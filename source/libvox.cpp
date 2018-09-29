#include "libvox.h"
#include "vox.h"

#include <fstream>
#include <iostream>

namespace vox {

vox read(const void* data, size_t size) {
  auto id = read_t<uint32_t>(data, size);
  if (vox::id == id) {
    auto version = read_t<int32_t>(data, size);
    if (150 == version) {
      return vox::read(data, size);
    }
  }
  return vox();
}

}  // namespace vox
