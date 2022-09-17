/** @file nim_chatroom_def.h
 * @brief 聊天室 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @author Oleg, Harrison
 * @date 2015/12/24
 */
#ifndef NIM_CHATROOM_NIM_CHATROOM_DEFINES_NIM_CHATROOM_DEF_H_
#define NIM_CHATROOM_NIM_CHATROOM_DEFINES_NIM_CHATROOM_DEF_H_

#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _tagNIMChatRoomLocation {
    /// 位置信息 x 坐标
    float x_;
    /// 位置信息 y 坐标
    float y_;
    /// 位置信息 z 坐标
    float z_;
    /// 距离信息，仅在更新位置信息时会用到，发送消息、加入房间不需要填写
    float distance_;
} NIMChatRoomLocation;

typedef struct _tagNIMChatRoomUpdateTagsInfo {
    /// 标签，可以设置多个，json_array格式，例子：["tag1", "tag2"]
    char* tags_;
    /// 更新标签的通知的目标标签，是一个标签表达式
    char* notify_target_tags_;
    /// 1表示需要通知，如果需要通知，则会产生一条通知，新增NotifyEventId=325
    int need_notify_;
    /// 通知扩展字段
    char* ext_;
} NIMChatRoomUpdateTagsInfo;

/** @typedef void (*nim_chatroom_enter_cb_func)(int64_t room_id, int enter_step, int error_code, const char *result, const void *user_data)
 * 进入的回调函数定义
 * @param[out] room_id        聊天室ID
 * @param[out] enter_step    进入聊天室的过程(NIMChatRoomEnterStep)
 * @param[out] error_code
 * 错误码(关注但不仅限200,408,415,10001,13001,13002,13003,如果错误码为10001，聊天室重连机制结束，则需要向IM服务器重新请求进入该聊天室权限)
 * @param[out] result        聊天室信息
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data    APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_enter_cb_func)(int64_t room_id,
    int enter_step,
    int error_code,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_chatroom_exit_cb_func)(int64_t room_id, int error_code, int exit_type, const char *json_extension, const void *user_data)
 * 退出、被踢的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] exit_type        退出原因(ChatRoomExitReason)
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data    APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_exit_cb_func)(int64_t room_id, int error_code, int exit_type, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_link_condition_cb_func)(int64_t room_id, int condition, const void *user_data)
 * 聊天室链接状况的回调函数定义
 * @param[out] room_id        聊天室ID
 * @param[out] condition    网络状况
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data    APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_link_condition_cb_func)(int64_t room_id, int condition, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_sendmsg_arc_cb_func)(int64_t room_id, int error_code, const char *result, const void *user_data)
 * 发送消息回执的回调函数定义
 * @param[out] room_id        聊天室ID
 * @param[out] error_code    错误码(关注但不仅限200,408,416,13004,13006)
 * @param[out] result        json string
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data    APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_chatroom_sendmsg_arc_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_receive_msg_cb_func)(int64_t room_id, const char *result, const char *json_extension, const void *user_data)
 * 接收消息的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] result            json string, json key定义见 消息结构 Json Keys
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_receive_msg_cb_func)(int64_t room_id, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_receive_notification_cb_func)(int64_t room_id, const char *result, const char *json_extension, const void *user_data)
 * 聊天室通知的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] result            json string, json key定义见 聊天室通知Keys
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_receive_notification_cb_func)(int64_t room_id, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_get_members_cb_func)(int64_t room_id, int error_code, const char *result, const char *json_extension,
                                                      const void *user_data)
 * 获取指定/分页获取成员列表的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            json string , json key定义见 聊天室个人Info Json Keys
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_chatroom_get_members_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_get_msg_cb_func)(int64_t room_id, int error_code, const char *result,
                                                  const char *json_extension, const void *user_data)
 * 获取历史消息的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            json string , json key定义见 消息结构 Json Keys
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_get_msg_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_set_member_attribute_cb_func)(int64_t room_id, int error_code, const char *result,
                                                               const char *json_extension, const void *user_data)
 * 设定聊天室成员标记身份的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            json string
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_set_member_attribute_cb_func)(int64_t room_id,
    int error_code,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_chatroom_get_info_cb_func)(int64_t room_id, int error_code, const char *result,
 *                                                 const char *json_extension, const void *user_data)
 * 获取当前聊天室信息的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            member info json string , json key定义见 聊天室Info Json Keys
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_get_info_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_kick_member_cb_func)(int64_t room_id, int error_code, const char *json_extension, const void *user_data)
 * 踢掉指定成员的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_kick_member_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_temp_mute_member_cb_func)(int64_t room_id, int error_code, const char *result,
                                                          const char *json_extension, const void  *user_data)
 * 临时禁言指定成员的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            member info json string
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_chatroom_temp_mute_member_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_query_members_count_by_tag_cb_func)(int64_t room_id,
                                                                     int error_code,
                                                                     uint64_t count,
                                                                     const char *json_extension,
                                                                     const void *user_data)
 * 查询指定 tag 在聊天室的成员数量回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] count            指定 tag 的成员数量
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_query_members_count_by_tag_cb_func)(int64_t room_id,
    int error_code,
    uint64_t count,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_chatroom_temp_mute_member_by_tag_cb_func)(int64_t room_id, int error_code, const char *result,
                                                                  const char *json_extension, const void *user_data)
 * 临时禁言指定 tag 下的成员回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            member info json string
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_temp_mute_member_by_tag_cb_func)(int64_t room_id,
    int error_code,
    const char* result,
    const char* json_extension,
    const void* user_data);

/** @typedef void (*nim_chatroom_update_room_info_cb_func)(int64_t room_id, int error_code, const char *json_extension, const void *user_data)
 * 更新聊天室信息的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_update_room_info_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_update_my_role_cb_func)(int64_t room_id, int error_code, const char *json_extension, const void *user_data)
 * 更新我的信息的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_update_my_role_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_queue_offer_cb_func)(int64_t room_id, int error_code, const char *json_extension, const void *user_data)
 * 新加(更新)队列元素的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_queue_offer_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_queue_poll_cb_func)(int64_t room_id, int error_code, const char *result,
 *                                                   const char *json_extension, const void *user_data)
 * 取出元素的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            json object string (聊天室麦序队列元素Keys)
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_chatroom_queue_poll_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_queue_list_cb_func)(int64_t room_id, int error_code, const char *result, const char *json_extension,
                                                     const void *user_data)
 * 排序列出所有元素的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            json array string (聊天室麦序队列元素Keys)
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_chatroom_queue_list_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_queue_header_cb_func)(int64_t room_id, int error_code, const char *result, const char *json_extension,
                                                      const void *user_data)
 * 查看头元素的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            json object string (聊天室麦序队列元素Keys)
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (
    *nim_chatroom_queue_header_cb_func)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_queue_drop_cb_func)(int64_t room_id, int error_code, const char *json_extension, const void *user_data)
 * 删除麦序队列的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_queue_drop_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_queue_init_cb_func)(int64_t room_id, int error_code, const char *json_extension, const void *user_data)
 * 麦序队列初始化的回调函数定义
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_queue_init_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_query_robots_cb_func)(int rescode, const char *result, const char *json_extension, const void *user_data)
 * 获取机器人信息的函数定义
 * @param[out] rescode            错误码,200:一切正常
 * @param[out] result            机器人信息 Json string array
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_query_robots_cb_func)(int rescode, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_batch_update_cb)(int room_id, const char *result, const char *json_extension, const void *user_data)
 * 批量更新成员列表信息函数
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] result            不存在的元素列表 Json string array
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_batch_update_cb)(int64_t room_id, int error_code, const char* result, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_update_location_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data)
 * 更新聊天室位置信息回调函数
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_update_location_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_custom_token_cb_func)(char*& auth_token, uint32_t* length, const char* json_params, const void* user_data)
 * 登录时 auth type 不为 0 时触发断线重连的回调函数，在此回调中填充auth_token
 * @param[in] auth_token 新的 auth token
 * @param[in] length token缓冲区的长度
 * @param[out] json_params 输出的json字符串内容
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_custom_token_cb_func)(char* auth_token, const uint32_t length, const char* json_params, const void* user_data);

/** @typedef void (*nim_chatroom_update_tags_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data)
 * 更新聊天室标签回调函数
 * @param[out] room_id            聊天室ID
 * @param[out] error_code        错误码
 * @param[out] json_extension    json扩展数据（备用）
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_update_tags_cb_func)(int64_t room_id, int error_code, const char* json_extension, const void* user_data);

/** @typedef void (*nim_chatroom_sdk_log_cb_func)(const char* log_content, const void* user_data)
 * SDK系统日志回调
 * @param[out] log_content      日志内容
 * @param[out] user_data        APP的自定义用户数据，SDK只负责传回给回调函数，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_chatroom_sdk_log_cb_func)(const char* log_content, const void* user_data);

/** @name 进入聊天室的可选填信息Json Keys
 * @{
 */
