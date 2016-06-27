#ifndef MRKGUI_H
#define MRKGUI_H

#include "Controller/mrk.h"

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

signals:
    void clickSetingButtonSignal();

private slots:
    void clickSetingButtonSlot();

private:
    Ui::MrkGUI *ui;
    Mrk *m_mrk;
};

#endif // MRKGUI_H
