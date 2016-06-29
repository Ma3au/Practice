#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    client = new Client();
    nmea = new Nmea();
    mrk = new Mrk();

    connect(client, SIGNAL(messageSignal(QByteArray)), nmea, SLOT(messageSlot(QByteArray)));
    connect(nmea, SIGNAL(receiveSignal(QByteArray)), mrk, SLOT(receiveSlot(QByteArray)));
}

Controller::~Controller()
{
    delete mrk;
    delete client;
    delete nmea;
}
