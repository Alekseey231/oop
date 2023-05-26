#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <stdlib.h>
#include <memory>
#include "BaseCreator.h"

class BaseBuilder
{
public:
    BaseBuilder() = default;
    ~BaseBuilder() = default;

    virtual void build() = 0;
    virtual bool isBuild() const = 0;
};

class BaseBuilderCreator : public BaseCreator
{
  public:
    virtual ~BaseBuilderCreator() = default;
    virtual std::unique_ptr<BaseBuilder> createBuilder() = 0;
};

template <std::derived_from<BaseBuilder> Tprod> class ConBuilderCreator : public BaseBuilderCreator
{
  public:
    std::unique_ptr<BaseBuilder> createBuilder() override
    {
        return std::make_unique<Tprod>();
    }
};

class CrBuilderCreator
{
  public:
    template <typename Tprod> static std::unique_ptr<BaseBuilderCreator> createConCreator()
    {
        return std::make_unique<ConBuilderCreator<Tprod>>();
    }
};


#endif // BASEBUILDER_H
