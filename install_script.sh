pip install pybind11
c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` worm_simulation.cpp -o worm_simulation`python3-config --extension-suffix`   -w -I./helpers