/// string, （匿名登录时必填）进入聊天室后展示的昵称,选填,聊天室成员收到聊天室进入通知中可以获取该数据
static const char* kNIMChatRoomEnterKeyNick = "nick";
/// string, （匿名登录时必填）设置后通过获取聊天室成员信息接口可以获取该数据
static const char* kNIMChatRoomEnterKeyAvatar = "avatar";
/// string, 聊天室可用的扩展字段,必须为可以解析为Json的非格式化的字符串,选填,设置后通过获取聊天室成员信息接口可以获取该数据
static const char* kNIMChatRoomEnterKeyExt = "ext";
/// string, 进入聊天室通知开发者扩展字段,必须为可以解析为Json的非格式化的字符串,选填,聊天室成员收到聊天室进入通知中可以获取该数据
static const char* kNIMChatRoomEnterKeyNotifyExt = "notify_ext";
/// string array 登录标签，可以设置多个，json array 格式，例子：["tag1", "tag2"]
static const char* kNIMChatRoomEnterLoginTags = "login_tags";
/// string 登录登出通知的目标标签
static const char* kNIMChatRoomEnterNotifyTags = "notify_tags";
/// int 鉴权方式，0表示最初的loginToken的校验方式，1表示基于appSecret计算的token鉴权方式，2表示基于第三方回调的token鉴权方式，默认0
static const char* kNIMChatRoomEnterAuthType = "auth_type";
/// string, 登录自定义字段，用于提交给用户的第三方回调服务进行登录检测，不会同步给其他端
static const char* kNIMChatRoomEnterLoginExt = "login_ext";
/// string, 反垃圾相关业务id
static const char* kNIMChatRoomEnterAntiSpamBusinessID = "anti_spam_business_id";
/// int 登录时使用的位置信息
static const char* kNIMChatRoomEnterEnableLocation = "enable_location";
static const char* kNIMChatRoomEnterLocationX = "location_x";
static const char* kNIMChatRoomEnterLocationY = "location_y";
static const char* kNIMChatRoomEnterLocationZ = "location_z";
static const char* kNIMChatRoomEnterLocationDistance = "location_distance";
/** @}*/  // 进入聊天室的可选填信息Json Keys

/** @name 独立聊天室进入的信息Json Keys
 * @{
 */
