#ifndef CARCASMODELSOURCESOLUTION_H
#define CARCASMODELSOURCESOLUTION_H

#include "./CarcasModelSource.h"

class CarcasModelSourceSolution
{
    using CreateCreator = std::unique_ptr<CarcasModelSourceCreator> (&)();
    using CallBackMap = std::map<std::size_t, CreateCreator>;

  public:
    CarcasModelSourceSolution() = default;
    explicit CarcasModelSourceSolution(std::initializer_list<std::pair<std::size_t, CreateCreator>> list);

    bool registration(std::size_t id, CreateCreator createfun);
    bool check(std::size_t id)
    {
        return this->callbacks.erase(id) == 1;
    };

    std::unique_ptr<CarcasModelSourceCreator> create(const std::size_t id);

  private:
    CallBackMap callbacks;
};

#endif // CARCASMODELSOURCESOLUTION_H
