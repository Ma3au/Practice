#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork>

class Server: public QWidget
{
    Q_OBJECT
public:
    Server(QWidget* parent = 0);
    bool startServer(int nPort);
    bool stopServer();
    bool isRunning();

private slots:
    void slotNewConnection();
    void slotReadClient();
    void slotDisconnected();

private:
    QTcpServer* m_pTcpServer;
    QMap<int, QTcpSocket*> m_connectTable;
    bool m_serverIsRunning;

    void sendToClient(QTcpSocket* pSocket, const QString& str);
    void closeAllConnections();
};

#endif // SERVER_H
