/**
 * @file nim_qchat_public_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_PUBLIC_DEF_H__
#define __NIM_QCHAT_PUBLIC_DEF_H__

#include <stddef.h>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
/** @enum NIMQChatChannelViewMode 圈组频道查看模式 */
enum NIMQChatChannelViewMode {
    /// 公开模式
    kNIMQChatChannelViewModePublic = 0,
    /// 私密模式
    kNIMQChatChannelViewModePrivate = 1,
};

/// @enum NIMQChatChannelSyncMode
enum NIMQChatChannelSyncMode {
    /// 不与频道分组同步
    kNIMQChatChannelSyncModeNoSync = 0,
    /// 与频道分组同步
    kNIMQChatChannelSyncModeSync = 1,
};

/** @enum NIMQChatSubscribeOpeType 圈组订阅操作类型 */
enum NIMQChatSubscribeOpeType {
    /// 订阅
    kNIMQChatSubscribeOpeTypeSubscribe = 1,
    /// 取消订阅
    kNIMQChatSubscribeOpeTypeUnsubscribe = 2,
};

/** @enum NIMQChatSubscribeType 圈组订阅类型 */
enum NIMQChatSubscribeType {
    /// 未知
    kNIMQChatSubscribeTypeUnknow = 0,
    /// 订阅某个channel的【消息】/【通知】
    kNIMQChatSubscribeTypeMsg = 1,
    /// 订阅某个channel的【消息未读数】/【通知】
    kNIMQChatSubscribeTypeUnreadCount = 2,
    /// 订阅某个channel的【消息未读状态】/【通知】
    kNIMQChatSubscribeTypeUnreadStatus = 3,
    /// 订阅某个server的【通知】
    kNIMQChatSubscribeTypeServerNotification = 4,
    /// 订阅某个channel的【正在输入事件】
    kNIMQChatSubscribeTypeTypingEvent = 5,
};

static inline bool NIMQChatSubscribeTypeIsServer(NIMQChatSubscribeType type) {
    return type == kNIMQChatSubscribeTypeServerNotification;
};

static inline bool NIMQChatSubscribeTypeIsChannel(NIMQChatSubscribeType type) {
    return type == kNIMQChatSubscribeTypeMsg || type == kNIMQChatSubscribeTypeUnreadCount || type == kNIMQChatSubscribeTypeUnreadStatus ||
           type == kNIMQChatSubscribeTypeTypingEvent;
};

static inline bool NIMQChatSubscribeTypeIsMsg(NIMQChatSubscribeType type) {
    return type == kNIMQChatSubscribeTypeMsg || type == kNIMQChatSubscribeTypeUnreadCount || type == kNIMQChatSubscribeTypeUnreadStatus;
};

/// @enum NIMQChatBanMemberOpeType 圈组封禁操作类型
enum NIMQChatBanMemberOpeType {
    /// 封禁
    kNIMQChatBanMemberOpeTypeBan = 1,
    /// 解除封禁
    kNIMQChatBanMemberOpeTypeUnban = 2,
};

/// @enum NIMQChatSearchOrder 搜索排序顺序
enum NIMQChatSearchOrder {
    /// 按时间正序
    kNIMQChatSearchOrderAsc = 1,
    /// 按时间倒序
    kNIMQChatSearchOrderDesc = 2,
};

/// @enum NIMQChatServerSearchSort 服务器搜索排序规则
enum NIMQChatServerSearchSort {
    /// 自定义权重排序(详见服务器端文档)
    kNIMQChatServerSearchSortCustom = 0,
    /// 创建时间排序
    kNIMQChatServerSearchSortCreateTime = 1,
    /// 服务器总人数排序
    kNIMQChatServerSearchSortMemberCOunt = 2,
};

/// @enum NIMQChatChannelSearchSort 频道搜索排序规则
enum NIMQChatChannelSearchSort {
    /// 自定义权重排序(详见服务器端文档)
    kNIMQChatChannelSearchSortCustom = 0,
    /// 创建时间排序
    kNIMQChatChannelSearchSortCreateTime = 1,
};

/// @enum NIMQChatMessageSearchSort 消息搜索排序规则
enum NIMQChatMessageSearchSort {
    /// 创建时间排序
    kNIMQChatMessageSearchSortCreateTime = 1,
};

/// @struct NIMQChatBaseResp
struct NIMQChatBaseResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
};

/// @struct NIMQChatBusinessAntiSpamInfo
struct NIMQChatBusinessAntiSpamInfo {
    /// 反垃圾文本业务id
    char* text_bid;
    /// 反垃圾图片业务id
    char* pic_bid;
};

/** @struct NIMQChatChannelIdInfo 圈组频道ID信息 */
struct NIMQChatChannelIDInfo {
    /// server id
    uint64_t server_id;
    /// channel id
    uint64_t channel_id;
};

