#ifndef BASE_GRAPHICS_SCENE_H
#define BASE_GRAPHICS_SCENE_H


class BaseGraphicsScene
{
    public:
        BaseGraphicsScene() = default;
        virtual ~BaseGraphicsScene() = default;

        virtual void clear() = 0;
        virtual void draw_line(float x1, float y1, float x2, float y2) = 0;
};

#endif