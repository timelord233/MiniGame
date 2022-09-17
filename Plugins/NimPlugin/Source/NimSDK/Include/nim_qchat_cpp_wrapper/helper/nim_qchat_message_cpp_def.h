/**
 * @file nim_qchat_message_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_MESSAGE_CPP_DEF_H__
#define __NIM_QCHAT_MESSAGE_CPP_DEF_H__

#include <iostream>
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_message_def.h"

namespace nim_qchat {

/// @struct IQChatAttachInterface
struct IQChatAttachInterface {
    IQChatAttachInterface() = default;
    virtual ~IQChatAttachInterface() {}
    virtual void SetRawData(const std::string& raw_data){};
    virtual std::string GetRawData() const { return ""; };
    virtual bool IsFileBased() const { return false; };
};

struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatDefaultAttach : public IQChatAttachInterface {
    QChatDefaultAttach() = default;
    QChatDefaultAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatDefaultAttach(const NIMQChatDefaultAttach& c_param) { msg_attach = c_param.msg_attach ? c_param.msg_attach : ""; }
    const NIMQChatDefaultAttach ToCParam() {
        NIMQChatDefaultAttach c_param;
        c_param.msg_attach = const_cast<char*>(msg_attach.c_str());
        return c_param;
    }
    void SetRawData(const std::string& raw_data) { msg_attach = raw_data; };
    std::string GetRawData() const override { return msg_attach; }
    std::string msg_attach;
};

/** @struct QChatFileAttach 圈组文件消息附件定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatFileAttach : public IQChatAttachInterface {
public:
    QChatFileAttach() = default;
    QChatFileAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatFileAttach(const NIMQChatFileAttach& c_param) {
        file_path = c_param.file_path ? c_param.file_path : "";
        download_url = c_param.url ? c_param.url : "";
        hash = c_param.md5 ? c_param.md5 : "";
        extension = c_param.ext ? c_param.ext : "";
        name = c_param.name ? c_param.name : "";
    }
    const NIMQChatFileAttach ToCParam() const {
        NIMQChatFileAttach param;
        param.file_path = const_cast<char*>(file_path.c_str());
        param.url = const_cast<char*>(download_url.c_str());
        param.md5 = const_cast<char*>(hash.c_str());
        param.ext = const_cast<char*>(extension.c_str());
        param.name = const_cast<char*>(name.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatFilePath))
                file_path = values[kNIMQChatFilePath].asString();
            if (values.isMember(kNIMQChatMD5))
                hash = values[kNIMQChatMD5].asString();
            if (values.isMember(kNIMQChatName))
                name = values[kNIMQChatName].asString();
            if (values.isMember(kNIMQChatURL))
                download_url = values[kNIMQChatURL].asString();
            if (values.isMember(kNIMQChatExt))
                extension = values[kNIMQChatExt].asString();
        }
    };
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        ProcessFileFields(values);
        return nim::GetJsonStringWithNoStyled(values);
    }
    void ProcessFileFields(nim_cpp_wrapper_util::Json::Value& values) const {
        values[kNIMQChatFilePath] = file_path;
        values[kNIMQChatURL] = download_url;
        values[kNIMQChatMD5] = hash;
        values[kNIMQChatExt] = extension;
        values[kNIMQChatName] = name;
    }
    bool IsFileBased() const override { return true; }

    std::string name;
    std::string file_path;
    std::string hash;
    std::string download_url;
    std::string extension;
};

/** @struct QChatImageAttach 圈组图片消息附件定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatImageAttach : public QChatFileAttach {
    QChatImageAttach() = default;
    QChatImageAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatImageAttach(const NIMQChatImageAttach& c_param) {
        file_path = c_param.file_path ? c_param.file_path : "";
        width = c_param.width;
        height = c_param.height;
        download_url = c_param.url ? c_param.url : "";
        hash = c_param.md5 ? c_param.md5 : "";
        extension = c_param.ext ? c_param.ext : "";
        name = c_param.name ? c_param.name : "";
    }
    const NIMQChatImageAttach ToCParam() const {
        NIMQChatImageAttach param;
        param.file_path = const_cast<char*>(file_path.c_str());
        param.width = width;
        param.height = height;
        param.url = const_cast<char*>(download_url.c_str());
        param.md5 = const_cast<char*>(hash.c_str());
        param.ext = const_cast<char*>(extension.c_str());
        param.name = const_cast<char*>(name.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        QChatFileAttach::SetRawData(raw_data);
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatWidth))
                width = values[kNIMQChatWidth].asInt();
            if (values.isMember(kNIMQChatHeight))
                height = values[kNIMQChatHeight].asInt();
        }
    }
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        ProcessFileFields(values);
        values[kNIMQChatWidth] = width;
        values[kNIMQChatHeight] = height;
        return nim::GetJsonStringWithNoStyled(values);
    }

    uint32_t width = 0;
    uint32_t height = 0;
};

/** @struct QChatAudioAttach 圈组音频消息附件定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAudioAttach : public QChatFileAttach {
    QChatAudioAttach() = default;
    QChatAudioAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatAudioAttach(const NIMQChatAudioAttach& c_param) {
        file_path = c_param.file_path ? c_param.file_path : "";
        duration = c_param.duration;
        download_url = c_param.url ? c_param.url : "";
        hash = c_param.md5 ? c_param.md5 : "";
        extension = c_param.ext ? c_param.ext : "";
        name = c_param.name ? c_param.name : "";
    }
    const NIMQChatAudioAttach ToCParam() const {
        NIMQChatAudioAttach param;
        param.file_path = const_cast<char*>(file_path.c_str());
        param.duration = duration;
        param.url = const_cast<char*>(download_url.c_str());
        param.md5 = const_cast<char*>(hash.c_str());
        param.ext = const_cast<char*>(extension.c_str());
        param.name = const_cast<char*>(name.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatDuration))
                duration = values[kNIMQChatDuration].asInt();
        }
    }
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        ProcessFileFields(values);
        values[kNIMQChatDuration] = duration;
        return nim::GetJsonStringWithNoStyled(values);
    }

    uint64_t duration = 0;
};

/** @struct QChatVideoAttach 圈组视频消息附件定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatVideoAttach : public QChatFileAttach {
    QChatVideoAttach() = default;
    QChatVideoAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatVideoAttach(const NIMQChatVideoAttach& c_param) {
        file_path = c_param.file_path ? c_param.file_path : "";
        duration = c_param.duration;
        width = c_param.width;
        height = c_param.height;
        download_url = c_param.url ? c_param.url : "";
        hash = c_param.md5 ? c_param.md5 : "";
        extension = c_param.ext ? c_param.ext : "";
        name = c_param.name ? c_param.name : "";
    }
    const NIMQChatVideoAttach ToCParam() const {
        NIMQChatVideoAttach param;
        param.file_path = const_cast<char*>(file_path.c_str());
        param.duration = duration;
        param.width = width;
        param.height = height;
        param.url = const_cast<char*>(download_url.c_str());
        param.md5 = const_cast<char*>(hash.c_str());
        param.ext = const_cast<char*>(extension.c_str());
        param.name = const_cast<char*>(name.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatDuration))
                duration = values[kNIMQChatDuration].asInt();
            if (values.isMember(kNIMQChatWidth))
                width = values[kNIMQChatWidth].asInt();
            if (values.isMember(kNIMQChatHeight))
                height = values[kNIMQChatHeight].asInt();
        }
    }
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        ProcessFileFields(values);
        values[kNIMQChatDuration] = duration;
        values[kNIMQChatWidth] = width;
        values[kNIMQChatHeight] = height;
        return nim::GetJsonStringWithNoStyled(values);
    }

    uint64_t duration = 0;
    uint32_t width = 0;
    uint32_t height = 0;
};

/** @struct QChatLocationAttach 圈组位置消息附件定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatLocationAttach : public IQChatAttachInterface {
    QChatLocationAttach() = default;
    QChatLocationAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatLocationAttach(const NIMQChatLocationAttach& c_param) {
        latitude = c_param.latitude;
        longitude = c_param.longitude;
        title = c_param.title ? c_param.title : "";
    }
    const NIMQChatLocationAttach ToCParam() const {
        NIMQChatLocationAttach param;
        param.latitude = latitude;
        param.longitude = longitude;
        param.title = const_cast<char*>(title.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatLatitude))
                latitude = values[kNIMQChatLatitude].asDouble();
            if (values.isMember(kNIMQChatLongitude))
                longitude = values[kNIMQChatLongitude].asDouble();
            if (values.isMember(kNIMQChatTitle))
                title = values[kNIMQChatTitle].asString();
        }
    }
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMQChatLatitude] = latitude;
        values[kNIMQChatLongitude] = longitude;
        values[kNIMQChatTitle] = title;
        return nim::GetJsonStringWithNoStyled(values);
    }

    double latitude = 0;
    double longitude = 0;
    std::string title;
};

struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatNotificationAttach : IQChatAttachInterface {
    QChatNotificationAttach() = default;
    QChatNotificationAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatNotificationAttach(const NIMQChatNotificationAttach& c_param) {
        id = c_param.id;
        data = c_param.data ? c_param.data : "";
    }
    const NIMQChatNotificationAttach ToCParam() const {
        NIMQChatNotificationAttach param;
        param.id = id;
        param.data = const_cast<char*>(data.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatID))
                id = values[kNIMQChatID].asInt();
            if (values.isMember(kNIMQChatData))
                data = values[kNIMQChatData].asString();
        }
    }
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMQChatID] = id;
        values[kNIMQChatData] = data;
        return nim::GetJsonStringWithNoStyled(values);
    }

    uint32_t id = 0;
    std::string data;
};

struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatTipsAttach : IQChatAttachInterface {
    QChatTipsAttach() = default;
    QChatTipsAttach(const std::string& raw_data) { SetRawData(raw_data); }
    QChatTipsAttach(const NIMQChatTipsAttach& c_param) {
        type = c_param.type;
        data = c_param.data ? c_param.data : "";
    }
    const NIMQChatTipsAttach ToCParam() const {
        NIMQChatTipsAttach param;
        param.type = type;
        param.data = const_cast<char*>(data.c_str());
        return param;
    }
    void SetRawData(const std::string& raw_data) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(raw_data, values)) {
            if (values.isMember(kNIMQChatType))
                type = values[kNIMQChatType].asInt();
            if (values.isMember(kNIMQChatData))
                data = values[kNIMQChatData].asString();
        }
    }
    std::string GetRawData() const override {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMQChatType] = type;
        values[kNIMQChatData] = data;
        return nim::GetJsonStringWithNoStyled(values);
    }

    uint32_t type = 0;
    std::string data;
};

/** @struct QChatMessageUpdateInfo 更新消息时需要指定的参数 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageUpdateInfo {
    /// 操作附言
    std::string postscript;
    /// 操作扩展字段
    std::string extension;
    /// 推送文案
    std::string push_content;
    /// 推送payload
    std::string push_payload;
    /// 环境变量，用于指向不同的抄送、第三方回调等配置
    std::string env;
    /// 是否需要抄送
    bool route_enable;
    // 以下字段仅在收到消息时有效
    std::string operator_id;
    uint32_t operator_client_type;
    QChatMessageUpdateInfo() = default;
    QChatMessageUpdateInfo(const NIMQChatMessageUpdateInfo& c_param) {
        postscript = c_param.postscript ? c_param.postscript : "";
        extension = c_param.extension ? c_param.extension : "";
        push_content = c_param.push_content ? c_param.push_content : "";
        push_payload = c_param.push_payload ? c_param.push_payload : "";
        env = c_param.env ? c_param.env : "";
        route_enable = c_param.route_enable;
        operator_id = c_param.operator_id ? c_param.operator_id : "";
        operator_client_type = c_param.operator_client_type;
    }
    const NIMQChatMessageUpdateInfo ToCParam() const {
        NIMQChatMessageUpdateInfo c_param = {};
        c_param.postscript = const_cast<char*>(postscript.c_str());
        c_param.extension = const_cast<char*>(extension.c_str());
        c_param.push_content = const_cast<char*>(push_content.c_str());
        c_param.push_payload = const_cast<char*>(push_payload.c_str());
        c_param.env = const_cast<char*>(env.c_str());
        c_param.route_enable = route_enable;
        c_param.operator_id = const_cast<char*>(operator_id.c_str());
        c_param.operator_client_type = operator_client_type;
        return c_param;
    }
};

/// @struct QChatMessageAntiSpamInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageAntiSpamInfo {
    /// 是否需要使用自定义反垃圾字段(即antiSpamContent), false:不需要, true:需要, 一般使用的情况是通用反垃圾转易盾
    bool use_custom_content{false};
    /// 单条消息是否使用易盾反垃圾, false:(在开通易盾的情况下)不过易盾反垃圾, 其他都是按照原来的规则
    bool anti_spam_using_yidun{true};
    /// 反垃圾内容, 开发者自定义的反垃圾字段, 如果提供了这个字段, 在过反垃圾时不会再使用body或者attach
    std::string anti_spam_content;
    /// 反垃圾业务ID, 对某些单条消息另外的反垃圾的业务ID
    std::string anti_spam_bussiness_id;
    /// 易盾check的回调URL
    std::string yidun_callback_url;
    /// 易盾反垃圾增强反作弊专属字段, 限制json, 长度限制1024
    std::string yidun_anti_cheating;
    /// 易盾反垃圾扩展字段, 限制json, 长度限制1024
    std::string yidun_anti_spam_ext;
    QChatMessageAntiSpamInfo() = default;
    QChatMessageAntiSpamInfo(const NIMQChatMessageAntiSpamInfo& c_param) {
        use_custom_content = c_param.use_custom_content;
        anti_spam_using_yidun = c_param.anti_spam_using_yidun;
        anti_spam_content = c_param.anti_spam_content ? c_param.anti_spam_content : "";
        anti_spam_bussiness_id = c_param.anti_spam_bussiness_id ? c_param.anti_spam_bussiness_id : "";
        yidun_callback_url = c_param.yidun_callback_url ? c_param.yidun_callback_url : "";
        yidun_anti_cheating = c_param.yidun_anti_cheating ? c_param.yidun_anti_cheating : "";
        yidun_anti_spam_ext = c_param.yidun_anti_spam_ext ? c_param.yidun_anti_spam_ext : "";
    }
    const NIMQChatMessageAntiSpamInfo ToCParam() const {
        NIMQChatMessageAntiSpamInfo c_param = {};
        c_param.use_custom_content = use_custom_content;
        c_param.anti_spam_using_yidun = anti_spam_using_yidun;
        c_param.anti_spam_content = const_cast<char*>(anti_spam_content.c_str());
        c_param.anti_spam_bussiness_id = const_cast<char*>(anti_spam_bussiness_id.c_str());
        c_param.yidun_callback_url = const_cast<char*>(yidun_callback_url.c_str());
        c_param.yidun_anti_cheating = const_cast<char*>(yidun_anti_cheating.c_str());
        c_param.yidun_anti_spam_ext = const_cast<char*>(yidun_anti_spam_ext.c_str());
        return c_param;
    }
};

/** @struct QChatMessageThreadInfo thread 消息结构信息 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageThreadInfo {
    /// 被回复的消息所有者 ID
    std::string reply_from_accid;
    /// 被回复消息得创建时间
    uint64_t reply_msg_timestamp = 0;
    /// 被回复消息得服务器消息 ID
    uint64_t reply_msg_server_id = 0;
    /// 被回复消息得客户端消息 ID
    std::string reply_msg_client_id;
    /// thread 根消息的所有者 ID
    std::string thread_root_accid;
    /// thread 根消息的创建时间
    uint64_t thread_root_msg_timestamp = 0;
    /// thread 根消息的服务器消息 ID
    uint64_t thread_root_msg_server_id = 0;
    /// thread 根消息的客户端消息 ID
    std::string thread_root_msg_client_id;
    QChatMessageThreadInfo() = default;
    QChatMessageThreadInfo(const NIMQChatMessageThreadInfo& c_param) {
        reply_from_accid = c_param.reply_from_accid ? c_param.reply_from_accid : "";
        reply_msg_timestamp = c_param.reply_msg_timestamp;
        reply_msg_server_id = c_param.reply_msg_server_id;
        reply_msg_client_id = c_param.reply_msg_client_id ? c_param.reply_msg_client_id : "";
        thread_root_accid = c_param.thread_root_accid ? c_param.thread_root_accid : "";
        thread_root_msg_timestamp = c_param.thread_root_msg_timestamp;
        thread_root_msg_server_id = c_param.thread_root_msg_server_id;
        thread_root_msg_client_id = c_param.thread_root_msg_client_id ? c_param.thread_root_msg_client_id : "";
    }
    const NIMQChatMessageThreadInfo ToCParam() const {
        NIMQChatMessageThreadInfo c_param = {};
        c_param.reply_from_accid = const_cast<char*>(reply_from_accid.c_str());
        c_param.reply_msg_timestamp = reply_msg_timestamp;
        c_param.reply_msg_server_id = reply_msg_server_id;
        c_param.reply_msg_client_id = const_cast<char*>(reply_msg_client_id.c_str());
        c_param.thread_root_accid = const_cast<char*>(thread_root_accid.c_str());
        c_param.thread_root_msg_timestamp = thread_root_msg_timestamp;
        c_param.thread_root_msg_server_id = thread_root_msg_server_id;
        c_param.thread_root_msg_client_id = const_cast<char*>(thread_root_msg_client_id.c_str());
        return c_param;
    }
};

/** @struct QChatMessageSend 发送消息时指定的参数 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageSend {
    /// 必填，消息所属的server id
    uint64_t server_id{0};
    /// 必填，消息所属的channel id
    uint64_t channel_id{0};
    /// 必填，消息类型
    NIMQChatMsgType msg_type{kNIMQChatMsgTypeUnknown};
    /// 可选, 消息子类型
    uint32_t msg_sub_type{0};
    /// 可选，消息内容
    std::string msg_body{""};
    /// 可选，消息附件
    std::shared_ptr<IQChatAttachInterface> msg_attach{std::make_shared<QChatDefaultAttach>()};
    /// 可选，消息扩展字段
    std::string msg_ext{""};
    /// 可选，消息重发时需要指定此参数
    std::string msg_id{""};
    /// 必填，重发标记，false:不是重发，true:是重发
    bool resend_flag{false};
    /// 可选，是否艾特所有人，false:否，true:是
    bool mention_all{false};
    /// 可选，被艾特的人的accid列表
    std::list<std::string> mention_accids{};
    /// 必填，该消息是否存储云端历史，0:不支持，1:支持
    bool history_enable{true};
    /// 可选，自定义的推送属性，限制json
    std::string push_payload{""};
    /// 可选，自定义的推送内容
    std::string push_content{""};
    /// 可选，是否需要推送, false: 不需要, true: 需要, 默认 false
    bool push_enable{false};
    /// 可选，是否需要消息计数, false: 不需要, true: 需要, 默认 true
    bool need_badge{true};
    /// 可选，是否需要推送昵称, false: 不需要, true: 需要, 默认 true
    bool need_push_nick{true};
    /// 可选，是否需要抄送, false: 不需要, true: 需要, 默认 true
    bool route_enable{true};
    /// 可选，thread 消息相关信息
    QChatMessageThreadInfo thread_info;
    /// 可选，反垃圾信息
    QChatMessageAntiSpamInfo anti_spam_info;
    /// 可选，环境变量
    std::string env;
    QChatMessageSend() = default;
    QChatMessageSend(const NIMQChatMessage& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        msg_type = c_param.msg_type;
        msg_sub_type = c_param.msg_sub_type;
        msg_body = c_param.msg_body;
        msg_attach = CreateAttach(c_param);
        msg_ext = c_param.msg_ext;
        msg_id = c_param.msg_id ? c_param.msg_id : "";
        resend_flag = c_param.resend_flag;
        mention_all = c_param.mention_all;
        if (c_param.mention_accids)
            nim::JsonArrayStringToList(c_param.mention_accids, mention_accids);
        history_enable = c_param.history_enable;
        push_payload = c_param.push_payload;
        push_content = c_param.push_content;
        push_enable = c_param.push_enable;
        need_badge = c_param.need_badge;
        need_push_nick = c_param.need_push_nick;
        route_enable = c_param.route_enable;
        thread_info = c_param.thread_info;
        anti_spam_info = c_param.anti_spam_info;
        env = c_param.env ? c_param.env : "";
    }
    const NIMQChatMessage ToCParam() const {
        NIMQChatMessage c_param = {};
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.msg_type = msg_type;
        c_param.msg_sub_type = msg_sub_type;
        c_param.msg_body = const_cast<char*>(msg_body.c_str());
        c_param.msg_ext = const_cast<char*>(msg_ext.c_str());
        c_param.msg_id = const_cast<char*>(msg_id.c_str());
        c_param.resend_flag = resend_flag;
        c_param.mention_all = mention_all;
        mention_accids_json_array_.clear();
        nim::StrListToJsonString(mention_accids, mention_accids_json_array_);
        c_param.mention_accids = const_cast<char*>(mention_accids_json_array_.c_str());
        c_param.history_enable = history_enable;
        c_param.push_payload = const_cast<char*>(push_payload.c_str());
        c_param.push_content = const_cast<char*>(push_content.c_str());
        c_param.push_enable = push_enable;
        c_param.need_badge = need_badge;
        c_param.need_push_nick = need_push_nick;
        c_param.route_enable = route_enable;
        c_param.from_accid = nullptr;
        c_param.from_device_id = nullptr;
        c_param.from_nick = nullptr;
        ParseAttach(msg_attach, c_param);
        c_param.thread_info = thread_info.ToCParam();
        c_param.anti_spam_info = anti_spam_info.ToCParam();
        c_param.env = const_cast<char*>(env.c_str());
        return c_param;
    }
    using AttachRawCreateFunc = std::function<std::shared_ptr<IQChatAttachInterface>(const std::string&)>;
    using AttachCreateFunc = std::function<std::shared_ptr<IQChatAttachInterface>(const NIMQChatMessage&)>;
    using AttachParseFunc = std::function<void(const std::shared_ptr<IQChatAttachInterface>&, NIMQChatMessage&)>;
    static std::map<NIMQChatMsgType, AttachRawCreateFunc> attach_raw_create_function_;
    static std::shared_ptr<IQChatAttachInterface> CreateAttachWithRawData(NIMQChatMsgType type, const std::string& raw_data) {
        auto iter = attach_raw_create_function_.find(type);
        if (iter != attach_raw_create_function_.end()) {
            return iter->second(raw_data);
        }
        return std::make_shared<QChatDefaultAttach>(raw_data);
    }

private:
    std::shared_ptr<IQChatAttachInterface> CreateAttach(const NIMQChatMessage& m) {
        auto iter = attach_create_functions_.find(m.msg_type);
        if (iter != attach_create_functions_.end()) {
            return iter->second(m);
        }
        return std::make_shared<QChatDefaultAttach>(m.default_attach.msg_attach == nullptr ? "" : m.default_attach.msg_attach);
    }
    void ParseAttach(const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp) const {
        if (!p) {
            return;
        }
        auto iter = attach_parse_functions_.find(cp.msg_type);
        if (iter != attach_parse_functions_.end()) {
            iter->second(p, cp);
        } else {
            cp.default_attach = std::dynamic_pointer_cast<QChatDefaultAttach>(p)->ToCParam();
        }
    }
    template <typename ATTACH_TYPE>
    static std::shared_ptr<ATTACH_TYPE> GetOriginAttach(const std::shared_ptr<IQChatAttachInterface>& p) {
        auto attach = std::dynamic_pointer_cast<ATTACH_TYPE>(p);
        if (attach) {
            return attach;
        } else {
            return std::make_shared<ATTACH_TYPE>(p->GetRawData());
        }
    }
    // clang-format off
    std::map<NIMQChatMsgType, AttachCreateFunc> attach_create_functions_ = {
        { kNIMQChatMsgTypeText, [](const NIMQChatMessage& m) { return std::make_shared<QChatDefaultAttach>(m.default_attach); } },
        { kNIMQChatMsgTypeImage, [](const NIMQChatMessage& m) { return std::make_shared<QChatImageAttach>(m.image_attach); } },
        { kNIMQChatMsgTypeAudio, [](const NIMQChatMessage& m) { return std::make_shared<QChatAudioAttach>(m.audio_attach); } },
        { kNIMQChatMsgTypeVideo, [](const NIMQChatMessage& m) { return std::make_shared<QChatVideoAttach>(m.video_attach); } },
        { kNIMQChatMsgTypeFile, [](const NIMQChatMessage& m) { return std::make_shared<QChatFileAttach>(m.file_attach); } },
        { kNIMQChatMsgTypeLocation, [](const NIMQChatMessage& m) { return std::make_shared<QChatLocationAttach>(m.location_attach); } },
        { kNIMQChatMsgTypeNotification, [](const NIMQChatMessage& m) { return std::make_shared<QChatNotificationAttach>(m.notification_attach); } },
        { kNIMQChatMsgTypeTips, [](const NIMQChatMessage& m) { return std::make_shared<QChatTipsAttach>(m.tips_attach); } }
    };

    std::map<NIMQChatMsgType, AttachParseFunc> attach_parse_functions_ = {
        {kNIMQChatMsgTypeText, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.default_attach = GetOriginAttach<QChatDefaultAttach>(p)->ToCParam(); } },
        {kNIMQChatMsgTypeImage, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.image_attach = GetOriginAttach<QChatImageAttach>(p)->ToCParam(); } }, 
        {kNIMQChatMsgTypeAudio, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.audio_attach = GetOriginAttach<QChatAudioAttach>(p)->ToCParam(); } },
        {kNIMQChatMsgTypeVideo, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.video_attach = GetOriginAttach<QChatVideoAttach>(p)->ToCParam(); } },
        {kNIMQChatMsgTypeFile, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.file_attach = GetOriginAttach<QChatFileAttach>(p)->ToCParam(); } },
        {kNIMQChatMsgTypeLocation, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.location_attach = GetOriginAttach<QChatLocationAttach>(p)->ToCParam(); } },
        {kNIMQChatMsgTypeNotification, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.notification_attach = GetOriginAttach<QChatNotificationAttach>(p)->ToCParam(); } },
        {kNIMQChatMsgTypeTips, [](const std::shared_ptr<IQChatAttachInterface>& p, NIMQChatMessage& cp)
            { cp.tips_attach = GetOriginAttach<QChatTipsAttach>(p)->ToCParam(); } }
    };
    // clang-format on

protected:
    mutable std::string mention_accids_json_array_;
};

/// @struct QChatMessageUpdateContent
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageUpdateContent {
    /// 消息状态
    NIMQChatMessageStatus status;
    /// 消息内容
    std::string msg_body;
    /// 消息扩展字段
    std::string msg_ext;
    QChatMessageUpdateContent() = default;
    QChatMessageUpdateContent(const NIMQChatMessageUpdateContent& c_param) {
        status = c_param.status;
        msg_body = c_param.msg_body;
        msg_ext = c_param.msg_ext;
    }
    const NIMQChatMessageUpdateContent ToCParam() const {
        NIMQChatMessageUpdateContent c_param;
        c_param.status = status;
        c_param.msg_body = const_cast<char*>(msg_body.c_str());
        c_param.msg_ext = const_cast<char*>(msg_ext.c_str());
        return c_param;
    }
};

/// @struct QChatMessageUpdateOpeInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageUpdateOpeInfo {
    /// 操作者账号
    std::string operator_id;
    /// 操作者客户端类型
    uint32_t operator_client_type;
    /// 操作附言
    std::string postscript;
    /// 操作扩展字段
    std::string extension;
    /// 推送文案
    std::string push_content;
    /// 推送payload
    std::string push_payload;
    QChatMessageUpdateOpeInfo() = default;
    QChatMessageUpdateOpeInfo(const NIMQChatMessageUpdateOpeInfo& c_param) {
        operator_id = c_param.operator_id;
        operator_client_type = c_param.operator_client_type;
        postscript = c_param.postscript;
        extension = c_param.extension;
        push_content = c_param.push_content;
        push_payload = c_param.push_payload;
    }
    const NIMQChatMessageUpdateOpeInfo ToCParam() const {
        NIMQChatMessageUpdateOpeInfo c_param;
        c_param.operator_id = const_cast<char*>(operator_id.c_str());
        c_param.operator_client_type = operator_client_type;
        c_param.postscript = const_cast<char*>(postscript.c_str());
        c_param.extension = const_cast<char*>(extension.c_str());
        c_param.push_content = const_cast<char*>(push_content.c_str());
        c_param.push_payload = const_cast<char*>(push_payload.c_str());
        return c_param;
    }
};

/// @struct QChatMessage 接收到的完整消息体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessage : public QChatMessageSend {
    // 以下字段仅在收到消息时有效
    /// 消息状态
    NIMQChatMessageStatus status{kMsgStatusNormal};
    /// 更新消息时必填，消息服务器端id
    uint64_t msg_server_id{0};
    /// 消息发送者的accid
    std::string from_accid{""};
    /// 消息发送者的客户端类型
    uint32_t from_client_type{0};
    /// 消息发送者的设备id
    std::string from_device_id{""};
    /// 消息发送者的昵称
    std::string from_nick{""};
    /// 更新消息时必填，消息创建的时间戳，以服务器返回信息为准
    uint64_t timestamp{0};
    /// 消息更新时间戳
    uint64_t update_timestamp{0};
    /// 消息下发原因
    NIMQChatMessageNotifyReason notify_reason{kMessageNotifyReasonUnkonw};
    /// 是否被反垃圾
    bool is_anti_spamed{false};
    /// 反垃圾结果
    std::string anti_spam_result;
    /// 可选，第三方回调扩展字段
    std::string callback_ext;
    /// 上次消息变更内容
    QChatMessageUpdateContent update_content;
    /// 上次消息变更操作信息
    QChatMessageUpdateOpeInfo update_ope_info;
    QChatMessage() = default;
    QChatMessage(const NIMQChatMessage& c_param)
        : QChatMessageSend(c_param) {
        // fill by server
        status = c_param.status;
        msg_server_id = c_param.msg_server_id;
        from_accid = c_param.from_accid ? c_param.from_accid : "";
        from_client_type = c_param.from_client_type;
        from_device_id = c_param.from_device_id ? c_param.from_device_id : "";
        from_nick = c_param.from_nick ? c_param.from_nick : "";
        timestamp = c_param.timestamp;
        update_timestamp = c_param.update_timestamp;
        notify_reason = c_param.notify_reason;
        is_anti_spamed = c_param.is_anti_spamed;
        callback_ext = c_param.callback_ext ? c_param.callback_ext : "";
        anti_spam_result = c_param.anti_spam_result ? c_param.anti_spam_result : "";
        update_content = c_param.update_content;
        update_ope_info = c_param.update_ope_info;
    }
    const NIMQChatMessage ToCParam() const {
        auto c_param = QChatMessageSend::ToCParam();
        c_param.status = status;
        c_param.msg_server_id = msg_server_id;
        c_param.from_accid = const_cast<char*>(from_accid.c_str());
        c_param.from_client_type = from_client_type;
        c_param.from_device_id = const_cast<char*>(from_device_id.c_str());
        c_param.from_nick = const_cast<char*>(from_nick.c_str());
        c_param.timestamp = timestamp;
        c_param.update_timestamp = update_timestamp;
        c_param.notify_reason = notify_reason;
        c_param.is_anti_spamed = is_anti_spamed;
        c_param.callback_ext = const_cast<char*>(callback_ext.c_str());
        c_param.anti_spam_result = const_cast<char*>(anti_spam_result.c_str());
        c_param.update_content = update_content.ToCParam();
        c_param.update_ope_info = update_ope_info.ToCParam();
        return c_param;
    }
};

/// @struct QChatRecvMsgResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRecvMsgResp {
    /// 消息体
    QChatMessage message{};
    QChatRecvMsgResp() = default;
    QChatRecvMsgResp(const NIMQChatRecvMsgResp& c_resp) { message = c_resp.message; }
};

/// @struct QChatMsgUpdatedResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMsgUpdatedResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 消息更新信息
    QChatMessageUpdateInfo update_info{};
    /// 消息体
    QChatMessage message{};
    QChatMsgUpdatedResp() = default;
    QChatMsgUpdatedResp(const NIMQChatMsgUpdatedResp& c_resp) {
        update_info = c_resp.update_info;
        message = c_resp.message;
    }
};

/// @struct QChatSendMessageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSendMessageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 消息体
    QChatMessage message{};
    QChatSendMessageResp() = default;
    QChatSendMessageResp(const NIMQChatSendMessageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess && c_resp.res_code != kNIMLocalResMsgAccessDenied)
            return;
        message = c_resp.message;
    }
    const NIMQChatSendMessageResp ToCParam() const {
        NIMQChatSendMessageResp c_response;
        c_response.message = message.ToCParam();
        c_response.res_code = res_code;
        return c_response;
    }
};

/// @struct QChatReplyMessageResp
using QChatReplyMessageResp = QChatSendMessageResp;

/// @struct QChatUpdateMessageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateMessageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 消息体
    QChatMessage message{};
    QChatUpdateMessageResp() = default;
    QChatUpdateMessageResp(const NIMQChatUpdateMessageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess && c_resp.res_code != kNIMLocalResMsgAccessDenied)
            return;
        message = c_resp.message;
    }
    const NIMQChatUpdateMessageResp ToCParam() const {
        NIMQChatUpdateMessageResp c_response;
        c_response.message = message.ToCParam();
        c_response.res_code = res_code;
        return c_response;
    }
};

/// @struct QChatGetMessagesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMessagesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 消息列表
    std::list<QChatMessage> messages{};
    QChatGetMessagesResp() = default;
    QChatGetMessagesResp(const NIMQChatGetMessagesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.messages_count; i++) {
            messages.emplace_back(c_resp.messages[i]);
        }
    }
    const NIMQChatGetMessagesResp ToCParam() const {
        NIMQChatGetMessagesResp c_response;
        c_response.res_code = res_code;
        message_.clear();
        for (const auto& msg : messages) {
            message_.push_back(msg.ToCParam());
        }
        c_response.messages = const_cast<NIMQChatMessage*>(message_.data());
        c_response.messages_count = static_cast<uint32_t>(message_.size());
        return c_response;
    }

private:
    mutable std::vector<NIMQChatMessage> message_;
};

/// @struct QChatGetLastMessagesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetLastMessagesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 消息列表, key为channel_id
    std::map<uint64_t, QChatMessage> messages{};
    QChatGetLastMessagesResp() = default;
    QChatGetLastMessagesResp(const NIMQChatGetLastMessagesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.messages_count; i++) {
            messages.emplace(c_resp.messages[i].channel_id, c_resp.messages[i]);
        }
    }
    const NIMQChatGetLastMessagesResp ToCParam() const {
        NIMQChatGetLastMessagesResp c_response;
        c_response.res_code = res_code;
        message_.clear();
        for (auto&& iter : messages) {
            message_.push_back(iter.second.ToCParam());
        }
        c_response.messages = const_cast<NIMQChatMessage*>(message_.data());
        c_response.messages_count = static_cast<uint32_t>(message_.size());
        return c_response;
    }

private:
    mutable std::vector<NIMQChatMessage> message_;
};

/// @struct QChatGetMessagesCacheResp
using QChatGetMessagesCacheResp = QChatGetMessagesResp;

/// @struct QChatGetMessageHistoryByIdsResp
using QChatGetMessageHistoryByIdsResp = QChatGetMessagesResp;

/// @struct QChatGetReferMessagesResp
using QChatGetReferMessagesResp = QChatGetMessagesResp;

/// @struct QChatMarkMessageReadResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMarkMessageReadResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code = 0;
    /// 未读数信息
    NIMQChatUnreadInfo unread_info{};
    QChatMarkMessageReadResp() = default;
    QChatMarkMessageReadResp(const NIMQChatMarkMessageReadResp& c_resp) {
        res_code = c_resp.res_code;
        unread_info = c_resp.unread_info;
    }
    const NIMQChatMarkMessageReadResp ToCParam() const {
        NIMQChatMarkMessageReadResp c_response{};
        c_response.res_code = res_code;
        c_response.unread_info = unread_info;
        return c_response;
    }
};

/// @struct QChatGetThreadMessagesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetThreadMessagesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// thread 消息元信息
    NIMQChatThreadMessageMetaInfo meta_info;
    /// 消息体
    QChatMessage root_message;
    /// 消息列表
    std::list<QChatMessage> messages;
    QChatGetThreadMessagesResp() = default;
    QChatGetThreadMessagesResp(const NIMQChatGetThreadMessagesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        meta_info = c_resp.meta_info;
        root_message = c_resp.root_message;
        for (size_t i = 0; i < c_resp.messages_count; i++) {
            messages.emplace_back(c_resp.messages[i]);
        }
    }
    const NIMQChatGetThreadMessagesResp ToCParam() const {
        NIMQChatGetThreadMessagesResp c_response;
        c_response.meta_info = meta_info;
        c_response.meta_info.thread_msg_server_id = root_message.msg_server_id;
        c_response.meta_info.thread_msg_timestamp = root_message.timestamp;
        c_response.root_message = root_message.ToCParam();
        messages_.clear();
        for (auto& message : messages)
            messages_.push_back(message.ToCParam());
        c_response.messages = const_cast<NIMQChatMessage*>(messages_.data());
        c_response.messages_count = messages_.size();
        c_response.res_code = res_code;
        return c_response;
    }

private:
    mutable std::vector<NIMQChatMessage> messages_;
};

/// @struct QChatGetThreadRootMessagesMetaResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetThreadRootMessagesMetaResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code = 0;
    /// thread 消息元信息
    std::vector<NIMQChatThreadMessageMetaInfo> meta_infos;
    QChatGetThreadRootMessagesMetaResp() = default;
    QChatGetThreadRootMessagesMetaResp(const NIMQChatGetThreadRootMessagesMetaResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.meta_info_count; i++) {
            meta_infos.emplace_back(c_resp.meta_infos[i]);
        }
    }
    const NIMQChatGetThreadRootMessagesMetaResp ToCParam() const {
        NIMQChatGetThreadRootMessagesMetaResp c_response;
        c_response.res_code = res_code;
        c_response.meta_infos = const_cast<NIMQChatThreadMessageMetaInfo*>(meta_infos.data());
        c_response.meta_info_count = meta_infos.size();
        return c_response;
    }
};

/// @struct QChatAddQuickCommentResp
using QChatAddQuickCommentResp = QChatBaseResp;

/// @struct QChatRemoveQuickCommentResp
using QChatRemoveQuickCommentResp = QChatBaseResp;

/// @struct QChatQuickCommentDetail
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatQuickCommentDetail {
    /// 表示评论类型
    uint64_t type;
    /// 表示这个评论的数量
    uint64_t count;
    /// 表示自己是否添加过这个标签
    bool include_yourself;
    /// 若干个添加过表情的 account ID
    std::list<std::string> accids;
    QChatQuickCommentDetail() = default;
    QChatQuickCommentDetail(const NIMQChatQuickCommentDetail& c_param) {
        type = c_param.type;
        count = c_param.count;
        include_yourself = c_param.include_yourself;
        for (size_t i = 0; i < c_param.account_count; i++) {
            accids.emplace_back(c_param.accids[i]);
        }
    }
    const NIMQChatQuickCommentDetail ToCParam() const {
        NIMQChatQuickCommentDetail detail;
        detail.type = type;
        detail.count = count;
        detail.include_yourself = include_yourself;
        accids_.clear();
        for (auto& account : accids)
            accids_.push_back(const_cast<char*>(account.c_str()));
        detail.accids = const_cast<char**>(accids_.data());
        detail.account_count = accids_.size();
        return detail;
    }

private:
    mutable std::vector<char*> accids_;
};

/// @struct QChatQuickCommentInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatQuickCommentInfo {
    /// 评论所在服务器
    uint64_t server_id;
    /// 评论所在频道
    uint64_t channel_id;
    /// 评论所属的消息服务器 ID
    uint64_t msg_server_id;
    /// 总的评论数量
    uint64_t count;
    /// 最后一次操作的时间
    uint64_t timestamp;
    /// 评论详情
    std::list<QChatQuickCommentDetail> details;
    QChatQuickCommentInfo() = default;
    QChatQuickCommentInfo(const NIMQChatQuickCommentInfo& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        msg_server_id = c_param.msg_server_id;
        count = c_param.count;
        timestamp = c_param.timestamp;
        for (size_t i = 0; i < c_param.detail_count; i++) {
            details.emplace_back(c_param.detail[i]);
        }
    }
    const NIMQChatQuickCommentInfo ToCParam() const {
        NIMQChatQuickCommentInfo info;
        info.server_id = server_id;
        info.channel_id = channel_id;
        info.msg_server_id = msg_server_id;
        info.count = count;
        info.timestamp = timestamp;
        detail_.clear();
        for (auto& d : details)
            detail_.push_back(d.ToCParam());
        info.detail = const_cast<NIMQChatQuickCommentDetail*>(detail_.data());
        info.detail_count = detail_.size();
        return info;
    }

private:
    mutable std::vector<NIMQChatQuickCommentDetail> detail_;
};

/// @struct QChatGetQuickCommentsResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetQuickCommentsResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 快捷评论列表
    std::list<QChatQuickCommentInfo> comments{};
    QChatGetQuickCommentsResp() = default;
    QChatGetQuickCommentsResp(const NIMQChatGetQuickCommentsResp& c_response) {
        res_code = c_response.res_code;
        if (c_response.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_response.comments_count; i++) {
            comments.emplace_back(c_response.comments[i]);
        }
    }
    const NIMQChatGetQuickCommentsResp ToCParam() const {
        NIMQChatGetQuickCommentsResp c_response;
        c_response.res_code = res_code;
        if (res_code != kNIMResSuccess)
            return c_response;
        comments_.clear();
        for (auto& comment : comments)
            comments_.push_back(comment.ToCParam());
        c_response.comments = const_cast<NIMQChatQuickCommentInfo*>(comments_.data());
        c_response.comments_count = comments_.size();
        return c_response;
    }

private:
    mutable std::vector<NIMQChatQuickCommentInfo> comments_;
};

/// @struct QChatMessageSearchPageResp
struct QChatMessageSearchPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info;
    /// 消息列表
    std::vector<QChatMessage> messages{};
    QChatMessageSearchPageResp() = default;
    QChatMessageSearchPageResp(const NIMQChatMessageSearchPageResp& c_response) {
        res_code = c_response.res_code;
        page_info = c_response.page_info;
        for (size_t i = 0; i < c_response.messages_count; i++) {
            messages.emplace_back(c_response.messages[i]);
        }
    }
    const NIMQChatMessageSearchPageResp ToCParam() const {
        NIMQChatMessageSearchPageResp c_response;
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_messages.clear();
        for (auto& message : messages)
            c_messages.push_back(message.ToCParam());
        c_response.messages = const_cast<NIMQChatMessage*>(c_messages.data());
        c_response.messages_count = c_messages.size();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMessage> c_messages;
};

/// 接收消息回调
typedef std::function<void(const QChatRecvMsgResp&)> RecvMsgCallback;
/// 发送消息回调
typedef std::function<void(const QChatSendMessageResp&)> SendMsgCallback;
/// 更新消息回调
typedef std::function<void(const QChatUpdateMessageResp&)> UpdateMsgCallback;
/// 消息更新回调
typedef std::function<void(const QChatMsgUpdatedResp&)> MsgUpdatedCallback;
/// 查询历史消息回调
typedef std::function<void(const QChatGetMessagesResp&)> GetMessagesCallback;
/// 查询频道最后一条消息回调
typedef std::function<void(const QChatGetLastMessagesResp&)> GetLastMessagesCallback;
/// 本地获取消息回调
using GetMessagesCacheCallback = GetMessagesCallback;
/// 消息已读标记回调
typedef std::function<void(const QChatMarkMessageReadResp&)> MarkMessageReadCallback;
/// 回复消息回调
using ReplyMessageCallback = std::function<void(const QChatReplyMessageResp&)>;
/// 根据消息 ID 查询消息回调
using GetMessageHistoryByIdsCallback = GetMessagesCallback;
/// 获取关联消息回调
using GetReferMessagesCallback = GetMessagesCallback;
/// 查询Thread消息回调
using GetThreadMessagesCallback = std::function<void(const QChatGetThreadMessagesResp&)>;
/// 查询Thread消息元信息回调
using GetThreadRootMessagesMetaCallback = std::function<void(const QChatGetThreadRootMessagesMetaResp&)>;
/// 添加快捷回复回调
using QuickCommentCallback = QChatBaseCallback;
/// 查询快捷回复回调
using GetQuickCommentsCallback = std::function<void(const QChatGetQuickCommentsResp&)>;
/// 消息分页搜索回调
using MessageSearchPageCallback = std::function<void(const QChatMessageSearchPageResp&)>;

/// @struct QChatRegRecvMsgCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRegRecvMsgCbParam {
    /// 回调函数
    RecvMsgCallback cb{nullptr};
    const NIMQChatRegRecvMsgCbParam ToCParam() const {
        static RecvMsgCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatRegRecvMsgCbParam param = {};
        param.cb = [](const NIMQChatRecvMsgResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatRegMsgUpdatedCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRegMsgUpdatedCbParam {
    /// 回调函数
    MsgUpdatedCallback cb{nullptr};
    const NIMQChatRegMsgUpdatedCbParam ToCParam() const {
        static MsgUpdatedCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatRegMsgUpdatedCbParam param = {};
        param.cb = [](const NIMQChatMsgUpdatedResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatSendMessageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSendMessageParam {
    /// 回调函数
    SendMsgCallback cb{nullptr};
    /// 圈组消息体
    QChatMessageSend message{};
    QChatSendMessageParam() = default;
    QChatSendMessageParam(const NIMQChatSendMessageParam& c_param) {
        message = c_param.message;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatSendMessageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatSendMessageParam ToCParam() const {
        auto cb_holder = new SendMsgCallback(cb);
        NIMQChatSendMessageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatSendMessageResp& resp) {
            InvokeCallback<SendMsgCallback, NIMQChatSendMessageResp>(resp);
        };
        param.message = message.ToCParam();
        return param;
    }
};

/// @struct QChatUpdateMessageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateMessageParam {
    /// 回调函数
    UpdateMsgCallback cb{nullptr};
    /// 频道ID信息
    NIMQChatChannelIDInfo id_info{};
    /// 消息服务器 id
    uint64_t msg_server_id{0};
    /// 消息发送时间戳
    uint64_t timestamp{0};
    /// 更新信息
    QChatMessageUpdateInfo update_info{};
    /// 反垃圾信息
    QChatMessageAntiSpamInfo anti_spam_info{};
    // 以下为待更新的消息属性
    /// 消息状态, 不允许更新为删除或撤回
    NIMQChatMessageStatus status{kMsgStatusNormal};
    /// 消息体
    std::string msg_body{""};
    /// 消息扩展字段
    std::string msg_ext{""};
    /// 消息子类型
    uint32_t msg_sub_type{0};
    QChatUpdateMessageParam() = default;
    QChatUpdateMessageParam(const NIMQChatUpdateMessageParam& c_param) {
        id_info = c_param.id_info;
        msg_server_id = c_param.msg_server_id;
        timestamp = c_param.timestamp;
        update_info = c_param.update_info;
        anti_spam_info = c_param.anti_spam_info;
        status = c_param.status;
        msg_body = c_param.msg_body;
        msg_ext = c_param.msg_ext;
        msg_sub_type = c_param.msg_sub_type;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatUpdateMessageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    QChatUpdateMessageParam(const NIMQChatRevokeMessageParam& c_param) {
        id_info = c_param.id_info;
        msg_server_id = c_param.msg_server_id;
        timestamp = c_param.timestamp;
        update_info = c_param.update_info;
        status = kMsgStatusRevoke;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatUpdateMessageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    QChatUpdateMessageParam(const NIMQChatDeleteMessageParam& c_param) {
        id_info = c_param.id_info;
        msg_server_id = c_param.msg_server_id;
        timestamp = c_param.timestamp;
        update_info = c_param.update_info;
        status = kMsgStatusDelete;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatUpdateMessageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatUpdateMessageParam ToCParam() const {
        auto cb_holder = new UpdateMsgCallback(cb);
        NIMQChatUpdateMessageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatUpdateMessageResp& resp) {
            InvokeCallback<UpdateMsgCallback, NIMQChatUpdateMessageResp>(resp);
        };
        param.id_info = id_info;
        param.msg_server_id = msg_server_id;
        param.timestamp = timestamp;
        param.update_info = update_info.ToCParam();
        param.anti_spam_info = anti_spam_info.ToCParam();
        param.status = status;
        param.msg_body = const_cast<char*>(msg_body.c_str());
        param.msg_ext = const_cast<char*>(msg_ext.c_str());
        param.msg_sub_type = msg_sub_type;
        return param;
    }
};

/// @struct QChatRevokeMessageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRevokeMessageParam {
    /// 回调函数
    UpdateMsgCallback cb{nullptr};
    NIMQChatChannelIDInfo id_info{};
    uint64_t msg_server_id{0};
    uint64_t timestamp{0};
    QChatMessageUpdateInfo update_info{};
    const NIMQChatRevokeMessageParam ToCParam() const {
        auto cb_holder = new UpdateMsgCallback(cb);
        NIMQChatRevokeMessageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatUpdateMessageResp& resp) {
            InvokeCallback<UpdateMsgCallback, NIMQChatUpdateMessageResp>(resp);
        };
        param.id_info = id_info;
        param.msg_server_id = msg_server_id;
        param.timestamp = timestamp;
        param.update_info = update_info.ToCParam();
        return param;
    }
};

/// @struct QChatDeleteMessageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatDeleteMessageParam {
    /// 回调函数
    UpdateMsgCallback cb{nullptr};
    NIMQChatChannelIDInfo id_info{};
    uint64_t msg_server_id{0};
    uint64_t timestamp{0};
    QChatMessageUpdateInfo update_info{};
    const NIMQChatDeleteMessageParam ToCParam() const {
        auto cb_holder = new UpdateMsgCallback(cb);
        NIMQChatDeleteMessageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatUpdateMessageResp& resp) {
            InvokeCallback<UpdateMsgCallback, NIMQChatUpdateMessageResp>(resp);
        };
        param.id_info = id_info;
        param.msg_server_id = msg_server_id;
        param.timestamp = timestamp;
        param.update_info = update_info.ToCParam();
        return param;
    }
};

/// @struct QChatGetMessagesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMessagesParam {
    /// 回调函数
    GetMessagesCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 查询开始时间
    uint64_t from_time{0};
    /// 查询结束时间
    uint64_t to_time{0};
    /// 排除某条消息
    uint64_t exclude_msg_server_id{0};
    /// 查询条数
    uint32_t limit{100};
    /// 是否倒序, false: 否, true: 是
    bool reverse{false};
    QChatGetMessagesParam() = default;
    QChatGetMessagesParam(const NIMQChatGetMessagesParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        from_time = c_param.from_time;
        to_time = c_param.to_time;
        exclude_msg_server_id = c_param.exclude_msg_server_id;
        limit = c_param.limit;
        reverse = c_param.reverse;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetMessagesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatGetMessagesParam ToCParam() const {
        auto cb_holder = new GetMessagesCallback(cb);
        NIMQChatGetMessagesParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatGetMessagesResp& resp) {
            InvokeCallback<GetMessagesCallback, NIMQChatGetMessagesResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.from_time = from_time;
        param.to_time = to_time;
        param.exclude_msg_server_id = exclude_msg_server_id;
        param.limit = limit;
        param.reverse = reverse;
        return param;
    }
};

/// @struct QChatGetLastMessagesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetLastMessagesParam {
    /// 回调函数
    GetLastMessagesCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID列表
    std::vector<uint64_t> channel_ids{};
    QChatGetLastMessagesParam() = default;
    QChatGetLastMessagesParam(const NIMQChatGetLastMessagesParam& c_param) {
        server_id = c_param.server_id;
        for (size_t i = 0; i < c_param.channel_ids_count; i++) {
            channel_ids.emplace_back(c_param.channel_ids[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetLastMessagesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatGetLastMessagesParam ToCParam() const {
        auto cb_holder = new GetLastMessagesCallback(cb);
        NIMQChatGetLastMessagesParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatGetLastMessagesResp& resp) {
            InvokeCallback<GetLastMessagesCallback, NIMQChatGetLastMessagesResp>(resp);
        };
        param.server_id = server_id;
        param.channel_ids_count = channel_ids.size();
        param.channel_ids = const_cast<uint64_t*>(channel_ids.data());
        return param;
    }
};

/// @struct QChatGetMessagesCacheParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMessagesCacheParam {
    /// 回调函数
    GetMessagesCacheCallback cb = nullptr;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    QChatGetMessagesCacheParam() = default;
    const NIMQChatGetMessagesCacheParam ToCParam() const {
        auto cb_holder = new GetMessagesCacheCallback(cb);
        NIMQChatGetMessagesCacheParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatGetMessagesCacheResp& resp) {
            InvokeCallback<GetMessagesCacheCallback, NIMQChatGetMessagesCacheResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        return param;
    }
};

/// @struct QChatMarkMessageReadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMarkMessageReadParam {
    /// 回调函数
    MarkMessageReadCallback cb{nullptr};
    /// 标记已读channel ID
    NIMQChatChannelIDInfo id_info{};
    /// 标记消息已读时间戳
    uint64_t timestamp{0};
    QChatMarkMessageReadParam() = default;
    QChatMarkMessageReadParam(const NIMQChatMarkMessageReadParam& param) {
        id_info = param.id_info;
        timestamp = param.timestamp;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatMarkMessageReadResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatMarkMessageReadParam ToCParam() const {
        auto cb_holder = new MarkMessageReadCallback(cb);
        NIMQChatMarkMessageReadParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatMarkMessageReadResp& resp) {
            InvokeCallback<MarkMessageReadCallback, NIMQChatMarkMessageReadResp>(resp);
        };
        param.id_info = id_info;
        param.timestamp = timestamp;
        return param;
    }
};

/// @struct QChatReplyMessageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatReplyMessageParam {
    /// 回调函数
    ReplyMessageCallback cb = nullptr;
    /// 被引用的消息体
    QChatMessage quote_message;
    /// 回复消息内容
    QChatMessageSend message;
    QChatReplyMessageParam() = default;
    QChatReplyMessageParam(const NIMQChatReplyMessageParam& c_param) {
        quote_message = c_param.quote_message;
        message = c_param.message;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatReplyMessageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatReplyMessageParam ToCParam() const {
        auto cb_holder = new ReplyMessageCallback(cb);
        NIMQChatReplyMessageParam param = {};
        param.quote_message = quote_message.ToCParam();
        param.message = message.ToCParam();
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatReplyMsgResp* c_response) {
            InvokeCallback<ReplyMessageCallback, NIMQChatReplyMsgResp>(*c_response);
        };
        return param;
    }
};

/// @struct QChatGetMessageHistoryByIdsParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMessageHistoryByIdsParam {
    GetMessageHistoryByIdsCallback cb = nullptr;
    uint64_t server_id = 0;
    uint64_t channel_id = 0;
    std::vector<NIMQChatGetMessageColumns> columns;
    QChatGetMessageHistoryByIdsParam() = default;
    QChatGetMessageHistoryByIdsParam(const NIMQChatGetMessageHistoryByIdsParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        for (size_t i = 0; i < c_param.column_count; i++) {
            columns.push_back(c_param.columns[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetMessageHistoryByIdsResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetMessageHistoryByIdsParam ToCParam() const {
        auto cb_holder = new GetMessageHistoryByIdsCallback(cb);
        NIMQChatGetMessageHistoryByIdsParam param = {};
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.columns = const_cast<NIMQChatGetMessageColumns*>(columns.data());
        param.column_count = columns.size();
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatGetMessageHistoryByIdsResp* c_response) {
            InvokeCallback<GetMessageHistoryByIdsCallback, NIMQChatGetMessageHistoryByIdsResp>(*c_response);
        };
        return param;
    }
};

/// @struct QChatGetReferMessagesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetReferMessagesParam {
    GetReferMessagesCallback cb;
    NIMQChatGetReferMessageType type;
    QChatMessage message;
    QChatGetReferMessagesParam() = default;
    QChatGetReferMessagesParam(const NIMQChatGetReferMessagesParam& c_param) {
        type = c_param.type;
        message = c_param.message;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetReferMessagesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetReferMessagesParam ToCParam() const {
        NIMQChatGetReferMessagesParam param = {};
        param.type = type;
        param.message = message.ToCParam();
        param.user_data = new GetReferMessagesCallback(cb);
        param.cb = [](const NIMQChatGetReferMessagesResp* c_response) {
            InvokeCallback<GetReferMessagesCallback, NIMQChatGetReferMessagesResp>(*c_response);
        };
        return param;
    }
};

/// @struct QChatGetThreadMessagesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetThreadMessagesParam {
    /// 回调函数
    GetThreadMessagesCallback cb = nullptr;
    /// 要查询的 thread 依据完整消息体
    QChatMessage message;
    /// 查询开始时间
    uint64_t from_time = 0;
    /// 查询结束时间
    uint64_t to_time = 0;
    /// 排除的消息 ID
    uint64_t exclude_msg_server_id = 0;
    /// 查询条数
    uint32_t limit = 10;
    /// 是否倒序, false: 否, true: 是
    bool reverse = false;
    QChatGetThreadMessagesParam() = default;
    QChatGetThreadMessagesParam(const NIMQChatGetThreadMessagesParam& c_param) {
        message = c_param.message;
        from_time = c_param.from_time;
        to_time = c_param.to_time;
        exclude_msg_server_id = c_param.exclude_msg_server_id;
        limit = c_param.limit;
        reverse = c_param.reverse;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetThreadMessagesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetThreadMessagesParam ToCParam() const {
        auto cb_holder = new GetThreadMessagesCallback(cb);
        NIMQChatGetThreadMessagesParam param = {};
        param.message = message.ToCParam();
        param.from_time = from_time;
        param.to_time = to_time;
        param.exclude_msg_server_id = exclude_msg_server_id;
        param.limit = limit;
        param.reverse = reverse;
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatGetThreadMessagesResp* c_response) {
            InvokeCallback<GetThreadMessagesCallback, NIMQChatGetThreadMessagesResp>(*c_response);
        };
        return param;
    }
};

template <NIMQChatQuickCommentOperation operation, typename TCParam, typename TCResponse>
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatQuickCommentParam {
    /// 回调函数
    QuickCommentCallback cb = nullptr;
    /// 快速评论内容
    QChatMessage message;
    /// 快速评论类型，是一个数组，大于 0
    uint32_t type;
    QChatQuickCommentParam() = default;
    QChatQuickCommentParam(const TCParam& c_param) {
        message = c_param.quote_message;
        type = c_param.type;
        opt = c_param.operation;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatAddQuickCommentResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const TCParam ToCParam() const {
        auto cb_holder = new QuickCommentCallback(cb);
        TCParam param;
        param.quote_message = message.ToCParam();
        param.type = type;
        param.operation = opt;
        param.user_data = cb_holder;
        param.cb = [](const TCResponse* c_response) {
            InvokeCallback<QuickCommentCallback, TCResponse>(*c_response);
        };
        return param;
    }
    NIMQChatQuickCommentOperation GetOperation() const { return opt; }

private:
    /// 操作类型
    NIMQChatQuickCommentOperation opt = operation;
};

/// @struct QChatGetThreadRootMessagesMetaParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetThreadRootMessagesMetaParam {
    /// 回调函数
    GetThreadRootMessagesMetaCallback cb;
    uint64_t server_id = 0;
    uint64_t channel_id = 0;
    std::list<QChatMessage> thread_root_messages;
    QChatGetThreadRootMessagesMetaParam() = default;
    QChatGetThreadRootMessagesMetaParam(const NIMQChatGetThreadRootMessagesMetaParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        for (size_t i = 0; i < c_param.message_count; i++) {
            thread_root_messages.push_back(c_param.messages[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetThreadRootMessagesMetaResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetThreadRootMessagesMetaParam ToCParam() const {
        NIMQChatGetThreadRootMessagesMetaParam param = {};
        param.server_id = server_id;
        param.channel_id = channel_id;
        messages_.clear();
        for (auto& message : thread_root_messages) {
            messages_.push_back(message.ToCParam());
        }
        param.messages = const_cast<NIMQChatMessage*>(messages_.data());
        param.message_count = messages_.size();
        param.user_data = new GetThreadRootMessagesMetaCallback(cb);
        param.cb = [](const NIMQChatGetThreadRootMessagesMetaResp* c_response) {
            InvokeCallback<GetThreadRootMessagesMetaCallback, NIMQChatGetThreadRootMessagesMetaResp>(*c_response);
        };
        return param;
    }

private:
    mutable std::vector<NIMQChatMessage> messages_;
};

// clang-format off
using QChatAddQuickCommentParam = QChatQuickCommentParam<kNIMQChatQuickCommentAdd, NIMQChatAddQuickCommentParam, NIMQChatAddQuickCommentResp>;
using QChatRemoveQuickCommentParam = QChatQuickCommentParam<kNIMQChatQuickCommentRemove, NIMQChatRemoveQuickCommentParam, NIMQChatRemoveQuickCommentResp>;
// clang-format on

/// @struct QChatGetQuickCommentsParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetQuickCommentsParam {
    /// 回调函数
    GetQuickCommentsCallback cb = nullptr;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 要查询的服务器消息 ID 列表
    std::vector<uint64_t> msg_server_id_list;
    QChatGetQuickCommentsParam() = default;
    QChatGetQuickCommentsParam(const NIMQChatGetQuickCommentsParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        for (size_t i = 0; i < c_param.msg_server_id_count; i++)
            msg_server_id_list.push_back(c_param.msg_server_id_list[i]);
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatGetQuickCommentsResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetQuickCommentsParam ToCParam() const {
        auto cb_holder = new GetQuickCommentsCallback(cb);
        NIMQChatGetQuickCommentsParam param = {};
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.msg_server_id_list = const_cast<uint64_t*>(msg_server_id_list.data());
        param.msg_server_id_count = msg_server_id_list.size();
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatGetQuickCommentsResp* resp) {
            InvokeCallback<GetQuickCommentsCallback, NIMQChatGetQuickCommentsResp>(*resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        return param;
    }
};

/// @struct QChatMessageSearchPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMessageSearchPageParam {
    /// 回调函数
    MessageSearchPageCallback cb = nullptr;
    /// 搜索关键字
    std::string keyword;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道 ID
    uint64_t channel_id;
    /// 消息发送者ID
    std::string from_accid;
    /// 搜索的开始时间
    uint64_t from_time;
    /// 搜索的结束时间
    uint64_t to_time;
    /// 搜索消息类型
    std::vector<NIMQChatMsgType> msg_types;
    /// 搜索消息类型
    std::vector<uint32_t> sub_types;
    /// 是否包含自己的消息
    bool include_self{false};
    /// 排序顺序
    NIMQChatSearchOrder order;
    /// 排序规则
    NIMQChatMessageSearchSort sort;
    /// 查询条数
    uint32_t limit;
    /// 查询游标, 查询的起始位置
    std::string cursor;
    QChatMessageSearchPageParam() = default;
    QChatMessageSearchPageParam(const NIMQChatMessageSearchPageParam& c_param) {
        keyword = c_param.keyword ? c_param.keyword : "";
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        from_accid = c_param.from_accid ? c_param.from_accid : "";
        from_time = c_param.from_time;
        to_time = c_param.to_time;
        for (size_t i = 0; i < c_param.msg_types_count; i++)
            msg_types.push_back(c_param.msg_types[i]);
        for (size_t i = 0; i < c_param.sub_types_count; i++)
            sub_types.push_back(c_param.sub_types[i]);
        include_self = c_param.include_self;
        order = c_param.order;
        sort = c_param.sort;
        limit = c_param.limit;
        cursor = c_param.cursor ? c_param.cursor : "";
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatMessageSearchPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatMessageSearchPageParam ToCParam() const {
        NIMQChatMessageSearchPageParam param = {};
        param.keyword = const_cast<char*>(keyword.c_str());
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.from_accid = const_cast<char*>(from_accid.c_str());
        param.from_time = from_time;
        param.to_time = to_time;
        param.msg_types = const_cast<NIMQChatMsgType*>(msg_types.data());
        param.msg_types_count = msg_types.size();
        param.sub_types = const_cast<uint32_t*>(sub_types.data());
        param.sub_types_count = sub_types.size();
        param.include_self = include_self;
        param.order = order;
        param.sort = sort;
        param.limit = limit;
        param.cursor = const_cast<char*>(cursor.c_str());
        param.user_data = new MessageSearchPageCallback(cb);
        param.cb = [](const NIMQChatMessageSearchPageResp* c_response) {
            InvokeCallback<MessageSearchPageCallback, NIMQChatMessageSearchPageResp>(*c_response);
        };
        return param;
    }
};
}  // namespace nim_qchat

#endif  // __NIM_QCHAT_MESSAGE_CPP_DEF_H__
