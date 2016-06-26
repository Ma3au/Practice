#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Controller/server.h"

#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();

    Server* server;
};

#endif // CONTROLLER_H
