/** @file nim_chatroom_helper.h
 * @brief 聊天室SDK辅助方法
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @date 2015/12/29
 */

#ifndef WRAPPER_NIM_CHATROOM_CPP_WRAPPER_HELPER_NIM_CHATROOM_HELPER_H_
#define WRAPPER_NIM_CHATROOM_CPP_WRAPPER_HELPER_NIM_CHATROOM_HELPER_H_

#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <utility>
#include <vector>
#if !defined(_WIN32) && !defined(WIN32)
#include <pthread.h>
#endif
#include "nim_chatroom_cpp_wrapper/nim_chatroom_sdk_cpp_wrapper.h"
#include "nim_chatroom_def_include.h"
#include "nim_wrapper_util/nim_json_util.h"

/**
 * @namespace nim_chatroom
 * @brief 聊天室
 */
namespace nim_chatroom {

/** @brief 聊天室登录信息 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomEnterInfo {
    /** @fn void SetNick(const std::string &nick)
     * @brief 设置进入聊天室后展示的昵称,选填
     * @param[in] nick 聊天室昵称
     * @return void
     */
    void SetNick(const std::string& nick) { values_[kNIMChatRoomEnterKeyNick] = nick; }

    /** @fn void SetAvatar(const std::string &avatar)
     * @brief 设置进入聊天室后展示的头像,选填
     * @param[in] avatar 聊天室头像下载地址
     * @return void
     */
    void SetAvatar(const std::string& avatar) { values_[kNIMChatRoomEnterKeyAvatar] = avatar; }

    /** @fn void SetExt(const std::string &ext)
     * @brief 设置聊天室可用的扩展字段,选填
     * @param[in] ext 聊天室可用的扩展字段
     * @return void
     */
    void SetExt(const nim_cpp_wrapper_util::Json::Value& ext) { values_[kNIMChatRoomEnterKeyExt] = nim::GetJsonStringWithNoStyled(ext); }

    /** @fn void SetNotifyExt(const std::string &notify_ext)
     * @brief 设置进入聊天室通知开发者扩展字段,选填
     * @param[in] notify_ext 进入聊天室通知开发者扩展字段
     * @return void
     */
    void SetNotifyExt(const nim_cpp_wrapper_util::Json::Value& notify_ext) {
        values_[kNIMChatRoomEnterKeyNotifyExt] = nim::GetJsonStringWithNoStyled(notify_ext);
    }

    /** @fn void SetLoginTag(const std::list<std::string>& login_tags)
     * @brief 设置登录携带的 tag 列表，允许多个
     * @param login_tags 要设置的 tag 列表
     * @return void
     */
    void SetLoginTag(const std::list<std::string>& login_tags) {
        for (auto& tag : login_tags) {
            values_[kNIMChatRoomEnterLoginTags].append(tag);
        }
    }

    /** @fn void SetNotifyTags(const std::string& expression)
     * @brief 登录时携带的 notify tag 表达式
     * @param expression 表达式字符串，如 {"tag": "abc"} or {"tag": "def"}
     * @return void
     */
    void SetNotifyTags(const std::string& expression) { values_[kNIMChatRoomEnterNotifyTags] = expression; }

    /** @fn void SetLocation(NIMChatRoomLocation location)
     * @brief 登录聊天室时传递的位置信息
     * @param location 位置坐标描述
     * @return void
     */
    void SetLocation(NIMChatRoomLocation location) {
        values_[kNIMChatRoomEnterLocationX] = location.x_;
        values_[kNIMChatRoomEnterLocationY] = location.y_;
        values_[kNIMChatRoomEnterLocationZ] = location.z_;
        values_[kNIMChatRoomEnterLocationDistance] = location.distance_;
    }

    /** @fn void EnableLocation(bool enable)
     * @brief 是否启用聊天室空间位置信息功能，启用后 SetLocation 功能才生效，否则 SDK 不解析 Location 信息
     * @param enable true 为启用，false 为关闭，该功能默认关闭
     * @return void
     */
    void EnableLocation(bool enable) { values_[kNIMChatRoomEnterEnableLocation] = enable; }

    /** @fn SetAuthType(int auth_type)
     * @brief 设置鉴权方式
     * @param auth_type 0表示最初的loginToken的校验方式，1表示基于appSecret计算的token鉴权方式，2表示基于第三方回调的token鉴权方式，默认0
     * @return void
     */
    void SetAuthType(int auth_type) { values_[kNIMChatRoomEnterAuthType] = auth_type; }

    /** @fn SetLoginExt(const std::string& login_ext)
     * @brief 登录自定义字段
     * @param login_ext 用于提交给用户的第三方回调服务进行登录检测
     * @return void
     */
    void SetLoginExt(const std::string& login_ext) { values_[kNIMChatRoomEnterLoginExt] = login_ext; }

    /** @fn SetLoginExt(const std::string& login_ext)
     * @brief 配置反垃圾相关业务id
     * @param anti_spam_business_id 用于配置反垃圾相关业务id
     * @return void
     */
    void SetAntiSpamBusinessID(const std::string& anti_spam_business_id) { values_[kNIMChatRoomEnterAntiSpamBusinessID] = anti_spam_business_id; }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return void
     */
    std::string ToJsonString() const { return values_.empty() ? "" : nim::GetJsonStringWithNoStyled(values_); }

public:
    nim_cpp_wrapper_util::Json::Value values_;
};

