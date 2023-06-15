#pragma once

#if defined(__ANDROID__)
#define WUTIL_OS_ANDROID 1
#elif defined(__linux__)
#define WUTIL_OS_LINUX 1
#elif defined(_WIN32)
#define WUTIL_OS_WINDOWS 1
#else
#error
#endif

#if defined(__GNUC__)
#define WUTIL_COMPILER_GCC 1
#elif defined(_MSC_VER)
#define WUTIL_COMPILER_MSVC 1
#else
#error
#endif

#if defined(WUTIL_COMPILER_MSVC)
#define WUTIL_EXPORT_INTERFACE __declspec(dllexport)
#define WUTIL_IMPORT_INTERFACE __declspec(dllimport)
#elif defined(WUTIL_COMPILER_GCC)
#define WUTIL_EXPORT_INTERFACE __attribute__((visibility("default")))
#define WUTIL_IMPORT_INTERFACE __attribute__((visibility("default")))
#endif

#if defined(WUTIL_SHARED_BUILDING)
#define WUTIL_EXPORT WUTIL_EXPORT_INTERFACE
#elif defined(WUTIL_SHARED)
#define WUTIL_EXPORT WUTIL_IMPORT_INTERFACE
#else
#define WUTIL_EXPORT
#endif

#if defined(WUTIL_OS_WINDOWS)
#define WUTIL_CALLBACK __stdcall
#else
#define WUTIL_CALLBACK
#endif