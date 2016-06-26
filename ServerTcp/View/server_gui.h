#ifndef SERVERGUI_H
#define SERVERGUI_H

#include "Controller/server.h"

#include <QMainWindow>

namespace Ui {
    class ServerGUI;
}

class ServerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ServerGUI(Server* m_server, QWidget *parent = 0);
    ~ServerGUI();

private slots:
    void slotStartButton();
    void slotStopButton();

private:
    Ui::ServerGUI *ui;
    Server* m_server;
};

#endif // SERVERGUI_H
