#ifndef CONTROLLER_MANAGER_H
#define CONTROLLER_MANAGER_H

#include <QObject>

class Data;
class SettingsManager;
class FieldController;
class HouseController;
class TownhallController;

class ControllerManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QObject * field READ field NOTIFY fieldChanged)
    Q_PROPERTY(QObject * house READ house NOTIFY houseChanged)
    Q_PROPERTY(QObject * townhall READ townhall NOTIFY townhallChanged)

public:
    explicit ControllerManager(QObject *parent = nullptr);
    virtual ~ControllerManager();

    void setData(Data *data);

    QObject * field() const;
    QObject * house() const;
    QObject * townhall() const;

public slots:
    void reset();

private slots:
    void updateFarmers();
    void updateSettings();

private:
    Data *_data;
    SettingsManager *_settingsManager;

    FieldController * _field;
    HouseController * _house;
    TownhallController * _townhall;

signals:
    void fieldChanged();
    void houseChanged();
    void townhallChanged();

};

#endif // CONTROLLER_MANAGER_H
