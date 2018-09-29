#pragma once

#include "chunk.h"

#include <iostream>

namespace vox {

/**
 * Size chunk
 */
struct size : public chunk {
  static constexpr uint32_t id = generate_id('S', 'I', 'Z', 'E');
  int32_t x, y, z;

  static size read(const void*& data, size_t& size);
};

}  // namespace vox
