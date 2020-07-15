
#pragma once

#include "libvox.h"

#include "chunk/layr.h"
#include "chunk/matl.h"
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
 * @see https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox.txt
 * @see https://github.com/ephtracy/voxel-model/blob/master/MagicaVoxel-file-format-vox-extension.txt
 */
struct vox {
  //! VOX format file tag.
  static constexpr uint32_t tag = generate_id('V', 'O', 'X', ' ');

  using node_t = std::unordered_map<int32_t, std::shared_ptr<node>>;
  using material_t = std::unordered_map<int32_t, matl>;
  using layer_t = std::unordered_map<int32_t, layr>;

  int32_t version;          //!< Vox file version.
  std::vector<size> size;   //!< Model size.
  std::vector<xyzi> voxel;  //!< Model voxels.
  rgba palette;             //!< Palette.

  node_t node;          //!< extension nodes.
  material_t material;  //!< extension materials.
  layer_t layer;        //!< extension layers.

  //! Default palette.
  static const uint32_t default_palette[256];
  //! Create vox format data from memory.
  static vox read(const void*& data, size_t& size);
};

}  // namespace vox
