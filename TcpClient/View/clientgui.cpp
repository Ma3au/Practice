#include "clientgui.h"
#include "ui_clientgui.h"

ClientGUI::ClientGUI(Client *client, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientGUI)
{
    ui->setupUi(this);

    m_client = client;
    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(false);

    connect(ui->connectButton, SIGNAL(clicked(bool)), SLOT(connectedButtonSlot()));
    connect(ui->disconnectButton, SIGNAL(clicked(bool)), SLOT(disconnectButtonSlot()));
}

//По нажатию кнопки "Старт"
void ClientGUI::connectedButtonSlot()
{
    ui->statusLabel->setText("Ожидание подключения...");
    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(false);
    m_client->connectToServer(ui->ipEdit->text(), ui->portEdit->text().toInt());
}

//По нажатию кнопки "Стоп"
void ClientGUI::disconnectButtonSlot()
{
    ui->statusLabel->setText("Ожидание отключения...");
    ui->connectButton->setEnabled(false);
    ui->disconnectButton->setEnabled(false);
    m_client->disconnectFromServer();
}

//Изменение статуса подключения
void ClientGUI::statusSlot(QString str)
{
    ui->statusLabel->setText(str);
    ui->connectButton->setEnabled(true);
    ui->disconnectButton->setEnabled(true);
}

ClientGUI::~ClientGUI()
{
    delete ui;
}
