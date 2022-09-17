/**
 * @file nim_qchat_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-15
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_NIM_QCHAT_CPP_H__
#define __NIM_QCHAT_NIM_QCHAT_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_client_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"

/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {
/** @class QChat
 * @brief 圈组客户端接口
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChat {
public:
    /** @fn void RegCustomTokenCb(const QChatRegCustomTokenCbParam& param)
     * 注册自定义token回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegCustomTokenCb(const QChatRegCustomTokenCbParam& param);

    /** @fn void RegKickedOutCb(const QChatRegKickedCbParam& param)
     * 注册被踢回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegKickedOutCb(const QChatRegKickedCbParam& param);

    /** @fn void RegLoginStatusCb(const QChatRegLoginStatusCbParam& param)
     * 注册登录状态回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegLoginStatusCb(const QChatRegLoginStatusCbParam& param);

    /** @fn void RegMultispotLoginCb(const QChatRegMultispotLoginCbParam& param)
     * 注册多端登录通知回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegMultispotLoginCb(const QChatRegMultispotLoginCbParam& param);

    /** @fn static void RegSDKLogCb(const SDKLogCallback& callback)
     * SDK系统日志回调，可用于动态获取日志，不建议用于生产环境
     * @param[in] callback 回调函数
     * @return
     */
    static void RegSDKLogCb(const SDKLogCallback& callback);

    /** @fn bool Init(const QChatInitParam& param)
     * 圈组模块初始化(SDK初始化时调用一次)
     * @param[in] param 接口参数
     * @return bool 模块加载结果
     */
    static bool Init(const QChatInitParam& param);

    /** @fn bool Cleanup(const QChatCleanupParam& param)
     * 圈组模块清理(卸载SDK时调用一次)
     * @param[in] param 接口参数
     * @return bool 模块清理结果
     */
    static bool Cleanup(const QChatCleanupParam& param);

    /** @fn void Login(const QChatLoginParam& param)
     * 登录圈组
     * @param[in] param 接口参数
     * @return void
     */
    static void Login(const QChatLoginParam& param);

    /** @fn void Logout(const QChatLogoutParam& param)
     * 登出圈组
     * @param[in] param 接口参数
     * @return void
     */
    static void Logout(const QChatLogoutParam& param);

    /** @fn void KickOtherClients(const QChatKickParam& param)
     * 踢掉自己指定的一个其他端
     * @param[in] param 接口参数
     * @return void
     */
    static void KickOtherClients(const QChatKickParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_CPP_H__
