#include "Controller/controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    server = new Server();
}


Controller::~Controller()
{
    delete server;
}
