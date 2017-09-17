#include "ibuildingcontroller.h"

IBuildingController::IBuildingController(QObject *parent)
    : QObject(parent)
{

}

void IBuildingController::setData(Data *data)
{
    _data = data;
    connectData();
    updateCanBuild();
    emit canBuildChanged();
}

void IBuildingController::manageCanBuild(bool canBuild, const QString & errorString)
{
   if (_errorString != errorString)
   {
       _errorString = errorString;
       emit errorStringChanged();
   }
   if (_canBuild != canBuild)
   {
       _canBuild = canBuild;
       emit canBuildChanged();
   }
}
