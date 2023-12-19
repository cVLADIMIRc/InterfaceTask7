// levelsfacade.cpp
#include "levelsfacade.h"

LevelsFacade::LevelsFacade() {}

QStringList LevelsFacade::getLevelList(const QString& directoryPath) {
    QDir directory(directoryPath);
    QStringList filters;
    filters << "*.txt";
    directory.setNameFilters(filters);
    return directory.entryList();
}

QStringList LevelsFacade::loadLevel(const QString& levelFileName) {
    QStringList bricksData;

    QFile levelFile(levelFileName);
    if (levelFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&levelFile);
        while (!in.atEnd()) {
            QString brickData = in.readLine();
            bricksData.append(brickData);
        }
        levelFile.close();
    }

    return bricksData;
}
