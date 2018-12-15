#pragma once

#include "node.h"

#include <string>
#include <unordered_map>

namespace vox {

/**
 * Transform Node Chunk
 */
struct transform : node {
  static constexpr uint32_t tag = generate_id('n', 'T', 'R', 'N');

  std::string name;
  bool hidden;
  int32_t child;
  int32_t layer;
  std::vector<std::unordered_map<std::string, std::string>> frame;

  transform() { node::tag = tag; }
  static transform* read(const void*& data, size_t& size);
};

}  // namespace vox
