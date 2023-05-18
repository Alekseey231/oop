#include "matrix/matrix/matrix.h"
#include <iostream>

class Point1
{
    public:
        Point1(const double x, const double y, const double z) : data({{x,y,z,1}}) {};
    private:
        Matrix<double> data{{0,0,0,1}};
};

int main()
{
    Point1 point(1,2,3);
    std::cout << point.data[0][0];
}