/// @struct NIMQChatMessageUpdateInfo
struct NIMQChatMessageUpdateInfo {
    /// 操作附言
    char* postscript;
    /// 操作扩展字段
    char* extension;
    /// 推送文案
    char* push_content;
    /// 推送payload
    char* push_payload;
    /// 环境变量，用于指向不同的抄送、第三方回调等配置
    char* env;
    /// 是否需要抄送
    bool route_enable;
    // 以下字段仅在收到消息时有效
    /// 操作者账号
    char* operator_id;
    /// 操作者客户端类型
    uint32_t operator_client_type;
};

/// @struct NIMQChatMessageAntiSpamInfo
struct NIMQChatMessageAntiSpamInfo {
    /// 是否需要使用自定义反垃圾字段(即antiSpamContent), false:不需要, true:需要, 默认0, 一般使用的情况是通用反垃圾转易盾
    bool use_custom_content;
    /// 单条消息是否使用易盾反垃圾, false:(在开通易盾的情况下)不过易盾反垃圾, 其他都是按照原来的规则
    bool anti_spam_using_yidun;
    /// 反垃圾内容, 开发者自定义的反垃圾字段, 如果提供了这个字段, 在过反垃圾时不会再使用body或者attach
    char* anti_spam_content;
    /// 反垃圾业务ID, 对某些单条消息另外的反垃圾的业务ID
    char* anti_spam_bussiness_id;
    /// 易盾check的回调URL
    char* yidun_callback_url;
    /// 易盾反垃圾增强反作弊专属字段, 限制json, 长度限制1024
    char* yidun_anti_cheating;
    /// 易盾反垃圾扩展字段, 限制json, 长度限制1024
    char* yidun_anti_spam_ext;
};

/// @struct NIMQChatPageInfo 圈组分页查询信息
struct NIMQChatPageInfo {
    /// 是否还有更多
    bool has_more;
    /// 下一次分页起始时间
    uint64_t next_timestamp;
    /// 下一次分页起始游标
    char* cursor;
};

