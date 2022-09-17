/** @file nim_qchat_helper.h
 * @brief 圈组CPP wrapper helpers
 * @date 2021-12-29
 * @copyright Copyright (c) 2021
 */
#ifndef _NIM_SDK_CPP_NIM_QCHAT_SDK_LOADER_HELPER_H_
#define _NIM_SDK_CPP_NIM_QCHAT_SDK_LOADER_HELPER_H_

#include "nim_wrapper_util/nim_sdk_util.h"

namespace nim_qchat {
extern nim::SDKInstance* nim_qchat_sdk_instance;
}  // namespace nim_qchat

template <typename C, typename R>
static void InvokeCallback(const R& response) {
    if (response.user_data != nullptr) {
        auto cb = reinterpret_cast<C*>(response.user_data);
        if (cb) {
            if (*cb) {
                (*cb)(response);
            }
            delete cb;
        }
    }
}

// template <typename C, typename R>
// static void InvokeCallback(const R* response) {
//     if (response != nullptr && response->user_data != nullptr) {
//         auto cb = reinterpret_cast<C*>(response->user_data);
//         if (cb) {
//             (*cb)(*response);
//             delete cb;
//         }
//     }
// }

#ifdef NIM_SDK_DLL_IMPORT
#define NIM_QCHAT_SDK_GET_FUNC(function_ptr) NIM_SDK_GET_FUNC_FROM_INSTANCE(nim_qchat_sdk_instance, function_ptr)
#else
#define NIM_QCHAT_SDK_GET_FUNC(function_ptr) function_ptr
#endif
#endif  // _NIM_SDK_CPP_NIM_QCHAT_SDK_LOADER_HELPER_H_
