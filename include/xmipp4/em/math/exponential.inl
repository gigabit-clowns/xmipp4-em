// SPDX-License-Identifier: GPL-3.0-only

#include "exponential.hpp"

#include "power.hpp"
#include <xmipp4/core/platform/builtin.h>

#include <cmath>

namespace xmipp4
{
namespace math
{

namespace detail
{

inline float exp(float exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(expf)
    return XMIPP4_BUILTIN(expf)(exponent);
#else
    return expf(exponent);
#endif
}

inline double exp(double exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(exp)
    return XMIPP4_BUILTIN(exp)(exponent);
#else
    return ::exp(exponent);
#endif
}

inline long double exp(long double exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(expl)
    return XMIPP4_BUILTIN(expl)(exponent);
#else
    return expl(exponent);
#endif
}

} // namespace detail

template <typename F>
inline
F exp(F exponent) noexcept
{
    return detail::exp(exponent);
}





namespace detail
{

inline float exp2(float exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(exp2f)
    return XMIPP4_BUILTIN(exp2f)(exponent);
#else
    return exp2f(exponent);
#endif
}

inline double exp2(double exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(exp2)
    return XMIPP4_BUILTIN(exp2)(exponent);
#else
    return ::exp2(exponent);
#endif
}

inline long double exp2(long double exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(exp2l)
    return XMIPP4_BUILTIN(exp2l)(exponent);
#else
    return exp2l(exponent);
#endif
}

} // namespace detail

template <typename F>
inline
F exp2(F exponent) noexcept
{
    return detail::exp2(exponent);
}





namespace detail
{

template <typename F>
inline
F exp10(F exponent) noexcept
{
    XMIPP4_CONST_CONSTEXPR F base = 10;
    return pow(base, exponent);
}

#if !defined(__APPLE__) //FIXME: Not compiling with conda, undefiend reference to _exp10
#if XMIPP4_HAS_BUILTIN(exp10f)
inline float exp10(float exponent) noexcept
{
    return XMIPP4_BUILTIN(exp10f)(exponent);
}
#endif

#if XMIPP4_HAS_BUILTIN(exp10)
inline double exp10(double exponent) noexcept
{
    return XMIPP4_BUILTIN(exp10)(exponent);
}
#endif

#if XMIPP4_HAS_BUILTIN(exp10l)
inline long double exp10(long double exponent) noexcept
{
    return XMIPP4_BUILTIN(exp10l)(exponent);
}
#endif
#endif

} // namespace detail

template <typename F>
inline
F exp10(F exponent) noexcept
{
    return detail::exp10(exponent);
}





namespace detail
{

inline float expm1(float exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(expm1f)
    return XMIPP4_BUILTIN(expm1f)(exponent);
#else
    return expm1f(exponent);
#endif
}

inline double expm1(double exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(expm1)
    return XMIPP4_BUILTIN(expm1)(exponent);
#else
    return ::expm1(exponent);
#endif
}

inline long double expm1(long double exponent) noexcept
{
#if XMIPP4_HAS_BUILTIN(expm1l)
    return XMIPP4_BUILTIN(expm1l)(exponent);
#else
    return expm1l(exponent);
#endif
}

} // namespace detail

template <typename F>
inline
F expm1(F exponent) noexcept
{
    return detail::expm1(exponent);
}





namespace detail
{

inline float log(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(logf)
    return XMIPP4_BUILTIN(logf)(x);
#else
    return logf(x);
#endif
}

inline double log(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log)
    return XMIPP4_BUILTIN(log)(x);
#else
    return ::log(x);
#endif
}

inline long double log(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(logl)
    return XMIPP4_BUILTIN(logl)(x);
#else
    return logl(x);
#endif
}

} // namespace detail

template <typename F>
inline
F log(F x) noexcept
{
    return detail::log(x);
}





namespace detail
{

inline float log2(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log2f)
    return XMIPP4_BUILTIN(log2f)(x);
#else
    return log2f(x);
#endif
}

inline double log2(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log2)
    return XMIPP4_BUILTIN(log2)(x);
#else
    return ::log2(x);
#endif
}

inline long double log2(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log2l)
    return XMIPP4_BUILTIN(log2l)(x);
#else
    return log2l(x);
#endif
}

} // namespace detail

template <typename F>
inline
F log2(F x) noexcept
{
    return detail::log2(x);
}





namespace detail
{

inline float log10(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log10f)
    return XMIPP4_BUILTIN(log10f)(x);
#else
    return log10f(x);
#endif
}

inline double log10(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log10)
    return XMIPP4_BUILTIN(log10)(x);
#else
    return ::log10(x);
#endif
}

inline long double log10(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log10l)
    return XMIPP4_BUILTIN(log10l)(x);
#else
    return log10l(x);
#endif
}

} // namespace detail

template <typename F>
inline
F log10(F x) noexcept
{
    return detail::log10(x);
}





template <typename F>
inline
F logn(F n, F x) noexcept
{
    return log(x) / log(n);
}





namespace detail
{

inline float log1p(float x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log1pf)
    return XMIPP4_BUILTIN(log1pf)(x);
#else
    return log1pf(x);
#endif
}

inline double log1p(double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log1p)
    return XMIPP4_BUILTIN(log1p)(x);
#else
    return ::log1p(x);
#endif
}

inline long double log1p(long double x) noexcept
{
#if XMIPP4_HAS_BUILTIN(log1pl)
    return XMIPP4_BUILTIN(log1pl)(x);
#else
    return log1pl(x);
#endif
}

} // namespace detail

template <typename F>
inline
F log1p(F x) noexcept
{
    return detail::log1p(x);
}

template <typename F>
inline
F log_add(F log_x, F log_y) noexcept
{
    if (log_x < log_y)
    {
        std::swap(log_x, log_y);
    }

    const auto minus_difference = log_y - log_x; // -(log_x - log_y)
    return log_x + log1p(exp(minus_difference));
}

} // namespace math
} // namespace xmipp4
