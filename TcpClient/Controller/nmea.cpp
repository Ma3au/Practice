#include "nmea.h"
#include <QDataStream>
#include <QtNetwork>

Nmea::Nmea(QObject *parent) : QObject(parent)
{
    m_dataFile = new QFile("response.txt");
    m_dataFile->open(QIODevice::WriteOnly);
}

//Вычисление контрольной суммы
bool Nmea::checksum()
{
    foreach (QByteArray arr, list)
    {
        if(arr[0] != '$' || arr[arr.length() - 1] != '\r')
            return false;

        QByteArray part = arr;
        part.truncate(part.indexOf('*'));
        //part.remove(0, 1);

        int check = 0;
        for(int i = 1; i < part.length(); i++)
            check ^= part[i];

        part = arr;
        part.remove(0, part.indexOf('*') + 1);
        part.truncate(part.indexOf('\r'));

        if(QString::number(check, 16).toUpper() != part)
            return false;
    }
    return true;
}

//Слот на сигнал от Client TODO: запись в файл
void Nmea::slotMessage(const QByteArray &str)
{
    list = str.split('\n');
    qDebug() << "Данные от сервера были приняты";
//    for(int i = 5; i < list.length(); i += 5)
//        list.removeAt(i);

    if(checksum())
        processMessage();
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
