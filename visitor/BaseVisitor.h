#ifndef BASE_VISITOR_H
#define BASE_VISITOR_H

class CarcasModel;

class Visitor
{
    public:
        virtual void visit(CarcasModel &model) = 0;
};

#endif