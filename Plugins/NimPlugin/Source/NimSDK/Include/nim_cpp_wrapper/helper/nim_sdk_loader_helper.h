/**
 * @file nim_sdk_loader_helper.h
 * @brief 加载 NIM SDK 的帮助类头文件
 * @version 0.1
 * @date 2021-04-17
 *
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 *
 */
#ifndef _NIM_SDK_CPP_NIM_SDK_LOADER_HELPER_H_
#define _NIM_SDK_CPP_NIM_SDK_LOADER_HELPER_H_

#include "nim_wrapper_util/callback_proxy.h"
#include "nim_wrapper_util/nim_json_util.h"
#include "nim_wrapper_util/nim_sdk_util.h"
#include "nim_wrapper_util/nim_string_util.h"

namespace nim {
extern nim::SDKInstance* nim_sdk_instance;
}
#ifdef NIM_SDK_DLL_IMPORT
#define NIM_SDK_GET_FUNC(function_ptr) NIM_SDK_GET_FUNC_FROM_INSTANCE(nim_sdk_instance, function_ptr)
#else
#define NIM_SDK_GET_FUNC(function_ptr) function_ptr
#endif
#endif  // _NIM_SDK_CPP_NIM_SDK_LOADER_HELPER_H_
