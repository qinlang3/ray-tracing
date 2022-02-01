#include <Eigen/Core>

Eigen::Vector3d reflect(const Eigen::Vector3d & in, const Eigen::Vector3d & n)
{
  return (in.normalized()-2*(in.normalized()).dot(n)*n).normalized();
}
