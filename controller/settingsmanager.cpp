#include "settingsmanager.h"

#include <QSettings>
#include <QtConcurrent/QtConcurrentRun>

#include "data/data.h"

SettingsManager::SettingsManager(Data *data)
    : _data(data)
    , _settings(new QSettings(QSettings::IniFormat, QSettings::UserScope, "Shadow Revival", "Farmers"))
{

}

SettingsManager::~SettingsManager()
{
    delete _settings;
}

void SettingsManager::save()
{
    QtConcurrent::run([=] () {
        _settings->setValue("houses", _data->houses());
        _settings->setValue("fields", _data->fields());
        _settings->setValue("townhall", _data->townhall());
    });
}

void SettingsManager::load()
{
    _data->setHouses(_settings->value("houses", 0).toInt());
    _data->setFields(_settings->value("fields", 0).toInt());
    _data->setTownhall(_settings->value("townhall", false).toBool());
}
