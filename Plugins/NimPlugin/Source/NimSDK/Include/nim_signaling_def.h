/** @file nim_signaling_def.h
 * @brief 独立信令 接口相关的常量函数等定义头文件
 * @copyright (c) 2015-2018, NetEase Inc. All rights reserved
 * @author gq
 * @date 2018/10/31
 */

#ifndef NIM_SDK_DLL_EXPORT_HEADERS_NIM_SIGNALING_DEF_H_
#define NIM_SDK_DLL_EXPORT_HEADERS_NIM_SIGNALING_DEF_H_

#include "public_defines.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @enum NIMSignalingType
 *    @brief 频道类型
 */
enum NIMSignalingType {
    /// 音频类型
    kNIMSignalingTypeAudio = 1,
    /// 视频类型
    kNIMSignalingTypeVideo = 2,
    /// 自定义
    kNIMSignalingTypeCustom = 3,
};

/** @struct NIMSignalingChannelInfo
 *    @brief 频道属性
 */
struct NIMSignalingChannelInfo {
    /// 通话类型,1:音频;2:视频;3:其他
    enum NIMSignalingType channel_type_;
    /// 创建时传入的频道名
    char* channel_name_;
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 创建时传入的扩展字段
    char* channel_ext_;
    /// 创建时间点
    uint64_t create_timestamp_;
    /// 失效时间点
    uint64_t expire_timestamp_;
    /// 创建者的accid
    char* creator_id_;
    /// 频道是否有效
    bool invalid_;
    /// 云信G2-RTC的token的有效期
    uint64_t nertc_token_ttl_;
    /// 云信G2-RTC的token
    char* nertc_token_;
    /// 云信G2-RTC加入房间的响应，可以转成json
    char* nertc_join_room_resp_;
};

/** @struct NIMSignalingMemberInfo
 *    @brief 成员属性
 */
struct NIMSignalingMemberInfo {
    /// 成员的 accid
    char* account_id_;
    /// 成员的 uid，大于零有效，无效时服务器会分配随机频道内唯一的uid
    int64_t uid_;
    /// 加入时间点
    uint64_t create_timestamp_;
    /// 失效时间点，失效后认为离开频道
    uint64_t expire_timestamp_;
};

/** @struct NIMSignalingChannelDetailedinfo
 *    @brief 频道的详细信息，包含频道信息及成员列表
 */
struct NIMSignalingChannelDetailedinfo {
    /// 频道信息
    struct NIMSignalingChannelInfo channel_info_;
    /// 频道内成员信息数组
    struct NIMSignalingMemberInfo* members_;
    /// 频道内成员个数
    int32_t member_size_;
};

/** @struct NIMSignalingPushInfo
 *    @brief 推送属性
 */
struct NIMSignalingPushInfo {
    /// 是否需要推送，默认false，
    bool need_push_;
    /// 推送标题
    char* push_title_;
    /// 推送内容
    char* push_content_;
    /// 推送自定义字段
    char* push_payload_;
    /// 是否计入未读计数,默认true
    bool need_badge_;
};

/** @enum NIMSignalingEventType
 *    @brief 频道事件，包含在线，同步，离线等
 */
enum NIMSignalingEventType {
    /// 返回NIMSignalingNotifyInfoClose，支持在线、离线通知
    kNIMSignalingEventTypeClose = 1,
    /// 返回NIMSignalingNotifyInfoJoin，支持在线、离线通知
    kNIMSignalingEventTypeJoin = 2,
    /// 返回NIMSignalingNotifyInfoInvite，支持在线、离线通知
    kNIMSignalingEventTypeInvite = 3,
    /// 返回NIMSignalingNotifyInfoCancelInvite，支持在线、离线通知
    kNIMSignalingEventTypeCancelInvite = 4,
    /// 返回NIMSignalingNotifyInfoReject，支持在线、多端同步、离线通知
    kNIMSignalingEventTypeReject = 5,
    /// 返回NIMSignalingNotifyInfoAccept，支持在线、多端同步、离线通知
    kNIMSignalingEventTypeAccept = 6,
    /// 返回NIMSignalingNotifyInfoLeave，支持在线、离线通知
    kNIMSignalingEventTypeLeave = 7,
    /// 返回NIMSignalingNotifyInfoControl，支持在线通知
    kNIMSignalingEventTypeCtrl = 8,
};

