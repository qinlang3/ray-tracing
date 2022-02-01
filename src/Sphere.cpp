#include "Sphere.h"
#include "Ray.h"

bool Sphere::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  double a = ray.direction.dot(ray.direction);
  double b = 2*ray.direction.dot(ray.origin-center);
  double c = (ray.origin-center).dot(ray.origin-center)-radius*radius;
  double delta = b*b-4*a*c;
  
  if(delta>=0){
    double t1=(-b+sqrt(delta))/(2*a);
    double t2=(-b-sqrt(delta))/(2*a);
    if(t1>t2) t1=t2;
    if(t1>=min_t){
      t=t1;
      n=(ray.origin+t*ray.direction-center).normalized();
      return true;
    }
  }
  return false;
}


