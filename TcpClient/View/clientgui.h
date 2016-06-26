#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include "Controller/client.h"
#include <QMainWindow>

namespace Ui {
class ClientGUI;
}

class ClientGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientGUI(Client* client, QWidget *parent = 0);
    ~ClientGUI();

private slots:
    void statusSlot(QString str);
    void connectedButtonSlot();
    void disconnectButtonSlot();

private:
    Ui::ClientGUI *ui;
    Client *m_client;

};

#endif // CLIENTGUI_H
