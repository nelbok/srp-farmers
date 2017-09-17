#include "fieldcontroller.h"

#include "data/data.h"

FieldController::FieldController(QObject *parent)
    : IBuildingController(parent)
{
}

void FieldController::build()
{
    if (!canBuild())
        return;

    _data->setFields(_data->fields() + 1);
}

void FieldController::updateCanBuild()
{
    bool canBuild = false;
    QString errorString = "";

    if (_data->farmers() == 1 && _data->fields() == 0)
    {
        canBuild = true;
    }
    else
    {
        canBuild = _data->farmers() >= (_data->fields() + 1) * 3;
        if (!canBuild)
        {
            errorString = QObject::tr("Fields: Not enough farmers");
        }
    }

    manageCanBuild(canBuild, errorString);
}

void FieldController::connectData()
{
    connect(_data, SIGNAL(farmersChanged()), SLOT(updateCanBuild()));
    connect(_data, SIGNAL(fieldsChanged()), SLOT(updateCanBuild()));
}