/// @struct ChatRoomIndependentEnterInfo
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomIndependentEnterInfo {
    /// 聊天室地址，地址通过应用服务器接口获取
    std::list<std::string> address_;
    /// 应用数据目录
    std::string app_data_file_;
    /// 匿名登录时选填,定义见NIMSDKLogLevel（选填，SDK默认的内置级别为kNIMSDKLogLevelPro）
    int sdk_log_level_;
    /// 应用appkey，匿名登录时必填
    std::string app_key_;
    /// 登录聊天室的账号
    std::string accid_;
    /// 登录聊天室的密码
    std::string token_;
    /// 登录标签，可以设置多个
    std::list<std::string> login_tags_;
    /// 登录登出通知的目标标签
    std::string notify_tags_;
    /// 位置坐标描述
    NIMChatRoomLocation location_;
    /// 是否启用空间消息能力，true 为启用，false 为关闭，SDK 不解析 location 相关信息
    bool enable_location_;
    /// 鉴权方式，0表示最初的loginToken的校验方式，1表示基于appSecret计算的token鉴权方式，2表示基于第三方回调的token鉴权方式，默认0
    int auth_type_;
    /// 登录自定义字段
    std::string login_ext_;
    /// 反垃圾相关业务id
    std::string anti_spam_business_id_;

    ChatRoomIndependentEnterInfo() {
        sdk_log_level_ = 5;
        location_ = {0};
        enable_location_ = false;
        auth_type_ = 0;
    }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return void
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        std::string addr_str;
        for (auto& address : address_) {
            values[kNIMChatRoomEnterKeyAddress].append(address);
        }
        std::string login_tags;
        nim::StrListToJsonString(login_tags_, login_tags);
        values[kNIMChatRoomEnterLoginTags] = login_tags;
        values[kNIMChatRoomEnterKeyAppDataPath] = app_data_file_;
        values[kNIMChatRoomEnterKeyLogLevel] = sdk_log_level_;
        values[kNIMChatRoomEnterKeyAppKey] = app_key_;
        values[kNIMChatRoomEnterKeyAccID] = accid_;
        values[kNIMChatRoomEnterKeyToken] = token_;
        values[kNIMChatRoomEnterNotifyTags] = notify_tags_;
        values[kNIMChatRoomEnterLocationX] = location_.x_;
        values[kNIMChatRoomEnterLocationY] = location_.y_;
        values[kNIMChatRoomEnterLocationZ] = location_.z_;
        values[kNIMChatRoomEnterLocationDistance] = location_.distance_;
        values[kNIMChatRoomEnterEnableLocation] = enable_location_;
        values[kNIMChatRoomEnterAuthType] = auth_type_;
        values[kNIMChatRoomEnterLoginExt] = login_ext_;
        values[kNIMChatRoomEnterAntiSpamBusinessID] = anti_spam_business_id_;
        return nim::GetJsonStringWithNoStyled(values);
    }

    /** @fn nim_cpp_wrapper_util::Json::Value ToJsonObject() const
     * @brief 组装Json Value
     * @return nim_cpp_wrapper_util::Json::Value
     */
    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        std::string addr_str;
        values[kNIMChatRoomEnterKeyAddress] = nim_cpp_wrapper_util::Json::Value(nim_cpp_wrapper_util::Json::arrayValue);
        for (auto& address : address_) {
            values[kNIMChatRoomEnterKeyAddress].append(address);
        }
        std::string login_tags;
        nim::StrListToJsonString(login_tags_, login_tags);
        values[kNIMChatRoomEnterLoginTags] = login_tags;
        values[kNIMChatRoomEnterKeyAppDataPath] = app_data_file_;
        values[kNIMChatRoomEnterKeyLogLevel] = sdk_log_level_;
        values[kNIMChatRoomEnterKeyAppKey] = app_key_;
        values[kNIMChatRoomEnterKeyAccID] = accid_;
        values[kNIMChatRoomEnterKeyToken] = token_;
        values[kNIMChatRoomEnterNotifyTags] = notify_tags_;
        values[kNIMChatRoomEnterLocationX] = location_.x_;
        values[kNIMChatRoomEnterLocationY] = location_.y_;
        values[kNIMChatRoomEnterLocationZ] = location_.z_;
        values[kNIMChatRoomEnterLocationDistance] = location_.distance_;
        values[kNIMChatRoomEnterEnableLocation] = enable_location_;
        values[kNIMChatRoomEnterAuthType] = auth_type_;
        values[kNIMChatRoomEnterLoginExt] = login_ext_;
        values[kNIMChatRoomEnterAntiSpamBusinessID] = anti_spam_business_id_;
        return values;
    }

    void FromJsonObject(const nim_cpp_wrapper_util::Json::Value& values) {
        nim::JsonArrayStringToList(values[kNIMChatRoomEnterLoginTags].asString(), login_tags_);
        app_data_file_ = values[kNIMChatRoomEnterKeyAppDataPath].asString();
        sdk_log_level_ = values[kNIMChatRoomEnterKeyLogLevel].asInt();
        app_key_ = values[kNIMChatRoomEnterKeyAppKey].asString();
        accid_ = values[kNIMChatRoomEnterKeyAccID].asString();
        token_ = values[kNIMChatRoomEnterKeyToken].asString();
        notify_tags_ = values[kNIMChatRoomEnterNotifyTags].asString();
        location_.x_ = values[kNIMChatRoomEnterLocationX].asFloat();
        location_.y_ = values[kNIMChatRoomEnterLocationY].asFloat();
        location_.z_ = values[kNIMChatRoomEnterLocationZ].asFloat();
        location_.distance_ = values[kNIMChatRoomEnterLocationDistance].asFloat();
        enable_location_ = values[kNIMChatRoomEnterEnableLocation].asBool();
        auth_type_ = values[kNIMChatRoomEnterAuthType].asInt();
        login_ext_ = values[kNIMChatRoomEnterLoginExt].asString();
        anti_spam_business_id_ = values[kNIMChatRoomEnterAntiSpamBusinessID].asString();
        for (auto index = values[kNIMChatRoomEnterKeyAddress].begin(); index != values[kNIMChatRoomEnterKeyAddress].end(); index++) {
            address_.push_back(index->asString());
        }
    }
};

/// @struct ChatRoomAnoymityEnterInfo
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomAnoymityEnterInfo {
    /// 聊天室地址，地址通过应用服务器接口获取
    std::list<std::string> address_;
    /// 应用数据目录，匿名登录时必填,使用默认路径时只需传入单个目录名（不以反斜杠结尾)，使用自定义路径时需传入完整路径（以反斜杠结尾，并确保有正确的读写权限！）
    std::string app_data_file_;
    /// 匿名登录时选填,定义见NIMSDKLogLevel（选填，SDK默认的内置级别为kNIMSDKLogLevelPro）
    int sdk_log_level_;
    /// 应用appkey，匿名登录时必填
    std::string app_key_;
    /// 是否开启随机ID模式，默认为关闭(false)，建议默认值
    bool random_id_;
    /// 使用自定义用户 ID，一旦指定，SDK 不会自动生成随机 ID，random 参数将无效
    std::string accid_;
    /// 登录聊天室的密码
    std::string token_;

    ChatRoomAnoymityEnterInfo() {
        sdk_log_level_ = 5;
        random_id_ = false;
    }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return void
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        std::string addr_str;
        for (auto& address : address_) {
            values[kNIMChatRoomEnterKeyAddress].append(address);
        }
        values[kNIMChatRoomEnterKeyAppDataPath] = app_data_file_;
        values[kNIMChatRoomEnterKeyLogLevel] = sdk_log_level_;
        values[kNIMChatRoomEnterKeyAppKey] = app_key_;
        values[kNIMChatRoomEnterKeyRandomID] = random_id_ ? 1 : 0;
        values[kNIMChatRoomEnterKeyAccID] = accid_;
        values[kNIMChatRoomEnterKeyToken] = token_;
        return nim::GetJsonStringWithNoStyled(values);
    }
    /** @fn nim_cpp_wrapper_util::Json::Value ToJsonObject() const
     * @brief 组装Json Value
     * @return nim_cpp_wrapper_util::Json::Value
     */
    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        std::string addr_str;
        values[kNIMChatRoomEnterKeyAddress] = nim_cpp_wrapper_util::Json::Value(nim_cpp_wrapper_util::Json::arrayValue);
        for (auto& address : address_) {
            values[kNIMChatRoomEnterKeyAddress].append(address);
        }
        values[kNIMChatRoomEnterKeyAppDataPath] = app_data_file_;
        values[kNIMChatRoomEnterKeyLogLevel] = sdk_log_level_;
        values[kNIMChatRoomEnterKeyAppKey] = app_key_;
        values[kNIMChatRoomEnterKeyRandomID] = random_id_ ? 1 : 0;
        values[kNIMChatRoomEnterKeyAccID] = accid_;
        values[kNIMChatRoomEnterKeyToken] = token_;
        return values;
    }
    /** @fn void ParseJsonValue(const nim_cpp_wrapper_util::Json::Value& values)
     * @brief 解析Json Value
     * @param[in] values Json Value
     * @return void
     */
    void ParseJsonValue(const nim_cpp_wrapper_util::Json::Value& values) {
        if (values.isMember(kNIMChatRoomEnterKeyAddress)) {
            address_.clear();
            for (auto iter = values[kNIMChatRoomEnterKeyAddress].begin(); iter != values[kNIMChatRoomEnterKeyAddress].end(); ++iter) {
                address_.push_back(iter->asString());
            }
        }
        if (values.isMember(kNIMChatRoomEnterKeyAppDataPath))
            app_data_file_ = values[kNIMChatRoomEnterKeyAppDataPath].asString();
        if (values.isMember(kNIMChatRoomEnterKeyLogLevel))
            sdk_log_level_ = values[kNIMChatRoomEnterKeyLogLevel].asInt();
        if (values.isMember(kNIMChatRoomEnterKeyAppKey))
            app_key_ = values[kNIMChatRoomEnterKeyAppKey].asString();
        if (values.isMember(kNIMChatRoomEnterKeyRandomID))
            random_id_ = values[kNIMChatRoomEnterKeyRandomID].asInt() == 1;
        if (values.isMember(kNIMChatRoomEnterKeyAccID))
            accid_ = values[kNIMChatRoomEnterKeyAccID].asString();
        if (values.isMember(kNIMChatRoomEnterKeyToken))
            token_ = values[kNIMChatRoomEnterKeyToken].asString();
    }
};

