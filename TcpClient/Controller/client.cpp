#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    m_pTcpSocket = new QTcpSocket();
    connection = false;

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(connectedSlot()));
    connect(m_pTcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), SLOT(errorSlot()));
    connect(m_pTcpSocket, SIGNAL(disconnected()), SLOT(disconnectedSlot()));
    connect(m_pTcpSocket, SIGNAL(readyRead()), SLOT(readyReadSlot()));

    connectToServer("localhost", 2323);
}

//Подключение к серверу
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

//Отключение от сервера
bool Client::disconnectFromServer()
{
    if(connection)
    {
        m_pTcpSocket->disconnectFromHost();
        return true;
    }

    emit statusSignal("Вы не подключены к серверу");
    return false;
}

//В случае подключения
void Client::connectedSlot()
{
    connection = true;
    emit statusSignal("Вы подключены к серверу:\n" + m_ip + ":" + QString::number(m_port));
}

//В случае ошибки
void Client::errorSlot()
{
    connection = false;
    emit statusSignal("Вы не подключены к серверу");
}

//В случае отсоединения
void Client::disconnectedSlot()
{
    connection = false;
    emit statusSignal("Вы не подключены к серверу");
}

//Чтение сервера и отправка NMEA
void Client::readyReadSlot()
{
    if(m_pTcpSocket->bytesAvailable())
        m_msg = m_pTcpSocket->readAll();

    emit messageSignal(m_msg);
}

void Client::setIp(const QString &value)
{
    m_ip = value;
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
