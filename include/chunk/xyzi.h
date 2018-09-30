#pragma once

#include "chunk.h"

#include <vector>

namespace vox {

/**
 * Xyzi chunk
 */
struct xyzi : public chunk {
  static constexpr uint32_t tag = generate_id('X', 'Y', 'Z', 'I');
  struct cell {
    uint8_t x, y, z, i;
    cell(uint8_t x, uint8_t y, uint8_t z, uint8_t i) : x(x), y(y), z(z), i(i) {}
  };

  int32_t num;
  std::vector<cell> voxels;

  static xyzi read(const void*& data, size_t& size);
};

}  // namespace vox
