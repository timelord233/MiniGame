/**
 * @file nim_qchat_public_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_PUBLIC_CPP_DEF_H__
#define __NIM_QCHAT_PUBLIC_CPP_DEF_H__

#include <functional>
#include <list>
#include <map>
#include <string>
#include <vector>
#include "nim_qchat_cpp_wrapper/nim_qchat_sdk_cpp_wrapper.h"
#include "nim_qchat_public_def.h"
#include "nim_wrapper_util/nim_json_util.h"

namespace nim_qchat {
static const char* kNIMQChatWidth = "w";
static const char* kNIMQChatHeight = "h";
static const char* kNIMQChatDuration = "dur";
static const char* kNIMQChatLatitude = "lat";
static const char* kNIMQChatLongitude = "lng";
static const char* kNIMQChatTitle = "title";
static const char* kNIMQChatFilePath = "file_path";
static const char* kNIMQChatURL = "url";
static const char* kNIMQChatMD5 = "md5";
static const char* kNIMQChatName = "name";
static const char* kNIMQChatExt = "ext";
static const char* kNIMQChatID = "id";
static const char* kNIMQChatType = "type";
static const char* kNIMQChatData = "data";

/// @struct QChatBaseResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatBaseResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code = 0;
    QChatBaseResp() = default;
    QChatBaseResp(const NIMQChatBaseResp& c_resp) { res_code = c_resp.res_code; }
    const NIMQChatBaseResp ToCParam() const {
        NIMQChatBaseResp c_response{};
        c_response.res_code = res_code;
        return c_response;
    }
};

/// @struct QChatBusinessAntiSpamInfo
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatBusinessAntiSpamInfo {
    /// 反垃圾文本业务id
    std::string text_bid;
    /// 反垃圾图片业务id
    std::string pic_bid;
    QChatBusinessAntiSpamInfo() = default;
    QChatBusinessAntiSpamInfo(const NIMQChatBusinessAntiSpamInfo& c_info) {
        text_bid = c_info.text_bid;
        pic_bid = c_info.pic_bid;
    }
    const NIMQChatBusinessAntiSpamInfo ToCParam() const {
        NIMQChatBusinessAntiSpamInfo c_info{};
        c_info.text_bid = const_cast<char*>(text_bid.c_str());
        c_info.pic_bid = const_cast<char*>(pic_bid.c_str());
        return c_info;
    }
};

/// @struct QChatPageInfo 圈组分页查询信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatPageInfo {
    /// 是否还有更多
    bool has_more;
    /// 下一次分页起始时间
    uint64_t next_timestamp;
    /// 下一次分页起始游标
    std::string cursor;
    QChatPageInfo() = default;
    QChatPageInfo(const NIMQChatPageInfo& c_info) {
        has_more = c_info.has_more;
        next_timestamp = c_info.next_timestamp;
        cursor = c_info.cursor ? c_info.cursor : "";
    }
    const NIMQChatPageInfo ToCParam() const {
        NIMQChatPageInfo c_info{};
        c_info.has_more = has_more;
        c_info.next_timestamp = next_timestamp;
        c_info.cursor = const_cast<char*>(cursor.c_str());
        return c_info;
    }
};

/// 通用回调模板
typedef std::function<void(const QChatBaseResp&)> QChatBaseCallback;

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_PUBLIC_CPP_DEF_H__
