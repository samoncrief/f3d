/**
 * @namespace   types
 * @brief   Namespace containing types used in the libf3d API
 */

#ifndef f3d_types_h
#define f3d_types_h

#include <array>

namespace f3d
{
/**
 * Describe a 3D point
 */
struct point3_t : std::array<double, 3>
{
  template<typename... Args>
  point3_t(Args&&... args)
    : array({ double(std::forward<Args>(args))... })
  {
  }
};

/**
 * Describe a 3D vector
 */
struct vector3_t : std::array<double, 3>
{
  template<typename... Args>
  vector3_t(Args&&... args)
    : array({ double(std::forward<Args>(args))... })
  {
  }
};

/**
 * Describe a 4x4 matrix
 */
struct matrix4_t : std::array<double, 16>
{
  template<typename... Args>
  matrix4_t(Args&&... args)
    : array({ double(std::forward<Args>(args))... })
  {
  }
};

/**
 * Describe an angle in degrees
 */
using angle_deg_t = double;
}

#endif