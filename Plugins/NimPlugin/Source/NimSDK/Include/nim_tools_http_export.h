/**
 * @file nim_tools_http_export.h
 * @brief NIM HTTP TOOLS 导出头文件预定义宏
 * @date 2021-04-25
 * @copyright Copyright (c) 2021
 *
 */

#ifndef NIM_TOOLS_HTTP_EXPORT_H_
#define NIM_TOOLS_HTTP_EXPORT_H_

#if defined(NIM_TOOLS_HTTP_IMPLEMENTATION)
#if defined(WIN32)
#define NIM_TOOLS_HTTP_EXPORT __declspec(dllexport)
#else
#define NIM_TOOLS_HTTP_EXPORT __attribute__((visibility("default")))
#endif  // WIN32
#else
#if defined(WIN32)
#define NIM_TOOLS_HTTP_EXPORT __declspec(dllimport)
#else
#define NIM_TOOLS_HTTP_EXPORT __attribute__((visibility("default")))
#endif WIN32
#endif  // NIM_TOOLS_HTTP_IMPLEMENTATION

#endif  // NIM_TOOLS_HTTP_EXPORT_H_
