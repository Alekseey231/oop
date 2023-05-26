#ifndef BASELOADMODERATOR_H
#define BASELOADMODERATOR_H

#include <memory>
#include "../objects/BaseObject.h"
#include "BaseCreator.h"

class BaseLoadModerator
{
public:
    BaseLoadModerator() = default;
    ~BaseLoadModerator() = default;

    virtual std::shared_ptr<BaseObject> load(const std::string &fileName) = 0;
};

/*class BaseLoadModeratorCreator : BaseCreator
{
  public:
    virtual ~BaseLoadModeratorCreator() = default;
    virtual std::unique_ptr<BaseLoadModerator> createLoadModerator() = 0;
};

template <std::derived_from<BaseLoadModerator> Tprod> class ConLoadModeratorCreator : public BaseLoadModeratorCreator
{
  public:
    std::unique_ptr<BaseLoadModerator> createLoadModerator() override
    {
        return std::make_unique<Tprod>();
    }
};

class CrLoadCreator
{
  public:
    template <typename Tprod> static std::unique_ptr<BaseLoadModeratorCreator> createConCreator()
    {
        return std::make_unique<ConLoadModeratorCreator<Tprod>>();
    }
};*/

#endif // BASELOADMODERATOR_H
