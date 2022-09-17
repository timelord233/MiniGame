/**
 * @file nim_qchat_channel_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_CPP_DEF_H__
#define __NIM_QCHAT_CHANNEL_CPP_DEF_H__

#include "nim_qchat_channel_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_helper.h"
#include "nim_qchat_member_cpp_def.h"
#include "nim_qchat_role_cpp_def.h"
#include "nim_qchat_server_cpp_def.h"

namespace nim_qchat {

/** @struct QChatChannelInfo 圈组频道信息 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelInfo {
    /// server id
    uint64_t server_id{0};
    /// channel id
    uint64_t channel_id{0};
    /// 名称
    std::string name{""};
    /// 主题
    std::string topic{""};
    /// 自定义字段
    std::string custom{""};
    /// 频道类型，0:消息频道
    NIMQChatChannelType type{kNIMQChatChannelTypeText};
    /// 拥有者
    std::string owner{""};
    /// 查看模式，只有在category_id为0或sync_mode为kNIMQChatChannelSyncModeNoSync时有效
    NIMQChatChannelViewMode view_mode{kNIMQChatChannelViewModePublic};
    /// 有效标记，false:无效 true:有效
    bool valid_flag{false};
    /// 创建时间
    uint64_t create_time{0};
    /// 更新时间
    uint64_t update_time{0};
    /// 频道分组ID
    uint64_t category_id{0};
    /// 频道分组同步模式
    NIMQChatChannelSyncMode sync_mode{kNIMQChatChannelSyncModeSync};
    /// 自定义排序权重值
    uint64_t reorder_weight{0};
    QChatChannelInfo() = default;
    QChatChannelInfo(const NIMQChatChannelInfo& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        name = c_param.name ? c_param.name : "";
        topic = c_param.topic ? c_param.topic : "";
        custom = c_param.custom ? c_param.custom : "";
        type = c_param.type;
        owner = c_param.owner ? c_param.owner : "";
        view_mode = c_param.view_mode;
        valid_flag = c_param.valid_flag;
        create_time = c_param.create_time;
        update_time = c_param.update_time;
        category_id = c_param.category_id;
        sync_mode = c_param.sync_mode;
        reorder_weight = c_param.reorder_weight;
    }
    const NIMQChatChannelInfo ToCParam() const {
        NIMQChatChannelInfo c_param = {};
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.name = const_cast<char*>(name.c_str());
        c_param.topic = const_cast<char*>(topic.c_str());
        c_param.custom = const_cast<char*>(custom.c_str());
        c_param.type = type;
        c_param.owner = const_cast<char*>(owner.c_str());
        c_param.view_mode = view_mode;
        c_param.valid_flag = valid_flag;
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        c_param.category_id = category_id;
        c_param.sync_mode = sync_mode;
        c_param.reorder_weight = reorder_weight;
        return c_param;
    }
};

/// @struct QChatChannelRTCAudioInfo 圈组RTC频道音频信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelRTCAudioInfo {
    /// 音频属性 ["HIGH_QUALITY_STEREO","HIGH_QUALITY","STANDARD_EXTEND"]
    std::string profile;
    /// 音频应用场景 ["DEFAULT","SPEECH","MUSIC", "CHATROOM"]
    std::string scenario;
    QChatChannelRTCAudioInfo() = default;
    QChatChannelRTCAudioInfo(const NIMQChatChannelRTCAudioInfo& c_param) {
        profile = c_param.profile ? c_param.profile : "";
        scenario = c_param.scenario ? c_param.scenario : "";
    }
    const NIMQChatChannelRTCAudioInfo ToCParam() const {
        NIMQChatChannelRTCAudioInfo c_param = {};
        c_param.profile = const_cast<char*>(profile.c_str());
        c_param.scenario = const_cast<char*>(scenario.c_str());
        return c_param;
    }
};

/// @struct QChatChannelRTCVideoInfo 圈组RTC频道视频信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelRTCVideoInfo {
    /// 分辨率宽
    uint32_t width{640};
    /// 分辨率高
    uint32_t height{480};
    /// 帧率
    uint32_t fps{15};
    QChatChannelRTCVideoInfo() = default;
    QChatChannelRTCVideoInfo(const NIMQChatChannelRTCVideoInfo& c_param) {
        width = c_param.width;
        height = c_param.height;
        fps = c_param.fps;
    }
    const NIMQChatChannelRTCVideoInfo ToCParam() const {
        NIMQChatChannelRTCVideoInfo c_param = {};
        c_param.width = width;
        c_param.height = height;
        c_param.fps = fps;
        return c_param;
    }
};

/// @struct QChatChannelRTCInfo 圈组频道RTC信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelRTCInfo {
    /// 在线人数限制
    uint32_t limit{99};
    /// 音频配置
    QChatChannelRTCAudioInfo audio{};
    /// 视频配置
    QChatChannelRTCVideoInfo video{};
    QChatChannelRTCInfo() = default;
    QChatChannelRTCInfo(const NIMQChatChannelRTCInfo& c_param) {
        limit = c_param.limit;
        audio = c_param.audio;
        video = c_param.video;
    }
    const NIMQChatChannelRTCInfo ToCParam() const {
        NIMQChatChannelRTCInfo c_param = {};
        c_param.limit = limit;
        c_param.audio = audio.ToCParam();
        c_param.video = video.ToCParam();
        return c_param;
    }
};

/** @struct QChatChannelCategoryInfo 圈组频道分组信息 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryInfo {
    /// server id
    uint64_t server_id{0};
    /// category id
    uint64_t category_id{0};
    /// 名称
    std::string name{""};
    /// 自定义字段
    std::string custom{""};
    /// 拥有者
    std::string owner{""};
    /// 查看模式
    NIMQChatChannelViewMode view_mode{kNIMQChatChannelViewModePublic};
    /// 有效标记，false:无效 true:有效
    bool valid_flag{false};
    /// 创建时间
    uint64_t create_time{0};
    /// 更新时间
    uint64_t update_time{0};
    QChatChannelCategoryInfo() = default;
    QChatChannelCategoryInfo(const NIMQChatChannelCategoryInfo& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        name = c_param.name ? c_param.name : "";
        custom = c_param.custom ? c_param.custom : "";
        owner = c_param.owner ? c_param.owner : "";
        view_mode = c_param.view_mode;
        valid_flag = c_param.valid_flag;
        create_time = c_param.create_time;
        update_time = c_param.update_time;
    }
    const NIMQChatChannelCategoryInfo ToCParam() const {
        NIMQChatChannelCategoryInfo c_param = {};
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.name = const_cast<char*>(name.c_str());
        c_param.custom = const_cast<char*>(custom.c_str());
        c_param.owner = const_cast<char*>(owner.c_str());
        c_param.view_mode = view_mode;
        c_param.valid_flag = valid_flag;
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        return c_param;
    }
};

/// @struct QChatChannelSubscribeResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelSubscribeResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 订阅失败列表
    std::vector<NIMQChatChannelIDInfo> failed_channels{};
    /// 频道未读信息, 内部使用，未读相关变更关注RegUnreadCb回调
    std::vector<NIMQChatUnreadInfo> unread_infos{};
    QChatChannelSubscribeResp() = default;
    QChatChannelSubscribeResp(const NIMQChatChannelSubscribeResp& c_resp) {
        res_code = c_resp.res_code;
        for (size_t i = 0; i < c_resp.failed_channels_count; i++) {
            failed_channels.push_back(c_resp.failed_channels[i]);
        }
        for (size_t i = 0; i < c_resp.unread_infos_count; i++) {
            unread_infos.push_back(c_resp.unread_infos[i]);
        }
    }
    NIMQChatChannelSubscribeResp ToCParam() const {
        NIMQChatChannelSubscribeResp c_resp;
        c_resp.res_code = res_code;
        c_resp.failed_channels = const_cast<NIMQChatChannelIDInfo*>(failed_channels.data());
        c_resp.failed_channels_count = failed_channels.size();
        c_resp.unread_infos = const_cast<NIMQChatUnreadInfo*>(unread_infos.data());
        c_resp.unread_infos_count = unread_infos.size();
        return c_resp;
    }
};

/// @struct QChatChannelQueryUnreadInfoResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelQueryUnreadInfoResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 未读信息列表
    std::vector<NIMQChatUnreadInfo> unread_infos;
    QChatChannelQueryUnreadInfoResp() = default;
    QChatChannelQueryUnreadInfoResp(const NIMQChatChannelQueryUnreadInfoResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.unread_info_count; i++) {
            unread_infos.push_back(c_resp.unread_infos[i]);
        }
    }
    NIMQChatChannelQueryUnreadInfoResp ToCParam() const {
        NIMQChatChannelQueryUnreadInfoResp c_resp = {};
        c_resp.res_code = res_code;
        if (res_code != kNIMResSuccess)
            return c_resp;
        c_resp.unread_infos = const_cast<NIMQChatUnreadInfo*>(unread_infos.data());
        c_resp.unread_info_count = unread_infos.size();
        return c_resp;
    }
};

/// @struct QChatChannelCreateResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCreateResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 频道信息
    QChatChannelInfo channel_info{};
    QChatChannelCreateResp() = default;
    QChatChannelCreateResp(const NIMQChatChannelCreateResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        channel_info = c_resp.channel_info;
    }
    NIMQChatChannelCreateResp ToCParam() const {
        NIMQChatChannelCreateResp c_resp = {};
        c_resp.res_code = res_code;
        if (res_code != kNIMResSuccess)
            return c_resp;
        c_resp.channel_info = channel_info.ToCParam();
        return c_resp;
    }
};

/// @struct QChatChannelDeleteResp
using QChatChannelDeleteResp = QChatBaseResp;

/// @struct QChatChannelUpdateResp
using QChatChannelUpdateResp = QChatChannelCreateResp;

/// @struct QChatChannelUpdateCategoryInfoResp
using QChatChannelUpdateCategoryInfoResp = QChatChannelCreateResp;

/// @struct QChatChannelGetChannelsResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetChannelsResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 频道列表
    std::list<QChatChannelInfo> channel_list{};
    QChatChannelGetChannelsResp() = default;
    QChatChannelGetChannelsResp(const NIMQChatChannelGetChannelsResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.channel_list_count; i++) {
            channel_list.emplace_back(c_resp.channel_list[i]);
        }
    }
    NIMQChatChannelGetChannelsResp ToCParam() const {
        NIMQChatChannelGetChannelsResp c_param = {};
        c_param.res_code = res_code;
        vec_channels.clear();
        for (auto&& it : channel_list) {
            vec_channels.push_back(it.ToCParam());
        }
        c_param.channel_list = vec_channels.data();
        c_param.channel_list_count = vec_channels.size();
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatChannelInfo> vec_channels;
};

/// @struct QChatChannelGetChannelsPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetChannelsPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 频道列表
    std::list<QChatChannelInfo> channel_list{};
    QChatChannelGetChannelsPageResp() = default;
    QChatChannelGetChannelsPageResp(const NIMQChatChannelGetChannelsPageResp& c_resp) {
        res_code = c_resp.res_code;
        page_info = c_resp.page_info;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.channel_list_count; i++) {
            channel_list.emplace_back(c_resp.channel_list[i]);
        }
    }
    const NIMQChatChannelGetChannelsPageResp ToCParam() const {
        NIMQChatChannelGetChannelsPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        vec_channels.clear();
        for (auto&& info : channel_list) {
            vec_channels.push_back(info.ToCParam());
        }
        c_response.channel_list_count = vec_channels.size();
        c_response.channel_list = vec_channels.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatChannelInfo> vec_channels;
};

/// @struct QChatChannelUnreadResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelUnreadResp {
    /// 未读数信息
    std::vector<NIMQChatUnreadInfo> unread_infos;
    QChatChannelUnreadResp() = default;
    QChatChannelUnreadResp(const NIMQChatChannelUnreadResp& c_resp) {
        for (size_t i = 0; i < c_resp.unread_infos_count; i++) {
            unread_infos.emplace_back(c_resp.unread_infos[i]);
        }
    }
};

typedef QChatBaseResp QChatChannelUpdateWhiteBlackRoleResp;
typedef QChatBaseResp QChatChannelUpdateWhiteBlackMembersResp;

/// @struct QChatChannelGetWhiteBlackRolesPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetWhiteBlackRolesPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 身份组列表
    std::list<QChatServerRoleInfo> roles{};
    QChatChannelGetWhiteBlackRolesPageResp() = default;
    QChatChannelGetWhiteBlackRolesPageResp(const NIMQChatChannelGetWhiteBlackRolesPageResp& c_resp) {
        res_code = c_resp.res_code;
        page_info = c_resp.page_info;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            roles.emplace_back(c_resp.roles[i]);
        }
    }
    const NIMQChatChannelGetWhiteBlackRolesPageResp ToCParam() const {
        NIMQChatChannelGetWhiteBlackRolesPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_roles.clear();
        for (const auto& role : roles) {
            c_roles.push_back(role.ToCParam());
        }
        c_response.role_count = c_roles.size();
        c_response.roles = const_cast<NIMQChatRoleInfo*>(c_roles.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> c_roles;
};

/// @struct QChatChannelGetWhiteBlackMembersPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetWhiteBlackMembersPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 身份组列表
    std::list<QChatMemberInfo> members{};
    QChatChannelGetWhiteBlackMembersPageResp() = default;
    QChatChannelGetWhiteBlackMembersPageResp(const NIMQChatChannelGetWhiteBlackMembersPageResp& c_resp) {
        res_code = c_resp.res_code;
        page_info = c_resp.page_info;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_count; i++) {
            members.emplace_back(c_resp.members[i]);
        }
    }
    const NIMQChatChannelGetWhiteBlackMembersPageResp ToCParam() const {
        NIMQChatChannelGetWhiteBlackMembersPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_members.clear();
        for (const auto& member : members) {
            c_members.push_back(member.ToCParam());
        }
        c_response.member_count = c_members.size();
        c_response.members = const_cast<NIMQChatMemberInfo*>(c_members.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberInfo> c_members;
};

/// @struct QChatChannelGetExistingWhiteBlackRolesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetExistingWhiteBlackRolesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 身份组列表
    std::list<QChatServerRoleInfo> roles{};
    QChatChannelGetExistingWhiteBlackRolesResp() = default;
    QChatChannelGetExistingWhiteBlackRolesResp(const NIMQChatChannelGetExistingWhiteBlackRolesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            roles.emplace_back(c_resp.roles[i]);
        }
    }
    const NIMQChatChannelGetExistingWhiteBlackRolesResp ToCParam() const {
        NIMQChatChannelGetExistingWhiteBlackRolesResp c_response{};
        c_response.res_code = res_code;
        c_roles.clear();
        for (const auto& role : roles) {
            c_roles.push_back(role.ToCParam());
        }
        c_response.role_count = c_roles.size();
        c_response.roles = const_cast<NIMQChatRoleInfo*>(c_roles.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> c_roles;
};

/// @struct QChatChannelGetExistingWhiteBlackMembersResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetExistingWhiteBlackMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 身份组列表，结果中不包含成员有效属性 vaild_flag
    std::list<QChatMemberInfo> members{};
    QChatChannelGetExistingWhiteBlackMembersResp() = default;
    QChatChannelGetExistingWhiteBlackMembersResp(const NIMQChatChannelGetExistingWhiteBlackMembersResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_count; i++) {
            members.emplace_back(c_resp.members[i]);
        }
    }
    const NIMQChatChannelGetExistingWhiteBlackMembersResp ToCParam() const {
        NIMQChatChannelGetExistingWhiteBlackMembersResp c_response{};
        c_response.res_code = res_code;
        c_members.clear();
        for (const auto& member : members) {
            c_members.push_back(member.ToCParam());
        }
        c_response.member_count = c_members.size();
        c_response.members = const_cast<NIMQChatMemberInfo*>(c_members.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberInfo> c_members;
};
using QChatChannelGetMembersPageResp = QChatServerGetMembersPageResp;
using QChatChannelSearchPageResp = QChatChannelGetChannelsPageResp;
/// @struct QChatChannelMemberSearchResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelMemberSearchResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 成员信息列表
    std::list<QChatMemberInfo> member_list{};
    QChatChannelMemberSearchResp() = default;
    QChatChannelMemberSearchResp(const NIMQChatChannelMemberSearchResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_list_count; i++) {
            member_list.emplace_back(c_resp.member_list[i]);
        }
    }
    NIMQChatChannelMemberSearchResp ToCParam() const {
        NIMQChatChannelMemberSearchResp c_response{};
        c_response.res_code = res_code;
        vec_members.clear();
        for (auto&& info : member_list) {
            vec_members.push_back(info.ToCParam());
        }
        c_response.member_list_count = vec_members.size();
        c_response.member_list = vec_members.data();
        return c_response;
    };

protected:
    mutable std::vector<NIMQChatMemberInfo> vec_members;
};

/// @struct QChatChannelCategoryCreateResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryCreateResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分类信息
    QChatChannelCategoryInfo category_info{};
    QChatChannelCategoryCreateResp() = default;
    QChatChannelCategoryCreateResp(const NIMQChatChannelCategoryCreateResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        category_info = c_resp.category_info;
    }
    const NIMQChatChannelCategoryCreateResp ToCParam() const {
        NIMQChatChannelCategoryCreateResp c_response{};
        c_response.res_code = res_code;
        c_response.category_info = category_info.ToCParam();
        return c_response;
    }
};

/// @struct QChatChannelCategoryRemoveResp
using QChatChannelCategoryRemoveResp = QChatBaseResp;

/// @struct QChatChannelCategoryUpdateResp
using QChatChannelCategoryUpdateResp = QChatChannelCategoryCreateResp;

/// @struct QChatChannelGetCategoriesByIDResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetCategoriesByIDResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 频道分组信息列表
    std::list<QChatChannelCategoryInfo> categories{};
    QChatChannelGetCategoriesByIDResp() = default;
    QChatChannelGetCategoriesByIDResp(const NIMQChatChannelGetCategoriesByIDResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.category_count; i++) {
            categories.emplace_back(c_resp.categories[i]);
        }
    }
    const NIMQChatChannelGetCategoriesByIDResp ToCParam() const {
        NIMQChatChannelGetCategoriesByIDResp c_response{};
        c_response.res_code = res_code;
        c_categories.clear();
        for (const auto& category : categories) {
            c_categories.push_back(category.ToCParam());
        }
        c_response.category_count = c_categories.size();
        c_response.categories = const_cast<NIMQChatChannelCategoryInfo*>(c_categories.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatChannelCategoryInfo> c_categories;
};

/// @struct QChatChannelGetCategoriesPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetCategoriesPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 分类信息
    std::list<QChatChannelCategoryInfo> categories{};
    QChatChannelGetCategoriesPageResp() = default;
    QChatChannelGetCategoriesPageResp(const NIMQChatChannelGetCategoriesPageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        page_info = c_resp.page_info;
        for (size_t i = 0; i < c_resp.category_count; i++) {
            categories.emplace_back(c_resp.categories[i]);
        }
    }
    const NIMQChatChannelGetCategoriesPageResp ToCParam() const {
        NIMQChatChannelGetCategoriesPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_categories.clear();
        for (const auto& category : categories) {
            c_categories.push_back(category.ToCParam());
        }
        c_response.category_count = c_categories.size();
        c_response.categories = const_cast<NIMQChatChannelCategoryInfo*>(c_categories.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatChannelCategoryInfo> c_categories;
};

/// @struct QChatChannelGetCategoryChannelsPageResp
using QChatChannelGetCategoryChannelsPageResp = QChatChannelGetChannelsPageResp;

/// @struct QChatChannelCategoryUpdateWhiteBlackRoleResp
using QChatChannelCategoryUpdateWhiteBlackRoleResp = QChatBaseResp;

/// @struct QChatChannelCategoryGetWhiteBlackRolesPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetWhiteBlackRolesPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 身份组列表
    std::list<QChatServerRoleInfo> roles{};
    QChatChannelCategoryGetWhiteBlackRolesPageResp() = default;
    QChatChannelCategoryGetWhiteBlackRolesPageResp(const NIMQChatChannelCategoryGetWhiteBlackRolesPageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        page_info = c_resp.page_info;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            roles.emplace_back(c_resp.roles[i]);
        }
    }
    const NIMQChatChannelCategoryGetWhiteBlackRolesPageResp ToCParam() const {
        NIMQChatChannelCategoryGetWhiteBlackRolesPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_roles.clear();
        for (const auto& role : roles) {
            c_roles.push_back(role.ToCParam());
        }
        c_response.role_count = c_roles.size();
        c_response.roles = const_cast<NIMQChatRoleInfo*>(c_roles.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> c_roles;
};

/// @struct QChatChannelCategoryGetExistingWhiteBlackRolesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetExistingWhiteBlackRolesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 身份组列表
    std::list<QChatServerRoleInfo> roles{};
    QChatChannelCategoryGetExistingWhiteBlackRolesResp() = default;
    QChatChannelCategoryGetExistingWhiteBlackRolesResp(const NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            roles.emplace_back(c_resp.roles[i]);
        }
    }
    const NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp ToCParam() const {
        NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp c_response{};
        c_response.res_code = res_code;
        c_roles.clear();
        for (const auto& role : roles) {
            c_roles.push_back(role.ToCParam());
        }
        c_response.role_count = c_roles.size();
        c_response.roles = const_cast<NIMQChatRoleInfo*>(c_roles.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> c_roles;
};

/// @struct QChatChannelCategoryUpdateWhiteBlackMembersResp
using QChatChannelCategoryUpdateWhiteBlackMembersResp = QChatBaseResp;

/// @struct QChatChannelCategoryGetWhiteBlackMembersPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetWhiteBlackMembersPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 成员列表
    std::list<QChatMemberInfo> members{};
    QChatChannelCategoryGetWhiteBlackMembersPageResp() = default;
    QChatChannelCategoryGetWhiteBlackMembersPageResp(const NIMQChatChannelCategoryGetWhiteBlackMembersPageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        page_info = c_resp.page_info;
        for (size_t i = 0; i < c_resp.member_count; i++) {
            members.emplace_back(c_resp.members[i]);
        }
    }
    const NIMQChatChannelCategoryGetWhiteBlackMembersPageResp ToCParam() const {
        NIMQChatChannelCategoryGetWhiteBlackMembersPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_members.clear();
        for (const auto& member : members) {
            c_members.push_back(member.ToCParam());
        }
        c_response.member_count = c_members.size();
        c_response.members = const_cast<NIMQChatMemberInfo*>(c_members.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberInfo> c_members;
};

/// @struct QChatChannelCategoryGetExistingWhiteBlackMembersResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetExistingWhiteBlackMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 成员列表
    std::list<QChatMemberInfo> members{};
    QChatChannelCategoryGetExistingWhiteBlackMembersResp() = default;
    QChatChannelCategoryGetExistingWhiteBlackMembersResp(const NIMQChatChannelCategoryGetWhiteBlackMembersResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_count; i++) {
            members.emplace_back(c_resp.members[i]);
        }
    }
    const NIMQChatChannelCategoryGetWhiteBlackMembersResp ToCParam() const {
        NIMQChatChannelCategoryGetWhiteBlackMembersResp c_response{};
        c_response.res_code = res_code;
        c_members.clear();
        for (const auto& member : members) {
            c_members.push_back(member.ToCParam());
        }
        c_response.member_count = c_members.size();
        c_response.members = const_cast<NIMQChatMemberInfo*>(c_members.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberInfo> c_members;
};

/// @struct QChatChannelUpdateRTCInfoResp
using QChatChannelUpdateRTCInfoResp = QChatBaseResp;

/// @struct QChatChannelGetRTCInfoResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetRTCInfoResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// RTC信息
    QChatChannelRTCInfo rtc_info;
    QChatChannelGetRTCInfoResp() = default;
    QChatChannelGetRTCInfoResp(const NIMQChatChannelGetRTCInfoResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        rtc_info = c_resp.rtc_info;
    }
    const NIMQChatChannelGetRTCInfoResp ToCParam() const {
        NIMQChatChannelGetRTCInfoResp c_response{};
        c_response.res_code = res_code;
        c_response.rtc_info = rtc_info.ToCParam();
        return c_response;
    }
};

/// @struct QChatChannelGetRTCOnlineMembersResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetRTCOnlineMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 成员列表
    std::vector<QChatMemberInfo> members;
    QChatChannelGetRTCOnlineMembersResp() = default;
    QChatChannelGetRTCOnlineMembersResp(const NIMQChatChannelGetRTCOnlineMembersResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_count; i++) {
            members.emplace_back(c_resp.members[i]);
        }
    }
    const NIMQChatChannelGetRTCOnlineMembersResp ToCParam() const {
        NIMQChatChannelGetRTCOnlineMembersResp c_response{};
        c_response.res_code = res_code;
        c_members.clear();
        for (const auto& member : members) {
            c_members.push_back(member.ToCParam());
        }
        c_response.member_count = c_members.size();
        c_response.members = const_cast<NIMQChatMemberInfo*>(c_members.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberInfo> c_members;
};

/// 未读信息回调
typedef std::function<void(const QChatChannelUnreadResp&)> ChannelUnreadCallback;
/// 创建频道回调
typedef std::function<void(const QChatChannelCreateResp&)> ChannelCreateCallback;
/// 删除频道回调
typedef std::function<void(const QChatChannelDeleteResp&)> ChannelDeleteCallback;
/// 更新频道回调
typedef std::function<void(const QChatChannelUpdateResp&)> ChannelUpdateCallback;
/// 更新频道的分组信息回调
typedef std::function<void(const QChatChannelUpdateCategoryInfoResp&)> ChannelUpdateCategoryInfoCallback;
/// 查询频道列表回调
typedef std::function<void(const QChatChannelGetChannelsResp&)> GetChannelsCallback;
/// 分页查询频道列表回调
typedef std::function<void(const QChatChannelGetChannelsPageResp&)> GetChannelsPageCallback;
/// 分页查询成员列表回调
typedef std::function<void(const QChatChannelGetMembersPageResp&)> ChannelGetMembersPageCallback;
/// 查询未读消息数回调
typedef std::function<void(const QChatChannelQueryUnreadInfoResp&)> ChannelQueryUnreadInfoCallback;
/// 订阅回调
typedef std::function<void(const QChatChannelSubscribeResp&)> ChannelSubscribeCallback;
/// 更新白/黑名单身份组回调
typedef std::function<void(const QChatChannelUpdateWhiteBlackRoleResp&)> UpdateWhiteBlackRoleCallback;
/// 更新白/黑名单成员回调
typedef std::function<void(const QChatChannelUpdateWhiteBlackMembersResp&)> UpdateWhiteBlackMembersCallback;
/// 分页查询白/黑名单身份组回调
typedef std::function<void(const QChatChannelGetWhiteBlackRolesPageResp&)> GetWhiteBlackRolesPageCallback;
/// 分页查询白/黑名单成员回调
typedef std::function<void(const QChatChannelGetWhiteBlackMembersPageResp&)> GetWhiteBlackMembersPageCallback;
/// 查询已存在白/黑名单身份组回调
typedef std::function<void(const QChatChannelGetExistingWhiteBlackRolesResp&)> GetExistingWhiteBlackRolesCallback;
/// 查询已存在白/黑名单成员回调
typedef std::function<void(const QChatChannelGetExistingWhiteBlackMembersResp&)> GetExistingWhiteBlackMembersCallback;
/// 搜索频道分页回调
using ChannelSearchPageCallback = GetChannelsPageCallback;
/// 搜索频道成员回调
using ChannelMemberSearchCallback = std::function<void(const QChatChannelMemberSearchResp&)>;
/// 创建频道分组回调
using ChannelCategoryCreateCallback = std::function<void(const QChatChannelCategoryCreateResp&)>;
/// 删除频道分组回调
using ChannelCategoryRemoveCallback = std::function<void(const QChatChannelCategoryRemoveResp&)>;
/// 更新频道分组回调
using ChannelCategoryUpdateCallback = std::function<void(const QChatChannelCategoryUpdateResp&)>;
/// 根据频道分组ID查询频道分组列表回调
using ChannelGetCategoriesByIDCallback = std::function<void(const QChatChannelGetCategoriesByIDResp&)>;
/// 分页查询频道分组回调
using ChannelGetCategoriesPageCallback = std::function<void(const QChatChannelGetCategoriesPageResp&)>;
/// 分页查询指定频道分组中的频道
using ChannelGetCategoryChannelsPageCallback = std::function<void(const QChatChannelGetCategoryChannelsPageResp&)>;
/// 更新频道分组白/黑名单身份组
using ChannelCategoryUpdateWhiteBlackRoleCallback = std::function<void(const QChatChannelCategoryUpdateWhiteBlackRoleResp&)>;
/// 分页查询频道分组白/黑名单身份组
using ChannelCategoryGetWhiteBlackRolesPageCallback = std::function<void(const QChatChannelCategoryGetWhiteBlackRolesPageResp&)>;
/// 批量查询频道分组白/黑名单身份组
using ChannelCategoryGetExistingWhiteBlackRolesCallback = std::function<void(const QChatChannelCategoryGetExistingWhiteBlackRolesResp&)>;
/// 更新频道分组白/黑名单成员
using ChannelCategoryUpdateWhiteBlackMembersCallback = std::function<void(const QChatChannelCategoryUpdateWhiteBlackMembersResp&)>;
/// 分页查询频道分组白/黑名单成员
using ChannelCategoryGetWhiteBlackMembersPageCallback = std::function<void(const QChatChannelCategoryGetWhiteBlackMembersPageResp&)>;
/// 批量查询频道分组白/黑名单成员
using ChannelCategoryGetExistingWhiteBlackMembersCallback = std::function<void(const QChatChannelCategoryGetExistingWhiteBlackMembersResp&)>;
/// 修改RTC频道参数回调
using ChannelUpdateRTCInfoCallback = std::function<void(const QChatChannelUpdateRTCInfoResp&)>;
/// 查询RTC频道参数回调
using ChannelGetRTCInfoCallback = std::function<void(const QChatChannelGetRTCInfoResp&)>;
/// 查询RTC频道在线成员回调
using ChannelGetRTCOnlineMembersCallback = std::function<void(const QChatChannelGetRTCOnlineMembersResp&)>;

/// @struct QChatChannelRegUnreadCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelRegUnreadCbParam {
    ChannelUnreadCallback cb{nullptr};
    const NIMQChatChannelRegUnreadCbParam ToCParam() const {
        static ChannelUnreadCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatChannelRegUnreadCbParam param = {};
        param.cb = [](const NIMQChatChannelUnreadResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatChannelSubscribeParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelSubscribeParam {
    /// 回调函数
    ChannelSubscribeCallback cb{nullptr};
    /// 操作类型
    NIMQChatSubscribeOpeType ope_type{kNIMQChatSubscribeOpeTypeSubscribe};
    /// 订阅类型
    NIMQChatSubscribeType sub_type{kNIMQChatSubscribeTypeMsg};
    /// ID 列表
    std::vector<NIMQChatChannelIDInfo> id_infos{};
    QChatChannelSubscribeParam() = default;
    QChatChannelSubscribeParam(const NIMQChatChannelSubscribeParam& c_param) {
        ope_type = c_param.ope_type;
        sub_type = c_param.sub_type;
        for (size_t i = 0; i < c_param.id_infos_count; i++) {
            id_infos.push_back(c_param.id_infos[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelSubscribeResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelSubscribeParam ToCParam() const {
        auto cb_holder = new ChannelSubscribeCallback(cb);
        NIMQChatChannelSubscribeParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelSubscribeResp& resp) {
            InvokeCallback<ChannelSubscribeCallback, NIMQChatChannelSubscribeResp>(resp);
        };
        param.ope_type = ope_type;
        param.sub_type = sub_type;
        param.id_infos_count = id_infos.size();
        param.id_infos = const_cast<NIMQChatChannelIDInfo*>(id_infos.data());
        return param;
    }
};

/// @struct QChatChannelQueryUnreadInfoParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelQueryUnreadInfoParam {
    /// 回调函数
    ChannelQueryUnreadInfoCallback cb{nullptr};
    /// 待查询的ID列表
    std::vector<NIMQChatChannelIDInfo> id_infos{};
    QChatChannelQueryUnreadInfoParam() = default;
    QChatChannelQueryUnreadInfoParam(const NIMQChatChannelQueryUnreadInfoParam& c_param) {
        for (size_t i = 0; i < c_param.id_infos_count; i++) {
            id_infos.push_back(c_param.id_infos[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelQueryUnreadInfoResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelQueryUnreadInfoParam ToCParam() const {
        auto cb_holder = new ChannelQueryUnreadInfoCallback(cb);
        NIMQChatChannelQueryUnreadInfoParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelQueryUnreadInfoResp& resp) {
            InvokeCallback<ChannelQueryUnreadInfoCallback, NIMQChatChannelQueryUnreadInfoResp>(resp);
        };
        param.id_infos_count = id_infos.size();
        param.id_infos = const_cast<NIMQChatChannelIDInfo*>(id_infos.data());
        return param;
    }
};

/// @struct QChatChannelCreateParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCreateParam {
    /// 回调函数
    ChannelCreateCallback cb{nullptr};
    /// 频道信息
    QChatChannelInfo channel_info{};
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatChannelCreateParam() = default;
    QChatChannelCreateParam(const NIMQChatChannelCreateParam& c_param) {
        channel_info = c_param.channel_info;
        anti_spam_info = c_param.anti_spam_info;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCreateResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCreateParam ToCParam() const {
        auto cb_holder = new ChannelCreateCallback(cb);
        NIMQChatChannelCreateParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCreateResp& resp) {
            InvokeCallback<ChannelCreateCallback, NIMQChatChannelCreateResp>(resp);
        };
        param.channel_info = channel_info.ToCParam();
        param.anti_spam_info = anti_spam_info.ToCParam();
        return param;
    }
};

/// @struct QChatChannelDeleteParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelDeleteParam {
    /// 回调函数
    ChannelDeleteCallback cb{nullptr};
    /// 频道ID
    uint64_t channel_id{0};
    QChatChannelDeleteParam() = default;
    QChatChannelDeleteParam(const NIMQChatChannelDeleteParam& c_param) {
        channel_id = c_param.channel_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelDeleteResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelDeleteParam ToCParam() const {
        auto cb_holder = new ChannelDeleteCallback(cb);
        NIMQChatChannelDeleteParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelDeleteResp& resp) {
            InvokeCallback<ChannelDeleteCallback, NIMQChatChannelDeleteResp>(resp);
        };
        param.channel_id = channel_id;
        return param;
    }
};

/// @struct QChatChannelUpdateParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelUpdateParam {
    /// 回调函数
    ChannelUpdateCallback cb{nullptr};
    /// 频道ID
    uint64_t channel_id{0};
    /// 名称
    std::string name;
    /// 主题
    std::string topic;
    /// 自定义字段
    std::string custom;
    /// 查看模式
    NIMQChatChannelViewMode view_mode{kNIMQChatChannelViewModePublic};
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatChannelUpdateParam() = default;
    QChatChannelUpdateParam(const NIMQChatChannelUpdateParam& c_param) {
        channel_id = c_param.channel_id;
        name = c_param.name;
        topic = c_param.topic;
        custom = c_param.custom;
        view_mode = c_param.view_mode;
        anti_spam_info = c_param.anti_spam_info;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelUpdateResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelUpdateParam ToCParam() const {
        auto cb_holder = new ChannelUpdateCallback(cb);
        NIMQChatChannelUpdateParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelUpdateResp& resp) {
            InvokeCallback<ChannelUpdateCallback, NIMQChatChannelUpdateResp>(resp);
        };
        param.channel_id = channel_id;
        param.name = const_cast<char*>(name.c_str());
        param.topic = const_cast<char*>(topic.c_str());
        param.custom = const_cast<char*>(custom.c_str());
        param.view_mode = view_mode;
        param.anti_spam_info = anti_spam_info.ToCParam();
        return param;
    }
};

/// @struct QChatChannelUpdateCategoryInfoParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelUpdateCategoryInfoParam {
    /// 回调函数
    ChannelUpdateCategoryInfoCallback cb{nullptr};
    /// 频道ID
    uint64_t channel_id{0};
    /// 频道分组ID
    uint64_t category_id{0};
    /// 频道分组同步模式
    NIMQChatChannelSyncMode sync_mode{kNIMQChatChannelSyncModeSync};
    QChatChannelUpdateCategoryInfoParam() = default;
    QChatChannelUpdateCategoryInfoParam(const NIMQChatChannelUpdateCategoryInfoParam& c_param) {
        channel_id = c_param.channel_id;
        category_id = c_param.category_id;
        sync_mode = c_param.sync_mode;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelUpdateCategoryInfoResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelUpdateCategoryInfoParam ToCParam() const {
        auto cb_holder = new ChannelUpdateCategoryInfoCallback(cb);
        NIMQChatChannelUpdateCategoryInfoParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelUpdateCategoryInfoResp& resp) {
            InvokeCallback<ChannelUpdateCategoryInfoCallback, NIMQChatChannelUpdateCategoryInfoResp>(resp);
        };
        param.channel_id = channel_id;
        param.category_id = category_id;
        param.sync_mode = sync_mode;
        return param;
    }
};

/// @struct QChatChannelGetChannelsParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetChannelsParam {
    /// 回调函数
    GetChannelsCallback cb{nullptr};
    /// 频道id列表
    std::vector<uint64_t> channel_ids{};
    QChatChannelGetChannelsParam() = default;
    QChatChannelGetChannelsParam(const NIMQChatChannelGetChannelsParam& c_param) {
        for (auto index = 0; index < c_param.channel_ids_count; index++) {
            channel_ids.push_back(c_param.channel_ids[index]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetChannelsResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetChannelsParam ToCParam() const {
        auto cb_holder = new GetChannelsCallback(cb);
        NIMQChatChannelGetChannelsParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetChannelsResp& resp) {
            InvokeCallback<GetChannelsCallback, NIMQChatChannelGetChannelsResp>(resp);
        };
        param.channel_ids_count = channel_ids.size();
        param.channel_ids = const_cast<uint64_t*>(channel_ids.data());
        return param;
    }
};

/// @struct QChatChannelGetChannelsPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetChannelsPageParam {
    /// 回调函数
    GetChannelsPageCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelGetChannelsPageParam() = default;
    QChatChannelGetChannelsPageParam(const NIMQChatChannelGetChannelsPageParam& c_param) {
        server_id = c_param.server_id;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetChannelsPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetChannelsPageParam ToCParam() const {
        auto cb_holder = new GetChannelsPageCallback(cb);
        NIMQChatChannelGetChannelsPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetChannelsPageResp& resp) {
            InvokeCallback<GetChannelsPageCallback, NIMQChatChannelGetChannelsPageResp>(resp);
        };
        param.server_id = server_id;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelGetMembersPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetMembersPageParam {
    /// 回调函数
    ChannelGetMembersPageCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelGetMembersPageParam() = default;
    QChatChannelGetMembersPageParam(const NIMQChatChannelGetMembersPageParam c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetMembersPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetMembersPageParam ToCParam() const {
        auto cb_holder = new ChannelGetMembersPageCallback(cb);
        NIMQChatChannelGetMembersPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetMembersPageResp& resp) {
            InvokeCallback<ChannelGetMembersPageCallback, NIMQChatChannelGetMembersPageResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelUpdateWhiteBlackRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelUpdateWhiteBlackRoleParam {
    /// 回调函数
    UpdateWhiteBlackRoleCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 身份组id
    uint64_t role_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type{kNIMQChatChannelWhiteBlackOpeTypeAdd};
    QChatChannelUpdateWhiteBlackRoleParam() = default;
    QChatChannelUpdateWhiteBlackRoleParam(const NIMQChatChannelUpdateWhiteBlackRoleParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        role_id = c_param.role_id;
        type = c_param.type;
        ope_type = c_param.ope_type;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelUpdateWhiteBlackRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelUpdateWhiteBlackRoleParam ToCParam() const {
        auto cb_holder = new UpdateWhiteBlackRoleCallback(cb);
        NIMQChatChannelUpdateWhiteBlackRoleParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelUpdateWhiteBlackRoleResp& resp) {
            InvokeCallback<UpdateWhiteBlackRoleCallback, NIMQChatChannelUpdateWhiteBlackRoleResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.role_id = role_id;
        param.type = type;
        param.ope_type = ope_type;
        return param;
    }
};

/// @struct QChatChannelUpdateWhiteBlackMembersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelUpdateWhiteBlackMembersParam {
    /// 回调函数
    UpdateWhiteBlackMembersCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 用户accid列表
    std::list<std::string> accids;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type{kNIMQChatChannelWhiteBlackOpeTypeAdd};
    QChatChannelUpdateWhiteBlackMembersParam() = default;
    QChatChannelUpdateWhiteBlackMembersParam(const NIMQChatChannelUpdateWhiteBlackMembersParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
        type = c_param.type;
        ope_type = c_param.ope_type;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelUpdateWhiteBlackMembersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelUpdateWhiteBlackMembersParam ToCParam() const {
        auto cb_holder = new UpdateWhiteBlackMembersCallback(cb);
        NIMQChatChannelUpdateWhiteBlackMembersParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelUpdateWhiteBlackMembersResp& resp) {
            InvokeCallback<UpdateWhiteBlackMembersCallback, NIMQChatChannelUpdateWhiteBlackMembersResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        accids_vec.clear();
        for (auto&& accid : accids)
            accids_vec.push_back(const_cast<char*>(accid.c_str()));
        param.accids_count = accids_vec.size();
        param.accids = accids_vec.data();
        param.type = type;
        param.ope_type = ope_type;
        return param;
    }

protected:
    mutable std::vector<char*> accids_vec;
};

/// @struct QChatChannelGetWhiteBlackRolesPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetWhiteBlackRolesPageParam {
    /// 回调函数
    GetWhiteBlackRolesPageCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
    QChatChannelGetWhiteBlackRolesPageParam() = default;
    QChatChannelGetWhiteBlackRolesPageParam(const NIMQChatChannelGetWhiteBlackRolesPageParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        type = c_param.type;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetWhiteBlackRolesPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetWhiteBlackRolesPageParam ToCParam() const {
        auto cb_holder = new GetWhiteBlackRolesPageCallback(cb);
        NIMQChatChannelGetWhiteBlackRolesPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetWhiteBlackRolesPageResp& resp) {
            InvokeCallback<GetWhiteBlackRolesPageCallback, NIMQChatChannelGetWhiteBlackRolesPageResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.type = type;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelGetWhiteBlackMembersPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetWhiteBlackMembersPageParam {
    /// 回调函数
    GetWhiteBlackMembersPageCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
    QChatChannelGetWhiteBlackMembersPageParam() = default;
    QChatChannelGetWhiteBlackMembersPageParam(const NIMQChatChannelGetWhiteBlackMembersPageParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        type = c_param.type;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetWhiteBlackMembersPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetWhiteBlackMembersPageParam ToCParam() const {
        auto cb_holder = new GetWhiteBlackMembersPageCallback(cb);
        NIMQChatChannelGetWhiteBlackMembersPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetWhiteBlackMembersPageResp& resp) {
            InvokeCallback<GetWhiteBlackMembersPageCallback, NIMQChatChannelGetWhiteBlackMembersPageResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.type = type;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelGetExistingWhiteBlackRolesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetExistingWhiteBlackRolesParam {
    /// 回调函数
    GetExistingWhiteBlackRolesCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 身份组id列表
    std::list<uint64_t> role_ids;
    QChatChannelGetExistingWhiteBlackRolesParam() = default;
    QChatChannelGetExistingWhiteBlackRolesParam(const NIMQChatChannelGetExistingWhiteBlackRolesParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        type = c_param.type;
        for (size_t i = 0; i < c_param.role_ids_count; i++)
            role_ids.push_back(c_param.role_ids[i]);
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetExistingWhiteBlackRolesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetExistingWhiteBlackRolesParam ToCParam() const {
        auto cb_holder = new GetExistingWhiteBlackRolesCallback(cb);
        NIMQChatChannelGetExistingWhiteBlackRolesParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetExistingWhiteBlackRolesResp& resp) {
            InvokeCallback<GetExistingWhiteBlackRolesCallback, NIMQChatChannelGetExistingWhiteBlackRolesResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.type = type;
        role_ids_vec.clear();
        for (auto&& role_id : role_ids)
            role_ids_vec.push_back(role_id);
        param.role_ids_count = role_ids_vec.size();
        param.role_ids = role_ids_vec.data();
        return param;
    }

protected:
    mutable std::vector<uint64_t> role_ids_vec;
};

/// @struct QChatChannelGetExistingWhiteBlackMembersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetExistingWhiteBlackMembersParam {
    /// 回调函数
    GetExistingWhiteBlackMembersCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 频道ID
    uint64_t channel_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 用户accid列表
    std::list<std::string> accids;
    QChatChannelGetExistingWhiteBlackMembersParam() = default;
    QChatChannelGetExistingWhiteBlackMembersParam(const NIMQChatChannelGetExistingWhiteBlackMembersParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        type = c_param.type;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetExistingWhiteBlackMembersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetExistingWhiteBlackMembersParam ToCParam() const {
        auto cb_holder = new GetExistingWhiteBlackMembersCallback(cb);
        NIMQChatChannelGetExistingWhiteBlackMembersParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetExistingWhiteBlackMembersResp& resp) {
            InvokeCallback<GetExistingWhiteBlackMembersCallback, NIMQChatChannelGetExistingWhiteBlackMembersResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.type = type;
        accids_vec.clear();
        for (auto&& accid : accids)
            accids_vec.push_back(const_cast<char*>(accid.c_str()));
        param.accids_count = accids_vec.size();
        param.accids = accids_vec.data();
        return param;
    }

protected:
    mutable std::vector<char*> accids_vec;
};

/// @struct QChatChannelSearchPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelSearchPageParam {
    /// 回调函数
    ChannelSearchPageCallback cb{nullptr};
    /// 服务器 id, 若为空则表示在所有服务器下可见频道中搜索
    uint64_t server_id{0};
    /// 搜索内容
    std::string keyword{""};
    /// 起始时间
    uint64_t start_time{0};
    /// 结束时间
    uint64_t end_time{0};
    /// 排序规则
    NIMQChatSearchOrder order{kNIMQChatSearchOrderAsc};
    /// 排序规则
    NIMQChatChannelSearchSort sort{kNIMQChatChannelSearchSortCreateTime};
    /// 查询条数
    uint32_t limit{100};
    /// 查询游标, 查询的起始位置
    std::string cursor{""};
    QChatChannelSearchPageParam() = default;
    QChatChannelSearchPageParam(const NIMQChatChannelSearchPageParam& c_param) {
        server_id = c_param.server_id;
        keyword = c_param.keyword ? c_param.keyword : "";
        start_time = c_param.start_time;
        end_time = c_param.end_time;
        order = c_param.order;
        sort = c_param.sort;
        limit = c_param.limit;
        cursor = c_param.cursor ? c_param.cursor : "";
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelSearchPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelSearchPageParam ToCParam() const {
        auto cb_holder = new ChannelSearchPageCallback(cb);
        NIMQChatChannelSearchPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelSearchPageResp& resp) {
            InvokeCallback<ChannelSearchPageCallback, NIMQChatChannelSearchPageResp>(resp);
        };
        param.server_id = server_id;
        param.keyword = const_cast<char*>(keyword.c_str());
        param.start_time = start_time;
        param.end_time = end_time;
        param.order = order;
        param.sort = sort;
        param.limit = limit;
        param.cursor = const_cast<char*>(cursor.c_str());
        return param;
    }
};

/// @struct QChatChannelMemberSearchParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelMemberSearchParam {
    /// 回调函数
    ChannelMemberSearchCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 频道 id
    uint64_t channel_id{0};
    /// 搜索内容
    std::string keyword{""};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelMemberSearchParam() = default;
    QChatChannelMemberSearchParam(const NIMQChatChannelMemberSearchParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        keyword = c_param.keyword;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelMemberSearchResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelMemberSearchParam ToCParam() const {
        auto cb_holder = new ChannelMemberSearchCallback(cb);
        NIMQChatChannelMemberSearchParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelMemberSearchResp& resp) {
            InvokeCallback<ChannelMemberSearchCallback, NIMQChatChannelMemberSearchResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.keyword = const_cast<char*>(keyword.c_str());
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelCategoryCreateParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryCreateParam {
    /// 回调函数
    ChannelCategoryCreateCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 名称
    std::string name{""};
    /// 自定义字段
    std::string custom{""};
    /// 查看模式
    NIMQChatChannelViewMode view_mode{kNIMQChatChannelViewModePublic};
    QChatChannelCategoryCreateParam() = default;
    QChatChannelCategoryCreateParam(const NIMQChatChannelCategoryCreateParam& c_param) {
        server_id = c_param.server_id;
        name = c_param.name;
        custom = c_param.custom;
        view_mode = c_param.view_mode;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryCreateResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryCreateParam ToCParam() const {
        auto cb_holder = new ChannelCategoryCreateCallback(cb);
        NIMQChatChannelCategoryCreateParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryCreateResp& resp) {
            InvokeCallback<ChannelCategoryCreateCallback, NIMQChatChannelCategoryCreateResp>(resp);
        };
        param.server_id = server_id;
        param.name = const_cast<char*>(name.c_str());
        param.custom = const_cast<char*>(custom.c_str());
        param.view_mode = view_mode;
        return param;
    }
};

/// @struct QChatChannelCategoryRemoveParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryRemoveParam {
    /// 回调函数
    ChannelCategoryRemoveCallback cb{nullptr};
    /// 频道分组 ID
    uint64_t category_id{0};
    QChatChannelCategoryRemoveParam() = default;
    QChatChannelCategoryRemoveParam(const NIMQChatChannelCategoryRemoveParam& c_param) {
        category_id = c_param.category_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryRemoveResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryRemoveParam ToCParam() const {
        auto cb_holder = new ChannelCategoryRemoveCallback(cb);
        NIMQChatChannelCategoryRemoveParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryRemoveResp& resp) {
            InvokeCallback<ChannelCategoryRemoveCallback, NIMQChatChannelCategoryRemoveResp>(resp);
        };
        param.category_id = category_id;
        return param;
    }
};

/// @struct QChatChannelCategoryUpdateParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryUpdateParam {
    /// 回调函数
    ChannelCategoryUpdateCallback cb{nullptr};
    /// 分组 id
    uint64_t category_id{0};
    /// 名称
    std::string name{""};
    /// 自定义字段
    std::string custom{""};
    /// 查看模式
    NIMQChatChannelViewMode view_mode{kNIMQChatChannelViewModePublic};
    QChatChannelCategoryUpdateParam() = default;
    QChatChannelCategoryUpdateParam(const NIMQChatChannelCategoryUpdateParam& c_param) {
        category_id = c_param.category_id;
        name = c_param.name;
        custom = c_param.custom;
        view_mode = c_param.view_mode;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryUpdateResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryUpdateParam ToCParam() const {
        auto cb_holder = new ChannelCategoryUpdateCallback(cb);
        NIMQChatChannelCategoryUpdateParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryUpdateResp& resp) {
            InvokeCallback<ChannelCategoryUpdateCallback, NIMQChatChannelCategoryUpdateResp>(resp);
        };
        param.category_id = category_id;
        param.name = const_cast<char*>(name.c_str());
        param.custom = const_cast<char*>(custom.c_str());
        param.view_mode = view_mode;
        return param;
    }
};

/// @struct QChatChannelGetCategoriesByIDParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetCategoriesByIDParam {
    /// 回调函数
    ChannelGetCategoriesByIDCallback cb{nullptr};
    /// 分组ID列表
    std::vector<uint64_t> category_ids;
    QChatChannelGetCategoriesByIDParam() = default;
    QChatChannelGetCategoriesByIDParam(const NIMQChatChannelGetCategoriesByIDParam& c_param) {
        for (size_t i = 0; i < c_param.category_ids_count; i++)
            category_ids.push_back(c_param.category_ids[i]);
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetCategoriesByIDResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetCategoriesByIDParam ToCParam() const {
        auto cb_holder = new ChannelGetCategoriesByIDCallback(cb);
        NIMQChatChannelGetCategoriesByIDParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetCategoriesByIDResp& resp) {
            InvokeCallback<ChannelGetCategoriesByIDCallback, NIMQChatChannelGetCategoriesByIDResp>(resp);
        };
        param.category_ids = const_cast<uint64_t*>(category_ids.data());
        param.category_ids_count = category_ids.size();
        return param;
    }
};

/// @struct QChatChannelGetCategoriesPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetCategoriesPageParam {
    /// 回调函数
    ChannelGetCategoriesPageCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelGetCategoriesPageParam() = default;
    QChatChannelGetCategoriesPageParam(const NIMQChatChannelGetCategoriesPageParam& c_param) {
        server_id = c_param.server_id;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetCategoriesPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetCategoriesPageParam ToCParam() const {
        auto cb_holder = new ChannelGetCategoriesPageCallback(cb);
        NIMQChatChannelGetCategoriesPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetCategoriesPageResp& resp) {
            InvokeCallback<ChannelGetCategoriesPageCallback, NIMQChatChannelGetCategoriesPageResp>(resp);
        };
        param.server_id = server_id;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelGetCategoryChannelsPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetCategoryChannelsPageParam {
    /// 回调函数
    ChannelGetCategoryChannelsPageCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 分组 id
    uint64_t category_id{0};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelGetCategoryChannelsPageParam() = default;
    QChatChannelGetCategoryChannelsPageParam(const NIMQChatChannelGetCategoryChannelsPageParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetCategoryChannelsPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetCategoryChannelsPageParam ToCParam() const {
        auto cb_holder = new ChannelGetCategoryChannelsPageCallback(cb);
        NIMQChatChannelGetCategoryChannelsPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetCategoryChannelsPageResp& resp) {
            InvokeCallback<ChannelGetCategoryChannelsPageCallback, NIMQChatChannelGetCategoryChannelsPageResp>(resp);
        };
        param.server_id = server_id;
        param.category_id = category_id;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelCategoryUpdateWhiteBlackRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryUpdateWhiteBlackRoleParam {
    /// 回调函数
    ChannelCategoryUpdateWhiteBlackRoleCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 分组 id
    uint64_t category_id{0};
    /// 身份组 id
    uint64_t role_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type{kNIMQChatChannelWhiteBlackOpeTypeAdd};
    QChatChannelCategoryUpdateWhiteBlackRoleParam() = default;
    QChatChannelCategoryUpdateWhiteBlackRoleParam(const NIMQChatChannelCategoryUpdateWhiteBlackRoleParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        role_id = c_param.role_id;
        type = c_param.type;
        ope_type = c_param.ope_type;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryUpdateWhiteBlackRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryUpdateWhiteBlackRoleParam ToCParam() const {
        auto cb_holder = new ChannelCategoryUpdateWhiteBlackRoleCallback(cb);
        NIMQChatChannelCategoryUpdateWhiteBlackRoleParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryUpdateWhiteBlackRoleResp& resp) {
            InvokeCallback<ChannelCategoryUpdateWhiteBlackRoleCallback, NIMQChatChannelCategoryUpdateWhiteBlackRoleResp>(resp);
        };
        param.server_id = server_id;
        param.category_id = category_id;
        param.role_id = role_id;
        param.type = type;
        param.ope_type = ope_type;
        return param;
    }
};

/// @struct QChatChannelCategoryGetWhiteBlackRolesPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetWhiteBlackRolesPageParam {
    /// 获取频道分组白/黑名单身份组回调
    ChannelCategoryGetWhiteBlackRolesPageCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 分组ID
    uint64_t category_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelCategoryGetWhiteBlackRolesPageParam() = default;
    QChatChannelCategoryGetWhiteBlackRolesPageParam(const NIMQChatChannelCategoryGetWhiteBlackRolesPageParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        type = c_param.type;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryGetWhiteBlackRolesPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryGetWhiteBlackRolesPageParam ToCParam() const {
        auto cb_holder = new ChannelCategoryGetWhiteBlackRolesPageCallback(cb);
        NIMQChatChannelCategoryGetWhiteBlackRolesPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryGetWhiteBlackRolesPageResp& resp) {
            InvokeCallback<ChannelCategoryGetWhiteBlackRolesPageCallback, NIMQChatChannelCategoryGetWhiteBlackRolesPageResp>(resp);
        };
        param.server_id = server_id;
        param.category_id = category_id;
        param.type = type;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelCategoryGetExistingWhiteBlackRolesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetExistingWhiteBlackRolesParam {
    /// 获取频道分组白/黑名单身份组回调
    ChannelCategoryGetExistingWhiteBlackRolesCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 分组ID
    uint64_t category_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 身份组ID列表
    std::vector<uint64_t> role_ids;
    QChatChannelCategoryGetExistingWhiteBlackRolesParam() = default;
    QChatChannelCategoryGetExistingWhiteBlackRolesParam(const NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        type = c_param.type;
        for (size_t i = 0; i < c_param.role_ids_count; i++)
            role_ids.push_back(c_param.role_ids[i]);
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryGetExistingWhiteBlackRolesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam ToCParam() const {
        auto cb_holder = new ChannelCategoryGetExistingWhiteBlackRolesCallback(cb);
        NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp& resp) {
            InvokeCallback<ChannelCategoryGetExistingWhiteBlackRolesCallback, NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp>(resp);
        };
        param.server_id = server_id;
        param.category_id = category_id;
        param.type = type;
        param.role_ids = const_cast<uint64_t*>(role_ids.data());
        param.role_ids_count = role_ids.size();
        return param;
    }
};

/// @struct QChatChannelCategoryUpdateWhiteBlackMembersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryUpdateWhiteBlackMembersParam {
    /// 更新频道分组白/黑名单成员回调
    ChannelCategoryUpdateWhiteBlackMembersCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 分组ID
    uint64_t category_id{0};
    /// 成员ID列表
    std::list<std::string> accids;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type{kNIMQChatChannelWhiteBlackOpeTypeAdd};
    QChatChannelCategoryUpdateWhiteBlackMembersParam() = default;
    QChatChannelCategoryUpdateWhiteBlackMembersParam(const NIMQChatChannelCategoryUpdateWhiteBlackMembersParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
        type = c_param.type;
        ope_type = c_param.ope_type;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryUpdateWhiteBlackMembersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryUpdateWhiteBlackMembersParam ToCParam() const {
        auto cb_holder = new ChannelCategoryUpdateWhiteBlackMembersCallback(cb);
        NIMQChatChannelCategoryUpdateWhiteBlackMembersParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryUpdateWhiteBlackMembersResp& resp) {
            InvokeCallback<ChannelCategoryUpdateWhiteBlackMembersCallback, NIMQChatChannelCategoryUpdateWhiteBlackMembersResp>(resp);
        };
        vec_accids.clear();
        for (auto& accid : accids)
            vec_accids.push_back(const_cast<char*>(accid.c_str()));
        param.accids = const_cast<char**>(vec_accids.data());
        param.accids_count = vec_accids.size();
        param.server_id = server_id;
        param.category_id = category_id;
        param.type = type;
        param.ope_type = ope_type;
        return param;
    }

protected:
    mutable std::vector<char*> vec_accids;
};

/// @struct QChatChannelCategoryGetWhiteBlackMembersPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetWhiteBlackMembersPageParam {
    /// 获取频道分组白/黑名单成员回调
    ChannelCategoryGetWhiteBlackMembersPageCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 分组ID
    uint64_t category_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatChannelCategoryGetWhiteBlackMembersPageParam() = default;
    QChatChannelCategoryGetWhiteBlackMembersPageParam(const NIMQChatChannelCategoryGetWhiteBlackMembersPageParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        type = c_param.type;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryGetWhiteBlackMembersPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryGetWhiteBlackMembersPageParam ToCParam() const {
        auto cb_holder = new ChannelCategoryGetWhiteBlackMembersPageCallback(cb);
        NIMQChatChannelCategoryGetWhiteBlackMembersPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryGetWhiteBlackMembersPageResp& resp) {
            InvokeCallback<ChannelCategoryGetWhiteBlackMembersPageCallback, NIMQChatChannelCategoryGetWhiteBlackMembersPageResp>(resp);
        };
        param.server_id = server_id;
        param.category_id = category_id;
        param.type = type;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatChannelCategoryGetExistingWhiteBlackMembersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryGetExistingWhiteBlackMembersParam {
    /// 获取频道分组白/黑名单成员回调
    ChannelCategoryGetExistingWhiteBlackMembersCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 分组ID
    uint64_t category_id{0};
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type{kNIMQChatChannelBlack};
    /// 成员ID列表
    std::list<std::string> accids;
    QChatChannelCategoryGetExistingWhiteBlackMembersParam() = default;
    QChatChannelCategoryGetExistingWhiteBlackMembersParam(const NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        type = c_param.type;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelCategoryGetExistingWhiteBlackMembersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam ToCParam() const {
        auto cb_holder = new ChannelCategoryGetExistingWhiteBlackMembersCallback(cb);
        NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelCategoryGetWhiteBlackMembersResp& resp) {
            InvokeCallback<ChannelCategoryGetExistingWhiteBlackMembersCallback, NIMQChatChannelCategoryGetWhiteBlackMembersResp>(resp);
        };
        vec_accids.clear();
        for (auto& accid : accids)
            vec_accids.push_back(const_cast<char*>(accid.c_str()));
        param.accids = const_cast<char**>(vec_accids.data());
        param.accids_count = vec_accids.size();
        param.server_id = server_id;
        param.category_id = category_id;
        param.type = type;
        return param;
    }

protected:
    mutable std::vector<char*> vec_accids;
};

/// @struct QChatChannelUpdateRTCInfoParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelUpdateRTCInfoParam {
    /// 修改RTC频道参数回调
    ChannelUpdateRTCInfoCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 频道 ID
    uint64_t channel_id{0};
    /// RTC频道参数
    QChatChannelRTCInfo rtc_info{};
    QChatChannelUpdateRTCInfoParam() = default;
    QChatChannelUpdateRTCInfoParam(const NIMQChatChannelUpdateRTCInfoParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        rtc_info = c_param.rtc_info;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelUpdateRTCInfoResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelUpdateRTCInfoParam ToCParam() const {
        auto cb_holder = new ChannelUpdateRTCInfoCallback(cb);
        NIMQChatChannelUpdateRTCInfoParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelUpdateRTCInfoResp& resp) {
            InvokeCallback<ChannelUpdateRTCInfoCallback, NIMQChatChannelUpdateRTCInfoResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        param.rtc_info = rtc_info.ToCParam();
        return param;
    }
};

/// @struct QChatChannelGetRTCInfoParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetRTCInfoParam {
    /// 查询RTC频道参数回调
    ChannelGetRTCInfoCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 频道 ID
    uint64_t channel_id{0};
    QChatChannelGetRTCInfoParam() = default;
    QChatChannelGetRTCInfoParam(const NIMQChatChannelGetRTCInfoParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetRTCInfoResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetRTCInfoParam ToCParam() const {
        auto cb_holder = new ChannelGetRTCInfoCallback(cb);
        NIMQChatChannelGetRTCInfoParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetRTCInfoResp& resp) {
            InvokeCallback<ChannelGetRTCInfoCallback, NIMQChatChannelGetRTCInfoResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        return param;
    }
};

/// @struct QChatChannelGetRTCOnlineMembersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelGetRTCOnlineMembersParam {
    /// 获取RTC在线成员列表回调
    ChannelGetRTCOnlineMembersCallback cb{nullptr};
    /// 服务器 ID
    uint64_t server_id{0};
    /// 频道 ID
    uint64_t channel_id{0};
    QChatChannelGetRTCOnlineMembersParam() = default;
    QChatChannelGetRTCOnlineMembersParam(const NIMQChatChannelGetRTCOnlineMembersParam& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatChannelGetRTCOnlineMembersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatChannelGetRTCOnlineMembersParam ToCParam() const {
        auto cb_holder = new ChannelGetRTCOnlineMembersCallback(cb);
        NIMQChatChannelGetRTCOnlineMembersParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatChannelGetRTCOnlineMembersResp& resp) {
            InvokeCallback<ChannelGetRTCOnlineMembersCallback, NIMQChatChannelGetRTCOnlineMembersResp>(resp);
        };
        param.server_id = server_id;
        param.channel_id = channel_id;
        return param;
    }
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_CHANNEL_CPP_DEF_H__
