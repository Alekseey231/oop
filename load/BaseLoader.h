#ifndef BASELOADER_H
#define BASELOADER_H

#include <string>
#include <vector>

#include "../objects/visible_object/carcas_model/edge.h"
#include "../objects/visible_object/carcas_model/figure.h"
#include "../objects/visible_object/carcas_model/point.h"
#include "BaseCreator.h"

class BaseLoader
{
  public:
    BaseLoader() = default;
    virtual ~BaseLoader() = default;

    virtual void open(const std::string &fileName) = 0;
    virtual void close() = 0;

    virtual std::size_t loadCount() = 0;
    virtual Point loadPoint() = 0;
    virtual std::vector<Point> loadPoints() = 0;
    virtual std::vector<Edge> loadEdges(int &amountPoint) = 0;
};

/*class BaseModelLoaderCreator : public BaseCreator
{
  public:
    virtual ~BaseModelLoaderCreator() = default;
    virtual std::unique_ptr<BaseLoader> createModelLoader() = 0;
};

template <std::derived_from<BaseLoader> Tprod> class ConLoaderCreator : public BaseModelLoaderCreator
{
  public:
    std::unique_ptr<BaseLoader> createModelLoader() override
    {
        return std::make_unique<Tprod>();
    }
};

class CrModelLoaderCreator
{
  public:
    template <typename Tprod> static std::unique_ptr<BaseModelLoaderCreator> createConCreator()
    {
        return std::make_unique<ConLoaderCreator<Tprod>>();
    }
};
*/
#endif // BASELOADER_H
// load/BaseLoader.h
