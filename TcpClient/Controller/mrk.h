#ifndef MRK_H
#define MRK_H

#include <QObject>

class Mrk : public QObject
{
    Q_OBJECT
public:
    explicit Mrk(QObject *parent = 0);
    ~Mrk();
signals:

public slots:
};

#endif // MRK_H
