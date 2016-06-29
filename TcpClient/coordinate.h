#ifndef COORDINATE_H
#define COORDINATE_H

#include <QString>

class Coordinate
{
public:
    Coordinate();

    int deg() const;
    void setDeg(int deg);

    float min() const;
    void setMin(float min);

    QString direction() const;
    void setDirection(const QString &direction);

private:
    int m_deg;
    float m_min;
    QString m_direction;
};

#endif // COORDINATE_H
