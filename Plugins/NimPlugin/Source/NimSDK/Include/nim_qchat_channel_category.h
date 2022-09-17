/**
 * @file nim_qchat_channel_category.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_H__
#define __NIM_QCHAT_CHANNEL_H__

#include "nim_qchat_defines/nim_qchat_channel_def.h"
#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_qchat_channel_category_create(const NIMQChatChannelCategoryCreateParam& param)
 * @brief   创建频道分组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_create(const NIMQChatChannelCategoryCreateParam& param);

/** @fn void nim_qchat_channel_category_remove(const NIMQChatChannelCategoryRemoveParam& param)
 * @brief   删除频道分组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_remove(const NIMQChatChannelCategoryRemoveParam& param);

/** @fn void nim_qchat_channel_category_update(const NIMQChatChannelCategoryUpdateParam& param)
 * @brief   删除频道分组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_update(const NIMQChatChannelCategoryUpdateParam& param);

/** @fn void nim_qchat_channel_get_categories_by_id(const NIMQChatChannelGetCategoriesByIDParam& param)
 * @brief   根据频道分组ID查询频道分组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_get_categories_by_id(const NIMQChatChannelGetCategoriesByIDParam& param);

/** @fn void nim_qchat_channel_get_categories_page(const NIMQChatChannelGetCategoriesPageParam& param)
 * @brief   查询频道分组列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_get_categories_page(const NIMQChatChannelGetCategoriesPageParam& param);

/** @fn void nim_qchat_channel_get_category_channels_page(const NIMQChatChannelGetCategoryChannelsPageParam& param)
 * @brief   查询频道分组下的频道列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_get_category_channels_page(const NIMQChatChannelGetCategoryChannelsPageParam& param);

/** @fn void nim_qchat_channel_category_update_white_black_role(const NIMQChatChannelCategoryUpdateWhiteBlackRoleParam& param)
 * @brief   更新频道分组白/黑名单身份组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_update_white_black_role(const NIMQChatChannelCategoryUpdateWhiteBlackRoleParam& param);

/** @fn void nim_qchat_channel_category_get_white_black_roles_by_id(const NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam& param)
 * @brief   根据ID查询频道分组白/黑名单身份组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_get_white_black_roles_by_id(const NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam& param);

/** @fn void nim_qchat_channel_category_get_white_black_roles_page(const NIMQChatChannelCategoryGetWhiteBlackRolesPageParam& param)
 * @brief   查询频道分组白/黑名单身份组列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_get_white_black_roles_page(const NIMQChatChannelCategoryGetWhiteBlackRolesPageParam& param);

/** @fn void nim_qchat_channel_category_update_white_black_members(const NIMQChatChannelCategoryUpdateWhiteBlackMembersParam& param)
 * @brief   更新频道分组白/黑名单成员
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_update_white_black_members(const NIMQChatChannelCategoryUpdateWhiteBlackMembersParam& param);

/** @fn void nim_qchat_channel_category_get_white_black_members_by_id(const NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam& param)
 * @brief   根据ID查询频道分组白/黑名单成员
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_get_white_black_members_by_id(const NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam& param);

/** @fn void nim_qchat_channel_category_get_white_black_members_page(const NIMQChatChannelCategoryGetWhiteBlackMembersPageParam& param)
 * @brief   查询频道分组白/黑名单成员列表(分页)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_channel_category_get_white_black_members_page(const NIMQChatChannelCategoryGetWhiteBlackMembersPageParam& param);

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_CHANNEL_H__
