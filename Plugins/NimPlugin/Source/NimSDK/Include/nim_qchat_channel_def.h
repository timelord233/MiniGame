/**
 * @file nim_qchat_channel_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_CHANNEL_DEF_H__
#define __NIM_QCHAT_CHANNEL_DEF_H__

#include "nim_qchat_member_def.h"
#include "nim_qchat_public_def.h"
#include "nim_qchat_role_def.h"
#include "nim_qchat_server_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @enum NIMQChatChannelType 圈组频道类型
enum NIMQChatChannelType {
    /// 普通文本频道
    kNIMQChatChannelTypeText,
    /// RTC频道
    kNIMQChatChannelTypeRTC,
    /// 自定义频道类型
    kNIMQChatChannelTypeCustom = 100
};

/// @enum NIMQChatChannelMemberIdentifyType
enum NIMQChatChannelMemberIdentifyType {
    kNIMQChatWhite = 1,
    kNIMQChatBlack = 2,
};

/// @enum NIMQChatChannelMemberIdentifyOpeType
enum NIMQChatChannelMemberIdentifyOpeType {
    kNIMQChatChannelMemberIdentifyOpeTypeAdd = 1,
    kNIMQChatChannelMemberIdentifyOpeTypeRemove = 2,
};

/// @enum NIMQChatChannelWhiteBlackType
enum NIMQChatChannelWhiteBlackType {
    kNIMQChatChannelWhite = 1,
    kNIMQChatChannelBlack = 2,
};

/// @enum NIMQChatChannelWhiteBlackOpeType
enum NIMQChatChannelWhiteBlackOpeType {
    kNIMQChatChannelWhiteBlackOpeTypeAdd = 1,
    kNIMQChatChannelWhiteBlackOpeTypeRemove = 2,
};

/// @struct NIMQChatChannelInfo 圈组频道信息
struct NIMQChatChannelInfo {
    /// server id
    uint64_t server_id;
    /// channel id
    uint64_t channel_id;
    /// 名称
    char* name;
    /// 主题
    char* topic;
    /// 自定义字段
    char* custom;
    /// 频道类型
    NIMQChatChannelType type;
    /// 拥有者
    char* owner;
    /// 查看模式，只有在category_id为0或sync_mode为kNIMQChatChannelSyncModeNoSync时有效
    NIMQChatChannelViewMode view_mode;
    /// 有效标记，false:无效 true:有效
    bool valid_flag;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
    /// 频道分组ID
    uint64_t category_id;
    /// 频道分组同步模式
    NIMQChatChannelSyncMode sync_mode;
    /// 自定义排序权重值
    uint64_t reorder_weight;
};

/// @struct NIMQChatChannelRTCAudioInfo 圈组RTC频道音频信息
struct NIMQChatChannelRTCAudioInfo {
    /// 音频属性
    char* profile;
    /// 音频应用场景
    char* scenario;
};

/// @struct NIMQChatChannelRTCVideoInfo 圈组RTC频道视频信息
struct NIMQChatChannelRTCVideoInfo {
    /// 分辨率宽
    uint32_t width;
    /// 分辨率高
    uint32_t height;
    /// 帧率
    uint32_t fps;
};

/// @struct NIMQChatChannelRTCInfo 圈组频道RTC信息
struct NIMQChatChannelRTCInfo {
    /// 在线人数限制
    uint32_t limit;
    /// 音频配置
    NIMQChatChannelRTCAudioInfo audio;
    /// 视频配置
    NIMQChatChannelRTCVideoInfo video;
};

/// @struct NIMQChatChannelCategoryInfo
struct NIMQChatChannelCategoryInfo {
    /// 服务器ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 名称
    char* name;
    /// 自定义字段
    char* custom;
    /// 拥有者
    char* owner;
    /// 查看模式
    NIMQChatChannelViewMode view_mode;
    /// 有效标记，false:无效 true:有效
    bool valid_flag;
    /// 创建时间
    uint64_t create_time;
    /// 更新时间
    uint64_t update_time;
};

/// @struct NIMQChatChannelCreateResp
struct NIMQChatChannelCreateResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 频道信息
    NIMQChatChannelInfo channel_info;
};

/// @struct NIMQChatChannelUpdateResp
typedef NIMQChatChannelCreateResp NIMQChatChannelUpdateResp;

/// @struct NIMQChatChannelUpdateCategoryInfoResp
typedef NIMQChatChannelCreateResp NIMQChatChannelUpdateCategoryInfoResp;

/// @struct NIMQChatChannelDeleteResp
typedef NIMQChatBaseResp NIMQChatChannelDeleteResp;

/// @struct NIMQChatChannelGetChannelsResp
struct NIMQChatChannelGetChannelsResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 频道列表数量
    size_t channel_list_count;
    /// 频道列表
    NIMQChatChannelInfo* channel_list;
};

/// @struct NIMQChatChannelGetChannelsPageResp
struct NIMQChatChannelGetChannelsPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 频道列表数量
    size_t channel_list_count;
    /// 频道列表
    NIMQChatChannelInfo* channel_list;
};

/// @struct NIMQChatChannelGetMembersPageResp
typedef NIMQChatServerGetMembersPageResp NIMQChatChannelGetMembersPageResp;

/// @struct NIMQChatChannelQueryUnreadInfoResp
struct NIMQChatChannelQueryUnreadInfoResp {
    NIMQChatUnreadInfo* unread_infos;
    size_t unread_info_count;
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
};

/// @struct NIMQChatChannelSubscribeResp
struct NIMQChatChannelSubscribeResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 订阅失败列表
    NIMQChatChannelIDInfo* failed_channels;
    /// 订阅失败列表数量
    size_t failed_channels_count;
    /// 频道未读信息, 内部使用，未读相关变更关注RegUnreadCb回调
    NIMQChatUnreadInfo* unread_infos;
    /// 频道未读信息数量
    size_t unread_infos_count;
};

/// @struct NIMQChatChannelUnreadResp
struct NIMQChatChannelUnreadResp {
    /// 自定义用户数据
    void* user_data;
    /// 未读数信息数量
    size_t unread_infos_count;
    /// 未读数信息
    NIMQChatUnreadInfo* unread_infos;
};

/// @struct NIMQChatChannelUpdateWhiteBlackRoleResp
typedef NIMQChatBaseResp NIMQChatChannelUpdateWhiteBlackRoleResp;

/// @struct NIMQChatChannelUpdateWhiteBlackMembersResp
typedef NIMQChatBaseResp NIMQChatChannelUpdateWhiteBlackMembersResp;

/// @struct NIMQChatChannelGetWhiteBlackRolesPageResp
struct NIMQChatChannelGetWhiteBlackRolesPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
};

/// @struct NIMQChatChannelGetWhiteBlackMembersPageResp
struct NIMQChatChannelGetWhiteBlackMembersPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
};

/// @struct NIMQChatChannelGetExistingWhiteBlackRolesResp
struct NIMQChatChannelGetExistingWhiteBlackRolesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
};

/// @struct NIMQChatChannelGetExistingWhiteBlackMembersResp
struct NIMQChatChannelGetExistingWhiteBlackMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
};

/// @struct NIMQChatChannelSearchPageResp
typedef NIMQChatChannelGetChannelsPageResp NIMQChatChannelSearchPageResp;

/// @struct NIMQChatChannelMemberSearchResp
struct NIMQChatChannelMemberSearchResp {
    /// 操作结果, 参考 NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员信息列表数量
    size_t member_list_count;
    /// 成员信息列表
    NIMQChatMemberInfo* member_list;
};

/// @struct NIMQChatChannelCategoryCreateResp
struct NIMQChatChannelCategoryCreateResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 频道分组信息
    NIMQChatChannelCategoryInfo category_info;
};

/// @struct NIMQChatChannelCategoryRemoveResp
typedef NIMQChatBaseResp NIMQChatChannelCategoryRemoveResp;

/// @struct NIMQChatChannelCategoryUpdateResp
typedef NIMQChatChannelCategoryCreateResp NIMQChatChannelCategoryUpdateResp;

/// @struct NIMQChatChannelGetCategoriesByIDResp
struct NIMQChatChannelGetCategoriesByIDResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分组列表
    NIMQChatChannelCategoryInfo* categories;
    /// 分组数量
    size_t category_count;
};

/// @struct NIMQChatChannelGetCategoriesPageResp
struct NIMQChatChannelGetCategoriesPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 分组列表
    NIMQChatChannelCategoryInfo* categories;
    /// 分组数量
    size_t category_count;
};

/// @struct NIMQChatChannelGetCategoryChannelsResp
typedef NIMQChatChannelGetChannelsPageResp NIMQChatChannelGetCategoryChannelsPageResp;

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackRoleResp
typedef NIMQChatBaseResp NIMQChatChannelCategoryUpdateWhiteBlackRoleResp;

/// @struct NIMQChatChannelCategoryGetWhiteBlackRolesPageResp
struct NIMQChatChannelCategoryGetWhiteBlackRolesPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
};

/// @struct NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp
struct NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 身份组列表
    NIMQChatRoleInfo* roles;
    /// 身份组数量
    size_t role_count;
};

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackMembersResp
typedef NIMQChatBaseResp NIMQChatChannelCategoryUpdateWhiteBlackMembersResp;

/// @struct NIMQChatChannelCategoryGetWhiteBlackMembersPageResp
struct NIMQChatChannelCategoryGetWhiteBlackMembersPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 分页信息
    NIMQChatPageInfo page_info;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
};

/// @struct NIMQChatChannelCategoryGetWhiteBlackMembersResp
struct NIMQChatChannelCategoryGetWhiteBlackMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
};

/// @struct NIMQChatChannelUpdateRTCInfoResp
typedef NIMQChatBaseResp NIMQChatChannelUpdateRTCInfoResp;

/// @struct NIMQChatChannelGetRTCInfoResp
struct NIMQChatChannelGetRTCInfoResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// RTC信息
    NIMQChatChannelRTCInfo rtc_info;
};

/// @struct NIMQChatChannelGetRTCOnlineMembersResp
struct NIMQChatChannelGetRTCOnlineMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code;
    /// 自定义用户数据
    void* user_data;
    /// 成员列表
    NIMQChatMemberInfo* members;
    /// 成员数量
    size_t member_count;
};

/* ------------------------------- 接口回调模板 -------------------------------- */
/// 未读数回调
typedef void (*nim_qchat_channel_unread_cb_func)(const NIMQChatChannelUnreadResp& resp);
/// 创建频道回调
typedef void (*nim_qchat_channel_create_cb_func)(const NIMQChatChannelCreateResp& resp);
/// 删除频道回调
typedef void (*nim_qchat_channel_remove_cb_func)(const NIMQChatChannelDeleteResp& resp);
/// 更新频道回调
typedef void (*nim_qchat_channel_update_cb_func)(const NIMQChatChannelUpdateResp& resp);
/// 更新频道的分组信息回调
typedef void (*nim_qchat_channel_update_category_info_cb_func)(const NIMQChatChannelUpdateCategoryInfoResp& resp);
/// 查询频道列表回调
typedef void (*nim_qchat_channel_get_channels_cb_func)(const NIMQChatChannelGetChannelsResp& resp);
/// 分页查询频道列表回调
typedef void (*nim_qchat_channel_get_channels_page_cb_func)(const NIMQChatChannelGetChannelsPageResp& resp);
/// 分页查询成员列表回调
typedef void (*nim_qchat_channel_get_members_page_cb_func)(const NIMQChatChannelGetMembersPageResp& resp);
/// 查询未读消息数回调
typedef void (*nim_qchat_channel_query_unread_info_cb_func)(const NIMQChatChannelQueryUnreadInfoResp& resp);
/// 订阅回调
typedef void (*nim_qchat_channel_subscribe_cb_func)(const NIMQChatChannelSubscribeResp& resp);
/// 更新白/黑名单身份组回调
typedef void (*nim_qchat_channel_update_white_black_role_cb_func)(const NIMQChatChannelUpdateWhiteBlackRoleResp& resp);
/// 更新白/黑名单成员回调
typedef void (*nim_qchat_channel_update_white_black_members_cb_func)(const NIMQChatChannelUpdateWhiteBlackMembersResp& resp);
/// 分页查询白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_white_black_roles_page_cb_func)(const NIMQChatChannelGetWhiteBlackRolesPageResp& resp);
/// 分页查询白/黑名单成员回调
typedef void (*nim_qchat_channel_get_white_black_members_page_cb_func)(const NIMQChatChannelGetWhiteBlackMembersPageResp& resp);
/// 查询已存在白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_existing_white_black_roles_cb_func)(const NIMQChatChannelGetExistingWhiteBlackRolesResp& resp);
/// 查询已存在白/黑名单成员回调
typedef void (*nim_qchat_channel_get_existing_white_black_members_cb_func)(const NIMQChatChannelGetExistingWhiteBlackMembersResp& resp);
/// 搜索频道分页回调
typedef nim_qchat_channel_get_channels_page_cb_func nim_qchat_channel_search_page_cb_func;
/// 搜索频道成员回调
typedef void (*nim_qchat_channel_member_search_cb_func)(const NIMQChatChannelMemberSearchResp& resp);
/// 创建频道分组回调
typedef void (*nim_qchat_channel_create_category_cb_func)(const NIMQChatChannelCategoryCreateResp& resp);
/// 删除频道分组回调
typedef void (*nim_qchat_channel_remove_category_cb_func)(const NIMQChatChannelCategoryRemoveResp& resp);
/// 更新频道分组回调
typedef void (*nim_qchat_channel_update_category_cb_func)(const NIMQChatChannelCategoryUpdateResp& resp);
/// 根据ID查询频道分组列表回调
typedef void (*nim_qchat_channel_get_categories_cb_func)(const NIMQChatChannelGetCategoriesByIDResp& resp);
/// 分页查询频道分组列表回调
typedef void (*nim_qchat_channel_get_categories_page_cb_func)(const NIMQChatChannelGetCategoriesPageResp& resp);
/// 分页查询频道分组中的频道
typedef void (*nim_qchat_channel_get_category_channels_page_cb_func)(const NIMQChatChannelGetCategoryChannelsPageResp& resp);
/// 更新频道分组白/黑名单身份组回调
typedef void (*nim_qchat_channel_update_category_white_black_role_cb_func)(const NIMQChatChannelCategoryUpdateWhiteBlackRoleResp& resp);
/// 分页查询频道分组白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_category_white_black_roles_page_cb_func)(const NIMQChatChannelCategoryGetWhiteBlackRolesPageResp& resp);
/// 更新频道分组白/黑名单成员回调
typedef void (*nim_qchat_channel_update_category_white_black_members_cb_func)(const NIMQChatChannelCategoryUpdateWhiteBlackMembersResp& resp);
/// 分页查询频道分组白/黑名单成员回调
typedef void (*nim_qchat_channel_get_category_white_black_members_page_cb_func)(const NIMQChatChannelCategoryGetWhiteBlackMembersPageResp& resp);
/// 批量查询频道分组白/黑名单身份组回调
typedef void (*nim_qchat_channel_get_category_white_black_roles_cb_func)(const NIMQChatChannelCategoryGetExistingWhiteBlackRolesResp& resp);
/// 批量查询频道分组白/黑名单成员回调
typedef void (*nim_qchat_channel_get_category_white_black_members_cb_func)(const NIMQChatChannelCategoryGetWhiteBlackMembersResp& resp);
/// 修改RTC频道参数回调
typedef void (*nim_qchat_channel_update_rtc_info_cb_func)(const NIMQChatChannelUpdateRTCInfoResp& resp);
/// 查询RTC频道参数回调
typedef void (*nim_qchat_channel_get_rtc_info_cb_func)(const NIMQChatChannelGetRTCInfoResp& resp);
/// 查询RTC频道在线成员回调
typedef void (*nim_qchat_channel_get_rtc_online_members_cb_func)(const NIMQChatChannelGetRTCOnlineMembersResp& resp);

