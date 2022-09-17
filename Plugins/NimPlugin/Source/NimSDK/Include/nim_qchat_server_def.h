/**
 * @file nim_qchat_server_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SERVER_DEF_H__
#define __NIM_QCHAT_SERVER_DEF_H__

#include "nim_qchat_member_def.h"
#include "nim_qchat_public_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @enum NIMQChatServerInviteMode
enum NIMQChatServerInviteMode {
    /// 需要验证
    kNIMQChatServerInviteModeNeedConfirm,
    kNIMQChatServerInviteModeNormal  // 不需要验证
};

/// @enum NIMQChatServerApplyMode
enum NIMQChatServerApplyMode {
    /// 不需要验证
    kNIMQChatServerApplyModeNormal,
    /// 需要验证
    kNIMQChatServerApplyModeNeedConfirm,
};

/// @enum NIMQChatServerInviteFailReason
enum NIMQChatServerInviteFailReason {
    /// 服务器人数超过限制
    kNIMQChatServerInviteFailReasonExceedLimit = 1,
    /// 被封禁
    kNIMQChatServerInviteFailReasonBanned = 2,
};

/// @enum NIMQChatServerSearchType
enum NIMQChatServerSearchType {
    /// 广场搜索
    kNIMQChatServerSearchTypeSquare = 1,
    /// 个人服务器搜索
    kNIMQChatServerSearchTypePersonal = 2,
};

/** @struct NIMQChatServerInfo 圈组服务器信息 */
struct NIMQChatServerInfo {
    /// server id
    uint64_t server_id;
    /// 用户自定义服务器类别, 0表示无类别
    uint32_t server_type;
    /// 是否能被搜索
    bool searchable;
    /// 名称
    char* name;
    /// 图标 url
    char* icon;
    /// 自定义字段
    char* custom;
    /// 所有者 id
    char* owner_id;
    /// 成员数量
    uint64_t member_count;
    /// 邀请模式
    NIMQChatServerInviteMode invite_mode;
    /// 申请模式
    NIMQChatServerApplyMode apply_mode;
    /// 有效标记，false:无效 true:有效
    bool valid_flag;
    /// 该服务器下频道总数
    uint32_t channel_count;
    /// 总频道分组数量
    uint32_t channel_category_count;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
    /// 自定义排序权重值
    uint64_t reorder_weight;
};

/// @enum NIMQChatInviteApplyRecordType
enum NIMQChatInviteApplyRecordType {
    /// 申请
    kNIMQChatInviteApplyRecordTypeApply = 1,
    /// 邀请
    kNIMQChatInviteApplyRecordTypeInvite = 2,
    /// 被邀请
    kNIMQChatInviteApplyRecordTypeBeInvited = 3,
    /// 生成邀请码
    kNIMQChatInviteApplyRecordTypeGenerateInviteCode = 4,
    /// 通过邀请码加入
    kNIMQChatInviteApplyRecordTypeJoinByInviteCode = 5,
};

/// @enum NIMQChatInviteApplyRecordStatus
enum NIMQChatInviteApplyRecordStatus {
    /// 初始状态
    kNIMQChatInviteApplyRecordStatusInitial = 0,
    /// 同意
    kNIMQChatInviteApplyRecordStatusApprove = 1,
    /// 拒绝
    kNIMQChatInviteApplyRecordStatusReject = 2,
    /// 通过其他请求同意
    kNIMQChatInviteApplyRecordStatusApproveByOtherRequest = 3,
    /// 通过其他请求拒绝
    kNIMQChatInviteApplyRecordStatusRejectByOtherRequest = 4,
    /// 邀请/申请时自动加入
    kNIMQChatInviteApplyRecordStatusAutoJoin = 5,
    /// 过期
    kNIMQChatInviteApplyRecordStatusExpired = 6,
};

/// @struct NIMQChatApplyInfoData 圈组申请信息数据
struct NIMQChatApplyInfoData {
    /// 申请附言
    char* apply_postscript;
    /// 更新者 id
    char* update_accid;
    /// 更新附言
    char* update_postscript;
};

/// @struct NIMQChatInviteUserInfo 圈组邀请用户信息
struct NIMQChatInviteUserInfo {
    /// accid
    char* accid;
    /// 更新附言
    char* update_postscript;
    /// 状态
    NIMQChatInviteApplyRecordStatus status;
    /// 更新时间
    uint64_t update_time;
};

