/** @file nim_talkex_helper_pin_message.h
 * @brief Talkex Pin Message 辅助方法和数据结构定义
 * @copyright (c) 2015-2020, NetEase Inc. All rights reserved
 * @date 2020/04/20
 */

#ifndef _NIM_SDK_CPP_TALKEX_HELPER_PIN_MESSAGE_H_
#define _NIM_SDK_CPP_TALKEX_HELPER_PIN_MESSAGE_H_

#include <algorithm>
#include <functional>
#include <list>
#include <string>
#include "nim_cpp_wrapper/helper/nim_sdk_loader_helper.h"
#include "nim_cpp_wrapper/helper/nim_talk_helper.h"
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"
#include "nim_define_include.h"
#include "nim_wrapper_util/nim_json_util.h"
/**
 * @namespace nim
 * @brief namespace nim
 */
namespace nim {
/** @brief Pin消息属性 */
struct NIM_SDK_CPPWRAPPER_DLL_API PinMessageInfo {
    /// Pin Message的ID 客户端生成服务端没有
    std::string id;
    /// Pin Message对应的会话ID (客户端数据)
    std::string session_id;
    /// 被 Pin 消息的服务端ID
    uint64_t server_id;
    /// 被 pin 消息的客户商dID
    std::string client_id;
    /// 被 pin 消息的会话类型
    int to_type;
    /// 被 pin 消息的发送方ID
    std::string from_account;
    /// 被 pin 消息的接收方ID
    std::string to_account;
    /// 被 pin 消息的时间戳
    uint64_t message_time;
    /// Pin Message的操作者ID
    std::string operator_account;
    /// Pin Message的扩展字段
    std::string ext;
    /// Pin Message的创建时间戳
    uint64_t create_time;
    /// Pin Message的更新时间戳
    uint64_t update_time;

    static std::string ToJsonString(const PinMessageInfo& info);
    static void ToJsonObject(const PinMessageInfo& info, nim_cpp_wrapper_util::Json::Value& json_info);
    static nim_cpp_wrapper_util::Json::Value ToJsonObject(const PinMessageInfo& info);
    static void FromJsonString(const std::string& json_info, PinMessageInfo& info);
    static void FromJsonObject(const nim_cpp_wrapper_util::Json::Value& json_info, PinMessageInfo& info);
};

/** @brief 修改、取消Pin Message参数定义 */
struct NIM_SDK_CPPWRAPPER_DLL_API ModifyPinMessageParam {
    /// UnPin 消息所属会话
    std::string session;
    /// UnPin 消息所属会话类型
    int to_type;
    /// Pin Message 的ID 客户端生成服务端没有
    std::string id;
    /// 扩展字段
    std::string ext;
    static std::string ToJsonString(const ModifyPinMessageParam& info);
};

/** @brief 查询Pin Message应答参数定义 */
struct NIM_SDK_CPPWRAPPER_DLL_API QueryAllPinMessageResponse {
    std::list<PinMessageInfo> pin_list;
    static void FromJsonString(const std::string& json_info, QueryAllPinMessageResponse& info);
    static std::string ToJsonString(const QueryAllPinMessageResponse& rsp);
};
}  // namespace nim

#endif  //_NIM_SDK_CPP_TALKEX_HELPER_PIN_MESSAGE_H_