/** @enum NIMResCode 返回的错误号（只定义需要客户端处理的） */
enum NIMResCode {
    // 通用错误码
    /// 错误
    kNIMResError = 0,
    /// 没有错误，一切正常
    kNIMResSuccess = 200,
    /// 客户端版本不正确
    kNIMResVersionError = 201,
    /// 用户名或密码错误
    kNIMResUidPassError = 302,
    /// 禁止操作
    kNIMResForbidden = 403,
    /// 请求的目标（用户或对象）不存在
    kNIMResNotExist = 404,
    /// 数据自上次查询以来未发生变化（用于增量更新）
    kNIMResNoModify = 406,
    /// 请求过程超时
    kNIMResTimeoutError = 408,
    /// 参数错误
    kNIMResParameterError = 414,
    /// 网络连接出现错误
    kNIMResConnectionError = 415,
    /// 操作太过频繁
    kNIMResFrequently = 416,
    /// 对象已经存在/重复操作
    kNIMResExist = 417,
    /// 超限
    kNIMResOverrun = 419,
    /// 帐号被禁用
    kNIMResAccountBlock = 422,
    /// 未知错误，或者不方便告诉你
    kNIMResUnknownError = 500,
    /// 服务器数据错误
    kNIMResServerDataError = 501,
    /// 服务器太忙
    kNIMResTooBuzy = 503,
    /// 超过配置有效期
    kNIMResExceedLimit = 508,
    /// 协议无效, 不允许访问的协议
    kNIMResInvalid = 509,
    // 群错误码
    /// 已达到人数限制
    kNIMResTeamECountLimit = 801,
    /// 没有权限
    kNIMResTeamENAccess = 802,
    /// 群不存在
    kNIMResTeamENotExist = 803,
    /// 用户不在兴趣组里面
    kNIMResTeamEMemberNotExist = 804,
    /// 群类型不对
    kNIMResTeamErrType = 805,
    /// 创建群数量限制
    kNIMResTeamLimit = 806,
    /// 群成员状态不对
    kNIMResTeamUserStatusErr = 807,
    /// 申请成功
    kNIMResTeamApplySuccess = 808,
    /// 已经在群里
    kNIMResTeamAlreadyIn = 809,
    /// 邀请成功
    kNIMResTeamInviteSuccess = 810,
    /// 强推列表账号数量超限
    kNIMResForcePushCountLimit = 811,
    /// 操作成功，但部分成员的群数量超限
    kNIMResTeamMemberLimit = 813,
    // 数据整解编错误代码
    /// 协议已失效
    kNIMResInvalidProtocol = 997,
    /// 解包错误
    kNIMResEUnpacket = 998,
    /// 打包错误
    kNIMResEPacket = 999,
    /// 被接收方加入黑名单 SDK版本大于2.5.0支持
    kNIMResInBlack = 7101,
    // 客户端自定义的错误号
    /// 值大于该错误号的都是客户端自定义的错误号。不能随意更改其值！
    kNIMLocalRes = 10000,
    /// 客户端本地错误号，需要重新向IM服务器获取进入聊天室权限
    kNIMResRoomLocalNeedRequestAgain = 10001,
    /// 客户端本地错误号，本地网络错误，需要检查本地网络
    kNIMLocalResNetworkError = 10010,
    // 客户端自定义的消息错误号
    /// (发送文件消息或者stop_upload_ex)HTTP upload to NOS上传暂停
    kNIMLocalResMsgNosUploadCancel = 10200,
    /// (收到文件消息或者stop_download_ex)HTTP download from NOS下载暂停
    kNIMLocalResMsgNosDownloadCancel = 10206,
    /// 收到文件消息，NOS下载完成后本地文件检查错误，一般为下载的文件大小与文件信息不符
    kNIMLocalResMsgNosDownloadCheckError = 10207,
    /// 禁止访问
    kNIMLocalResMsgAccessDenied = 10403,
    /// 本地资源不存在
    kNIMLocalResMsgFileNotExist = 10404,
    /// 本地错误码，参数错误，(收到消息，资源下载地址无效，无法下载)
    kNIMLocalResParameterError = 10414,
    /// 本地错误码，操作太过频繁
    kNIMLocalResFrequently = 10416,
    /// 本地错误码，对象已经存在/重复操作，(收到消息，本地资源已存在，不需要重复下载)
    kNIMLocalResExist = 10417,
    /// 发送消息，上传NOS失败
    kNIMLocalResMsgSendNosError = 10502,
    /// 本地错误码,超过配置有效期或者所需参数不存在
    kNIMLocalResExceedLimit = 10508,
    /// 导入消息历史时验证身份和加密密钥不通过
    kNIMLocalResCheckMsgDBFailed = 10600,
    /// 导入消息历史时写记录失败
    kNIMLocalResImportMsgDBFailed = 10601,
    // 客户端自定义的RTS错误号
    /// rts会话 未知错误
    kNIMLocalResRtsError = 11100,
    /// rts会话 id不存在
    kNIMLocalResRtsIdNotExist = 11101,
    /// rts会话 音视频已存在
    kNIMLocalResRtsVChatExist = 11417,
    /// rts会话 通道状态不正确
    kNIMLocalResRtsStatusError = 11501,
    /// rts会话 通道不存在
    kNIMLocalResRtsChannelNotExist = 11510,
    /// 主链接错误
    kNIMResRoomLinkError = 13001,
    /// 聊天室状态异常
    kNIMResRoomError = 13002,
    /// 黑名单用户禁止进入
    kNIMResRoomBlackBeOut = 13003,
    /// 被禁言
    kNIMResRoomBeMuted = 13004,
    /// 聊天室处于整体禁言状态,只有管理员能发言
    kNIMResRoomAllMuted = 13006,
    // 客户端自定义的api调用问题
    /// 还未初始化或初始化未正常完成
    kNIMLocalResAPIErrorInitUndone = 20000,
    /// 还未登陆或登录未完成
    kNIMLocalResAPIErrorLoginUndone = 20001,
    /// 已经登录
    kNIMLocalResAPIErrorLogined = 20002,
    /// SDK版本不对，可能会引发其他问题
    kNIMLocalResAPIErrorVersionError = 20003,
    /// 聊天室模式混用错误，不支持同时以登陆状态和匿名状态登陆聊天室
    kNIMLocalResAPIErrorChatroomMixError = 20004,
    /// 连接地址用完了
    kNIMLocalResAPIErrorRunOutOfLinkAddress = 20005,
};

/// @struct NIMQChatUnreadInfo 圈组频道未读信息
struct NIMQChatUnreadInfo {
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 已读时间戳
    uint64_t ack_timestamp;
    /// 未读数
    uint64_t unread_count;
    /// 被@未读数
    uint64_t mentioned_unread_count;
    /// 订阅未读数时的最大未读数
    uint64_t max_unread_count;
    /// 最后一条消息时间戳
    uint64_t last_msg_timestamp;
};

/// @struct NIMQChatServerUnreadInfo 圈组服务器未读信息
struct NIMQChatServerUnreadInfo {
    /// 服务器ID
    uint64_t server_id;
    /// 未读数
    uint64_t unread_count;
    /// 被@未读数
    uint64_t mentioned_unread_count;
    /// 订阅未读数时的最大未读数
    uint64_t max_unread_count;
};

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_PUBLIC_DEF_H__
