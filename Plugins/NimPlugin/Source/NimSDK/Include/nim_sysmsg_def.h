/** @file nim_sysmsg_def.h
 * @brief 系统（自定义）消息 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg
 * @date 2015/2/1
 */
#ifndef NIM_SDK_DLL_EXPORT_HEADERS_SYSMSG_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_SYSMSG_DEF_H_

#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif
/** @typedef void (*nim_custom_sysmsg_ack_cb_func)(const char *result, const void *user_data)
 * 透传系统消息回执的回调函数定义
 * @param[out] result json string (Keys SEE MORE 『发送透传的系统消息回执Json Keys』 as follows)
 * @param[out] user_data    APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_custom_sysmsg_ack_cb_func)(const char* result, const void* user_data);

/** @typedef void (*nim_sysmsg_receive_cb_func)(const char *content, const char *json_extension, const void *user_data)
 * 接收系统消息的回调函数定义
 * @param[out] content            json string (Keys SEE MORE 『接收系统消息Json Keys』 as follows)
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_sysmsg_receive_cb_func)(const char* content, const char* json_extension, const void* user_data);

/** @typedef void (*nim_sysmsg_query_cb_func)(int count, const char *result, const char *json_extension, const void *user_data)
 * 查询系统消息的回调函数定义
 * @param[out] count            查询结果的实际数量
 * @param[out] result            查询结果json object array string SEE MORE 『查询系统消息历史结果Json Keys』
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_sysmsg_query_cb_func)(int count, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_sysmsg_res_cb_func)(int res_code, int unread_count, const char *json_extension, const void *user_data)
 * 系统消息历史操作结果的回调函数定义
 * @param[out] res_code        操作结果，成功200
 * @param[out] unread_count    总的未读数
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_sysmsg_res_cb_func)(int res_code, int unread_count, const char* json_extension, const void* user_data);

/** @typedef void (*nim_sysmsg_res_ex_cb_func)(int res_code, int64_t msg_id, int unread_count, const char *json_extension, const void *user_data)
 * 系统消息历史操作结果的回调函数定义
 * @param[out] res_code    操作结果，成功200
 * @param[out] msg_id        消息id
 * @param[out] unread_count    总的未读数
 * @param[out] json_extension json扩展数据（备用）
 * @param[out] user_data    APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_sysmsg_res_ex_cb_func)(int res_code, int64_t msg_id, int unread_count, const char* json_extension, const void* user_data);

/** @name 查询系统消息历史结果Json Keys
 * for example:
 * {"count": 20,
 *  "unread_count": 20,
 *  "content":[***]
 * }
 * @{
 */
/// int, 查询得到的数量
static const char* kNIMSysMsglogQueryKeyCount = "count";
/// int, 每次查询带回的是当前的总的未读数
static const char* kNIMSysMsglogQueryKeyUnreadCount = "unread_count";
/// json object array 协议定义的系统消息结构
static const char* kNIMSysMsglogQueryKeyContent = "content";
/** @}*/  // 查询系统消息历史结果Json Keys

/** @name 发送透传的系统消息回执Json Keys
 * for example:
 * {"msg_id": "123456",
 *  "talk_id": "abc",
 *  "rescode":200
 * }
 * @{
 */
/// string, 本地定义的消息id,返回的是发送方发送时填写的id
static const char* kNIMSendSysMsgAckKeyMsgId = "msg_id";
/// string, 会话id,消息接收者id
static const char* kNIMSendSysMsgAckKeyTalkId = "talk_id";
/// int, 返回的错误码，见NIMResCode
static const char* kNIMSendSysMsgAckKeyRescode = "rescode";
/** @}*/  // 发送透传的系统消息回执Json Keys

/** @name 接收系统消息Json Keys，本地定义
 * for example:
 * {"rescode": 200
 *  "feature": 1,
 *  "unread_count": 20,
 *  "content": "***",
 * }
 * @{
 */
/// int, 返回的错误码,见NIMResCode
static const char* kNIMSysMsgKeyLocalRescode = "rescode";
/// int, 本地定义的消息特征,见NIMMessageFeature
static const char* kNIMSysMsgKeyLocalFeature = "feature";
/// int, 每次带回的是当前的总的未读数
static const char* kNIMSysMsgKeyLocalUnreadCount = "unread_count";
/// json string, 协议定义的系统消息结构
static const char* kNIMSysMsgKeyLocalContent = "content";
/** @}*/  // 接收系统消息Json Keys，本地定义

/** @name 系统消息/客户端自定义通知结构 Json Keys，协议定义
 * @{
 */
