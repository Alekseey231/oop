#ifndef BASE_OBJECT
#define BASE_OBJECT

#include "../math/transformation.h"
#include "../visitor/BaseVisitor.h"
#include <map>
#include <memory>

class RotateVisitor;
class ScaleVisitor;
class TranslateVisitor;

class BaseObject;
using ObjectMap = std::map<std::size_t, std::shared_ptr<BaseObject>>;

class BaseObject
{
    using value_type = ObjectMap::value_type;
    using size_type = ObjectMap::size_type;
    using iterator = ObjectMap ::iterator;
    using const_iterator = ObjectMap ::const_iterator;

  public:
    BaseObject() = default;
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
    Matrix4 get_transform_matrix() const
    {
        return transform->get_matrix();
    }

  protected:
    friend RotateVisitor;
    friend ScaleVisitor;
    friend TranslateVisitor;
    std::shared_ptr<Transformation> transform = std::make_shared<Transformation>();
};

#endif
