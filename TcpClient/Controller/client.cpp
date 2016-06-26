#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    connection = false;

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(slotError()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), SLOT(slotDisconnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
}

bool Client::connectToServer(QString ip, int port)
{
    if(connection)
    {
        emit signalStatus("Вы подключены к серверу:\n" + m_ip + ":" + QString::number(m_port));
        return false;
    }

    setIp(ip);
    setPort(port);
    m_pTcpSocket->connectToHost(ip, port);

    return true;
}

bool Client::disconnectFromServer()
{
    if(connection)
    {
        m_pTcpSocket->disconnectFromHost();
        emit signalStatus("Вы не подключены к серверу");
        return true;
    }

    emit signalStatus("Вы не подключены к серверу");
    return false;
}

void Client::slotConnected()
{
    connection = true;
    emit signalStatus("Вы подключены к серверу:\n" + m_ip + ":" + QString::number(m_port));
}

void Client::slotError()
{
    emit signalStatus("Вы не подключены к серверу");
}

void Client::slotDisconnected()
{
    connection = false;
    emit signalStatus("Вы не подключены к серверу");
}

void Client::slotReadyRead()
{
    if(m_pTcpSocket->bytesAvailable())
        m_msg = m_pTcpSocket->readAll();

    emit signalMessage(m_msg);
}

QString Client::getIp() const
{
    return m_ip;
}

void Client::setIp(const QString &value)
{
    m_ip = value;
}

int Client::getPort() const
{
    return m_port;
}

void Client::setPort(int value)
{
    m_port = value;
}

Client::~Client()
{
    if(connection)
        m_pTcpSocket->disconnectFromHost();
    delete m_pTcpSocket;
}
