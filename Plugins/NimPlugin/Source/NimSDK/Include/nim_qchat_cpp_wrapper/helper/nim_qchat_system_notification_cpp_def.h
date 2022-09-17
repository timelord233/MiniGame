/**
 * @file nim_qchat_system_notification_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SYSTEM_NOTIFICATION_CPP_DEF_H__
#define __NIM_QCHAT_SYSTEM_NOTIFICATION_CPP_DEF_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_channel_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_message_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_server_cpp_def.h"
#include "nim_qchat_system_notification_def.h"

namespace nim_qchat {

/// @struct QChatSystemNotificationDataBase 系统消息不包含额外数据
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataBase {
    virtual ~QChatSystemNotificationDataBase(){};
};

/// @struct QChatSystemNotificationDataServerInvite 系统消息为邀请服务器成员时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerInvite : QChatSystemNotificationDataBase {
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataServerInvite() = default;
    QChatSystemNotificationDataServerInvite(const NIMQChatSystemNotificationDataServerInvite& c_param) { request_id = c_param.request_id; }
};

/// @struct QChatSystemNotificationDataServerInviteReject 系统消息为拒绝服务器成员邀请时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerInviteReject : QChatSystemNotificationDataBase {
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataServerInviteReject() = default;
    QChatSystemNotificationDataServerInviteReject(const NIMQChatSystemNotificationDataServerInviteReject& c_param) {
        request_id = c_param.request_id;
    }
};

/// @struct QChatSystemNotificationDataServerApply 系统消息为申请加入服务器时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerApply : QChatSystemNotificationDataBase {
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataServerApply() = default;
    QChatSystemNotificationDataServerApply(const NIMQChatSystemNotificationDataServerApply& c_param) { request_id = c_param.request_id; }
};

/// @struct QChatSystemNotificationDataServerApplyReject 系统消息为拒绝申请加入服务器时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerApplyReject : QChatSystemNotificationDataBase {
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataServerApplyReject() = default;
    QChatSystemNotificationDataServerApplyReject(const NIMQChatSystemNotificationDataServerApplyReject& c_param) { request_id = c_param.request_id; }
};

/// @struct QChatSystemNotificationDataServerCreate 系统消息为创建服务器时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerCreate : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    QChatSystemNotificationDataServerCreate() = default;
    QChatSystemNotificationDataServerCreate(const NIMQChatSystemNotificationDataServerCreate& c_param) { server_info = c_param.server_info; }
};

/// @struct QChatSystemNotificationDataServerUpdate 系统消息为更新服务器时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerUpdate : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    QChatSystemNotificationDataServerUpdate() = default;
    QChatSystemNotificationDataServerUpdate(const NIMQChatSystemNotificationDataServerUpdate& c_param) { server_info = c_param.server_info; }
};

/// @struct QChatSystemNotificationDataChannelCreate 系统消息为创建频道时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelCreate : QChatSystemNotificationDataBase {
    /// 圈组频道信息
    QChatChannelInfo channel_info;
    QChatSystemNotificationDataChannelCreate() = default;
    QChatSystemNotificationDataChannelCreate(const NIMQChatSystemNotificationDataChannelCreate& c_param) { channel_info = c_param.channel_info; }
};

/// @struct QChatSystemNotificationDataChannelUpdate 系统消息为更新频道时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelUpdate : QChatSystemNotificationDataBase {
    /// 圈组频道信息
    QChatChannelInfo channel_info;
    QChatSystemNotificationDataChannelUpdate() = default;
    QChatSystemNotificationDataChannelUpdate(const NIMQChatSystemNotificationDataChannelUpdate& c_param) { channel_info = c_param.channel_info; }
};

/// @struct QChatSystemNotificationDataMemberInviteDone 系统消息为邀请完成时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberInviteDone : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    /// 邀请的accid列表
    std::list<std::string> invite_accids;
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataMemberInviteDone() = default;
    QChatSystemNotificationDataMemberInviteDone(const NIMQChatSystemNotificationDataMemberInviteDone& c_param) {
        server_info = c_param.server_info;
        if (c_param.invite_accids) {
            nim::JsonArrayStringToList(c_param.invite_accids, invite_accids);
        }
        request_id = c_param.request_id;
    }
};

/// @struct QChatSystemNotificationDataMemberInviteAccept 系统消息为邀请接受时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberInviteAccept : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    /// 邀请的accid
    std::string invite_accid;
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataMemberInviteAccept() = default;
    QChatSystemNotificationDataMemberInviteAccept(const NIMQChatSystemNotificationDataMemberInviteAccept& c_param) {
        server_info = c_param.server_info;
        invite_accid = c_param.invite_accid ? c_param.invite_accid : "";
        request_id = c_param.request_id;
    }
};

/// @struct QChatSystemNotificationDataMemberApplyDone 系统消息为申请完成时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberApplyDone : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataMemberApplyDone() = default;
    QChatSystemNotificationDataMemberApplyDone(const NIMQChatSystemNotificationDataMemberApplyDone& c_param) {
        server_info = c_param.server_info;
        request_id = c_param.request_id;
    }
};

/// @struct QChatSystemNotificationDataMemberApplyAccept 系统消息为申请接受时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberApplyAccept : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    /// 申请的accid
    std::string apply_accid;
    /// 请求ID
    uint64_t request_id{0};
    QChatSystemNotificationDataMemberApplyAccept() = default;
    QChatSystemNotificationDataMemberApplyAccept(const NIMQChatSystemNotificationDataMemberApplyAccept& c_param) {
        server_info = c_param.server_info;
        apply_accid = c_param.apply_accid ? c_param.apply_accid : "";
        request_id = c_param.request_id;
    }
};

/// @struct QChatSystemNotificationDataMemberKick 系统消息为踢出服务器成员时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberKick : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    /// 被踢的accid列表
    std::list<std::string> kick_accids;
    QChatSystemNotificationDataMemberKick() = default;
    QChatSystemNotificationDataMemberKick(const NIMQChatSystemNotificationDataMemberKick& c_param) {
        server_info = c_param.server_info;
        if (c_param.kick_accids)
            nim::JsonArrayStringToList(c_param.kick_accids, kick_accids);
    }
};

/// @struct QChatSystemNotificationDataMemberLeave 系统消息为服务器成员离开时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberLeave : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info;
    QChatSystemNotificationDataMemberLeave() = default;
    QChatSystemNotificationDataMemberLeave(const NIMQChatSystemNotificationDataMemberLeave& c_param) { server_info = c_param.server_info; }
};

/// @struct QChatSystemNotificationDataMemberUpdate 系统消息为服务器成员更新时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberUpdate : QChatSystemNotificationDataBase {
    /// 圈组成员信息
    QChatMemberInfo member_info;
    QChatSystemNotificationDataMemberUpdate() = default;
    QChatSystemNotificationDataMemberUpdate(const NIMQChatSystemNotificationDataMemberUpdate& c_param) { member_info = c_param.member_info; }
};

/// @struct QChatSystemNotificationDataWhiteBlackRoleUpdate 系统消息为频道白/黑名单身份组更新时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataWhiteBlackRoleUpdate : QChatSystemNotificationDataBase {
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 身份组id
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
    QChatSystemNotificationDataWhiteBlackRoleUpdate() = default;
    QChatSystemNotificationDataWhiteBlackRoleUpdate(const NIMQChatSystemNotificationDataWhiteBlackRoleUpdate& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        role_id = c_param.role_id;
        type = c_param.type;
        ope_type = c_param.ope_type;
    }
};

/// @struct QChatSystemNotificationDataWhiteBlackMembersUpdate 系统消息为频道白/黑名单成员更新时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataWhiteBlackMembersUpdate : QChatSystemNotificationDataBase {
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 成员列表
    std::list<std::string> accids;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
    QChatSystemNotificationDataWhiteBlackMembersUpdate() = default;
    QChatSystemNotificationDataWhiteBlackMembersUpdate(const NIMQChatSystemNotificationDataWhiteBlackMembersUpdate& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
        type = c_param.type;
        ope_type = c_param.ope_type;
    }
};

/// @struct QChatSystemNotificationDataQuickCommentChanged 系统消息为快捷评论更新时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataQuickCommentChanged : QChatSystemNotificationDataBase {
    /// 服务器ID
    uint64_t server_id = 0;
    /// 频道ID
    uint64_t channel_id = 0;
    /// 发送者accid
    std::string msg_sender_accid;
    /// 消息id
    uint64_t msg_server_id;
    /// 消息时间戳
    uint64_t msg_timestamp;
    /// 消息类型
    uint64_t type;
    /// 操作类型
    NIMQChatQuickCommentOperation operate_type;
    /// 操作者
    std::string operator_accid;
    QChatSystemNotificationDataQuickCommentChanged() = default;
    QChatSystemNotificationDataQuickCommentChanged(const NIMQChatSystemNotificationDataQuickCommentChanged& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        msg_sender_accid = c_param.msg_sender_accid;
        msg_server_id = c_param.msg_server_id;
        msg_timestamp = c_param.msg_timestamp;
        type = c_param.type;
        operate_type = c_param.operate_type;
        operator_accid = c_param.operator_accid;
    }
};

/// @struct QChatSystemNotificationDataChannelCategoryCreate 系统消息为创建频道分组的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelCategoryCreate : QChatSystemNotificationDataBase {
    /// 圈组频道分组信息
    QChatChannelCategoryInfo category_info;
    QChatSystemNotificationDataChannelCategoryCreate() = default;
    QChatSystemNotificationDataChannelCategoryCreate(const NIMQChatSystemNotificationDataChannelCategoryCreate& c_param) {
        category_info = c_param.category_info;
    }
};

/// @struct QChatSystemNotificationDataChannelCategoryRemove 系统消息为删除频道分组的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelCategoryRemove : QChatSystemNotificationDataBase {
    /// 圈组频道分组ID
    uint64_t category_id;
    QChatSystemNotificationDataChannelCategoryRemove() = default;
    QChatSystemNotificationDataChannelCategoryRemove(const NIMQChatSystemNotificationDataChannelCategoryRemove& c_param) {
        category_id = c_param.category_id;
    }
};

/// @struct QChatSystemNotificationDataChannelCategoryUpdate
using QChatSystemNotificationDataChannelCategoryUpdate = QChatSystemNotificationDataChannelCategoryCreate;

/// @struct QChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate 系统消息为频道分组白/黑名单身份组更新时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate : QChatSystemNotificationDataBase {
    /// 服务器ID
    uint64_t server_id;
    /// 频道分组ID
    uint64_t category_id;
    /// 身份组ID
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
    QChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate() = default;
    QChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate(const NIMQChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        role_id = c_param.role_id;
        type = c_param.type;
        ope_type = c_param.ope_type;
    }
};

/// @struct QChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate 系统消息为频道分组白/黑名单成员更新时的数据结构体
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate : QChatSystemNotificationDataBase {
    /// 服务器ID
    uint64_t server_id;
    /// 频道分组ID
    uint64_t category_id;
    /// 成员列表
    std::list<std::string> accids;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
    QChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate() = default;
    QChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate(
        const NIMQChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate& c_param) {
        server_id = c_param.server_id;
        category_id = c_param.category_id;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
        type = c_param.type;
        ope_type = c_param.ope_type;
    }
};

/// @struct QChatSystemNotificationDataServerRoleAddMember 系统消息为成员加入服务器身份组
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerRoleAddMember : QChatSystemNotificationDataBase {
    /// 服务器id
    uint64_t server_id;
    /// 身份组id
    uint64_t role_id;
    /// accid列表
    std::list<std::string> accids;
    QChatSystemNotificationDataServerRoleAddMember() = default;
    QChatSystemNotificationDataServerRoleAddMember(const NIMQChatSystemNotificationDataServerRoleAddMember& c_param) {
        server_id = c_param.server_id;
        role_id = c_param.role_id;
        for (size_t i = 0; i < c_param.accids_count; i++)
            accids.push_back(c_param.accids[i]);
    }
};

/// @struct QChatSystemNotificationDataServerRoleRemoveMember 系统消息为成员离开服务器身份组
using QChatSystemNotificationDataServerRoleRemoveMember = QChatSystemNotificationDataServerRoleAddMember;

/// @struct QChatSystemNotificationDataServerRolePermissionChange 系统消息为服务器身份组权限变更
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerRolePermissionChange : QChatSystemNotificationDataBase {
    /// 服务器id
    uint64_t server_id;
    /// 身份组id
    uint64_t role_id;
    /// 变更的权限
    QChatPermission permissions{};
    QChatSystemNotificationDataServerRolePermissionChange() = default;
    QChatSystemNotificationDataServerRolePermissionChange(const NIMQChatSystemNotificationDataServerRolePermissionChange& c_param) {
        server_id = c_param.server_id;
        role_id = c_param.role_id;
        for (size_t i = 0; i < c_param.permissions_count; i++) {
            auto permission = c_param.permissions[i].permission;
            auto option = c_param.permissions[i].option;
            permissions.emplace(permission, option);
        }
    }
};

/// @struct QChatSystemNotificationDataChannelRolePermissionChange 系统消息为频道定制身份组权限变更
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelRolePermissionChange : QChatSystemNotificationDataBase {
    /// 服务器id
    uint64_t server_id;
    /// 频道id
    uint64_t channel_id;
    /// 继承的服务器身份组 ID
    uint64_t parent_role_id;
    /// 身份组id
    uint64_t role_id;
    /// 变更的权限
    QChatPermission permissions{};
    QChatSystemNotificationDataChannelRolePermissionChange() = default;
    QChatSystemNotificationDataChannelRolePermissionChange(const NIMQChatSystemNotificationDataChannelRolePermissionChange& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        parent_role_id = c_param.parent_role_id;
        role_id = c_param.role_id;
        for (size_t i = 0; i < c_param.permissions_count; i++) {
            auto permission = c_param.permissions[i].permission;
            auto option = c_param.permissions[i].option;
            permissions.emplace(permission, option);
        }
    }
};

/// @struct QChatSystemNotificationDataMemberRolePermissionChange 系统消息为频道个人定制权限变更
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataMemberRolePermissionChange : QChatSystemNotificationDataBase {
    /// 服务器id
    uint64_t server_id;
    /// 频道id
    uint64_t channel_id;
    /// accid
    std::string accid;
    /// 变更的权限
    QChatPermission permissions{};
    QChatSystemNotificationDataMemberRolePermissionChange() = default;
    QChatSystemNotificationDataMemberRolePermissionChange(const NIMQChatSystemNotificationDataMemberRolePermissionChange& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        accid = c_param.accid;
        for (size_t i = 0; i < c_param.permissions_count; i++) {
            auto permission = c_param.permissions[i].permission;
            auto option = c_param.permissions[i].option;
            permissions.emplace(permission, option);
        }
    }
};

/// @struct QChatSystemNotificationDataChannelVisibilityChange 系统消息为频道对当前用户可见性变更
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataChannelVisibilityChange : QChatSystemNotificationDataBase {
    /// 频道可见性
    bool visible{true};
    QChatSystemNotificationDataChannelVisibilityChange() = default;
    QChatSystemNotificationDataChannelVisibilityChange(const NIMQChatSystemNotificationDataChannelVisibilityChange& c_param) {
        visible = c_param.visible;
    }
};

/// @struct QChatSystemNotificationDataServerEnterLeave 系统消息为当前用户进入/离开服务器
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerEnterLeave : QChatSystemNotificationDataBase {
    /// 进入/离开
    bool is_enter{true};
    QChatSystemNotificationDataServerEnterLeave() = default;
    QChatSystemNotificationDataServerEnterLeave(const NIMQChatSystemNotificationDataServerEnterLeave& c_param) { is_enter = c_param.is_enter; }
};

/// @struct QChatSystemNotificationDataServerJoinByInviteCode 系统消息为用户通过邀请码加入服务器
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationDataServerJoinByInviteCode : QChatSystemNotificationDataBase {
    /// 圈组服务器信息
    QChatServerInfo server_info{};
    /// 请求id
    uint64_t request_id{0};
    /// 邀请码
    std::string invite_code;
    QChatSystemNotificationDataServerJoinByInviteCode() = default;
    QChatSystemNotificationDataServerJoinByInviteCode(const NIMQChatSystemNotificationDataServerJoinByInviteCode& c_param) {
        server_info = c_param.server_info;
        request_id = c_param.request_id;
        invite_code = c_param.invite_code ? c_param.invite_code : "";
    }
};

template <typename CPP_TYPE, typename C_TYPE>
static std::shared_ptr<QChatSystemNotificationDataBase> MsgDataCPPToC(void* c_msg_data) {
    return std::make_shared<CPP_TYPE>(*(C_TYPE*)c_msg_data);
};
// clang-format off
static std::map<NIMQChatSystemNotificationType, std::function<std::shared_ptr<QChatSystemNotificationDataBase>(void*)>> msg_data_transform_map_{
    {kNIMQChatSystemNotificationTypeMemberInvite, MsgDataCPPToC<QChatSystemNotificationDataServerInvite, NIMQChatSystemNotificationDataServerInvite>},
    {kNIMQChatSystemNotificationTypeMemberInviteReject, MsgDataCPPToC<QChatSystemNotificationDataServerInviteReject, NIMQChatSystemNotificationDataServerInviteReject>},
    {kNIMQChatSystemNotificationTypeMemberApply, MsgDataCPPToC<QChatSystemNotificationDataServerApply, NIMQChatSystemNotificationDataServerApply>},
    {kNIMQChatSystemNotificationTypeMemberApplyReject, MsgDataCPPToC<QChatSystemNotificationDataServerApplyReject, NIMQChatSystemNotificationDataServerApplyReject>},
    {kNIMQChatSystemNotificationTypeServerCreate, MsgDataCPPToC<QChatSystemNotificationDataServerCreate, NIMQChatSystemNotificationDataServerCreate>},
    {kNIMQChatSystemNotificationTypeServerUpdate, MsgDataCPPToC<QChatSystemNotificationDataServerUpdate, NIMQChatSystemNotificationDataServerUpdate>},
    {kNIMQChatSystemNotificationTypeChannelCreate, MsgDataCPPToC<QChatSystemNotificationDataChannelCreate, NIMQChatSystemNotificationDataChannelCreate>},
    {kNIMQChatSystemNotificationTypeChannelUpdate, MsgDataCPPToC<QChatSystemNotificationDataChannelUpdate, NIMQChatSystemNotificationDataChannelUpdate>},
    {kNIMQChatSystemNotificationTypeMemberInviteDone, MsgDataCPPToC<QChatSystemNotificationDataMemberInviteDone, NIMQChatSystemNotificationDataMemberInviteDone>},
    {kNIMQChatSystemNotificationTypeMemberInviteAccept, MsgDataCPPToC<QChatSystemNotificationDataMemberInviteAccept, NIMQChatSystemNotificationDataMemberInviteAccept>},
    {kNIMQChatSystemNotificationTypeMemberApplyDone, MsgDataCPPToC<QChatSystemNotificationDataMemberApplyDone, NIMQChatSystemNotificationDataMemberApplyDone>},
    {kNIMQChatSystemNotificationTypeMemberApplyAccept, MsgDataCPPToC<QChatSystemNotificationDataMemberApplyAccept, NIMQChatSystemNotificationDataMemberApplyAccept>},
    {kNIMQChatSystemNotificationTypeMemberKick, MsgDataCPPToC<QChatSystemNotificationDataMemberKick, NIMQChatSystemNotificationDataMemberKick>},
    {kNIMQChatSystemNotificationTypeMemberLeave, MsgDataCPPToC<QChatSystemNotificationDataMemberLeave, NIMQChatSystemNotificationDataMemberLeave>},
    {kNIMQChatSystemNotificationTypeMemberUpdate, MsgDataCPPToC<QChatSystemNotificationDataMemberUpdate, NIMQChatSystemNotificationDataMemberUpdate>},
    {kNIMQChatSystemNotificationTypeWhiteBlackRoleUpdate, MsgDataCPPToC<QChatSystemNotificationDataWhiteBlackRoleUpdate, NIMQChatSystemNotificationDataWhiteBlackRoleUpdate>},
    {kNIMQChatSystemNotificationTypeWhiteBlackMembersUpdate, MsgDataCPPToC<QChatSystemNotificationDataWhiteBlackMembersUpdate, NIMQChatSystemNotificationDataWhiteBlackMembersUpdate>},
    {kNIMQChatSystemNotificationTypeQuickCommentChanged, MsgDataCPPToC<QChatSystemNotificationDataQuickCommentChanged, NIMQChatSystemNotificationDataQuickCommentChanged>},
    {kNIMQChatSystemNotificationTypeChannelCategoryCreate, MsgDataCPPToC<QChatSystemNotificationDataChannelCategoryCreate, NIMQChatSystemNotificationDataChannelCategoryCreate>},
    {kNIMQChatSystemNotificationTypeChannelCategoryRemove, MsgDataCPPToC<QChatSystemNotificationDataChannelCategoryRemove, NIMQChatSystemNotificationDataChannelCategoryRemove>},
    {kNIMQChatSystemNotificationTypeChannelCategoryUpdate, MsgDataCPPToC<QChatSystemNotificationDataChannelCategoryUpdate, NIMQChatSystemNotificationDataChannelCategoryUpdate>},
    {kNIMQChatSystemNotificationTypeChannelCategoryWhiteBlackRoleUpdate, MsgDataCPPToC<QChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate, NIMQChatSystemNotificationDataChannelCategoryWhiteBlackRoleUpdate>},
    {kNIMQChatSystemNotificationTypeChannelCategoryWhiteBlackMembersUpdate, MsgDataCPPToC<QChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate, NIMQChatSystemNotificationDataChannelCategoryWhiteBlackMembersUpdate>},
    {kNIMQChatSystemNotificationTypeServerRoleAddMember, MsgDataCPPToC<QChatSystemNotificationDataServerRoleAddMember, NIMQChatSystemNotificationDataServerRoleAddMember>},
    {kNIMQChatSystemNotificationTypeServerRoleRemoveMember, MsgDataCPPToC<QChatSystemNotificationDataServerRoleRemoveMember, NIMQChatSystemNotificationDataServerRoleRemoveMember>},
    {kNIMQChatSystemNotificationTypeServerRolePermissionChange, MsgDataCPPToC<QChatSystemNotificationDataServerRolePermissionChange, NIMQChatSystemNotificationDataServerRolePermissionChange>},
    {kNIMQChatSystemNotificationTypeChannelRolePermissionChange, MsgDataCPPToC<QChatSystemNotificationDataChannelRolePermissionChange, NIMQChatSystemNotificationDataChannelRolePermissionChange>},
    {kNIMQChatSystemNotificationTypeMemberRolePermissionChange, MsgDataCPPToC<QChatSystemNotificationDataMemberRolePermissionChange, NIMQChatSystemNotificationDataMemberRolePermissionChange>},
    {kNIMQChatSystemNotificationTypeChannelVisibilityChange, MsgDataCPPToC<QChatSystemNotificationDataChannelVisibilityChange, NIMQChatSystemNotificationDataChannelVisibilityChange>},
    {kNIMQChatSystemNotificationTypeServerEnterLeave, MsgDataCPPToC<QChatSystemNotificationDataServerEnterLeave, NIMQChatSystemNotificationDataServerEnterLeave>},
    {kNIMQChatSystemNotificationTypeServerJoinByInviteCode, MsgDataCPPToC<QChatSystemNotificationDataServerJoinByInviteCode, NIMQChatSystemNotificationDataServerJoinByInviteCode>}
};
// clang-format on

/** @struct QChatSystemNotification 圈组系统消息定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotification {
    /// 消息所属的server id
    uint64_t server_id{0};
    /// 消息所属的channel id
    uint64_t channel_id{0};
    /// 消息id
    std::string msg_id{""};
    /// 系统消息类型
    NIMQChatSystemNotificationType msg_type{kNIMQChatSystemNotificationTypeUnkonwn};
    /// 消息内容
    std::string msg_body{""};
    /// 消息附件
    std::string msg_attach{""};
    /// 消息扩展字段
    std::string msg_ext{""};
    /// 重发标记，false:不是重发，true:是重发
    bool resend_flag{false};
    /// 通知接受者账号列表
    std::list<std::string> to_accids{};
    /// false 或者 true, 是否存离线，只有 to_accids 不为空，才能设置为存离线，默认 false
    bool history_enable{false};
    /// 自定义的推送属性，限制json
    std::string push_payload{""};
    /// 自定义的推送内容
    std::string push_content{""};
    /// 是否需要推送, false: 不需要, true: 需要, 默认 false
    bool push_enable{false};
    /// 是否需要消息计数, false: 不需要, true: 需要, 默认 true
    bool need_badge{true};
    /// 是否需要推送昵称, false: 不需要, true: 需要, 默认 true
    bool need_push_nick{true};
    /// 是否需要抄送, false: 不需要, true: 需要, 默认 true
    bool route_enable{true};
    /// 环境变量，用于指向不同的抄送、第三方回调等配置
    std::string env{""};
    // 以下字段仅在收到消息时有效
    /// 消息状态
    NIMQChatSystemNotificationStatus status{kNIMQChatSystemNotificationNormal};
    /// 消息服务器端id
    uint64_t msg_server_id{0};
    /// 消息发送者的accid
    std::string from_accid{""};
    /// 消息发送者的客户端类型
    uint32_t from_client_type{0};
    /// 消息发送者的设备id
    std::string from_device_id{""};
    /// 消息发送者的昵称
    std::string from_nick{""};
    /// 消息发送时间戳
    uint64_t timestamp{0};
    /// 消息更新时间戳
    uint64_t update_timestamp{0};
    /// 消息数据
    std::shared_ptr<QChatSystemNotificationDataBase> msg_data{nullptr};
    /// 回调扩展字段
    std::string callback_ext{""};
    QChatSystemNotification() = default;
    QChatSystemNotification(const NIMQChatSystemNotification& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        msg_id = c_param.msg_id ? c_param.msg_id : "";
        msg_type = c_param.msg_type;
        msg_body = c_param.msg_body ? c_param.msg_body : "";
        msg_attach = c_param.msg_attach ? c_param.msg_attach : "";
        msg_ext = c_param.msg_ext ? c_param.msg_ext : "";
        resend_flag = c_param.resend_flag;
        if (c_param.to_accids)
            nim::JsonArrayStringToList(c_param.to_accids, to_accids);
        route_enable = c_param.route_enable;
        env = c_param.env ? c_param.env : "";
        // fill by server
        status = c_param.status;
        history_enable = c_param.history_enable;
        push_payload = c_param.push_payload ? c_param.push_payload : "";
        push_content = c_param.push_content ? c_param.push_content : "";
        push_enable = c_param.push_enable;
        need_badge = c_param.need_badge;
        need_push_nick = c_param.need_push_nick;
        msg_server_id = c_param.msg_server_id;
        from_accid = c_param.from_accid ? c_param.from_accid : "";
        from_client_type = c_param.from_client_type;
        from_device_id = c_param.from_device_id ? c_param.from_device_id : "";
        from_nick = c_param.from_nick ? c_param.from_nick : "";
        timestamp = c_param.timestamp;
        update_timestamp = c_param.update_timestamp;
        if (c_param.msg_data) {
            auto iter = msg_data_transform_map_.find(msg_type);
            if (iter != msg_data_transform_map_.end()) {
                msg_data = iter->second(c_param.msg_data);
            }
        }
        callback_ext = c_param.callback_ext ? c_param.callback_ext : "";
    }
    const NIMQChatSystemNotification ToCParam() const {
        nim::StrListToJsonString(to_accids, to_accids_json_array);
        NIMQChatSystemNotification c_param = {};
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.msg_id = const_cast<char*>(msg_id.c_str());
        c_param.msg_type = msg_type;
        c_param.msg_body = const_cast<char*>(msg_body.c_str());
        c_param.msg_attach = const_cast<char*>(msg_attach.c_str());
        c_param.msg_ext = const_cast<char*>(msg_ext.c_str());
        c_param.resend_flag = resend_flag;
        c_param.to_accids = const_cast<char*>(to_accids_json_array.c_str());
        c_param.history_enable = history_enable;
        c_param.push_payload = const_cast<char*>(push_payload.c_str());
        c_param.push_content = const_cast<char*>(push_content.c_str());
        c_param.push_enable = push_enable;
        c_param.need_badge = need_badge;
        c_param.need_push_nick = need_push_nick;
        c_param.route_enable = route_enable;
        c_param.env = const_cast<char*>(env.c_str());
        // fill by server
        c_param.status = status;
        c_param.msg_server_id = msg_server_id;
        c_param.from_accid = const_cast<char*>(from_accid.c_str());
        c_param.from_client_type = from_client_type;
        c_param.from_device_id = const_cast<char*>(from_device_id.c_str());
        c_param.from_nick = const_cast<char*>(from_nick.c_str());
        c_param.timestamp = timestamp;
        c_param.update_timestamp = update_timestamp;
        c_param.callback_ext = const_cast<char*>(callback_ext.c_str());
        return c_param;
    }

protected:
    // 以下字段为内部使用
    mutable std::string to_accids_json_array;
};

/** @struct QChatTypingEvent 圈组正在输入事件定义 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatTypingEvent {
    /// 事件所属的server id
    uint64_t server_id{0};
    /// 事件所属的channel id
    uint64_t channel_id{0};
    /// 事件扩展字段
    std::string extension{""};
    // 以下字段仅在收到事件时有效
    /// 事件发送者的accid
    std::string from_accid{""};
    /// 事件发送者的昵称
    std::string from_nick{""};
    /// 事件发送时间戳
    uint64_t timestamp{0};
    QChatTypingEvent() = default;
    QChatTypingEvent(const NIMQChatTypingEvent& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        extension = c_param.extension ? c_param.extension : "";
        from_accid = c_param.from_accid ? c_param.from_accid : "";
        from_nick = c_param.from_nick ? c_param.from_nick : "";
        timestamp = c_param.timestamp;
    }
    const NIMQChatTypingEvent ToCParam() const {
        NIMQChatTypingEvent c_param = {};
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.extension = const_cast<char*>(extension.c_str());
        c_param.from_accid = const_cast<char*>(from_accid.c_str());
        c_param.from_nick = const_cast<char*>(from_nick.c_str());
        c_param.timestamp = timestamp;
        return c_param;
    }
};

/// @struct QChatRecvSystemNotificationResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRecvSystemNotificationResp {
    /// 系统消息
    QChatSystemNotification notification{};
    QChatRecvSystemNotificationResp() = default;
    QChatRecvSystemNotificationResp(const NIMQChatRecvSystemNotificationResp& c_resp) { notification = c_resp.notification; }
};

/// @struct QChatSystemNotificationUpdatedResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSystemNotificationUpdatedResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 消息更新信息
    QChatMessageUpdateInfo update_info{};
    /// 消息体
    QChatSystemNotification notification{};
    QChatSystemNotificationUpdatedResp() = default;
    QChatSystemNotificationUpdatedResp(const NIMQChatSystemNotificationUpdatedResp& c_resp) {
        update_info = c_resp.update_info;
        notification = c_resp.notification;
    }
};

/// @struct QChatSendSystemNotificationResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSendSystemNotificationResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 系统消息
    QChatSystemNotification notification{};
    QChatSendSystemNotificationResp() = default;
    QChatSendSystemNotificationResp(const NIMQChatSendSystemNotificationResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        notification = c_resp.notification;
    }
    NIMQChatSendSystemNotificationResp ToCParam() const {
        NIMQChatSendSystemNotificationResp c_resp = {};
        c_resp.res_code = res_code;
        c_resp.notification = notification.ToCParam();
        return c_resp;
    }
};

/// @struct QChatUpdateSystemNotificationResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateSystemNotificationResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 系统消息
    QChatSystemNotification notification{};
    QChatUpdateSystemNotificationResp() = default;
    QChatUpdateSystemNotificationResp(const NIMQChatUpdateSystemNotificationResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        notification = c_resp.notification;
    }
    NIMQChatUpdateSystemNotificationResp ToCParam() const {
        NIMQChatUpdateSystemNotificationResp c_resp = {};
        c_resp.res_code = res_code;
        c_resp.notification = notification.ToCParam();
        return c_resp;
    }
};

/// @struct QChatMarkReadSystemNotificationResp
using QChatMarkReadSystemNotificationResp = QChatBaseResp;

/// @struct QChatMarkSystemNotificationsReadResp
using QChatMarkSystemNotificationsReadResp = QChatBaseResp;

/// @struct QChatRecvTypingEventResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRecvTypingEventResp {
    /// 圈组正在输入事件
    QChatTypingEvent typing_event{};
    QChatRecvTypingEventResp() = default;
    QChatRecvTypingEventResp(const NIMQChatRecvTypingEventResp& c_resp) { typing_event = c_resp.typing_event; }
};

/// @struct QChatSendTypingEventResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSendTypingEventResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 圈组正在输入事件
    QChatTypingEvent typing_event{};
    QChatSendTypingEventResp() = default;
    QChatSendTypingEventResp(const NIMQChatSendTypingEventResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        typing_event = c_resp.typing_event;
    }
    const NIMQChatSendTypingEventResp ToCParam() const {
        NIMQChatSendTypingEventResp c_resp = {};
        c_resp.res_code = res_code;
        c_resp.typing_event = typing_event.ToCParam();
        return c_resp;
    }
};

/// 接收系统消息回调
typedef std::function<void(const QChatRecvSystemNotificationResp&)> RecvSystemNotificationCallback;
/// 发送系统消息回调
typedef std::function<void(const QChatSendSystemNotificationResp&)> SendSystemNotificationCallback;
/// 消息更新回调
typedef std::function<void(const QChatSystemNotificationUpdatedResp&)> SystemNotificationUpdatedCallback;
/// 更新系统通知回调
typedef std::function<void(const QChatUpdateSystemNotificationResp&)> UpdateSystemNotificationCallback;
/// 标记系统通知消息已读回调函数
typedef std::function<void(const QChatMarkSystemNotificationsReadResp&)> MarkReadSystemNotificationCallback;
/// 接收圈组正在输入事件回调
typedef std::function<void(const QChatRecvTypingEventResp&)> RecvTypingEventCallback;
/// 发送圈组正在输入事件回调
typedef std::function<void(const QChatSendTypingEventResp&)> SendTypingEventCallback;

/// @struct QChatRegRecvSystemNotificationCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRegRecvSystemNotificationCbParam {
    /// 回调函数
    RecvSystemNotificationCallback cb{nullptr};
    const NIMQChatRegRecvSystemNotificationCbParam ToCParam() const {
        static RecvSystemNotificationCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatRegRecvSystemNotificationCbParam param = {};
        param.cb = [](const NIMQChatRecvSystemNotificationResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatRegSystemNotificationUpdatedCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRegSystemNotificationUpdatedCbParam {
    /// 回调函数
    SystemNotificationUpdatedCallback cb{nullptr};
    const NIMQChatRegSystemNotificationUpdatedCbParam ToCParam() const {
        static SystemNotificationUpdatedCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatRegSystemNotificationUpdatedCbParam param = {};
        param.cb = [](const NIMQChatSystemNotificationUpdatedResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatSendSystemNotificationParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSendSystemNotificationParam {
    /// 回调函数
    SendSystemNotificationCallback cb{nullptr};
    /// 系统消息体
    QChatSystemNotification notification{};
    QChatSendSystemNotificationParam() = default;
    QChatSendSystemNotificationParam(const NIMQChatSendSystemNotificationParam& c_param) {
        notification = c_param.notification;
        cb = [c_param](const QChatSendSystemNotificationResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = c_param.user_data;
            c_param.cb(c_response);
        };
    }
    const NIMQChatSendSystemNotificationParam ToCParam() const {
        auto cb_holder = new SendSystemNotificationCallback(cb);
        NIMQChatSendSystemNotificationParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatSendSystemNotificationResp& resp) {
            InvokeCallback<SendSystemNotificationCallback, NIMQChatSendSystemNotificationResp>(resp);
        };
        param.notification = notification.ToCParam();
        return param;
    }
};

/// @struct QChatUpdateSystemNotificationParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateSystemNotificationParam {
    /// 回调函数
    UpdateSystemNotificationCallback cb{nullptr};
    /// 系统通知服务器ID
    uint64_t msg_server_id{0};
    /// 系统通知类型
    NIMQChatSystemNotificationType msg_type{kNIMQChatSystemNotificationTypeUnkonwn};
    /// 消息状态
    NIMQChatSystemNotificationStatus status{kNIMQChatSystemNotificationNormal};
    /// 消息内容
    std::string msg_body;
    /// 消息扩展字段
    std::string msg_ext;
    /// 更新信息
    QChatMessageUpdateInfo update_info;
    QChatUpdateSystemNotificationParam() = default;
    QChatUpdateSystemNotificationParam(const NIMQChatUpdateSystemNotificationParam& c_param) {
        msg_server_id = c_param.msg_server_id;
        msg_type = c_param.msg_type;
        status = c_param.status;
        msg_body = c_param.msg_body;
        msg_ext = c_param.msg_ext;
        update_info = c_param.update_info;
        cb = [c_param](const QChatUpdateSystemNotificationResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = c_param.user_data;
            c_param.cb(c_response);
        };
    }
    const NIMQChatUpdateSystemNotificationParam ToCParam() const {
        auto cb_holder = new UpdateSystemNotificationCallback(cb);
        NIMQChatUpdateSystemNotificationParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatUpdateSystemNotificationResp& resp) {
            InvokeCallback<UpdateSystemNotificationCallback, NIMQChatUpdateSystemNotificationResp>(resp);
        };
        param.msg_server_id = msg_server_id;
        param.msg_type = msg_type;
        param.status = status;
        param.msg_body = const_cast<char*>(msg_body.c_str());
        param.msg_ext = const_cast<char*>(msg_ext.c_str());
        param.update_info = update_info.ToCParam();
        return param;
    }
};

/// @struct QChatMarkSystemNotificationsReadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMarkSystemNotificationsReadParam {
    MarkReadSystemNotificationCallback cb{nullptr};
    std::vector<NIMQChatSystemNotificationMarkReadInfo> mark_read_infos{};
    QChatMarkSystemNotificationsReadParam() = default;
    QChatMarkSystemNotificationsReadParam(const NIMQChatMarkSystemNotificationsReadParam& c_param) {
        for (size_t i = 0; i < c_param.mark_read_infos_count; i++) {
            mark_read_infos.push_back(c_param.mark_read_infos[i]);
        }
        cb = [c_param](const QChatMarkSystemNotificationsReadResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = c_param.user_data;
            c_param.cb(c_response);
        };
    }
    const NIMQChatMarkSystemNotificationsReadParam ToCParam() const {
        auto cb_holder = new MarkReadSystemNotificationCallback(cb);
        NIMQChatMarkSystemNotificationsReadParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatMarkReadSystemNotificationResp& resp) {
            InvokeCallback<MarkReadSystemNotificationCallback, NIMQChatMarkReadSystemNotificationResp>(resp);
        };
        param.mark_read_infos_count = mark_read_infos.size();
        param.mark_read_infos = const_cast<NIMQChatSystemNotificationMarkReadInfo*>(mark_read_infos.data());
        return param;
    }
};

/// @struct QChatRegRecvTypingEventCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRegRecvTypingEventCbParam {
    /// 回调函数
    RecvTypingEventCallback cb{nullptr};
    const NIMQChatRegRecvTypingEventCbParam ToCParam() const {
        static RecvTypingEventCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatRegRecvTypingEventCbParam param = {};
        param.cb = [](const NIMQChatRecvTypingEventResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatSendTypingEventParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatSendTypingEventParam {
    /// 回调函数
    SendTypingEventCallback cb{nullptr};
    /// 圈组正在输入事件
    QChatTypingEvent typing_event{};
    QChatSendTypingEventParam() = default;
    QChatSendTypingEventParam(const NIMQChatSendTypingEventParam& c_param) {
        typing_event = c_param.typing_event;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatSendTypingEventResp& resp) {
            NIMQChatSendTypingEventResp c_response = resp.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatSendTypingEventParam ToCParam() const {
        auto cb_holder = new SendTypingEventCallback(cb);
        NIMQChatSendTypingEventParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatSendTypingEventResp& resp) {
            InvokeCallback<SendTypingEventCallback, NIMQChatSendTypingEventResp>(resp);
        };
        param.typing_event = typing_event.ToCParam();
        return param;
    }
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_SYSTEM_NOTIFICATION_CPP_DEF_H__
