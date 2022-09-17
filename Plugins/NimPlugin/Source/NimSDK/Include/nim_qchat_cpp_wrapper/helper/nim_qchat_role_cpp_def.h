/**
 * @file nim_qchat_role_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_IDENTITY_CPP_DEF_H__
#define __NIM_QCHAT_IDENTITY_CPP_DEF_H__

#include <iostream>
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_member_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_helper.h"
#include "nim_qchat_role_def.h"

namespace nim_qchat {

/// @struct QChatPermission
using QChatPermission = std::map<NIMQChatPermissions, NIMQChatPermissionsOption>;

/// @struct QChatRoleMemberInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRoleMemberInfo {
    /// member_info
    QChatMemberInfo member_info{};
    /// 所在身份组role id
    uint64_t role_id{0};
    QChatRoleMemberInfo() = default;
    QChatRoleMemberInfo(const NIMQChatRoleMemberInfo& c_param) {
        member_info = c_param.member_info;
        role_id = c_param.role_id;
    }
    const NIMQChatRoleMemberInfo ToCParam() const {
        NIMQChatRoleMemberInfo c_param = {};
        c_param.member_info = member_info.ToCParam();
        c_param.role_id = role_id;
        return c_param;
    }
};

/// @struct QChatRoleInfoBase
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRoleInfoBase {
    /// 服务器ID
    uint64_t server_id = 0;
    /// 身份组id
    uint64_t role_id = 0;
    /// 身份组名称
    std::string role_name;
    /// 身份组图片 URL
    std::string role_icon;
    /// 身份组扩展字段
    std::string extension;
    /// 身份组权限设定
    QChatPermission permissions{};
    /// 身份组类型 1 表示 Everyone，2 表示定制身份组
    NIMQChatRoleType role_type = kRoleTypeUnkonwn;
    /// 身份组创建时间
    uint64_t create_time = 0;
    /// 身份组修改时间
    uint64_t update_time = 0;
    QChatRoleInfoBase() = default;
    QChatRoleInfoBase(const NIMQChatRoleInfo& info) {
        server_id = info.server_id;
        role_id = info.role_id;
        role_name = info.role_name;
        role_icon = info.role_icon;
        extension = info.extension;
        for (size_t i = 0; i < info.permissions_count; i++) {
            auto permission = info.permissions[i].permission;
            auto option = info.permissions[i].option;
            permissions.emplace(permission, option);
        }
        role_type = info.role_type;
        create_time = info.create_time;
        update_time = info.update_time;
    }
    const NIMQChatRoleInfo ToCParam() const {
        NIMQChatRoleInfo c_param;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        c_param.role_type = role_type;
        c_param.role_name = const_cast<char*>(role_name.c_str());
        c_param.role_icon = const_cast<char*>(role_icon.c_str());
        c_param.extension = const_cast<char*>(extension.c_str());
        vec_permissions.clear();
        for (auto&& permission : permissions) {
            NIMQChatPermissionGroup perms;
            perms.permission = permission.first;
            perms.option = permission.second;
            vec_permissions.push_back(perms);
        }
        c_param.permissions = vec_permissions.data();
        c_param.permissions_count = vec_permissions.size();
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> vec_permissions;
};

/// @struct QChatServerRoleInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerRoleInfo : public QChatRoleInfoBase {
    /// 该身份组的成员数量，Everyone 身份组数量为 -1
    uint32_t member_count = 0;
    /// 身份组优先级，Everyone 最高为 0，数字越大优先级越低，自定义优先级区间 1~9007199254740991
    uint64_t priority = 0;
    QChatServerRoleInfo() = default;
    QChatServerRoleInfo(const NIMQChatRoleInfo& info)
        : QChatRoleInfoBase(info) {
        member_count = info.server_role.member_count;
        priority = info.server_role.priority;
    }
    const NIMQChatRoleInfo ToCParam() const {
        auto c_param = QChatRoleInfoBase::ToCParam();
        c_param.server_role.member_count = member_count;
        c_param.server_role.priority = priority;
        return c_param;
    }
};

/// @struct QChatChannelRoleInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelRoleInfo : public QChatRoleInfoBase {
    /// 频道 ID
    uint64_t channel_id = 0;
    /// 继承的服务器身份组 ID
    uint64_t parent_role_id = 0;
    QChatChannelRoleInfo() = default;
    QChatChannelRoleInfo(const NIMQChatRoleInfo& info)
        : QChatRoleInfoBase(info) {
        channel_id = info.channel_role.channel_id;
        parent_role_id = info.channel_role.parent_role_id;
    }
    const NIMQChatRoleInfo ToCParam() const {
        auto c_param = QChatRoleInfoBase::ToCParam();
        c_param.channel_role.channel_id = channel_id;
        c_param.channel_role.parent_role_id = parent_role_id;
        return c_param;
    }
};

/// @struct QChatChannelCategoryRoleInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryRoleInfo : public QChatRoleInfoBase {
    /// 频道分组 ID
    uint64_t category_id{0};
    /// 继承的服务器身份组 ID
    uint64_t parent_role_id{0};
    /// 有效标志
    bool valid_flag{true};
    QChatChannelCategoryRoleInfo() = default;
    QChatChannelCategoryRoleInfo(const NIMQChatRoleInfo& info)
        : QChatRoleInfoBase(info) {
        category_id = info.channel_category_role.category_id;
        parent_role_id = info.channel_category_role.parent_role_id;
        valid_flag = info.channel_category_role.valid_flag;
    }
    const NIMQChatRoleInfo ToCParam() const {
        auto c_param = QChatRoleInfoBase::ToCParam();
        c_param.channel_category_role.category_id = category_id;
        c_param.channel_category_role.parent_role_id = parent_role_id;
        c_param.channel_category_role.valid_flag = valid_flag;
        return c_param;
    }
};

/// @struct QChatMemberRoleInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMemberRoleInfo {
    /// 该定制权限所在的频道 ID
    uint64_t channel_id{0};
    /// 该定制权限所在的身份组 ID
    uint64_t role_id{0};
    /// 定制权限的用户信息
    QChatMemberInfo member_info{};
    /// 身份组权限设定
    QChatPermission permissions{};
    /// 身份组创建时间
    uint64_t create_time{0};
    /// 身份组修改时间
    uint64_t update_time{0};
    QChatMemberRoleInfo() = default;
    QChatMemberRoleInfo(const NIMQChatMemberRoleInfo& info)
        : member_info(info.member_info) {
        channel_id = info.channel_id;
        role_id = info.role_id;
        for (size_t i = 0; i < info.permissions_count; i++) {
            permissions.emplace(info.permissions[i].permission, info.permissions[i].option);
        }
        create_time = info.create_time;
        update_time = info.update_time;
    }
    const NIMQChatMemberRoleInfo ToCParam() const {
        NIMQChatMemberRoleInfo c_param;
        c_param.channel_id = channel_id;
        c_param.role_id = role_id;
        c_param.member_info = member_info.ToCParam();
        vec_permissions.clear();
        for (auto&& permission : permissions) {
            NIMQChatPermissionGroup perms;
            perms.permission = permission.first;
            perms.option = permission.second;
            vec_permissions.push_back(perms);
        }
        c_param.permissions = vec_permissions.data();
        c_param.permissions_count = vec_permissions.size();
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> vec_permissions;
};

/// @struct QChatChannelCategoryMemberRoleInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatChannelCategoryMemberRoleInfo {
    /// 频道分组 ID
    uint64_t category_id{0};
    /// 该定制权限所在的身份组 ID
    uint64_t role_id{0};
    /// 定制权限的用户信息
    QChatMemberInfo member_info{};
    /// 身份组权限设定
    QChatPermission permissions{};
    /// 身份组创建时间
    uint64_t create_time{0};
    /// 身份组修改时间
    uint64_t update_time{0};
    QChatChannelCategoryMemberRoleInfo() = default;
    QChatChannelCategoryMemberRoleInfo(const NIMQChatChannelCategoryMemberRoleInfo& info)
        : member_info(info.member_info) {
        category_id = info.category_id;
        role_id = info.role_id;
        for (size_t i = 0; i < info.permissions_count; i++) {
            permissions.emplace(info.permissions[i].permission, info.permissions[i].option);
        }
        create_time = info.create_time;
        update_time = info.update_time;
    }
    const NIMQChatChannelCategoryMemberRoleInfo ToCParam() const {
        NIMQChatChannelCategoryMemberRoleInfo c_param;
        c_param.category_id = category_id;
        c_param.role_id = role_id;
        c_param.member_info = member_info.ToCParam();
        vec_permissions.clear();
        for (auto&& permission : permissions) {
            NIMQChatPermissionGroup perms;
            perms.permission = permission.first;
            perms.option = permission.second;
            vec_permissions.push_back(perms);
        }
        c_param.permissions = vec_permissions.data();
        c_param.permissions_count = vec_permissions.size();
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> vec_permissions;
};

/* ---------------------------------------------------------- */

