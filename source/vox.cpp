#include "vox.h"
#include "chunk/layr.h"
#include "chunk/main.h"
#include "chunk/matl.h"
#include "chunk/matt.h"
#include "chunk/pack.h"
#include "chunk/rgba.h"
#include "chunk/size.h"
#include "chunk/xyzi.h"
#include "node/group.h"
#include "node/shape.h"
#include "node/transform.h"

#include <iostream>
#include <memory>

namespace vox {

vox vox::read(const void*& data, size_t& size) {
  vox vox;
  vox.version = 150;
  auto main = main::read(data, size);
  while (0 < size) {
    auto id = peek_t<uint32_t>(data);
    switch (id) {
    case pack::tag: {
      auto pack = pack::read(data, size);
    } break;
    case size::tag: {
      vox.size.push_back(size::read(data, size));
    } break;
    case xyzi::tag: {
      vox.voxel.push_back(xyzi::read(data, size));
    } break;
    case rgba::tag: {
      vox.palette = rgba::read(data, size);
    } break;
    case matl::tag: {
      auto matl = matl::read(data, size);
      vox.material.emplace(matl.id, std::move(matl));
    } break;
    case layr::tag: {
      auto layr = layr::read(data, size);
      vox.layer.emplace(layr.id, std::move(layr));
    } break;
    case transform::tag: {
      auto transform =
          std::shared_ptr<::vox::node>(transform::read(data, size));
      vox.node.emplace(transform->id, transform);
    } break;
    case group::tag: {
      auto group = std::shared_ptr<::vox::group>(group::read(data, size));
      vox.node.emplace(group->id, group);
    } break;
    case shape::tag: {
      auto shape = std::shared_ptr<::vox::shape>(shape::read(data, size));
      vox.node.emplace(shape->id, shape);
    } break;
    default: {
      id = read_t<uint32_t>(data, size);
      auto content = read_t<int32_t>(data, size);
#if __has_cpp_attribute(maybe_unused)
      [[maybe_unused]]
#endif
      auto children = read_t<int32_t>(data, size);
#if __has_cpp_attribute(maybe_unused)
#else
      (void)children;
#endif
      data = (char*)data + content;
      size -= content;
    } break;
    }
  }
  return vox;
}

// clang-format off
const uint32_t vox::default_palette[256] = {
  0xffffffff, 0xffffffcc, 0xffffff99, 0xffffff66, 0xffffff33, 0xffffff00, 0xffffccff, 0xffffcccc, 0xffffcc99, 0xffffcc66, 0xffffcc33, 0xffffcc00, 0xffff99ff, 0xffff99cc, 0xffff9999, 0xffff9966,
  0xffff9933, 0xffff9900, 0xffff66ff, 0xffff66cc, 0xffff6699, 0xffff6666, 0xffff6633, 0xffff6600, 0xffff33ff, 0xffff33cc, 0xffff3399, 0xffff3366, 0xffff3333, 0xffff3300, 0xffff00ff, 0xffff00cc,
  0xffff0099, 0xffff0066, 0xffff0033, 0xffff0000, 0xffccffff, 0xffccffcc, 0xffccff99, 0xffccff66, 0xffccff33, 0xffccff00, 0xffccccff, 0xffcccccc, 0xffcccc99, 0xffcccc66, 0xffcccc33, 0xffcccc00,
  0xffcc99ff, 0xffcc99cc, 0xffcc9999, 0xffcc9966, 0xffcc9933, 0xffcc9900, 0xffcc66ff, 0xffcc66cc, 0xffcc6699, 0xffcc6666, 0xffcc6633, 0xffcc6600, 0xffcc33ff, 0xffcc33cc, 0xffcc3399, 0xffcc3366,
  0xffcc3333, 0xffcc3300, 0xffcc00ff, 0xffcc00cc, 0xffcc0099, 0xffcc0066, 0xffcc0033, 0xffcc0000, 0xff99ffff, 0xff99ffcc, 0xff99ff99, 0xff99ff66, 0xff99ff33, 0xff99ff00, 0xff99ccff, 0xff99cccc,
  0xff99cc99, 0xff99cc66, 0xff99cc33, 0xff99cc00, 0xff9999ff, 0xff9999cc, 0xff999999, 0xff999966, 0xff999933, 0xff999900, 0xff9966ff, 0xff9966cc, 0xff996699, 0xff996666, 0xff996633, 0xff996600,
  0xff9933ff, 0xff9933cc, 0xff993399, 0xff993366, 0xff993333, 0xff993300, 0xff9900ff, 0xff9900cc, 0xff990099, 0xff990066, 0xff990033, 0xff990000, 0xff66ffff, 0xff66ffcc, 0xff66ff99, 0xff66ff66,
  0xff66ff33, 0xff66ff00, 0xff66ccff, 0xff66cccc, 0xff66cc99, 0xff66cc66, 0xff66cc33, 0xff66cc00, 0xff6699ff, 0xff6699cc, 0xff669999, 0xff669966, 0xff669933, 0xff669900, 0xff6666ff, 0xff6666cc,
  0xff666699, 0xff666666, 0xff666633, 0xff666600, 0xff6633ff, 0xff6633cc, 0xff663399, 0xff663366, 0xff663333, 0xff663300, 0xff6600ff, 0xff6600cc, 0xff660099, 0xff660066, 0xff660033, 0xff660000,
  0xff33ffff, 0xff33ffcc, 0xff33ff99, 0xff33ff66, 0xff33ff33, 0xff33ff00, 0xff33ccff, 0xff33cccc, 0xff33cc99, 0xff33cc66, 0xff33cc33, 0xff33cc00, 0xff3399ff, 0xff3399cc, 0xff339999, 0xff339966,
  0xff339933, 0xff339900, 0xff3366ff, 0xff3366cc, 0xff336699, 0xff336666, 0xff336633, 0xff336600, 0xff3333ff, 0xff3333cc, 0xff333399, 0xff333366, 0xff333333, 0xff333300, 0xff3300ff, 0xff3300cc,
  0xff330099, 0xff330066, 0xff330033, 0xff330000, 0xff00ffff, 0xff00ffcc, 0xff00ff99, 0xff00ff66, 0xff00ff33, 0xff00ff00, 0xff00ccff, 0xff00cccc, 0xff00cc99, 0xff00cc66, 0xff00cc33, 0xff00cc00,
  0xff0099ff, 0xff0099cc, 0xff009999, 0xff009966, 0xff009933, 0xff009900, 0xff0066ff, 0xff0066cc, 0xff006699, 0xff006666, 0xff006633, 0xff006600, 0xff0033ff, 0xff0033cc, 0xff003399, 0xff003366,
  0xff003333, 0xff003300, 0xff0000ff, 0xff0000cc, 0xff000099, 0xff000066, 0xff000033, 0xffee0000, 0xffdd0000, 0xffbb0000, 0xffaa0000, 0xff880000, 0xff770000, 0xff550000, 0xff440000, 0xff220000,
  0xff110000, 0xff00ee00, 0xff00dd00, 0xff00bb00, 0xff00aa00, 0xff008800, 0xff007700, 0xff005500, 0xff004400, 0xff002200, 0xff001100, 0xff0000ee, 0xff0000dd, 0xff0000bb, 0xff0000aa, 0xff000088,
  0xff000077, 0xff000055, 0xff000044, 0xff000022, 0xff000011, 0xffeeeeee, 0xffdddddd, 0xffbbbbbb, 0xffaaaaaa, 0xff888888, 0xff777777, 0xff555555, 0xff444444, 0xff222222, 0xff111111, 0xff000000
};
// clang-format on

}  // namespace vox
