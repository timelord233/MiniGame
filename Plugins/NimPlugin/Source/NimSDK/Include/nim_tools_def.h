/** @file nim_tools_def.h
 * @brief 工具类 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Harrison
 * @date 2015/2/1
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_TOOLS_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_TOOLS_DEF_H_

#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @enum NIMAppDataType AppData类型 */
enum NIMAppDataType {
    /// 其他资源文件（除了消息历史文件和已知类型之外的消息数据缓存文件）
    kNIMAppDataTypeUnknownOtherRes = 0,
    /// 图片消息文件
    kNIMAppDataTypeImage = 1,
    /// 语音消息文件
    kNIMAppDataTypeAudio = 2,
    /// 视频消息文件
    kNIMAppDataTypeVideo = 3,
};

/** @name Trans Audio Msg Info Keys
 * @{
 */
/// string 语音类型
static const char* kNIMTransAudioKeyMime = "mime";
/// string 语音采样率
static const char* kNIMTransAudioKeySample = "samp";
/// string 语音url
static const char* kNIMTransAudioKeyAudioUrl = "url";
/// long 语音时长，毫秒
static const char* kNIMTransAudioKeyDuration = "dur";
/** @}*/  // Trans Audio Msg Info Keys

/** @typedef void (*nim_tool_get_audio_text_cb_func)(const char *text, const char *json_extension, const void *user_data)
 * nim callback function for get audio text
 * @param[out] rescode         转换结果，成功200
 * @param[out] text             语音文字
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_tool_get_audio_text_cb_func)(int rescode, const char* text, const char* json_extension, const void* user_data);

/** @typedef void (*nim_tool_filter_client_antispam_cb_func)(bool succeed, int ret, const char *text,
 *                                                           const char *json_extension, const void *user_data)
 * nim callback function for client antispam
 * @param[out] succeed         本地反垃圾成功
 * @param[out] ret          本地反垃圾结果码，
 * 1：敏感词已被替换，替换后的内容可以发送，2：表明含有敏感词不允许发送；3：表明发送时需要将内容设置在消息结构的反垃圾字段里，由服务器过滤；
 * @param[out] rescode         转换结果，成功200
 * @param[out] text             反垃圾处理后的内容
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_tool_filter_client_antispam_cb_func)(bool succeed, int ret, const char* text, const char* json_extension, const void* user_data);

/** @typedef void (*nim_tool_sdk_log_cb_func)(const char* log_content, const void* user_data)
 * SDK系统日志回调
 * @param[out] log_content      日志内容
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_tool_sdk_log_cb_func)(const char* log_content, const void* user_data);

/** @typedef void (*nim_tool_sdk_collect_log_cb_func)(const char* log_files, const void* user_data)
 * @brief SDK 日志上报时用户层指定的要上报的日志文件回调
 * @param[out] log_files        日志文件列表，json array 格式，每个文件要求绝对路径
 * @param[out] length           数据长度
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 */
typedef void (*nim_tool_sdk_collect_log_cb_func)(char** log_files, uint64_t* length, const void* user_data);

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_TOOLS_DEF_H_
