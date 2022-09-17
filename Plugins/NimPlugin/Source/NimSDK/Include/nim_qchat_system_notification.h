/**
 * @file nim_qchat_system_notification.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SYSMSG_H__
#define __NIM_QCHAT_SYSMSG_H__

#include "nim_qchat_defines/nim_qchat_system_notification_def.h"
#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @fn void nim_qchat_reg_recv_system_notification_cb(const NIMQChatRegRecvSystemNotificationCbParam& param)
 * @brief 注册接收系统通知回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_recv_system_notification_cb(const NIMQChatRegRecvSystemNotificationCbParam& param);

/** @fn void nim_qchat_reg_recv_typing_event_cb(const NIMQChatRegRecvTypingEventCbParam& param)
 * @brief 注册接收正在输入事件回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_recv_typing_event_cb(const NIMQChatRegRecvTypingEventCbParam& param);

/** @fn void nim_qchat_reg_system_notification_updated_cb(const NIMQChatRegSystemNotificationUpdatedCbParam& param)
 * @brief 注册系统通知更新回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_system_notification_updated_cb(const NIMQChatRegSystemNotificationUpdatedCbParam& param);

/** @fn void nim_qchat_send_system_notification(const NIMQChatSendSystemNotificationParam& param)
 * @brief 发送圈组自定义系统通知
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_send_system_notification(const NIMQChatSendSystemNotificationParam& param);

/** @fn void nim_qchat_update_system_notification(const NIMQChatUpdateSystemNotificationParam& param)
 * @brief 更新系统消息
 * @param param 更新的系统消息内容
 * @param attachment 更新消息得附加信息
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_update_system_notification(const NIMQChatUpdateSystemNotificationParam& param);

/** @fn void nim_qchat_mark_system_notifications_read(const NIMQChatMarkSystemNotificationsReadParam& param)
 * @brief 标记一条系统通知消息已读
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_mark_system_notifications_read(const NIMQChatMarkSystemNotificationsReadParam& param);

/** @fn void nim_qchat_send_typing_event(const NIMQChatSendTypingEventParam& param)
 * @brief 发送正在输入事件
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_send_typing_event(const NIMQChatSendTypingEventParam& param);

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_SYSMSG_H__
