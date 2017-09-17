#include "housecontroller.h"

#include "data/data.h"

HouseController::HouseController(QObject *parent)
    : IBuildingController(parent)
{
}

void HouseController::build()
{
    if (!canBuild())
        return;

    _data->setHouses(_data->houses() + 1);
}

void HouseController::updateCanBuild()
{
    bool canBuild = false;
    QString errorString = "";

    if (_data->houses() >= _data->fields() * 4)
    {
        canBuild = false;
        errorString = QObject::tr("Houses: Not enough fields");
    }
    else if (_data->townhall())
    {
        canBuild = _data->houses() < 10;
        if (!canBuild)
        {
            errorString = QObject::tr("Houses: Need game update");
        }
    }
    else
    {
        canBuild = _data->houses() < 5;
        if (!canBuild)
        {
            errorString = QObject::tr("Houses: Need a townhall");
        }
    }

    manageCanBuild(canBuild, errorString);
}

void HouseController::connectData()
{
    connect(_data, SIGNAL(housesChanged()), SLOT(updateCanBuild()));
    connect(_data, SIGNAL(fieldsChanged()), SLOT(updateCanBuild()));
    connect(_data, SIGNAL(townhallChanged()), SLOT(updateCanBuild()));
}
