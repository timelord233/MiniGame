/**
 * @file nim_qchat_role_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_IDENTITY_CPP_H__
#define __NIM_QCHAT_IDENTITY_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_role_cpp_def.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {
/** @class Role
 * @brief 圈组身份组
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API Role {
public:
    /** @fn void CreateServerRole(const QChatCreateServerRoleParam& param)
     * @brief 在服务器中创建一个身份组
     * @param param 参数见 @see QChatCreateServerRoleParam
     */
    static void CreateServerRole(const QChatCreateServerRoleParam& param);

    /** @fn void UpdateServerRole(const QChatUpdateServerRoleParam& param)
     * @brief 更新服务器中指定身份组
     * @param param 参数见 @see QChatUpdateServerRoleParam
     */
    static void UpdateServerRole(const QChatUpdateServerRoleParam& param);

    /** @fn void UpdateServerRolePriorities(const QChatUpdateServerRolePrioritiesParam& param)
     * @brief 批量更新服务器身份组优先级，如果具备修改身份组优先级权限，则服务器会应用您传递的参数中身份组优先级列表所有的内容
     * 如在 UI 展示中，允许拖拽对身份组优先级进行排序，则在排序完成后将最终的排序列表传递到参数中即可。
     * @param param 参数见 @see QChatUpdateServerRolePrioritiesParam
     */
    static void UpdateServerRolePriorities(const QChatUpdateServerRolePrioritiesParam& param);

    /** @fn void DeleteServerRole(const QChatDeleteServerRoleParam& param)
     * @brief 从服务器中删除指定身份组
     * @param param 参数见 @see QChatDeleteServerRoleParam
     */
    static void DeleteServerRole(const QChatDeleteServerRoleParam& param);

    /** @fn void GetServerRoles(const QChatGetServerRolesParam& param)
     * @brief 获取指定服务器下已创建的身份组列表
     * @param param 参数见 @see QChatGetServerRolesParam
     */
    static void GetServerRoles(const QChatGetServerRolesParam& param);

    /** @fn void AddMembersToServerRole(const QChatAddMembersToServerRoleParam& param)
     * @brief 添加部分成员到服务器指定的身份组中
     * @param param 参数见 @see QChatAddMembersToServerRoleParam
     */
    static void AddMembersToServerRole(const QChatAddMembersToServerRoleParam& param);

    /** @fn void RemoveMembersFromServerRole(const QChatRemoveMembersFromServerRoleParam& param)
     * @brief 从服务器指定身份组移除部分成员
     * @param param 参数见 @see QChatRemoveMembersFromServerRoleParam
     */
    static void RemoveMembersFromServerRole(const QChatRemoveMembersFromServerRoleParam& param);

    /** @fn void GetMembersFromServerRole(const QChatGetMembersFromServerRoleParam& param)
     * @brief 分页从服务器指定身份组中查询成员列表
     * @param param 参数见 @see QChatGetMembersFromServerRoleParam
     */
    static void GetMembersFromServerRole(const QChatGetMembersFromServerRoleParam& param);

    /** @fn void AddChannelRole(const QChatAddChannelRoleParam& param)
     * @brief 添加一个身份组到频道
     * @param param 参数见 @see QChatAddChannelRoleParam
     */
    static void AddChannelRole(const QChatAddChannelRoleParam& param);

    /** @fn void UpdateChannelRole(const QChatUpdateChannelRoleParam& param)
     * @brief 更新频道中指定身份组的信息
     * @param param 参数见 @see QChatUpdateChannelRoleParam
     */
    static void UpdateChannelRole(const QChatUpdateChannelRoleParam& param);

    /** @fn void RemoveChannelRole(const QChatRemoveChannelRoleParam& param)
     * @brief 从频道中移除指定身份组
     * @param param 参数见 @see QChatRemoveChannelRoleParam
     */
    static void RemoveChannelRole(const QChatRemoveChannelRoleParam& param);

    /** @fn void GetChannelRoles(const QChatGetChannelRolesParam& param)
     * @brief 获取频道下所有已分配的身份组信息
     * @param param 参数见 @see QChatGetChannelRolesParam
     */
    static void GetChannelRoles(const QChatGetChannelRolesParam& param);

    /** @fn void AddMemberRole(const QChatAddMemberRoleParam& param)
     * @brief 在频道中添加针对指定人的特殊权限配置
     * @param param 参数见 @see QChatAddMemberRoleParam
     */
    static void AddMemberRole(const QChatAddMemberRoleParam& param);

    /** @fn void UpdateMemberRole(const QChatUpdateMemberRoleParam& param)
     * @brief 更新频道中指定人的特殊权限配置
     * @param param 参数见 @see QChatUpdateMemberRoleParam
     */
    static void UpdateMemberRole(const QChatUpdateMemberRoleParam& param);

    /** @fn void RemoveMemberRole(const QChatRemoveMemberRoleParam& param)
     * @brief 从频道中移除指定人的特殊权限配置
     * @param param 参数见 @see QChatRemoveMemberRoleParam
     */
    static void RemoveMemberRole(const QChatRemoveMemberRoleParam& param);

    /** @fn void GetMemberRoles(const QChatGetMemberRolesParam& param)
     * @brief 分页获取频道下所有针对人的特殊权限配置列表
     * @param param 参数见 @see QChatGetMemberRolesParam
     */
    static void GetMemberRoles(const QChatGetMemberRolesParam& param);

    /** @fn void GetRolesByAccid(const QChatGetRolesByAccidParam& param)
     * @brief 根据用户 ID 获取其已经分配的身份组列表
     * @param param 参数见 @see QChatGetRolesByAccidParam
     */
    static void GetRolesByAccid(const QChatGetRolesByAccidParam& param);

    /** @fn void GetExistingServerRolesByAccids(const QChatGetExistingServerRolesByAccidsParam& param)
     * @brief 根据一组用户列表查询该列表下所有用户的身份组列表信息
     * @param param 参数见 @see QChatGetExistingServerRolesByAccidsParam
     */
    static void GetExistingServerRolesByAccids(const QChatGetExistingServerRolesByAccidsParam& param);

    /** @fn void GetExistingChannelRolesByServerRoleIds(const QChatGetExistingChannelRolesByServerRoleIdsParam& param)
     * @brief 根据一组身份组列表查询频道中已经存在的身份组
     * @param param 参数见 @see QChatGetExistingChannelRolesByServerRoleIdsParam
     */
    static void GetExistingChannelRolesByServerRoleIds(const QChatGetExistingChannelRolesByServerRoleIdsParam& param);

    /** @fn void GetExistingAccidsOfMemberRoles(const QChatGetExistingAccidsOfMemberRolesParam& param)
     * @brief 根据一组用户 ID 查询指定频道下的定制权限信息
     * @param param 参数见 @see QChatGetExistingAccidsOfMemberRolesParam
     */
    static void GetExistingAccidsOfMemberRoles(const QChatGetExistingAccidsOfMemberRolesParam& param);

    /** void GetExistingAccidsInServerRole(const QChatGetExistingAccidsInServerRoleParam& param)
     * @brief 查询服务器某身份组是否包含指定成员
     * @param param 参数见 @see QChatGetExistingAccidsInServerRoleParam
     */
    static void GetExistingAccidsInServerRole(const QChatGetExistingAccidsInServerRoleParam& param);

    /** @fn void CheckPermission(const QChatCheckPermissionParam& param)
     * @brief 查询当前登录用户是否拥有特定权限
     * @param param 参数见 @see QChatGetRolesByAccidParam
     */
    static void CheckPermission(const QChatCheckPermissionParam& param);

    /** @fn void CheckPermissions(const QChatCheckPermissionsParam& param)
     * @brief 批量查询当前登录用户是否拥有特定权限
     * @param param 参数见 @see QChatCheckPermissionsParam
     */
    static void CheckPermissions(const QChatCheckPermissionsParam& param);

    /** @fn void AddChannelCategoryRole(const QChatAddChannelCategoryRoleParam& param)
     * @brief 添加一个身份组到频道分组
     * @param param 参数见 @see QChatAddChannelCategoryRoleParam
     */
    static void AddChannelCategoryRole(const QChatAddChannelCategoryRoleParam& param);

    /** @fn void RemoveChannelCategoryRole(const QChatRemoveChannelCategoryRoleParam& param)
     * @brief 从频道分组中移除身份组
     * @param param 参数见 @see QChatRemoveChannelCategoryRoleParam
     */
    static void RemoveChannelCategoryRole(const QChatRemoveChannelCategoryRoleParam& param);

    /** @fn void UpdateChannelCategoryRole(const QChatUpdateChannelCategoryRoleParam& param)
     * @brief 更新频道分组中的身份组
     * @param param 参数见 @see QChatUpdateChannelCategoryRoleParam
     */
    static void UpdateChannelCategoryRole(const QChatUpdateChannelCategoryRoleParam& param);

    /** @fn void GetChannelCategoryRolesPage(const QChatGetChannelCategoryRolesPageParam& param)
     * @brief 分页获取频道分组下的身份组列表
     * @param param 参数见 @see QChatGetChannelCategoryRolesPageParam
     */
    static void GetChannelCategoryRolesPage(const QChatGetChannelCategoryRolesPageParam& param);

    /** @fn void AddChannelCategoryMemberRole(const QChatAddChannelCategoryMemberRoleParam& param)
     * @brief 定制指定成员在频道分组中的权限
     * @param param 参数见 @see QChatAddChannelCategoryMemberRoleParam
     */
    static void AddChannelCategoryMemberRole(const QChatAddChannelCategoryMemberRoleParam& param);

    /** @fn void RemoveChannelCategoryMemberRole(const QChatRemoveChannelCategoryMemberRoleParam& param)
     * @brief 取消指定成员在频道分组中的权限
     * @param param 参数见 @see QChatRemoveChannelCategoryMemberRoleParam
     */
    static void RemoveChannelCategoryMemberRole(const QChatRemoveChannelCategoryMemberRoleParam& param);

    /** @fn void UpdateChannelCategoryMemberRole(const QChatUpdateChannelCategoryMemberRoleParam& param)
     * @brief 更新指定成员在频道分组中的权限
     * @param param 参数见 @see QChatUpdateChannelCategoryMemberRoleParam
     */
    static void UpdateChannelCategoryMemberRole(const QChatUpdateChannelCategoryMemberRoleParam& param);

    /** @fn void GetChannelCategoryMemberRolesPage(const QChatGetChannelCategoryMemberRolesPageParam& param)
     * @brief 分页获取频道分组下的成员权限列表
     * @param param 参数见 @see QChatGetChannelCategoryMemberRolesPageParam
     */
    static void GetChannelCategoryMemberRolesPage(const QChatGetChannelCategoryMemberRolesPageParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_IDENTITY_CPP_H__