/// @struct QChatCreateServerRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatCreateServerRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    QChatServerRoleInfo role_info;
    QChatCreateServerRoleResp() = default;
    QChatCreateServerRoleResp(const NIMQChatCreateServerRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        role_info = QChatServerRoleInfo(c_resp.role_info);
    }
    const NIMQChatCreateServerRoleResp ToCParam() const {
        NIMQChatCreateServerRoleResp c_resp;
        c_resp.res_code = res_code;
        c_resp.role_info = role_info.ToCParam();
        return c_resp;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> permissions_;
    mutable NIMQChatServerRoleInfo server_role_info_;
};

/// @struct QChatUpdateServerRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateServerRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    QChatServerRoleInfo role_info;
    QChatUpdateServerRoleResp() = default;
    QChatUpdateServerRoleResp(const NIMQChatUpdateServerRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        role_info = QChatServerRoleInfo(c_resp.role_info);
    }
};

/// @struct QChatDeleteServerRoleResp
using QChatDeleteServerRoleResp = QChatBaseResp;

/// @struct QChatGetServerRolesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetServerRolesResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    /// 返回查询的所有身份组信息
    std::list<QChatServerRoleInfo> role_infos;
    /// 自己已经加入的身份组列表
    std::list<QChatServerRoleInfo> joined_roles;
    QChatGetServerRolesResp() = default;
    QChatGetServerRolesResp(const NIMQChatGetServerRolesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            role_infos.push_back(QChatServerRoleInfo(c_resp.roles[i]));
        }
        for (size_t i = 0; i < c_resp.joined_role_count; i++) {
            joined_roles.push_back(QChatServerRoleInfo(c_resp.joined_roles[i]));
        }
    }
    const NIMQChatGetServerRolesResp ToCParam() const {
        NIMQChatGetServerRolesResp c_response{};
        c_response.res_code = res_code;
        roles_vec.clear();
        joined_roles_vec.clear();
        for (auto&& role : role_infos) {
            auto&& role_info = role.ToCParam();
            roles_vec.push_back(role_info);
        }
        for (auto&& role : joined_roles) {
            auto&& role_info = role.ToCParam();
            joined_roles_vec.push_back(role_info);
        }
        c_response.roles = roles_vec.data();
        c_response.role_count = roles_vec.size();
        c_response.joined_roles = joined_roles_vec.data();
        c_response.joined_role_count = joined_roles_vec.size();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> roles_vec;
    mutable std::vector<NIMQChatRoleInfo> joined_roles_vec;
};

/// @struct QChatUpdateServerRolePrioritiesResp
using QChatUpdateServerRolePrioritiesResp = QChatGetServerRolesResp;

/// @struct QChatGetMembersFromServerRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMembersFromServerRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::list<QChatRoleMemberInfo> members;
    QChatGetMembersFromServerRoleResp() = default;
    QChatGetMembersFromServerRoleResp(const NIMQChatGetMembersFromServerRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_count; i++) {
            QChatRoleMemberInfo member(c_resp.members[i]);
            members.push_back(member);
        }
    }
    const NIMQChatGetMembersFromServerRoleResp ToCParam() const {
        NIMQChatGetMembersFromServerRoleResp c_response;
        c_response.res_code = res_code;
        c_response.member_count = members.size();
        members_.clear();
        for (auto&& member : members) {
            members_.push_back(member.ToCParam());
        }
        c_response.members = members_.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleMemberInfo> members_;
};

/// @struct QChatAddMembersToServerRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddMembersToServerRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    /// 加入成功的用户列表
    std::list<std::string> succeed_list;
    /// 加入失败的用户列表
    std::list<std::string> failed_list;

    QChatAddMembersToServerRoleResp() = default;
    QChatAddMembersToServerRoleResp(const NIMQChatAddMembersToServerRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.succeed_count; i++) {
            succeed_list.push_back(c_resp.succeed_list[i]);
        }
        for (size_t i = 0; i < c_resp.failed_count; i++) {
            failed_list.push_back(c_resp.failed_list[i]);
        }
    }
    const NIMQChatAddMembersToServerRoleResp ToCParam() const {
        NIMQChatAddMembersToServerRoleResp c_response;
        c_response.res_code = res_code;
        succeed_members_.clear();
        failed_members_.clear();
        for (auto&& member : succeed_list)
            succeed_members_.push_back(const_cast<char*>(member.c_str()));
        c_response.succeed_count = succeed_members_.size();
        c_response.succeed_list = succeed_members_.data();
        for (auto&& member : failed_list)
            failed_members_.push_back(const_cast<char*>(member.c_str()));
        c_response.failed_count = failed_members_.size();
        c_response.failed_list = failed_members_.data();
        return c_response;
    }

protected:
    mutable std::vector<char*> succeed_members_;
    mutable std::vector<char*> failed_members_;
};

/// @struct QChatRemoveMembersFromServerRoleResp
using QChatRemoveMembersFromServerRoleResp = QChatAddMembersToServerRoleResp;

/// @struct QChatAddChannelRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddChannelRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    QChatChannelRoleInfo role_info{};
    QChatAddChannelRoleResp() = default;
    QChatAddChannelRoleResp(const NIMQChatAddChannelRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        role_info = QChatChannelRoleInfo(c_resp.role_info);
    }
    const NIMQChatAddChannelRoleResp ToCParam() const {
        NIMQChatAddChannelRoleResp c_response;
        c_response.res_code = res_code;
        c_response.role_info = role_info.ToCParam();
        return c_response;
    }
};

/// @struct QChatUpdateChannelRoleResp
using QChatUpdateChannelRoleResp = QChatAddChannelRoleResp;
/// @struct QChatRemoveChannelRoleResp
using QChatRemoveChannelRoleResp = QChatBaseResp;

/// @struct QChatAddChannelCategoryRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddChannelCategoryRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    /// 频道分组身份组信息
    QChatChannelCategoryRoleInfo role_info;
    QChatAddChannelCategoryRoleResp() = default;
    QChatAddChannelCategoryRoleResp(const NIMQChatAddChannelCategoryRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        role_info = QChatChannelCategoryRoleInfo(c_resp.role_info);
    }
    const NIMQChatAddChannelCategoryRoleResp ToCParam() const {
        NIMQChatAddChannelCategoryRoleResp c_response;
        c_response.res_code = res_code;
        c_response.role_info = role_info.ToCParam();
        return c_response;
    }
};
/// @struct QChatUpdateChannelCategoryRoleResp
using QChatUpdateChannelCategoryRoleResp = QChatAddChannelCategoryRoleResp;
/// @struct QChatRemoveChannelCategoryRoleResp
using QChatRemoveChannelCategoryRoleResp = QChatBaseResp;

/// @struct QChatGetChannelRolesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetChannelRolesResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::list<QChatChannelRoleInfo> role_infos;

    QChatGetChannelRolesResp() = default;
    QChatGetChannelRolesResp(const NIMQChatGetChannelRolesResp& c_resp) {
        res_code = c_resp.res_code;

        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            role_infos.push_back(QChatChannelRoleInfo(c_resp.role_infos[i]));
        }
    }
    const NIMQChatGetChannelRolesResp ToCParam() const {
        NIMQChatGetChannelRolesResp c_response;
        c_response.res_code = res_code;
        channel_role_infos_.clear();
        for (auto&& role_info : role_infos) {
            channel_role_infos_.push_back(role_info.ToCParam());
        }
        c_response.role_count = channel_role_infos_.size();
        c_response.role_infos = channel_role_infos_.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> channel_role_infos_;
};

/// @struct QChatGetChannelCategoryRolesPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetChannelCategoryRolesPageResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::list<QChatChannelCategoryRoleInfo> role_infos;
    QChatGetChannelCategoryRolesPageResp() = default;
    QChatGetChannelCategoryRolesPageResp(const NIMQChatGetChannelCategoryRolesPageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.role_count; i++) {
            role_infos.push_back(QChatChannelCategoryRoleInfo(c_resp.role_infos[i]));
        }
    }
    const NIMQChatGetChannelCategoryRolesPageResp ToCParam() const {
        NIMQChatGetChannelCategoryRolesPageResp c_response;
        c_response.res_code = res_code;
        vec_role_infos_.clear();
        for (auto&& role_info : role_infos) {
            vec_role_infos_.push_back(role_info.ToCParam());
        }
        c_response.role_count = vec_role_infos_.size();
        c_response.role_infos = vec_role_infos_.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfo> vec_role_infos_;
};

/// @struct QChatAddMemberRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddMemberRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    QChatMemberRoleInfo role_info{};
    QChatAddMemberRoleResp() = default;
    QChatAddMemberRoleResp(const NIMQChatAddMemberRoleResp& c_resp)
        : role_info(c_resp.role_info) {
        res_code = c_resp.res_code;
    }
    const NIMQChatAddMemberRoleResp ToCParam() const {
        NIMQChatAddMemberRoleResp c_response{};
        c_response.res_code = res_code;
        c_response.role_info = role_info.ToCParam();
        return c_response;
    }
};

/// @struct QChatUpdateMemberRoleResp
using QChatUpdateMemberRoleResp = QChatAddMemberRoleResp;
/// @struct QChatRemoveMemberRoleResp
using QChatRemoveMemberRoleResp = QChatBaseResp;

/// @struct QChatAddChannelCategoryMemberRoleResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddChannelCategoryMemberRoleResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    /// 频道分组成员身份组信息
    QChatChannelCategoryMemberRoleInfo role_info;
    QChatAddChannelCategoryMemberRoleResp() = default;
    QChatAddChannelCategoryMemberRoleResp(const NIMQChatAddChannelCategoryMemberRoleResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        role_info = QChatChannelCategoryMemberRoleInfo(c_resp.role_info);
    }
    const NIMQChatAddChannelCategoryMemberRoleResp ToCParam() const {
        NIMQChatAddChannelCategoryMemberRoleResp c_response;
        c_response.res_code = res_code;
        c_response.role_info = role_info.ToCParam();
        return c_response;
    }
};

/// @struct QChatUpdateChannelCategoryMemberRoleResp
using QChatUpdateChannelCategoryMemberRoleResp = QChatAddChannelCategoryMemberRoleResp;
/// @struct QChatRemoveChannelCategoryMemberRoleResp
using QChatRemoveChannelCategoryMemberRoleResp = QChatBaseResp;

/// @struct QChatGetMemberRolesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMemberRolesResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::list<QChatMemberRoleInfo> role_infos;
    QChatGetMemberRolesResp() = default;
    QChatGetMemberRolesResp(const NIMQChatGetMemberRolesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_role_count; i++) {
            role_infos.push_back(QChatMemberRoleInfo(c_resp.role_infos[i]));
        }
    }
    const NIMQChatGetMemberRolesResp ToCParam() const {
        NIMQChatGetMemberRolesResp c_response;
        c_response.res_code = res_code;
        role_infos_.clear();
        for (auto&& channel_member_role : role_infos) {
            role_infos_.push_back(channel_member_role.ToCParam());
        }

        c_response.member_role_count = role_infos_.size();
        c_response.role_infos = role_infos_.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberRoleInfo> role_infos_;
};

/// @struct QChatGetChannelCategoryMemberRolesPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetChannelCategoryMemberRolesPageResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::list<QChatChannelCategoryMemberRoleInfo> role_infos;
    QChatGetChannelCategoryMemberRolesPageResp() = default;
    QChatGetChannelCategoryMemberRolesPageResp(const NIMQChatGetChannelCategoryMemberRolesPageResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_role_count; i++) {
            role_infos.push_back(QChatChannelCategoryMemberRoleInfo(c_resp.role_infos[i]));
        }
    }
    const NIMQChatGetChannelCategoryMemberRolesPageResp ToCParam() const {
        NIMQChatGetChannelCategoryMemberRolesPageResp c_response;
        c_response.res_code = res_code;
        role_infos_.clear();
        for (auto&& channel_member_role : role_infos) {
            role_infos_.push_back(channel_member_role.ToCParam());
        }
        c_response.member_role_count = role_infos_.size();
        c_response.role_infos = role_infos_.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatChannelCategoryMemberRoleInfo> role_infos_;
};

/// @struct QChatGetRolesByAccidResp
using QChatGetRolesByAccidResp = QChatGetServerRolesResp;

/// @struct QChatGetExistingServerRolesByAccidsResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetExistingServerRolesByAccidsResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::map<std::string, std::list<QChatServerRoleInfo>> roles_of_member_ids;
    QChatGetExistingServerRolesByAccidsResp() = default;
    QChatGetExistingServerRolesByAccidsResp(const NIMQChatGetServerRolesByMemberIdsResp& c_response) {
        res_code = c_response.res_code;
        if (c_response.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_response.count; i++) {
            auto& role_info_of_member = c_response.roles_of_member[i];
            std::list<QChatServerRoleInfo> roles;
            for (auto j = 0; j < role_info_of_member.role_count; j++) {
                QChatServerRoleInfo role_info = role_info_of_member.roles[j];
                roles.push_back(role_info);
            }
            roles_of_member_ids[role_info_of_member.member_id] = roles;
        }
    }
    const NIMQChatGetServerRolesByMemberIdsResp ToCParam() const {
        NIMQChatGetServerRolesByMemberIdsResp c_response;
        c_response.res_code = res_code;
        c_response.count = roles_of_member_ids.size();
        role_info_of_members_.clear();
        c_role_info_of_members_.clear();
        for (auto& roles_of_member : roles_of_member_ids) {
            std::vector<NIMQChatRoleInfo> roles;
            NIMQChatRoleInfoOfMember role_info_of_member;
            role_info_of_member.member_id = const_cast<char*>(roles_of_member.first.c_str());
            role_info_of_member.role_count = roles_of_member.second.size();
            for (auto& role_info : roles_of_member.second) {
                roles.push_back(role_info.ToCParam());
            }
            role_info_of_member.roles = roles.data();
            c_role_info_of_members_.push_back(std::move(roles));
            role_info_of_members_.push_back(std::move(role_info_of_member));
        }
        c_response.roles_of_member = role_info_of_members_.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatRoleInfoOfMember> role_info_of_members_;
    mutable std::list<std::vector<NIMQChatRoleInfo>> c_role_info_of_members_;
};

/// @struct QChatGetExistingChannelRolesByServerRoleIdsResp
using QChatGetExistingChannelRolesByServerRoleIdsResp = QChatGetChannelRolesResp;

/// @struct QChatGetExistingAccidsOfMemberRolesResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetExistingAccidsOfMemberRolesResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    std::list<std::string> member_ids_result;
    QChatGetExistingAccidsOfMemberRolesResp() = default;
    QChatGetExistingAccidsOfMemberRolesResp(const NIMQChatGetExistingAccidsOfMemberRolesResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_ids_count; i++) {
            member_ids_result.push_back(c_resp.member_ids[i]);
        }
    }
    const NIMQChatGetExistingAccidsOfMemberRolesResp ToCParam() const {
        NIMQChatGetExistingAccidsOfMemberRolesResp c_response;
        c_response.res_code = res_code;
        member_query_accids_.clear();
        for (auto&& member_id : member_ids_result) {
            member_query_accids_.push_back(const_cast<char*>(member_id.c_str()));
        }
        c_response.member_ids_count = member_query_accids_.size();
        c_response.member_ids = member_query_accids_.data();
        return c_response;
    }

