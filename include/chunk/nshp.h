#pragma once

#include "node.h"

namespace vox {

/**
 * Shape Node Chunk
 */
struct nshp : node {
  static constexpr uint32_t tag = generate_id('n', 'S', 'H', 'P');

  std::unordered_map<std::string, std::string> attribute;
  std::unordered_map<int32_t, std::unordered_map<std::string, std::string>>  model;

  static nshp read(const void*& data, size_t& size);
};

}  // namespace vox
