#include "mrkgui.h"
#include "ui_mrkgui.h"

MrkGUI::MrkGUI(Mrk *mrk, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MrkGUI)
{
    ui->setupUi(this);
    m_mrk = mrk;

    ui->textEdit->setReadOnly(true);

}

void MrkGUI::mrkDataSlot(QTime time, QDate date, Coordinate lon, Coordinate lat)
{
    ui->textEdit->clear();
    ui->textEdit->append(time.toString());
    ui->textEdit->append(date.toString());
    ui->textEdit->append("Градусов долготы: " + QString::number(lon.deg()));
    ui->textEdit->append("Градусов широты: " + QString::number(lat.deg()));
}

void MrkGUI::showEvent(QShowEvent *ev)
{
    QWidget::showEvent(ev);

    emit windowShownSignal();
}

void MrkGUI::closeEvent(QCloseEvent *ev)
{
    QWidget::closeEvent(ev);

    emit windowClosedSignal();
}

MrkGUI::~MrkGUI()
{
    delete ui;
}