/// @struct NIMQChatInviteInfoData 圈组邀请信息数据
struct NIMQChatInviteInfoData {
    /// 邀请附言
    char* invite_postscript;
    /// 邀请成员信息列表
    NIMQChatInviteUserInfo* invite_user_infos;
    /// 邀请成员信息列表数量
    size_t invite_user_infos_count;
};

/// @struct NIMQChatBeInvitedInfoData 圈组被邀请信息数据
struct NIMQChatBeInvitedInfoData {
    /// 邀请附言
    char* invite_postscript;
    /// 更新附言
    char* update_postscript;
};

/// @struct NIMQChatGenerateInviteCodeInfoData 圈组生成邀请码信息数据
struct NIMQChatGenerateInviteCodeInfoData {
    /// 邀请附言
    char* invite_postscript;
    /// 邀请码
    char* invite_code;
    /// 邀请人数
    uint32_t invite_count;
};

/// @struct NIMQChatJoinByInviteCodeInfoData 圈组通过邀请码加入信息数据
struct NIMQChatJoinByInviteCodeInfoData {
    /// 邀请附言
    char* invite_postscript;
    /// 更新附言
    char* update_postscript;
    /// 邀请码
    char* invite_code;
};

/// @struct NIMQChatInviteApplyRecord 圈组邀请申请信息
struct NIMQChatInviteApplyRecord {
    /// accid
    char* accid;
    /// type
    NIMQChatInviteApplyRecordType type;
    /// 服务器ID
    uint64_t server_id;
    /// 状态
    NIMQChatInviteApplyRecordStatus status;
    /// 请求ID
    uint64_t request_id;
    /// 记录ID
    uint64_t record_id;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
    /// 过期时间
    uint64_t expire_time;
    /// 邀请申请信息原始Json数据
    char* raw_data;
    union {
        /// 申请数据
        NIMQChatApplyInfoData apply_data;
        /// 邀请数据
        NIMQChatInviteInfoData invite_data;
        /// 被邀请数据
        NIMQChatBeInvitedInfoData be_invited_data;
        /// 生成邀请码数据
        NIMQChatGenerateInviteCodeInfoData generate_invite_code_data;
        /// 通过邀请码加入数据
        NIMQChatJoinByInviteCodeInfoData join_by_invite_code_data;
    };
};

/// @struct NIMQChatServerCreateResp
struct NIMQChatServerCreateResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    NIMQChatServerInfo server_info;
};

/// @struct NIMQChatServerDeleteResp
typedef NIMQChatBaseResp NIMQChatServerDeleteResp;

/// @struct NIMQChatServerUpdateResp
typedef NIMQChatServerCreateResp NIMQChatServerUpdateResp;

/// @struct NIMQChatServerGetServersResp
struct NIMQChatServerGetServersResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 服务器列表数量
    size_t server_list_count;
    /// 服务器列表
    NIMQChatServerInfo* server_list;
};

/// @struct NIMQChatServerGetServersPageResp
struct NIMQChatServerGetServersPageResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 服务器列表数量
    size_t server_list_count;
    /// 服务器列表
    NIMQChatServerInfo* server_list;
};

/// @struct NIMQChatServerInviteResp
struct NIMQChatServerInviteResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 请求ID
    uint64_t request_id;
    /// 过期时间
    uint64_t expire_time;
    /// 邀请失败 id 列表数量
    size_t accids_count;
    /// 邀请失败 id 列表
    char** accids;
    /// 邀请失败原因列表
    NIMQChatServerInviteFailReason* fail_reasons;
};

/// @struct NIMQChatServerAcceptInviteResp
typedef NIMQChatBaseResp NIMQChatServerAcceptInviteResp;

/// @struct NIMQChatServerRejectInviteResp
typedef NIMQChatBaseResp NIMQChatServerRejectInviteResp;

/// @struct NIMQChatServerApplyResp
struct NIMQChatServerApplyResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 请求ID
    uint64_t request_id;
    /// 过期时间
    uint64_t expire_time;
};

/// @struct NIMQChatServerAcceptApplyResp
typedef NIMQChatBaseResp NIMQChatServerAcceptApplyResp;

/// @struct NIMQChatServerRejectApplyResp
typedef NIMQChatBaseResp NIMQChatServerRejectApplyResp;

/// @struct NIMQChatServerKickResp
typedef NIMQChatBaseResp NIMQChatServerKickResp;

