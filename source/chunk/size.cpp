#include "chunk/size.h"

namespace vox {

size size::read(const void*& data, size_t& size) {
  auto vsize = ::vox::size();
  auto id = read_t<uint32_t>(data, size);
  if (vox::size::tag != id) return vsize;

  vsize.content = read_t<int32_t>(data, size);
  vsize.children = read_t<int32_t>(data, size);
  vsize.x = read_t<int32_t>(data, size);
  vsize.y = read_t<int32_t>(data, size);
  vsize.z = read_t<int32_t>(data, size);
  return vsize;
}

}  // namespace vox
