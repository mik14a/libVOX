#pragma once

#include "chunk.h"

#include <unordered_map>

namespace vox {

/**
 * Layer Chunk
 */
struct layr : public chunk {
  static constexpr uint32_t tag = generate_id('L', 'A', 'Y', 'R');

  int32_t id;
  std::string name;
  bool hidden;

  static layr read(const void*& data, size_t& size);
};

}  // namespace vox