/** @brief 聊天室信息 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomInfo {
    /// 聊天室ID
    int64_t id_;
    /// 聊天室名称
    std::string name_;
    /// 聊天室公告
    std::string announcement_;
    /// 视频直播拉流地址
    std::string broadcast_url_;
    /// 聊天室创建者账号
    std::string creator_id_;
    /// 聊天室有效标记, 1:有效,0:无效
    int valid_flag_{0};
    /// 第三方扩展字段, 必须为可以解析为json的非格式化的字符串, 长度4k
    std::string ext_;
    /// 在线人数
    int online_count_{0};
    /// 聊天室禁言标志 1:禁言,0:非禁言
    int mute_all_{0};
    /// int, 队列管理权限：0:所有人都有权限变更队列，1:只有主播管理员才能操作变更
    int queuelevel{0};
    /** 构造函数 */
    ChatRoomInfo()
        : id_(0)
        , valid_flag_(0)
        , mute_all_(0)
        , queuelevel(1) {}

    /** @fn void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value &values)
     * @brief 从JsonValue中解析得到聊天室信息
     * @param[in] values 聊天室信息JsonValue
     * @return void
     */
    void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value& values) {
        id_ = values[kNIMChatRoomInfoKeyID].asUInt64();
        name_ = values[kNIMChatRoomInfoKeyName].asString();
        announcement_ = values[kNIMChatRoomInfoKeyAnnouncement].asString();
        broadcast_url_ = values[kNIMChatRoomInfoKeyBroadcastUrl].asString();
        creator_id_ = values[kNIMChatRoomInfoKeyCreatorID].asString();
        valid_flag_ = values[kNIMChatRoomInfoKeyValidFlag].asUInt();
        ext_ = values[kNIMChatRoomInfoKeyExt].asString();
        online_count_ = values[kNIMChatRoomInfoKeyOnlineCount].asUInt();
        mute_all_ = values[kNIMChatRoomInfoKeyMuteAll].asUInt();
        queuelevel = values[kNIMChatRoomInfoKeyQueuelevel].asInt();
    }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return void
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomInfoKeyID] = id_;
        values[kNIMChatRoomInfoKeyName] = name_;
        values[kNIMChatRoomInfoKeyAnnouncement] = announcement_;
        values[kNIMChatRoomInfoKeyBroadcastUrl] = broadcast_url_;
        values[kNIMChatRoomInfoKeyCreatorID] = creator_id_;
        values[kNIMChatRoomInfoKeyValidFlag] = valid_flag_;
        values[kNIMChatRoomInfoKeyExt] = ext_;
        values[kNIMChatRoomInfoKeyOnlineCount] = online_count_;
        values[kNIMChatRoomInfoKeyMuteAll] = mute_all_;
        values[kNIMChatRoomInfoKeyQueuelevel] = queuelevel;
        return nim::GetJsonStringWithNoStyled(values);
    }

    /** @fn nim_cpp_wrapper_util::Json::Value ToJsonObject() const
     * @brief 组装Json Value
     * @return nim_cpp_wrapper_util::Json::Value
     */
    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomInfoKeyID] = id_;
        values[kNIMChatRoomInfoKeyName] = name_;
        values[kNIMChatRoomInfoKeyAnnouncement] = announcement_;
        values[kNIMChatRoomInfoKeyBroadcastUrl] = broadcast_url_;
        values[kNIMChatRoomInfoKeyCreatorID] = creator_id_;
        values[kNIMChatRoomInfoKeyValidFlag] = valid_flag_;
        values[kNIMChatRoomInfoKeyExt] = ext_;
        values[kNIMChatRoomInfoKeyOnlineCount] = online_count_;
        values[kNIMChatRoomInfoKeyMuteAll] = mute_all_;
        values[kNIMChatRoomInfoKeyQueuelevel] = queuelevel;
        return values;
    }
};

/** @brief 聊天室通知 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomNotification {
    /// 通知类型
    NIMChatRoomNotificationId id_;
    /// 上层开发自定义的事件通知扩展字段, 必须为可以解析为json的非格式化的字符串
    std::string ext_;
    /// 操作者的账号accid
    std::string operator_id_;
    /// 操作者的账号nick
    std::string operator_nick_;
    /// 被操作者的账号nick列表
    std::list<std::string> target_nick_;
    /// 被操作者的accid列表
    std::list<std::string> target_ids_;
    /// 当通知为临时禁言相关时有该值，禁言时代表本次禁言的时长(秒)，解禁时代表本次禁言剩余时长(秒)
    /// 当通知为聊天室进入事件，代表临时禁言时长(秒); 其他通知事件不带该数据
    /// 当通知为聊天室进入事件才有，代表是否禁言状态
    int64_t temp_mute_duration_;
    bool muted_;
    /// 当通知为聊天室进入事件才有，代表是否临时禁言状态
    bool temp_muted_;
    /// 当通知为聊天室队列变更事件才有，代表变更的内容
    std::string queue_change_;

    /** Added IM 8.4.0 */
    /// 当通知为聊天室按标签禁言/解禁事件才有，代表当前被禁言的 tag
    std::string target_tag_;

    /** Added IM 8.7.0 */
    /// 当通知为聊天室撤回消息事件时才有，代表当前被撤回的消息 ID
    std::string msg_id_;
    /// 当通知为聊天室撤回消息事件时才有，代表当前被撤回消息的时间戳
    uint64_t msg_timetag_;

    /** 构造函数 */
    ChatRoomNotification()
        : temp_mute_duration_(0)
        , muted_(false)
        , temp_muted_(false)
        , msg_timetag_(0) {}

    /** @fn void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value &values)
     * @brief 从JsonValue中解析得到聊天室通知
     * @param[in] values 聊天室通知JsonValue
     * @return void
     */
    void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value& values) {
        id_ = (NIMChatRoomNotificationId)values[kChatRoomNotificationKeyID].asUInt();
        ext_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyExt].asString();
        operator_id_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyOpt].asString();
        operator_nick_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyOptNick].asString();
        nim::JsonStrArrayToList(values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyTargetNick], target_nick_);
        nim::JsonStrArrayToList(values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyTarget], target_ids_);
        if (id_ == kNIMChatRoomNotificationIdMemberTempMute || id_ == kNIMChatRoomNotificationIdMemberTempUnMute) {
            temp_mute_duration_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyTempMuteDuration].asInt64();
            temp_muted_ = (temp_mute_duration_ != 0);
        }
        if (id_ == kNIMChatRoomNotificationIdMemberIn) {
            if (values[kChatRoomNotificationKeyData].isMember(kChatRoomNotificationDataKeyMuteFlag))
                muted_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyMuteFlag].asUInt() == 1;
            if (values[kChatRoomNotificationKeyData].isMember(kChatRoomNotificationDataKeyTempMutedFlag))
                temp_muted_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyTempMutedFlag].asUInt() == 1;
            temp_mute_duration_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyMemberInTempMutedDuration].asInt64();
        }
        if (id_ == kNIMChatRoomNotificationIdQueueChanged || id_ == kNIMChatRoomNotificationIdQueueBatchChanged ||
            id_ == kNIMChatRoomNotificationIdQueueBatchOffer) {
            queue_change_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyQueueChange].asString();
        }
        if (id_ == kNIMChatRoomNotificationIdTagTempMuteAdd || id_ == kNIMChatRoomNotificationIdTagTempMuteRemove) {
            if (values[kChatRoomNotificationKeyData].isMember(kChatRoomNotificationDataKeyTargetTag)) {
                target_tag_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyTargetTag].asString();
            }
            if (values[kChatRoomNotificationKeyData].isMember(kChatRoomNotificationDataKeyTempMuteDuration)) {
                temp_mute_duration_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyTempMuteDuration].asInt64();
            }
            temp_muted_ = (temp_mute_duration_ != 0);
        }
        if (id_ == kNIMChatRoomNotificationIdRecallMessage) {
            if (values[kChatRoomNotificationKeyData].isMember(kChatRoomNotificationDataKeyMsgTimetag)) {
                msg_timetag_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyMsgTimetag].asUInt64();
            }
            if (values[kChatRoomNotificationKeyData].isMember(kChatRoomNotificationDataKeyMsgId)) {
                msg_id_ = values[kChatRoomNotificationKeyData][kChatRoomNotificationDataKeyMsgId].asString();
            }
        }
    }

    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomInfoKeyID] = id_;
        values[kChatRoomNotificationDataKeyExt] = ext_;
        values[kChatRoomNotificationDataKeyOpt] = operator_id_;
        values[kChatRoomNotificationDataKeyOptNick] = operator_nick_;
        for (const auto& nick : target_nick_) {
            values[kChatRoomNotificationDataKeyTargetNick].append(nick);
        }
        for (const auto& id : target_ids_) {
            values[kChatRoomNotificationDataKeyTarget].append(id);
        }
        values[kChatRoomNotificationDataKeyTempMuteDuration] = temp_mute_duration_;
        values[kChatRoomNotificationDataKeyMuteFlag] = muted_;
        values[kChatRoomNotificationDataKeyTempMutedFlag] = temp_muted_;
        values[kChatRoomNotificationDataKeyQueueChange] = queue_change_;
        if (!target_tag_.empty())
            values[kChatRoomNotificationDataKeyTargetTag] = target_tag_;
        if (!msg_id_.empty()) {
            values[kChatRoomNotificationDataKeyMsgTimetag] = msg_timetag_;
            values[kChatRoomNotificationDataKeyMsgId] = msg_id_;
        }

        return nim::GetJsonStringWithNoStyled(values);
    }

    /** @fn nim_cpp_wrapper_util::Json::Value ToJsonObject() const
     * @brief 组装Json Value
     * @return nim_cpp_wrapper_util::Json::Value
     */
    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomInfoKeyID] = id_;
        values[kChatRoomNotificationDataKeyExt] = ext_;
        values[kChatRoomNotificationDataKeyOpt] = operator_id_;
        values[kChatRoomNotificationDataKeyOptNick] = operator_nick_;
        for (const auto& nick : target_nick_) {
            values[kChatRoomNotificationDataKeyTargetNick].append(nick);
        }
        for (const auto& id : target_ids_) {
            values[kChatRoomNotificationDataKeyTarget].append(id);
        }
        values[kChatRoomNotificationDataKeyTempMuteDuration] = temp_mute_duration_;
        values[kChatRoomNotificationDataKeyMuteFlag] = muted_;
        values[kChatRoomNotificationDataKeyTempMutedFlag] = temp_muted_;
        values[kChatRoomNotificationDataKeyQueueChange] = queue_change_;
        if (!target_tag_.empty())
            values[kChatRoomNotificationDataKeyTargetTag] = target_tag_;
        if (!msg_id_.empty()) {
            values[kChatRoomNotificationDataKeyMsgTimetag] = msg_timetag_;
            values[kChatRoomNotificationDataKeyMsgId] = msg_id_;
        }
        return values;
    }
};

