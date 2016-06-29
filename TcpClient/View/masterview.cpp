#include "masterview.h"
#include "ui_masterview.h"

MasterView::MasterView(Controller *controller, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MasterView)
{   
    ui->setupUi(this);

    m_controller = controller;
    m_clientGUI = new ClientGUI(controller->client, this);
    m_mrkGUI = new MrkGUI(controller->mrk);

    connect(m_controller->client, SIGNAL(statusSignal(QString)), m_clientGUI, SLOT(statusSlot(QString)));
    connect(m_controller->mrk, SIGNAL(mrkDataSignal(QTime,QDate,Coordinate,Coordinate)),
            m_mrkGUI, SLOT(mrkDataSlot(QTime,QDate,Coordinate,Coordinate)));

    connect(m_mrkGUI, SIGNAL(windowShownSignal()),m_controller->mrk, SLOT(windowShownSlot()));
    connect(m_mrkGUI, SIGNAL(windowClosedSignal()),m_controller->mrk, SLOT(windowClosedSlot()));
}

//По нажатию кнопки "Настройка"
void MasterView::on_clientButton_clicked()
{
    m_clientGUI->show();
}

//По нажатию кнопки "МРК"
void MasterView::on_mrkButton_clicked()
{
    m_mrkGUI->show();
}

//По нажатию кнопки "Выход"
void MasterView::on_exitButton_clicked()
{
    m_mrkGUI->close();
    m_clientGUI->close();
    this->close();
}

MasterView::~MasterView()
{
    delete m_clientGUI;
    delete m_mrkGUI;
    delete ui;
}
