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




bool operator==(int3 a, int3 b)
{
    return (a.x == b.x) && (a.y == b.y) && (a.z == b.z);
}

bool operator>(int3 a, int3 b)
{
    return (a.x > b.x) || (a.y > b.y)|| (a.z > b.z);
}

bool operator<(int3 a, int3 b)
{
    return (a.x < b.x) || (a.y < b.y) || (a.z < b.z);
}

bool operator<(int3 a, float b)
{
    return (a.x < b) && (a.y < b) && (a.z < b);
}

bool operator<=(int3 a, int b)
{
    return (a.x <= b) && (a.y <= b) && (a.z <= b);
}

#endif // !HELPER_MATH_WORM_H

