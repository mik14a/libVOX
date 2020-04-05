#include "node/shape.h"

namespace vox {

shape* shape::read(const void*& data, size_t& size) {
  auto* nshp = new ::vox::shape();
  auto id = read_t<uint32_t>(data, size);
  if (vox::shape::tag != id) return nshp;

  nshp->content = read_t<int32_t>(data, size);
  nshp->children = read_t<int32_t>(data, size);
  nshp->id = read_t<int32_t>(data, size);
  auto attribute = read_dictionary(data, size);
  auto models = read_t<int32_t>(data, size);
  for (auto i = 0; i < models; ++i) {
    auto model = model_t::value_type();
    model.id = read_t<int32_t>(data, size);
    model.attributes = read_dictionary(data, size);
    nshp->model.push_back(std::move(model));
  }
  return nshp;
}

}  // namespace vox
