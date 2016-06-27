#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "Controller/controller.h"

#include "clientgui.h"
#include "mrkgui.h"

#include <QObject>

class MasterView : public QObject
{
    Q_OBJECT
public:
    explicit MasterView(Controller *controller, QObject *parent = 0);
    ~MasterView();

public slots:
    void clickSetingMrkSlot();

private:
    Controller *m_controller;

    ClientGUI *m_clientGUI;
    MrkGUI *m_mrkGUI;
};

#endif // MASTERVIEW_H