/* ------------------------------- 接口调用参数 ------------------------------ */
/// @struct NIMQChatChannelRegUnreadCbParam
struct NIMQChatChannelRegUnreadCbParam {
    nim_qchat_channel_unread_cb_func cb;
    void* user_data;
};

/// @struct NIMQChatChannelCreateParam
struct NIMQChatChannelCreateParam {
    /// 创建频道异步回调
    nim_qchat_channel_create_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道信息
    NIMQChatChannelInfo channel_info;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
};

/// @struct NIMQChatChannelDeleteParam
struct NIMQChatChannelDeleteParam {
    /// 移除频道异步回调
    nim_qchat_channel_remove_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道ID
    uint64_t channel_id;
};

/// @struct NIMQChatChannelUpdateParam
struct NIMQChatChannelUpdateParam {
    /// 更新频道信息异步回调
    nim_qchat_channel_update_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道 ID
    uint64_t channel_id;
    /// 频道名称
    char* name;
    /// 主题
    char* topic;
    /// 自定义扩展
    char* custom;
    /// 查看权限
    NIMQChatChannelViewMode view_mode;
    /// 反垃圾信息
    NIMQChatBusinessAntiSpamInfo anti_spam_info;
};

/// @struct NIMQChatChannelUpdateCategoryInfoParam
struct NIMQChatChannelUpdateCategoryInfoParam {
    /// 更新频道的分组信息异步回调
    nim_qchat_channel_update_category_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道 ID
    uint64_t channel_id;
    /// 频道分组ID
    uint64_t category_id;
    /// 频道分组同步模式
    NIMQChatChannelSyncMode sync_mode;
};

