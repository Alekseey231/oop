#ifndef INVISIBLE_OBJECT_H
#define INVISIBLE_OBJECT_H

#include "../BaseObject.h"

class InvisibleObject : public BaseObject
{
  public:
    InvisibleObject() = default;
    bool is_visible() override
    {
        return false;
    };
    ~InvisibleObject() override = default;
};

#endif
