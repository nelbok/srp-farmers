#include "townhallcontroller.h"

#include "data/data.h"

TownhallController::TownhallController(QObject *parent)
    : IBuildingController(parent)
{
}

void TownhallController::build()
{
    if (!canBuild())
        return;

    _data->setTownhall(true);
}

void TownhallController::updateCanBuild()
{
    bool canBuild = false;
    QString errorString = "";

    if (_data->townhall())
    {
        canBuild = false;
        errorString = QObject::tr("Townhall: Already built");
    }
    else
    {
        canBuild = _data->houses() >=5;
        if (!canBuild)
        {
            errorString = QObject::tr("Townhall: Not enough houses");
        }
    }

    manageCanBuild(canBuild, errorString);
}

void TownhallController::connectData()
{
    connect(_data, SIGNAL(housesChanged()), SLOT(updateCanBuild()));
    connect(_data, SIGNAL(townhallChanged()), SLOT(updateCanBuild()));
}
