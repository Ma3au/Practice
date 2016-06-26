#include "nmea.h"
#include <QDataStream>
#include <QtNetwork>

Nmea::Nmea(QObject *parent) : QObject(parent)
{
    m_dataFile = new QFile("response.txt");
    m_dataFile->open(QIODevice::WriteOnly);
}



//Слот на сигнал от Client TODO: запись в файл
void Nmea::messageSlot(const QByteArray &msg)
{
    QByteArrayList listMsg;
    listMsg = msg.split('\n');

    foreach (QByteArray msg, listMsg) {
        if(checkMsg(msg) != true){
            listMsg.removeOne(msg);
        }

    }

    qDebug() << "Данные от сервера были приняты";
    processMessage();
}

bool Nmea::checkMsg(const QByteArray msg)
{
    int length = msg.length();
    if (length < 2){
        return false;
    }
    if(msg[0] != '$' || msg[length - 1] != '\r'){
        return false;
    }

    if(!checksum(msg)){
        return false;
    }

    return true;
}

//Вычисление контрольной суммы
bool Nmea::checksum(const QByteArray msg)
{
    int indexAsterisk = msg.indexOf('*');
    if(indexAsterisk == -1){
        return false;
    }

    int check = 0;
    for(int i = 1; i < indexAsterisk; i++){
        check ^= msg[i];
    }

    QString checksumMsg = msg;
    checksumMsg.remove(0, checksumMsg.indexOf('*') + 1);
    checksumMsg.truncate(checksumMsg.indexOf('\r'));

    bool ok;
    if(check != checksumMsg.toInt(&ok, 16))
        return false;

    return true;
}

void Nmea::processMessage()
{
    //qDebug() << "OK";
}

Nmea::~Nmea()
{
    m_dataFile->close();
    delete m_dataFile;
}
