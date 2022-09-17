/**
 * @file nim_qchat_attachment_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_ATTACHMENT_CPP_DEF_H__
#define __NIM_QCHAT_ATTACHMENT_CPP_DEF_H__

#include <functional>
#include <list>
#include <map>
#include <string>
#include <vector>
#include "nim_qchat_attachment_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"
#include "nim_wrapper_util/nim_json_util.h"

namespace nim_qchat {
/// @struct QChatAttachmentCustomTokenResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentCustomTokenResp {
    /// 上传后的url
    std::string url{""};
    /// 自定义token
    std::string token{""};
    QChatAttachmentCustomTokenResp() = default;
    QChatAttachmentCustomTokenResp(const NIMQChatAttachmentCustomTokenResp& c_resp) {
        url = c_resp.url ? c_resp.url : "";
        token = "";
    }
    NIMQChatAttachmentCustomTokenResp ToCParam() {
        NIMQChatAttachmentCustomTokenResp c_resp;
        c_resp.url = const_cast<char*>(url.c_str());
        c_resp.token = const_cast<char*>(token.c_str());
        return c_resp;
    }
};

/// @struct QChatAttachmentUploadResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentUploadResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 任务id
    std::string task_id{""};
    /// 上传后的url
    std::string url{""};
    QChatAttachmentUploadResp() = default;
    QChatAttachmentUploadResp(const NIMQChatAttachmentUploadResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        task_id = c_resp.task_id ? c_resp.task_id : "";
        url = c_resp.url ? c_resp.url : "";
    }
};

/// @struct QChatAttachmentDownloadResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentDownloadResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 下载资源类型
    NIMQChatDownloadResType res_type{NIMQChatDownloadResTypeSource};
    /// 任务id, 自动下载的任务则为消息id
    std::string task_id{""};
    /// 下载后的文件路径
    std::string file_path{""};
    QChatAttachmentDownloadResp() = default;
    QChatAttachmentDownloadResp(const NIMQChatAttachmentDownloadResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        res_type = c_resp.res_type;
        task_id = c_resp.task_id ? c_resp.task_id : "";
        file_path = c_resp.file_path ? c_resp.file_path : "";
    }
};

/// @struct QChatAttachmentProgressResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentProgressResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};

    /// 任务id
    std::string task_id{""};
    /// 文件总大小
    uint64_t total_size{0};
    /// 当前已经上传/下载的大小
    uint64_t cur_size{0};
    QChatAttachmentProgressResp() = default;
    QChatAttachmentProgressResp(const NIMQChatAttachmentProgressResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        task_id = c_resp.task_id ? c_resp.task_id : "";
        total_size = c_resp.total_size;
        cur_size = c_resp.cur_size;
    }
};

/// 获取附件自定义token回调
typedef std::function<QChatAttachmentCustomTokenResp(const QChatAttachmentCustomTokenResp&)> AttachmentCustomTokenCallback;
/// 上传附件回调
typedef std::function<void(const QChatAttachmentUploadResp&)> AttachmentUploadCallback;
/// 下载附件回调
typedef std::function<void(const QChatAttachmentDownloadResp&)> AttachmentDownloadCallback;
/// 上传/下载附件进度回调
typedef std::function<void(const QChatAttachmentProgressResp&)> AttachmentProgressCallback;

/// @struct QChatAttachmentRegCustomTokenCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentRegCustomTokenCbParam {
    /// 回调函数
    AttachmentCustomTokenCallback cb{nullptr};
    const NIMQChatAttachmentRegCustomTokenCbParam ToCParam() const {
        static AttachmentCustomTokenCallback cb_holder = nullptr;
        static QChatAttachmentCustomTokenResp resp_holder{};
        cb_holder = cb;
        NIMQChatAttachmentRegCustomTokenCbParam param = {};
        param.cb = [](const NIMQChatAttachmentCustomTokenResp& resp) {
            if (cb_holder)
                resp_holder = cb_holder(resp);
            return resp_holder.ToCParam();
        };
        return param;
    }
};

/// @struct QChatAttachmentRegUploadCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentRegUploadCbParam {
    /// 回调函数
    AttachmentUploadCallback cb{nullptr};
    const NIMQChatAttachmentRegUploadCbParam ToCParam() const {
        static AttachmentUploadCallback cb_holder = nullptr;
        static AttachmentProgressCallback progress_cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatAttachmentRegUploadCbParam param = {};
        param.cb = [](const NIMQChatAttachmentUploadResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatAttachmentRegDownloadCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentRegDownloadCbParam {
    /// 回调函数
    AttachmentDownloadCallback cb{nullptr};
    const NIMQChatAttachmentRegDownloadCbParam ToCParam() const {
        static AttachmentDownloadCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatAttachmentRegDownloadCbParam param = {};
        param.cb = [](const NIMQChatAttachmentDownloadResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatAttachmentRegProgressCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentRegProgressCbParam {
    /// 回调函数
    AttachmentProgressCallback cb{nullptr};
    const NIMQChatAttachmentRegProgressCbParam ToCParam() const {
        static AttachmentProgressCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatAttachmentRegProgressCbParam param = {};
        param.cb = [](const NIMQChatAttachmentProgressResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct UploadAttachementCallbacks
struct UploadAttachementCallbacks {
    AttachmentUploadCallback* completed_cb = nullptr;
    AttachmentProgressCallback* progress_cb = nullptr;
};

/// @struct QChatAttachmentUploadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentUploadParam {
    /// 回调函数
    AttachmentUploadCallback cb{nullptr};
    /// 进度回调
    AttachmentProgressCallback progress_cb{nullptr};
    /// 任务id, 为空时自动生成
    std::string task_id;
    /// 文件路径
    std::string file_path{""};
    const NIMQChatAttachmentUploadParam ToCParam() const {
        auto attachment_cbs = new UploadAttachementCallbacks;
        attachment_cbs->completed_cb = new AttachmentUploadCallback(cb);
        attachment_cbs->progress_cb = new AttachmentProgressCallback(progress_cb);
        NIMQChatAttachmentUploadParam param = {};
        param.user_data = attachment_cbs;
        param.cb = [](const NIMQChatAttachmentUploadResp& resp) {
            auto attachment_cbs = reinterpret_cast<UploadAttachementCallbacks*>(resp.user_data);
            if (attachment_cbs && attachment_cbs->completed_cb)
                (*attachment_cbs->completed_cb)(resp);
            delete attachment_cbs->completed_cb;
            delete attachment_cbs->progress_cb;
            delete attachment_cbs;
        };
        param.progress_cb = [](const NIMQChatAttachmentProgressResp& progress) {
            auto attachment_cbs = reinterpret_cast<UploadAttachementCallbacks*>(progress.user_data);
            if (attachment_cbs && attachment_cbs->progress_cb)
                (*attachment_cbs->progress_cb)(progress);
        };
        param.task_id = const_cast<char*>(task_id.c_str());
        param.file_path = const_cast<char*>(file_path.c_str());
        return param;
    }
};

/// @struct QChatAttachmentStopUploadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentStopUploadParam {
    /// 任务id
    std::string task_id;
    const NIMQChatAttachmentStopUploadParam ToCParam() const {
        NIMQChatAttachmentStopUploadParam param = {};
        param.task_id = const_cast<char*>(task_id.c_str());
        return param;
    }
};

/// @struct DownloadAttachementCallbacks
struct DownloadAttachementCallbacks {
    AttachmentDownloadCallback* completed_cb = nullptr;
    AttachmentProgressCallback* progress_cb = nullptr;
};

/// @struct QChatAttachmentDownloadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentDownloadParam {
    /// 回调函数
    AttachmentDownloadCallback cb{nullptr};
    /// 进度回调
    AttachmentProgressCallback progress_cb{nullptr};
    /// 下载资源类型
    NIMQChatDownloadResType res_type{NIMQChatDownloadResTypeSource};
    /// 任务id, 为空时自动生成
    std::string task_id;
    /// 下载地址
    std::string url{""};
    /// 文件路径
    std::string file_path{""};
    const NIMQChatAttachmentDownloadParam ToCParam() const {
        auto attachment_cbs = new DownloadAttachementCallbacks;
        attachment_cbs->completed_cb = new AttachmentDownloadCallback(cb);
        attachment_cbs->progress_cb = new AttachmentProgressCallback(progress_cb);
        NIMQChatAttachmentDownloadParam param = {};
        param.user_data = attachment_cbs;
        param.cb = [](const NIMQChatAttachmentDownloadResp& resp) {
            auto attachment_cbs = reinterpret_cast<DownloadAttachementCallbacks*>(resp.user_data);
            if (attachment_cbs && attachment_cbs->completed_cb) {
                (*attachment_cbs->completed_cb)(resp);
            }
            delete attachment_cbs->completed_cb;
            delete attachment_cbs->progress_cb;
            delete attachment_cbs;
        };
        param.progress_cb = [](const NIMQChatAttachmentProgressResp& progress) {
            auto attachment_cbs = reinterpret_cast<DownloadAttachementCallbacks*>(progress.user_data);
            if (attachment_cbs && attachment_cbs->progress_cb) {
                (*attachment_cbs->progress_cb)(progress);
            }
        };
        param.res_type = res_type;
        param.task_id = const_cast<char*>(task_id.c_str());
        param.url = const_cast<char*>(url.c_str());
        param.file_path = const_cast<char*>(file_path.c_str());
        return param;
    }
};

/// @struct QChatAttachmentStopDownloadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatAttachmentStopDownloadParam {
    /// 任务id
    std::string task_id;
    const NIMQChatAttachmentStopDownloadParam ToCParam() const {
        NIMQChatAttachmentStopDownloadParam param = {};
        param.task_id = const_cast<char*>(task_id.c_str());
        return param;
    }
};
}  // namespace nim_qchat

#endif  // __NIM_QCHAT_ATTACHMENT_CPP_DEF_H__
