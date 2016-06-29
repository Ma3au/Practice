#ifndef CLIENT_H
#define CLIENT_H

#include <QtNetwork>
#include <QString>
#include <QObject>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();

    bool connectToServer(QString ip, int port);
    bool disconnectFromServer();

    void setIp(const QString &value);
    void setPort(int value);

private:
    QTcpSocket *m_pTcpSocket;
    bool connection;
    QString m_ip;
    int m_port;
    QByteArray m_msg;

private slots:
    void connectedSlot();
    void errorSlot();
    void disconnectedSlot();
    void readyReadSlot();

signals:
    void statusSignal(const QString &str);
    void messageSignal(const QByteArray &msg);
};

#endif // CLIENT_H
