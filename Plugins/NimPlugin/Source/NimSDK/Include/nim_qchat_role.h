/**
 * @file nim_qchat_role.h
 * @author NetEase Yunxin
 * @brief 圈组身份组相关接口定义
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_ROLE_H__
#define __NIM_QCHAT_ROLE_H__

#include "nim_qchat_defines/nim_qchat_role_def.h"
#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_qchat_role_server_create(NIMQChatCreateServerRoleParam& param)
 * @brief 在服务器下创建身份组
 *
 * @param[in] param 接口参数 @see NIMQChatCreateServerRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_create(const NIMQChatCreateServerRoleParam& param);

/** @fn void nim_qchat_role_server_update(NIMQChatUpdateServerRoleParam& param)
 * @brief 更新服务器指定身份组信息
 *
 * @param[in] param 接口参数 @see NIMQChatUpdateServerRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_update(const NIMQChatUpdateServerRoleParam& param);

/** @fn void nim_qchat_role_server_batch_update_priorities(const NIMQChatBatchUpdateServerRolePrioritiesParam& param)
 * @brief 批量更新服务器身份组信息
 *
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_batch_update_priorities(const NIMQChatBatchUpdateServerRolePrioritiesParam& param);

/** @fn void nim_qchat_role_server_delete(NIMQChatDeleteServerRoleParam& param)
 * @brief 从服务器彻底删除指定身份组
 *
 * @param[in] param 接口参数 @see NIMQChatDeleteServerRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_delete(const NIMQChatDeleteServerRoleParam& param);

/** @fn void nim_qchat_role_server_get_list(NIMQChatGetServerRolesParam& param)
 * @brief 分页获取指定服务器下身份组列表
 *
 * @param[in] param 接口参数 @see NIMQChatGetServerRolesParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_get_list(const NIMQChatGetServerRolesParam& param);

/** @fn void nim_qchat_role_server_add_members(NIMQChatAddMembersToServerRoleParam& param)
 * @brief 将部分成员加入到指定服务器的指定身份组中
 *
 * @param[in] param 接口参数 @see NIMQChatAddMembersToServerRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_add_members(const NIMQChatAddMembersToServerRoleParam& param);

/** @fn void nim_qchat_role_server_remove_members(const NIMQChatRemoveMembersFromServerRoleParam& param)
 * @brief 将部分成员从服务器指定身份组中移除
 *
 * @param param 接口参数 @see NIMQChatRemoveMembersFromServerRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_remove_members(const NIMQChatRemoveMembersFromServerRoleParam& param);

/** @fn void nim_qchat_role_server_get_members(NIMQChatGetMembersFromServerRoleParam& param)
 * @brief 分页查询某服务器下指定身份组下的成员
 *
 * @param[in] param 接口参数 @see NIMQChatGetMembersFromServerRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_get_members(const NIMQChatGetMembersFromServerRoleParam& param);

/** @fn void nim_qchat_role_channel_add(NIMQChatAddChannelRoleParam& param);
 * @brief 将服务器指定身份组分配给频道
 *
 * @param[in] param 接口参数 @see NIMQChatAddChannelRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_channel_add(const NIMQChatAddChannelRoleParam& param);

/** @fn void nim_qchat_role_channel_update(const NIMQChatAddChannelRoleParam& param)
 * @brief 更新频道下的身份组信息
 *
 * @param[in] param 接口参数 @see NIMQChatUpdateChannelRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_channel_update(const NIMQChatUpdateChannelRoleParam& param);

/** @fn void nim_qchat_role_channel_remove(const NIMQChatAddChannelRoleParam& param)
 * @brief 从频道中移除指定身份组
 *
 * @param[in] param 接口参数 @see NIMQChatAddChannelRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_channel_remove(const NIMQChatRemoveChannelRoleParam& param);

/** @fn void nim_qchat_role_channel_get_list(const NIMQChatGetChannelRolesParam& param)
 * @brief 分页获取指定频道的身份组信息
 *
 * @param[in] param 接口参数 @see NIMQChatGetChannelRolesParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_channel_get_list(const NIMQChatGetChannelRolesParam& param);

/** @fn void nim_qchat_role_member_add(const NIMQChatAddMemberRoleParam& param)
 * @brief 定制指定成员在频道中的权限
 *
 * @param[in] param 接口参数 @see NIMQChatAddMemberRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_add(const NIMQChatAddMemberRoleParam& param);

/** @fn void nim_qchat_role_member_update(const NIMQChatUpdateMemberRoleParam& param)
 * @brief 更新指定成员在频道中的权限
 *
 * @param[in] param 接口参数 @see NIMQChatUpdateMemberRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_update(const NIMQChatUpdateMemberRoleParam& param);

/** @fn void nim_qchat_role_member_remove(const NIMQChatRemoveMemberRoleParam& param)
 * @brief 移除指定成员在频道中的定制权限
 *
 * @param[in] param 接口参数 @see NIMQChatRemoveMemberRoleParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_remove(const NIMQChatRemoveMemberRoleParam& param);

/** @fn void nim_qchat_role_member_get_list(const NIMQChatGetMemberRolesParam& param)
 * @brief 分页查询指定频道下针对成员的定制权限列表
 *
 * @param[in] param 接口参数 @see NIMQChatGetMemberRolesParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_get_list(const NIMQChatGetMemberRolesParam& param);

/** @fn void nim_qchat_role_member_get_server_roles(const NIMQChatGetServerRolesByMembersIdParam& param)
 * @brief 通过用户账号查询自定义身份组列表
 *
 * @param[in] param 接口参数 @see NIMQChatGetServerRolesByMembersIdParam
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_get_server_roles(const NIMQChatGetServerRolesByMembersIdParam& param);

/** @fn void nim_qchat_role_member_get_roles_by_member_ids(const NIMQChatGetServerRolesByMemberIdsParam& param)
 * @brief 通过一组 accid 列表查询该列表下所有人的所有已加入的身份组信息
 *
 * @param param 接口参数 @see
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_get_roles_by_member_ids(const NIMQChatGetServerRolesByMemberIdsParam& param);

/** @fn void nim_qchat_role_channel_get_existing_roles(const NIMQChatGetExistingRolesInChannelParam& param)
 * @brief 获取指定频道下已存在的身份组列表
 *
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_channel_get_existing_roles(const NIMQChatGetExistingRolesInChannelParam& param);

/** @fn void nim_qchat_role_member_get_existing_roles(const NIMQChatGetExistingAccidsOfMemberRolesParam& param)
 * @brief 批量获取指定频道下一批用户的定制权限信息，只会返回已存在的个人定制权限
 *
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_member_get_existing_roles(const NIMQChatGetExistingAccidsOfMemberRolesParam& param);

/** @fn void nim_qchat_role_server_get_existing_members(const NIMQChatGetExistingAccidsInServerRoleParam& param)
 * @brief 查询服务器某身份组是否包含指定成员
 *
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_server_get_existing_members(const NIMQChatGetExistingAccidsInServerRoleParam& param);

/** @fn void nim_qchat_role_check_permission(const NIMQChatCheckPermissionParam& param)
 * @brief 查询当前登录用户是否拥有特定权限
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_check_permission(const NIMQChatCheckPermissionParam& param);

/** @fn void nim_qchat_role_check_permissions(const NIMQChatCheckPermissionsParam& param)
 * @brief 批量查询当前登录用户是否拥有特定权限
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_check_permissions(const NIMQChatCheckPermissionsParam& param);

/** @fn void nim_qchat_role_add_channel_category_role(const NIMQChatAddChannelCategoryRoleParam& param)
 * @brief 添加一个身份组到频道分组
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_add_channel_category_role(const NIMQChatAddChannelCategoryRoleParam& param);

/** @fn void nim_qchat_role_remove_channel_category_role(const NIMQChatRemoveChannelCategoryRoleParam& param)
 * @brief 从频道分组中移除一个身份组
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_remove_channel_category_role(const NIMQChatRemoveChannelCategoryRoleParam& param);

/** @fn void nim_qchat_role_update_channel_category_role(const NIMQChatUpdateChannelCategoryRoleParam& param)
 * @brief 更新频道分组中的身份组信息
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_update_channel_category_role(const NIMQChatUpdateChannelCategoryRoleParam& param);

/** @fn void nim_qchat_role_get_channel_category_roles_page(const NIMQChatGetChannelCategoryRolesPageParam& param)
 * @brief 分页获取频道分组下的身份组列表
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_get_channel_category_roles_page(const NIMQChatGetChannelCategoryRolesPageParam& param);

/** @fn void nim_qchat_role_add_channel_category_member_role(const NIMQChatAddChannelCategoryMemberRoleParam& param)
 * @brief 定制指定成员在频道分组中的权限
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_add_channel_category_member_role(const NIMQChatAddChannelCategoryMemberRoleParam& param);

/** @fn void nim_qchat_role_remove_channel_category_member_role(const NIMQChatRemoveChannelCategoryMemberRoleParam& param)
 * @brief 取消指定成员在频道分组中的权限
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_remove_channel_category_member_role(const NIMQChatRemoveChannelCategoryMemberRoleParam& param);

/** @fn void nim_qchat_role_update_channel_category_member_role(const NIMQChatUpdateChannelCategoryMemberRoleParam& param)
 * @brief 更新指定成员在频道分组中的权限
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_update_channel_category_member_role(const NIMQChatUpdateChannelCategoryMemberRoleParam& param);

/** @fn void nim_qchat_role_get_channel_category_member_roles_page(const NIMQChatGetChannelCategoryMemberRolesPageParam& param)
 * @brief 分页获取频道分组下的成员权限列表
 * @param param
 * @return 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_role_get_channel_category_member_roles_page(const NIMQChatGetChannelCategoryMemberRolesPageParam& param);
#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_ROLE_H__