/// string, 应用appkey，匿名登录时必填
static const char* kNIMChatRoomEnterKeyAppKey = "app_key";
/// string
/// 应用数据目录，匿名登录时必填,使用默认路径时只需传入单个目录名（不以反斜杠结尾)
/// 使用自定义路径时需传入完整路径（以反斜杠结尾，并确保有正确的读写权限！）
static const char* kNIMChatRoomEnterKeyAppDataPath = "app_data_path";
/// int，匿名登录时选填,定义见NIMSDKLogLevel（选填，SDK默认的内置级别为kNIMSDKLogLevelPro）
static const char* kNIMChatRoomEnterKeyLogLevel = "log_level";
/// string array，聊天室地址，地址通过应用服务器接口获取
static const char* kNIMChatRoomEnterKeyAddress = "address";
/// int，是否开启随机ID模式，默认为关闭(0)，建议默认值
static const char* kNIMChatRoomEnterKeyRandomID = "random_id";
/// string，登录聊天室的账号非匿名模式下使用
static const char* kNIMChatRoomEnterKeyAccID = "accid";
/// string，登录聊天室的密码非匿名模式下使用
static const char* kNIMChatRoomEnterKeyToken = "token";
/** @}*/  // 独立聊天室进入的信息Json Keys

/** @name 消息结构 Json Keys
 * @{
 */
// 协议定义
/// int, 消息类型(NIMChatRoomMsgType)
static const char* kNIMChatRoomMsgKeyType = "msg_type";
/// string, 消息内容,长度限制2048, 如果约定的是json字符串，必须为可以解析为json的非格式化的字符串
static const char* kNIMChatRoomMsgKeyAttach = "msg_attach";
/// string,客户端消息id
static const char* kNIMChatRoomMsgKeyClientMsgid = "client_msg_id";
/// int,消息重发标记位,第一次发送0,重发1
static const char* kNIMChatRoomMsgKeyResendFlag = "resend_flag";
/// string, 第三方扩展字段, 长度限制4096, 必须为可以解析为Json的非格式化的字符串
static const char* kNIMChatRoomMsgKeyExt = "ext";
/// int, 是否需要过易盾反垃圾, 0:不需要,1:需要, 默认0
static const char* kNIMChatRoomMsgKeyAntiSpamEnable = "anti_spam_enable";
/// string, (可选)开发者自定义的反垃圾字段, 长度限制2048
static const char* kNIMChatRoomMsgKeyAntiSpamContent = "anti_spam_content";
/// string,  (可选)用户配置的对某些单条消息另外的反垃圾的业务ID
static const char* kNIMChatRoomMsgKeyAntiSpamBizId = "anti_spam_business_id";
/// int,(可选)该消息是否存储云端历史,可选，0:不是,1:是, 默认1
static const char* kNIMChatRoomMsgKeyHistorySave = "history_save";
/// int,  (可选) 单条消息是否使用易盾反垃圾 0:(在开通易盾的情况下)不过易盾反垃圾而是通用反垃圾 其他都是按照原来的规则
static const char* kNIMChatRoomMsgKeyAntiSpamUsingYiDun = "anti_spam_using_yidun";
/// string,(可选)文本消息内容（聊天室机器人文本消息）
static const char* kNIMChatRoomMsgKeyBody = "body";
/// (可选)string第三方回调回来的自定义扩展字段 v7.8 新增
static const char* kNIMChatRoomMsgKeyThirdPartyCBEXT = "third_party_callback_ext";
/// (可选)int，消息的子类型，客户端定义，服务器透传
static const char* kNIMChatRoomMsgKeySubType = "msg_sub_type";
/// (可选)String, 易盾反垃圾增强反作弊专属字段, 限制json，长度限制1024
static const char* kNIMChatRoomMsgKeyYiDunAntiCheating = "yidun_anti_cheating";
/// (可选)String, 自定义抄送配置 v8.0.0 新增
static const char* kNIMChatRoomMsgKeyEnvConfig = "env_config";
/// (可选)String 消息的目标标签表达式，参见TagPattern和TagCalculator v8.4.0 新增
static const char* kNIMChatRoomMsgKeyNotifyTags = "notify_tags";
/// (可选)String, 易盾反垃圾扩展字段，限制json，长度限制1024
static const char* kNIMChatRoomMsgKeyAntiSpamExt = "anti_spam_ext";
/// String, 易盾反垃圾返回的结果字段
static const char* kNIMChatRoomMsgKeyAntiSpamRes = "anti_spam_res";
/// (可选)int, 位置信息 X 轴坐标
static const char* kNIMChatRoomMsgKeyLocationX = "location_x";
/// (可选)int, 位置信息 Y 轴坐标
static const char* kNIMChatRoomMsgKeyLocationY = "location_y";
/// (可选)int, 位置信息 Z 轴坐标
static const char* kNIMChatRoomMsgKeyLocationZ = "location_z";
/// (可选)string, json array，消息接受者，如果设置了本字段，且不为空，则本消息为聊天室定向消息（聊天室定向消息不会存历史）
static const char* kNIMChatRoomMsgKeyToAccids = "to_accids";
/// (可选)int, 高优消息是否需要ack，0:不需要,1:需要。默认为0
static const char* kNIMChatRoomMsgNeedHighPriorityAck = "need_high_priority_ack";

