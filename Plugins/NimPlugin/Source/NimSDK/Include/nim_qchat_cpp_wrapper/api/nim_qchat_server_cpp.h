/**
 * @file nim_qchat_server_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-15
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SERVER_CPP_H__
#define __NIM_QCHAT_SERVER_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_server_cpp_def.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {

/** @class Server
 * @brief 圈组服务器
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API Server {
public:
    /** @fn void RegUnreadCb(const QChatServerRegUnreadCbParam& param)
     * 注册未读数变更回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegUnreadCb(const QChatServerRegUnreadCbParam& param);

    /** @fn void CreateServer(const QChatServerCreateParam& param)
     * 创建服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void CreateServer(const QChatServerCreateParam& param);

    /** @fn void DeleteServer(const QChatServerDeleteParam& param)
     * 删除服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void DeleteServer(const QChatServerDeleteParam& param);

    /** @fn void UpdateServer(const QChatServerUpdateParam& param)
     * 更新服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateServer(const QChatServerUpdateParam& param);

    /** @fn void Subscribe(const QChatServerSubscribeParam& param)
     * 订阅指定服务器下的系统通知消息
     * @param[in] param 接口参数
     * @return void
     */
    static void Subscribe(const QChatServerSubscribeParam& param);

    /** @fn void SubscribeAllChannel(const QChatServerSubscribeAllChannelParam& param)
     * 订阅服务器下所有频道的消息
     * @param[in] param 接口参数
     * @return void
     */
    static void SubscribeAllChannel(const QChatServerSubscribeAllChannelParam& param);

    /** @fn void MarkRead(const QChatServerMarkReadParam& param)
     * 标记服务器下所有频道的消息为已读
     * @param[in] param 接口参数
     * @return void
     */
    static void MarkRead(const QChatServerMarkReadParam& param);

    /** @fn void GetServers(const QChatServerGetServersParam& param)
     * 查询服务器列表
     * @param[in] param 接口参数
     * @return void
     */
    static void GetServers(const QChatServerGetServersParam& param);

    /** @fn void GetServersByPage(const QChatServerGetServersPageParam& param)
     * 查询服务器列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetServersByPage(const QChatServerGetServersPageParam& param);

    /** @fn void Invite(const QChatServerInviteParam& param)
     * 邀请用户加入服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void Invite(const QChatServerInviteParam& param);

    /** @fn void AcceptInvite(const QChatServerAcceptInviteParam& param)
     * 接受加入服务器邀请
     * @param[in] param 接口参数
     * @return void
     */
    static void AcceptInvite(const QChatServerAcceptInviteParam& param);

    /** @fn void RejectInvite(const QChatServerRejectInviteParam& param)
     * 拒绝加入服务器邀请
     * @param[in] param 接口参数
     * @return void
     */
    static void RejectInvite(const QChatServerRejectInviteParam& param);

    /** @fn void Apply(const QChatServerApplyParam& param)
     * 申请加入服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void Apply(const QChatServerApplyParam& param);

    /** @fn void AcceptApply(const QChatServerAcceptApplyParam& param)
     * 同意加入服务器申请
     * @param[in] param 接口参数
     * @return void
     */
    static void AcceptApply(const QChatServerAcceptApplyParam& param);

    /** @fn void RejectApply(const QChatServerRejectApplyParam& param)
     * 拒绝加入服务器申请
     * @param[in] param 接口参数
     * @return void
     */
    static void RejectApply(const QChatServerRejectApplyParam& param);

    /** @fn void Kick(const QChatServerKickParam& param)
     * 将指定用户踢出服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void Kick(const QChatServerKickParam& param);

    /** @fn void Leave(const QChatServerLeaveParam& param)
     * 离开指定服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void Leave(const QChatServerLeaveParam& param);

    /** @fn void UpdateMemberInfo(const QChatServerUpdateMemberInfoParam& param)
     * 更新服务器成员信息
     * @param[in] param 接口参数
     * @return void
     */
    static void UpdateMemberInfo(const QChatServerUpdateMemberInfoParam& param);

    /** @fn void GetServerMembers(const QChatServerGetMembersParam& param)
     * 查询服务器成员列表
     * @param[in] param 接口参数
     * @return void
     */
    static void GetServerMembers(const QChatServerGetMembersParam& param);

    /** @fn void GetServerMembersByPage(const QChatServerGetMembersPageParam& param)
     * 查询服务器成员列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetServerMembersByPage(const QChatServerGetMembersPageParam& param);

    /** @fn void BanMember(const QChatServerBanMemberParam& param)
     * 封禁服务器成员
     * @param[in] param 接口参数
     * @return void
     */
    static void BanMember(const QChatServerBanMemberParam& param);

    /** @fn void UnbanMember(const QChatServerUnbanMemberParam& param)
     * 解封服务器成员
     * @param[in] param 接口参数
     * @return void
     */
    static void UnbanMember(const QChatServerUnbanMemberParam& param);

    /** @fn void GetBannedMembersByPage(const QChatServerGetBannedMembersPageParam& param)
     * 查询服务器封禁成员列表(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void GetBannedMembersByPage(const QChatServerGetBannedMembersPageParam& param);

    /** @fn void ServerSearchByPage(const QChatServerSearchPageParam& param)
     * 根据关键字搜索服务器(分页)
     * @param[in] param 接口参数
     * @return void
     */
    static void ServerSearchByPage(const QChatServerSearchPageParam& param);

    /** @fn void ServerMemberSearch(const QChatServerMemberSearchParam& param)
     * 根据关键字搜索服务器成员
     * @param[in] param 接口参数
     * @return void
     */
    static void ServerMemberSearch(const QChatServerMemberSearchParam& param);

    /** @fn void GenerateInviteCode(const QChatServerGenerateInviteCodeParam& param)
     * 生成服务器邀请码
     * @param[in] param 接口参数
     * @return void
     */
    static void GenerateInviteCode(const QChatServerGenerateInviteCodeParam& param);

    /** @fn void JoinByInviteCode(const QChatServerJoinByInviteCodeParam& param)
     * 通过邀请码加入服务器
     * @param[in] param 接口参数
     * @return void
     */
    static void JoinByInviteCode(const QChatServerJoinByInviteCodeParam& param);

    /** @fn void GetInviteApplyRecordOfServer(const QChatServerGetInviteApplyRecordOfServerParam& param)
     * 查询服务器下邀请申请历史
     * @param[in] param 接口参数
     * @return void
     */
    static void GetInviteApplyRecordOfServer(const QChatServerGetInviteApplyRecordOfServerParam& param);

    /** @fn void GetInviteApplyRecordOfSelf(const QChatServerGetInviteApplyRecordOfSelfParam& param)
     * 查询自己邀请申请历史
     * @param[in] param 接口参数
     * @return void
     */
    static void GetInviteApplyRecordOfSelf(const QChatServerGetInviteApplyRecordOfSelfParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_SERVER_CPP_H__
