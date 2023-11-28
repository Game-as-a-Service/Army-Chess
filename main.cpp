// #define ARMYCHESSTEST
#ifndef ARMYCHESSTEST
#include <QCoreApplication>

#include <QLocale>
#include <QTranslator>
#include "src/main/framework/ArmyChessController.hpp"


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ArmyChess_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    ArmyChessController controller;

    return a.exec();
}
#else

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
