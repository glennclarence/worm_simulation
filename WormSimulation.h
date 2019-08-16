#ifndef WORMSIMULATION_H
#define WORMSIMULATION_H

#include "Worm.h"
#include <pybind11/numpy.h>
namespace WormSpace
{
namespace py = pybind11;
struct WormSimulation{

WormSimulation(): m_worm()
{}

WormSimulation(uint worm_size, uint grid_size_x, uint grid_size_y): m_worm(worm_size,make_int2(grid_size_x,grid_size_y) ){}


py::array_t<double> run(uint num_steps, uint increments, bool choose_random_joints)
{

    int array_size = num_steps / increments;
    int* hist_array = new int[2*array_size * m_worm.m_size];
    for( int i = 0; i< num_steps;++i)
    {
        if(choose_random_joints)
        {
            m_worm.translateRandomJoint();
        }
        else
        {
            m_worm.translateJointbyIndex(i % m_worm.m_size);
        }     
        if ( i % increments == 0 )
        {
            auto delta = m_worm[0].getPos() - m_worm[m_worm.m_size -1].getPos();
            int  dist = sqrt(dot(delta, delta)); 
            for(int k = 0; k < m_worm.m_size; ++k)//m_worm.m_size
            {
                auto pos = m_worm[k].getPos();
                hist_array[2*m_worm.m_size*(i / increments) + 2*k ] = pos.x ;
                hist_array[2*m_worm.m_size*(i / increments) + 2*k +1 ] = pos.y ;

            }
        }   
    }

return py::array(std::vector<ptrdiff_t>{array_size, m_worm.m_size,2}, hist_array);
}


Worm m_worm;

};

} // namespace WormSpace

#endif // !JOINT_H
