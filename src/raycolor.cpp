#include "raycolor.h"
#include "first_hit.h"
#include "blinn_phong_shading.h"
#include "reflect.h"

#define MAX_ITERATION 5       // maximum recursive calls to raycolor
#define REFLECT_MIN_T 0.001   // set minimum dectection distance for reflection ray

bool raycolor(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  const std::vector< std::shared_ptr<Light> > & lights,
  const int num_recursive_calls,
  Eigen::Vector3d & rgb)
{
  int hit_id;
  double t;
  Eigen::Vector3d n;
  if(first_hit(ray,  min_t, objects, hit_id, t, n)){
    rgb = blinn_phong_shading(ray, hit_id, t, n, objects, lights);
    if(num_recursive_calls > MAX_ITERATION) return true;
    Ray reflected_ray;
    Eigen::Vector3d reflected_rgb;
    reflected_ray.origin = ray.origin+ray.direction*t;
    reflected_ray.direction = reflect(ray.direction, n);
    if(raycolor(reflected_ray, REFLECT_MIN_T, objects, lights, num_recursive_calls+1, reflected_rgb)){
      rgb += (objects[hit_id]->material->km.array()*reflected_rgb.array()).matrix();
    }
    return true;
  }
  return false;
}
