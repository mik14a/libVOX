#include "chunk/xyzi.h"

namespace vox {

xyzi xyzi::read(const void*& data, size_t& size) {
  auto xyzi = vox::xyzi();
  auto id = read_t<uint32_t>(data, size);
  if (vox::xyzi::tag != id) return xyzi;

  xyzi.content = read_t<int32_t>(data, size);
  xyzi.children = read_t<int32_t>(data, size);
  xyzi.num = read_t<int32_t>(data, size);
  for (auto n = 0; n < xyzi.num; ++n) {
    auto x = read_t<uint8_t>(data, size);
    auto y = read_t<uint8_t>(data, size);
    auto z = read_t<uint8_t>(data, size);
    auto i = read_t<uint8_t>(data, size);
    xyzi.voxels.emplace_back(x, y, z, i);
  }
  return xyzi;
}

}  // namespace vox
