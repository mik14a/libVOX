#include "chunk.h"

namespace vox {

/**
 * Pack chunk
 */
struct pack : public chunk {
  static constexpr uint32_t tag = generate_id('P', 'A', 'C', 'K');

  int32_t models;

  static pack read(const void*& data, size_t& size);
};

}  // namespace vox
