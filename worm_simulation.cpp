#include "WormSimulation.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

//using namespace WormSpace;


PYBIND11_MODULE(worm_simulation, m) {
        m.doc() = "Class to simulate a 3 dimensional worm moving inside a box."; 
    py::class_<WormSpace::WormSimulation>(m, "worm_simulation")
        .def(py::init<int, int>(), "Create an instance of worm_simulation, via its size and the box dimenstion given as integer.",py::arg("worm_size"), py::arg("box_dimension"))
        .def("run", &WormSpace::WormSimulation::run,"Run the simulation with a specified number of iterations and increments that determines the number of positions returned as a numpy array",
        py::return_value_policy::move, py::arg("n_steps"),py::arg("return_increment"),py::arg("update_random_joints") );
}