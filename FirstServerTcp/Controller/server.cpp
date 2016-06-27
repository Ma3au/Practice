#include "Controller/server.h"

#include <QDebug>

Server::Server(QWidget* parent):
    QWidget(parent)
{
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()),SLOT(workSlot()));

    m_serverIsRunning = false;

    m_dataFile = new QFile(":/data.txt");
    if(!m_dataFile->open(QIODevice::ReadOnly))
        qDebug() << "Error opening data file: " << m_dataFile->errorString();

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

    connect(m_pTcpServer, SIGNAL(newConnection()), SLOT(newConnectionSlot()));

    m_timer->start(1000);
    m_serverIsRunning = true;
    qDebug() << "The server is running!";
    return true;
}

void Server::sendToClient(QTcpSocket* pSocket, const QByteArray& arr)
{
    qDebug() << "Send msg to " << pSocket->socketDescriptor();
    pSocket->write(arr);
}

void Server::sendToAllClient(const QByteArray &arr)
{
    qDebug() << "Send msg to all client";
    foreach (QTcpSocket* socketClient, m_connectTable.keys()) {
        qDebug() << "Send msg to id:" << m_connectTable[socketClient] << " client";
        socketClient->write(arr);

    }
}

void Server::newConnectionSlot()
{
    qDebug() << "New connection";
    QTcpSocket* pClientSocket = m_pTcpServer->nextPendingConnection();

    int idNewUser = pClientSocket->socketDescriptor();
    qDebug() << "ID new user " << idNewUser;
    m_connectTable[pClientSocket] = idNewUser;

    connect(pClientSocket, SIGNAL(readyRead()), SLOT(readClientSlot()));
    connect(pClientSocket, SIGNAL(disconnected()), SLOT(disconnectedSlot()));

}

void Server::readClientSlot()
{
    /* Обработка входящих сообщений от клиента */
}

void Server::disconnectedSlot()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    qDebug() << "Client id:" << m_connectTable[clientSocket] << " disconnected";
    m_connectTable.remove(clientSocket);
}

void Server::closeAllConnections()
{
    foreach (QTcpSocket* socketClient, m_connectTable.keys()){
        /* Отчёт о том что сервер выключился, пока не нужен
        QByteArray msg;
        QDataStream out(&msg, QIODevice::WriteOnly);

        socketClient->write(msg);
        */
        socketClient->close();
        m_connectTable.remove(socketClient);
    }
    qDebug() << "All connections closed";
}

QByteArray Server::generationMsg()
{
    qDebug() << "Generation msg..";

    if(m_dataFile->atEnd()){
        m_dataFile->seek(0);
    }
    QString strMsg("");
    for(int i = 0; i < 5; i++){
        strMsg.append(QString(m_dataFile->readLine()));
    }
    m_dataFile->readLine(); // 6-ая пустая строка


    QByteArray msg;
    QDataStream out(&msg, QIODevice::WriteOnly);
    out << strMsg;

    qDebug() << "Done";

    msg = m_dataFile->readAll();
    return msg;
}

void Server::workSlot()
{
    qDebug() << "The server attempts to send data...";

    QByteArray msg = generationMsg();
    sendToAllClient(msg);
    qDebug() << "Done\n";

}


bool Server::stopServer()
{
    qDebug() << "Trying to stop the server...";
    if(!m_serverIsRunning)
    {
        qDebug() << "The server is already stopped";
        return false;
    }

    m_timer->stop();

    closeAllConnections();
    m_pTcpServer->close();
    delete m_pTcpServer;

    m_serverIsRunning = false;
    qDebug() << "Server is down";
    return true;
}

Server::~Server()
{
    stopServer();
}
