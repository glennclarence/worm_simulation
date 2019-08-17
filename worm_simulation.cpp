#include "WormSimulation.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

//using namespace WormSpace;


PYBIND11_MODULE(worm_simulation, m) {
    py::class_<WormSpace::WormSimulation>(m, "worm_simulation")
        .def(py::init<int, int, int,int>())
        .def("run", &WormSpace::WormSimulation::run,
         py::return_value_policy::move);
}



