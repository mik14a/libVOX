#pragma once

#include "chunk.h"

#include "node/node.h"

namespace vox {

/**
 * Matl chunk
 */
struct matl : public chunk {
  static constexpr uint32_t tag = generate_id('M', 'A', 'T', 'L');

  int32_t id;
  dictionary_t properties;

  static matl read(const void*& data, size_t& size);
};

}  // namespace vox
