/**
 * @file nim_qchat_server_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_SERVER_CPP_DEF_H__
#define __NIM_QCHAT_SERVER_CPP_DEF_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_member_cpp_def.h"
#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_helper.h"
#include "nim_qchat_server_def.h"

namespace nim_qchat {

/** @struct QChatServerInfo 圈组服务器信息 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerInfo {
    /// server id
    uint64_t server_id{0};
    /// 用户自定义服务器类别, 0表示无类别
    uint32_t server_type{0};
    /// 是否能被搜索
    bool searchable{true};
    /// 名称
    std::string name{""};
    /// 图标url
    std::string icon{""};
    /// 自定义字段
    std::string custom{""};
    /// 所有者id
    std::string owner_id{""};
    /// 成员数量
    uint64_t member_count{0};
    /// 邀请模式
    NIMQChatServerInviteMode invite_mode{kNIMQChatServerInviteModeNeedConfirm};
    /// 申请模式
    NIMQChatServerApplyMode apply_mode{kNIMQChatServerApplyModeNormal};
    /// 有效标记，false:无效 true:有效
    bool valid_flag{false};
    /// 总频道数量
    uint32_t channel_count{0};
    /// 总频道分组数量
    uint32_t channel_category_count{0};
    /// 创建时间
    uint64_t create_time{0};
    /// 更新时间
    uint64_t update_time{0};
    /// 自定义排序权重值
    uint64_t reorder_weight{0};
    QChatServerInfo() = default;
    QChatServerInfo(const NIMQChatServerInfo& c_param) {
        server_id = c_param.server_id;
        server_type = c_param.server_type;
        searchable = c_param.searchable;
        name = c_param.name ? c_param.name : "";
        icon = c_param.icon ? c_param.icon : "";
        custom = c_param.custom ? c_param.custom : "";
        owner_id = c_param.owner_id ? c_param.owner_id : "";
        member_count = c_param.member_count;
        invite_mode = c_param.invite_mode;
        apply_mode = c_param.apply_mode;
        valid_flag = c_param.valid_flag;
        channel_count = c_param.channel_count;
        channel_category_count = c_param.channel_category_count;
        create_time = c_param.create_time;
        update_time = c_param.update_time;
        reorder_weight = c_param.reorder_weight;
    }
    const NIMQChatServerInfo ToCParam() const {
        NIMQChatServerInfo c_param;
        c_param.server_id = server_id;
        c_param.server_type = server_type;
        c_param.searchable = searchable;
        c_param.name = const_cast<char*>(name.c_str());
        c_param.icon = const_cast<char*>(icon.c_str());
        c_param.custom = const_cast<char*>(custom.c_str());
        c_param.owner_id = const_cast<char*>(owner_id.c_str());
        c_param.member_count = member_count;
        c_param.invite_mode = invite_mode;
        c_param.apply_mode = apply_mode;
        c_param.valid_flag = valid_flag;
        c_param.channel_count = channel_count;
        c_param.channel_category_count = channel_category_count;
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        c_param.reorder_weight = reorder_weight;
        return c_param;
    }
};

/// @struct QChatInviteUserInfo 邀请用户信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatInviteUserInfo {
    /// accid
    std::string accid;
    /// 更新附言
    std::string update_postscript;
    /// 状态
    NIMQChatInviteApplyRecordStatus status{kNIMQChatInviteApplyRecordStatusInitial};
    /// 更新时间
    uint64_t update_time{0};
    QChatInviteUserInfo() = default;
    QChatInviteUserInfo(const NIMQChatInviteUserInfo& c_param) {
        accid = c_param.accid ? c_param.accid : "";
        update_postscript = c_param.update_postscript ? c_param.update_postscript : "";
        status = c_param.status;
        update_time = c_param.update_time;
    }
    const NIMQChatInviteUserInfo ToCParam() const {
        NIMQChatInviteUserInfo c_param;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.update_postscript = const_cast<char*>(update_postscript.c_str());
        c_param.status = status;
        c_param.update_time = update_time;
        return c_param;
    }
};

/// @struct QChatInviteApplyRecordData 邀请申请信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatInviteApplyRecordData {
    virtual ~QChatInviteApplyRecordData(){};
};

/// @struct QChatApplyInfoData 圈组申请信息数据
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatApplyInfoData : QChatInviteApplyRecordData {
    /// 申请附言
    std::string apply_postscript;
    /// 更新者 id
    std::string update_accid;
    /// 更新附言
    std::string update_postscript;
    QChatApplyInfoData() = default;
    QChatApplyInfoData(const NIMQChatApplyInfoData& c_param) {
        apply_postscript = c_param.apply_postscript ? c_param.apply_postscript : "";
        update_accid = c_param.update_accid ? c_param.update_accid : "";
        update_postscript = c_param.update_postscript ? c_param.update_postscript : "";
    }
    const NIMQChatApplyInfoData ToCParam() const {
        NIMQChatApplyInfoData c_param;
        c_param.apply_postscript = const_cast<char*>(apply_postscript.c_str());
        c_param.update_accid = const_cast<char*>(update_accid.c_str());
        c_param.update_postscript = const_cast<char*>(update_postscript.c_str());
        return c_param;
    }
};

/// @struct QChatInviteInfoData 圈组邀请信息数据
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatInviteInfoData : QChatInviteApplyRecordData {
    /// 邀请附言
    std::string invite_postscript;
    /// 邀请成员信息列表
    std::vector<QChatInviteUserInfo> invite_user_infos;
    QChatInviteInfoData() = default;
    QChatInviteInfoData(const NIMQChatInviteInfoData& c_param) {
        invite_postscript = c_param.invite_postscript ? c_param.invite_postscript : "";
        for (size_t i = 0; i < c_param.invite_user_infos_count; i++) {
            invite_user_infos.emplace_back(c_param.invite_user_infos[i]);
        }
    }
    const NIMQChatInviteInfoData ToCParam() const {
        NIMQChatInviteInfoData c_param;
        c_param.invite_postscript = const_cast<char*>(invite_postscript.c_str());
        c_invite_user_infos.clear();
        for (auto&& user_info : invite_user_infos) {
            c_invite_user_infos.push_back(user_info.ToCParam());
        }
        c_param.invite_user_infos = const_cast<NIMQChatInviteUserInfo*>(c_invite_user_infos.data());
        c_param.invite_user_infos_count = c_invite_user_infos.size();
        return c_param;
    }

protected:
    mutable std::vector<NIMQChatInviteUserInfo> c_invite_user_infos;
};

/// @struct QChatBeInvitedInfoData 圈组被邀请信息数据
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatBeInvitedInfoData : QChatInviteApplyRecordData {
    /// 邀请附言
    std::string invite_postscript;
    /// 更新附言
    std::string update_postscript;
    QChatBeInvitedInfoData() = default;
    QChatBeInvitedInfoData(const NIMQChatBeInvitedInfoData& c_param) {
        invite_postscript = c_param.invite_postscript ? c_param.invite_postscript : "";
        update_postscript = c_param.update_postscript ? c_param.update_postscript : "";
    }
    const NIMQChatBeInvitedInfoData ToCParam() const {
        NIMQChatBeInvitedInfoData c_param;
        c_param.invite_postscript = const_cast<char*>(invite_postscript.c_str());
        c_param.update_postscript = const_cast<char*>(update_postscript.c_str());
        return c_param;
    }
};

/// @struct QChatGenerateInviteCodeInfoData 圈组生成邀请码信息数据
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatGenerateInviteCodeInfoData : QChatInviteApplyRecordData {
    /// 邀请附言
    std::string invite_postscript;
    /// 邀请码
    std::string invite_code;
    /// 邀请人数
    uint32_t invite_count{0};
    QChatGenerateInviteCodeInfoData() = default;
    QChatGenerateInviteCodeInfoData(const NIMQChatGenerateInviteCodeInfoData& c_param) {
        invite_postscript = c_param.invite_postscript ? c_param.invite_postscript : "";
        invite_code = c_param.invite_code ? c_param.invite_code : "";
        invite_count = c_param.invite_count;
    }
    const NIMQChatGenerateInviteCodeInfoData ToCParam() const {
        NIMQChatGenerateInviteCodeInfoData c_param;
        c_param.invite_postscript = const_cast<char*>(invite_postscript.c_str());
        c_param.invite_code = const_cast<char*>(invite_code.c_str());
        c_param.invite_count = invite_count;
        return c_param;
    }
};

/// @struct QChatJoinByInviteCodeInfoData 圈组通过邀请码加入信息数据
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatJoinByInviteCodeInfoData : QChatInviteApplyRecordData {
    /// 邀请附言
    std::string invite_postscript;
    /// 更新附言
    std::string update_postscript;
    /// 邀请码
    std::string invite_code;
    QChatJoinByInviteCodeInfoData() = default;
    QChatJoinByInviteCodeInfoData(const NIMQChatJoinByInviteCodeInfoData& c_param) {
        invite_postscript = c_param.invite_postscript ? c_param.invite_postscript : "";
        update_postscript = c_param.update_postscript ? c_param.update_postscript : "";
        invite_code = c_param.invite_code ? c_param.invite_code : "";
    }
    const NIMQChatJoinByInviteCodeInfoData ToCParam() const {
        NIMQChatJoinByInviteCodeInfoData c_param;
        c_param.invite_postscript = const_cast<char*>(invite_postscript.c_str());
        c_param.update_postscript = const_cast<char*>(update_postscript.c_str());
        c_param.invite_code = const_cast<char*>(invite_code.c_str());
        return c_param;
    }
};

/// @struct QChatInviteApplyRecord 圈组邀请申请信息
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatInviteApplyRecord {
    /// accid
    std::string accid;
    /// type
    NIMQChatInviteApplyRecordType type{kNIMQChatInviteApplyRecordTypeApply};
    /// 服务器ID
    uint64_t server_id{0};
    /// 状态
    NIMQChatInviteApplyRecordStatus status{kNIMQChatInviteApplyRecordStatusInitial};
    /// 请求ID
    uint64_t request_id{0};
    /// 记录ID
    uint64_t record_id{0};
    /// 创建时间
    uint64_t create_time{0};
    /// 更新时间
    uint64_t update_time{0};
    /// 过期时间
    uint64_t expire_time{0};
    /// 邀请申请信息数据
    std::shared_ptr<QChatInviteApplyRecordData> data;
    /// 邀请申请信息原始Json数据
    std::string raw_data;
    QChatInviteApplyRecord() = default;
    QChatInviteApplyRecord(const NIMQChatInviteApplyRecord& c_param) {
        accid = c_param.accid ? c_param.accid : "";
        type = c_param.type;
        server_id = c_param.server_id;
        status = c_param.status;
        request_id = c_param.request_id;
        record_id = c_param.record_id;
        create_time = c_param.create_time;
        update_time = c_param.update_time;
        expire_time = c_param.expire_time;
        switch (type) {
            case kNIMQChatInviteApplyRecordTypeApply:
                data = std::make_shared<QChatApplyInfoData>(c_param.apply_data);
                break;
            case kNIMQChatInviteApplyRecordTypeInvite:
                data = std::make_shared<QChatInviteInfoData>(c_param.invite_data);
                break;
            case kNIMQChatInviteApplyRecordTypeBeInvited:
                data = std::make_shared<QChatBeInvitedInfoData>(c_param.be_invited_data);
                break;
            case kNIMQChatInviteApplyRecordTypeGenerateInviteCode:
                data = std::make_shared<QChatGenerateInviteCodeInfoData>(c_param.generate_invite_code_data);
                break;
            case kNIMQChatInviteApplyRecordTypeJoinByInviteCode:
                data = std::make_shared<QChatJoinByInviteCodeInfoData>(c_param.join_by_invite_code_data);
                break;
        }
        raw_data = c_param.raw_data ? c_param.raw_data : "";
    }
    const NIMQChatInviteApplyRecord ToCParam() const {
        NIMQChatInviteApplyRecord c_param;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.type = type;
        c_param.server_id = server_id;
        c_param.status = status;
        c_param.request_id = request_id;
        c_param.record_id = record_id;
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        c_param.expire_time = expire_time;
        switch (type) {
            case kNIMQChatInviteApplyRecordTypeApply:
                c_param.apply_data = dynamic_cast<QChatApplyInfoData*>(data.get())->ToCParam();
                break;
            case kNIMQChatInviteApplyRecordTypeInvite:
                c_param.invite_data = dynamic_cast<QChatInviteInfoData*>(data.get())->ToCParam();
                break;
            case kNIMQChatInviteApplyRecordTypeBeInvited:
                c_param.be_invited_data = dynamic_cast<QChatBeInvitedInfoData*>(data.get())->ToCParam();
                break;
            case kNIMQChatInviteApplyRecordTypeGenerateInviteCode:
                c_param.generate_invite_code_data = dynamic_cast<QChatGenerateInviteCodeInfoData*>(data.get())->ToCParam();
                break;
            case kNIMQChatInviteApplyRecordTypeJoinByInviteCode:
                c_param.join_by_invite_code_data = dynamic_cast<QChatJoinByInviteCodeInfoData*>(data.get())->ToCParam();
                break;
        }
        c_param.raw_data = const_cast<char*>(raw_data.c_str());
        return c_param;
    }
};

/// @struct QChatServerCreateResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerCreateResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 服务器ID
    QChatServerInfo server_info{};
    QChatServerCreateResp() = default;
    QChatServerCreateResp(const NIMQChatServerCreateResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        server_info = c_resp.server_info;
    }
    NIMQChatServerCreateResp ToCParam() const {
        NIMQChatServerCreateResp c_resp;
        c_resp.res_code = res_code;
        if (res_code != kNIMResSuccess)
            return c_resp;
        c_resp.server_info = server_info.ToCParam();
        return c_resp;
    }
};

/// @struct QChatServerDeleteResp
using QChatServerDeleteResp = QChatBaseResp;

/// @struct QChatServerUpdateResp
using QChatServerUpdateResp = QChatServerCreateResp;

/// @struct QChatServerGetServersResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetServersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 服务器列表
    std::list<QChatServerInfo> server_list{};
    QChatServerGetServersResp() = default;
    QChatServerGetServersResp(const NIMQChatServerGetServersResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.server_list_count; i++) {
            server_list.emplace_back(c_resp.server_list[i]);
        }
    }
    const NIMQChatServerGetServersResp ToCParam() const {
        NIMQChatServerGetServersResp c_response{};
        c_response.res_code = res_code;
        vec_servers.clear();
        for (auto&& info : server_list) {
            vec_servers.push_back(info.ToCParam());
        }
        c_response.server_list_count = vec_servers.size();
        c_response.server_list = vec_servers.data();
        return c_response;
    };

protected:
    mutable std::vector<NIMQChatServerInfo> vec_servers;
};

/// @struct QChatServerGetServersPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetServersPageResp : public QChatServerGetServersResp {
    /// 分页信息
    QChatPageInfo page_info{};
    QChatServerGetServersPageResp() = default;
    QChatServerGetServersPageResp(const NIMQChatServerGetServersPageResp& c_resp) {
        res_code = c_resp.res_code;
        page_info = c_resp.page_info;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.server_list_count; i++) {
            server_list.emplace_back(c_resp.server_list[i]);
        }
    }
    const NIMQChatServerGetServersPageResp ToCParam() const {
        NIMQChatServerGetServersPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        vec_servers.clear();
        for (auto&& info : server_list) {
            vec_servers.push_back(info.ToCParam());
        }
        c_response.server_list_count = vec_servers.size();
        c_response.server_list = vec_servers.data();
        return c_response;
    };
};

/// @struct QChatServerInviteResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerInviteResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 请求ID
    uint64_t request_id{0};
    /// 请求失效时间戳
    uint64_t expire_time{0};
    /// 邀请失败的成员id和失败原因
    std::map<std::string, NIMQChatServerInviteFailReason> fail_map;
    QChatServerInviteResp() = default;
    QChatServerInviteResp(const NIMQChatServerInviteResp& c_resp) {
        res_code = c_resp.res_code;
        request_id = c_resp.request_id;
        expire_time = c_resp.expire_time;
        for (size_t i = 0; i < c_resp.accids_count; i++) {
            fail_map.emplace(c_resp.accids[i], c_resp.fail_reasons[i]);
        }
    };
    NIMQChatServerInviteResp ToCParam() const {
        NIMQChatServerInviteResp c_resp;
        c_resp.res_code = res_code;
        c_resp.request_id = request_id;
        c_resp.expire_time = expire_time;
        vec_accids.clear();
        vec_fail_reason.clear();
        for (auto&& pair : fail_map) {
            vec_accids.push_back(const_cast<char*>(pair.first.c_str()));
            vec_fail_reason.push_back(pair.second);
        }
        c_resp.accids_count = vec_accids.size();
        c_resp.accids = vec_accids.data();
        c_resp.fail_reasons = const_cast<NIMQChatServerInviteFailReason*>(vec_fail_reason.data());
        return c_resp;
    }

protected:
    mutable std::vector<char*> vec_accids;
    mutable std::vector<NIMQChatServerInviteFailReason> vec_fail_reason;
};

/// @struct QChatServerAcceptInviteResp
using QChatServerAcceptInviteResp = QChatBaseResp;

/// @struct QChatServerRejectInviteResp
using QChatServerRejectInviteResp = QChatBaseResp;

/// @struct QChatServerApplyResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerApplyResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 请求ID
    uint64_t request_id{0};
    /// 过期时间
    uint64_t expire_time{0};
    QChatServerApplyResp() = default;
    QChatServerApplyResp(const NIMQChatServerApplyResp& c_resp) {
        res_code = c_resp.res_code;
        request_id = c_resp.request_id;
        expire_time = c_resp.expire_time;
    };
    NIMQChatServerApplyResp ToCParam() const {
        NIMQChatServerApplyResp c_resp;
        c_resp.res_code = res_code;
        c_resp.request_id = request_id;
        c_resp.expire_time = expire_time;
        return c_resp;
    }
};

/// @struct QChatServerAcceptApplyResp
using QChatServerAcceptApplyResp = QChatBaseResp;

/// @struct QChatServerRejectApplyResp
using QChatServerRejectApplyResp = QChatBaseResp;

/// @struct QChatServerKickResp
using QChatServerKickResp = QChatBaseResp;

/// @struct QChatServerLeaveResp
using QChatServerLeaveResp = QChatBaseResp;

/// @struct QChatServerUpdateMemberInfoResp
using QChatServerUpdateMemberInfoResp = QChatBaseResp;

/// @struct QChatServerGetMembersResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetMembersResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 成员信息列表
    std::list<QChatMemberInfo> member_list{};
    QChatServerGetMembersResp() = default;
    QChatServerGetMembersResp(const NIMQChatServerGetMembersResp& c_resp) {
        res_code = c_resp.res_code;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_list_count; i++) {
            member_list.emplace_back(c_resp.member_list[i]);
        }
    }
    NIMQChatServerGetMembersResp ToCParam() const {
        NIMQChatServerGetMembersResp c_response{};
        c_response.res_code = res_code;
        vec_members.clear();
        for (auto&& info : member_list) {
            vec_members.push_back(info.ToCParam());
        }
        c_response.member_list_count = vec_members.size();
        c_response.member_list = vec_members.data();
        return c_response;
    };

protected:
    mutable std::vector<NIMQChatMemberInfo> vec_members;
};

struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetMembersPageResp : public QChatServerGetMembersResp {
    /// 分页信息
    QChatPageInfo page_info{};
    QChatServerGetMembersPageResp() = default;
    QChatServerGetMembersPageResp(const NIMQChatServerGetMembersPageResp& c_resp) {
        res_code = c_resp.res_code;
        page_info = c_resp.page_info;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.member_list_count; i++) {
            member_list.emplace_back(c_resp.member_list[i]);
        }
    }
    NIMQChatServerGetMembersPageResp ToCParam() const {
        NIMQChatServerGetMembersPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        vec_members.clear();
        for (auto&& info : member_list) {
            vec_members.push_back(info.ToCParam());
        }
        c_response.member_list_count = vec_members.size();
        c_response.member_list = vec_members.data();
        return c_response;
    };
};

/// @struct QChatServerSubscribeResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerSubscribeResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 订阅失败列表
    std::vector<uint64_t> failed_servers{};
    QChatServerSubscribeResp() = default;
    QChatServerSubscribeResp(const NIMQChatServerSubscribeResp& c_resp) {
        res_code = c_resp.res_code;
        for (size_t i = 0; i < c_resp.failed_servers_count; i++) {
            failed_servers.push_back(c_resp.failed_servers[i]);
        }
    }
    NIMQChatServerSubscribeResp ToCParam() const {
        NIMQChatServerSubscribeResp c_resp;
        c_resp.res_code = res_code;
        c_resp.failed_servers = const_cast<uint64_t*>(failed_servers.data());
        c_resp.failed_servers_count = failed_servers.size();
        return c_resp;
    }
};

/// @struct QChatServerBanMemberResp
using QChatServerBanMemberResp = QChatBaseResp;

/// @struct QChatServerUnbanMemberResp
using QChatServerUnbanMemberResp = QChatBaseResp;

/// @struct QChatServerGetBannedMembersPageResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetBannedMembersPageResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 分页信息
    QChatPageInfo page_info{};
    /// 成员封禁列表
    std::list<QChatMemberBanInfo> ban_list{};
    QChatServerGetBannedMembersPageResp() = default;
    QChatServerGetBannedMembersPageResp(const NIMQChatServerGetBannedMembersPageResp& c_resp) {
        res_code = c_resp.res_code;
        page_info = c_resp.page_info;
        if (c_resp.res_code != kNIMResSuccess)
            return;
        for (size_t i = 0; i < c_resp.ban_list_count; i++) {
            ban_list.emplace_back(c_resp.ban_list[i]);
        }
    }
    const NIMQChatServerGetBannedMembersPageResp ToCParam() const {
        NIMQChatServerGetBannedMembersPageResp c_response{};
        c_response.res_code = res_code;
        c_response.page_info = page_info.ToCParam();
        c_ban_list.clear();
        for (auto&& info : ban_list) {
            c_ban_list.push_back(info.ToCParam());
        }
        c_response.ban_list_count = c_ban_list.size();
        c_response.ban_list = c_ban_list.data();
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatMemberBanInfo> c_ban_list;
};

/// @struct QChatServerSearchPageResp
using QChatServerSearchPageResp = QChatServerGetServersPageResp;

/// @struct QChatServerMemberSearchResp
using QChatServerMemberSearchResp = QChatServerGetMembersResp;

/// @struct QChatServerUnreadResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerUnreadResp {
    /// 未读数信息
    std::vector<NIMQChatServerUnreadInfo> unread_infos{};
    QChatServerUnreadResp() = default;
    QChatServerUnreadResp(const NIMQChatServerUnreadResp& c_resp) {
        for (size_t i = 0; i < c_resp.unread_infos_count; i++) {
            unread_infos.emplace_back(c_resp.unread_infos[i]);
        }
    }
};

/// QChatServerGenerateInviteCodeResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGenerateInviteCodeResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 服务器 id
    uint64_t server_id{0};
    /// 请求ID
    uint64_t request_id{0};
    /// 邀请码
    std::string invite_code;
    /// 过期时间
    uint64_t expire_time{0};
    QChatServerGenerateInviteCodeResp() = default;
    QChatServerGenerateInviteCodeResp(const NIMQChatServerGenerateInviteCodeResp& c_resp) {
        res_code = c_resp.res_code;
        server_id = c_resp.server_id;
        request_id = c_resp.request_id;
        invite_code = c_resp.invite_code ? c_resp.invite_code : "";
        expire_time = c_resp.expire_time;
    }
    const NIMQChatServerGenerateInviteCodeResp ToCParam() const {
        NIMQChatServerGenerateInviteCodeResp c_response{};
        c_response.res_code = res_code;
        c_response.server_id = server_id;
        c_response.request_id = request_id;
        c_response.invite_code = const_cast<char*>(invite_code.c_str());
        c_response.expire_time = expire_time;
        return c_response;
    }
};

/// @struct QChatServerJoinByInviteCodeResp
using QChatServerJoinByInviteCodeResp = QChatBaseResp;

/// @struct QChatServerGetInviteApplyRecordOfServerResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetInviteApplyRecordOfServerResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 邀请申请历史列表
    std::vector<QChatInviteApplyRecord> invite_apply_records{};
    QChatServerGetInviteApplyRecordOfServerResp() = default;
    QChatServerGetInviteApplyRecordOfServerResp(const NIMQChatServerGetInviteApplyRecordOfServerResp& c_resp) {
        res_code = c_resp.res_code;
        for (size_t i = 0; i < c_resp.invite_apply_records_count; i++) {
            invite_apply_records.emplace_back(c_resp.invite_apply_records[i]);
        }
    }
    const NIMQChatServerGetInviteApplyRecordOfServerResp ToCParam() const {
        NIMQChatServerGetInviteApplyRecordOfServerResp c_response{};
        c_response.res_code = res_code;
        c_invite_apply_records.clear();
        for (auto&& info : invite_apply_records) {
            c_invite_apply_records.push_back(info.ToCParam());
        }
        c_response.invite_apply_records_count = c_invite_apply_records.size();
        c_response.invite_apply_records = const_cast<NIMQChatInviteApplyRecord*>(c_invite_apply_records.data());
        return c_response;
    }

protected:
    mutable std::vector<NIMQChatInviteApplyRecord> c_invite_apply_records;
};

/// @struct QChatServerGetInviteApplyRecordOfSelfResp
using QChatServerGetInviteApplyRecordOfSelfResp = QChatServerGetInviteApplyRecordOfServerResp;

/// @struct QChatServerMarkReadResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerMarkReadResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 订阅成功的服务器 id
    std::vector<uint64_t> succeeded_servers{};
    /// 订阅失败的服务器 id
    std::vector<uint64_t> failed_servers{};
    /// 标记已读时间戳
    uint64_t timestamp{0};
    QChatServerMarkReadResp() = default;
    QChatServerMarkReadResp(const NIMQChatServerMarkReadResp& c_resp) {
        res_code = c_resp.res_code;
        for (size_t i = 0; i < c_resp.succeeded_servers_count; i++) {
            succeeded_servers.emplace_back(c_resp.succeeded_servers[i]);
        }
        for (size_t i = 0; i < c_resp.failed_servers_count; i++) {
            failed_servers.emplace_back(c_resp.failed_servers[i]);
        }
        timestamp = c_resp.timestamp;
    }
    const NIMQChatServerMarkReadResp ToCParam() const {
        NIMQChatServerMarkReadResp c_response{};
        c_response.res_code = res_code;
        c_response.succeeded_servers = const_cast<uint64_t*>(succeeded_servers.data());
        c_response.succeeded_servers_count = succeeded_servers.size();
        c_response.failed_servers = const_cast<uint64_t*>(failed_servers.data());
        c_response.failed_servers_count = failed_servers.size();
        c_response.timestamp = timestamp;
        return c_response;
    }
};

/// @struct QChatServerSubscribeAllChannelResp
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerSubscribeAllChannelResp {
    /// 操作结果, 参考NIMResCode
    uint32_t res_code{0};
    /// 订阅失败的服务器 id
    std::vector<uint64_t> failed_servers{};
    /// 频道未读信息, 内部使用，未读相关变更关注RegUnreadCb回调
    std::vector<NIMQChatUnreadInfo> unread_infos{};
    QChatServerSubscribeAllChannelResp() = default;
    QChatServerSubscribeAllChannelResp(const NIMQChatServerSubscribeAllChannelResp& c_resp) {
        res_code = c_resp.res_code;
        for (size_t i = 0; i < c_resp.failed_servers_count; i++) {
            failed_servers.emplace_back(c_resp.failed_servers[i]);
        }
        for (size_t i = 0; i < c_resp.unread_infos_count; i++) {
            unread_infos.emplace_back(c_resp.unread_infos[i]);
        }
    }
    const NIMQChatServerSubscribeAllChannelResp ToCParam() const {
        NIMQChatServerSubscribeAllChannelResp c_response{};
        c_response.res_code = res_code;
        c_response.failed_servers = const_cast<uint64_t*>(failed_servers.data());
        c_response.failed_servers_count = failed_servers.size();
        c_response.unread_infos = const_cast<NIMQChatUnreadInfo*>(unread_infos.data());
        c_response.unread_infos_count = unread_infos.size();
        return c_response;
    }
};

/// 未读数回调
using ServerUnreadCallback = std::function<void(const QChatServerUnreadResp&)>;
/// 创建服务器回调
typedef std::function<void(const QChatServerCreateResp&)> ServerCreateCallback;
/// 删除服务器回调
typedef std::function<void(const QChatServerDeleteResp&)> ServerRemoveCallback;
/// 更新服务器回调
typedef std::function<void(const QChatServerUpdateResp&)> ServerUpdateCallback;
/// 查询服务器列表回调
typedef std::function<void(const QChatServerGetServersResp&)> GetServersCallback;
/// 查询服务器列表分页回调
typedef std::function<void(const QChatServerGetServersPageResp&)> GetServersPageCallback;
/// 邀请用户加入服务器回调
typedef std::function<void(const QChatServerInviteResp&)> ServerInviteCallback;
/// 接受邀请加入服务器回调
typedef std::function<void(const QChatServerAcceptInviteResp&)> ServerAcceptInviteCallback;
/// 拒绝邀请加入服务器回调
typedef std::function<void(const QChatServerRejectInviteResp&)> ServerRejectInviteCallback;
/// 申请加入服务器回调
typedef std::function<void(const QChatServerApplyResp&)> ServerApplyCallback;
/// 接受申请加入服务器回调
typedef std::function<void(const QChatServerAcceptApplyResp&)> ServerAcceptApplyCallback;
/// 拒绝申请加入服务器回调
typedef std::function<void(const QChatServerRejectApplyResp&)> ServerRejectApplyCallback;
/// 踢出服务器回调
typedef std::function<void(const QChatServerKickResp&)> ServerKickCallback;
/// 离开服务器回调
typedef std::function<void(const QChatServerLeaveResp&)> ServerLeaveCallback;
/// 更新服务器成员信息回调
typedef std::function<void(const QChatServerUpdateMemberInfoResp&)> ServerUpdateMemberInfoCallback;
/// 查询服务器成员列表回调
typedef std::function<void(const QChatServerGetMembersResp&)> ServerGetMembersCallback;
/// 查询服务器成员列表分页回调
typedef std::function<void(const QChatServerGetMembersPageResp&)> ServerGetMembersPageCallback;
/// 订阅回调
typedef std::function<void(const QChatServerSubscribeResp&)> ServerSubscribeCallback;
/// 封禁成员回调
typedef std::function<void(const QChatServerBanMemberResp&)> ServerBanMemberCallback;
/// 解封成员回调
typedef std::function<void(const QChatServerUnbanMemberResp&)> ServerUnbanMemberCallback;
/// 查询服务器成员封禁列表分页回调
typedef std::function<void(const QChatServerGetBannedMembersPageResp&)> ServerGetBannedMembersPageCallback;
/// 搜索服务器分页回调
using ServerSearchPageCallback = GetServersPageCallback;
/// 搜索服务器成员分页回调
using ServerMemberSearchCallback = ServerGetMembersCallback;
/// 生成邀请码回调
using ServerGenerateInviteCodeCallback = std::function<void(const QChatServerGenerateInviteCodeResp&)>;
/// 通过邀请码加入回调
using ServerJoinByInviteCodeCallback = std::function<void(const QChatServerJoinByInviteCodeResp&)>;
/// 查询服务器下的申请邀请记录回调
using ServerGetInviteApplyRecordOfServerCallback = std::function<void(const QChatServerGetInviteApplyRecordOfServerResp&)>;
/// 查询自己的申请邀请记录回调
using ServerGetInviteApplyRecordOfSelfCallback = std::function<void(const QChatServerGetInviteApplyRecordOfSelfResp&)>;
/// 服务器标记已读
using ServerMarkReadCallback = std::function<void(const QChatServerMarkReadResp&)>;
/// 订阅所有频道
using ServerSubscribeAllChannelCallback = std::function<void(const QChatServerSubscribeAllChannelResp&)>;

/// @struct QChatServerRegUnreadCbParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerRegUnreadCbParam {
    ServerUnreadCallback cb{nullptr};
    const NIMQChatServerRegUnreadCbParam ToCParam() const {
        static ServerUnreadCallback cb_holder = nullptr;
        cb_holder = cb;
        NIMQChatServerRegUnreadCbParam param = {};
        param.cb = [](const NIMQChatServerUnreadResp& resp) {
            if (cb_holder)
                cb_holder(resp);
        };
        return param;
    }
};

/// @struct QChatServerCreateParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerCreateParam {
    /// 回调函数
    ServerCreateCallback cb{nullptr};
    /// 服务器信息
    QChatServerInfo server_info{};
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatServerCreateParam() = default;
    QChatServerCreateParam(const NIMQChatServerCreateParam& c_param) {
        server_info = c_param.server_info;
        anti_spam_info = c_param.anti_spam_info;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerCreateResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerCreateParam ToCParam() const {
        auto cb_holder = new ServerCreateCallback(cb);
        NIMQChatServerCreateParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerCreateResp& resp) {
            InvokeCallback<ServerCreateCallback, NIMQChatServerCreateResp>(resp);
        };
        param.server_info = server_info.ToCParam();
        param.anti_spam_info = anti_spam_info.ToCParam();
        return param;
    }
};

/// @struct QChatServerDeleteParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerDeleteParam {
    /// 回调函数
    ServerRemoveCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    QChatServerDeleteParam() = default;
    QChatServerDeleteParam(const NIMQChatServerDeleteParam& c_param) {
        server_id = c_param.server_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerDeleteResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerDeleteParam ToCParam() const {
        auto cb_holder = new ServerRemoveCallback(cb);
        NIMQChatServerDeleteParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerDeleteResp& resp) {
            InvokeCallback<ServerRemoveCallback, NIMQChatServerDeleteResp>(resp);
        };
        param.server_id = server_id;
        return param;
    }
};

/// @struct QChatServerUpdateParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerUpdateParam {
    /// 回调函数
    ServerUpdateCallback cb{nullptr};
    /// 服务器信息
    QChatServerInfo server_info{};
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatServerUpdateParam() = default;
    QChatServerUpdateParam(const NIMQChatServerUpdateParam& c_param) {
        server_info = c_param.server_info;
        anti_spam_info = c_param.anti_spam_info;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerUpdateResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerUpdateParam ToCParam() const {
        auto cb_holder = new ServerUpdateCallback(cb);
        NIMQChatServerUpdateParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerUpdateResp& resp) {
            InvokeCallback<ServerUpdateCallback, NIMQChatServerUpdateResp>(resp);
        };
        param.server_info = server_info.ToCParam();
        param.anti_spam_info = anti_spam_info.ToCParam();
        return param;
    }
};

/// @struct QChatServerGetServersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetServersParam {
    /// 回调函数
    GetServersCallback cb{nullptr};
    /// 服务器id列表
    std::vector<uint64_t> server_ids{};
    QChatServerGetServersParam() = default;
    QChatServerGetServersParam(const NIMQChatServerGetServersParam& c_param) {
        for (size_t i = 0; i < c_param.server_ids_count; i++) {
            server_ids.push_back(c_param.server_ids[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetServersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetServersParam ToCParam() const {
        auto cb_holder = new GetServersCallback(cb);
        NIMQChatServerGetServersParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGetServersResp& resp) {
            InvokeCallback<GetServersCallback, NIMQChatServerGetServersResp>(resp);
        };
        param.server_ids_count = server_ids.size();
        param.server_ids = const_cast<uint64_t*>(server_ids.data());
        return param;
    }
};

/// @struct QChatServerGetServersPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetServersPageParam {
    /// 回调函数
    GetServersPageCallback cb;
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatServerGetServersPageParam() = default;
    QChatServerGetServersPageParam(const NIMQChatServerGetServersPageParam& c_param) {
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetServersPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetServersPageParam ToCParam() const {
        auto cb_holder = new GetServersPageCallback(cb);
        NIMQChatServerGetServersPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGetServersPageResp& resp) {
            InvokeCallback<GetServersPageCallback, NIMQChatServerGetServersPageResp>(resp);
        };
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatServerInviteParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerInviteParam {
    /// 回调函数
    ServerInviteCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 受邀人id列表
    std::list<std::string> invite_ids{};
    /// 请求生存时间 ms
    uint64_t ttl{0};
    /// 附言
    std::string postscript;
    QChatServerInviteParam() = default;
    QChatServerInviteParam(const NIMQChatServerInviteParam& c_param) {
        server_id = c_param.server_id;
        for (size_t i = 0; i < c_param.invite_ids_count; i++) {
            invite_ids.push_back(c_param.invite_ids[i]);
        }
        ttl = c_param.ttl;
        postscript = c_param.postscript;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerInviteResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerInviteParam ToCParam() const {
        auto cb_holder = new ServerInviteCallback(cb);
        NIMQChatServerInviteParam param = {};
        vec_invite_ids.clear();
        for (auto&& id : invite_ids) {
            vec_invite_ids.push_back(const_cast<char*>(id.c_str()));
        }
        param.invite_ids_count = vec_invite_ids.size();
        param.invite_ids = vec_invite_ids.data();
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerInviteResp& resp) {
            InvokeCallback<ServerInviteCallback, NIMQChatServerInviteResp>(resp);
        };
        param.server_id = server_id;
        param.ttl = ttl;
        param.postscript = const_cast<char*>(postscript.c_str());
        return param;
    }

protected:
    mutable std::vector<char*> vec_invite_ids{};
};

/// @struct QChatServerAcceptInviteParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerAcceptInviteParam {
    /// 回调函数
    ServerAcceptInviteCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 邀请人id
    std::string accid{""};
    /// 请求ID
    uint64_t request_id;
    QChatServerAcceptInviteParam() = default;
    QChatServerAcceptInviteParam(const NIMQChatServerAcceptInviteParam& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid;
        request_id = c_param.request_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerAcceptInviteResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerAcceptInviteParam ToCParam() const {
        auto cb_holder = new ServerAcceptInviteCallback(cb);
        NIMQChatServerAcceptInviteParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerAcceptInviteResp& resp) {
            InvokeCallback<ServerAcceptInviteCallback, NIMQChatServerAcceptInviteResp>(resp);
        };
        param.server_id = server_id;
        param.accid = const_cast<char*>(accid.c_str());
        param.request_id = request_id;
        return param;
    }
};

/// @struct QChatServerRejectInviteParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerRejectInviteParam {
    /// 回调函数
    ServerRejectInviteCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 邀请人id
    std::string accid{""};
    /// 附言
    std::string postscript;
    /// 请求ID
    uint64_t request_id;
    QChatServerRejectInviteParam() = default;
    QChatServerRejectInviteParam(const NIMQChatServerRejectInviteParam& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid;
        postscript = c_param.postscript;
        request_id = c_param.request_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerRejectInviteResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerRejectInviteParam ToCParam() const {
        auto cb_holder = new ServerRejectInviteCallback(cb);
        NIMQChatServerRejectInviteParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerRejectInviteResp& resp) {
            InvokeCallback<ServerRejectInviteCallback, NIMQChatServerRejectInviteResp>(resp);
        };
        param.server_id = server_id;
        param.accid = const_cast<char*>(accid.c_str());
        param.postscript = const_cast<char*>(postscript.c_str());
        param.request_id = request_id;
        return param;
    }
};

/// @struct QChatServerApplyParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerApplyParam {
    /// 回调函数
    ServerApplyCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 请求生存时间 ms
    uint64_t ttl{0};
    /// 附言
    std::string postscript;
    QChatServerApplyParam() = default;
    QChatServerApplyParam(const NIMQChatServerApplyParam& c_param) {
        server_id = c_param.server_id;
        postscript = c_param.postscript;
        ttl = c_param.ttl;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerApplyResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerApplyParam ToCParam() const {
        auto cb_holder = new ServerApplyCallback(cb);
        NIMQChatServerApplyParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerApplyResp& resp) {
            InvokeCallback<ServerApplyCallback, NIMQChatServerApplyResp>(resp);
        };
        param.server_id = server_id;
        param.ttl = ttl;
        param.postscript = const_cast<char*>(postscript.c_str());
        return param;
    }
};

/// @struct QChatServerAcceptApplyParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerAcceptApplyParam {
    /// 回调函数
    ServerAcceptApplyCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 申请人id
    std::string accid{""};
    /// 请求ID
    uint64_t request_id;
    QChatServerAcceptApplyParam() = default;
    QChatServerAcceptApplyParam(const NIMQChatServerAcceptApplyParam& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid;
        request_id = c_param.request_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerAcceptApplyResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerAcceptApplyParam ToCParam() const {
        auto cb_holder = new ServerAcceptApplyCallback(cb);
        NIMQChatServerAcceptApplyParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerAcceptApplyResp& resp) {
            InvokeCallback<ServerAcceptApplyCallback, NIMQChatServerAcceptApplyResp>(resp);
        };
        param.server_id = server_id;
        param.accid = const_cast<char*>(accid.c_str());
        param.request_id = request_id;
        return param;
    }
};

/// @struct QChatServerRejectApplyParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerRejectApplyParam {
    /// 回调函数
    ServerRejectApplyCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 申请人id
    std::string accid{""};
    /// 附言
    std::string postscript;
    /// 请求ID
    uint64_t request_id;
    QChatServerRejectApplyParam() = default;
    QChatServerRejectApplyParam(const NIMQChatServerRejectApplyParam& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid;
        postscript = c_param.postscript;
        request_id = c_param.request_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerRejectApplyResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerRejectApplyParam ToCParam() const {
        auto cb_holder = new ServerRejectApplyCallback(cb);
        NIMQChatServerRejectApplyParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerRejectApplyResp& resp) {
            InvokeCallback<ServerRejectApplyCallback, NIMQChatServerRejectApplyResp>(resp);
        };
        param.server_id = server_id;
        param.accid = const_cast<char*>(accid.c_str());
        param.postscript = const_cast<char*>(postscript.c_str());
        param.request_id = request_id;
        return param;
    }
};

/// @struct QChatServerKickParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerKickParam {
    /// 回调函数
    ServerKickCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 被踢人id列表
    std::list<std::string> accids{};
    QChatServerKickParam() = default;
    QChatServerKickParam(const NIMQChatServerKickParam& c_param) {
        server_id = c_param.server_id;
        for (size_t i = 0; i < c_param.accids_count; i++) {
            accids.push_back(c_param.accids[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerKickResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerKickParam ToCParam() const {
        auto cb_holder = new ServerKickCallback(cb);
        NIMQChatServerKickParam param = {};
        vec_accids.clear();
        for (auto&& id : accids) {
            vec_accids.push_back(const_cast<char*>(id.c_str()));
        }
        param.accids_count = vec_accids.size();
        param.accids = vec_accids.data();
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerKickResp& resp) {
            InvokeCallback<ServerKickCallback, NIMQChatServerKickResp>(resp);
        };
        param.server_id = server_id;
        return param;
    }

protected:
    // 以下字段为内部使用
    mutable std::vector<char*> vec_accids;
};

/// @struct QChatServerLeaveParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerLeaveParam {
    /// 回调函数
    ServerLeaveCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    QChatServerLeaveParam() = default;
    QChatServerLeaveParam(const NIMQChatServerLeaveParam& c_param) {
        server_id = c_param.server_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerLeaveResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerLeaveParam ToCParam() const {
        auto cb_holder = new ServerLeaveCallback(cb);
        NIMQChatServerLeaveParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerLeaveResp& resp) {
            InvokeCallback<ServerLeaveCallback, NIMQChatServerLeaveResp>(resp);
        };
        param.server_id = server_id;
        return param;
    }
};

/// @struct QChatServerUpdateMemberInfoParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerUpdateMemberInfoParam {
    /// 回调函数
    ServerUpdateMemberInfoCallback cb{nullptr};
    /// 更新的成员信息
    QChatMemberInfo member_info{};
    /// 反垃圾信息
    QChatBusinessAntiSpamInfo anti_spam_info{};
    QChatServerUpdateMemberInfoParam() = default;
    QChatServerUpdateMemberInfoParam(const NIMQChatServerUpdateMemberInfoParam& c_param) {
        member_info = c_param.member_info;
        anti_spam_info = c_param.anti_spam_info;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerUpdateMemberInfoResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerUpdateMemberInfoParam ToCParam() const {
        auto cb_holder = new ServerUpdateMemberInfoCallback(cb);
        NIMQChatServerUpdateMemberInfoParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerUpdateMemberInfoResp& resp) {
            InvokeCallback<ServerUpdateMemberInfoCallback, NIMQChatServerUpdateMemberInfoResp>(resp);
        };
        param.member_info = member_info.ToCParam();
        param.anti_spam_info = anti_spam_info.ToCParam();
        return param;
    }
};

/// @struct QChatServerGetMembersParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetMembersParam {
    /// 回调函数
    ServerGetMembersCallback cb{nullptr};
    /// 服务器id和accid列表
    std::list<std::pair<uint64_t, std::string>> server_accid_list;
    QChatServerGetMembersParam() = default;
    QChatServerGetMembersParam(const NIMQChatServerGetMembersParam c_param) {
        server_accid_list.clear();
        for (auto index = 0; index < c_param.server_accid_list_count; index++) {
            server_accid_list.push_back(
                std::make_pair(c_param.server_accid_list[index].server_id, std::string(c_param.server_accid_list[index].accid)));
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetMembersResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetMembersParam ToCParam() const {
        auto cb_holder = new ServerGetMembersCallback(cb);
        for (auto&& item : server_accid_list) {
            NIMQChatServerMemberPair pair = {};
            pair.server_id = item.first;
            pair.accid = const_cast<char*>(item.second.c_str());
            vec_server_accid_list.push_back(pair);
        }
        NIMQChatServerGetMembersParam param = {};
        param.user_data = cb_holder;
        param.server_accid_list = vec_server_accid_list.data();
        param.server_accid_list_count = vec_server_accid_list.size();
        param.cb = [](const NIMQChatServerGetMembersResp& resp) {
            InvokeCallback<ServerGetMembersCallback, NIMQChatServerGetMembersResp>(resp);
        };
        return param;
    }

protected:
    // 以下字段为内部使用
    mutable std::vector<NIMQChatServerMemberPair> vec_server_accid_list;
};

/// @struct QChatServerGetMembersPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetMembersPageParam {
    /// 回调函数
    ServerGetMembersPageCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatServerGetMembersPageParam() = default;
    QChatServerGetMembersPageParam(const NIMQChatServerGetMembersPageParam c_param) {
        server_id = c_param.server_id;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetMembersPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetMembersPageParam ToCParam() const {
        auto cb_holder = new ServerGetMembersPageCallback(cb);
        NIMQChatServerGetMembersPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGetMembersPageResp& resp) {
            InvokeCallback<ServerGetMembersPageCallback, NIMQChatServerGetMembersPageResp>(resp);
        };
        param.server_id = server_id;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatServerSubscribeParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerSubscribeParam {
    /// 回调函数
    ServerSubscribeCallback cb{nullptr};
    /// 操作类型
    NIMQChatSubscribeOpeType ope_type{kNIMQChatSubscribeOpeTypeSubscribe};
    /// 订阅类型
    NIMQChatSubscribeType sub_type{kNIMQChatSubscribeTypeServerNotification};
    /// ID 列表
    std::vector<uint64_t> server_ids{};
    QChatServerSubscribeParam() = default;
    QChatServerSubscribeParam(const NIMQChatServerSubscribeParam& c_param) {
        ope_type = c_param.ope_type;
        sub_type = c_param.sub_type;
        for (size_t i = 0; i < c_param.server_ids_count; i++) {
            server_ids.push_back(c_param.server_ids[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerSubscribeResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerSubscribeParam ToCParam() const {
        auto cb_holder = new ServerSubscribeCallback(cb);
        NIMQChatServerSubscribeParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerSubscribeResp& resp) {
            InvokeCallback<ServerSubscribeCallback, NIMQChatServerSubscribeResp>(resp);
        };
        param.ope_type = ope_type;
        param.sub_type = sub_type;
        param.server_ids_count = server_ids.size();
        param.server_ids = const_cast<uint64_t*>(server_ids.data());
        return param;
    }
};

/// @struct QChatServerBanMemberParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerBanMemberParam {
    /// 回调函数
    ServerBanMemberCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 用户id
    std::string accid;
    /// 自定义字段
    std::string custom;
    QChatServerBanMemberParam() = default;
    QChatServerBanMemberParam(const NIMQChatServerBanMemberParam& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid;
        custom = c_param.custom;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerBanMemberResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerBanMemberParam ToCParam() const {
        auto cb_holder = new ServerBanMemberCallback(cb);
        NIMQChatServerBanMemberParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerBanMemberResp& resp) {
            InvokeCallback<ServerBanMemberCallback, NIMQChatServerBanMemberResp>(resp);
        };
        param.server_id = server_id;
        param.accid = const_cast<char*>(accid.c_str());
        param.custom = const_cast<char*>(custom.c_str());
        return param;
    }
};

/// @struct QChatServerUnbanMemberParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerUnbanMemberParam {
    /// 回调函数
    ServerUnbanMemberCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 用户id
    std::string accid;
    /// 自定义字段
    std::string custom;
    QChatServerUnbanMemberParam() = default;
    QChatServerUnbanMemberParam(const NIMQChatServerUnbanMemberParam& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid;
        custom = c_param.custom;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerUnbanMemberResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerUnbanMemberParam ToCParam() const {
        auto cb_holder = new ServerUnbanMemberCallback(cb);
        NIMQChatServerUnbanMemberParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerUnbanMemberResp& resp) {
            InvokeCallback<ServerUnbanMemberCallback, NIMQChatServerUnbanMemberResp>(resp);
        };
        param.server_id = server_id;
        param.accid = const_cast<char*>(accid.c_str());
        param.custom = const_cast<char*>(custom.c_str());
        return param;
    }
};

/// @struct QChatServerGetBannedMembersPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetBannedMembersPageParam {
    /// 回调函数
    ServerGetBannedMembersPageCallback cb{nullptr};
    /// 服务器ID
    uint64_t server_id{0};
    /// 时间戳
    uint64_t timestamp{0};
    /// 查询条数
    uint32_t limit{100};
    QChatServerGetBannedMembersPageParam() = default;
    QChatServerGetBannedMembersPageParam(const NIMQChatServerGetBannedMembersPageParam& c_param) {
        server_id = c_param.server_id;
        timestamp = c_param.timestamp;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetBannedMembersPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetBannedMembersPageParam ToCParam() const {
        auto cb_holder = new ServerGetBannedMembersPageCallback(cb);
        NIMQChatServerGetBannedMembersPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGetBannedMembersPageResp& resp) {
            InvokeCallback<ServerGetBannedMembersPageCallback, NIMQChatServerGetBannedMembersPageResp>(resp);
        };
        param.server_id = server_id;
        param.timestamp = timestamp;
        param.limit = limit;
        return param;
    }
};

/// @struct QChatServerSearchPageParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerSearchPageParam {
    /// 回调函数
    ServerSearchPageCallback cb{nullptr};
    /// 搜索内容
    std::string keyword{""};
    /// 起始时间
    uint64_t start_time{0};
    /// 结束时间
    uint64_t end_time{0};
    /// 排序规则
    NIMQChatSearchOrder order{kNIMQChatSearchOrderAsc};
    /// 排序规则
    NIMQChatServerSearchSort sort{kNIMQChatServerSearchSortCreateTime};
    /// 搜索的服务器类型, 为空表示搜索所有类型
    std::vector<uint32_t> server_types;
    /// 搜索类型
    NIMQChatServerSearchType search_type{kNIMQChatServerSearchTypeSquare};
    /// 查询条数
    uint32_t limit{100};
    /// 查询游标, 查询的起始位置
    std::string cursor{""};
    QChatServerSearchPageParam() = default;
    QChatServerSearchPageParam(const NIMQChatServerSearchPageParam& c_param) {
        keyword = c_param.keyword ? c_param.keyword : "";
        start_time = c_param.start_time;
        end_time = c_param.end_time;
        order = c_param.order;
        sort = c_param.sort;
        for (size_t i = 0; i < c_param.server_types_count; i++) {
            server_types.push_back(c_param.server_types[i]);
        }
        search_type = c_param.search_type;
        limit = c_param.limit;
        cursor = c_param.cursor ? c_param.cursor : "";
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerSearchPageResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerSearchPageParam ToCParam() const {
        auto cb_holder = new ServerSearchPageCallback(cb);
        NIMQChatServerSearchPageParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerSearchPageResp& resp) {
            InvokeCallback<ServerSearchPageCallback, NIMQChatServerSearchPageResp>(resp);
        };
        param.keyword = const_cast<char*>(keyword.c_str());
        param.start_time = start_time;
        param.end_time = end_time;
        param.order = order;
        param.sort = sort;
        param.server_types = const_cast<uint32_t*>(server_types.data());
        param.server_types_count = server_types.size();
        param.search_type = search_type;
        param.limit = limit;
        param.cursor = const_cast<char*>(cursor.c_str());
        return param;
    }
};

/// @struct QChatServerMemberSearchParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerMemberSearchParam {
    /// 回调函数
    ServerMemberSearchCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 搜索内容
    std::string keyword{""};
    /// 查询条数
    uint32_t limit{100};
    QChatServerMemberSearchParam() = default;
    QChatServerMemberSearchParam(const NIMQChatServerMemberSearchParam& c_param) {
        server_id = c_param.server_id;
        keyword = c_param.keyword;
        limit = c_param.limit;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerMemberSearchResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerMemberSearchParam ToCParam() const {
        auto cb_holder = new ServerMemberSearchCallback(cb);
        NIMQChatServerMemberSearchParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerMemberSearchResp& resp) {
            InvokeCallback<ServerMemberSearchCallback, NIMQChatServerMemberSearchResp>(resp);
        };
        param.server_id = server_id;
        param.keyword = const_cast<char*>(keyword.c_str());
        param.limit = limit;
        return param;
    }
};

/// @struct QChatServerGenerateInviteCodeParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGenerateInviteCodeParam {
    /// 回调函数
    ServerGenerateInviteCodeCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 请求生存时间 ms
    uint64_t ttl{0};
    QChatServerGenerateInviteCodeParam() = default;
    QChatServerGenerateInviteCodeParam(const NIMQChatServerGenerateInviteCodeParam& c_param) {
        server_id = c_param.server_id;
        ttl = c_param.ttl;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGenerateInviteCodeResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGenerateInviteCodeParam ToCParam() const {
        auto cb_holder = new ServerGenerateInviteCodeCallback(cb);
        NIMQChatServerGenerateInviteCodeParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGenerateInviteCodeResp& resp) {
            InvokeCallback<ServerGenerateInviteCodeCallback, NIMQChatServerGenerateInviteCodeResp>(resp);
        };
        param.server_id = server_id;
        param.ttl = ttl;
        return param;
    }
};

/// @struct QChatServerJoinByInviteCodeParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerJoinByInviteCodeParam {
    /// 回调函数
    ServerJoinByInviteCodeCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 邀请码
    std::string invite_code;
    /// 附言
    std::string postscript;
    QChatServerJoinByInviteCodeParam() = default;
    QChatServerJoinByInviteCodeParam(const NIMQChatServerJoinByInviteCodeParam& c_param) {
        server_id = c_param.server_id;
        invite_code = c_param.invite_code;
        postscript = c_param.postscript;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerJoinByInviteCodeResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerJoinByInviteCodeParam ToCParam() const {
        auto cb_holder = new ServerJoinByInviteCodeCallback(cb);
        NIMQChatServerJoinByInviteCodeParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerJoinByInviteCodeResp& resp) {
            InvokeCallback<ServerJoinByInviteCodeCallback, NIMQChatServerJoinByInviteCodeResp>(resp);
        };
        param.server_id = server_id;
        param.invite_code = const_cast<char*>(invite_code.c_str());
        param.postscript = const_cast<char*>(postscript.c_str());
        return param;
    }
};

/// @struct QChatServerGetInviteApplyRecordOfServerParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetInviteApplyRecordOfServerParam {
    /// 回调函数
    ServerGetInviteApplyRecordOfServerCallback cb{nullptr};
    /// 服务器 id
    uint64_t server_id{0};
    /// 起始时间
    uint64_t start_time{0};
    /// 结束时间
    uint64_t end_time{0};
    /// 是否倒序, false: 否, true: 是
    bool reverse{false};
    /// 查询条数
    uint32_t limit{0};
    /// 要排除的记录id
    uint64_t exclude_record_id{0};
    QChatServerGetInviteApplyRecordOfServerParam() = default;
    QChatServerGetInviteApplyRecordOfServerParam(const NIMQChatServerGetInviteApplyRecordOfServerParam& c_param) {
        server_id = c_param.server_id;
        start_time = c_param.start_time;
        end_time = c_param.end_time;
        reverse = c_param.reverse;
        limit = c_param.limit;
        exclude_record_id = c_param.exclude_record_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetInviteApplyRecordOfServerResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetInviteApplyRecordOfServerParam ToCParam() const {
        auto cb_holder = new ServerGetInviteApplyRecordOfServerCallback(cb);
        NIMQChatServerGetInviteApplyRecordOfServerParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGetInviteApplyRecordOfServerResp& resp) {
            InvokeCallback<ServerGetInviteApplyRecordOfServerCallback, NIMQChatServerGetInviteApplyRecordOfServerResp>(resp);
        };
        param.server_id = server_id;
        param.start_time = start_time;
        param.end_time = end_time;
        param.reverse = reverse;
        param.limit = limit;
        param.exclude_record_id = exclude_record_id;
        return param;
    }
};

/// @struct QChatServerGetInviteApplyRecordOfSelfParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerGetInviteApplyRecordOfSelfParam {
    /// 回调函数
    ServerGetInviteApplyRecordOfSelfCallback cb{nullptr};
    /// 起始时间
    uint64_t start_time{0};
    /// 结束时间
    uint64_t end_time{0};
    /// 是否倒序, false: 否, true: 是
    bool reverse{false};
    /// 查询条数
    uint32_t limit{0};
    /// 要排除的记录id
    uint64_t exclude_record_id{0};
    QChatServerGetInviteApplyRecordOfSelfParam() = default;
    QChatServerGetInviteApplyRecordOfSelfParam(const NIMQChatServerGetInviteApplyRecordOfSelfParam& c_param) {
        start_time = c_param.start_time;
        end_time = c_param.end_time;
        reverse = c_param.reverse;
        limit = c_param.limit;
        exclude_record_id = c_param.exclude_record_id;
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerGetInviteApplyRecordOfSelfResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerGetInviteApplyRecordOfSelfParam ToCParam() const {
        auto cb_holder = new ServerGetInviteApplyRecordOfSelfCallback(cb);
        NIMQChatServerGetInviteApplyRecordOfSelfParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerGetInviteApplyRecordOfSelfResp& resp) {
            InvokeCallback<ServerGetInviteApplyRecordOfSelfCallback, NIMQChatServerGetInviteApplyRecordOfSelfResp>(resp);
        };
        param.start_time = start_time;
        param.end_time = end_time;
        param.reverse = reverse;
        param.limit = limit;
        param.exclude_record_id = exclude_record_id;
        return param;
    }
};

/// @struct QChatServerMarkReadParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerMarkReadParam {
    /// 回调函数
    ServerMarkReadCallback cb{nullptr};
    /// 服务器 id 列表
    std::vector<uint64_t> server_ids;
    QChatServerMarkReadParam() = default;
    QChatServerMarkReadParam(const NIMQChatServerMarkReadParam& c_param) {
        for (size_t i = 0; i < c_param.server_ids_count; i++) {
            server_ids.push_back(c_param.server_ids[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerMarkReadResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerMarkReadParam ToCParam() const {
        auto cb_holder = new ServerMarkReadCallback(cb);
        NIMQChatServerMarkReadParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerMarkReadResp& resp) {
            InvokeCallback<ServerMarkReadCallback, NIMQChatServerMarkReadResp>(resp);
        };
        param.server_ids_count = server_ids.size();
        param.server_ids = const_cast<uint64_t*>(server_ids.data());
        return param;
    }
};

/// @struct QChatServerSubscribeAllChannelParam
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatServerSubscribeAllChannelParam {
    /// 回调函数
    ServerSubscribeAllChannelCallback cb{nullptr};
    /// 订阅类型
    NIMQChatSubscribeType sub_type;
    /// 服务器 id 列表
    std::vector<uint64_t> server_ids;
    QChatServerSubscribeAllChannelParam() = default;
    QChatServerSubscribeAllChannelParam(const NIMQChatServerSubscribeAllChannelParam& c_param) {
        sub_type = c_param.sub_type;
        for (size_t i = 0; i < c_param.server_ids_count; i++) {
            server_ids.push_back(c_param.server_ids[i]);
        }
        cb = [c_callback = c_param.cb, user_data = c_param.user_data](const QChatServerSubscribeAllChannelResp& response) {
            auto c_response = response.ToCParam();
            c_response.user_data = user_data;
            c_callback(c_response);
        };
    }
    const NIMQChatServerSubscribeAllChannelParam ToCParam() const {
        auto cb_holder = new ServerSubscribeAllChannelCallback(cb);
        NIMQChatServerSubscribeAllChannelParam param = {};
        param.user_data = cb_holder;
        param.cb = [](const NIMQChatServerSubscribeAllChannelResp& resp) {
            InvokeCallback<ServerSubscribeAllChannelCallback, NIMQChatServerSubscribeAllChannelResp>(resp);
        };
        param.sub_type = sub_type;
        param.server_ids_count = server_ids.size();
        param.server_ids = const_cast<uint64_t*>(server_ids.data());
        return param;
    }
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_SERVER_CPP_DEF_H__
