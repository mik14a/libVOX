#pragma once

#include "chunk.h"
#include "tag.h"

#include <cstdint>
#include <string>
#include <unordered_map>

namespace vox {

inline std::string read_string(const void*& data, size_t& size) {
  auto bytes = read_t<int32_t>(data, size);
  std::string string((const char*)data, bytes);
  data = (char*)data + bytes;
  size -= bytes;
  return string;
}

inline std::unordered_map<std::string, std::string> read_dictionary(
    const void*& data, size_t& size) {
  std::unordered_map<std::string, std::string> dictionary;
  auto num = read_t<int32_t>(data, size);
  for (auto i = 0; i < num; ++i) {
    auto key = read_string(data, size);
    auto value = read_string(data, size);
    dictionary.emplace(std::move(key), std::move(value));
  }
  return dictionary;
}

/**
 * Node structure
 */
struct node : chunk {
  int32_t id;
  std::unordered_map<std::string, std::string> attribute;
};

}  // namespace vox
