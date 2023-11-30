#ifndef ARMYCHESSCONTROLLER_HPP
#define ARMYCHESSCONTROLLER_HPP

#include <QHttpServer>

class ArmyChessController{
public:
    ArmyChessController();

    auto helloworld() -> QString;
    auto addNumber(int a, int b) -> QString;


private:
    QHttpServer server;
};

#endif