/** @brief 聊天室麦序添加、更新选项 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomQueueOfferOption {
public:
    /// true 表示当提交这个新元素的用户从聊天室掉线或退出的时候，需要删除这个元素；默认 false 表示不删除
    bool transient_;
    /// 队列元素所属账号，默认不传表示队列元素属于当前操作人，管理员可以指定队列元素归属于其他合法账号
    std::string element_accid_;
    ChatRoomQueueOfferOption()
        : transient_(false) {}
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomQueueOfferOptionTransient] = transient_;
        if (!element_accid_.empty())
            values[kNIMChatRoomQueueOfferOptionElementAccId] = element_accid_;
        return nim::GetJsonStringWithNoStyled(values);
    }
};

/** @brief 聊天室队列通知内容 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomQueueChangedNotification {
    /// 队列变更类型 OFFER, POLL, DROP
    std::string type_;
    /// 队列变更元素的Key
    std::string key_;
    /// 队列变更元素的Value
    std::string value_;

    /** @fn void ParseFromNotification(const ChatRoomNotification& notification)
     * @brief 从聊天室通知中解析得到队列变更具体内容
     * @param[in] notification 聊天室通知
     * @return void
     */
    void ParseFromNotification(const ChatRoomNotification& notification) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(notification.queue_change_, values) && values.isObject()) {
            type_ = values[kNIMChatRoomNotificationQueueChangedKeyType].asString();
            key_ = values[kNIMChatRoomNotificationQueueChangedKeyKey].asString();
            value_ = values[kNIMChatRoomNotificationQueueChangedKeyValue].asString();
        }
    }
};

/** @brief  通知麦序队列中有批量变更，发生在元素提交者离开聊天室或者从聊天室异常掉线时 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomQueueBatchChangedNotification {
    /// 队列变更类型 OFFER, POLL, DROP
    std::string type_;
    /// 队列变更元素的Key
    std::string key_;
    /// 队列变更元素的Value
    std::string value_;
    /// 队列变更元素的Value
    std::map<std::string, std::string> changed_values_;

    /** @fn void ParseFromNotification(const ChatRoomNotification& notification)
     * @brief 从聊天室通知中解析得到队列变更具体内容
     * @param[in] notification 聊天室通知
     * @return void
     */
    void ParseFromNotification(const ChatRoomNotification& notification) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(notification.queue_change_, values) && values.isObject()) {
            type_ = values[kNIMChatRoomNotificationQueueBatchChangedKeyType].asString();
            if (values.isMember(kNIMChatRoomNotificationQueueBatchChangedKeyKey))
                key_ = values[kNIMChatRoomNotificationQueueBatchChangedKeyKey].asString();
            if (values.isMember(kNIMChatRoomNotificationQueueBatchChangedKeyValue))
                value_ = values[kNIMChatRoomNotificationQueueBatchChangedKeyValue].asString();
            if (values.isMember(kNIMChatRoomNotificationQueueBatchChangedKeyObject)) {
                auto members_name = values[kNIMChatRoomNotificationQueueBatchChangedKeyObject].getMemberNames();
                auto it = members_name.begin();
                while (it != members_name.end()) {
                    changed_values_.insert(std::make_pair(*it, values[kNIMChatRoomNotificationQueueBatchChangedKeyObject][*it].asString()));
                    it++;
                }
            }
        }
    }
};

