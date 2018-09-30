
#pragma once

#include "chunk/rgba.h"
#include "chunk/size.h"
#include "chunk/xyzi.h"
#include "chunk/layr.h"
#include "libvox.h"

#include <iostream>
#include <unordered_map>
#include <vector>

namespace vox {

/**
 * Vox file format
 */
struct vox {
  static constexpr uint32_t tag = generate_id('V', 'O', 'X', ' ');

  int32_t version;
  std::vector<size> size;
  std::vector<xyzi> voxel;
  rgba palette;
  std::unordered_map<int32_t, layr> layer;

  static const uint32_t default_palette[256];
  static vox read(const void*& data, size_t& size);
};

}  // namespace vox