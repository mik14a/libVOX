#include "chunk/layr.h"

#include "chunk/node.h"

namespace vox {

layr layr::read(const void*& data, size_t& size) {
  layr layr;
  auto id = read_t<uint32_t>(data, size);
  if (layr::tag != id) return layr;
  layr.content = read_t<int32_t>(data, size);
  layr.children = read_t<int32_t>(data, size);
  layr.id = read_t<int32_t>(data, size);
  layr.attribute = read_dictionary(data, size);
  read_t<int32_t>(data, size);  // reserved
  return layr;
}

}  // namespace vox
