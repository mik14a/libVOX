#pragma once

#include "node.h"

#include <string>
#include <unordered_map>

namespace vox {

/**
 * Transform Node Chunk
 */
struct transform : node {
  struct frame {
    struct {
      int8_t m[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    } rotation;
    struct {
      int32_t x = 0, y = 0, z = 0;
    } translation;
  };

  static constexpr uint32_t tag = generate_id('n', 'T', 'R', 'N');
  using frame_t = std::vector<transform::frame>;

  std::string name;
  bool hidden;
  int32_t child;
  int32_t layer;
  frame_t frame;

  transform() { node::tag = tag; }
  static transform* read(const void*& data, size_t& size);
};

}  // namespace vox
