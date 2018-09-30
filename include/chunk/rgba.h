#pragma once

#include "chunk.h"

#include <vector>

namespace vox {

/**
 * Rgba chunk
 */
struct rgba : public chunk {
  static constexpr uint32_t tag = generate_id('R', 'G', 'B', 'A');
  struct color {
    uint8_t r, g, b, a;
    color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
        : r(r), g(g), b(b), a(a) {}
  };

  std::vector<color> palettes;

  static rgba read(const void*& data, size_t& size);
};

}  // namespace vox
