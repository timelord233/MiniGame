/** @file nim_session_online_service_helper.h
 * @brief SessionOnLineService 辅助方法和数据结构定义
 * @copyright (c) 2015-2019, NetEase Inc. All rights reserved
 * @date 2019/10/22
 */

#ifndef _NIM_CPP_SESSION_ONLINE_SERVICE_HELPER_H_
#define _NIM_CPP_SESSION_ONLINE_SERVICE_HELPER_H_

#include <functional>
#include <list>
#include <string>
#include "nim_cpp_wrapper/helper/nim_msg_helper.h"
#include "nim_cpp_wrapper/helper/nim_talk_helper.h"
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"
#include "nim_define_include.h"
#include "nim_wrapper_util/nim_json_util.h"
/**
 * @namespace nim
 * @brief namespace nim
 */
namespace nim {
class NIM_SDK_CPPWRAPPER_DLL_API SessionOnLineServiceHelper {
public:
    /** @brief 会话服务 会话数据定义 */
    struct NIM_SDK_CPPWRAPPER_DLL_API SessionInfo {
        SessionInfo()
            : last_message_("")
            , last_message_type_(0) {}
        /// 会话ID
        std::string id_;
        /// 会话类型
        NIMSessionType type_;
        /// 自定的扩展字段
        std::string ext_;
        /// 最后一条会话 json string
        std::string last_message_;
        /// 最后更新时间戳
        uint64_t update_time_;
        /// 最后一条消息的类型 0表示普通消息，1表示消息撤回通知
        int last_message_type_;
        // 返回普通消息 auto last_msg = SessionInfo.GetLastMessage<0>();
        template <int type>
        auto GetLastMessage() const -> typename std::enable_if<type == 0, IMMessage>::type {
            IMMessage msg;
            ParseReceiveMessage(last_message_, msg);
            return msg;
        }
        // 返回消息撤回通知auto last_msg = SessionInfo.GetLastMessage<1>();
        template <int type>
        auto GetLastMessage() const -> typename std::enable_if<type == 1, RecallMsgNotify>::type {
            RecallMsgNotify recall_notify_msg;
            ParseRecallMsgNotify(last_message_, recall_notify_msg);
            return recall_notify_msg;
        }
    };
    /// 会话列表
    typedef std::list<SessionInfo> SessionList;

    /** @brief 会话服务 查询会话列表应答数据定义 */
    struct NIM_SDK_CPPWRAPPER_DLL_API QuerySessionListResult {
        /// 返回的错误码 成功:200
        nim::NIMResCode res_code;
        /// 会话列表
        SessionList session_list_;
        /// 是否还有会话数据
        bool has_more_;
    };
    struct NIM_SDK_CPPWRAPPER_DLL_API DeleteSessionParam {
        void AddSession(nim::NIMSessionType /*to_type */, std::string /*session_id */);
        /// list 要删除的会话
        std::list<std::pair<nim::NIMSessionType /*to_type */, std::string /*session_id */>> delete_list_;
    };
    /** @fn bool ParseSessionOnLineInfo(const std::string& session_json, SessionOnLineInfo& session)
     * @brief 解析会话信息
     * @param[in] session_json 会话信息(Json Value数据字符串)
     * @param[out] session 会话信息
     * @return bool 解析成功 或失败
     */
    static bool ParseSessionInfo(const std::string& session_json, SessionInfo& session);

    /** @fn bool ParseSessionList(const std::string& sessions_json, SessionDataList& session_list)
     * @brief 解析查询会话列表结果
     * @param[in] sessions_json 查询结果 (Json Value数据字符串)
     * @param[out] result 会话信息
     * @return bool 解析成功 或失败
     */
    static bool ParseQuerySessionListResult(const std::string& sessions_json, QuerySessionListResult& result);

    /** @fn std::string DeleteSessionParamToJsonString(const DeleteSessionParam& param)
     * @brief 解析查询会话列表结果
     * @param[in] param DeleteSessionParam
     * @return string json string
     */
    static std::string DeleteSessionParamToJsonString(const DeleteSessionParam& param);
};
}  // namespace nim

#endif  //_NIM_CPP_SESSION_ONLINE_SERVICE_HELPER_H_
