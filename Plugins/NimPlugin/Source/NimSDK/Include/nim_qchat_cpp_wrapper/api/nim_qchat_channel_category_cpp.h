/**
 * @file nim_qchat_channel_category_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-05-10
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_CATEGORY_CPP_H__
#define __NIM_QCHAT_CHANNEL_CATEGORY_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_channel_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {

/** @class ChannelCategory
 * @brief 圈组频道分组
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API ChannelCategory {
public:
    /** @fn void CreateChannelCategory(const QChatChannelCategoryCreateParam& param)
     * 创建频道分组
     * @param[in] param 接口参数
     * @return void
     */
    static void CreateChannelCategory(const QChatChannelCategoryCreateParam& param);

    /** @fn void UpdateChannelCategory(const QChatChannelCategoryUpdateParam& param)
     * 更新频道分组
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateChannelCategory(const QChatChannelCategoryUpdateParam& param);

    /** @fn void RemoveChannelCategory(const QChatChannelCategoryRemoveParam& param)
     * 删除频道分组
     * @param[in] param 接口参数
     * @return void
     */
    static void RemoveChannelCategory(const QChatChannelCategoryRemoveParam& param);

    /** @fn void GetChannelCategoriesByID(const QChatChannelGetCategoriesByIDParam& param)
     * 根据分组ID查询频道分组
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannelCategoriesByID(const QChatChannelGetCategoriesByIDParam& param);

    /** @fn void GetChannelCategoriesPage(const QChatChannelGetCategoriesPageParam& param)
     * 查询频道分组列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannelCategoriesPage(const QChatChannelGetCategoriesPageParam& param);

    /** @fn void GetChannelCategoryChannelsPage(const QChatChannelGetCategoryChannelsPageParam& param)
     * 查询频道分组下频道列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannelCategoryChannelsPage(const QChatChannelGetCategoryChannelsPageParam& param);

    /** @fn void UpdateChannelCategoryWhiteBlackRole(const QChatChannelCategoryUpdateWhiteBlackRoleParam& param)
     * 更新频道分组白/黑名单身份组
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateChannelCategoryWhiteBlackRole(const QChatChannelCategoryUpdateWhiteBlackRoleParam& param);

    /** @fn void GetExistingChannelCategoryWhiteBlackRoles(const QChatChannelCategoryGetExistingWhiteBlackRolesParam& param)
     * 根据身份组ID查询频道分组白/黑名单身份组列表
     * @param[in] param 接口参数
     * @return void
     */
    static void GetExistingChannelCategoryWhiteBlackRoles(const QChatChannelCategoryGetExistingWhiteBlackRolesParam& param);

    /** @fn void GetChannelCategoryWhiteBlackRolesPage(const QChatChannelCategoryGetWhiteBlackRolesPageParam& param)
     * 查询频道分组白/黑名单身份组列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannelCategoryWhiteBlackRolesPage(const QChatChannelCategoryGetWhiteBlackRolesPageParam& param);

    /** @fn void UpdateChannelCategoryWhiteBlackMembers(const QChatChannelCategoryUpdateWhiteBlackMembersParam& param)
     * 更新频道分组白/黑名单成员
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateChannelCategoryWhiteBlackMembers(const QChatChannelCategoryUpdateWhiteBlackMembersParam& param);

    /** @fn void GetExistingChannelCategoryWhiteBlackMembers(const QChatChannelCategoryGetExistingWhiteBlackMembersParam& param)
     * 根据成员ID查询频道分组白/黑名单成员列表
     * @param[in] param 接口参数
     * @return void
     */
    static void GetExistingChannelCategoryWhiteBlackMembers(const QChatChannelCategoryGetExistingWhiteBlackMembersParam& param);

    /** @fn void GetChannelCategoryWhiteBlackMembersPage(const QChatChannelCategoryGetWhiteBlackMembersPageParam& param)
     * 查询频道分组白/黑名单成员列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannelCategoryWhiteBlackMembersPage(const QChatChannelCategoryGetWhiteBlackMembersPageParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_CHANNEL_CATEGORY_CPP_H__
