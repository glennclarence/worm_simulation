#include <iostream>
#include "Joint.h"
#include "Worm.h"
#include <iostream>
#include <fstream>
#include <chrono>

#define do_save 0
#define translate_random 0
using namespace WormSpace;

int2 gridSize = make_int3(200, 200,200);
int nsteps = 1e8;
int increment = 100;
int wormsize = 100;

int main()
{
    Worm worm(wormsize, gridSize);
    for (int i = 0; i < worm.m_size; ++i)
    {
        worm[i].setPos(make_int3(i + 30, 100,100));
    }
    std::ofstream positionfile;
    positionfile.open("steps.csv");

    positionfile << std::endl;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < nsteps; ++i)
    {
#if translate_random == 0
        worm.translateJointbyIndex(i % worm.m_size);
#else
        worm.translateRandomJoint();
#endif

#if do_save == 1
        if (i % increment == 0)
        {
            for (auto joint : worm)
            {
                auto pos = joint.getPos();
                positionfile << pos.x << "," << pos.y << ",";
            }
            positionfile << std::endl;
        }
#endif // DEBUG
    }

    auto stop = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    std::cout << "duration: " << duration << " ms" << std::endl;
    positionfile.close();

    return 0;
}