/** @brief 聊天室消息属性设置 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomMessageSetting {
    /// 消息重发标记位
    bool resend_flag_;
    /// 第三方扩展字段, 必须为可以解析为json的非格式化的字符串，长度限制4096
    std::string ext_;
    /// 是否需要过易盾反垃圾
    bool anti_spam_enable_;
    /// (可选)开发者自定义的反垃圾字段,长度限制2048
    std::string anti_spam_content_;
    /// (可选)是否存云端消息历史，默认存
    bool history_save_;
    /// (可选)用户配置的对某些单条消息另外的反垃圾的业务ID
    std::string anti_spam_bizid_;
    /// (可选) 单条消息是否使用易盾反垃圾 0:(在开通易盾的情况下)不过易盾反垃圾而是通用反垃圾,其他都是按照原来的规则
    int anti_spam_using_yidun_;
    /// 高优先级消息标记,1:是; 非高优先级消息不带该字段,服务器填写,发送方不需要填写
    int high_priority_;
    /// (可选)String, 易盾反垃圾增强反作弊专属字段, 限制json，长度限制1024
    std::string yidun_anti_cheating_;
    /// (可选) 自定义抄送配置
    std::string env_config_;
    /// (可选)String, 易盾反垃圾扩展字段，限制json，长度限制1024
    std::string anti_spam_ext_;
    /// (可选)发送消息时附加的位置信息
    NIMChatRoomLocation location_;
    /// (可选)消息接受者，如果设置了本字段，且不为空，则本消息为聊天室定向消息（聊天室定向消息不会存历史）
    std::list<std::string> to_accids;
    /** 构造函数 */
    ChatRoomMessageSetting()
        : resend_flag_(false)
        , anti_spam_enable_(false)
        , history_save_(true)
        , anti_spam_bizid_("")
        , anti_spam_using_yidun_(1)
        , high_priority_(0)
        , yidun_anti_cheating_("")
        , anti_spam_ext_("")
        , location_({0}) {}

    /** @fn void ToJsonValue(nim_cpp_wrapper_util::Json::Value& message) const
     * @brief 组装Json Value字符串
     * @param[out] message 消息Json
     * @return void
     */
    void ToJsonValue(nim_cpp_wrapper_util::Json::Value& message) const {
        message[kNIMChatRoomMsgKeyResendFlag] = resend_flag_ ? 1 : 0;
        message[kNIMChatRoomMsgKeyExt] = ext_;
        message[kNIMChatRoomMsgKeyAntiSpamEnable] = anti_spam_enable_ ? 1 : 0;
        message[kNIMChatRoomMsgKeyAntiSpamContent] = anti_spam_content_;
        message[kNIMChatRoomMsgKeyAntiSpamBizId] = anti_spam_bizid_;
        message[kNIMChatRoomMsgKeyHistorySave] = history_save_ ? 1 : 0;
        message[kNIMChatRoomMsgKeyAntiSpamUsingYiDun] = anti_spam_using_yidun_;
        message[kNIMChatRoomMsgKeyYiDunAntiCheating] = yidun_anti_cheating_;
        message[kNIMChatRoomMsgKeyEnvConfig] = env_config_;
        message[kNIMChatRoomMsgKeyAntiSpamExt] = anti_spam_ext_;
        message[kNIMChatRoomMsgKeyLocationX] = location_.x_;
        message[kNIMChatRoomMsgKeyLocationY] = location_.y_;
        message[kNIMChatRoomMsgKeyLocationZ] = location_.z_;
        std::string to_accids_str;
        nim::StrListToJsonString(to_accids, to_accids_str);
        message[kNIMChatRoomMsgKeyToAccids] = to_accids_str;
    }

    /** @fn void ParseMessageSetting(const nim_cpp_wrapper_util::Json::Value& message)
     * @brief 从Json Value解析出消息属性设置
     * @param[in] message 消息Json
     * @return void
     */
    void ParseMessageSetting(const nim_cpp_wrapper_util::Json::Value& message) {
        resend_flag_ = message[kNIMChatRoomMsgKeyResendFlag].asUInt() == 1;
        ext_ = message[kNIMChatRoomMsgKeyExt].asString();
        if (message.isMember(kNIMChatRoomMsgKeyAntiSpamEnable))
            anti_spam_enable_ = message[kNIMChatRoomMsgKeyAntiSpamEnable].asInt() == 1;
        anti_spam_content_ = message[kNIMChatRoomMsgKeyAntiSpamContent].asString();
        high_priority_ = message[kNIMChatRoomMsgKeyHighPriorityFlag].asInt();
        if (message.isMember(kNIMChatRoomMsgKeyYiDunAntiCheating))
            yidun_anti_cheating_ = message[kNIMChatRoomMsgKeyYiDunAntiCheating].asString();
        if (message.isMember(kNIMChatRoomMsgKeyEnvConfig))
            env_config_ = message[kNIMChatRoomMsgKeyEnvConfig].asString();
        if (message.isMember(kNIMChatRoomMsgKeyAntiSpamExt))
            anti_spam_ext_ = message[kNIMChatRoomMsgKeyAntiSpamExt].asString();
        if (message.isMember(kNIMChatRoomMsgKeyLocationX))
            location_.x_ = message[kNIMChatRoomMsgKeyLocationX].asFloat();
        if (message.isMember(kNIMChatRoomMsgKeyLocationY))
            location_.y_ = message[kNIMChatRoomMsgKeyLocationY].asFloat();
        if (message.isMember(kNIMChatRoomMsgKeyLocationZ))
            location_.z_ = message[kNIMChatRoomMsgKeyLocationZ].asFloat();
        if (message.isMember(kNIMChatRoomMsgKeyToAccids)) {
            to_accids.clear();
            nim::JsonStrArrayToList(message[kNIMChatRoomMsgKeyToAccids], to_accids);
        }
    }
};

/** @brief 聊天室消息 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomMessage {
public:
    /// 消息所属的聊天室id,服务器填写,发送方不需要填写
    int64_t room_id_;
    /// 消息发送者的账号,服务器填写,发送方不需要填写
    std::string from_id_;
    /// 消息发送的时间戳(毫秒),服务器填写,发送方不需要填写
    int64_t timetag_;
    /// 消息发送方客户端类型,服务器填写,发送方不需要填写
    NIMChatRoomClientType from_client_type_;
    /// 发送方昵称,服务器填写,发送方不需要填写
    std::string from_nick_;
    /// 发送方头像,服务器填写,发送方不需要填写
    std::string from_avatar_;
    /// 发送方身份扩展字段,服务器填写,发送方不需要填写
    std::string from_ext_;
    // v7.8 <--
    /// 第三方回调回来的自定义扩展字段
    std::string third_party_callback_ext_;
    // --> v7.8
    // v8.4.0 <--
    /// 对端发送消息或通知时携带的 notify tags 信息
    std::string notify_tags_;
    // --> v8.4.0
    /// String, 易盾反垃圾返回的结果字段
    std::string anti_spam_res_;

public:
    /// 消息类型
    NIMChatRoomMsgType msg_type_{kNIMChatRoomMsgTypeText};
    /// 消息内容,长度限制2048,json结构, 文本消息和其他消息保持一致
    std::string msg_attach_;
    /// 客户端消息id
    std::string client_msg_id_;
    /// 文本消息内容（聊天室机器人文本消息）
    std::string msg_body_;
    /// 消息属性设置
    ChatRoomMessageSetting msg_setting_;
    // v7.8 <--
    /// 消息的子类型，客户端定义，服务器透传
    int32_t sub_type_;
    // --> v7.8
public:
    /// 媒体文件本地绝对路径（客户端）
    std::string local_res_path_;
    /// 媒体文件ID（客户端）
    std::string local_res_id_;

    /** 构造函数 */
    ChatRoomMessage()
        : room_id_(0)
        , from_client_type_(kNIMChatRoomClientTypeDefault)
        , timetag_(0)
        , third_party_callback_ext_("")
        , sub_type_(0) {}

    /** @fn void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value &values)
     * @brief 从JsonValue中解析得到聊天室消息
     * @param[in] values 聊天室消息JsonValue
     * @return void
     */
    void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value& values) {
        room_id_ = values[kNIMChatRoomMsgKeyRoomID].asInt64();
        from_id_ = values[kNIMChatRoomMsgKeyFromAccount].asString();
        timetag_ = values[kNIMChatRoomMsgKeyTime].asUInt64();
        from_client_type_ = (NIMChatRoomClientType)values[kNIMChatRoomMsgKeyFromClientType].asUInt();
        from_nick_ = values[kNIMChatRoomMsgKeyFromNick].asString();
        from_avatar_ = values[kNIMChatRoomMsgKeyFromAvatar].asString();
        from_ext_ = values[kNIMChatRoomMsgKeyFromExt].asString();
        msg_type_ = (NIMChatRoomMsgType)values[kNIMChatRoomMsgKeyType].asUInt();
        msg_attach_ = values[kNIMChatRoomMsgKeyAttach].asString();
        client_msg_id_ = values[kNIMChatRoomMsgKeyClientMsgid].asString();
        local_res_path_ = values[kNIMChatRoomMsgKeyLocalFilePath].asString();
        local_res_id_ = values[kNIMChatRoomMsgKeyLocalResId].asString();
        msg_body_ = values[kNIMChatRoomMsgKeyBody].asString();
        msg_setting_.ParseMessageSetting(values);
        if (values.isMember(kNIMChatRoomMsgKeyThirdPartyCBEXT))
            third_party_callback_ext_ = values[kNIMChatRoomMsgKeyThirdPartyCBEXT].asString();
        if (values.isMember(kNIMChatRoomMsgKeySubType))
            sub_type_ = values[kNIMChatRoomMsgKeySubType].asInt();
        if (values.isMember(kNIMChatRoomMsgKeyNotifyTags))
            notify_tags_ = values[kNIMChatRoomMsgKeyNotifyTags].asString();
        if (values.isMember(kNIMChatRoomMsgKeyAntiSpamRes))
            anti_spam_res_ = values[kNIMChatRoomMsgKeyAntiSpamRes].asString();
    }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return string Json Value字符串
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomMsgKeyRoomID] = room_id_;
        values[kNIMChatRoomMsgKeyFromAccount] = from_id_;
        values[kNIMChatRoomMsgKeyTime] = timetag_;
        values[kNIMChatRoomMsgKeyFromClientType] = from_client_type_;
        values[kNIMChatRoomMsgKeyFromNick] = from_nick_;
        values[kNIMChatRoomMsgKeyFromAvatar] = from_avatar_;
        values[kNIMChatRoomMsgKeyFromExt] = from_ext_;
        values[kNIMChatRoomMsgKeyType] = msg_type_;
        values[kNIMChatRoomMsgKeyAttach] = msg_attach_;
        values[kNIMChatRoomMsgKeyClientMsgid] = client_msg_id_;
        values[kNIMChatRoomMsgKeyLocalFilePath] = local_res_path_;
        values[kNIMChatRoomMsgKeyLocalResId] = local_res_id_;
        values[kNIMChatRoomMsgKeyBody] = msg_body_;
        values[kNIMChatRoomMsgKeyThirdPartyCBEXT] = third_party_callback_ext_;
        values[kNIMChatRoomMsgKeySubType] = sub_type_;
        values[kNIMChatRoomMsgKeyAntiSpamRes] = anti_spam_res_;
        values[kNIMChatRoomMsgKeyNotifyTags] = notify_tags_;
        msg_setting_.ToJsonValue(values);
        return nim::GetJsonStringWithNoStyled(values);
    }

    /** @fn nim_cpp_wrapper_util::Json::Value ToJsonObject() const
     * @brief 组装Json Value
     * @return nim_cpp_wrapper_util::Json::Value
     */
    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomMsgKeyRoomID] = room_id_;
        values[kNIMChatRoomMsgKeyFromAccount] = from_id_;
        values[kNIMChatRoomMsgKeyTime] = timetag_;
        values[kNIMChatRoomMsgKeyFromClientType] = from_client_type_;
        values[kNIMChatRoomMsgKeyFromNick] = from_nick_;
        values[kNIMChatRoomMsgKeyFromAvatar] = from_avatar_;
        values[kNIMChatRoomMsgKeyFromExt] = from_ext_;
        values[kNIMChatRoomMsgKeyType] = msg_type_;
        values[kNIMChatRoomMsgKeyAttach] = msg_attach_;
        values[kNIMChatRoomMsgKeyClientMsgid] = client_msg_id_;
        values[kNIMChatRoomMsgKeyLocalFilePath] = local_res_path_;
        values[kNIMChatRoomMsgKeyLocalResId] = local_res_id_;
        values[kNIMChatRoomMsgKeyBody] = msg_body_;
        values[kNIMChatRoomMsgKeyThirdPartyCBEXT] = third_party_callback_ext_;
        values[kNIMChatRoomMsgKeySubType] = sub_type_;
        values[kNIMChatRoomMsgKeyAntiSpamRes] = anti_spam_res_;
        values[kNIMChatRoomMsgKeyNotifyTags] = notify_tags_;
        msg_setting_.ToJsonValue(values);
        return values;
    }
};

