#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

class QSettings;
class Data;

class SettingsManager
{
public:
    explicit SettingsManager(Data *data);
    virtual ~SettingsManager();

    void save();
    void load();

private:
    void initSettings();

    Data *_data;
    QSettings *_settings;
};

#endif // SETTINGSMANAGER_H
