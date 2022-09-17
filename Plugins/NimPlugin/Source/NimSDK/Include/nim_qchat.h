/** @file nim_qchat.h
 * @brief 圈组 接口头文件，在需要使用圈组 SDK 的地方包含该头文件即可
 * @copyright Copyright (c) 2021, NetEase Inc. All rights reserved
 * @author Zvicii
 * @date 2021/12/27
 */
#ifndef __NIM_QCHAT_NIM_QCHAT_H__
#define __NIM_QCHAT_NIM_QCHAT_H__

#include "nim_qchat_defines/nim_qchat_client_def.h"
#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_qchat_reg_custom_token_cb(const NIMQChatRegCustomTokenCbParam& param)
 * @brief 注册自定义token获取回调，用于登录类型不为静态token时，获取token
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_custom_token_cb(const NIMQChatRegCustomTokenCbParam& param);

/** @fn void nim_qchat_reg_kicked_out_cb(const NIMQChatRegKickedCbParam& param)
 * @brief 注册被踢回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_kicked_out_cb(const NIMQChatRegKickedCbParam& param);

/** @fn void nim_qchat_reg_login_status_cb(const NIMQChatRegLoginStatusCbParam& param)
 * @brief 注册登录状态回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_login_status_cb(const NIMQChatRegLoginStatusCbParam& param);

/** @fn void nim_qchat_reg_multispot_login_cb(const NIMQChatRegMultispotLoginCbParam& param)
 * @brief 注册多端登录通知回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_reg_multispot_login_cb(const NIMQChatRegMultispotLoginCbParam& param);

/** @fn void nim_qchat_reg_sdk_log_cb(const NIMQChatRegSDKLogCbParam& param)
 * SDK系统日志回调，可用于动态获取日志，不建议用于生产环境
 * @param[in] cb 回调
 * @param[in] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
NIM_SDK_DLL_API void nim_qchat_reg_sdk_log_cb(const NIMQChatRegSDKLogCbParam& param);

/** @fn void nim_qchat_init(const NIMQChatInitParam& param)
 * @brief 圈组模块初始化(SDK初始化时调用一次)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_init(const NIMQChatInitParam& param);

/** @fn void nim_qchat_cleanup(const NIMQChatCleanupParam& param)
 * @brief 圈组模块清理(卸载SDK时调用一次)
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_cleanup(const NIMQChatCleanupParam& param);

/** @fn void nim_qchat_login(const NIMQChatLoginParam& param)
 * @brief 登录圈组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_login(const NIMQChatLoginParam& param);

/** @fn void nim_qchat_logout(const NIMQChatLogoutParam& param)
 * @brief 登出圈组
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_logout(const NIMQChatLogoutParam& param);

/** @fn void nim_qchat_kick_other_clients(const NIMQChatKickParam& param)
 * @brief 踢掉自己其他端
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_kick_other_clients(const NIMQChatKickParam& param);

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_H__
