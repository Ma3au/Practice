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

    QString getIp() const;
    void setIp(const QString &value);

    int getPort() const;
    void setPort(int value);

private:
    QTcpSocket *m_pTcpSocket;
    bool connection;
    QString m_ip;
    int m_port;
    QByteArray m_msg;

private slots:
    void slotConnected();
    void slotError();
    void slotDisconnected();
    void slotReadyRead();

signals:
    void signalStatus(QString str);
    void signalMessage(const QByteArray &msg);
};

#endif // CLIENT_H
