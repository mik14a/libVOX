#pragma once

#include "node.h"

#include <string>
#include <unordered_map>

namespace vox {

/**
 * Group Node Chunk
 */
struct group : node {
  static constexpr uint32_t tag = generate_id('n', 'G', 'R', 'P');

  std::vector<int32_t> child;

  static group* read(const void*& data, size_t& size);
};

}  // namespace vox
