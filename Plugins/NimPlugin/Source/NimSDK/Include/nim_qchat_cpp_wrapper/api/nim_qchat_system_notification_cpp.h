/**
 * @file nim_qchat_system_notification_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-15
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SYSMSG_CPP_H__
#define __NIM_QCHAT_SYSMSG_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_system_notification_cpp_def.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {

/** @class SystemNotification
 * @brief 圈组系统通知
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API SystemNotification {
public:
    /** @fn void RegRecvCb(const QChatRegRecvSystemNotificationCbParam& param)
     * 注册接收系统消息回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegRecvCb(const QChatRegRecvSystemNotificationCbParam& param);

    /** @fn void RegRecvTypingEvent(const QChatRegRecvTypingEventCbParam& param)
     * 注册接收正在输入事件回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegRecvTypingEvent(const QChatRegRecvTypingEventCbParam& param);

    /** @fn void void RegUpdatedCb(const QChatRegSystemNotificationUpdatedCbParam& param)
     * 注册系统消息更新回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegUpdatedCb(const QChatRegSystemNotificationUpdatedCbParam& param);

    /** @fn void Send(const QChatSendSystemNotificationParam& param)
     * 发送系统消息
     * @param[in] param 接口参数
     * @return void
     */
    static void Send(const QChatSendSystemNotificationParam& param);

    /** @fn void Update(const QChatUpdateSystemNotificationParam& param)
     * @brief 更新系统消息
     * @param[in] param 接口参数
     */
    static void Update(const QChatUpdateSystemNotificationParam& param);

    /** @fn void MarkSystemNotificationsRead(const QChatMarkSystemNotificationsReadParam& param)
     * @brief 标记系统通知消息已读
     * @param param 接口参数
     * @return void
     */
    static void MarkSystemNotificationsRead(const QChatMarkSystemNotificationsReadParam& param);

    /** @fn void SendTypingEvent(const QChatSendTypingEventParam& param)
     * @brief 发送正在输入事件
     * @param param 接口参数
     * @return void
     */
    static void SendTypingEvent(const QChatSendTypingEventParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_SYSMSG_CPP_H__
