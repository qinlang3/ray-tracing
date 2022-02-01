#include "first_hit.h"

bool first_hit(
  const Ray & ray, 
  const double min_t,
  const std::vector< std::shared_ptr<Object> > & objects,
  int & hit_id, 
  double & t,
  Eigen::Vector3d & n)
{
  int no_hit = 1;
  double curr_t;
  Eigen::Vector3d curr_n;
  for (int i=0;i<objects.size();i++){
    if(objects[i]->intersect(ray, min_t, curr_t, curr_n)){
      if(no_hit){
        hit_id=i;
        t=curr_t;
        n=curr_n;
        no_hit=0;
      }else if(curr_t<t) {
        hit_id=i;
        t=curr_t;
        n=curr_n;
      }
    }
  }
  if(!no_hit) return true;
  return false;
}
