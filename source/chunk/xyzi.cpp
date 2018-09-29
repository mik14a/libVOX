#include "chunk/xyzi.h"

namespace vox {

xyzi xyzi::read(const void*& data, size_t& size) {
  xyzi xyzi;
  auto id = read_t<uint32_t>(data, size);
  if (xyzi::id != id) return xyzi;
  xyzi.content = read_t<int32_t>(data, size);
  xyzi.children = read_t<int32_t>(data, size);
  xyzi.num = read_t<int32_t>(data, size);
  for (auto n = 0; n < xyzi.num; ++n) {
    uint8_t x = read_t<uint8_t>(data, size);
    uint8_t y = read_t<uint8_t>(data, size);
    uint8_t z = read_t<uint8_t>(data, size);
    uint8_t i = read_t<uint8_t>(data, size);
    xyzi.voxels.push_back(cell(x, y, z, i));
  }
  return xyzi;
}

}  // namespace vox
