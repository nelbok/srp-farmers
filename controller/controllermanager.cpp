#include "controllermanager.h"

#include "data/data.h"
#include "controller/fieldcontroller.h"
#include "controller/housecontroller.h"
#include "controller/settingsmanager.h"
#include "controller/townhallcontroller.h"

ControllerManager::ControllerManager(QObject *parent)
    : QObject(parent)
    , _settingsManager(nullptr)
    , _field(nullptr)
    , _house(nullptr)
    , _townhall(nullptr)
{

}

ControllerManager::~ControllerManager()
{
    delete _settingsManager;
}

void ControllerManager::setData(Data *data)
{
    _data = data;

    if (_settingsManager)
        delete _settingsManager;
    if (_field)
        _field->deleteLater();
    if (_house)
        _house->deleteLater();
    if (_townhall)
        _townhall->deleteLater();

    _settingsManager = new SettingsManager(_data);

    _field = new FieldController(this);
    _field->setData(_data);
    _house = new HouseController(this);
    _house->setData(_data);
    _townhall = new TownhallController(this);
    _townhall->setData(_data);

    // Save
    connect(_data, SIGNAL(farmersChanged()), SLOT(updateSettings()));
    connect(_data, SIGNAL(fieldsChanged()), SLOT(updateSettings()));
    connect(_data, SIGNAL(housesChanged()), SLOT(updateSettings()));
    connect(_data, SIGNAL(townhallChanged()), SLOT(updateSettings()));

    // updateFarmers
    connect(_data, SIGNAL(housesChanged()), SLOT(updateFarmers()));
    updateFarmers();
}

QObject * ControllerManager::field() const
{
    return _field;
}

QObject * ControllerManager::house() const
{
    return _house;
}

QObject * ControllerManager::townhall() const
{
    return _townhall;
}

void ControllerManager::reset()
{
    _data->setFarmers(1);
    _data->setFields(0);
    _data->setHouses(0);
    _data->setTownhall(false);
}

void ControllerManager::updateFarmers()
{
    int farmers = 1;
    int houses = _data->houses();

    farmers += houses * 5;

    _data->setFarmers(farmers);
}

void ControllerManager::updateSettings()
{
    _settingsManager->save();
}