/// @struct NIMQChatServerLeaveResp
typedef NIMQChatBaseResp NIMQChatServerLeaveResp;

/// @struct NIMQChatServerUpdateMemberInfoResp
typedef NIMQChatBaseResp NIMQChatServerUpdateMemberInfoResp;

/// @struct NIMQChatServerGetMembersResp
struct NIMQChatServerGetMembersResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员信息列表数量
    size_t member_list_count;
    /// 成员信息列表
    NIMQChatMemberInfo* member_list;
};

/// @struct NIMQChatServerGetMembersPageResp
struct NIMQChatServerGetMembersPageResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 成员信息列表数量
    size_t member_list_count;
    /// 成员信息列表
    NIMQChatMemberInfo* member_list;
};

/// @struct NIMQChatServerSubscribeResp
struct NIMQChatServerSubscribeResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 订阅失败列表
    uint64_t* failed_servers;
    /// 订阅失败列表数量
    size_t failed_servers_count;
};

/// @struct NIMQChatServerBanMemberResp
typedef NIMQChatBaseResp NIMQChatServerBanMemberResp;

/// @struct NIMQChatServerUnbanMemberResp
typedef NIMQChatBaseResp NIMQChatServerUnbanMemberResp;

/// @struct NIMQChatServerGetBannedMembersPageResp
struct NIMQChatServerGetBannedMembersPageResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 封禁成员信息列表数量
    size_t ban_list_count;
    /// 封禁成员信息列表
    NIMQChatMemberBanInfo* ban_list;
};

/// @struct NIMQChatServerSearchPageResp
typedef NIMQChatServerGetServersPageResp NIMQChatServerSearchPageResp;

/// @struct NIMQChatServerMemberSearchResp
typedef NIMQChatServerGetMembersResp NIMQChatServerMemberSearchResp;

/// @struct NIMQChatServerUnreadResp
struct NIMQChatServerUnreadResp {
    /// 自定义用户数据
    void* user_data;
    /// 未读数信息列表长度
    size_t unread_infos_count;
    /// 未读数信息列表
    NIMQChatServerUnreadInfo* unread_infos;
};

/// @struct NIMQChatServerGenerateInviteCodeResp
struct NIMQChatServerGenerateInviteCodeResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 请求ID
    uint64_t request_id;
    /// 邀请码
    char* invite_code;
    /// 过期时间
    uint64_t expire_time;
};

/// @struct NIMQChatServerJoinByInviteCodeResp
typedef NIMQChatBaseResp NIMQChatServerJoinByInviteCodeResp;

/// @struct NIMQChatServerGetInviteApplyRecordOfServerResp
struct NIMQChatServerGetInviteApplyRecordOfServerResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 邀请申请历史列表数量
    size_t invite_apply_records_count;
    /// 邀请申请历史列表
    NIMQChatInviteApplyRecord* invite_apply_records;
};

/// @struct NIMQChatServerGetInviteApplyRecordOfSelfResp
typedef NIMQChatServerGetInviteApplyRecordOfServerResp NIMQChatServerGetInviteApplyRecordOfSelfResp;

/// @struct NIMQChatServerMarkReadResp
struct NIMQChatServerMarkReadResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 订阅成功列表
    uint64_t* succeeded_servers;
    /// 订阅成功列表数量
    size_t succeeded_servers_count;
    /// 订阅失败列表
    uint64_t* failed_servers;
    /// 订阅失败列表数量
    size_t failed_servers_count;
    /// 标记已读时间戳
    uint64_t timestamp;
};

/// @struct NIMQChatServerSubscribeAllChannelResp
struct NIMQChatServerSubscribeAllChannelResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 订阅失败列表
    uint64_t* failed_servers;
    /// 订阅失败列表数量
    size_t failed_servers_count;
    /// 频道未读信息, 内部使用，未读相关变更关注RegUnreadCb回调
    NIMQChatUnreadInfo* unread_infos;
    /// 频道未读信息数量
    size_t unread_infos_count;
};

