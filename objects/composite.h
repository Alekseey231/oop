#ifndef BASE_OBJECT_COMPOSITE
#define BASE_OBJECT_COMPOSITE

#include "BaseObject.h"

class Composite : public BaseObject
{
  public:
    Composite() = default;
    ~Composite() override = default;
    explicit Composite(std::shared_ptr<BaseObject> first, ...);

    bool is_composite() override
    {
        return true;
    };
    std::size_t add_object(const std::shared_ptr<BaseObject> &object) override;
    void remove_object(std::size_t object_id) override;
    std::shared_ptr<BaseObject> get_object(std::size_t object_id) override;
    ObjectVector::const_iterator begin() const override
    {
        return this->objects.begin();
    };
    ObjectVector::const_iterator end() const override
    {
        return this->objects.end();
    }
    void accept(Visitor &v) override;

  private:
    ObjectVector objects{};
};

#endif
