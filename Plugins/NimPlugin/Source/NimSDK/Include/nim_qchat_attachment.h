/**
 * @file nim_qchat_attachment.h
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

#include "nim_qchat_defines/nim_qchat_attachment_def.h"
#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @fn void nim_qchat_attachment_reg_custom_token_cb(const NIMQChatAttachmentRegCustomTokenCbParam& param)
 * @brief 注册附件上传下载自定义token获取回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_reg_custom_token_cb(const NIMQChatAttachmentRegCustomTokenCbParam& param);

/** @fn void nim_qchat_attachment_reg_upload_cb(const NIMQChatAttachmentRegUploadCbParam& param)
 * @brief 注册上传全局回调，例如发送多媒体消息自动上传时会触发此回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_reg_upload_cb(const NIMQChatAttachmentRegUploadCbParam& param);

/** @fn void nim_qchat_attachment_reg_download_cb(const NIMQChatAttachmentRegDownloadCbParam& param)
 * @brief 注册下载全局回调，例如接收多媒体消息自动下载时会触发此回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_reg_download_cb(const NIMQChatAttachmentRegDownloadCbParam& param);

/** @fn void nim_qchat_attachment_reg_progress_cb(const NIMQChatAttachmentRegProgressCbParam& param)
 * @brief 注册上传/下载全局进度回调，例如多媒体消息自动上传/下载时会触发此回调
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_reg_progress_cb(const NIMQChatAttachmentRegProgressCbParam& param);

/** @fn void nim_qchat_attachment_upload(const NIMQChatAttachmentUploadParam& param)
 * @brief 附件上传
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_upload(const NIMQChatAttachmentUploadParam& param);

/** @fn void nim_qchat_attachment_stop_upload(const NIMQChatAttachmentStopUploadParam& param)
 * @brief 停止附件上传
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_stop_upload(const NIMQChatAttachmentStopUploadParam& param);

/** @fn void nim_qchat_attachment_download(const NIMQChatAttachmentDownloadParam& param)
 * @brief 附件下载
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_download(const NIMQChatAttachmentDownloadParam& param);

/** @fn void nim_qchat_attachment_stop_download(const NIMQChatAttachmentStopDownloadParam& param)
 * @brief 停止附件下载
 * @param[in] param 接口参数
 * @return void
 */
NIM_SDK_DLL_API void nim_qchat_attachment_stop_download(const NIMQChatAttachmentStopDownloadParam& param);
#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_SYSMSG_H__