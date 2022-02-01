#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ray.origin = camera.e;
  ray.direction = (camera.u*(camera.width*((j+0.5)/width)-camera.width/2)+
                  camera.v*(camera.height/2-camera.height*((i+0.5)/height))+
                  camera.e-camera.d*camera.w)-camera.e;
}
