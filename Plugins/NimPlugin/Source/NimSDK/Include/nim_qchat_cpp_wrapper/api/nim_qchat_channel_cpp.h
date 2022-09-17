/**
 * @file nim_qchat_channel_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-15
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_CPP_H__
#define __NIM_QCHAT_CHANNEL_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_channel_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {

/** @class Channel
 * @brief 圈组频道
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API Channel {
public:
    /** @fn void RegUnreadCb(const QChatChannelRegUnreadCbParam& param)
     * 注册未读数变更回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegUnreadCb(const QChatChannelRegUnreadCbParam& param);

    /** @fn void CreateChannel(const QChatChannelCreateParam& param)
     * 创建频道
     * @param[in] param 接口参数
     * @return void
     */
    static void CreateChannel(const QChatChannelCreateParam& param);

    /** @fn void DeleteChannel(const QChatChannelDeleteParam& param)
     * 删除频道
     * @param[in] param 接口参数
     * @return void
     */
    static void DeleteChannel(const QChatChannelDeleteParam& param);

    /** @fn void UpdateChannel(const QChatChannelUpdateParam& param)
     * 更新频道
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateChannel(const QChatChannelUpdateParam& param);

    /** @fn void UpdateCategoryInfo(const QChatChannelUpdateCategoryInfoParam& param)
     * 更新频道的分组信息
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateCategoryInfo(const QChatChannelUpdateCategoryInfoParam& param);

    /** @fn void Subscribe(const QChatChannelSubscribeParam& param)
     * 订阅频道未读状态、未读数或未读消息、事件
     * @param[in] param 接口参数
     * @return void
     */
    static void Subscribe(const QChatChannelSubscribeParam& param);

    /** @fn void QueryUnreadInfo(const QChatChannelQueryUnreadInfoParam& param)
     * 查询消息未读数
     * @param[in] param 接口参数
     * @return void
     */
    static void QueryUnreadInfo(const QChatChannelQueryUnreadInfoParam& param);

    /** @fn void GetChannels(const QChatChannelGetChannelsParam& param)
     * 查询频道列表
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannels(const QChatChannelGetChannelsParam& param);

    /** @fn void GetChannelsByPage(const QChatChannelGetChannelsPageParam& param)
     * 查询频道列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetChannelsByPage(const QChatChannelGetChannelsPageParam& param);

    /** @fn void GetMembersByPage(const QChatChannelGetMembersPageParam& param)
     * 查询频道用户列表(分页)，与查询服务器成员不同，查询频道成员指可以查看该频道的成员信息，取决于频道的白/黑名单设置
     * 私有频道设置的白名单用户为该频道下的成员，公共频道除了黑名单中的成员均可以访问该频道
     * @param[in] param 接口参数
     * @return void
     */
    static void GetMembersByPage(const QChatChannelGetMembersPageParam& param);

    /** @fn void UpdateWhiteBlackRole(const QChatChannelUpdateWhiteBlackRoleParam& param)
     * 更新频道白/黑名单身份组，公开频道:黑名单，私有频道:白名单
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateWhiteBlackRole(const QChatChannelUpdateWhiteBlackRoleParam& param);

    /** @fn void UpdateWhiteBlackMembers(const QChatChannelUpdateWhiteBlackMembersParam& param)
     * 更新频道白/黑名单成员，公开频道:黑名单，私有频道:白名单
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateWhiteBlackMembers(const QChatChannelUpdateWhiteBlackMembersParam& param);

    /** @fn void GetWhiteBlackRolesPage(const QChatChannelGetWhiteBlackRolesPageParam& param)
     * 查询频道白/黑名单身份组列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetWhiteBlackRolesPage(const QChatChannelGetWhiteBlackRolesPageParam& param);

    /** @fn void GetWhiteBlackMembersPage(const QChatChannelGetWhiteBlackMembersPageParam& param)
     * 查询频道白/黑名单成员列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetWhiteBlackMembersPage(const QChatChannelGetWhiteBlackMembersPageParam& param);

    /** @fn void GetExistingWhiteBlackRoles(const QChatChannelGetExistingWhiteBlackRolesParam& param)
     * 根据身份组ID查询已存在的白/黑名单身份组
     * @param[in] param 接口参数
     * @return void
     */
    static void GetExistingWhiteBlackRoles(const QChatChannelGetExistingWhiteBlackRolesParam& param);

    /** @fn void GetExistingWhiteBlackMembers(const QChatChannelGetExistingWhiteBlackMembersParam& param)
     * 根据成员ID查询已存在的白/黑名单成员
     * @param[in] param 接口参数
     * @return void
     */
    static void GetExistingWhiteBlackMembers(const QChatChannelGetExistingWhiteBlackMembersParam& param);

    /** @fn void ChannelSearchByPage(const QChatChannelSearchByPageParam& param)
     * 根据关键字搜索频道列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void ChannelSearchByPage(const QChatChannelSearchPageParam& param);

    /** @fn void ChannelMemberSearch(const QChatChannelMemberSearchParam& param)
     * 根据关键字搜索频道成员列表
     * @param[in] param 接口参数
     * @return void
     */
    static void ChannelMemberSearch(const QChatChannelMemberSearchParam& param);

    /** @fn void UpdateRTCInfo(const QChatChannelUpdateRTCInfoParam& param)
     * 更新频道RTC信息
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateRTCInfo(const QChatChannelUpdateRTCInfoParam& param);

    /** @fn void GetRTCInfo(const QChatChannelGetRTCInfoParam& param)
     * 查询频道RTC信息
     * @param[in] param 接口参数
     * @return void
     */
    static void GetRTCInfo(const QChatChannelGetRTCInfoParam& param);

    /** @fn void GetRTCOnlineMembers(const QChatChannelGetRTCOnlineMembersParam& param)
     * 查询频道RTC在线成员列表
     * @param[in] param 接口参数
     * @return void
     */
    static void GetRTCOnlineMembers(const QChatChannelGetRTCOnlineMembersParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_CHANNEL_CPP_H__