protected:
    mutable std::vector<QChatMemberAccountId> member_query_accids_;
};

/// @struct QChatGetExistingAccidsInServerRoleResp
using QChatGetExistingAccidsInServerRoleResp = QChatGetExistingAccidsOfMemberRolesResp;

/// @struct QChatCheckPermissionResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatCheckPermissionResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    bool has_permission{false};
    QChatCheckPermissionResp() = default;
    QChatCheckPermissionResp(const NIMQChatCheckPermissionResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        has_permission = c_resp.has_permission;
    }
    const NIMQChatCheckPermissionResp ToCParam() const {
        NIMQChatCheckPermissionResp c_response;
        c_response.res_code = res_code;
        c_response.has_permission = has_permission;
        return c_response;
    }
};

/// @struct QChatCheckPermissionsResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatCheckPermissionsResp {
    /// 操作结果，@see NIMResCode
    NIMResCode res_code;
    /// 权限列表
    std::map<NIMQChatPermissions, NIMQChatPermissionsOption> permissions;
    QChatCheckPermissionsResp() = default;
    QChatCheckPermissionsResp(const NIMQChatCheckPermissionsResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        permissions.clear();
        for (size_t i = 0; i < c_resp.permissions_count; i++) {
            permissions.emplace(c_resp.permissions[i], c_resp.options[i]);
        }
    }
    const NIMQChatCheckPermissionsResp ToCParam() const {
        NIMQChatCheckPermissionsResp c_response;
        c_response.res_code = res_code;
        permissions_.clear();
        options_.clear();
        for (auto&& permission : permissions) {
            permissions_.push_back(permission.first);
            options_.push_back(permission.second);
        }
        c_response.permissions_count = permissions_.size();
        c_response.permissions = const_cast<NIMQChatPermissions*>(permissions_.data());
        c_response.options = const_cast<NIMQChatPermissionsOption*>(options_.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatPermissions> permissions_;
    mutable std::vector<NIMQChatPermissionsOption> options_;
};

// callbacks
using QChatCreateServerRoleCallback = std::function<void(const QChatCreateServerRoleResp&)>;
using QChatUpdateServerRoleCallback = std::function<void(const QChatUpdateServerRoleResp&)>;
using QChatBatchUpdateServerRolePrioritiesCallback = std::function<void(const QChatUpdateServerRolePrioritiesResp&)>;
using QChatDeleteServerRoleCallback = QChatBaseCallback;
using QChatGetServerRolesCallback = std::function<void(const QChatGetServerRolesResp&)>;
using QChatAddMembersToServerRoleCallback = std::function<void(const QChatAddMembersToServerRoleResp&)>;
using QChatRemoveMembersFromServerRoleCallback = std::function<void(const QChatRemoveMembersFromServerRoleResp&)>;
using QChatGetMembersFromServerRoleCallback = std::function<void(const QChatGetMembersFromServerRoleResp&)>;
using QChatAddChannelRoleCallback = std::function<void(const QChatAddChannelRoleResp&)>;
using QChatUpdateChannelRoleCallback = std::function<void(const QChatUpdateChannelRoleResp&)>;
using QChatRemoveChannelRoleCallback = QChatBaseCallback;
using QChatGetChannelRolesCallback = std::function<void(const QChatGetChannelRolesResp&)>;
using QChatAddMemberRoleCallback = std::function<void(const QChatAddMemberRoleResp&)>;
using QChatUpdateMemberRoleCallback = std::function<void(const QChatUpdateMemberRoleResp&)>;
using QChatRemoveMemberRoleCallback = QChatBaseCallback;
using QChatGetMemberRoleInChannelCallback = std::function<void(const QChatGetMemberRolesResp&)>;
using QChatGetRolesByMemberIdCallback = std::function<void(const QChatGetRolesByAccidResp&)>;
using QChatGetRolesByMemberIdsCallback = std::function<void(const QChatGetExistingServerRolesByAccidsResp&)>;
using QChatGetExistingRolesInChannelCallback = std::function<void(const QChatGetExistingChannelRolesByServerRoleIdsResp&)>;
using QChatGetExistingAccidsOfMemberRolesCallback = std::function<void(const QChatGetExistingAccidsOfMemberRolesResp&)>;
using QChatGetExistingAccidsInServerRoleCallback = std::function<void(const QChatGetExistingAccidsInServerRoleResp&)>;
using QChatCheckPermissionCallback = std::function<void(const QChatCheckPermissionResp&)>;
using QChatCheckPermissionsCallback = std::function<void(const QChatCheckPermissionsResp&)>;
using QChatAddChannelCategoryRoleCallback = std::function<void(const QChatAddChannelCategoryRoleResp&)>;
using QChatUpdateChannelCategoryRoleCallback = std::function<void(const QChatUpdateChannelCategoryRoleResp&)>;
using QChatRemoveChannelCategoryRoleCallback = QChatBaseCallback;
using QChatGetChannelCategoryRolesPageCallback = std::function<void(const QChatGetChannelCategoryRolesPageResp&)>;
using QChatAddChannelCategoryMemberRoleCallback = std::function<void(const QChatAddChannelCategoryMemberRoleResp&)>;
using QChatUpdateChannelCategoryMemberRoleCallback = std::function<void(const QChatUpdateChannelCategoryMemberRoleResp&)>;
using QChatRemoveChannelCategoryMemberRoleCallback = QChatBaseCallback;
using QChatGetChannelCategoryMemberRolesPageCallback = std::function<void(const QChatGetChannelCategoryMemberRolesPageResp&)>;

/// @struct QChatCreateServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatCreateServerRoleParam {
    QChatCreateServerRoleCallback cb;
    QChatServerRoleInfo info{};
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatCreateServerRoleParam() = default;
    QChatCreateServerRoleParam(const NIMQChatCreateServerRoleParam& param) {
        info = param.role_info;
        anti_spam_info = param.anti_spam_info;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatCreateServerRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatCreateServerRoleParam ToCParam() const {
        auto cb_holder = new QChatCreateServerRoleCallback(cb);
        NIMQChatCreateServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.role_info = info.ToCParam();
        c_param.anti_spam_info = anti_spam_info.ToCParam();
        c_param.cb = [](const NIMQChatCreateServerRoleResp* resp) {
            InvokeCallback<QChatCreateServerRoleCallback, NIMQChatCreateServerRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatUpdateServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateServerRoleParam {
    QChatUpdateServerRoleCallback cb;
    QChatServerRoleInfo info;
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatUpdateServerRoleParam() = default;
    QChatUpdateServerRoleParam(const NIMQChatUpdateServerRoleParam& param) {
        info = param.role_info;
        anti_spam_info = param.anti_spam_info;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatUpdateServerRoleResp& response) {
            NIMQChatUpdateServerRoleResp c_response;
            c_response.res_code = response.res_code;
            c_response.user_data = user_data;
            c_response.role_info = response.role_info.ToCParam();
            c_callback(&c_response);
        };
    }
    const NIMQChatUpdateServerRoleParam ToCParam() const {
        auto cb_holder = new QChatUpdateServerRoleCallback(cb);
        NIMQChatUpdateServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.role_info = info.ToCParam();
        c_param.anti_spam_info = anti_spam_info.ToCParam();
        c_param.cb = [](const NIMQChatUpdateServerRoleResp* resp) {
            InvokeCallback<QChatUpdateServerRoleCallback, NIMQChatUpdateServerRoleResp>(*resp);
        };

        return c_param;
    }
};

/// @struct QChatUpdateServerRolePrioritiesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateServerRolePrioritiesParam {
    QChatBatchUpdateServerRolePrioritiesCallback cb;
    uint64_t server_id = 0;
    /// 要批量更新的身份组信息，key: role_id, value: priority
    std::map<uint64_t, uint64_t> priority_map;
    QChatUpdateServerRolePrioritiesParam() = default;
    QChatUpdateServerRolePrioritiesParam(const NIMQChatBatchUpdateServerRolePrioritiesParam& param) {
        server_id = param.server_id;
        for (size_t i = 0; i < param.update_count; i++) {
            priority_map.emplace(param.update_priority_info[i].role_id, param.update_priority_info[i].priority);
        }
        cb = [c_callback = param.cb, user_data = param.user_data, this](const QChatUpdateServerRolePrioritiesResp& response) {
            NIMQChatUpdateServerRolePrioritiesResp c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatBatchUpdateServerRolePrioritiesParam ToCParam() const {
        auto cb_holder = new QChatBatchUpdateServerRolePrioritiesCallback(cb);
        NIMQChatBatchUpdateServerRolePrioritiesParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_role_infos_.clear();
        for (auto& priority_item : priority_map) {
            NIMQChatBatchUpdateServeRolePriorityGroup priority_group;
            priority_group.role_id = priority_item.first;
            priority_group.priority = priority_item.second;
            c_role_infos_.push_back(priority_group);
        }
        c_param.update_priority_info = c_role_infos_.data();
        c_param.update_count = c_role_infos_.size();
        c_param.cb = [](const NIMQChatUpdateServerRolePrioritiesResp* resp) {
            InvokeCallback<QChatBatchUpdateServerRolePrioritiesCallback, NIMQChatUpdateServerRolePrioritiesResp>(*resp);
        };

        return c_param;
    }

protected:
    mutable std::vector<NIMQChatBatchUpdateServeRolePriorityGroup> c_role_infos_;
};

/// @struct QChatDeleteServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatDeleteServerRoleParam {
    QChatDeleteServerRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 身份组 ID
    uint64_t role_id = 0;
    QChatDeleteServerRoleParam() = default;
    QChatDeleteServerRoleParam(const NIMQChatDeleteServerRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatDeleteServerRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatDeleteServerRoleParam ToCParam() const {
        auto cb_holder = new QChatDeleteServerRoleCallback(cb);
        NIMQChatDeleteServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        c_param.cb = [](const NIMQChatDeleteServerRoleResp* resp) {
            InvokeCallback<QChatDeleteServerRoleCallback, NIMQChatDeleteServerRoleResp>(*resp);
        };

        return c_param;
    }
};
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetServerRolesParam {
    QChatGetServerRolesCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 限制返回数量
    uint32_t limit = 0;
    /// 分页的起始优先级，起始页为0，自定义优先级区间 1~9007199254740991
    uint64_t priority = 0;
    /// 频道 ID, 如果非空，则只需要有该channel的管理权限即可，否则需要有server的管理权限
    uint64_t channel_id = 0;
    /// 频道分组 ID, 如果非空，则只需要有该channel_category的管理权限即可，否则需要有server的管理权限
    uint64_t channel_category_id = 0;
    QChatGetServerRolesParam() = default;
    QChatGetServerRolesParam(const NIMQChatGetServerRolesParam& param) {
        server_id = param.server_id;
        limit = param.limit;
        priority = param.priority;
        channel_id = param.channel_id;
        channel_category_id = param.channel_category_id;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetServerRolesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetServerRolesParam ToCParam() const {
        auto cb_holder = new QChatGetServerRolesCallback(cb);
        NIMQChatGetServerRolesParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.limit = limit;
        c_param.priority = priority;
        c_param.channel_id = channel_id;
        c_param.channel_category_id = channel_category_id;
        c_param.cb = [](const NIMQChatGetServerRolesResp* resp) {
            InvokeCallback<QChatGetServerRolesCallback, NIMQChatGetServerRolesResp>(*resp);
        };

        return c_param;
    }
};

/// @struct QChatAddMembersToServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddMembersToServerRoleParam {
    QChatAddMembersToServerRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 身份组 ID
    uint64_t role_id = 0;
    /// 要添加的成员列表
    std::list<std::string> members_accids;
    QChatAddMembersToServerRoleParam() = default;
    QChatAddMembersToServerRoleParam(const NIMQChatAddMembersToServerRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        for (size_t i = 0; i < param.member_count; i++)
            members_accids.push_back(param.members[i]);
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatAddMembersToServerRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatAddMembersToServerRoleParam ToCParam() const {
        auto cb_holder = new QChatAddMembersToServerRoleCallback(cb);
        NIMQChatAddMembersToServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        vec_members.clear();
        for (auto&& member_accid : members_accids)
            vec_members.push_back(const_cast<char*>(member_accid.c_str()));
        c_param.member_count = vec_members.size();
        c_param.members = vec_members.data();
        c_param.cb = [](const NIMQChatAddMembersToServerRoleResp* resp) {
            InvokeCallback<QChatAddMembersToServerRoleCallback, NIMQChatAddMembersToServerRoleResp>(*resp);
        };

        return c_param;
    }

protected:
    mutable std::vector<char*> vec_members;
};

/// @struct QChatRemoveMembersFromServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRemoveMembersFromServerRoleParam {
    QChatAddMembersToServerRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 身份组 ID
    uint64_t role_id = 0;
    /// 要移除的成员列表
    std::list<std::string> members_accids;
    QChatRemoveMembersFromServerRoleParam() = default;
    QChatRemoveMembersFromServerRoleParam(const NIMQChatRemoveMembersFromServerRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        for (size_t i = 0; i < param.member_count; i++)
            members_accids.push_back(param.members[i]);
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatRemoveMembersFromServerRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatRemoveMembersFromServerRoleParam ToCParam() const {
        auto cb_holder = new QChatRemoveMembersFromServerRoleCallback(cb);
        NIMQChatRemoveMembersFromServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        vec_members.clear();
        for (auto&& member_accid : members_accids)
            vec_members.push_back(const_cast<char*>(member_accid.c_str()));
        c_param.member_count = vec_members.size();
        c_param.members = vec_members.data();
        c_param.cb = [](const NIMQChatRemoveMembersFromServerRoleResp* resp) {
            InvokeCallback<QChatRemoveMembersFromServerRoleCallback, NIMQChatRemoveMembersFromServerRoleResp>(*resp);
        };

        return c_param;
    }

protected:
    mutable std::vector<char*> vec_members;
};

/// @struct QChatGetMembersFromServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMembersFromServerRoleParam {
    QChatGetMembersFromServerRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 身份组 ID
    uint64_t role_id = 0;
    /// 时间戳，从最新起查使用 0
    uint64_t timestamp = 0;
    /// 限制返回数量
    uint32_t limit = 0;
    /// 起查 accid，成员可能在同一个时间点被添加到某个身份组中
    std::string begin_accid;
    QChatGetMembersFromServerRoleParam() = default;
    QChatGetMembersFromServerRoleParam(const NIMQChatGetMembersFromServerRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        timestamp = param.timestamp;
        limit = param.limit;
        begin_accid = param.begin_accid;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetMembersFromServerRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetMembersFromServerRoleParam ToCParam() const {
        auto cb_holder = new QChatGetMembersFromServerRoleCallback(cb);
        NIMQChatGetMembersFromServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        c_param.timestamp = timestamp;
        c_param.limit = limit;
        c_param.begin_accid = const_cast<char*>(begin_accid.c_str());
        c_param.cb = [](const NIMQChatGetMembersFromServerRoleResp* resp) {
            InvokeCallback<QChatGetMembersFromServerRoleCallback, NIMQChatGetMembersFromServerRoleResp>(*resp);
        };

        return c_param;
    }
};

/// @struct QChatAddChannelRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddChannelRoleParam {
    QChatAddChannelRoleCallback cb;
    uint64_t server_id = 0;
    uint64_t parent_role_id = 0;
    uint64_t channel_id = 0;
    QChatAddChannelRoleParam() = default;
    QChatAddChannelRoleParam(const NIMQChatAddChannelRoleParam& param) {
        server_id = param.server_id;
        parent_role_id = param.parent_role_id;
        channel_id = param.channel_id;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatAddChannelRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatAddChannelRoleParam ToCParam() const {
        auto cb_holder = new QChatAddChannelRoleCallback(cb);
        NIMQChatAddChannelRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.parent_role_id = parent_role_id;
        c_param.channel_id = channel_id;
        c_param.cb = [](const NIMQChatAddChannelRoleResp* resp) {
            InvokeCallback<QChatAddChannelRoleCallback, NIMQChatAddChannelRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatUpdateChannelRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateChannelRoleParam {
    QChatUpdateChannelRoleCallback cb;
    uint64_t server_id = 0;
    uint64_t role_id = 0;
    uint64_t channel_id = 0;
    QChatPermission permissions{};
    QChatUpdateChannelRoleParam() = default;
    QChatUpdateChannelRoleParam(const NIMQChatUpdateChannelRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        channel_id = param.channel_id;
        for (size_t i = 0; i < param.permission_count; i++) {
            auto permission = param.permissions[i].permission;
            auto option = param.permissions[i].option;
            permissions.emplace(permission, option);
        }
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatUpdateChannelRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatUpdateChannelRoleParam ToCParam() const {
        auto cb_holder = new QChatUpdateChannelRoleCallback(cb);
        NIMQChatUpdateChannelRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        c_param.channel_id = channel_id;
        vec_permissions_.clear();
        for (auto&& permission : permissions) {
            vec_permissions_.push_back({permission.first, permission.second});
        }
        c_param.permission_count = vec_permissions_.size();
        c_param.permissions = vec_permissions_.data();
        c_param.cb = [](const NIMQChatUpdateChannelRoleResp* resp) {
            InvokeCallback<QChatUpdateChannelRoleCallback, NIMQChatUpdateChannelRoleResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> vec_permissions_;
};

/// @struct QChatRemoveChannelRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRemoveChannelRoleParam {
    QChatRemoveChannelRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 身份组 ID
    uint64_t role_id = 0;
    /// 频道 ID
    uint64_t channel_id = 0;
    QChatRemoveChannelRoleParam() = default;
    QChatRemoveChannelRoleParam(const NIMQChatRemoveChannelRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        channel_id = param.channel_id;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatRemoveChannelRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatRemoveChannelRoleParam ToCParam() const {
        auto cb_holder = new QChatRemoveChannelRoleCallback(cb);
        NIMQChatRemoveChannelRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.role_id = role_id;
        c_param.cb = [](const NIMQChatRemoveChannelRoleResp* resp) {
            InvokeCallback<QChatRemoveChannelRoleCallback, NIMQChatRemoveChannelRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatGetChannelRolesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetChannelRolesParam {
    QChatGetChannelRolesCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 频道 ID
    uint64_t channel_id = 0;
    /// 时间戳，查询最新指定为 0
    uint64_t timestamp = 0;
    /// 限制查询返回数量
    uint32_t limit = 0;
    QChatGetChannelRolesParam() = default;
    QChatGetChannelRolesParam(const NIMQChatGetChannelRolesParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        timestamp = param.timestamp;
        limit = param.limit;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetChannelRolesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetChannelRolesParam ToCParam() const {
        auto cb_holder = new QChatGetChannelRolesCallback(cb);
        NIMQChatGetChannelRolesParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.timestamp = timestamp;
        c_param.limit = limit;
        c_param.cb = [](const NIMQChatGetChannelRolesResp* resp) {
            InvokeCallback<QChatGetChannelRolesCallback, NIMQChatGetChannelRolesResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatAddMemberRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddMemberRoleParam {
    QChatAddMemberRoleCallback cb;
    uint64_t server_id = 0;
    uint64_t channel_id = 0;
    std::string accid;
    QChatAddMemberRoleParam() = default;
    QChatAddMemberRoleParam(const NIMQChatAddMemberRoleParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        accid = param.accid;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatAddMemberRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatAddMemberRoleParam ToCParam() const {
        auto cb_holder = new QChatAddMemberRoleCallback(cb);
        NIMQChatAddMemberRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.cb = [](const NIMQChatAddMemberRoleResp* resp) {
            InvokeCallback<QChatAddMemberRoleCallback, NIMQChatAddMemberRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatUpdateMemberRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateMemberRoleParam {
    QChatUpdateMemberRoleCallback cb;
    uint64_t server_id = 0;
    uint64_t channel_id = 0;
    std::string accid;
    QChatPermission permissions{};
    QChatUpdateMemberRoleParam() = default;
    QChatUpdateMemberRoleParam(const NIMQChatUpdateMemberRoleParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        accid = param.accid;
        for (size_t i = 0; i < param.permission_count; i++)
            permissions.emplace(param.permissions[i].permission, param.permissions[i].option);
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatUpdateMemberRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatUpdateMemberRoleParam ToCParam() const {
        auto cb_holder = new QChatUpdateMemberRoleCallback(cb);
        NIMQChatUpdateMemberRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        permissions_.clear();
        for (auto&& permission : permissions)
            permissions_.push_back({permission.first, permission.second});
        c_param.permission_count = permissions_.size();
        c_param.permissions = permissions_.data();
        c_param.cb = [](const NIMQChatUpdateMemberRoleResp* resp) {
            InvokeCallback<QChatUpdateMemberRoleCallback, NIMQChatUpdateMemberRoleResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> permissions_;
};

/// @struct QChatRemoveMemberRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRemoveMemberRoleParam {
    QChatRemoveMemberRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 频道 ID
    uint64_t channel_id = 0;
    /// 用户账号列表
    std::string accid;
    QChatRemoveMemberRoleParam() = default;
    QChatRemoveMemberRoleParam(const NIMQChatRemoveMemberRoleParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        accid = param.accid;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatRemoveMemberRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatRemoveMemberRoleParam ToCParam() const {
        auto cb_holder = new QChatRemoveMemberRoleCallback(cb);
        NIMQChatRemoveMemberRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.cb = [](const NIMQChatRemoveMemberRoleResp* resp) {
            InvokeCallback<QChatRemoveMemberRoleCallback, NIMQChatRemoveMemberRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatGetMemberRolesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetMemberRolesParam {
    QChatGetMemberRoleInChannelCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 频道 ID
    uint64_t channel_id = 0;
    /// 时间戳，查询最新指定为 0
    uint64_t timestamp = 0;
    /// 限制返回数量
    uint32_t limit = 0;
    QChatGetMemberRolesParam() = default;
    QChatGetMemberRolesParam(const NIMQChatGetMemberRolesParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        timestamp = param.timestamp;
        limit = param.limit;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetMemberRolesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetMemberRolesParam ToCParam() const {
        auto cb_holder = new QChatGetMemberRoleInChannelCallback(cb);
        NIMQChatGetMemberRolesParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.timestamp = timestamp;
        c_param.limit = limit;
        c_param.cb = [](const NIMQChatGetMemberRolesResp* resp) {
            InvokeCallback<QChatGetMemberRoleInChannelCallback, NIMQChatGetMemberRolesResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatGetRolesByAccidParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetRolesByAccidParam {
    QChatGetRolesByMemberIdCallback cb;
    /// 服务器 ID
    uint64_t server_id = 0;
    /// 用户账号
    std::string accid;
    /// 起查时间戳，返回最新传入 0
    uint64_t timestamp = 0;
    /// 限制返回数量
    uint32_t limit = 0;
    QChatGetRolesByAccidParam() = default;
    QChatGetRolesByAccidParam(const NIMQChatGetServerRolesByMembersIdParam& param) {
        server_id = param.server_id;
        accid = param.accid;
        timestamp = param.timestamp;
        limit = param.limit;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetRolesByAccidResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetServerRolesByMembersIdParam ToCParam() const {
        auto cb_holder = new QChatGetRolesByMemberIdCallback(cb);
        NIMQChatGetServerRolesByMembersIdParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.timestamp = timestamp;
        c_param.limit = limit;
        c_param.cb = [](const NIMQChatGetServerRolesByMembersIdResp* resp) {
            InvokeCallback<QChatGetRolesByMemberIdCallback, NIMQChatGetServerRolesByMembersIdResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatGetExistingServerRolesByAccidsParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetExistingServerRolesByAccidsParam {
    QChatGetRolesByMemberIdsCallback cb;
    uint64_t server_id{0};
    std::list<std::string> accids;
    QChatGetExistingServerRolesByAccidsParam() = default;
    QChatGetExistingServerRolesByAccidsParam(const NIMQChatGetServerRolesByMemberIdsParam& param) {
        server_id = param.server_id;
        for (size_t i = 0; i < param.account_count; i++) {
            accids.push_back(param.accids[i]);
        }
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetExistingServerRolesByAccidsResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetServerRolesByMemberIdsParam ToCParam() const {
        auto cb_holder = new QChatGetRolesByMemberIdsCallback(cb);
        NIMQChatGetServerRolesByMemberIdsParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.account_count = accids.size();
        accids_.clear();
        for (auto& accid : accids)
            accids_.push_back(const_cast<char*>(accid.c_str()));
        c_param.accids = accids_.data();
        c_param.cb = [](const NIMQChatGetServerRolesByMemberIdsResp* resp) {
            InvokeCallback<QChatGetRolesByMemberIdsCallback, NIMQChatGetServerRolesByMemberIdsResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<QChatMemberAccountId> accids_;
};

/// @struct QChatGetExistingChannelRolesByServerRoleIdsParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetExistingChannelRolesByServerRoleIdsParam {
    QChatGetExistingRolesInChannelCallback cb;
    uint64_t server_id{0};
    uint64_t channel_id{0};
    std::list<uint64_t> role_ids;
    QChatGetExistingChannelRolesByServerRoleIdsParam() = default;
    QChatGetExistingChannelRolesByServerRoleIdsParam(const NIMQChatGetExistingRolesInChannelParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        for (size_t i = 0; i < param.role_count; i++) {
            role_ids.push_back(param.role_ids[i]);
        }
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetExistingChannelRolesByServerRoleIdsResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetExistingRolesInChannelParam ToCParam() const {
        auto cb_holder = new QChatGetExistingRolesInChannelCallback(cb);
        NIMQChatGetExistingRolesInChannelParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.role_count = role_ids.size();
        role_ids_.clear();
        for (auto& roleid : role_ids)
            role_ids_.push_back(roleid);
        c_param.role_ids = role_ids_.data();
        c_param.cb = [](const NIMQChatGetExistingRolesInChannelResp* resp) {
            InvokeCallback<QChatGetExistingRolesInChannelCallback, NIMQChatGetExistingRolesInChannelResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<uint64_t> role_ids_;
};

/// @struct QChatGetExistingAccidsOfMemberRolesParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetExistingAccidsOfMemberRolesParam {
    QChatGetExistingAccidsOfMemberRolesCallback cb;
    uint64_t server_id{0};
    uint64_t channel_id{0};
    std::list<std::string> accids;
    QChatGetExistingAccidsOfMemberRolesParam() = default;
    QChatGetExistingAccidsOfMemberRolesParam(const NIMQChatGetExistingAccidsOfMemberRolesParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        for (size_t i = 0; i < param.account_count; i++) {
            accids.push_back(param.accids[i]);
        }
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetExistingAccidsOfMemberRolesResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetExistingAccidsOfMemberRolesParam ToCParam() const {
        auto cb_holder = new QChatGetExistingAccidsOfMemberRolesCallback(cb);
        NIMQChatGetExistingAccidsOfMemberRolesParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.account_count = accids.size();
        accids_.clear();
        for (auto& accid : accids)
            accids_.push_back(const_cast<char*>(accid.c_str()));
        c_param.accids = accids_.data();
        c_param.cb = [](const NIMQChatGetExistingAccidsOfMemberRolesResp* resp) {
            InvokeCallback<QChatGetExistingAccidsOfMemberRolesCallback, NIMQChatGetExistingAccidsOfMemberRolesResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<QChatMemberAccountId> accids_;
};

/// @struct QChatGetExistingAccidsInServerRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetExistingAccidsInServerRoleParam {
    QChatGetExistingAccidsInServerRoleCallback cb;
    uint64_t server_id{0};
    uint64_t role_id{0};
    std::list<std::string> accids;
    QChatGetExistingAccidsInServerRoleParam() = default;
    QChatGetExistingAccidsInServerRoleParam(const NIMQChatGetExistingAccidsInServerRoleParam& param) {
        server_id = param.server_id;
        role_id = param.role_id;
        for (size_t i = 0; i < param.account_count; i++) {
            accids.push_back(param.accids[i]);
        }
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetExistingAccidsInServerRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetExistingAccidsInServerRoleParam ToCParam() const {
        auto cb_holder = new QChatGetExistingAccidsInServerRoleCallback(cb);
        NIMQChatGetExistingAccidsInServerRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.role_id = role_id;
        c_param.account_count = accids.size();
        accids_.clear();
        for (auto& accid : accids)
            accids_.push_back(const_cast<char*>(accid.c_str()));
        c_param.accids = accids_.data();
        c_param.cb = [](const NIMQChatGetExistingAccidsInServerRoleResp* resp) {
            InvokeCallback<QChatGetExistingAccidsInServerRoleCallback, NIMQChatGetExistingAccidsInServerRoleResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<QChatMemberAccountId> accids_;
};

/// @struct QChatCheckPermissionParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatCheckPermissionParam {
    QChatCheckPermissionCallback cb;
    /// 服务器 id
    uint64_t server_id{0};
    /// 频道 id, 0表示查服务器下权限
    uint64_t channel_id{0};
    /// 查询的权限
    NIMQChatPermissions permission{kPermissionManageServer};
    QChatCheckPermissionParam() = default;
    QChatCheckPermissionParam(const NIMQChatCheckPermissionParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        permission = param.permission;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatCheckPermissionResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatCheckPermissionParam ToCParam() const {
        auto cb_holder = new QChatCheckPermissionCallback(cb);
        NIMQChatCheckPermissionParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.permission = permission;
        c_param.cb = [](const NIMQChatCheckPermissionResp* resp) {
            InvokeCallback<QChatCheckPermissionCallback, NIMQChatCheckPermissionResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatCheckPermissionsParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatCheckPermissionsParam {
    QChatCheckPermissionsCallback cb;
    /// 服务器 id
    uint64_t server_id{0};
    /// 频道 id, 0表示查服务器下权限
    uint64_t channel_id{0};
    /// 查询的权限列表
    std::vector<NIMQChatPermissions> permissions;
    QChatCheckPermissionsParam() = default;
    QChatCheckPermissionsParam(const NIMQChatCheckPermissionsParam& param) {
        server_id = param.server_id;
        channel_id = param.channel_id;
        for (size_t i = 0; i < param.permission_count; i++) {
            permissions.push_back(param.permissions[i]);
        }
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatCheckPermissionsResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatCheckPermissionsParam ToCParam() const {
        auto cb_holder = new QChatCheckPermissionsCallback(cb);
        NIMQChatCheckPermissionsParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.permission_count = permissions.size();
        c_param.permissions = const_cast<NIMQChatPermissions*>(permissions.data());
        c_param.cb = [](const NIMQChatCheckPermissionsResp* resp) {
            InvokeCallback<QChatCheckPermissionsCallback, NIMQChatCheckPermissionsResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatAddChannelCategoryRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddChannelCategoryRoleParam {
    QChatAddChannelCategoryRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id{0};
    /// 频道分组 ID
    uint64_t category_id{0};
    /// 服务器身份组ID
    uint64_t parent_role_id{0};
    QChatAddChannelCategoryRoleParam() = default;
    QChatAddChannelCategoryRoleParam(const NIMQChatAddChannelCategoryRoleParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        parent_role_id = param.parent_role_id;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatAddChannelCategoryRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatAddChannelCategoryRoleParam ToCParam() const {
        auto cb_holder = new QChatAddChannelCategoryRoleCallback(cb);
        NIMQChatAddChannelCategoryRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.parent_role_id = parent_role_id;
        c_param.cb = [](const NIMQChatAddChannelCategoryRoleResp* resp) {
            InvokeCallback<QChatAddChannelCategoryRoleCallback, NIMQChatAddChannelCategoryRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatUpdateChannelCategoryRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateChannelCategoryRoleParam {
    QChatUpdateChannelCategoryRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id{0};
    /// 频道分组 ID
    uint64_t category_id{0};
    /// 身份组 ID
    uint64_t role_id{0};
    /// 权限
    QChatPermission permissions{};
    QChatUpdateChannelCategoryRoleParam() = default;
    QChatUpdateChannelCategoryRoleParam(const NIMQChatUpdateChannelCategoryRoleParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        role_id = param.role_id;
        for (size_t i = 0; i < param.permission_count; i++)
            permissions.emplace(param.permissions[i].permission, param.permissions[i].option);
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatUpdateChannelCategoryRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatUpdateChannelCategoryRoleParam ToCParam() const {
        auto cb_holder = new QChatUpdateChannelCategoryRoleCallback(cb);
        NIMQChatUpdateChannelCategoryRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.role_id = role_id;
        permissions_.clear();
        for (auto&& permission : permissions)
            permissions_.push_back({permission.first, permission.second});
        c_param.permission_count = permissions_.size();
        c_param.permissions = permissions_.data();
        c_param.cb = [](const NIMQChatUpdateChannelCategoryRoleResp* resp) {
            InvokeCallback<QChatUpdateChannelCategoryRoleCallback, NIMQChatUpdateChannelCategoryRoleResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> permissions_;
};

/// @struct QChatRemoveChannelCategoryRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRemoveChannelCategoryRoleParam {
    QChatRemoveChannelCategoryRoleCallback cb;
    uint64_t server_id{0};
    uint64_t category_id{0};
    uint64_t role_id{0};
    QChatRemoveChannelCategoryRoleParam() = default;
    QChatRemoveChannelCategoryRoleParam(const NIMQChatRemoveChannelCategoryRoleParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        role_id = param.role_id;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatRemoveChannelCategoryRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatRemoveChannelCategoryRoleParam ToCParam() const {
        auto cb_holder = new QChatRemoveChannelCategoryRoleCallback(cb);
        NIMQChatRemoveChannelCategoryRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.role_id = role_id;
        c_param.cb = [](const NIMQChatRemoveChannelCategoryRoleResp* resp) {
            InvokeCallback<QChatRemoveChannelCategoryRoleCallback, NIMQChatRemoveChannelCategoryRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatGetChannelCategoryRolesPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetChannelCategoryRolesPageParam {
    QChatGetChannelCategoryRolesPageCallback cb;
    uint64_t server_id{0};
    uint64_t category_id{0};
    uint64_t timestamp{0};
    uint32_t limit{100};
    QChatGetChannelCategoryRolesPageParam() = default;
    QChatGetChannelCategoryRolesPageParam(const NIMQChatGetChannelCategoryRolesPageParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        timestamp = param.timestamp;
        limit = param.limit;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetChannelCategoryRolesPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetChannelCategoryRolesPageParam ToCParam() const {
        auto cb_holder = new QChatGetChannelCategoryRolesPageCallback(cb);
        NIMQChatGetChannelCategoryRolesPageParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.timestamp = timestamp;
        c_param.limit = limit;
        c_param.cb = [](const NIMQChatGetChannelCategoryRolesPageResp* resp) {
            InvokeCallback<QChatGetChannelCategoryRolesPageCallback, NIMQChatGetChannelCategoryRolesPageResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatAddChannelCategoryMemberRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAddChannelCategoryMemberRoleParam {
    QChatAddChannelCategoryMemberRoleCallback cb;
    uint64_t server_id{0};
    uint64_t category_id{0};
    std::string accid;
    QChatAddChannelCategoryMemberRoleParam() = default;
    QChatAddChannelCategoryMemberRoleParam(const NIMQChatAddChannelCategoryMemberRoleParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        accid = param.accid;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatAddChannelCategoryMemberRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatAddChannelCategoryMemberRoleParam ToCParam() const {
        auto cb_holder = new QChatAddChannelCategoryMemberRoleCallback(cb);
        NIMQChatAddChannelCategoryMemberRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.cb = [](const NIMQChatAddChannelCategoryMemberRoleResp* resp) {
            InvokeCallback<QChatAddChannelCategoryMemberRoleCallback, NIMQChatAddChannelCategoryMemberRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatUpdateChannelCategoryMemberRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatUpdateChannelCategoryMemberRoleParam {
    QChatUpdateChannelCategoryMemberRoleCallback cb;
    /// 服务器 ID
    uint64_t server_id{0};
    /// 频道分组 ID
    uint64_t category_id{0};
    /// 用户 ID
    std::string accid;
    /// 权限
    QChatPermission permissions{};
    QChatUpdateChannelCategoryMemberRoleParam() = default;
    QChatUpdateChannelCategoryMemberRoleParam(const NIMQChatUpdateChannelCategoryMemberRoleParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        accid = param.accid;
        for (size_t i = 0; i < param.permission_count; i++)
            permissions.emplace(param.permissions[i].permission, param.permissions[i].option);
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatUpdateChannelCategoryMemberRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatUpdateChannelCategoryMemberRoleParam ToCParam() const {
        auto cb_holder = new QChatUpdateChannelCategoryMemberRoleCallback(cb);
        NIMQChatUpdateChannelCategoryMemberRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        permissions_.clear();
        for (auto&& permission : permissions)
            permissions_.push_back({permission.first, permission.second});
        c_param.permission_count = permissions_.size();
        c_param.permissions = permissions_.data();
        c_param.cb = [](const NIMQChatUpdateChannelCategoryMemberRoleResp* resp) {
            InvokeCallback<QChatUpdateChannelCategoryMemberRoleCallback, NIMQChatUpdateChannelCategoryMemberRoleResp>(*resp);
        };
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatPermissionGroup> permissions_;
};

/// @struct QChatRemoveChannelCategoryMemberRoleParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatRemoveChannelCategoryMemberRoleParam {
    QChatRemoveChannelCategoryMemberRoleCallback cb;
    uint64_t server_id{0};
    uint64_t category_id{0};
    std::string accid;
    QChatRemoveChannelCategoryMemberRoleParam() = default;
    QChatRemoveChannelCategoryMemberRoleParam(const NIMQChatRemoveChannelCategoryMemberRoleParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        accid = param.accid;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatRemoveChannelCategoryMemberRoleResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatRemoveChannelCategoryMemberRoleParam ToCParam() const {
        auto cb_holder = new QChatRemoveChannelCategoryMemberRoleCallback(cb);
        NIMQChatRemoveChannelCategoryMemberRoleParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.cb = [](const NIMQChatRemoveChannelCategoryMemberRoleResp* resp) {
            InvokeCallback<QChatRemoveChannelCategoryMemberRoleCallback, NIMQChatRemoveChannelCategoryMemberRoleResp>(*resp);
        };
        return c_param;
    }
};

/// @struct QChatGetChannelCategoryMemberRolesPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGetChannelCategoryMemberRolesPageParam {
    QChatGetChannelCategoryMemberRolesPageCallback cb;
    uint64_t server_id{0};
    uint64_t category_id{0};
    uint64_t timestamp{0};
    uint32_t limit{100};
    QChatGetChannelCategoryMemberRolesPageParam() = default;
    QChatGetChannelCategoryMemberRolesPageParam(const NIMQChatGetChannelCategoryMemberRolesPageParam& param) {
        server_id = param.server_id;
        category_id = param.category_id;
        timestamp = param.timestamp;
        limit = param.limit;
        cb = [c_callback = param.cb, user_data = param.user_data](const QChatGetChannelCategoryMemberRolesPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(&c_response);
        };
    }
    const NIMQChatGetChannelCategoryMemberRolesPageParam ToCParam() const {
        auto cb_holder = new QChatGetChannelCategoryMemberRolesPageCallback(cb);
        NIMQChatGetChannelCategoryMemberRolesPageParam c_param{};
        c_param.user_data = cb_holder;
        c_param.server_id = server_id;
        c_param.category_id = category_id;
        c_param.timestamp = timestamp;
        c_param.limit = limit;
        c_param.cb = [](const NIMQChatGetChannelCategoryMemberRolesPageResp* resp) {
            InvokeCallback<QChatGetChannelCategoryMemberRolesPageCallback, NIMQChatGetChannelCategoryMemberRolesPageResp>(*resp);
        };
        return c_param;
    }
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_IDENTITY_CPP_DEF_H__
