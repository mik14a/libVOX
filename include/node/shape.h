#pragma once

#include "node.h"

#include <vector>

namespace vox {

/**
 * Shape Node Chunk
 */
struct shape : node {
  static constexpr uint32_t tag = generate_id('n', 'S', 'H', 'P');
  struct model {
    int32_t id;
    dictionary_t attributes;
  };
  using model_t = std::vector<shape::model>;

  model_t model;

  static shape* read(const void*& data, size_t& size);
};

}  // namespace vox