// 以下定义对于客户端只读
/// long, 消息所属的聊天室id,服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyRoomID = "room_id";
/// string, 消息发送者的账号,服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyFromAccount = "from_id";
/// long, 消息发送的时间戳(毫秒),服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyTime = "time";
/// int,消息发送方客户端类型(NIMChatRoomClientType),服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyFromClientType = "from_client_type";
/// string, 消息发送方昵称,服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyFromNick = "from_nick";
/// string, 消息发送方头像,服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyFromAvatar = "from_avator";
/// string, 消息发送方身份扩展字段,服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyFromExt = "from_ext";
/// int, 高优先级消息标记,1:是; 非高优先级消息不带该字段,服务器填写,发送方不需要填写
static const char* kNIMChatRoomMsgKeyHighPriorityFlag = "high_priority_flag";

// 本地定义
/// string, 暂时不用,多媒体消息资源本地绝对路径,SDK本地维护,发送多媒体消息时必填
static const char* kNIMChatRoomMsgKeyLocalFilePath = "local_res_path";
/// string, 暂时不用,多媒体资源id,发送方选填,接收方收到的是客户端消息id
static const char* kNIMChatRoomMsgKeyLocalResId = "res_id";
/// int 聊天室更新的批量最大数
static const int iNIMMaxBatchQueue = 100;
/** @}*/  // 消息结构 Json Keys

/** @enum NIMSDKLogLevel 聊天室日志级别 */
enum NIMSDKLogLevel {
    kNIMSDKLogLevelFatal = 1, /**< SDK Fatal级别Log */
    kNIMSDKLogLevelError = 2, /**< SDK Error级别Log */
    kNIMSDKLogLevelWarn = 3,  /**< SDK Warn级别Log */
    kNIMSDKLogLevelApp = 5,   /**< SDK应用级别Log，正式发布时为了精简sdk log，可采用此级别 */
    kNIMSDKLogLevelPro = 6,   /**< SDK调试过程级别Log，更加详细，更有利于开发调试 */
};

/** @enum NIMChatRoomMsgType 聊天室消息类型 */
enum NIMChatRoomMsgType {
    kNIMChatRoomMsgTypeText = 0,         /**< 文本类型消息 */
    kNIMChatRoomMsgTypeImage = 1,        /**< 图片类型消息 */
    kNIMChatRoomMsgTypeAudio = 2,        /**< 声音类型消息 */
    kNIMChatRoomMsgTypeVideo = 3,        /**< 视频类型消息 */
    kNIMChatRoomMsgTypeLocation = 4,     /**< 位置类型消息 */
    kNIMChatRoomMsgTypeNotification = 5, /**< 活动室通知 */
    kNIMChatRoomMsgTypeFile = 6,         /**< 文件类型消息 */
    kNIMChatRoomMsgTypeRobot = 11,       /**< 波特机器人消息 */
    kNIMChatRoomMsgTypeTips = 10,        /**< 提醒类型消息 */
    kNIMChatRoomMsgTypeCustom = 100,     /**< 自定义消息 */
    kNIMChatRoomMsgTypeUnknown = 1000,   /**< 未知类型消息，作为默认值 */
};

/** @enum NIMChatRoomClientType 聊天室消息来源端 */
enum NIMChatRoomClientType {
    kNIMChatRoomClientTypeDefault = 0,      /**< default,unset */
    kNIMChatRoomClientTypeAndroid = 1,      /**< android */
    kNIMChatRoomClientTypeiOS = 2,          /**< iOS */
    kNIMChatRoomClientTypePCWindows = 4,    /**< PC */
    kNIMChatRoomClientTypeWindowsPhone = 8, /**< WindowsPhone */
    kNIMChatRoomClientTypeWeb = 16,         /**< Web */
    kNIMChatRoomClientTypeRestAPI = 32,     /**< RestAPI */
    kNIMChatRoomClientTypeMacOS = 64,       /**< Mac */
};

/** @name 进入聊天室回调结果Json Keys
 * @{
 */
/// json value, 见聊天室Info Json Keys
static const char* kNIMChatRoomEnterCallbackKeyRoomInfo = "room_info";
/// json value, 见聊天室个人Info Json Keys
static const char* kNIMChatRoomEnterCallbackKeyMyInfo = "my_info";

/** @}*/  // 进入回调结果Json Keys

/** @name 聊天室Info Json Keys
 * @{
 */
/// long, 聊天室ID
static const char* kNIMChatRoomInfoKeyID = "id";
/// string, 聊天室名称
static const char* kNIMChatRoomInfoKeyName = "name";
/// string, 聊天室公告
static const char* kNIMChatRoomInfoKeyAnnouncement = "announcement";
/// string, 视频直播拉流地址
static const char* kNIMChatRoomInfoKeyBroadcastUrl = "broadcast_url";
/// string, 聊天室创建者账号
static const char* kNIMChatRoomInfoKeyCreatorID = "creator_id";
/// int, 聊天室有效标记, 1:有效,0:无效
static const char* kNIMChatRoomInfoKeyValidFlag = "valid_flag";
/// string, 第三方扩展字段, 必须为可以解析为Json的非格式化的字符串, 长度4k
static const char* kNIMChatRoomInfoKeyExt = "ext";
/// int, 当前在线用户数量
static const char* kNIMChatRoomInfoKeyOnlineCount = "online_count";
/// int, 聊天室禁言标志 1:禁言,0:解除禁言
static const char* kNIMChatRoomInfoKeyMuteAll = "mute_all";
/// int, 队列管理权限：0:所有人都有权限变更队列，1:只有主播管理员才能操作变更
static const char* kNIMChatRoomInfoKeyQueuelevel = "queuelevel";
/** @}*/  // 聊天室Info Json Keys