/** @brief 获取聊天室成员参数 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomGetMembersParameters {
    /// 成员类型
    NIMChatRoomGetMemberType type_;
    /// 成员时间戳偏移量
    int64_t timestamp_offset_;
    /// 数量
    int limit_;

    /** 构造函数 */
    ChatRoomGetMembersParameters()
        : timestamp_offset_(0)
        , limit_(0) {}

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return string Json Value字符串
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomGetMembersKeyType] = type_;
        values[kNIMChatRoomGetMembersKeyOffset] = timestamp_offset_;
        values[kNIMChatRoomGetMembersKeyLimit] = limit_;
        return nim::GetJsonStringWithNoStyled(values);
    }
};

/** @brief 根据 tag 获取聊天室成员参数 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomGetMembersByTagParameters {
    /// 成员 tag
    std::string tag_;
    /// 成员时间戳偏移量
    int64_t timestamp_offset_;
    /// 数量
    int limit_;

    /** 构造函数 */
    ChatRoomGetMembersByTagParameters()
        : timestamp_offset_(0)
        , limit_(0) {}

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return string Json Value字符串
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomGetMembersKeyTag] = tag_;
        values[kNIMChatRoomGetMembersKeyOffset] = timestamp_offset_;
        values[kNIMChatRoomGetMembersKeyLimit] = limit_;
        return nim::GetJsonStringWithNoStyled(values);
    }
};

/** @brief 获取聊天室消息历史参数 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomGetMsgHistoryParameters {
    /// 开始时间,单位毫秒
    int64_t start_timetag_;
    /// 本次返回的消息数量
    int limit_;
    /// 是否反向查询
    bool reverse_;
    /// 类型
    std::vector<NIMChatRoomMsgType> msg_types_;
    /** 构造函数 */
    ChatRoomGetMsgHistoryParameters()
        : start_timetag_(0)
        , limit_(0)
        , reverse_(false) {
        if (kMsg_Types_List.empty()) {
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeText);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeImage);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeAudio);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeVideo);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeLocation);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeNotification);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeFile);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeRobot);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeTips);
            kMsg_Types_List.emplace_back(kNIMChatRoomMsgTypeCustom);
        }
        msg_types_.assign(kMsg_Types_List.begin(), kMsg_Types_List.end());
    }
    // 考虑到兼容以前版本，只提供删除类型接口，如果所有类型都被删除，会添加Unknown类型以区别之前的版本
    void RemoveMessageType(NIMChatRoomMsgType type) {
        auto it = std::find_if(msg_types_.begin(), msg_types_.end(), [&](const NIMChatRoomMsgType& item) {
            return item == type;
        });
        if (it != msg_types_.end())
            msg_types_.erase(it);
        if (msg_types_.empty())
            msg_types_.emplace_back(kNIMChatRoomMsgTypeUnknown);
    }
    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return string Json Value字符串
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomGetMsgHistoryKeyStartTime] = start_timetag_;
        values[kNIMChatRoomGetMsgHistoryKeyLimit] = limit_;
        values[kNIMChatRoomGetMsgHistoryKeyReverse] = reverse_;
        auto it = msg_types_.begin();
        while (it != msg_types_.end()) {
            values[kNIMChatRoomGetMsgHistoryKeyMsgtypes].append(nim_cpp_wrapper_util::Json::Value(*it));
            it++;
        }
        return nim::GetJsonStringWithNoStyled(values);
    }

private:
    static std::vector<NIMChatRoomMsgType> kMsg_Types_List;
};

/** @brief 设置聊天室成员身份标识参数 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomSetMemberAttributeParameters {
    /// 成员ID
    std::string account_id_;
    /// 身份标识
    NIMChatRoomMemberAttribute attribute_;
    /// true:是,false:否
    bool opt_;
    /// 通知的扩展字段, 必须为可以解析为Json的非格式化的字符串
    std::string notify_ext_;

    /** 构造函数 */
    ChatRoomSetMemberAttributeParameters()
        : level_(0) {}

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return string Json Value字符串
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomSetMemberAttributeKeyAccoutID] = account_id_;
        values[kNIMChatRoomSetMemberAttributeKeyAttribute] = attribute_;
        values[kNIMChatRoomSetMemberAttributeKeyOpt] = opt_;
        values[kNIMChatRoomSetMemberAttributeKeyNotifyExt] = notify_ext_;
        return nim::GetJsonStringWithNoStyled(values);
    }