/** @struct NIMSignalingNotifyInfo
 *    @brief 事件通知信息基类
 */
struct NIMSignalingNotifyInfo {
    /// 通知类型
    enum NIMSignalingEventType event_type_;
    /// 频道信息
    struct NIMSignalingChannelInfo channel_info_;
    /// 操作者
    char* from_account_id_;
    /// 操作的扩展字段
    char* custom_info_;
    /// 操作的时间戳
    uint64_t timestamp_;
};

/**
 *    @brief NIMSignalingNotifyInfo 的宏定义基类
 */
#define NIMSignalingNotifyInfoBase                \
    enum NIMSignalingEventType event_type_;       \
    struct NIMSignalingChannelInfo channel_info_; \
    char* from_account_id_;                       \
    char* custom_info_;                           \
    uint64_t timestamp_;

/** @struct NIMSignalingNotifyInfoClose
 *    @brief 频道关闭事件通知信息，event_type_=kNIMSignalingEventTypeClose
 */
struct NIMSignalingNotifyInfoClose {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
};

/** @struct NIMSignalingNotifyInfoJoin
 *    @brief 加入频道事件通知信息，event_type_=kNIMSignalingEventTypeJoin
 */
struct NIMSignalingNotifyInfoJoin {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
    /// 加入成员的信息，用于获得uid
    struct NIMSignalingMemberInfo member_;
};

/** @struct NIMSignalingNotifyInfoInvite
 *    @brief 邀请事件通知信息，event_type_=kNIMSignalingEventTypeInvite
 */
struct NIMSignalingNotifyInfoInvite {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
    /// 被邀请者的账号
    char* to_account_id_;
    /// 邀请者邀请的请求id，用于被邀请者回传request_id_作对应的回应操作
    char* request_id_;
    /// 推送信息
    struct NIMSignalingPushInfo push_info_;
};

/** @struct NIMSignalingNotifyInfoCancelInvite
 *    @brief 取消邀请事件通知信息，event_type_=kNIMSignalingEventTypeCancelInvite
 */
struct NIMSignalingNotifyInfoCancelInvite {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
    /// 被邀请者的账号
    char* to_account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
};
/** @struct NIMSignalingNotifyInfoReject
 *    @brief 拒绝邀请事件通知信息，event_type_=kNIMSignalingEventTypeReject
 */
struct NIMSignalingNotifyInfoReject {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
    /// 邀请者的账号
    char* to_account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
};
/** @struct NIMSignalingNotifyInfoAccept
 *    @brief 接收邀请事件通知信息，event_type_=kNIMSignalingEventTypeAccept
 */
struct NIMSignalingNotifyInfoAccept {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
    /// 邀请者的账号
    char* to_account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
};

/** @struct NIMSignalingNotifyInfoLeave
 *    @brief 退出频道事件通知信息，event_type_=kNIMSignalingEventTypeLeave
 */
struct NIMSignalingNotifyInfoLeave {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
};

/** @struct NIMSignalingNotifyInfoControl
 *    @brief 控制事件通知信息，event_type_=kNIMSignalingEventTypeCtrl
 */
struct NIMSignalingNotifyInfoControl {
    /// 事件通知信息基类
    NIMSignalingNotifyInfoBase;
};

