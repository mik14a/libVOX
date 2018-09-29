#pragma once

#include "chunk.h"

namespace vox {

/**
 * Main chunk
 */
struct main : public chunk {
  static constexpr uint32_t id = generate_id('M', 'A', 'I', 'N');

  static main read(const void*& data, size_t& size);
};

}  // namespace vox
