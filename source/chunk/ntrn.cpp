#include "chunk/ntrn.h"

namespace vox {

ntrn ntrn::read(const void*& data, size_t& size) {
  auto id = read_t<uint32_t>(data, size);
  ntrn ntrn;
  ntrn.content = read_t<int32_t>(data, size);
  ntrn.children = read_t<int32_t>(data, size);
  ntrn.node::id = read_t<int32_t>(data, size);
  ntrn.attribute = read_dictionary(data, size);
  ntrn.child = read_t<int32_t>(data, size);
  read_t<int32_t>(data, size);  // reserved
  ntrn.layer = read_t<int32_t>(data, size);
  auto frames = read_t<int32_t>(data, size);
  for (auto i = 0; i < frames; ++i) {
    auto frame = read_dictionary(data, size);
    ntrn.frame.push_back(std::move(frame));
  }
  return ntrn;
}

}  // namespace vox
