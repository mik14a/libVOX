#pragma once

#include <cstdint>

namespace vox {

struct vox;

/**
 * Read vox format
 */
vox read(const void* data, size_t size);

}  // namespace vox
