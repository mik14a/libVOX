#include "chunk/pack.h"

namespace vox {

pack pack::read(const void*& data, size_t& size) {
  pack pack;
  auto id = read_t<uint32_t>(data, size);
  if (pack::tag != id) return pack;
  pack.content = read_t<int32_t>(data, size);
  pack.children = read_t<int32_t>(data, size);
  pack.models = read_t<int32_t>(data, size);
  return pack;
}

}  // namespace vox