/** @enum NIMChatRoomExitReason 聊天室离开原因 */
enum NIMChatRoomExitReason {
    kNIMChatRoomExitReasonExit = 0,            /**< 自行退出,重登前需要重新请求进入 */
    kNIMChatRoomExitReasonRoomInvalid = 1,     /**< 聊天室已经被解散,重登前需要重新请求进入 */
    kNIMChatRoomExitReasonKickByManager = 2,   /**< 被管理员踢出,重登前需要重新请求进入 */
    kNIMChatRoomExitReasonKickByMultiSpot = 3, /**< 多端被踢 */
    kNIMChatRoomExitReasonIllegalState = 4,    /**< 当前链接状态异常 */
    kNIMChatRoomExitReasonBeBlacklisted = 5,   /**< 被加黑了 */
};

/** @name 聊天室个人Info Json Keys
 * @{
 */
/// long 聊天室id
static const char* kNIMChatRoomMemberInfoKeyRoomID = "room_id";
/// string 成员账号
static const char* kNIMChatRoomMemberInfoKeyAccID = "account_id";
/// 成员类型, -1:受限用户; 0:普通;1:创建者;2:管理员;3:临时用户,非固定成员;4:匿名非注册用户,非云信注册用户
static const char* kNIMChatRoomMemberInfoKeyType = "type";
/// int 成员级别: >=0表示用户开发者可以自定义的级别
static const char* kNIMChatRoomMemberInfoKeyLevel = "level";
/// string 聊天室内的昵称字段,预留字段, 可从Uinfo中取
static const char* kNIMChatRoomMemberInfoKeyNick = "nick";
/// string 聊天室内的头像,预留字段, 可从Uinfo中取icon
static const char* kNIMChatRoomMemberInfoKeyAvatar = "avatar";
/// string 开发者扩展字段, 长度限制2k, 必须为可以解析为Json的非格式化的字符串
static const char* kNIMChatRoomMemberInfoKeyExt = "ext";
/// string 聊天室成员所属的 tag 信息
static const char* kNIMChatRoomMemberInfoKeyTag = "tags";
/// string 聊天室成员登录时指定的 notify_tags 信息
static const char* kNIMChatRoomMemberInfoKeyNotifyTags = "notify_tags";
/// NIMChatRoomOnlineState 成员是否处于在线状态, 仅特殊成员才可能离线, 对游客/匿名用户而言只能是在线
static const char* kNIMChatRoomMemberInfoKeyOnlineState = "online_state";
/// NIMChatRoomGuestFlag 是否是普通游客类型,0:不是游客,1:是游客; 游客身份在聊天室中没有持久化, 只有在线时才会有内存状态
static const char* kNIMChatRoomMemberInfoKeyGuestFlag = "guest_flag";
/// long 进入聊天室的时间点,对于离线成员该字段为空
static const char* kNIMChatRoomMemberInfoKeyEnterTimetag = "enter_timetag";
// 以下字段仅在返回前端时使用
/// int 是黑名单
static const char* kNIMChatRoomMemberInfoKeyBlacklist = "is_blacklist";
/// int 是禁言用户
static const char* kNIMChatRoomMemberInfoKeyMuted = "is_muted";
/// int 记录有效标记位
static const char* kNIMChatRoomMemberInfoKeyValid = "valid";
/// long 固定成员的记录更新时间,用于固定成员列表的排列查询
static const char* kNIMChatRoomMemberInfoKeyUpdateTimetag = "update_timetag";
/// int 临时禁言
static const char* kNIMChatRoomMemberInfoKeyTempMute = "temp_mute";
/// long 临时禁言的解除时长,单位秒
static const char* kNIMChatRoomMemberInfoKeyTempMuteRestDuration = "temp_mute_rest_duration";
/// string 反垃圾
static const char* kNIMChatRoomAntiSpamBusinessID = "anti_spam_business_id";
/** @}*/  // 聊天室个人Info Json Keys

/** @name 更新我的信息扩展字段 Json Keys
 * @{
 */
/// bool 我的资料是否需要持久化保存，默认false
static const char* kNIMChatRoomUpdateMyRoleExtNeedSave = "need_save";
/** @}*/  // 更新我的信息扩展字段 Json Keys

/** @enum NIMChatRoomLoginState 登录状态 */
enum NIMChatRoomLoginState {
    kNIMChatRoomLoginStateLogin = 1,   /**< 登录状态 */
    kNIMChatRoomLoginStateUnLogin = 2, /**< 未登录状态 */
};

/** @enum NIMChatRoomOnlineState 在线状态 */
enum NIMChatRoomOnlineState {
    kNIMChatRoomOnlineStateOffline = 0, /**<不在线 */
    kNIMChatRoomOnlineStateOnline = 1,  /**<在线 */
};

/** @enum NIMChatRoomGuestFlag 成员类型 */
enum NIMChatRoomGuestFlag {
    kNIMChatRoomGuestFlagNoGuest = 0, /**< 非游客 */
    kNIMChatRoomGuestFlagGuest = 1,   /**< 游客 */
};

/** @enum NIMChatRoomGetMemberType 查询成员的成员类型 */
enum NIMChatRoomGetMemberType {
    /// 固定成员,固定成员,包括创建者,管理员,普通等级用户,受限用户(禁言+黑名单)即使非在线也可以在列表中看到,有数量限制,查询时时间戳使用"updatetime"
    kNIMChatRoomGetMemberTypeSolid = 0,
    /// 非固定成员,非固定成员,又称临时成员,只有在线时才能在列表中看到,数量无上限,查询时时间戳使用"进入聊天室时间"
    kNIMChatRoomGetMemberTypeTemp = 1,
    /// 在线固定成员 查询时时间戳使用"updatetime"
    kNIMChatRoomGetMemberTypeSolidOL = 2,
    /// 非固定成员(反向查询) 查询时时间戳使用"进入聊天室时间"
    kNIMChatRoomGetMemberTypeTempOL = 3,
};

