#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork>

class Server: public QWidget
{
    Q_OBJECT
public:
    Server(QWidget* parent = 0);
    ~Server();
    bool startServer(int nPort);
    bool stopServer();

private slots:
    void newConnectionSlot();
    void readClientSlot();
    void disconnectedSlot();

    void workSlot();

private:
    QTcpServer* m_pTcpServer;
    QMap<QTcpSocket*, int> m_connectTable;
    bool m_serverIsRunning;

    QTimer* m_timer;

    void sendToClient(QTcpSocket* pSocket, const QByteArray &arr);
    void sendToAllClient(const QByteArray &arr);
    void closeAllConnections();

    //for emulation
    QFile* m_dataFile;

    QByteArray generationMsg();

};

#endif // SERVER_H
