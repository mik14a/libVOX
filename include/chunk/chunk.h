#pragma once

#include "tag.h"

#include <cstdint>

namespace vox {

template <typename T>
T peek_t(const void* data) {
  return *(T*)data;
}

template <typename T>
T read_t(const void*& data, size_t& size) {
  T value = peek_t<T>(data);
  data = (T*)data + 1;
  size -= sizeof(T);
  return value;
}

/**
 * Chunk structure
 */
struct chunk {
  int32_t content;
  int32_t children;
};

}  // namespace vox
