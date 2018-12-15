#include "node/transform.h"

namespace vox {

transform* transform::read(const void*& data, size_t& size) {
  auto id = read_t<uint32_t>(data, size);
  auto* ntrn = new vox::transform();
  ntrn->content = read_t<int32_t>(data, size);
  ntrn->children = read_t<int32_t>(data, size);
  ntrn->id = read_t<int32_t>(data, size);
  auto attribute = read_dictionary(data, size);
  auto name = attribute.find("_name");
  ntrn->name = name != attribute.end() ? name->second : std::string();
  auto hidden = attribute.find("_hidden");
  ntrn->hidden = hidden != attribute.end() ? std::stoi(hidden->second) : false;
  ntrn->child = read_t<int32_t>(data, size);
  read_t<int32_t>(data, size);  // reserved
  ntrn->layer = read_t<int32_t>(data, size);
  auto frames = read_t<int32_t>(data, size);
  for (auto i = 0; i < frames; ++i) {
    auto frame = read_dictionary(data, size);
    ntrn->frame.push_back(std::move(frame));
  }
  return ntrn;
}

}  // namespace vox