private:
    /// 暂时不支持
    int level_;
};

/** @brief 聊天室成员信息 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomMemberInfo {
    /// 聊天室id
    int64_t room_id_;
    /// 成员账号
    std::string account_id_;
    /// 聊天室成员登录时指定的 tag 信息
    std::string tags_;
    /// 成员类型, -2:未设置;-1:受限用户; 0:普通;1:创建者;2:管理员;3:临时用户,非固定成员;4:匿名非注册用户,非云信注册用户
    int type_;
    /// 成员级别: >=0表示用户开发者可以自定义的级别
    int level_;
    /// 聊天室内的昵称字段,预留字段, 可从Uinfo中取
    std::string nick_;
    /// 聊天室内的头像,预留字段, 可从Uinfo中取icon
    std::string avatar_;
    /// 开发者扩展字段, 长度限制2k, 必须为可以解析为json的非格式化的字符串
    std::string ext_;
    /// 聊天室成员登录时指定的 notify_tags 信息
    std::string notify_tags_;
    /// 成员是否处于在线状态, 仅特殊成员才可能离线, 对游客/匿名用户而言只能是在线
    NIMChatRoomOnlineState state_;
    /// 是否是普通游客类型,0:不是游客,1:是游客; 游客身份在聊天室中没有持久化, 只有在线时才会有内存状态
    NIMChatRoomGuestFlag guest_flag_;
    /// 进入聊天室的时间点,对于离线成员该字段为空
    int64_t enter_timetag_;
    /// 是黑名单
    bool is_blacklist_;
    /// 是禁言用户
    bool is_muted_;
    /// 记录有效标记位
    bool is_valid_;
    /// 固定成员的记录更新时间,用于固定成员列表的排列查询
    int64_t update_timetag_;
    /// 临时禁言
    bool temp_muted_;
    /// 临时禁言的解除时长,单位秒
    int64_t temp_muted_duration_;
    /** 构造函数 */
    ChatRoomMemberInfo()
        : room_id_(0)
        , type_(-2)
        , level_(0)
        , state_(kNIMChatRoomOnlineStateOffline)
        , guest_flag_(kNIMChatRoomGuestFlagGuest)
        , enter_timetag_(0)
        , is_blacklist_(false)
        , is_muted_(false)
        , is_valid_(false)
        , update_timetag_(0)
        , temp_muted_(false)
        , temp_muted_duration_(0) {}

    /** 构造函数 */
    void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value& value) {
        if (value.isMember(kNIMChatRoomMemberInfoKeyRoomID))
            room_id_ = value[kNIMChatRoomMemberInfoKeyRoomID].asUInt64();
        if (value.isMember(kNIMChatRoomMemberInfoKeyAccID))
            account_id_ = value[kNIMChatRoomMemberInfoKeyAccID].asString();
        if (value.isMember(kNIMChatRoomMemberInfoKeyType))
            type_ = value[kNIMChatRoomMemberInfoKeyType].asInt();
        if (value.isMember(kNIMChatRoomMemberInfoKeyLevel))
            level_ = value[kNIMChatRoomMemberInfoKeyLevel].asInt();
        if (value.isMember(kNIMChatRoomMemberInfoKeyNick))
            nick_ = value[kNIMChatRoomMemberInfoKeyNick].asString();
        if (value.isMember(kNIMChatRoomMemberInfoKeyAvatar))
            avatar_ = value[kNIMChatRoomMemberInfoKeyAvatar].asString();
        if (value.isMember(kNIMChatRoomMemberInfoKeyExt))
            ext_ = value[kNIMChatRoomMemberInfoKeyExt].asString();
        if (value.isMember(kNIMChatRoomMemberInfoKeyOnlineState))
            state_ = (NIMChatRoomOnlineState)value[kNIMChatRoomMemberInfoKeyOnlineState].asInt();
        if (value.isMember(kNIMChatRoomMemberInfoKeyGuestFlag))
            guest_flag_ = (NIMChatRoomGuestFlag)value[kNIMChatRoomMemberInfoKeyGuestFlag].asInt();
        if (value.isMember(kNIMChatRoomMemberInfoKeyEnterTimetag))
            enter_timetag_ = value[kNIMChatRoomMemberInfoKeyEnterTimetag].asUInt64();
        if (value.isMember(kNIMChatRoomMemberInfoKeyBlacklist))
            is_blacklist_ = value[kNIMChatRoomMemberInfoKeyBlacklist].asInt() == 1;
        if (value.isMember(kNIMChatRoomMemberInfoKeyMuted))
            is_muted_ = value[kNIMChatRoomMemberInfoKeyMuted].asInt() == 1;
        if (value.isMember(kNIMChatRoomMemberInfoKeyValid))
            is_valid_ = value[kNIMChatRoomMemberInfoKeyValid].asInt() == 1;
        if (value.isMember(kNIMChatRoomMemberInfoKeyUpdateTimetag))
            update_timetag_ = value[kNIMChatRoomMemberInfoKeyUpdateTimetag].asUInt64();
        if (value.isMember(kNIMChatRoomMemberInfoKeyTempMute))
            temp_muted_ = value[kNIMChatRoomMemberInfoKeyTempMute].asInt() == 1;
        if (value.isMember(kNIMChatRoomMemberInfoKeyTempMuteRestDuration))
            temp_muted_duration_ = value[kNIMChatRoomMemberInfoKeyTempMuteRestDuration].asInt64();
        if (value.isMember(kNIMChatRoomMemberInfoKeyTag))
            tags_ = value[kNIMChatRoomMemberInfoKeyTag].asString();
        if (value.isMember(kNIMChatRoomMemberInfoKeyNotifyTags))
            notify_tags_ = value[kNIMChatRoomMemberInfoKeyNotifyTags].asString();
    }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return void
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomMemberInfoKeyRoomID] = room_id_;
        values[kNIMChatRoomMemberInfoKeyAccID] = account_id_;
        values[kNIMChatRoomMemberInfoKeyTag] = tags_;
        values[kNIMChatRoomMemberInfoKeyType] = type_;
        values[kNIMChatRoomMemberInfoKeyLevel] = level_;
        values[kNIMChatRoomMemberInfoKeyNick] = nick_;
        values[kNIMChatRoomMemberInfoKeyAvatar] = avatar_;
        values[kNIMChatRoomMemberInfoKeyExt] = ext_;
        values[kNIMChatRoomMemberInfoKeyNotifyTags] = notify_tags_;
        values[kNIMChatRoomMemberInfoKeyOnlineState] = state_;
        values[kNIMChatRoomMemberInfoKeyGuestFlag] = guest_flag_;
        values[kNIMChatRoomMemberInfoKeyEnterTimetag] = enter_timetag_;
        values[kNIMChatRoomMemberInfoKeyBlacklist] = is_blacklist_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyMuted] = is_muted_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyValid] = is_valid_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyUpdateTimetag] = update_timetag_;
        values[kNIMChatRoomMemberInfoKeyTempMute] = temp_muted_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyTempMuteRestDuration] = temp_muted_duration_;
        return nim::GetJsonStringWithNoStyled(values);
    }

    /** @fn nim_cpp_wrapper_util::Json::Value ToJsonObject() const
     * @brief 组装Json Value
     * @return nim_cpp_wrapper_util::Json::Value
     */
    nim_cpp_wrapper_util::Json::Value ToJsonObject() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMChatRoomMemberInfoKeyRoomID] = room_id_;
        values[kNIMChatRoomMemberInfoKeyAccID] = account_id_;
        values[kNIMChatRoomMemberInfoKeyTag] = tags_;
        values[kNIMChatRoomMemberInfoKeyType] = type_;
        values[kNIMChatRoomMemberInfoKeyLevel] = level_;
        values[kNIMChatRoomMemberInfoKeyNick] = nick_;
        values[kNIMChatRoomMemberInfoKeyAvatar] = avatar_;
        values[kNIMChatRoomMemberInfoKeyExt] = ext_;
        values[kNIMChatRoomMemberInfoKeyNotifyTags] = notify_tags_;
        values[kNIMChatRoomMemberInfoKeyOnlineState] = state_;
        values[kNIMChatRoomMemberInfoKeyGuestFlag] = guest_flag_;
        values[kNIMChatRoomMemberInfoKeyEnterTimetag] = enter_timetag_;
        values[kNIMChatRoomMemberInfoKeyBlacklist] = is_blacklist_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyMuted] = is_muted_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyValid] = is_valid_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyUpdateTimetag] = update_timetag_;
        values[kNIMChatRoomMemberInfoKeyTempMute] = temp_muted_ ? 1 : 0;
        values[kNIMChatRoomMemberInfoKeyTempMuteRestDuration] = temp_muted_duration_;
        return values;
    }
};

