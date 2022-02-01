#include "Plane.h"
#include "Ray.h"
#include <iostream>
bool Plane::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  if(ray.direction.dot(normal)!=0){
    double curr_t = (point-ray.origin).dot(normal)/(ray.direction.dot(normal));
    if(curr_t>=min_t){
      t = curr_t;
      n = normal.normalized();
      return true;
    }
  }
  return false;
}

