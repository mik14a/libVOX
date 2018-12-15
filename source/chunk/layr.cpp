#include "chunk/layr.h"
#include "node/node.h"

namespace vox {

layr layr::read(const void*& data, size_t& size) {
  layr layr;
  auto id = read_t<uint32_t>(data, size);
  if (layr::tag != id) return layr;
  layr.content = read_t<int32_t>(data, size);
  layr.children = read_t<int32_t>(data, size);
  layr.id = read_t<int32_t>(data, size);
  auto attribute = read_dictionary(data, size);
  auto name = attribute.find("_name");
  layr.name = name != attribute.end() ? name->second : std::string();
  auto hidden = attribute.find("_hidden");
  layr.hidden = hidden != attribute.end() ? std::stoi(hidden->second) : false;
  read_t<int32_t>(data, size);  // reserved
  return layr;
}

}  // namespace vox
