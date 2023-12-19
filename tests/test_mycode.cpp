#include <QtTest/QtTest>
#include "../src/levelsfacade.h"

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testGetLevelList() {
        LevelsFacade levelsFacade;
        QString directoryPath = "C:/Users/ilya-/Desktop/UI/levels/";
        QStringList levelList = levelsFacade.getLevelList(directoryPath);

        QVERIFY(!levelList.isEmpty()); // Проверка, что список уровней не пустой
    }

    void testLoadLevel() {
        LevelsFacade levelsFacade;
        QString levelFileName = "C:/Users/ilya-/Desktop/UI/levels/leve1.txt";
        QStringList bricksData = levelsFacade.loadLevel(levelFileName);

        QVERIFY(!bricksData.isEmpty()); // Проверка, что данные уровня не пустые
    }
};

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
