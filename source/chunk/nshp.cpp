#include "chunk/nshp.h"

namespace vox {

nshp* nshp::read(const void*& data, size_t& size) {
  auto id = read_t<uint32_t>(data, size);
  auto* nshp = new ::vox::nshp();
  nshp->content = read_t<int32_t>(data, size);
  nshp->children = read_t<int32_t>(data, size);
  nshp->node::id = read_t<int32_t>(data, size);
  nshp->attribute = read_dictionary(data, size);
  auto models = read_t<int32_t>(data, size);
  for (auto i = 0; i < models; ++i) {
    auto id = read_t<int32_t>(data, size);
    auto attributes = read_dictionary(data, size);
    nshp->model.emplace(id, std::move(attributes));
  }
  return nshp;
}

}  // namespace vox
