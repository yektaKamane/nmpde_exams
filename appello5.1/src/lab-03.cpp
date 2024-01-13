#include <deal.II/base/convergence_table.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Poisson2D.hpp"

// Main function.
int
main(int /*argc*/, char * /*argv*/[])
{
  
  const std::string mesh_file_name =
    "../../examples/gmsh/mesh-square-h0.100000.msh";
  const unsigned int r = 1;

  Poisson2D problem(mesh_file_name, r);

  problem.setup();
  problem.assemble();
  problem.solve();
  problem.output();

  const double error_L2 = problem.compute_error(VectorTools::L2_norm);
  const double error_H1 = problem.compute_error(VectorTools::H1_norm);

  std::cout << "L2 : " << error_L2 << "\n";
  std::cout << "H1 : " << error_H1 << std::endl;

  return 0;
}