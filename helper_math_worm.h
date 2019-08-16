#ifndef HELPER_MATH_WORM_H
#include "helper_math.h"

bool operator==(int2 a, int2 b)
{
    return (a.x == b.x) && (a.y == b.y);
}

bool operator>(int2 a, int2 b)
{
    return (a.x > b.x) || (a.y > b.y);
}

bool operator<(int2 a, int2 b)
{
    return (a.x < b.x) || (a.y < b.y);
}

bool operator<(int2 a, float b)
{
    return (a.x < b) && (a.y < b);
}

bool operator<=(int2 a, int b)
{
    return (a.x <= b) && (a.y <= b);
}
#endif // !HELPER_MATH_WORM_H

