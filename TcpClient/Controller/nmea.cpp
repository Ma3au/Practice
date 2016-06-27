#include "nmea.h"
#include <QDataStream>
#include <QtNetwork>

Nmea::Nmea(QObject *parent) : QObject(parent)
{

}

void Nmea::messageSlot(const QByteArray &msg)
{
    qDebug() << "Данные от сервера были приняты";
    QByteArrayList listMsg;
    listMsg = msg.split('\n');

    foreach (QByteArray for_msg, listMsg)
    {
        if(checkMsg(for_msg))
            processMessage(for_msg);
        else
            qDebug() << "FAIL";
    }
}

bool Nmea::checkMsg(const QByteArray &msg)
{
    int length = msg.length();
    if (length < 2)
        return false;

    if(msg[0] != '$' || msg[length - 1] != '\r')
        return false;

    if(!checksum(msg))
        return false;

    return true;
}

//Вычисление контрольной суммы
bool Nmea::checksum(const QByteArray &msg)
{
    int indexAsterisk = msg.indexOf('*');
    if(indexAsterisk == -1)
        return false;

    int check = 0;
    for(int i = 1; i < indexAsterisk; i++)
        check ^= msg[i];

    QByteArray checksumMsg = msg;
    checksumMsg.remove(0, indexAsterisk + 1);
    checksumMsg.truncate(checksumMsg.indexOf('\r'));

    if(check != checksumMsg.toInt(NULL, 16))
        return false;

    return true;
}

void Nmea::processMessage(const QByteArray &msg)
{
    qDebug() << "OK";
}

Nmea::~Nmea()
{

}