/// long 时间戳,选填
static const char* kNIMSysMsgKeyTime = "msg_time";
/// int 通知类型,NIMSysMsgType,必填
static const char* kNIMSysMsgKeyType = "msg_type";
/// string 接收者id,如果是个人,则是对方用户id,如果是群,则是群id,必填
static const char* kNIMSysMsgKeyToAccount = "to_account";
/// string 自己id,选填
static const char* kNIMSysMsgKeyFromAccount = "from_account";
/// string 只读字段，SDK不转发该字段
static const char* kNIMSysMsgKeyMsg = "msg";
/// string 消息内容,规定是可以解析为Json格式的字符串，必须为非格式化形式
static const char* kNIMSysMsgKeyAttach = "attach";
/// long 服务器消息id（自定义通知消息,必须填0）,发送方不需要填写
static const char* kNIMSysMsgKeyMsgId = "msg_id";
/// int 本地定义的系统消息状态,见NIMSysMsgStatus,发送方不需要填写
static const char* kNIMSysMsgKeyLocalStatus = "log_status";
/// string 本地定义的消息id,发送方必填,建议使用uuid
static const char* kNIMSysMsgKeyLocalClientMsgId = "client_msg_id";
/// int (可选)自定义通知消息是否存离线:0-不存（只发给在线用户）,1-存（可发给离线用户）
static const char* kNIMSysMsgKeyCustomSaveFlag = "custom_save_flag";
/// string (可选)自定义通知消息推送文本，不填则不推送
static const char* kNIMSysMsgKeyCustomApnsText = "custom_apns_text";
/// json string, (可选)第三方自定义的推送属性，必须为可以解析为Json的非格式化的字符串，长度2048
static const char* kNIMSysMsgKeyPushPayload = "push_payload";
/// int (可选)是否需要推送, 0:不需要,1:需要,默认1
static const char* kNIMSysMsgKeyPushEnable = "push_enable";
/// int (可选)推送是否要做消息计数(角标)，0:不需要，1:需要，默认1
static const char* kNIMSysMsgKeyPushNeedBadge = "push_need_badge";
/// int (可选)推送需要前缀，0：不需要，1：需要，默认0
static const char* kNIMSysMsgKeyPushNeedPrefix = "push_prefix";
/// int, (功能暂时不开放)是否需要过易盾反垃圾, 0:不需要,1:需要, 默认0
static const char* kNIMSysMsgKeyAntiSpamEnable = "anti_spam_enable";
/// string, (功能暂时不开放)(可选)开发者自定义的反垃圾字段
static const char* kNIMSysMsgKeyAntiSpamContent = "anti_spam_content";
/// string, (可选) 指向自定义抄送的配置
static const char* kNIMSysMsgKeyEnvConfig = "env_config";
/// string, (可选) 第三方回调返回的自定义字段
static const char* kNIMSysMsgKeyCallbackExt = "callback_ext";

/** @}*/  // 接收系统消息Json Keys，协议定义

/** @enum NIMSysMsgStatus 系统消息状态 */
enum NIMSysMsgStatus {
    /// 默认,未读
    kNIMSysMsgStatusNone = 0,
    /// 收到消息,通过
    kNIMSysMsgStatusPass = 1,
    /// 收到消息,拒绝
    kNIMSysMsgStatusDecline = 2,
    /// 收到消息,已读
    kNIMSysMsgStatusRead = 3,
    /// 已删
    kNIMSysMsgStatusDeleted = 4,
    /// 已失效
    kNIMSysMsgStatusInvalid = 5,
};

/** @enum NIMSysMsgType 系统消息内容类型 */
enum NIMSysMsgType {
    /// 申请入群
    kNIMSysMsgTypeTeamApply = 0,
    /// 拒绝入群申请
    kNIMSysMsgTypeTeamReject = 1,
    /// 邀请进群
    kNIMSysMsgTypeTeamInvite = 2,
    /// 拒绝邀请
    kNIMSysMsgTypeTeamInviteReject = 3,
    /// 加好友, kNIMSysMsgKeyAttach: {"vt":verifyType}
    kNIMSysMsgTypeFriendAdd = 5,
    /// 删除好友
    kNIMSysMsgTypeFriendDel = 6,
    /// 点对点透传消息（透传消息的内容放到kNIMSysMsgKeyAttach）,SDK对该类消息不计入未读数, 即使kNIMSysMsgKeyPushNeedBadge为1
    kNIMSysMsgTypeCustomP2PMsg = 100,
    /// 群透传消息（透传消息的内容放到kNIMSysMsgKeyAttach）,SDK对该类消息不计入未读数, 即使kNIMSysMsgKeyPushNeedBadge为1
    kNIMSysMsgTypeCustomTeamMsg = 101,
    /// 超大群透传消息（透传消息的内容放到kNIMSysMsgKeyAttach）,SDK对该类消息不计入未读数, 即使kNIMSysMsgKeyPushNeedBadge为1
    kNIMSysMsgTypeCustomSuperTeamMsg = 103,
    /// 未知类型，本地使用，发送时勿使用，作为默认
    kNIMSysMsgTypeUnknown = 1000,
};

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_SYSMSG_DEF_H_
