#include "node/group.h"

namespace vox {

group* group::read(const void*& data, size_t& size) {
  auto* ngrp = new vox::group();
  auto id = read_t<uint32_t>(data, size);
  if (vox::group::tag != id) return ngrp;

  ngrp->content = read_t<int32_t>(data, size);
  ngrp->children = read_t<int32_t>(data, size);
  ngrp->id = read_t<int32_t>(data, size);
  auto attribute = read_dictionary(data, size);
  auto children = read_t<int32_t>(data, size);
  for (auto i = 0; i < children; ++i) {
    auto child = read_t<int32_t>(data, size);
    ngrp->child.push_back(child);
  }
  return ngrp;
}

}  // namespace vox
