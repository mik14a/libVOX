
#pragma once

#include "libvox.h"

#include "chunk/layr.h"
#include "chunk/rgba.h"
#include "chunk/size.h"
#include "chunk/xyzi.h"
#include "node/group.h"
#include "node/shape.h"
#include "node/transform.h"

#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

namespace vox {

/**
 * Vox file format
 */
struct vox {
  static constexpr uint32_t tag = generate_id('V', 'O', 'X', ' ');
  using node_t = std::unordered_map<int32_t, std::shared_ptr<node>>;
  using layer_t = std::unordered_map<int32_t, layr>;

  int32_t version;
  std::vector<size> size;
  std::vector<xyzi> voxel;
  rgba palette;
  node_t node;
  layer_t layer;

  static const uint32_t default_palette[256];
  static vox read(const void*& data, size_t& size);
};

}  // namespace vox
