#include "nmea.h"

Nmea::Nmea(QObject *parent) : QObject(parent)
{

}

//Приём от клиента сообщения
void Nmea::messageSlot(const QByteArray &msg)
{
    QByteArrayList listMsg;
    listMsg = msg.split('\n');

    foreach (QByteArray for_msg, listMsg)
    {
        if(checkMsg(for_msg))
            processMessage(for_msg);
    }
}

//Проверка строки
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

//Отправка строки МРК
void Nmea::processMessage(const QByteArray &msg)
{
    emit receiveSignal(msg);
}
