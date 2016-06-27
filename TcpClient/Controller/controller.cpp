#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    client = new Client();
    nmea = new Nmea();
    mrk = new Mrk();

    connect(client, SIGNAL(messageSignal(QByteArray)), nmea, SLOT(messageSlot(QByteArray)));
}

Controller::~Controller()
{
    delete mrk;
    delete client;
    delete nmea;
}
