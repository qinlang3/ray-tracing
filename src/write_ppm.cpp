#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  std::ofstream output_file(filename);
  if (!output_file) return false;
  std::string format = num_channels == 3 ? "P3 " : "P2 ";
  if(!(output_file<<format<<width<<" "<<height<<" "<<255<<std::endl)) return false;
  for(int i = 0; i < data.size(); i++) {
    if(!(output_file<<(int) data[i]<<" ")) return false;
  }
  return true;
}
