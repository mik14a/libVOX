#pragma once

#include <cstdint>

namespace vox {

constexpr uint32_t generate_id(char a, char b, char c, char d) {
  return (uint32_t)a | ((uint32_t)b << 8) | ((uint32_t)c << 16) |
         ((uint32_t)d << 24);
}

}  // namespace vox