/** @enum NIMChatRoomMemberAttribute 设置成员的成员身份 */
enum NIMChatRoomMemberAttribute {
    kNIMChatRoomMemberAttributeAdminister = 1,  /**< 管理员,operator必须是创建者 */
    kNIMChatRoomMemberAttributeNomalMember = 2, /**< 普通成员,operator必须是创建者或管理员 */
    kNIMChatRoomMemberAttributeBlackList = -1,  /**< 黑名单,operator必须是创建者或管理员 */
    kNIMChatRoomMemberAttributeMuteList = -2,   /**< 禁言,operator必须是创建者或管理员 */
};

/** @name 分页获取成员列表条件Keys
 * @{
 */
/// NIMChatRoomGetMemberType 成员类型
static const char* kNIMChatRoomGetMembersKeyType = "type";
/// 获取成员时指定的 tag
static const char* kNIMChatRoomGetMembersKeyTag = "tag";
/// long 时间戳,填0会使用当前服务器最新时间开始查询，即第一页
static const char* kNIMChatRoomGetMembersKeyOffset = "offset";
/// int 数量
static const char* kNIMChatRoomGetMembersKeyLimit = "limit";
/** @}*/  // 分页获取成员列表条件Keys

/** @name 分获取历史消息条件Keys
 * @{
 */
/// long 开始时间,单位毫秒
static const char* kNIMChatRoomGetMsgHistoryKeyStartTime = "start";
/// int 本次返回的消息数量
static const char* kNIMChatRoomGetMsgHistoryKeyLimit = "limit";
/// boolean: true:按时间正序起查，正序排列,false:按时间逆序起查，逆序排列
static const char* kNIMChatRoomGetMsgHistoryKeyReverse = "reverse";
/// array:数组 要查询的消息类型，取值NIMChatRoomMsgType中所枚举类型
static const char* kNIMChatRoomGetMsgHistoryKeyMsgtypes = "msgtypes";
/** @}*/  // 分获取历史消息条件Keys

/** @name 设定聊天室成员标记身份条件Keys
 * @{
 */
/// string 成员ID
static const char* kNIMChatRoomSetMemberAttributeKeyAccoutID = "account_id";
/// NIMChatRoomMemberAttribute
static const char* kNIMChatRoomSetMemberAttributeKeyAttribute = "attribute";
/// boolean: true:是,false:否
static const char* kNIMChatRoomSetMemberAttributeKeyOpt = "opt";
/// string 自定义的事件通知扩展字段, 必须为可以解析为Json的非格式化的字符串
static const char* kNIMChatRoomSetMemberAttributeKeyNotifyExt = "notify_ext";
/** @}*/  // 设定聊天室成员标记身份条件Keys

/** @name 聊天室通知Keys
 * @{
 */
/// string 通知内容
static const char* kChatRoomNotificationKeyData = "data";
/// string 通知类型ID
static const char* kChatRoomNotificationKeyID = "id";
/// string 上层开发自定义的事件通知扩展字段, 必须为可以解析为Json的非格式化的字符串
static const char* kChatRoomNotificationDataKeyExt = "ext";
/// string 操作者的账号accid
static const char* kChatRoomNotificationDataKeyOpt = "operator";
/// string 操作者的账号nick
static const char* kChatRoomNotificationDataKeyOptNick = "opeNick";
/// string json array 被操作者的nick列表
static const char* kChatRoomNotificationDataKeyTargetNick = "tarNick";
/// string json array 被操作者的accid
static const char* kChatRoomNotificationDataKeyTarget = "target";
/// long 当通知为临时禁言相关时有该值，禁言时kNIMChatRoomNotificationIdMemberTempMute代表本次禁言的时长(秒)
static const char* kChatRoomNotificationDataKeyTempMuteDuration = "muteDuration";
/// int 当通知为kNIMChatRoomNotificationIdMemberIn才有，代表是否禁言状态，1:是 缺省或0:不是
static const char* kChatRoomNotificationDataKeyMuteFlag = "muted";
/// int 当通知为kNIMChatRoomNotificationIdMemberIn才有，代表是否临时禁言状态，1:是 缺省或0:不是
static const char* kChatRoomNotificationDataKeyTempMutedFlag = "tempMuted";
/// long 当通知为kNIMChatRoomNotificationIdMemberIn，代表临时禁言时长(秒)， 其他通知事件不带该数据
static const char* kChatRoomNotificationDataKeyMemberInTempMutedDuration = "muteTtl";
/// string 当通知为kNIMChatRoomNotificationIdQueueChange，代表队列变更具体内容，内容解析 参考麦序队列变更通知扩展字段queueChange
static const char* kChatRoomNotificationDataKeyQueueChange = "queueChange";
/// string 当通知为 kChatRoomNotificationIdTagTempMuteAdd 或 kChatRoomNotificationIdTagTempMuteRemove，代表被禁言的目标 tag
static const char* kChatRoomNotificationDataKeyTargetTag = "targetTag";
/// int64_t 当通知为 kChatRoomNotificationIdRecallMessage，代表被撤回消息的消息时间戳
static const char* kChatRoomNotificationDataKeyMsgTimetag = "msgTime";
/// string 当通知为 kChatRoomNotificationIdRecallMessage，代表被撤回消息的消息 ID
static const char* kChatRoomNotificationDataKeyMsgId = "msgId";
///
/** @}*/  // 聊天室通知Keys

/** @name 聊天室麦序队列元素Keys
 * @{
 */
