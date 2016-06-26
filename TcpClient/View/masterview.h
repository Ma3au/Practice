#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "Controller/controller.h"
#include "clientgui.h"
#include <QObject>

class MasterView : public QObject
{
    Q_OBJECT
public:
    explicit MasterView(Controller *controller, QObject *parent = 0);
    ~MasterView();

private:
    Controller *m_controller;
    ClientGUI *m_clientGUI;
};

#endif // MASTERVIEW_H
