#include "chunk/main.h"

namespace vox {

main main::read(const void*& data, size_t& size) {
  auto main = vox::main();
  auto id = read_t<uint32_t>(data, size);
  if (vox::main::tag != id) return main;

  main.content = read_t<int32_t>(data, size);
  main.children = read_t<int32_t>(data, size);
  return main;
}

}  // namespace vox