/** @brief 聊天室麦序队列元素 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomQueueElement {
    /// 元素的UniqKey,长度限制128字节
    std::string key_;
    /// 元素的内容，长度限制4096字节
    std::string value_;
};

/** @brief 聊天室更新标签 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomUpdateTagsInfo {
    /// 标签
    std::list<std::string> tags_;
    /// 更新标签的通知的目标标签，是一个标签表达式
    std::string notify_target_tags_;
    /// 1表示需要通知，如果需要通知，则会产生一条通知
    int need_notify_{0};
    /// 通知扩展字段
    std::string ext_;
};

/** @brief 聊天室麦序队列 */
typedef std::list<ChatRoomQueueElement> ChatRoomQueue;

/** @brief 聊天室退出时的信息 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API NIMChatRoomExitReasonInfo {
    /// string 附加信息长度限制2048字节
    std::string notify_ext_;
    /// enum 退出原因的代码
    NIMChatRoomExitReason code_;
    operator NIMChatRoomExitReason() const { return code_; }
};

/** 重载符号= */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool operator==(const NIMChatRoomExitReasonInfo& info, NIMChatRoomExitReason code);

/** @fn bool ParseChatRoomEnterCallbackResultInfo(const std::string& result, ChatRoomInfo& room_info, ChatRoomMemberInfo& my_info)
 * @brief 解析聊天室登录结果
 * @param[in] result
 * @param[out] room_info
 * @param[out] my_info
 * @return bool 解析成功 或失败
 */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool ParseChatRoomEnterCallbackResultInfo(const std::string& result,
    ChatRoomInfo& room_info,
    ChatRoomMemberInfo& my_info);

/** @fn bool ParseChatRoomMemberInfos(const std::string& infos_json_str, std::list<ChatRoomMemberInfo>& infos)
 * @brief 解析聊天室成员信息
 * @param[in] infos_json_str
 * @param[out] infos
 * @return bool 解析成功 或失败
 */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool ParseChatRoomMemberInfos(const std::string& infos_json_str, std::list<ChatRoomMemberInfo>& infos);

/** @fn bool ParseChatRoomMsgs(const std::string& msgs_json_str, std::list<ChatRoomMessage>& msgs)
 * @brief 解析聊天室成员信息
 * @param[in] msgs_json_str
 * @param[out] msgs
 * @return bool 解析成功 或失败
 */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool ParseChatRoomMsgs(const std::string& msgs_json_str, std::list<ChatRoomMessage>& msgs);

/** @brief 机器人信息 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API RobotInfo {
public:
    /** 设置机器人云信id */
    void SetAccid(const std::string& accid) { robot_info_[kNIMRobotInfoKeyAccid] = accid; }

    /** 获取机器人云信id */
    std::string GetAccid() const { return robot_info_[kNIMRobotInfoKeyAccid].asString(); }

    /** 设置机器人名字 */
    void SetName(const std::string& name) { robot_info_[kNIMRobotInfoKeyName] = name; }

    /** 获取机器人名字 */
    std::string GetName() const { return robot_info_[kNIMRobotInfoKeyName].asString(); }

    /** 设置机器人头像 */
    void SetIcon(const std::string& icon) { robot_info_[kNIMRobotInfoKeyIcon] = icon; }

    /** 获取机器人头像 */
    std::string GetIcon() const { return robot_info_[kNIMRobotInfoKeyIcon].asString(); }

    /** 设置机器人介绍 */
    void SetIntro(const std::string& intro) { robot_info_[kNIMRobotInfoKeyIntro] = intro; }

    /** 获取机器人介绍 */
    std::string GetIntro() const { return robot_info_[kNIMRobotInfoKeyIntro].asString(); }

    /** 设置机器人波特平台ID */
    void SetRobotID(const std::string& id) { robot_info_[kNIMRobotInfoKeyRobotId] = id; }

    /** 获取机器人波特平台ID */
    std::string GetRobotID() const { return robot_info_[kNIMRobotInfoKeyRobotId].asString(); }

    /** 设置机器人创建时间 */
    void SetCreateTime(const uint64_t time) { robot_info_[kNIMRobotInfoKeyCreateTime] = time; }

    /** 获取机器人创建时间 */
    uint64_t GetCreateTime() const { return robot_info_[kNIMRobotInfoKeyCreateTime].asUInt64(); }

    /** 设置机器人更新时间 */
    void SetUpdateTime(const uint64_t time) { robot_info_[kNIMRobotInfoKeyUpdateTime] = time; }

    /** 获取机器人更新时间 */
    uint64_t GetUpdateTime() const { return robot_info_[kNIMRobotInfoKeyUpdateTime].asUInt64(); }

private:
    nim_cpp_wrapper_util::Json::Value robot_info_;
};

/// 机器人信息
typedef std::list<RobotInfo> RobotInfos;

/** @fn bool ParseRobotInfosStringToRobotInfos(const std::string& infos_json, RobotInfos &infos)
 * @brief 解析机器人信息
 * @param[in] infos_json 机器人信息（Json Value数据字符串）
 * @param[out] infos 机器人信息
 * @return bool 解析成功或失败
 */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool ParseRobotInfosStringToRobotInfos(const std::string& infos_json, RobotInfos& infos);

/** @fn bool ParseRobotInfoStringToRobotInfo(const std::string &info_json, RobotInfo &info)
 * @brief 解析机器人信息
 * @param[in] info_json 机器人信息
 * @param[out] info 机器人信息
 * @return bool 解析成功或失败
 */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool ParseRobotInfoStringToRobotInfo(const std::string& info_json, RobotInfo& info);

typedef ChatRoomQueueElement ChatRoomMember;
/** @brief 聊天室批量更新成员 */
struct NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API ChatRoomBatchMembers {
    std::map<std::string, std::string> members_values_;
    /** 构造函数 */
    ChatRoomBatchMembers() { members_values_.clear(); }
    explicit ChatRoomBatchMembers(const std::map<std::string, std::string>& members)
        : members_values_(members) {}

    void ParseFromJsonValue(const nim_cpp_wrapper_util::Json::Value& json_str) { assert(false); }

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return void
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        int i = 0;
        for (auto it = members_values_.begin(); it != members_values_.end(); ++it) {
            values[i][kNIMChatRoomQueueElementKey] = it->first.c_str();
            values[i][kNIMChatRoomQueueElementValue] = it->second.c_str();
            i++;
        }
        return nim::GetJsonStringWithNoStyled(values);
    }
};

/** @fn bool ParseBatchInfosStringToNotMembers(const std::string &infos_json, std::list<std::string> &lst_members)
 * @brief 解析成员列表
 * @param[in] info_json 成员列表信息 json格式字符串
 * @param[out] lst_members 成员列表
 * @return bool 解析成功或失败
 */
NIM_CHATROOM_SDK_CPPWRAPPER_DLL_API bool ParseBatchInfosStringToNotMembers(const std::string& infos_json, std::list<std::string>& lst_members);

}  // namespace nim_chatroom

#endif  //_NIM_CHATROOM_SDK_CPP_HELPER_H_
