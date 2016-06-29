#include "coordinate.h"

Coordinate::Coordinate()
{

}

int Coordinate::deg() const
{
    return m_deg;
}

void Coordinate::setDeg(int deg)
{
    m_deg = deg;
}

float Coordinate::min() const
{
    return m_min;
}

void Coordinate::setMin(float min)
{
    m_min = min;
}

QString Coordinate::direction() const
{
    return m_direction;
}

void Coordinate::setDirection(const QString &direction)
{
    m_direction = direction;
}
