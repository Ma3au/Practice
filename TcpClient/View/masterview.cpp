#include "masterview.h"

MasterView::MasterView(Controller *controller, QObject *parent) : QObject(parent)
{   
    m_controller = controller;
    m_mrkGUI = new MrkGUI(controller->mrk);
    m_clientGUI = new ClientGUI(controller->client, m_mrkGUI);

    connect(controller->client, SIGNAL(statusSignal(QString)), m_clientGUI, SLOT(statusSlot(QString)));
    connect(m_mrkGUI, SIGNAL(clickSetingButtonSignal()), SLOT(clickSetingMrkSlot()));

    m_mrkGUI->show();
}

MasterView::~MasterView()
{
    delete m_clientGUI;
}

void MasterView::clickSetingMrkSlot()
{
    m_clientGUI->show();
}
