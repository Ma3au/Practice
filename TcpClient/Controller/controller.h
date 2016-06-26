#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "client.h"
#include "nmea.h"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();

    Client *client;
    Nmea *nmea;
};

#endif // CONTROLLER_H
