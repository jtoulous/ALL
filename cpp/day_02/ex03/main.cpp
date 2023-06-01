#include "Fixed.hpp"
#include "Point.hpp"

float power(float nb, int powa)
{
    int z = 0;
    float res = nb;

    while (z < powa - 1)
    {
        res = res * nb;
        z++;
    }
    return (res);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
    Fixed res1;
    Fixed res2;
    Fixed res3;

    res1 = a.vectorial_product(b, point);
    res2 = b.vectorial_product(c, point);
    res3 = c.vectorial_product(a, point);

    if (res1 == 0 || res2 == 0 || res3 == 0)
        return (false);
    if (res1 > 0)
    {
        if (res2 < 0 || res3 < 0)
            return (false);
    }
    if (res1 < 0)
    {
        if (res2 > 0 || res3 > 0)
            return (false);
    }
    return (true);
}

int main( void ) 
{

    const Point a(1.2, 0.8);
    const Point b(2.6, 4.6);
    const Point c(7.6, 3.1);
    const Point p(1.7, 2.4);

    if (bsp(a, b, c, p))
        std::cout << "good" << std::endl;
    else
        std::cout << "no good" << std::endl;
    return 0;
}