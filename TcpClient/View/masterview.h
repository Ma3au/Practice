#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include "Controller/controller.h"
#include "clientgui.h"
#include "mrkgui.h"
#include <QWidget>

namespace Ui {
class MasterView;
}

class MasterView : public QWidget
{
    Q_OBJECT
public:
    explicit MasterView(Controller *controller, QWidget *parent = 0);
    ~MasterView();

private slots:
    void on_clientButton_clicked();

    void on_mrkButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MasterView *ui;
    Controller *m_controller;
    ClientGUI *m_clientGUI;
    MrkGUI *m_mrkGUI;
};

#endif // MASTERVIEW_H