/// string 元素key
static const char* kNIMChatRoomQueueElementKey = "key";
/// string 元素value
static const char* kNIMChatRoomQueueElementValue = "value";
/** @}*/  // 聊天室麦序队列元素Keys

/**
 * @name 聊天室添加、更新队列元素选项
 * @{
 */
/// bool （可选参数）true 表示当提交这个新元素的用户从聊天室掉线或退出的时候，需要删除这个元素；默认 false 表示不删除
static const char* kNIMChatRoomQueueOfferOptionTransient = "transient";
/// string （可选参数）队列元素所属账号，默认不传表示队列元素属于当前操作人，管理员可以指定队列元素归属于其他合法账号
static const char* kNIMChatRoomQueueOfferOptionElementAccId = "element_accid";
/** @}*/  // 聊天室添加、更新队列元素选项

/** @name 麦序队列变更通知扩展字段type取值
 * @{
 */
/// 放元素到新队列
static const char* kNIMChatRoomNotificationQueueChangedType_OFFER = "OFFER";
/// 从队列中取出新队列
static const char* kNIMChatRoomNotificationQueueChangedType_POLL = "POLL";
/// 清理队列操作
static const char* kNIMChatRoomNotificationQueueChangedType_DROP = "DROP";
/// 部分清理操作(发生在提交元素的用户掉线时，清理这个用户对应的key
static const char* kNIMChatRoomNotificationQueueChangedType_PARTCLEAR = "PARTCLEAR";
/** @}*/  // 麦序队列变更通知扩展字段type取值

/** @name 聊天室通知 麦序队列变更通知扩展字段queueChange keys
 * @{
 */
/// string 变更类型，目前有OFFER,POLL,DROP,BATCH_UPDATE 类型
static const char* kNIMChatRoomNotificationQueueChangedKeyType = "_e";
/// string 变更元素的key
static const char* kNIMChatRoomNotificationQueueChangedKeyKey = "key";
/// string 变更元素的内容
static const char* kNIMChatRoomNotificationQueueChangedKeyValue = "content";
/** @}*/  // 聊天室通知 麦序队列变更通知扩展字段queueChange keys

/** @name 聊天室通知 麦序队列中有批量变更通知扩展字段queueBatchChange keys
 * @ 当type为"PARTCLEAR"时，一般情况下只会有_e和kvObject字段，不会有key和content字段
 * @{
 */
/// string 变更类型，目前有OFFER,POLL,DROP,PARTCLEAR四个类型
static const char* kNIMChatRoomNotificationQueueBatchChangedKeyType = "_e";
/// string 变更元素的key
static const char* kNIMChatRoomNotificationQueueBatchChangedKeyKey = "key";
/// string 变更元素的内容
static const char* kNIMChatRoomNotificationQueueBatchChangedKeyValue = "content";
/// map 变更元素的内容
static const char* kNIMChatRoomNotificationQueueBatchChangedKeyObject = "kvObject";
/** @}*/  // 聊天室通知 麦序队列中有批量变更通知扩展字段queueBatchChange keys

/** @enum NIMChatRoomNotificationId 聊天室通知类型 {"data" : {"ext":"", "operator":"", "opeNick":"", "tarNick":["",...], "target":["",...], ...},
 * "id": 301} */
enum NIMChatRoomNotificationId {
    kNIMChatRoomNotificationIdMemberIn = 301,         /**< 成员进入聊天室 */
    kNIMChatRoomNotificationIdMemberExit = 302,       /**< 成员离开聊天室 */
    kNIMChatRoomNotificationIdAddBlack = 303,         /**< 成员被加黑 */
    kNIMChatRoomNotificationIdRemoveBlack = 304,      /**< 成员被取消黑名单 */
    kNIMChatRoomNotificationIdAddMute = 305,          /**< 成员被设置禁言 */
    kNIMChatRoomNotificationIdRemoveMute = 306,       /**< 成员被取消禁言 */
    kNIMChatRoomNotificationIdAddManager = 307,       /**< 设置为管理员 */
    kNIMChatRoomNotificationIdRemoveManager = 308,    /**< 取消管理员 */
    kNIMChatRoomNotificationIdAddFixed = 309,         /**< 成员设定为固定成员 */
    kNIMChatRoomNotificationIdRemoveFixed = 310,      /**< 成员取消固定成员 */
    kNIMChatRoomNotificationIdClosed = 311,           /**< 聊天室被关闭了 */
    kNIMChatRoomNotificationIdInfoUpdated = 312,      /**< 聊天室信息被更新了 */
    kNIMChatRoomNotificationIdMemberKicked = 313,     /**< 成员被踢了 */
    kNIMChatRoomNotificationIdMemberTempMute = 314,   /**< 临时禁言 */
    kNIMChatRoomNotificationIdMemberTempUnMute = 315, /**< 主动解除临时禁言 */
    kNIMChatRoomNotificationIdMyRoleUpdated = 316,    /**< 成员主动更新了聊天室内的角色信息(仅指nick/avator/ext) */
    kNIMChatRoomNotificationIdQueueChanged = 317, /**< 麦序队列中有变更 "ext" : {"_e":"OFFER", "key":"element_key", "content":"element_value"} */
    kNIMChatRoomNotificationIdRoomMuted = 318,    /**< 聊天室被禁言了,只有管理员可以发言,其他人都处于禁言状态 */
    kNIMChatRoomNotificationIdRoomDeMuted = 319, /**< 聊天室解除全体禁言状态 */
    kNIMChatRoomNotificationIdQueueBatchChanged = 320, /**< 麦序队列中有批量变更，发生在元素提交者离开聊天室或者从聊天室异常掉线时 */
    kNIMChatRoomNotificationIdTagTempMuteAdd = 321, /**< 聊天室新增标签禁言，包括的字段是muteDuration、targetTag、operator、opeNick字段 */
    kNIMChatRoomNotificationIdTagTempMuteRemove = 322, /**< 聊天室移除标签禁言，包括的字段是muteDuration、targetTag、operator、opeNick字段 */
    kNIMChatRoomNotificationIdRecallMessage = 323, /**< 聊天室消息撤回，包括的字段是operator、target、msgTime、msgId、ext字段 */
    /// 聊天室麦序队列中有批量增加通知消息 "ext" :{"_e":"BATCH_OFFER","elements":[{"nick":"ddd","accid":"ljmt","value":"v2","key":"hzlj02_key2"}]}
    kNIMChatRoomNotificationIdQueueBatchOffer = 324
};

