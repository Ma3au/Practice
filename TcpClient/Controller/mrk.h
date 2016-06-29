#ifndef MRK_H
#define MRK_H

#include "coordinate.h"
#include <QObject>
#include <QTime>
#include <QDate>
#include <QtNetwork>

class Mrk : public QObject
{
    Q_OBJECT
public:
    explicit Mrk(QObject *parent = 0);
    ~Mrk();

public slots:
    void receiveSlot(const QByteArray &msg);
    void parseSlot();

    void windowShownSlot();
    void windowClosedSlot();
private:
    QByteArray *m_rawDataGGA;
    QByteArray *m_rawDataRMC;

    QTime *m_time;
    QDate *m_date;
    Coordinate *m_longitude;
    Coordinate *m_latitude;

    bool m_windowShown;

signals:
    void mrkDataSignal(QTime time, QDate date, Coordinate lon, Coordinate lat);
};

#endif // MRK_H
