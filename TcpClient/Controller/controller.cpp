#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    client = new Client();
    nmea = new Nmea();

    connect(client, SIGNAL(messageSignal(QByteArray)), nmea, SLOT(messageSlot(QByteArray)));
}

Controller::~Controller()
{
    delete client;
    delete nmea;
}