/** @typedef void(*nim_signaling_notify_cb_func)(const struct NIMSignalingNotifyInfo *notify_info, const void *user_data);
 * @brief 事件回调函数，用于在线通知和多端同步通知
 * @param[out] notify_info
 * 事件回调的信息指针，根据NIMSignalingNotifyInfo.event_type_指向对应NIMSignalingNotifyInfo扩展，如NIMSignalingNotifyInfoAccept
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_signaling_notify_cb_func)(const struct NIMSignalingNotifyInfo* notify_info, const void* user_data);

/** @typedef void(*nim_signaling_notify_list_cb_func)(const struct NIMSignalingNotifyInfo** info_list, int32_t size, const void *user_data)
 * @brief 事件回调函数，用于离线通知
 * @param[out] info_list
 * 事件回调的信息NIMSignalingNotifyInfo指针的数组，根据NIMSignalingNotifyInfo.event_type_指向对应NIMSignalingNotifyInfo扩展，如NIMSignalingNotifyInfoAccept
 * @param[out] size info_list数组的长度
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_signaling_notify_list_cb_func)(const struct NIMSignalingNotifyInfo** info_list, int32_t size, const void* user_data);

/** @typedef void(*nim_signaling_channels_sync_cb_func)(const struct NIMSignalingChannelDetailedinfo *info_list, int32_t size, const void *user_data)
 * @brief 频道列表同步回调函数
 * @note 在login或者relogin后，会通知该设备账号还未退出的频道列表，用于同步；如果没有在任何频道中，也会返回该同步通知，list为空
 * @param[out] info_list 频道的详细信息NIMSignalingChannelDetailedinfo的数组，可能为空
 * @param[out] size info_list数组的长度
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_signaling_channels_sync_cb_func)(const struct NIMSignalingChannelDetailedinfo* info_list, int32_t size, const void* user_data);

/** @typedef void(*nim_signaling_members_sync_cb_func)(const struct NIMSignalingChannelDetailedinfo *detailed_info, const void *user_data)
 * @brief 频道成员变更同步回调函数
 * @note 用于同步频道内的成员列表变更，当前该接口为定时接口，2分钟同步一次，成员有变化时才上报
 *         由于一些特殊情况，导致成员在离开或掉线前没有主动调用离开频道接口，使得该成员的离开没有对应的离开通知事件，由该回调接口【频道成员变更同步通知】告知用户。
 * @param[out] detailed_info 频道的详细信息
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_signaling_members_sync_cb_func)(const struct NIMSignalingChannelDetailedinfo* detailed_info, const void* user_data);

/** @struct NIMSignalingCreateParam
 *    @brief 创建频道接口nim_signaling_create的传入参数
 */
struct NIMSignalingCreateParam {
    /// 通话类型,1:音频;2:视频;3:其他
    enum NIMSignalingType channel_type_;
    /// 创建时传入的频道名，可缺省
    char* channel_name_;
    /// 创建时传入的扩展字段，可缺省
    char* channel_ext_;
};

/** @struct NIMSignalingCreateResParam
 *    @brief 创建频道结果回调信息
 */
struct NIMSignalingCreateResParam {
    /// 频道信息
    struct NIMSignalingChannelInfo channel_info_;
};

/** @struct NIMSignalingCloseParam
 *    @brief 关闭频道接口nim_signaling_close的传入参数
 */
struct NIMSignalingCloseParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 操作的扩展字段
    char* custom_info_;
    /// 是否存离线
    bool offline_enabled_;
};

/** @struct NIMSignalingJoinParam
 *    @brief 加入频道接口nim_signaling_join的传入参数
 */
struct NIMSignalingJoinParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 操作者附加的自定义信息，透传给其他人，可缺省
    char* custom_info_;
    /// 自己在频道中对应的uid，大于零有效，无效时服务器会分配随机唯一的uid
    int64_t uid_;
    /// 是否存离线
    bool offline_enabled_;
    /// 云信G2-RTC的房间名，不为空则返回对应token
    char* nertc_channel_name_;
    /// 云信G2-RTC的token有效期, 单位秒
    uint64_t nertc_token_ttl_;
    /// 云信G2-RTC加入房间的请求参数
    char* nertc_join_room_query_param_;
};
/** @struct NIMSignalingJoinResParam
 *    @brief 加入频道结果回调信息
 */
struct NIMSignalingJoinResParam {
    /// 频道的详细信息
    struct NIMSignalingChannelDetailedinfo info_;
};

/** @struct NIMSignalingLeaveParam
 *    @brief 离开频道接口nim_signaling_leave的传入参数
 */
struct NIMSignalingLeaveParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 操作的扩展字段
    char* custom_info_;
    /// 是否存离线
    bool offline_enabled_;
};

/** @struct NIMSignalingQueryChannelInfoParam
 *    @brief 查询频道接口nim_signaling_query_channel_info的传入参数
 */
struct NIMSignalingQueryChannelInfoParam {
    /// 创建时传入的频道名
    char* channel_name_;
};
/** @struct NIMSignalingQueryChannelInfoResParam
 *    @brief 查询频道结果回调信息
 */
struct NIMSignalingQueryChannelInfoResParam {
    /// 频道的详细信息
    struct NIMSignalingChannelDetailedinfo info_;
};

/** @struct NIMSignalingCallParam
 *    @brief 呼叫接口nim_signaling_call的传入参数
 */
