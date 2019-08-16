#ifndef WORM_H
#define WORM_H

#include "Joint.h"
#include "stdlib.h"
#include "config.h"
#include <iostream>
#include <random>

namespace WormSpace
{
std::random_device rd;
struct Worm
{
    using Pos = int2;

    Worm() : m_size(0), m_joints(nullptr), m_uni(0, 8), m_rng(rd()), m_uni_joint(0, 0), m_grid_size(make_int2(0, 0)) {}

    Worm(uint size, Pos grid_size) : m_size(size), m_joints(nullptr), m_uni(0, 8), m_rng(rd()), m_uni_joint(0, size - 1), m_grid_size(grid_size)
    {
        m_joints = (Joint *)malloc(size * sizeof(Joint));
        int x_half = m_grid_size.x / 2;
        int y_half = m_grid_size.y / 2;
        for (int i = 0; i < m_size; ++i)
        {
            m_joints[i].setPos(make_int2(i + x_half - size/2   ,  y_half));
        }
    }

    ~Worm()
    {
        free(m_joints);
    }

    inline uint size()
    {
        return m_size;
    }

    inline void translate(int jointIdx, Pos translation)
    {
        m_joints[jointIdx].translate(translation);
    }

    inline bool translationIsInNeighborProximity(int jointIdx, Pos translation)
    {

        Pos check_position = m_joints[jointIdx].getPos() + translation;
        if (jointIdx > 0 && jointIdx < m_size - 1)
        {
            //std::cout <<jointIdx<<" "<<translation.x << " " <<translation.y<<" " << (int)  m_joints[jointIdx - 1].isInRange(check_position)<< " "<<m_joints[jointIdx + 1].isInRange(check_position)<< std::endl;
            return m_joints[jointIdx - 1].isInRange(check_position) && m_joints[jointIdx + 1].isInRange(check_position);
        }
        else if (jointIdx == 0)
        {
            return m_joints[1].isInRange(check_position);
        }
        else if (jointIdx == m_size - 1)
        {
            return m_joints[m_size - 2].isInRange(check_position);
        }
    }

    inline bool translationIsPossible(int jointIdx, Pos translation)
    {
        if (translation > MAX_TRANSLATION)
        {
            return false;
        }
        Pos check_position = m_joints[jointIdx].getPos() + translation;

        if (check_position.x >= m_grid_size.x || check_position.y >= m_grid_size.y || check_position.x <= 0 || check_position.y <= 0)
        {
            return false;
        }

        if (!translationIsInNeighborProximity(jointIdx, translation))
        {
            return false;
        }
        for (int i = 0; i < m_size; ++i)
        {
            if (i != jointIdx)
            {
                if (i > 0 && i < m_size - 1)
                {
                    if (m_joints[i - 1].isAtPosition(check_position) || m_joints[i + 1].isAtPosition(check_position))
                    {
                        return false;
                    }
                }
                else if (i == 0)
                {
                    if (m_joints[0].isAtPosition(check_position))
                    {
                        return false;
                    }
                }
                else if (i == m_size - 1)
                {
                    if (m_joints[m_size - 1].isAtPosition(check_position))
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    inline void checkAndTranslate(int jointIdx, Pos translation)
    {
        if (translationIsPossible(jointIdx, translation))
        {
            //std::cout <<"t "<<translation.x << " " <<translation.y<<std::endl;
            m_joints[jointIdx].translate(translation);
        }
    }

    inline Pos getRandomTranslation()
    {
        uint random_number = m_uni(m_rng);
        return make_int2( (random_number / 3) - 1,  (random_number % 3)-1);
    }

    inline uint getRandomJointIndex()
    {
        return m_uni_joint(m_rng);
    }

    inline void translateRandomJoint()
    {
        uint jointIdx = getRandomJointIndex();
        auto translation = getRandomTranslation();
        checkAndTranslate(jointIdx, translation);
    }

    inline void translateJointbyIndex(uint jointIdx)
    {
        auto translation = getRandomTranslation();
        checkAndTranslate(jointIdx, translation);
    }

    inline Joint &operator[](int i)
    {
        return m_joints[i];
    }

    Joint *begin()
    {
        return &m_joints[0];
    }

    Joint *end()
    {
        return &m_joints[m_size];
    }

    std::mt19937 m_rng;
    std::uniform_int_distribution<int> m_uni;
    std::uniform_int_distribution<int> m_uni_joint;
    Pos m_grid_size;
    Joint *m_joints;
    uint m_size;
};

} // namespace WormSpace

#endif