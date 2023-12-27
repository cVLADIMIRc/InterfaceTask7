#include "form.h"
#include "boyer.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();
    int res;

    res = find(str, sub_str);

    // Поиск подстроки в строке
    // bool found = str.contains(sub_str, Qt::CaseInsensitive); // Игнорирование регистра при поиске

    bool found = (res != -1);
    // Вывод результата
    if (found) {
        ui->result->setText("yes");
    } else {
        ui->result->setText("no");
    }
}

QVector<int> Form::prefix_func(const QString &s) {
    QVector<int> p(s.length());

    int k = 0;
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        while (k > 0 && s[k] != s[i]) {
            k = p[k - 1];
        }
        if (s[k] == s[i]) {
            ++k;
        }
        p[i] = k;
    }
    return p;
}

int Form::find(const QString &s, const QString &t) {
    if (s.length() < t.length()) {
        return -1;
    }

    if (t.isEmpty()) {
        return s.length();
    }

    QMap<QChar, int> stop_table;
    QMap<int, int> suffics_table;

    for (int i = 0; i < t.length(); ++i) {
        stop_table[t[i]] = i;
    }

    QString rt(t);
    std::reverse(rt.begin(), rt.end());
    QVector<int> p = prefix_func(t), pr = prefix_func(rt);
    for (int i = 0; i < t.length() + 1; ++i) {
        suffics_table[i] = t.length() - p.back();
    }

    for (int i = 1; i < t.length(); ++i) {
        int j = pr[i];
        suffics_table[j] = std::min(suffics_table[j], i - pr[i] + 1);
    }

    for (int shift = 0; shift <= s.length() - t.length();) {
        int pos = t.length() - 1;

        while (t[pos] == s[pos + shift]) {
            if (pos == 0) return shift;
            --pos;
        }

        if (pos == t.length() - 1) {
            QMap<QChar, int>::const_iterator stop_symbol = stop_table.find(s[pos + shift]);
            int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol.value() : -1);
            shift += stop_symbol_additional;
        } else {
            shift += suffics_table[t.length() - pos - 1];
        }
    }

    return -1;
}
