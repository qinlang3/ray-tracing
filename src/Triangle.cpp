#include "Triangle.h"
#include "Ray.h"
#include <Eigen/Geometry>
#include <iostream>

bool Triangle::intersect(
  const Ray & ray, const double min_t, double & t, Eigen::Vector3d & n) const
{
  double x_a = std::get<0>(corners)[0];
  double y_a = std::get<0>(corners)[1];
  double z_a = std::get<0>(corners)[2];
  double x_b = std::get<1>(corners)[0];
  double y_b = std::get<1>(corners)[1];
  double z_b = std::get<1>(corners)[2];
  double x_c = std::get<2>(corners)[0];
  double y_c = std::get<2>(corners)[1];
  double z_c = std::get<2>(corners)[2];
  double a = x_a-x_b;
  double b = y_a-y_b;
  double c = z_a-z_b;
  double d = x_a-x_c;
  double e = y_a-y_c;
  double f = z_a-z_c;
  double g = ray.direction[0];
  double h = ray.direction[1];
  double i = ray.direction[2];
  double j = x_a-ray.origin[0];
  double k = y_a-ray.origin[1];
  double l = z_a-ray.origin[2];
  double m = a*(e*i-h*f)+b*(g*f-d*i)+c*(d*h-e*g);
  double curr_t = -(f*(a*k-j*b)+e*(j*c-a*l)+d*(b*l-k*c))/m;
  if(curr_t<min_t) return false;
  double alpha = (i*(a*k-j*b)+h*(j*c-a*l)+g*(b*l-k*c))/m;
  if(alpha<0||alpha>1) return false;
  double beta = (j*(e*i-h*f)+k*(g*f-d*i)+l*(d*h-e*g))/m;
  if(beta<0||beta>1) return false;
  if(alpha+beta<=1){
    t = curr_t;
    n = ((std::get<1>(corners)-std::get<0>(corners)).cross(std::get<2>(corners)-std::get<0>(corners))).normalized();
    return true;
  }
  return false;
}


