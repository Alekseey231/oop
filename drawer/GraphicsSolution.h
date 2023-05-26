#ifndef GRAPHICSSOLUTION_H
#define GRAPHICSSOLUTION_H

#include <memory>
#include "BaseGraphicsScene.h"
#include "QtGraphicsFactory.h"
#include "GraphicsFactory.h"
#include <stdlib.h>

#define TYPE 1

/*class GraphicsSolution
{
public:
    template<typename... Args>
    static std::shared_ptr<GraphicsFactory> instance()
    {
        //class Proxy: public GraphicsSolution{};
#if TYPE == 1
        static std::shared_ptr<GraphicsFactory> instance = std::make_shared<QtGraphicsFactory>();
#else
        static std::shared_ptr<GraphicsFactory> instance = make_shared<>();
#endif
        return instance;
    }
    ~GraphicsSolution() = default;

    GraphicsSolution(const GraphicsSolution&) = delete;
    GraphicsSolution& operator=(const GraphicsSolution&) = delete;
private:
    GraphicsSolution() = default;
};*/

#endif // GRAPHICSSOLUTION_H
