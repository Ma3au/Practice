#include "View/masterview.h"

MasterView::MasterView(Controller* controller, QObject *parent) : QObject(parent)
{
    m_controller = controller;

    m_serverGUI = new ServerGUI(controller->server);
    m_serverGUI->show();
}

MasterView::~MasterView()
{
    delete m_serverGUI;
}
