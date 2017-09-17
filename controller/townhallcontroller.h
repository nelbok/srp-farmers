#ifndef TOWNHALL_CONTROLLER_H
#define TOWNHALL_CONTROLLER_H

#include "ibuildingcontroller.h"

class TownhallController : public IBuildingController
{
    Q_OBJECT

public:
    explicit TownhallController(QObject *parent = nullptr);

    virtual void build();

protected slots:
    virtual void updateCanBuild();

protected:
    virtual void connectData();

};

#endif // TOWNHALL_CONTROLLER_H
