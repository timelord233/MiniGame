/** @file nim_doc_trans_helper.h
 * @brief 文档传输辅助方法和数据结构定义
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @date 2016/12/15
 */

#ifndef _NIM_SDK_CPP_DOC_TRANS_HELPER_H_
#define _NIM_SDK_CPP_DOC_TRANS_HELPER_H_

#include <functional>
#include <list>
#include <string>
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"
#include "nim_define_include.h"
#include "nim_wrapper_util/nim_json_util.h"
/**
 * @namespace nim
 * @brief namespace nim
 */
namespace nim {
/** @brief 文档传输的图片信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API PictureInfo {
    /// 转码图像清晰度
    NIMDocTranscodingQuality quality_;
    /// 图片宽度
    int width_;
    /// 图片宽度
    int height_;
    /// 文件大小
    int64_t size_;
    PictureInfo()
        : quality_(kNIMDocTranscodingQualityHigh)
        , width_(0)
        , height_(0)
        , size_(0) {}
};

/** @brief 文档传输信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API DocTransInfo {
    /// 标识ID
    std::string id_;
    /// 转码文档名称
    std::string name_;
    /// 转码源文档的文件类型
    NIMDocTranscodingFileType source_type_;
    /// 文件大小
    int64_t size_;
    /// 转码目标图片的文件类型
    NIMDocTranscodingImageType pic_type_;
    /// 转码过程状态
    NIMDocTranscodingState state_;
    /// 转码后的下载地址前缀
    std::string url_prefix_;
    /// 转码文档总页数
    int page_num_;
    /// 发起文档转码时的附带信息
    std::string ext_;
    /// 图片信息的key
    std::list<PictureInfo> pic_info_;

    /// 客户端本地扩展:上传文件路径
    std::string upload_file_path;
    /// 客户端本地扩展:续传文件状态
    NIMDocContinueUploadState continue_upload_state_;
    DocTransInfo()
        : source_type_(kNIMDocTranscodingFileTypePPT)
        , size_(0)
        , pic_type_(kNIMDocTranscodingImageTypeJPG)
        , state_(kNIMDocTranscodingStatePreparing)
        , page_num_(0)
        , continue_upload_state_(kNIMDocContinueUploadNone) {}
};

/** @fn bool ParseDocTransInfo(const std::string& json, DocTransInfo& info)
 * @brief 解析文档传输信息
 * @param[in] json 文档传输信息(Json Value数据字符串)
 * @param[out] infos 文档传输信息
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseDocTransInfo(const std::string& json, DocTransInfo& info);

/** @fn int32_t ParseDocTransInfos(const std::string& json, std::list<DocTransInfo>& infos)
 * @brief 解析一组文档传输信息
 * @param[in] json 文档传输信息(Json Value数据字符串)
 * @param[out] infos 文档传输信息
 * @return int32_t 服务器总条数
 */
NIM_SDK_CPPWRAPPER_DLL_API int32_t ParseDocTransInfos(const std::string& json, std::list<DocTransInfo>& info_list);

}  // namespace nim

#endif  //_NIM_SDK_CPP_DOC_TRANS_HELPER_H_
