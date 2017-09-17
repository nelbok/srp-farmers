#ifndef DATA_H
#define DATA_H

#include <QObject>

class Data : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int farmers READ farmers WRITE setFarmers NOTIFY farmersChanged)
    Q_PROPERTY(int houses READ houses WRITE setHouses NOTIFY housesChanged)
    Q_PROPERTY(int fields READ fields WRITE setFields NOTIFY fieldsChanged)
    Q_PROPERTY(bool townhall READ townhall WRITE setTownhall NOTIFY townhallChanged)

public:
    explicit Data(QObject *parent = nullptr);

    int farmers() const;
    void setFarmers(int value);

    int houses() const;
    void setHouses(int value);

    int fields() const;
    void setFields(int value);

    bool townhall() const;
    void setTownhall(bool value);

private:
    int _farmers;
    int _houses;
    int _fields;
    bool _townhall;

signals:
    void farmersChanged();
    void housesChanged();
    void fieldsChanged();
    void townhallChanged();

};

#endif // DATA_H