/** @enum NIMChatRoomLinkCondition 聊天室链接情况，一般都是有本地网路情况引起 */
enum NIMChatRoomLinkCondition {
    kNIMChatRoomLinkConditionAlive = 0,        /**< 链接正常 */
    kNIMChatRoomLinkConditionDeadAndRetry = 1, /**< 链接失败,sdk尝试重链 */
    kNIMChatRoomLinkConditionDead = 2,         /**< 链接失败,开发者需要重新申请聊天室进入信息 */
};

/** @enum NIMChatRoomEnterStep 聊天室进入状态 */
enum NIMChatRoomEnterStep {
    kNIMChatRoomEnterStepInit = 1,              /**< 本地服务初始化 */
    kNIMChatRoomEnterStepServerConnecting = 2,  /**< 服务器连接中 */
    kNIMChatRoomEnterStepServerConnectOver = 3, /**< 服务器连接结束,连接结果见error_code */
    kNIMChatRoomEnterStepRoomAuthing = 4,       /**< 聊天室鉴权中 */
    kNIMChatRoomEnterStepRoomAuthOver = 5, /**< 聊天室鉴权结束,鉴权结果见error_code, error_code非408则需要开发者重新请求聊天室进入信息 */
};

/** @enum NIMChatRoomProxyType 代理类型 */
enum NIMChatRoomProxyType {
    kNIMChatRoomProxyNone = 0,    /**< 不使用代理 */
    kNIMChatRoomProxyHttp11 = 1,  /**< HTTP 1.1 Proxy（暂不支持） */
    kNIMChatRoomProxySocks4 = 4,  /**< Socks4 Proxy */
    kNIMChatRoomProxySocks4a = 5, /**< Socks4a Proxy */
    kNIMChatRoomProxySocks5 = 6,  /**< Socks5 Proxy */
};

/** @name 机器人信息 Json Keys
 * 例子  { "accid" : "", "create_timetag" : 1430101821372, "icon" : "", "intro":"", "name" : "", "update_timetag" : 1430101821372, "rid":"" }
 * @{
 */
// 协议定义
/// string 帐号
static const char* kNIMRobotInfoKeyAccid = "accid";
/// string 名字
static const char* kNIMRobotInfoKeyName = "name";
/// string 头像
static const char* kNIMRobotInfoKeyIcon = "icon";
/// string 介绍
static const char* kNIMRobotInfoKeyIntro = "intro";
/// string 机器人ID
static const char* kNIMRobotInfoKeyRobotId = "rid";
/// long 创建时间戳 毫秒
static const char* kNIMRobotInfoKeyCreateTime = "create_timetag";
/// long 更新时间戳 毫秒
static const char* kNIMRobotInfoKeyUpdateTime = "update_timetag";
/** @}*/  // 机器人信息 Json Keys

/** @name 公共配置 Json Keys
 * @{
 */
/// json obj 公共配置root key
static const char* kEnterKeyPublicConfigRoot = "public_config";
/// int 是否为专属集群 1:是 0: 否
static const char* kEnterKeyDedicatedClusteFlag = "dedicated_cluste_flag";
/// int  "交换密钥"协议加密算法 {1(RSA),2(SM2)}, def:1(RSA) 非对称加密
static const char* kEnterKeyNegoKeyNECA = "nego_key_neca";
/// int 通信加密算法 {1(RC4),2(AES128),4(SM4)} def:1(RC4) 对称加密
static const char* kEnterKeyCommNECA = "comm_enca";
/// int 登录时使用的握手协议类型 0:支持配置多种对称与非对称加密算法,1:只支持RAS + RC4，缺省 1
static const char* kEnterKeyHandShakeType = "hand_shake_type";
/** @} */
/** @name 私有化配置 Json Keys
 * @{
 */
/// json obj 私有配置root key
static const char* kEnterKeyPrivateConfigRoot = "private_config";
/// string  "交换密钥"协议加密算法密钥 part A 自定义时则必填 BigNumHex string 不含0x RSA:module,SM2:X
static const char* kEnterKeyNegoKeyNECAKeyPA = "nego_key_enca_key_parta";
/// string  "交换密钥"协议加密算法密钥 part B 自定义时则必填 BigNumHex string 不含0x RSA:EXP,SM2:Y
static const char* kEnterKeyNegoKeyNECAKeyPB = "nego_key_enca_key_partb";
/// int  非对称加密算法的 key version 自定义时则必填
static const char* kEnterKeyNegoKeyNECAKeyV = "nego_key_enca_key_version";
/** @} */
typedef char* NIMChatRoomConfigGetter;
#define EmptyNIMChatRoomConfigGetter ("")
#ifdef __cplusplus
};
#endif  // __cplusplus
#endif  // NIM_CHATROOM_NIM_CHATROOM_DEFINES_NIM_CHATROOM_DEF_H_
