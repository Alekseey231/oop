#ifndef CARCASMODELSOURCE_H
#define CARCASMODELSOURCE_H

#include "../objects/visible_object/carcas_model/CarcasModel.h"
#include <optional>

class CarcasModelSource
{
  public:
    virtual std::optional<Edge> next_edge() = 0;
    virtual std::optional<Point> next_point() = 0;
};

class CarcasModelSourceCreator
{
  public:
    virtual ~CarcasModelSourceCreator() = default;
    virtual std::unique_ptr<CarcasModelSource> createCamera(const std::string &path) = 0;
};

template <std::derived_from<CarcasModelSource> Tprod>
class ConCarcasModelSourceCreator : public CarcasModelSourceCreator
{
  public:
    std::unique_ptr<CarcasModelSource> createCamera(const std::string &path) override
    {
        return std::make_unique<Tprod>(path);
    }
};

class CrCarcasModelSourceCreator
{
  public:
    template <typename Tprod> static std::unique_ptr<CarcasModelSource> createConCreator()
    {
        return std::make_unique<ConCarcasModelSourceCreator<Tprod>>();
    }
};

#endif // CARCASMODELSOURCE_H
