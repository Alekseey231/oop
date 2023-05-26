#include "ModelLoadModerator.h"
#include "BaseModelDirector.h"
#include "FileCarcasModelLoader.h"
#include "FileModelDirector.h"
#include "ModelBuilder.h"

ModelLoadModerator::ModelLoadModerator(std::shared_ptr<BaseModelDirector> director)
    : _builder(make_shared<ModelBuilder>()), _director(director)
{
}

std::shared_ptr<BaseObject> ModelLoadModerator::load(const std::string &fileName)
{
    std::shared_ptr<CarcasModel> model_sh_ptr;
    model_sh_ptr = _director->load(_builder, fileName);
    // Todo exceptions

    return std::shared_ptr<BaseObject>(model_sh_ptr);
}

std::shared_ptr<ModelLoadModerator> ModelLoadModeratorCreator::createModerator()
{
    if (nullptr == _moderator)
        createInstance();

    return _moderator;
}

void ModelLoadModeratorCreator::createInstance()
{
    static std::shared_ptr<ModelLoadModerator> moderator;

    if (!moderator)
    {
        auto reader = std::shared_ptr<FileCarcasModelLoader>(std::make_shared<FileCarcasModelLoader>());
        auto director = std::shared_ptr<BaseModelDirector>(std::make_shared<FileModelDirector>(reader));
        moderator = std::make_shared<ModelLoadModerator>(director);
    }

    _moderator = moderator;
}
