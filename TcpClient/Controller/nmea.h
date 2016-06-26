#ifndef NMEA_H
#define NMEA_H

#include <QString>
#include <QObject>
#include <QFile>

class Nmea : public QObject
{
    Q_OBJECT
public:
    Nmea(QObject *parent = 0);
    ~Nmea();

    bool checksum(const QByteArray str);
    void processMessage();

private slots:
    void messageSlot(const QByteArray &msg);

private:
    QFile *m_dataFile;

    bool checkMsg(const QByteArray msg);
};

#endif // NMEA_H
