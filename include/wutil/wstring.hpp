#pragma once
#include "wutil/wbuild.hpp"

#ifndef __cplusplus
extern "C" {
#endif

typedef struct _wutil_string_utf8_t {
  char8_t* str;
  size_t length;
  void (*dtor)(char8_t*);
} wutil_string_utf8_t;

WUTIL_EXPORT int wutil_string_utf8_set(const char*,
                                       size_t length,
                                       wutil_string_utf8_t*,
                                       int copy);

#ifndef __cplusplus
}
#endif