#ifndef MRKGUI_H
#define MRKGUI_H

#include <Controller/mrk.h>
#include <QWidget>

namespace Ui {
class MrkGUI;
}

class MrkGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MrkGUI(Mrk *mrk, QWidget *parent = 0);
    ~MrkGUI();

public slots:
    void mrkDataSlot(QTime time, QDate date, Coordinate lon, Coordinate lat);

signals:
    void windowShownSignal();
    void windowClosedSignal();

protected:
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
private:
    Ui::MrkGUI *ui;
    Mrk *m_mrk;
};

#endif // MRKGUI_H
