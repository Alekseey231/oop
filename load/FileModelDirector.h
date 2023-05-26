#ifndef FILEMODELDIRECTOR_H
#define FILEMODELDIRECTOR_H

#include "../objects/visible_object/carcas_model/CarcasModel.h"
#include "BaseModelDirector.h"
#include "FileCarcasModelLoader.h"

class FileModelDirector : public BaseModelDirector
{
  public:
    FileModelDirector();
    explicit FileModelDirector(std::shared_ptr<FileCarcasModelLoader> &loader);

    ~FileModelDirector() override = default;

    std::shared_ptr<CarcasModel> load(std::shared_ptr<BaseModelBuilder> builder, const std::string &fileName) override;

  protected:
    std::shared_ptr<FileCarcasModelLoader> _loader;
};

#endif // FILEMODELDIRECTOR_H
// load/FileModelDirector.h
