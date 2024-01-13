#include "Heat.hpp"

// Main function.
int
main(int argc, char *argv[])
{
  Utilities::MPI::MPI_InitFinalize mpi_init(argc, argv);

  const std::string  mesh_file_name =  "../../examples/gmsh/mesh-square-h0.100000.msh";
  const unsigned int degree         = 2;

  const double T      = 3.0;
  const double deltat = 0.1;
  const double theta  = 0.5;

  Heat problem(mesh_file_name, degree, T, deltat, theta);

  problem.setup();
  problem.solve();

  return 0;
}