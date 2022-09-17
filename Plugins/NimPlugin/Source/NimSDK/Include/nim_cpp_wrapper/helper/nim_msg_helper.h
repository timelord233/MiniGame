/** @file nim_msg_helper.h
 * @brief Message 通用辅助方法和数据结构定义
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @date 2015/10/20
 */

#ifndef _NIM_SDK_CPP_MESSAGE_HELPER_H_
#define _NIM_SDK_CPP_MESSAGE_HELPER_H_

#include <functional>
#include <list>
#include <string>
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"
#include "nim_define_include.h"
#include "nim_wrapper_util/nim_json_util.h"

/**
 * @namespace nim
 * @brief namespace nim
 */
namespace nim {

/** @brief 发送消息回执 */
struct NIM_SDK_CPPWRAPPER_DLL_API SendMessageArc {
    /// 会话ID
    std::string talk_id_;
    /// 消息ID
    std::string msg_id_;
    /// 错误码
    NIMResCode rescode_;
    /// 消息时间戳
    int64_t msg_timetag_;
    /// 第三方回调回来的自定义扩展字段
    std::string third_party_callback_ext_;
    /// 易盾反垃圾返回的结果字段
    std::string anti_spam_res_;

    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMMsgKeyLocalTalkId] = talk_id_;
        values[kNIMSendAckKeyMsgId] = msg_id_;
        values[kNIMSendAckKeyRescode] = rescode_;
        values[kNIMSendAckKeyTimetag] = msg_timetag_;
        values[kNIMSendAckKeyCallbackExt] = third_party_callback_ext_;
        values[kNIMSendAckKeyAntiSpamRes] = anti_spam_res_;
        return nim::GetJsonStringWithNoStyled(values);
    }

    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMMsgKeyLocalTalkId] = talk_id_;
        values[kNIMSendAckKeyMsgId] = msg_id_;
        values[kNIMSendAckKeyRescode] = rescode_;
        values[kNIMSendAckKeyTimetag] = msg_timetag_;
        values[kNIMSendAckKeyCallbackExt] = third_party_callback_ext_;
        values[kNIMSendAckKeyAntiSpamRes] = anti_spam_res_;
        return values;
    }
};

/** @brief 消息撤回通知 */
struct NIM_SDK_CPPWRAPPER_DLL_API RecallMsgNotify {
    /// 消息发送方ID
    std::string from_id_;
    /// 消息接收方ID
    std::string to_id_;
    /// 客户端消息ID
    std::string msg_id_;
    /// 自定义通知文案
    std::string notify_;
    /// 消息发送方昵称
    std::string from_nick_;
    /// 消息的操作者，比哪谁撤消了消息
    std::string operator_id_;
    /// 会话类型
    NIMSessionType session_type_;
    /// 通知时间戳
    int64_t notify_timetag_;
    /// 通知的种类
    NIMMessageFeature notify_feature_;
    /// 客户端消息本地是否存在
    bool msglog_exist_;
    /// 撤回的消息的消息时间戳
    int64_t msglog_timetag_;
    /// v8.2.0 透传的附件信息
    std::string attach_;
    /// v8.2.0 第三方回调返回的字定义字段
    std::string callback_ext_;
    RecallMsgNotify()
        : notify_timetag_(0)
        , msglog_exist_(true)
        , msglog_timetag_(0) {}
};

/** @fn bool bool ParseRecallMsgNotify(const std::string json_value, RecallMsgNotify& notify)
 * @brief 解析消息撤回通知
 * @param[in] json_value 消息撤回通知json格式
 * @param[out] notify 消息撤回通知
 * @return bool 解析成功 或失败
 */

NIM_SDK_CPPWRAPPER_DLL_API bool ParseRecallMsgNotify(const std::string json_value, RecallMsgNotify& notify);

/** @fn bool ParseRecallMsgNotify(const std::string& notify_json, std::list<RecallMsgNotify>& notifys)
 * @brief 解析消息撤回通知
 * @param[in] notify_json 消息撤回通知(Json Value数据字符串)
 * @param[out] notifys 消息撤回通知
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseRecallMsgNotify(const std::string& notify_json, std::list<RecallMsgNotify>& notifys);

/** @fn bool ParseSendMessageAck(const std::string& arc_json, SendMessageArc& arc)
 * @brief 解析发送消息回执
 * @param[in] arc_json 发送消息回执(Json Value数据字符串)
 * @param[out] arc 发送消息回执
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseSendMessageAck(const std::string& arc_json, SendMessageArc& arc);

}  // namespace nim

#endif  //_NIM_SDK_CPP_MESSAGE_HELPER_H_
