#ifndef VISIBLE_OBJECT_H
#define VISIBLE_OBJECT_H

#include "../BaseObject.h"

class VisibleObject : public BaseObject
{
  public:
    VisibleObject() = default;
    bool is_visible() override
    {
        return true;
    };
    ~VisibleObject() override = default;
};

#endif
