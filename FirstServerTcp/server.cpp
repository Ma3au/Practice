#include "server.h"

#include <QDebug>

Server::Server(QWidget* parent):
    QWidget(parent)
{
    m_serverIsRunning = false;
}

bool Server::startServer(int nPort)
{
    qDebug() << "Trying to start the server...";
    if(m_serverIsRunning)
    {
       qDebug() << "Error: Server is already running";
       return false;
    }
    m_pTcpServer = new QTcpServer(this);
    if(!m_pTcpServer->listen(QHostAddress::Any, nPort))
    {
        qDebug() << "Error: Unable to start the server";
        qDebug() << m_pTcpServer->errorString();
        m_pTcpServer->close();
        return false;
    }

    connect(m_pTcpServer, SIGNAL(newConnection()), SLOT(slotNewConnection()));

    m_serverIsRunning = true;
    qDebug() << "The server is running!";
    return true;
}

void Server::slotNewConnection()
{
    qDebug() << "New connection";
    QTcpSocket* pClientSocket = m_pTcpServer->nextPendingConnection();

    int idNewUser = pClientSocket->socketDescriptor();
    m_connectTable[idNewUser] = pClientSocket;

    connect(pClientSocket, SIGNAL(readyRead()), SLOT(slotReadClient()));
    connect(pClientSocket, SIGNAL(disconnected()), SLOT(slotDisconnected()));
}

void Server::slotReadClient()
{
    /* Обработка входящих сообщений от клиента */
}

void Server::slotDisconnected()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    int idUser = clientSocket->socketDescriptor();
    m_connectTable.remove(idUser);
    qDebug() << idUser << " disconnected";
}

void Server::closeAllConnections()
{
    foreach (int i, m_connectTable.keys())
    {
        QByteArray msg;
        QDataStream out(msg);
        out << int(0) << "The server shuts down";

        m_connectTable[i]->write(msg);
        m_connectTable[i]->close();
        m_connectTable.remove(i);
    }
    qDebug() << "All connections closed";
}

bool Server::isRunning()
{
    return m_serverIsRunning;
}

bool Server::stopServer()
{
    qDebug() << "Trying to stop the server...";
    if(!m_serverIsRunning)
    {
        qDebug() << "The server is already stopped";
        return false;
    }

    closeAllConnections();
    m_pTcpServer->close();
    delete m_pTcpServer;

    m_serverIsRunning = false;
    qDebug() << "Server is down";
    return true;
}
