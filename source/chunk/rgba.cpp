#include "chunk/rgba.h"

namespace vox {

vox::rgba rgba::read(const void*& data, size_t& size) {
  rgba rgba;
  auto id = read_t<uint32_t>(data, size);
  if (rgba::tag != id) return rgba;
  rgba.content = read_t<int32_t>(data, size);
  rgba.children = read_t<int32_t>(data, size);
  for (auto n = 0; n < 256; ++n) {
    uint8_t r = read_t<uint8_t>(data, size);
    uint8_t g = read_t<uint8_t>(data, size);
    uint8_t b = read_t<uint8_t>(data, size);
    uint8_t a = read_t<uint8_t>(data, size);
    rgba.palettes.push_back(color(r, g, b, a));
  }
  return rgba;
}

}  // namespace vox
