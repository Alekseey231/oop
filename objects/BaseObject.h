#ifndef BASE_OBJECT
#define BASE_OBJECT

#include "../visitor/BaseVisitor.h"
#include <memory>
#include <vector>

class BaseObject;
using ObjectVector = std::vector<std::shared_ptr<BaseObject>>;

class BaseObject
{
    using value_type = BaseObject;
    using size_type = size_t;
    using iterator = ObjectVector::iterator;
    using const_iterator = ObjectVector::const_iterator;

  public:
    BaseObject() : id(current_id++){};
    virtual ~BaseObject() = default;

    virtual bool is_visible()
    {
        return false;
    };
    virtual bool is_composite()
    {
        return false;
    };

    virtual void accept(Visitor &v) = 0;

    virtual std::shared_ptr<BaseObject> get_object(std::size_t object_id)
    {
        return nullptr;
    }

    virtual std::size_t add_object(const std::shared_ptr<BaseObject> &object)
    {
        return false;
    };
    virtual bool remove_object(std::size_t object_id)
    {
        return false;
    };
    virtual const_iterator begin() const
    {
        return const_iterator();
    };
    virtual const_iterator end() const
    {
        return const_iterator();
    };

  protected:
    std::size_t id;
    static std::size_t current_id;
};

#endif
