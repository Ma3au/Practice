#include "View/server_gui.h"
#include "ui_server_gui.h"

ServerGUI::ServerGUI(Server* server, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServerGUI)
{
    ui->setupUi(this);

    m_server = server;

    connect(ui->buttonStart, SIGNAL(clicked(bool)), SLOT(slotStartButton()));
    connect(ui->buttonStop, SIGNAL(clicked(bool)), SLOT(slotStopButton()));
}

void ServerGUI::slotStartButton()
{
    int port = ui->editPort->toPlainText().toInt();
    if(m_server->startServer(port))
        ui->lblServerStatus->setText(QString("Server is running"));
}

void ServerGUI::slotStopButton()
{
    if(m_server->stopServer())
        ui->lblServerStatus->setText(QString("Server is stopped"));
}


ServerGUI::~ServerGUI()
{
    delete ui;
}