struct NIMSignalingCallParam {
    /// 通话类型,1:音频;2:视频;3:其他
    enum NIMSignalingType channel_type_;
    /// 创建时传入的频道名，可缺省
    char* channel_name_;
    /// 创建时传入的扩展字段，可缺省
    char* channel_ext_;
    /// 自己在频道中对应的uid，大于零有效，无效时服务器会分配随机唯一的uid
    int64_t uid_;
    /// 被邀请者的账号
    char* account_id_;
    /// 邀请者邀请的请求id，需要邀请者填写，之后取消邀请、拒绝、接受需要复用该request_id_
    char* request_id_;
    /// 操作的扩展字段，透传给被邀请者，可缺省
    char* custom_info_;
    /// 是否存离线
    bool offline_enabled_;
    /// 推送属性
    struct NIMSignalingPushInfo push_info_;
    /// 云信G2-RTC的房间名，不为空则返回对应token
    char* nertc_channel_name_;
    /// 云信G2-RTC的token有效期, 单位秒
    uint64_t nertc_token_ttl_;
    /// 云信G2-RTC加入房间的请求参数
    char* nertc_join_room_query_param_;
};

/** @typedef NIMSignalingCallResParam
 *    @brief 呼叫结果回调信息
 */
struct NIMSignalingCallResParam {
    /// 频道的详细信息
    struct NIMSignalingChannelDetailedinfo info_;
    uint32_t call_status_;
};

struct NIMSignalingJoinAndAcceptParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 操作者附加的自定义信息，透传给其他人，可缺省
    char* custom_info_;
    /// 自己在频道中对应的uid，大于零有效，无效时服务器会分配随机唯一的uid
    int64_t uid_;
    /// 邀请者的账号
    char* account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
    /// 是否存离线
    bool offline_enabled_;
    /// 云信G2-RTC的房间名，不为空则返回对应token
    char* nertc_channel_name_;
    /// 云信G2-RTC的token有效期, 单位秒
    uint64_t nertc_token_ttl_;
    /// 云信G2-RTC加入房间的请求参数
    char* nertc_join_room_query_param_;
};

struct NIMSignalingJoinAndAcceptResParam {
    /// 频道的详细信息
    struct NIMSignalingChannelDetailedinfo info_;
    uint32_t call_status_;
};

/** @struct NIMSignalingInviteParam
 *    @brief 邀请接口nim_signaling_invite的传入参数
 */
struct NIMSignalingInviteParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 被邀请者的账号
    char* account_id_;
    /// 邀请者邀请的请求id，需要邀请者填写，之后取消邀请、拒绝、接受需要复用该request_id_
    char* request_id_;
    /// 操作的扩展字段，透传给被邀请者，可缺省
    char* custom_info_;
    /// 是否存离线
    bool offline_enabled_;
    /// 推送属性
    struct NIMSignalingPushInfo push_info_;
};

/** @struct NIMSignalingCancelInviteParam
 *    @brief 取消邀请接口nim_signaling_cancel_invite的传入参数
 */
struct NIMSignalingCancelInviteParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 被邀请者的账号
    char* account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
    /// 操作的扩展字段，可缺省
    char* custom_info_;
    /// 是否存离线
    bool offline_enabled_;
};

/** @struct NIMSignalingRejectParam
 *    @brief 拒绝接口nim_signaling_reject的传入参数
 */
struct NIMSignalingRejectParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 邀请者的账号
    char* account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
    /// 操作的扩展字段
    char* custom_info_;
    /// 是否存离线
    bool offline_enabled_;
};
/** @struct NIMSignalingAcceptParam
 *    @brief 接受邀请接口nim_signaling_accept的传入参数
 */
struct NIMSignalingAcceptParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 邀请者的账号
    char* account_id_;
    /// 邀请者邀请的请求id
    char* request_id_;
    /// 操作的扩展字段
    char* accept_custom_info_;
    /// 是否存离线
    bool offline_enabled_;
    /// 是否加入，默认不打开，打开后后续参数uid_、join_custom_info_有效
    bool auto_join_;
    /// 自己在频道中对应的uid，大于零有效，无效时服务器会分配随机唯一的uid，可缺省填0
    int64_t uid_;
    /// 加入频道的自定义扩展信息，将在加入频道通知中带给其他频道成员，可缺省
    char* join_custom_info_;
    /// 云信G2-RTC的房间名，不为空则返回对应token
    char* nertc_channel_name_;
    /// 云信G2-RTC的token有效期, 单位秒
    uint64_t nertc_token_ttl_;
    /// 云信G2-RTC加入房间的请求参数
    char* nertc_join_room_query_param_;
};

