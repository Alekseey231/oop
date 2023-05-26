#ifndef LOADMANAGER_H
#define LOADMANAGER_H

#include "../load/BaseLoadModerator.h"


class LoadManager
{
public:
    LoadManager() = default;
    std::size_t load(const std::string &name);
    void setModerator(std::shared_ptr<BaseLoadModerator> m);
   private:
std::shared_ptr<BaseLoadModerator> _moderator;
};

class LoadManagerCreator
{
  public:
    std::shared_ptr<LoadManager> get();

  protected:
    std::shared_ptr<LoadManager> create();
    std::shared_ptr<LoadManager> manager{nullptr};
};

#endif // LOADMANAGER_H
