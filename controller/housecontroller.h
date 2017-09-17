#ifndef HOUSE_CONTROLLER_H
#define HOUSE_CONTROLLER_H

#include "ibuildingcontroller.h"

class HouseController : public IBuildingController
{
    Q_OBJECT

public:
    explicit HouseController(QObject *parent = nullptr);

    virtual void build();

protected slots:
    virtual void updateCanBuild();

protected:
    virtual void connectData();

};

#endif // HOUSE_CONTROLLER_H