/// @struct NIMQChatChannelGetChannelsParam
struct NIMQChatChannelGetChannelsParam {
    /// 查询频道列表异步回调
    nim_qchat_channel_get_channels_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 频道id列表长度
    size_t channel_ids_count;
    /// 频道id列表
    uint64_t* channel_ids;
};

/// @struct NIMQChatChannelGetChannelsPageParam
struct NIMQChatChannelGetChannelsPageParam {
    /// 查询频道列表异步回调
    nim_qchat_channel_get_channels_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelGetMembersPageParam
struct NIMQChatChannelGetMembersPageParam {
    /// 查询成员列表异步回调
    nim_qchat_channel_get_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelQueryUnreadInfoParam
struct NIMQChatChannelQueryUnreadInfoParam {
    /// 查询未读消息数异步回调
    nim_qchat_channel_query_unread_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// ID 列表长度
    size_t id_infos_count;
    /// ID 列表
    NIMQChatChannelIDInfo* id_infos;
};

/// @struct NIMQChatChannelSubscribeParam
struct NIMQChatChannelSubscribeParam {
    /// 订阅频道信息回调函数
    nim_qchat_channel_subscribe_cb_func cb;
    void* user_data;
    /// 操作类型
    NIMQChatSubscribeOpeType ope_type;
    /// 订阅类型
    NIMQChatSubscribeType sub_type;
    /// ID 列表长度
    size_t id_infos_count;
    /// ID 列表
    NIMQChatChannelIDInfo* id_infos;
};

/// @struct NIMQChatChannelUpdateWhiteBlackRoleParam
struct NIMQChatChannelUpdateWhiteBlackRoleParam {
    /// 更新白/黑名单身份组回调
    nim_qchat_channel_update_white_black_role_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 身份组id
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
};

/// @struct NIMQChatChannelUpdateWhiteBlackMembersParam
struct NIMQChatChannelUpdateWhiteBlackMembersParam {
    /// 更新白/黑名单成员回调
    nim_qchat_channel_update_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 被踢人id列表
    char** accids;
    /// 被踢人id列表长度
    size_t accids_count;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
};

/// @struct NIMQChatChannelGetWhiteBlackRolesPageParam
struct NIMQChatChannelGetWhiteBlackRolesPageParam {
    /// 查询白/黑名单身份组列表回调
    nim_qchat_channel_get_white_black_roles_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelGetWhiteBlackMembersPageParam
struct NIMQChatChannelGetWhiteBlackMembersPageParam {
    /// 查询白/黑名单成员列表回调
    nim_qchat_channel_get_white_black_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelGetExistingWhiteBlackRolesParam
struct NIMQChatChannelGetExistingWhiteBlackRolesParam {
    /// 查询白/黑名单身份组列表回调
    nim_qchat_channel_get_existing_white_black_roles_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 身份组id列表
    uint64_t* role_ids;
    /// 身份组id列表长度
    size_t role_ids_count;
};

/// @struct NIMQChatChannelGetExistingWhiteBlackMembersParam
struct NIMQChatChannelGetExistingWhiteBlackMembersParam {
    /// 查询白/黑名单成员列表回调
    nim_qchat_channel_get_existing_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// accid列表
    char** accids;
    /// accid列表长度
    size_t accids_count;
};

/// @struct NIMQChatChannelSearchPageParam
struct NIMQChatChannelSearchPageParam {
    /// 搜索异步回调
    nim_qchat_channel_search_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id, 若为空则表示在所有服务器下可见频道中搜索
    uint64_t server_id;
    /// 搜索内容
    char* keyword;
    /// 起始时间
    uint64_t start_time;
    /// 结束时间
    uint64_t end_time;
    /// 排序顺序
    NIMQChatSearchOrder order;
    /// 排序规则
    NIMQChatChannelSearchSort sort;
    /// 查询条数
    uint32_t limit;
    /// 查询游标, 查询的起始位置
    char* cursor;
};

/// @struct NIMQChatChannelMemberSearchParam
struct NIMQChatChannelMemberSearchParam {
    /// 搜索异步回调
    nim_qchat_channel_member_search_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 频道 id
    uint64_t channel_id;
    /// 搜索内容
    char* keyword;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelCategoryCreateParam
struct NIMQChatChannelCategoryCreateParam {
    /// 创建频道分组回调
    nim_qchat_channel_create_category_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 名称
    char* name;
    /// 自定义字段
    char* custom;
    /// 查看模式
    NIMQChatChannelViewMode view_mode;
};

/// @struct NIMQChatChannelCategoryRemoveParam
struct NIMQChatChannelCategoryRemoveParam {
    /// 删除频道分组回调
    nim_qchat_channel_remove_category_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 分组 id
    uint64_t category_id;
};

/// @struct NIMQChatChannelCategoryUpdateParam
struct NIMQChatChannelCategoryUpdateParam {
    /// 更新频道分组回调
    nim_qchat_channel_update_category_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 分组 id
    uint64_t category_id;
    /// 名称
    char* name;
    /// 自定义字段
    char* custom;
    /// 查看模式
    NIMQChatChannelViewMode view_mode;
};

/// @struct NIMQChatChannelGetCategoriesByIDParam
struct NIMQChatChannelGetCategoriesByIDParam {
    /// 获取频道分组回调
    nim_qchat_channel_get_categories_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 分组ID列表
    uint64_t* category_ids;
    /// 分组ID列表长度
    size_t category_ids_count;
};

/// @struct NIMQChatChannelGetCategoriesPageParam
struct NIMQChatChannelGetCategoriesPageParam {
    /// 分页获取频道分组回调
    nim_qchat_channel_get_categories_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelGetCategoryChannelsPageParam
struct NIMQChatChannelGetCategoryChannelsPageParam {
    /// 分页获取频道分组回调
    nim_qchat_channel_get_category_channels_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 id
    uint64_t server_id;
    /// 分组 id
    uint64_t category_id;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackRoleParam
struct NIMQChatChannelCategoryUpdateWhiteBlackRoleParam {
    /// 更新频道分组白/黑名单身份组回调
    nim_qchat_channel_update_category_white_black_role_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 身份组ID
    uint64_t role_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
};

/// @struct NIMQChatChannelCategoryGetWhiteBlackRolesPageParam
struct NIMQChatChannelCategoryGetWhiteBlackRolesPageParam {
    /// 获取频道分组白/黑名单身份组回调
    nim_qchat_channel_get_category_white_black_roles_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam
struct NIMQChatChannelCategoryGetExistingWhiteBlackRolesParam {
    /// 获取频道分组白/黑名单身份组回调
    nim_qchat_channel_get_category_white_black_roles_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 身份组ID列表
    uint64_t* role_ids;
    /// 身份组ID列表长度
    size_t role_ids_count;
};

/// @struct NIMQChatChannelCategoryUpdateWhiteBlackMembersParam
struct NIMQChatChannelCategoryUpdateWhiteBlackMembersParam {
    /// 更新频道分组白/黑名单成员回调
    nim_qchat_channel_update_category_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 成员ID列表
    char** accids;
    /// 成员ID列表长度
    size_t accids_count;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 操作类型
    NIMQChatChannelWhiteBlackOpeType ope_type;
};

/// @struct NIMQChatChannelCategoryGetWhiteBlackMembersPageParam
struct NIMQChatChannelCategoryGetWhiteBlackMembersPageParam {
    /// 获取频道分组白/黑名单成员回调
    nim_qchat_channel_get_category_white_black_members_page_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 时间戳
    uint64_t timestamp;
    /// 查询条数
    uint32_t limit;
};

/// @struct NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam
struct NIMQChatChannelCategoryGetExistingWhiteBlackMembersParam {
    /// 获取频道分组白/黑名单成员回调
    nim_qchat_channel_get_category_white_black_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 分组ID
    uint64_t category_id;
    /// 白/黑名单类型
    NIMQChatChannelWhiteBlackType type;
    /// 成员ID列表
    char** accids;
    /// 成员ID列表长度
    size_t accids_count;
};

/// @struct NIMQChatChannelUpdateRTCInfoParam
struct NIMQChatChannelUpdateRTCInfoParam {
    /// 更新频道RTC信息回调
    nim_qchat_channel_update_rtc_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
    /// RTC信息
    NIMQChatChannelRTCInfo rtc_info;
};

/// @struct NIMQChatChannelGetRTCInfoParam
struct NIMQChatChannelGetRTCInfoParam {
    /// 获取频道RTC信息回调
    nim_qchat_channel_get_rtc_info_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
};

/// @struct NIMQChatChannelGetRTCOnlineMembersParam
struct NIMQChatChannelGetRTCOnlineMembersParam {
    /// 获取频道RTC在线成员回调
    nim_qchat_channel_get_rtc_online_members_cb_func cb;
    /// 自定义用户数据
    void* user_data;
    /// 服务器 ID
    uint64_t server_id;
    /// 频道ID
    uint64_t channel_id;
};

#ifdef __cplusplus
}
#endif

#endif  // __NIM_QCHAT_CHANNEL_DEF_H__
