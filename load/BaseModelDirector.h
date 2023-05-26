#ifndef BASEMODELDIRECTOR_H
#define BASEMODELDIRECTOR_H

#include "BaseDirector.h"
#include "BaseModelBuilder.h"
#include <fstream>
#include <memory>
#include <string>

class BaseModelDirector : public BaseDirector
{
  public:
    BaseModelDirector() = default;
    virtual ~BaseModelDirector() = default;
    virtual std::shared_ptr<CarcasModel> load(std::shared_ptr<BaseModelBuilder> builder,
                                              const std::string &fileName) = 0;
};

#endif // BASEDIRECTOR_H
// load/BaseDirector.h
