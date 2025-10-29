// SPDX-License-Identifier: GPL-3.0-only

#include "nearest_integer.hpp"

#include <xmipp4/core/platform/builtin.h>

#include <cmath>

namespace xmipp4
{
namespace math
{

namespace detail
{

inline float trunc(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(truncf)
    return XMIPP4_BUILTIN(truncf)(x);
#else
    return truncf(x);
#endif
}

inline double trunc(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(trunc)
    return XMIPP4_BUILTIN(trunc)(x);
#else
    return ::trunc(x);
#endif
}

inline long double trunc(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(truncl)
    return XMIPP4_BUILTIN(truncl)(x);
#else
    return truncl(x);
#endif
}

} // namespace detail

template <typename F>
inline
F trunc(F x) noexcept
{
    return detail::trunc(x);
}





namespace detail
{

inline float floor(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(floorf)
    return XMIPP4_BUILTIN(floorf)(x);
#else
    return floorf(x);
#endif
}

inline double floor(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(floor)
    return XMIPP4_BUILTIN(floor)(x);
#else
    return ::floor(x);
#endif
}

inline long double floor(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(floorl)
    return XMIPP4_BUILTIN(floorl)(x);
#else
    return floorl(x);
#endif
}

} // namespace detail

template <typename F>
inline
F floor(F x) noexcept
{
    return detail::floor(x);
}





namespace detail
{

inline float ceil(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(ceilf)
    return XMIPP4_BUILTIN(ceilf)(x);
#else
    return ceilf(x);
#endif
}

inline double ceil(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(ceil)
    return XMIPP4_BUILTIN(ceil)(x);
#else
    return ::ceil(x);
#endif
}

inline long double ceil(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(ceill)
    return XMIPP4_BUILTIN(ceill)(x);
#else
    return ceill(x);
#endif
}

} // namespace detail

template <typename F>
inline
F ceil(F x) noexcept
{
    return detail::ceil(x);
}





namespace detail
{

inline float round(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(roundf)
    return XMIPP4_BUILTIN(roundf)(x);
#else
    return roundf(x);
#endif
}

inline double round(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(round)
    return XMIPP4_BUILTIN(round)(x);
#else
    return ::round(x);
#endif
}

inline long double round(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(roundl)
    return XMIPP4_BUILTIN(roundl)(x);
#else
    return roundl(x);
#endif
}

} // namespace detail

template <typename F>
inline
F round(F x) noexcept
{
    return detail::round(x);
}

} // namespace math
} // namespace xmipp4
