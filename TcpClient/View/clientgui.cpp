#include "clientgui.h"
#include "ui_clientgui.h"

ClientGUI::ClientGUI(Client *client, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientGUI)
{
    ui->setupUi(this);
    ui->statusLabel->setText("Вы не подключены к серверу");

    m_client = client;

    connect(ui->connectButton, SIGNAL(clicked(bool)), SLOT(connectedButtonSlot()));
    connect(ui->disconnectButton, SIGNAL(clicked(bool)), SLOT(disconnectButtonSlot()));
}

void ClientGUI::connectedButtonSlot()
{
    ui->statusLabel->setText("Ожидание подключения...");
    m_client->connectToServer(ui->ipEdit->text(), ui->portEdit->text().toInt());
    ui->ipEdit->clear();
    ui->portEdit->clear();
}

void ClientGUI::disconnectButtonSlot()
{
    ui->statusLabel->setText("Ожидание отключения...");
    m_client->disconnectFromServer();
}

void ClientGUI::statusSlot(QString str)
{
    ui->statusLabel->setText(str);
}

ClientGUI::~ClientGUI()
{
    delete ui;
}
