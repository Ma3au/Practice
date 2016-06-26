#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    client = new Client();
    nmea = new Nmea();

    connect(client, SIGNAL(signalMessage(QByteArray)), nmea, SLOT(slotMessage(QByteArray)));
}

Controller::~Controller()
{
    delete client;
    delete nmea;
}
