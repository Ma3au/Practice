#include "masterview.h"

MasterView::MasterView(Controller *controller, QObject *parent) : QObject(parent)
{
    m_controller = controller;
    m_clientGUI = new ClientGUI(controller->client);

    connect(controller->client, SIGNAL(signalStatus(QString)), m_clientGUI, SLOT(slotStatus(QString)));

    m_clientGUI->show();
}

MasterView::~MasterView()
{
    delete m_clientGUI;
}
