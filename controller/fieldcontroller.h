#ifndef FIELD_CONTROLLER_H
#define FIELD_CONTROLLER_H

#include "ibuildingcontroller.h"

class FieldController : public IBuildingController
{
    Q_OBJECT

public:
    explicit FieldController(QObject *parent = nullptr);

    virtual void build();

protected slots:
    virtual void updateCanBuild();

protected:
    virtual void connectData();

};

#endif // FIELD_CONTROLLER_H
