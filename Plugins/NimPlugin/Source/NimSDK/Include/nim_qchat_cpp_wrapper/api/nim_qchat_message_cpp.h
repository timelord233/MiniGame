/**
 * @file nim_qchat_message_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-15
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_MESSAGE_CPP_H__
#define __NIM_QCHAT_MESSAGE_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_message_cpp_def.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {

/** @class Message
 * @brief 圈组消息
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API Message {
public:
    /** @fn void RegRecvCb(const QChatRegRecvMsgCbParam& param)
     * 注册接收消息回调
     * @param[in] param 接口参数 @see QChatRegRecvMsgCbParam
     * @return void
     */
    static void RegRecvCb(const QChatRegRecvMsgCbParam& param);

    /** @fn void void RegUpdatedCb(const QChatRegMsgUpdatedCbParam& param)
     * 注册消息更新回调
     * @param[in] param 接口参数 @see QChatRegMsgUpdatedCbParam
     * @return void
     */
    static void RegUpdatedCb(const QChatRegMsgUpdatedCbParam& param);

    /** @fn void Send(const QChatSendMessageParam& param)
     * 发送消息
     * @param[in] param 接口参数 @see QChatSendMessageParam
     * @return void
     */
    static void Send(const QChatSendMessageParam& param);

    /** @fn void Update(const QChatUpdateMessageParam& param)
     * 更新消息
     * @param[in] param 接口参数 @see QChatUpdateMessageParam
     */
    static void Update(const QChatUpdateMessageParam& param);

    /** @fn void Revoke(const QChatRevokeMessageParam& param)
     * 撤回消息，撤回未读消息不影响未读数
     * @param[in] param 接口参数 @see QChatRevokeMessageParam
     * @return void
     */
    static void Revoke(const QChatRevokeMessageParam& param);

    /** @fn void Delete(const QChatDeleteMessageParam& param)
     * 删除消息，删除未读消息影响未读数
     * @param[in] param 接口参数 @see QChatDeleteMessageParam
     * @return void
     */
    static void Delete(const QChatDeleteMessageParam& param);

    /** @fn void GetMessages(const QChatGetMessagesParam& param)
     * 查询历史消息
     * @param[in] param 接口参数 @see QChatGetMessagesParam
     * @return void
     */
    static void GetMessages(const QChatGetMessagesParam& param);

    /** @fn void GetMessagesCache(const QChatGetMessagesCacheParam& param)
     * @brief 查询本地消息历史缓存, 仅用于无网络情况或加速页面显示时使用，恢复通信后应使用GetMessages的结果进行覆盖
     *
     * @param param 要查询的服务器、频道信息 @see QChatGetMessagesCacheParam
     * @return void
     */
    static void GetMessagesCache(const QChatGetMessagesCacheParam& param);

    /** @fn void GetLastMessages(const QChatGetLastMessagesParam& param)
     * 查询频道最后一条消息
     * @param[in] param 接口参数 @see QChatGetLastMessagesParam
     * @return void
     */
    static void GetLastMessages(const QChatGetLastMessagesParam& param);

    /** @fn void MarkRead(const QChatMarkMessageReadParam& param)
     * 标记消息已读
     * @param[in] param 接口参数 @see QChatMarkMessageReadParam
     * @return void
     */
    static void MarkRead(const QChatMarkMessageReadParam& param);

    /** @fn void Reply(const QChatReplyMessageParam& param)
     * @brief 回复指定消息
     * @since v9.1.0
     * @param[in] param 接口参数 @see QChatReplyMessageParam
     */
    static void Reply(const QChatReplyMessageParam& param);

    /** @fn void GetMessageHistoryByIds(const QChatGetMessageHistoryByIdsParam& param)
     * @brief 通过一组消息 ID 查询消息详情
     * @since v9.1.0
     * @param param 接口参数 @see QChatGetMessageHistoryByIdsParam
     */
    static void GetMessageHistoryByIds(const QChatGetMessageHistoryByIdsParam& param);

    /** @fn void GetReferMessages(const QChatGetReferMessagesParam& param)
     * @brief 获取指定消息的引用消息内容
     * @since v9.1.0
     * @param param 接口参数 @see QChatGetReferMessagesParam
     */
    static void GetReferMessages(const QChatGetReferMessagesParam& param);

    /** @fn void GetThreadMessages(const QChatGetThreadMessagesParam& param)
     * @brief 分页获取一个 thread 消息得详细回复消息列表
     * @since v9.1.0
     * @param param 接口参数 @see QChatGetThreadMessagesParam
     */
    static void GetThreadMessages(const QChatGetThreadMessagesParam& param);

    /** @fn void GetThreadRootMessagesMeta(const QChatGetThreadRootMessagesMetaParam& param)
     * @brief 获取一批 thread root 消息的基本信息（回复次数，最后回复时间）
     * @since v9.1.0
     * @param param 接口参数 @see QChatGetThreadRootMessagesMetaParam
     */
    static void GetThreadRootMessagesMeta(const QChatGetThreadRootMessagesMetaParam& param);

    /** @fn void AddQuickComment(const QChatAddQuickCommentParam& param)
     * @brief 对指定消息添加快捷评论
     * @since v9.1.0
     * @param param 接口参数 @see QChatAddQuickCommentParam
     */
    static void AddQuickComment(const QChatAddQuickCommentParam& param);

    /** @fn void RemoveQuickComment(const QChatRemoveQuickCommentParam& param)
     * @brief 从某个消息上移除快捷评论
     * @since v9.1.0
     * @param param 接口参数 @see QChatRemoveQuickComm entParam
     */
    static void RemoveQuickComment(const QChatRemoveQuickCommentParam& param);

    /** @fn void GetQuickComments(const QChatGetQuickCommentsParam& param)
     * @brief 获取指定消息包含的快捷评论列表
     * @since v9.1.0
     * @param param 接口参数 @see QChatGetQuickCommentsParam
     */
    static void GetQuickComments(const QChatGetQuickCommentsParam& param);

    /** @fn void SearchMsgByPage(const QChatSearchMsgByPageParam& param)
     * @brief 分页搜索消息
     * @since v9.4.0
     * @param param 接口参数 @see QChatSearchMsgByPageParam
     */
    static void SearchMsgByPage(const QChatMessageSearchPageParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_MESSAGE_CPP_H__
