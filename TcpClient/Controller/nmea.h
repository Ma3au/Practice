#ifndef NMEA_H
#define NMEA_H

#include <QString>
#include <QObject>
#include <QFile>
#include <QtNetwork>

class Nmea : public QObject
{
    Q_OBJECT
public:
    Nmea(QObject *parent = 0);

    bool checksum(const QByteArray &str);
    void processMessage(const QByteArray &msg);
    bool checkMsg(const QByteArray &msg);

public slots:
    void messageSlot(const QByteArray &msg);

signals:
    void receiveSignal(QByteArray msg);
};

#endif // NMEA_H
