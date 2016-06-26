#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    server = new Server();

    connect(ui->buttonStart, SIGNAL(clicked(bool)), SLOT(slotStartButton()));
    connect(ui->buttonStop, SIGNAL(clicked(bool)), SLOT(slotStopButton()));
}

void MainWindow::slotStartButton()
{
    int port = ui->editPort->toPlainText().toInt();
    server->startServer(port);

    ui->lblServerStatus->setText(QString("Server is running"));
}

void MainWindow::slotStopButton()
{
    server->stopServer();

    ui->lblServerStatus->setText(QString("Server is stopped"));
}


MainWindow::~MainWindow()
{
    if(server->isRunning())
        server->stopServer();
    delete server;
    delete ui;
}
