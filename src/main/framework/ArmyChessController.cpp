#include "ArmyChessController.hpp"

ArmyChessController::ArmyChessController(){
    server.route("/", [&](){ return helloworld(); });
    server.route("/add/<arg>/<arg>", [&](int a, int b){ return addNumber(a, b); });

    auto port = server.listen(QHostAddress::Any, 8080);

    qDebug() << QString("http://127.0.0.1:%2/").arg(port);
}

auto ArmyChessController::helloworld() -> QString {
    return "hello world! army chess!";
}

auto ArmyChessController::addNumber(int a, int b) -> QString{
    return QString("add : %1 + %2 = %3").arg(a).arg(b).arg(a+b);
}
