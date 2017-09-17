#ifndef IBUILDING_CONTROLLER_H
#define IBUILDING_CONTROLLER_H

#include <QObject>

class Data;

class IBuildingController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool canBuild READ canBuild NOTIFY canBuildChanged)
    Q_PROPERTY(const QString & errorString READ errorString NOTIFY errorStringChanged)

public:
    explicit IBuildingController(QObject *parent = nullptr);

    void setData(Data *data);

    bool canBuild() const { return _canBuild; }
    const QString & errorString() const { return _errorString; }

public slots:
    virtual void build() = 0;

protected slots:
    virtual void updateCanBuild() = 0;

protected:
    virtual void connectData() = 0;
    void manageCanBuild(bool canBuild, const QString & errorString);
    Data *_data;

private:
    bool _canBuild;
    QString _errorString;

signals:
    void canBuildChanged();
    void errorStringChanged();

};

#endif // IBUILDING_CONTROLLER_H
