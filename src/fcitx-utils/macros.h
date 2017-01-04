/*
 * Copyright (C) 2015~2015 by CSSlayer
 * wengxt@gmail.com
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; see the file COPYING. If not,
 * see <http://www.gnu.org/licenses/>.
 */
#ifndef _FCITX_UTILS_MACROS_H_
#define _FCITX_UTILS_MACROS_H_

// steal some Qt macro here

#define FCITX_DECLARE_PUBLIC(Class)                                                                                    \
    inline Class *q_func() { return static_cast<Class *>(q_ptr); }                                                     \
    inline const Class *q_func() const { return static_cast<const Class *>(q_ptr); }                                   \
    friend class Class;

#define FCITX_DECLARE_PRIVATE(Class)                                                                                   \
    inline Class##Private *d_func() { return reinterpret_cast<Class##Private *>(d_ptr.get()); }                        \
    inline const Class##Private *d_func() const { return reinterpret_cast<Class##Private *>(d_ptr.get()); }            \
    friend class Class##Private;

#define FCITX_D() auto *const d = d_func()
#define FCITX_Q() auto *const q = q_func()

#define FCITX_UNUSED(X) ((void)(X))

#ifdef __cplusplus
#define FCITX_C_DECL_BEGIN extern "C" {
#define FCITX_C_DECL_END }
#else
#define FCITX_C_DECL_BEGIN
#define FCITX_C_DECL_END
#endif

#define FCITX_ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#ifdef __GNUC__
#define _FCITX_UNUSED_ __attribute__((__unused__))
#else
#define _FCITX_UNUSED_
#endif

#define FCITX_WHITE_SPACE "\f\n\r\t\v "

#define FCITX_EXPAND(x) x

#define FCITX_FOR_EACH_0(...)
#define FCITX_FOR_EACH_1(what, x, ...) what(x)
#define FCITX_FOR_EACH_2(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_1(what, __VA_ARGS__))
#define FCITX_FOR_EACH_3(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_2(what, __VA_ARGS__))
#define FCITX_FOR_EACH_4(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_3(what, __VA_ARGS__))
#define FCITX_FOR_EACH_5(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_4(what, __VA_ARGS__))
#define FCITX_FOR_EACH_6(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_5(what, __VA_ARGS__))
#define FCITX_FOR_EACH_7(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_6(what, __VA_ARGS__))
#define FCITX_FOR_EACH_8(what, x, ...) what(x) FCITX_EXPAND(FCITX_FOR_EACH_7(what, __VA_ARGS__))

#define FCITX_FOR_EACH_IDX_0(...)
#define FCITX_FOR_EACH_IDX_1(what, x, ...) what(1, x)
#define FCITX_FOR_EACH_IDX_2(what, x, ...) what(2, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_1(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX_3(what, x, ...) what(3, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_2(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX_4(what, x, ...) what(4, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_3(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX_5(what, x, ...) what(5, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_4(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX_6(what, x, ...) what(6, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_5(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX_7(what, x, ...) what(7, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_6(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX_8(what, x, ...) what(8, x) FCITX_EXPAND(FCITX_FOR_EACH_IDX_7(what, __VA_ARGS__))

#define FCITX_GET_ARG9(_1, _2, _3, _4, _5, _6, _7, _8, N, ...) N

#define FCITX_HAS_COMMA(...) FCITX_GET_ARG9(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 0)

#define FCITX_TRIGGER_PARENTHESIS_(...) ,

#define FCITX_IS_EMPTY(...)                                                                                            \
    FCITX_IS_EMPTY_(FCITX_HAS_COMMA(__VA_ARGS__), FCITX_HAS_COMMA(FCITX_TRIGGER_PARENTHESIS_ __VA_ARGS__),             \
                    FCITX_HAS_COMMA(__VA_ARGS__()), FCITX_HAS_COMMA(FCITX_TRIGGER_PARENTHESIS_ __VA_ARGS__()))

#define FCITX_PASTE5_(_0, _1, _2, _3, _4) _0##_1##_2##_3##_4

#define FCITX_IS_EMPTY_(_0, _1, _2, _3) FCITX_HAS_COMMA(FCITX_PASTE5_(FCITX_IS_EMPTY_CASE_, _0, _1, _2, _3))

#define FCITX_IS_EMPTY_CASE_0001 ,

#define FCITX_EMPTY_1(X) 0
#define FCITX_EMPTY_0(X) X

#define FCITX_NARG(...) FCITX_NARG_HELPER_(FCITX_IS_EMPTY(__VA_ARGS__), FCITX_NARG_(__VA_ARGS__))
#define FCITX_NARG_HELPER_(B, VAL) FCITX_NARG_HELPER__(FCITX_CONCATENATE(FCITX_EMPTY_, B), VAL)
#define FCITX_NARG_HELPER__(B, VAL) B(VAL)

#define FCITX_NARG_(...) FCITX_NARG__(__VA_ARGS__, FCITX_RSEQ8())
#define FCITX_NARG__(...) FCITX_EXPAND(FCITX_GET_ARG9(__VA_ARGS__))
#define FCITX_RSEQ8() 8, 7, 6, 5, 4, 3, 2, 1, 0
#define FCITX_CONCATENATE(x, y) x##y
#define FCITX_FOR_EACH_(N, what, ...) FCITX_EXPAND(FCITX_CONCATENATE(FCITX_FOR_EACH_, N)(what, __VA_ARGS__))
#define FCITX_FOR_EACH(what, ...) FCITX_FOR_EACH_(FCITX_NARG(__VA_ARGS__), what, __VA_ARGS__)

#define FCITX_FOR_EACH_IDX_(N, what, ...) FCITX_EXPAND(FCITX_CONCATENATE(FCITX_FOR_EACH_IDX_, N)(what, __VA_ARGS__))
#define FCITX_FOR_EACH_IDX(what, ...) FCITX_FOR_EACH_IDX_(FCITX_NARG(__VA_ARGS__), what, __VA_ARGS__)

#define FCITX_XSTRINGIFY(...) #__VA_ARGS__
#define FCITX_STRINGIFY(...) FCITX_XSTRINGIFY(__VA_ARGS__)
#define FCITX_RETURN_IF(EXPR, VALUE)                                                                                   \
    if ((EXPR)) {                                                                                                      \
        return (VALUE);                                                                                                \
    }

#endif // _FCITX_UTILS_MACROS_H_

