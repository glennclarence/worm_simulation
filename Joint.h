#ifndef JOINT_H
#define JOINT_H

#include "vector_types.h"
#include "helper_math.h"
#include "helper_math_worm.h"
#include <iostream>
#include "config.h"

namespace WormSpace
{

struct Joint
{
    using Pos = int3;
    Joint() : m_pos(make_int3(0,0, 0)) {}

    Joint(Pos position) : m_pos(position) {}

    inline bool isInRange(Pos position)
    {
        Pos d_pos = (m_pos - position);
        return dot(d_pos, d_pos) <= MAX_DISTANCE;
    }

    inline bool isAtPosition(Pos position)
    {
        return m_pos == position;
    }

    inline void translate(Pos deltaPos)
    {
        m_pos += deltaPos;
    }

    inline Pos getPos()
    {
        return m_pos;
    }

    inline void setPos(Pos position)
    {
        m_pos = position;
    }

    Pos m_pos;
};

} // namespace WormSpace

#endif // !JOINT_H
