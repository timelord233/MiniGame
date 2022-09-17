/** @file nim_talkex_helper_quick_comment.h
 * @brief Talkex快捷回复辅助方法和数据结构定义
 * @copyright (c) 2015-2020, NetEase Inc. All rights reserved
 * @date 2020/04/20
 */

#ifndef _NIM_SDK_CPP_TALKEX_HELPER_QUICK_COMMENT_H_
#define _NIM_SDK_CPP_TALKEX_HELPER_QUICK_COMMENT_H_

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
/** @brief 快捷回复属性 */
struct NIM_SDK_CPPWRAPPER_DLL_API QuickCommentInfo {
    std::string id; /** <服务端没有这个字段，本地为了好处理记录加上的(message serverid + from_accid + type) */
                    /// 回复者的 accid
    std::string from_account;
    /// 开发者自定义的回复类型
    int64_t reply_type;
    /// 被回复消息的客户端ID
    std::string client_id;
    /// 被回复消息的服务端ID
    uint64_t server_id;
    /// 回复的时间戳
    uint64_t time;
    /// 自定义扩展字段，最大8字符
    std::string ext;
    /// 是否需要推送，0表示不需要，1表示需要，默认0
    bool need_push;
    /// 是否需要角标，0表示不需要，1表示需要，默认0
    bool need_badge;
    /// 推送标题
    std::string push_title;
    /// 推送文案
    std::string push_content;
    /// 推送自定义字段JSON
    std::string push_payload;

    static std::string ToJsonString(const QuickCommentInfo& info);
    static nim_cpp_wrapper_util::Json::Value ToJsonObject(const QuickCommentInfo& info);
    static void FromJsonString(const std::string& json_info, QuickCommentInfo& info);
    static void FromJsonObject(const nim_cpp_wrapper_util::Json::Value& json_info, QuickCommentInfo& info);
};

/** @brief 删除快捷回复参数定义 */
struct NIM_SDK_CPPWRAPPER_DLL_API RemoveQuickCommentParam {
    /// string 服务端没有这个字段，本地为了好处理记录加上的
    std::string id;
    /// int64_t 开发者自定义的回复类型
    int64_t reply_type;
    /// string 取消操作的扩展字段
    std::string ext;
    static std::string ToJsonString(const RemoveQuickCommentParam& param);
};

/** @brief 查询快捷回复参数定义 */
struct NIM_SDK_CPPWRAPPER_DLL_API QueryQuickCommentsParam {
    bool AddMessage(const IMMessage& message) {
        if (message_list.size() > 20)
            return false;
        if (std::find_if(message_list.begin(), message_list.end(), [&](const IMMessage& it) {
                return message.client_msg_id_.compare(it.client_msg_id_) == 0;
            }) != message_list.end())
            return false;
        message_list.emplace_back(message);
        return true;
    }
    static std::string ToJsonString(const QueryQuickCommentsParam& param);

    /// list 要查询的消息 一次最多查询20条
    std::list<IMMessage> message_list;
};

/** @brief 查询快捷回复参数定义 */
struct NIM_SDK_CPPWRAPPER_DLL_API QueryQuickCommentsResponse {
    struct QueryQuickCommentsResponseItem {
        std::string message_client_id;
        std::list<QuickCommentInfo> quick_comment_list;
    };
    std::list<QueryQuickCommentsResponseItem> message_quick_comment_list;
    static void FromJsonString(const std::string& json_info, QueryQuickCommentsResponse& info);
};
}  // namespace nim

#endif  //_NIM_SDK_CPP_TALKEX_HELPER_QUICK_COMMENT_H_
