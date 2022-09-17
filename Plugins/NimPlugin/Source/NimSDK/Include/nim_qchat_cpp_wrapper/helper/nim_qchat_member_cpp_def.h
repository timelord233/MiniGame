/**
 * @file nim_qchat_member_cpp_def.h
 * @author NetEase Yunxin
 * @brief
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright (c) 2022, NetEase Inc. All rights reserved
 *
 */
#ifndef __NIM_QCHAT_MEMBER_CPP_DEF_H__
#define __NIM_QCHAT_MEMBER_CPP_DEF_H__

#include "nim_qchat_cpp_wrapper/helper/nim_qchat_public_cpp_def.h"
#include "nim_qchat_member_def.h"

namespace nim_qchat {

/** @struct QChatMemberInfo 圈组服务器成员信息 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMemberInfo {
    /// server id
    uint64_t server_id{0};
    /// channel id
    uint64_t channel_id{0};
    /// 用户accid
    std::string accid{""};
    /// 昵称
    std::string nick{""};
    /// 头像url
    std::string avatar{""};
    /// 自定义字段
    std::string custom{""};
    /// 用户类型，0:普通用户 1:所有者
    uint32_t type{0};
    /// 加入时间
    uint64_t join_time{0};
    /// 邀请人
    std::string inviter{""};
    /// 有效标记，false:无效 true:有效
    bool valid_flag{true};
    /// 创建时间
    uint64_t create_time{0};
    /// 更新时间
    uint64_t update_time{0};
    QChatMemberInfo() = default;
    QChatMemberInfo(const NIMQChatMemberInfo& c_param) {
        server_id = c_param.server_id;
        channel_id = c_param.channel_id;
        accid = c_param.accid ? c_param.accid : "";
        nick = c_param.nick ? c_param.nick : "";
        avatar = c_param.avatar ? c_param.avatar : "";
        custom = c_param.custom ? c_param.custom : "";
        type = c_param.type;
        join_time = c_param.join_time;
        inviter = c_param.inviter ? c_param.inviter : "";
        valid_flag = c_param.valid_flag;
        create_time = c_param.create_time;
        update_time = c_param.update_time;
    }
    const NIMQChatMemberInfo ToCParam() const {
        NIMQChatMemberInfo c_param = {};
        c_param.server_id = server_id;
        c_param.channel_id = channel_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.nick = const_cast<char*>(nick.c_str());
        c_param.avatar = const_cast<char*>(avatar.c_str());
        c_param.custom = const_cast<char*>(custom.c_str());
        c_param.type = type;
        c_param.join_time = join_time;
        c_param.inviter = const_cast<char*>(inviter.c_str());
        c_param.valid_flag = valid_flag;
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        return c_param;
    }
};

/** @struct QChatMemberBanInfo 圈组服务器成员封禁信息 */
struct NIM_QCHAT_SDK_CPPWRAPPER_DLL_API QChatMemberBanInfo {
    /// server id
    uint64_t server_id{0};
    /// 用户accid
    std::string accid{""};
    /// 自定义字段
    std::string custom{""};
    /// 封禁时间
    uint64_t ban_time{0};
    /// 有效标记，false:无效 true:有效
    bool valid_flag{false};
    /// 创建时间
    uint64_t create_time{0};
    /// 更新时间
    uint64_t update_time{0};
    QChatMemberBanInfo() = default;
    QChatMemberBanInfo(const NIMQChatMemberBanInfo& c_param) {
        server_id = c_param.server_id;
        accid = c_param.accid ? c_param.accid : "";
        custom = c_param.custom ? c_param.custom : "";
        ban_time = c_param.ban_time;
        valid_flag = c_param.valid_flag;
        create_time = c_param.create_time;
        update_time = c_param.update_time;
    }
    const NIMQChatMemberBanInfo ToCParam() const {
        NIMQChatMemberBanInfo c_param = {};
        c_param.server_id = server_id;
        c_param.accid = const_cast<char*>(accid.c_str());
        c_param.custom = const_cast<char*>(custom.c_str());
        c_param.ban_time = ban_time;
        c_param.valid_flag = valid_flag;
        c_param.create_time = create_time;
        c_param.update_time = update_time;
        return c_param;
    }
};

}  // namespace nim_qchat

#endif  // __NIM_QCHAT_MEMBER_CPP_DEF_H__
