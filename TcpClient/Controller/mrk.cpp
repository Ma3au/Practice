#include "mrk.h"

Mrk::Mrk(QObject *parent) : QObject(parent)
{
    m_rawDataGGA = new QByteArray();
    m_rawDataRMC = new QByteArray();

    m_windowShown = false;

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), SLOT(parseSlot()));
    timer->start(5000);
}

//Получение строки от NMEA
void Mrk::receiveSlot(const QByteArray &msg)
{
    QByteArray type;
    type = msg.mid(3, 3);

    if(type == "GGA")
    {
        delete m_rawDataGGA;
        m_rawDataGGA = new QByteArray(msg);
        return;
    }

    if(type == "RMC")
    {
        delete m_rawDataRMC;
        m_rawDataRMC = new QByteArray(msg);
        return;
    }
}

//Парсинг (GGA)
void Mrk::parseSlot()
{
    if(!m_windowShown){
        return;
    }
    qDebug() << "Парсинг идёт";

    m_time = new QTime();
    m_date = new QDate();
    m_latitude = new Coordinate();
    m_longitude = new Coordinate();

    *m_date = m_date->currentDate();
    m_time->setHMS(m_rawDataGGA->mid(7, 2).toInt(),
                   m_rawDataGGA->mid(9, 2).toInt(),
                   m_rawDataGGA->mid(11, 2).toInt(),
                   m_rawDataGGA->mid(14, 2).toInt());

    m_latitude->setDeg(m_rawDataGGA->mid(17, 2).toInt());
    m_latitude->setMin(m_rawDataGGA->mid(19, 7).toFloat());
    m_latitude->setDirection(QString(m_rawDataGGA->mid(27, 1)));

    m_longitude->setDeg(m_rawDataGGA->mid(29, 3).toInt());
    m_longitude->setMin(m_rawDataGGA->mid(32, 7).toFloat());
    m_longitude->setDirection(QString(m_rawDataGGA->mid(40, 1)));

    emit mrkDataSignal(*m_time, *m_date, *m_longitude, *m_latitude);
}

void Mrk::windowShownSlot()
{
    m_windowShown = true;
}

void Mrk::windowClosedSlot()
{
    m_windowShown = false;
}


Mrk::~Mrk()
{
    delete m_time;
    delete m_date;
    delete m_latitude;
    delete m_longitude;
}
