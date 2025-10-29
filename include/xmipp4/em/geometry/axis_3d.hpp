// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <xmipp4/core/platform/constexpr.hpp>
#include <xmipp4/core/platform/attributes.hpp>

#include <string_view>
#include <ostream>

namespace xmipp4 
{
namespace geometry
{

/**
 * @brief Enumeration representing canonical 3D unit axes.
 * Additionally, zero is also represented for compatibility
 * with some operations.  
 * 
 */
enum class axis_3d
{
    zero = 0,
    x = 1,
    y = 2,
    z = 3,
    negative_x = -x,
    negative_y = -y,
    negative_z = -z,
};

/**
 * @brief Obtain the negative axis.
 * 
 * @param axis Input axis
 * @return axis_3d Axis contrary to the input axis 
 */
XMIPP4_CONSTEXPR axis_3d operator-(axis_3d axis) noexcept;

/**
 * @brief Determine if the axis is strictly positive.
 * @note Zero is not considered as positive.
 * 
 * @param axis Input axis
 * @return bool True if axis is strictly positive. False otherwise 
 */
XMIPP4_CONSTEXPR bool is_negative(axis_3d axis) noexcept;

/**
 * @brief Determine if the axis is strictly negative.
 * @note Zero is not considered as negative.
 * 
 * @param axis Input axis
 * @return bool True if axis is strictly negative. False otherwise 
 */
XMIPP4_CONSTEXPR bool is_positive(axis_3d axis) noexcept;

/**
 * @brief Get the next axis in succession.
 * 
 * For positive axes, this leads to the following succession:
 * +x -> +y -> +z -> +x ...
 * For negative axes, this leads to the following succession:
 * -x -> -z -> -y -> -x ...
 * Zero will lead to also zero:
 * zero -> zero ...
 * 
 * @param axis Input axis
 * @return axis_3d The next axis 
 */
XMIPP4_NODISCARD XMIPP4_CONSTEXPR axis_3d next_axis(axis_3d axis) noexcept;

/**
 * @brief Computes the dot product of a given pair of axes.
 * 
 * When two unitary axes are equal their dot product will be 1.
 * If those axes are opposite to one another, the dot product
 * will be -1. If any of the axes are zero or orthogonal, the
 * dot product will be 0
 * 
 * @param left Left hand side operand
 * @param right Right hand side operand
 * @return int Dot product between left and right.
 * @see https://en.wikipedia.org/wiki/Dot_product
 */
XMIPP4_CONSTEXPR int dot(axis_3d left, axis_3d right) noexcept;

/**
 * @brief Computes the cross product of a given pair of axes
 * 
 * @param left Left hand side operand
 * @param right Right hand side operand
 * @return axis_3d Cross product between left and right
 * @see https://en.wikipedia.org/wiki/Cross_product
 */
XMIPP4_CONSTEXPR axis_3d cross(axis_3d left, axis_3d right) noexcept;

XMIPP4_CONSTEXPR const char* to_string(axis_3d axis) noexcept;
bool from_string(std::string_view str, axis_3d& axis) noexcept;

template<typename T>
std::basic_ostream<T>& operator<<(std::basic_ostream<T>& os, axis_3d axis);

} // namespace geometry
} // namespace xmipp4

#include "axis_3d.inl"
