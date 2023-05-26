#ifndef CAMERASOLUTION_H
#define CAMERASOLUTION_H

#include "BaseCamera.h"
#include "Camera.h"

class Solution
{
    using CreateCreator = std::unique_ptr<BaseCameraCreator> (&)();
    using CallBackMap = std::map<std::size_t, CreateCreator>;

  public:
    Solution() = default;
    explicit Solution(std::initializer_list<std::pair<std::size_t, CreateCreator>> list);

    bool registration(std::size_t id, CreateCreator createfun);
    bool check(std::size_t id)
    {
        return this->callbacks.erase(id) == 1;
    };

    std::unique_ptr<BaseCameraCreator> create(const std::size_t id);

  private:
    CallBackMap callbacks;
};

#endif // CAMERASOLUTION_H
