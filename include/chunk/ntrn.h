#pragma once

#include "node.h"

#include <unordered_map>
#include <string>

namespace vox {

/**
 * Transform Node Chunk 
 */
struct ntrn : node {
  static constexpr uint32_t tag = generate_id('n', 'T', 'R', 'N');

  int32_t child;
  int32_t layer; 
  std::vector<std::unordered_map<std::string, std::string>> frame;

  static ntrn read(const void*& data, size_t& size);
};

}  // namespace vox
