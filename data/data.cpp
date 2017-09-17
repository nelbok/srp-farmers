#include "data.h"

#define SETTER(CLASS, LNAME, UNAME, TYPE)   \
void CLASS::set ## UNAME(TYPE value)        \
{                                           \
    if (_ ## LNAME == value)                \
        return;                             \
                                            \
    _ ## LNAME = value;                     \
    emit LNAME ## Changed();                \
}                                           \

#define GETTER(CLASS, LNAME, UNAME, TYPE)   \
TYPE CLASS::LNAME() const                   \
{                                           \
    return _ ## LNAME;                      \
}                                           \

#define ACCESSOR(CLASS, LNAME, UNAME, TYPE) \
SETTER(CLASS, LNAME, UNAME, TYPE)           \
GETTER(CLASS, LNAME, UNAME, TYPE)           \

Data::Data(QObject *parent)
    : QObject(parent)
    , _farmers(0)
    , _houses(0)
    , _fields(0)
    , _townhall(false)
{

}

ACCESSOR(Data, farmers, Farmers, int)
ACCESSOR(Data, houses, Houses, int)
ACCESSOR(Data, fields, Fields, int)
ACCESSOR(Data, townhall, Townhall, bool)
