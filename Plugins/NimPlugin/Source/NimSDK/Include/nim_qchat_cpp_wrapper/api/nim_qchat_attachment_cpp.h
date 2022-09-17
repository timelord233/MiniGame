/**
 * @file nim_qchat_attachment_cpp.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2021, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_ATTACHMENT_CPP_H__
#define __NIM_QCHAT_ATTACHMENT_CPP_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_attachment_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_helper.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"
/**
 * @namespace nim_qchat
 * @brief 圈组
 */
namespace nim_qchat {

/** @class Attachment
 * @brief 圈组附件能力
 */
class NIM_QCHAT_SDK_CPPWRAPPER_DLL_API Attachment {
public:
    /** @fn void void RegCustomTokenCb(const QChatAttachmentRegCustomTokenCbParam& param)
     * 注册自定义token回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegCustomTokenCb(const QChatAttachmentRegCustomTokenCbParam& param);

    /**
     * @fn void void RegUploadCb(const QChatAttachmentRegUploadCbParam& param);
     * 注册上传全局回调，例如发送多媒体消息自动上传时会触发此回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegUploadCb(const QChatAttachmentRegUploadCbParam& param);

    /** @fn void void RegDownloadCb(const QChatAttachmentRegDownloadCbParam& param);
     * 注册下载全局回调，例如接收多媒体消息自动下载时会触发此回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegDownloadCb(const QChatAttachmentRegDownloadCbParam& param);

    /** @fn void RegProgressCb(const QChatAttachmentRegProgressCbParam& param);
     * 注册上传/下载全局进度回调，例如多媒体消息自动上传/下载时会触发此回调
     * @param[in] param 接口参数
     * @return void
     */
    static void RegProgressCb(const QChatAttachmentRegProgressCbParam& param);

    /** @fn void Upload(const QChatAttachmentUploadParam& param)
     * 上传附件
     * @param[in] param 接口参数
     * @return void
     */
    static void Upload(const QChatAttachmentUploadParam& param);

    /** @fn void StopUpload(const std::string& task_id)
     * 停止上传附件
     * @param[in] param 接口参数
     * @return void
     */
    static void StopUpload(const QChatAttachmentStopUploadParam& param);

    /** @fn void Download(const QChatAttachmentDownloadParam& param)
     * 下载附件
     * @param[in] param 接口参数
     * @return void
     */
    static void Download(const QChatAttachmentDownloadParam& param);

    /** @fn void StopDownload(const QChatAttachmentStopDownloadParam& param)
     * 停止下载附件
     * @param[in] param 接口参数
     * @return void
     */
    static void StopDownload(const QChatAttachmentStopDownloadParam& param);
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_ATTACHMENT_CPP_H__