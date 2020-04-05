#include "chunk/rgba.h"

namespace vox {

vox::rgba rgba::read(const void*& data, size_t& size) {
  auto rgba = vox::rgba();
  auto id = read_t<uint32_t>(data, size);
  if (vox::rgba::tag != id) return rgba;

  rgba.content = read_t<int32_t>(data, size);
  rgba.children = read_t<int32_t>(data, size);
  for (auto n = 0; n < 256; ++n) {
    auto r = read_t<uint8_t>(data, size);
    auto g = read_t<uint8_t>(data, size);
    auto b = read_t<uint8_t>(data, size);
    auto a = read_t<uint8_t>(data, size);
    rgba.palettes.emplace_back(r, g, b, a);
  }
  return rgba;
}

}  // namespace vox
