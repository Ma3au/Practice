#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "Controller/controller.h"
#include "View/server_gui.h"

#include <QObject>

class MasterView : public QObject
{
    Q_OBJECT
public:
    explicit MasterView(Controller* controller, QObject *parent = 0);
    ~MasterView();
signals:

public slots:

private:
    Controller* m_controller;

    ServerGUI* m_serverGUI;
};

#endif // MASTERVIEW_H
