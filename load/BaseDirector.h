#ifndef BASEDIRECTOR_H
#define BASEDIRECTOR_H

#include "BaseCreator.h"
#include <memory>
#include <stdlib.h>

class BaseDirector
{
  public:
    BaseDirector() = default;
    virtual ~BaseDirector() = default;
};

/*class BaseDirectorCreator : public BaseCreator
{
  public:
    virtual ~BaseDirectorCreator() = default;
    virtual std::unique_ptr<BaseDirector> createDirector() = 0;
};

template <std::derived_from<BaseDirector> Tprod> class ConDirectorCreator : public BaseDirectorCreator
{
  public:
    std::unique_ptr<BaseDirector> createDirector() override
    {
        return std::make_unique<Tprod>();
    }
};

class CrModelDirectorCreator
{
  public:
    template <typename Tprod> static std::unique_ptr<BaseDirectorCreator> createConCreator()
    {
        return std::make_unique<ConDirectorCreator<Tprod>>();
    }
};*/

#endif // BASEDIRECTOR_H
