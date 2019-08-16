#include <iostream>
#include "Joint.h"
#include "Worm.h"
#include <iostream>
#include <fstream>
#include <chrono>

#define do_save 0
#define translate_random 0
using namespace WormSpace;

int2 gridSize = make_int2(200, 200);
int nsteps = 1e8;
int increment = 100;
int wormsize = 100;

// int main()
// {
//     Worm worm(wormsize, gridSize);
//     for (int i = 0; i < worm.m_size; ++i)
//     {
//         worm[i].setPos(make_int2(i + 30, 100));
//     }
//     std::ofstream positionfile;
//     positionfile.open("steps.csv");

//     positionfile << std::endl;

//     auto start = std::chrono::system_clock::now();
//     for (int i = 0; i < nsteps; ++i)
//     {
// #if translate_random == 0
//         worm.translateJointbyIndex(i % worm.m_size);
// #else
//         worm.translateRandomJoint();
// #endif

// #if do_save == 1
//         if (i % increment == 0)
//         {
//             for (auto joint : worm)
//             {
//                 auto pos = joint.getPos();
//                 positionfile << pos.x << "," << pos.y << ",";
//             }
//             positionfile << std::endl;
//         }
// #endif // DEBUG
//     }

//     auto stop = std::chrono::system_clock::now();
//     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
//     std::cout << "duration: " << duration << " ms" << std::endl;
//     positionfile.close();

//     return 0;
// }

int main()
{
    Worm worm(4, make_int2(10, 10));

    for (int i = 0; i < 3; ++i)
    {
        std::cout << worm[i].getPos().x << " " << worm[i].getPos().y << std::endl;
    }


    for ( int i = 0; i< 10; ++i)
    {
        worm.translateJointbyIndex(1);
        std::cout << worm[1].getPos().x << " " << worm[1].getPos().y << std::endl;
    }

    return 0;
}