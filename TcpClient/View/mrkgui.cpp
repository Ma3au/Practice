#include "mrkgui.h"
#include "ui_mrkgui.h"

MrkGUI::MrkGUI(Mrk *mrk, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MrkGUI)
{
    ui->setupUi(this);
    m_mrk = mrk;

    connect(ui->setingButton, SIGNAL(clicked()),SLOT(clickSetingButtonSlot()));
}

MrkGUI::~MrkGUI()
{
    delete ui;
}

void MrkGUI::clickSetingButtonSlot()
{
    emit clickSetingButtonSignal();
}
