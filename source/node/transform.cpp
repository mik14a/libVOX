#include "node/transform.h"

#include <sstream>

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
  for (auto f = 0; f < frames; ++f) {
    auto dictionary = read_dictionary(data, size);
    auto frame = frame_t::value_type();
    auto r = dictionary.find("_r");
    if (r != dictionary.end()) {
      const auto m = std::stoi(r->second.c_str());
      const auto first = static_cast<int>((m >> 0) & 0x03);
      const auto second = static_cast<int>((m >> 2) & 0x03);
      const auto third = 0x03 ^ (first | second);
      const int sign[] = {
          static_cast<int>((m >> 4) & 0x01),
          static_cast<int>((m >> 5) & 0x01),
          static_cast<int>((m >> 6) & 0x01),
      };
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          frame.rotation.m[i][j] = 0;
        }
      }
      frame.rotation.m[0][first] = sign[0] ? -1 : 1;
      frame.rotation.m[1][second] = sign[1] ? -1 : 1;
      frame.rotation.m[2][third] = sign[2] ? -1 : 1;
    }
    auto t = dictionary.find("_t");
    if (t != dictionary.end()) {
      auto stream = std::stringstream(t->second);
      stream >> frame.translation.x >> frame.translation.y >>
          frame.translation.z;
    }
    ntrn->frame.push_back(std::move(frame));
  }
  return ntrn;
}

}  // namespace vox
