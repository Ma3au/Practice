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

    bool checksum();
    void processMessage();

private slots:
    void slotMessage(const QByteArray &str);

private:
    QFile *m_dataFile;
    QByteArrayList list;
};

#endif // NMEA_H
