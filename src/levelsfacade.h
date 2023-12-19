// levelsfacade.h
#ifndef LEVELSFACADE_H
#define LEVELSFACADE_H

#include <QString>
#include <QDir>
#include <QFile>
#include <QTextStream>

class LevelsFacade {
public:
    LevelsFacade();

    QStringList getLevelList(const QString& directoryPath);
    QStringList loadLevel(const QString& levelFileName);
};

#endif // LEVELSFACADE_H
