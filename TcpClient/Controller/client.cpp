#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    connection = false;

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(connectedSlot()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(errorSlot()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), SLOT(disconnectedSlot()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(readyReadSlot()));
}

bool Client::connectToServer(QString ip, int port)
{
    if(connection)
    {
        emit statusSignal("Вы подключены к серверу:\n" + m_ip + ":" + QString::number(m_port));
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
        emit statusSignal("Вы не подключены к серверу");
        return true;
    }

    emit statusSignal("Вы не подключены к серверу");
    return false;
}

void Client::connectedSlot()
{
    connection = true;
    emit statusSignal("Вы подключены к серверу:\n" + m_ip + ":" + QString::number(m_port));
}

void Client::errorSlot()
{
    emit statusSignal("Вы не подключены к серверу");
}

void Client::disconnectedSlot()
{
    connection = false;
    emit statusSignal("Вы не подключены к серверу");
}

void Client::readyReadSlot()
{
    if(m_pTcpSocket->bytesAvailable())
        m_msg = m_pTcpSocket->readAll();

    emit messageSignal(m_msg);
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