/* ----------------------------- 接口回调模板 ------------------------------- */
/// 未读数回调
typedef void (*nim_qchat_server_unread_cb_func)(const NIMQChatServerUnreadResp& resp);
/// 创建服务回调
typedef void (*nim_qchat_server_create_cb_func)(const NIMQChatServerCreateResp& resp);
/// 删除服务回调
typedef void (*nim_qchat_server_remove_cb_func)(const NIMQChatServerDeleteResp& resp);
/// 更新服务回调
typedef void (*nim_qchat_server_update_cb_func)(const NIMQChatServerUpdateResp& resp);
/// 查询服务列表回调
typedef void (*nim_qchat_server_get_servers_cb_func)(const NIMQChatServerGetServersResp& resp);
/// 查询服务列表分页回调
typedef void (*nim_qchat_server_get_servers_page_cb_func)(const NIMQChatServerGetServersPageResp& resp);
/// 邀请回调
typedef void (*nim_qchat_server_invite_cb_func)(const NIMQChatServerInviteResp& resp);
/// 接受邀请回调
typedef void (*nim_qchat_server_accept_invite_cb_func)(const NIMQChatServerAcceptInviteResp& resp);
/// 拒绝邀请回调
typedef void (*nim_qchat_server_reject_invite_cb_func)(const NIMQChatServerRejectInviteResp& resp);
/// 申请回调
typedef void (*nim_qchat_server_apply_cb_func)(const NIMQChatServerApplyResp& resp);
/// 接受申请回调
typedef void (*nim_qchat_server_accept_apply_cb_func)(const NIMQChatServerAcceptApplyResp& resp);
/// 拒绝申请回调
typedef void (*nim_qchat_server_reject_apply_cb_func)(const NIMQChatServerRejectApplyResp& resp);
/// 踢人回调
typedef void (*nim_qchat_server_kick_cb_func)(const NIMQChatServerKickResp& resp);
/// 离开回调
typedef void (*nim_qchat_server_leave_cb_func)(const NIMQChatServerLeaveResp& resp);
/// 更新成员信息回调
typedef void (*nim_qchat_server_update_member_info_cb_func)(const NIMQChatServerUpdateMemberInfoResp& resp);
/// 查询成员列表回调
typedef void (*nim_qchat_server_get_members_cb_func)(const NIMQChatServerGetMembersResp& resp);
/// 查询成员列表分页回调
typedef void (*nim_qchat_server_get_members_page_cb_func)(const NIMQChatServerGetMembersPageResp& resp);
/// 订阅回调
typedef void (*nim_qchat_server_subscribe_cb_func)(const NIMQChatServerSubscribeResp& resp);
/// 封禁成员回调
typedef void (*nim_qchat_server_ban_member_cb_func)(const NIMQChatServerBanMemberResp& resp);
/// 解封成员回调
typedef void (*nim_qchat_server_unban_member_cb_func)(const NIMQChatServerUnbanMemberResp& resp);
/// 查询封禁成员列表回调
typedef void (*nim_qchat_server_get_banned_members_page_cb_func)(const NIMQChatServerGetBannedMembersPageResp& resp);
/// 搜索服务器分页回调
typedef nim_qchat_server_get_servers_page_cb_func nim_qchat_server_search_page_cb_func;
/// 搜索成员分页回调
typedef nim_qchat_server_get_members_cb_func nim_qchat_server_member_search_cb_func;
/// 生成邀请码回调
typedef void (*nim_qchat_server_generate_invite_code_cb_func)(const NIMQChatServerGenerateInviteCodeResp& resp);
/// 通过邀请码加入回调
typedef void (*nim_qchat_server_join_by_invite_code_cb_func)(const NIMQChatServerJoinByInviteCodeResp& resp);
/// 查询服务器下的申请邀请记录回调
typedef void (*nim_qchat_server_get_invite_apply_record_of_server_cb_func)(const NIMQChatServerGetInviteApplyRecordOfServerResp& resp);
/// 查询自己的申请邀请记录回调
typedef void (*nim_qchat_server_get_invite_apply_record_by_self_cb_func)(const NIMQChatServerGetInviteApplyRecordOfSelfResp& resp);
/// 服务器标记已读
typedef void (*nim_qchat_server_mark_read_cb_func)(const NIMQChatServerMarkReadResp& resp);
/// 订阅所有频道
typedef void (*nim_qchat_server_subscribe_all_channel_cb_func)(const NIMQChatServerSubscribeAllChannelResp& resp);

/* ----------------------------- 接口调用参数 ----------------------------- */
/// @struct NIMQChatServerRegUnreadCbParam
struct NIMQChatServerRegUnreadCbParam {
    nim_qchat_server_unread_cb_func cb;
    void* user_data;
};