/** @typedef NIMSignalingAcceptResParam
 *    @brief 接受邀请结果回调信息，在自动加入成功后返回有效
 */
typedef NIMSignalingJoinResParam NIMSignalingAcceptResParam;

/** @struct NIMSignalingControlParam
 *    @brief 控制通知接口nim_signaling_control的传入参数
 */
struct NIMSignalingControlParam {
    /// 服务器生成的频道ID
    char* channel_id_;
    /// 对方accid，如果为空，则通知所有人
    char* account_id_;
    /// 操作的扩展字段
    char* custom_info_;
};

/** @typedef void (*nim_signaling_opt_cb_func)(int code, void *opt_res_param, const void *user_data);
 * @brief 操作回调，通用的操作回调接口
 * @param[out] code 操作返回码NIMResCode，见nim_res_code_def.h
 * @param[out] opt_res_param 操作结果返回信息
 * @param[out] user_data APP的自定义用户数据，SDK只负责传回给回调函数cb，不做任何处理！
 * @return void 无返回值
 */
typedef void (*nim_signaling_opt_cb_func)(int code, void* opt_res_param, const void* user_data);

/// 通知类型
static const char* kNIMSglEventType = "event_type";
/// 频道信息
static const char* kNIMSglChannelInfo = "channel_info";
/// 操作者
static const char* kNIMSglFromAccountID = "from_account_id";
/// 扩展字段
static const char* kNIMSglCustomInfo = "custom_info";
/// 时间戳
static const char* kNIMSglTimeStamp = "timestamp";
/// 通话类型,1:音频;2:视频;3:其他
static const char* kNIMSglChannelType = "channel_type";
/// 创建时传入的频道名
static const char* kNIMSglChannelName = "channel_name";
/// 服务器生成的频道ID
static const char* kNIMSglChannelID = "channel_id";
/// 扩展字段
static const char* kNIMSglChannelExt = "channel_ext";
/// 创建时间点
static const char* kNIMSglCreateTime = "create_timestamp";
/// 失效时间点
static const char* kNIMSglExpireTime = "expire_timestamp";
/// 创建者的accid
static const char* kNIMSglCreatorID = "creator_id";
/// 频道是否有效
static const char* kNIMSglInvalid = "invalid";
/// 频道内成员信息数组
static const char* kNIMSglMembers = "members";
/// 成员的 accid
static const char* kNIMSglAccountID = "account_id";
/// 成员的 uid，大于零有效，无效时服务器会分配随机频道内唯一的uid
static const char* kNIMSglUID = "uid";
/// 是否存离线
static const char* kNIMSglOfflineEnabled = "offline_enabled";
/// 频道详细信息
static const char* kNIMSglDetailedInfo = "info";
/// 邀请者邀请的请求id，需要邀请者填写，之后取消邀请、拒绝、接受需要复用该request_id_
static const char* kNIMSglRequestID = "request_id";
/// 推送属性
static const char* kNIMSglPushInfo = "push_info";
/// 是否需要推送，默认false
static const char* kNIMSglNeedPush = "need_push";
/// 推送标题
static const char* kNIMSglPushTitle = "push_title";
/// 推送内容
static const char* kNIMSglPushContent = "push_content";
/// 推送自定义字段
static const char* kNIMSglPushPlayload = "push_payload";
/// 是否计入未读计数,默认true
static const char* kNIMSglNeedBadge = "need_badge";
/// 扩展字段
static const char* kNIMSglAcceptCustomInfo = "accept_custom_info";
/// 是否加入，打开后后续参数uid_、join_custom_info_有效
static const char* kNIMSglAutoJoin = "auto_join";
/// 加入频道的自定义扩展信息，将在加入频道通知中带给其他频道成员，可缺省
static const char* kNIMSglJoinCustomInfo = "join_custom_info";

#ifdef __cplusplus
};
#endif  //__cplusplus
#endif  // NIM_SDK_DLL_EXPORT_HEADERS_NIM_SIGNALING_DEF_H_
