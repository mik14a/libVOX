#include "chunk/matl.h"

namespace vox {

vox::matl matl::read(const void*& data, size_t& size) {
  auto matl = vox::matl();
  auto id = read_t<uint32_t>(data, size);
  if (vox::matl::tag != id) return matl;

  matl.content = read_t<int32_t>(data, size);
  matl.children = read_t<int32_t>(data, size);
  matl.id = read_t<int32_t>(data, size);
  matl.properties = read_dictionary(data, size);
  return matl;
}

}  // namespace vox
