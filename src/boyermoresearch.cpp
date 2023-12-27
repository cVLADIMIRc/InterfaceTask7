#include "boyermoresearch.h"
#include <QDebug>

QVector<int> search(const QString &text, const QString &pattern)
{
    QVector<int> badChar(256, -1);

    QVector<int> indices;
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n) {
        return indices;
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < m; ++i) {
        badChar[pattern[i].toLatin1()] = i;
    }

    int s = 0;
    while (s <= n - m) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            --j;
        }

        if (j < 0) {
            indices.append(s);
            s += m;
        } else {
            s += std::max(1, j - badChar[text[s + j].toLatin1()]);
        }
    }


    return indices;
}
