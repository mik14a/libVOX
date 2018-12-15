#pragma once

#include "chunk/chunk.h"
#include "tag.h"

#include <cstdint>
#include <string>
#include <unordered_map>

namespace vox {

using dictionary_t = std::unordered_map<std::string, std::string>;

inline std::string read_string(const void*& data, size_t& size) {
  auto bytes = read_t<int32_t>(data, size);
  std::string string((const char*)data, bytes);
  data = (char*)data + bytes;
  size -= bytes;
  return string;
}

inline dictionary_t read_dictionary(const void*& data, size_t& size) {
  dictionary_t dictionary;
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
};

}  // namespace vox
