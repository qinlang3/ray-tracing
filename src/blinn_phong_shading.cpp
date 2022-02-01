#include "blinn_phong_shading.h"
// Hint:
#include "first_hit.h"
#include <iostream>
#include <cmath>

#define I_AMBIENT 0.1         // ambient light itensity
#define BACK_RAY_MIN_T 0.001  // set minimum dectection distance for reflection ray

Eigen::Vector3d blinn_phong_shading(
  const Ray & ray,
  const int & hit_id, 
  const double & t,
  const Eigen::Vector3d & n,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector<std::shared_ptr<Light> > & lights)
{
  Eigen::Vector3d rgb = I_AMBIENT*objects[hit_id]->material->ka;
  Ray back_ray;
  back_ray.origin = ray.origin+ray.direction*t;
  Eigen::Vector3d l;
  double max_t;
  int back_ray_hit_id;
  double back_ray_t;
  Eigen::Vector3d back_ray_n;
  bool result;

  for (int i=0;i<lights.size();i++){
    lights[i]->direction(back_ray.origin, l, max_t);
    back_ray.direction = l;
    result = first_hit(back_ray, BACK_RAY_MIN_T, objects, back_ray_hit_id, back_ray_t, back_ray_n);
    if(!result||back_ray_t > max_t){
      rgb += ((lights[i]->I*fmax(0, n.dot(l))).array() * objects[hit_id]->material->kd.array()).matrix();
      rgb += ((lights[i]->I*pow(fmax(0, n.dot(((-ray.direction).normalized()+l).normalized())), objects[hit_id]->material->phong_exponent)).array() 
                      * objects[hit_id]->material->ks.array()).matrix();
    }
  }
  return rgb;
}
