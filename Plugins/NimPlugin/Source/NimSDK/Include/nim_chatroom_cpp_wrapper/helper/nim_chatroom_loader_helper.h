/**
 * @file nim_chatroom_loader_helper.h
 * @brief 聊天室相关工具
 * @date 2021-04-06
 * @copyright Copyright (c) 2021
 */
#ifndef _NIM_SDK_CPP_NIM_CHATROOM_SDK_LOADER_HELPER_H_
#define _NIM_SDK_CPP_NIM_CHATROOM_SDK_LOADER_HELPER_H_

#include "nim_wrapper_util/callback_proxy.h"
#include "nim_wrapper_util/nim_json_util.h"
#include "nim_wrapper_util/nim_sdk_util.h"
#include "nim_wrapper_util/nim_string_util.h"

#ifndef DEF_UNDER_NO_NAMESPACE
namespace nim_chatroom {
#endif  // DEF_UNDER_NO_NAMESPACE

#include "nim_chatroom_def_include.h"

#ifndef DEF_UNDER_NO_NAMESPACE
}
#endif  // DEF_UNDER_NO_NAMESPACE

namespace nim_chatroom {
extern nim::SDKInstance* nim_chatroom_sdk_instance;
}
#ifdef NIM_SDK_DLL_IMPORT
#define NIM_CHATROOM_SDK_GET_FUNC(function_ptr) NIM_SDK_GET_FUNC_FROM_INSTANCE(nim_chatroom_sdk_instance, function_ptr)
#else
#define NIM_CHATROOM_SDK_GET_FUNC(function_ptr) function_ptr
#endif
#endif  // _NIM_SDK_CPP_NIM_CHATROOM_SDK_LOADER_HELPER_H_