/// @struct NIMQChatServerCreateParam
struct NIMQChatServerCreateParam {
    /// 创建会话异步回调
    nim_qchat_server_create_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器信息
    NIMQChatServerInfo server_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
};

/// @struct NIMQChatServerDeleteParam
struct NIMQChatServerDeleteParam {
    /// 删除会话异步回调
    nim_qchat_server_remove_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
};

/// @struct NIMQChatServerUpdateParam
struct NIMQChatServerUpdateParam {
    /// 更新会话异步回调
    nim_qchat_server_update_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器信息
    NIMQChatServerInfo server_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
};

/// @struct NIMQChatServerGetServersParam
struct NIMQChatServerGetServersParam {
    /// 查询会话列表异步回调
    nim_qchat_server_get_servers_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id 列表长度
    size_t server_ids_count;
    /// 服务器 id 列表
    uint64_t* server_ids;
};

/// @struct NIMQChatServerGetServersPageParam
struct NIMQChatServerGetServersPageParam {
    /// 查询会话列表分页异步回调
    nim_qchat_server_get_servers_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatServerInviteParam
struct NIMQChatServerInviteParam {
    /// 邀请异步回调
    nim_qchat_server_invite_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 受邀人 id 列表
    char** invite_ids;
    /// 受邀人 id 列表长度
    size_t invite_ids_count;
    /// 请求生存时间 ms
    uint64_t ttl;
    /// 附言
    char* postscript;
};

/// @struct NIMQChatServerAcceptInviteParam
struct NIMQChatServerAcceptInviteParam {
    /// 接受邀请异步回调
    nim_qchat_server_accept_invite_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 邀请人 id
    char* accid;
    /// 请求ID
    uint64_t request_id;
};

/// @struct NIMQChatServerRejectInviteParam
struct NIMQChatServerRejectInviteParam {
    /// 拒绝邀请异步回调
    nim_qchat_server_reject_invite_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 邀请人 id
    char* accid;
    /// 附言
    char* postscript;
    /// 请求ID
    uint64_t request_id;
};

/// @struct NIMQChatServerApplyParam
struct NIMQChatServerApplyParam {
    /// 申请加入异步回调
    nim_qchat_server_apply_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 请求生存时间 ms
    uint64_t ttl;
    /// 附言
    char* postscript;
};

/// @struct NIMQChatServerAcceptApplyParam
struct NIMQChatServerAcceptApplyParam {
    /// 接受申请异步回调
    nim_qchat_server_accept_apply_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 申请人 id
    char* accid;
    /// 请求ID
    uint64_t request_id;
};

/// @struct NIMQChatServerRejectApplyParam
struct NIMQChatServerRejectApplyParam {
    /// 拒绝申请异步回调
    nim_qchat_server_reject_apply_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 申请人 id
    char* accid;
    /// 附言
    char* postscript;
    /// 请求ID
    uint64_t request_id;
};

/// @struct NIMQChatServerKickParam
struct NIMQChatServerKickParam {
    /// 踢人异步回调
    nim_qchat_server_kick_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 被踢人 id 列表
    char** accids;
    /// 被踢人 id 列表长度
    size_t accids_count;
};

/// @struct NIMQChatServerLeaveParam
struct NIMQChatServerLeaveParam {
    /// 离开异步回调
    nim_qchat_server_leave_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
};

/// @struct NIMQChatServerUpdateMemberInfoParam
struct NIMQChatServerUpdateMemberInfoParam {
    /// 更新成员信息异步回调
    nim_qchat_server_update_member_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 成员信息
    NIMQChatMemberInfo member_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
};

/// @struct NIMQChatServerMemberPair
struct NIMQChatServerMemberPair {
    uint64_t server_id;
    char* accid;
};

/// @struct NIMQChatServerGetMembersParam
struct NIMQChatServerGetMembersParam {
    /// 查询成员列表异步回调
    nim_qchat_server_get_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器id和accid列表
    NIMQChatServerMemberPair* server_accid_list;
    /// 服务器id和accid列表长度
    size_t server_accid_list_count;
};

/// @struct NIMQChatServerGetMembersPageParam
struct NIMQChatServerGetMembersPageParam {
    /// 查询成员列表异步回调
    nim_qchat_server_get_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatServerSubscribeParam
struct NIMQChatServerSubscribeParam {
    /// 订阅频道信息回调函数
    nim_qchat_server_subscribe_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 操作类型
    NIMQChatSubscribeOpeType ope_type;
    /// 订阅类型
    NIMQChatSubscribeType sub_type;
    /// 服务器 id 列表长度
    size_t server_ids_count;
    /// 服务器 id 列表
    uint64_t* server_ids;
};

/// @struct NIMQChatServerBanMemberParam
struct NIMQChatServerBanMemberParam {
    /// 封禁成员异步回调
    nim_qchat_server_ban_member_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 用户id
    char* accid;
    /// 自定义字段
    char* custom;
};

/// @struct NIMQChatServerUnbanMemberParam
struct NIMQChatServerUnbanMemberParam {
    /// 解封成员异步回调
    nim_qchat_server_unban_member_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 用户id
    char* accid;
    /// 自定义字段
    char* custom;
};

/// @struct NIMQChatServerGetBannedMembersPageParam
struct NIMQChatServerGetBannedMembersPageParam {
    /// 查询封禁成员列表异步回调
    nim_qchat_server_get_banned_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatServerSearchPageParam
struct NIMQChatServerSearchPageParam {
    /// 搜索异步回调
    nim_qchat_server_search_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 搜索内容
    char* keyword;
    /// 起始时间
    uint64_t start_time;
    /// 结束时间
    uint64_t end_time;
    /// 排序顺序
    NIMQChatSearchOrder order;
    /// 排序规则
    NIMQChatServerSearchSort sort;
    /// 搜索的服务器类型, 为空表示搜索所有类型
    uint32_t* server_types;
    /// 服务器类型长度
    size_t server_types_count;
    /// 搜索类型
    NIMQChatServerSearchType search_type;
    /// 查询条数
    uint32_t limit;
    /// 查询游标, 查询的起始位置
    char* cursor;
};

/// @struct NIMQChatServerMemberSearchParam
struct NIMQChatServerMemberSearchParam {
    /// 搜索异步回调
    nim_qchat_server_member_search_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 搜索内容
    char* keyword;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatServerGenerateInviteCodeParam
struct NIMQChatServerGenerateInviteCodeParam {
    /// 生成邀请码异步回调
    nim_qchat_server_generate_invite_code_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 请求生存时间 ms
    uint64_t ttl;
};

/// @struct NIMQChatServerJoinByInviteCodeParam
struct NIMQChatServerJoinByInviteCodeParam {
    /// 通过邀请码加入异步回调
    nim_qchat_server_join_by_invite_code_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 邀请码
    char* invite_code;
    /// 附言
    char* postscript;
};

/// @struct NIMQChatServerGetInviteApplyRecordOfServerParam
struct NIMQChatServerGetInviteApplyRecordOfServerParam {
    /// 查询服务器下邀请申请历史异步回调
    nim_qchat_server_get_invite_apply_record_of_server_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 起始时间
    uint64_t start_time;
    /// 结束时间
    uint64_t end_time;
    /// 是否倒序, false: 否, true: 是
    bool reverse;
    /// 查询条数
    uint32_t limit;
    /// 要排除的记录id
    uint64_t exclude_record_id;
};

/// @struct NIMQChatServerGetInviteApplyRecordOfSelfParam
struct NIMQChatServerGetInviteApplyRecordOfSelfParam {
    /// 查询自己邀请申请历史异步回调
    nim_qchat_server_get_invite_apply_record_by_self_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 起始时间
    uint64_t start_time;
    /// 结束时间
    uint64_t end_time;
    /// 是否倒序, false: 否, true: 是
    bool reverse;
    /// 查询条数
    uint32_t limit;
    /// 要排除的记录id
    uint64_t exclude_record_id;
};

/// @struct NIMQChatServerMarkReadParam
struct NIMQChatServerMarkReadParam {
    /// 标记服务器下消息已读异步回调
    nim_qchat_server_mark_read_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id 列表
    uint64_t* server_ids;
    /// 服务器 id 列表长度
    size_t server_ids_count;
};

/// @struct NIMQChatServerSubscribeAllChannelParam
struct NIMQChatServerSubscribeAllChannelParam {
    /// 订阅所有频道异步回调
    nim_qchat_server_subscribe_all_channel_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 订阅类型
    NIMQChatSubscribeType sub_type;
    /// 服务器 id 列表
    uint64_t* server_ids;
    /// 服务器 id 列表长度
    size_t server_ids_count;
};

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_SERVER_DEF_H__
