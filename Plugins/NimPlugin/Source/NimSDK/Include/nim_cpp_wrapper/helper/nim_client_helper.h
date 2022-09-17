/** @file nim_client_helper.h
 * @brief Client 辅助方法和数据结构定义
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @date 2015/09/07
 */
#ifndef _NIM_SDK_CPP_CLIENT_HELPER_H_
#define _NIM_SDK_CPP_CLIENT_HELPER_H_

#include <functional>
#include <list>
#include <map>
#include <string>
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"
#include "nim_define_include.h"
#include "nim_wrapper_util/nim_json_util.h"
#include "public_defines.h"

/**
 * @namespace nim
 * @brief namespace nim
 */
namespace nim {

class Client;
/** @brief SDK设置项 */
struct NIM_SDK_CPPWRAPPER_DLL_API SDKConfig {
    // global_config
    /// string 选填，云信后台配置的推送证书名称 ( iOS/Mac有效)
    std::string push_cer_name_;
    /// string 选填，推送的设备token (iOS/Mac有效)
    std::string push_token_;
    /// string 数据库秘钥，必填，目前只支持最多32个字符的加密密钥！建议使用32个字符
    std::string database_encrypt_key_;
    /// 是否需要预下载附件(图片和语音),选填,默认为true,如果有对带宽流量有较高要求的请关闭该选项，改为上层开发者按需下载附件文件
    bool preload_attach_;
    /// int 预下载图片质量,选填,范围0-100
    int preload_image_quality_;
    /// string 预下载图片基于长宽做内缩略,选填,比如宽100高50,则赋值为100x50,中间为字母小写x
    std::string preload_image_resize_;
    /// string 预下载图片命名规则，以{filename}为token进行替换
    std::string preload_image_name_template_;
    /// NIMSDKLogLevel 定义见NIMSDKLogLevel，选填，SDK默认的内置级别为kNIMSDKLogLevelPro
    NIMSDKLogLevel sdk_log_level_;
    /// bool 设置是否已读未读状态多端同步，默认true
    bool sync_session_ack_;
    /// int 登录重试最大次数，如需设置建议设置大于3次，默认填0，SDK默认设置次数
    int login_max_retry_times_;
    /// int 自定义通讯超时时间，暂时不开放设置
    int custom_timeout_;
    /// bool 是否启用HTTPS协议，默认为true
    bool use_https_;
    /// bool 群通知是否计入未读数，默认为false
    bool team_notification_unread_count_;
    /// bool 语音消息未接通消息是否计入未读数，默认为false
    bool vchat_miss_unread_count_;
    /// bool 撤回消息是否重新计算未读消息计数，默认为false
    bool reset_unread_count_when_recall_;
    /// bool，在调用 Login 接口后无论成功是否上报历史错误日志到服务器（目前支持 408、415、500）默认为false
    bool upload_sdk_events_after_login_;
    /// bool 开启对动图缩略图的支持，默认为false,开启后获取的缩略图为原格式，关闭后获取的缩略图为第一帧静态图
    bool animated_image_thumbnail_enabled_;
    /// bool 客户端反垃圾，默认为false，如需开启请提前咨询技术支持或销售
    bool client_antispam_;
    /// bool 群消息已读功能开关， 默认为false，如需开启请提前咨询技术支持或销售
    bool team_msg_ack_;
    /// bool 在进行重新登录前是否先刷新一下lbs,对于切换网络的场景适用
    bool need_update_lbs_befor_relogin_;
    /// list<NIMMessageType> 更新会话时忽略某种消息类型，默认为空
    std::list<NIMMessageType> session_ignore_msg_types_;

    /***********消息“已接收回执”发送配置 begin************/
    /// bool 是否开启缓存式“已接收回执”发送，程序可能收到大量消息以至触发频控时可以考虑开启此开关 缺省 false 关闭
    bool caching_markread_;
    /// uint32 caching_markread_ == true 时有效 缓存时间 单位ms 缺省 1000
    uint32_t caching_markread_time_;
    /// uint32 caching_markread_ == true 时有效 缓存的最大消息条数  缺省 10
    uint32_t caching_markread_count_;
    /***********消息“已接收回执”发送配置 end************/

    /***********用户数据本地备份与恢复 begin************/
    /// bool 是否开启用户数据备份(本地)功能  缺省true
    bool enable_user_datafile_backup_;
    /// bool 是否开启用户数据恢复(本地)功能  缺省false
    bool enable_user_datafile_restore_;
    /// bool 是否使用缺省的用户数据恢复(本地)方案  缺省false enable_user_datafile_restore_ == true 生效
    bool enable_user_datafile_defrestoreproc_;
    /// string 用户数据文件备份（本地）目录，缺省在数据文件所在目录创建一个db_file.back目录
    std::string user_datafile_localbackup_folder_;
    /***********用户数据本地备份与恢复 end************/

    /***********IP地址族相关设置 begin************/
    /// int IP地址族设置 0:ipv4 1:ipv6 2:auto,经SDK测试后，自行选择,会有少许性能损耗。缺省 0(ipv4)
    int ip_protocol_version_;
    /***********地址族相关设置 end************/

    /// bool 是否为专属集群 {true,false} def:false
    bool dedicated_cluste_flag_;
    /// int 登录时使用的握手协议类型 0:支持配置多种对称与非对称加密算法,1:只支持RAS + RC4，缺省 1
    int hand_shake_type_;
    /// int  "交换密钥"协议加密算法 {1(RSA),2(SM2)}, def:1(RSA) 非对称加密
    int nego_key_neca_;
    /// int 通信加密算法 {1(RC4),2(AES128),4(SM4)} def:1(RC4) 对称加密
    int comm_neca_;
    /// string 私有云服务器相关地址配置文件本地绝对路径，如果不填默认执行文件目录下的server_conf.txt
    std::string server_conf_file_path_;
    // private_server_setting 私有服务器配置（设置方法有两种，一个是配置以下信息，一个是通过配置server_conf_file_path_地址，信息从文件中读取）
    /// bool 是否使用私有服务器，如果使用私有服务器，则必须设置为true
    bool use_private_server_;
    /// string lbs地址，如果选择使用私有服务器，则必填
    std::string lbs_address_;
    /// string list  lbs备用地址,没有可不填
    std::list<std::string> lbs_backup_address_;
    /// string nos lbs地址，如果选择使用私有服务器，则必填
    std::string nos_lbs_address_;
    /// string 默认link服务器地址，如果选择使用私有服务器，ip_protocol_version_ != 1(ipv4 or auto)则必填
    std::string default_link_address_;
    /// string 默认link ipv6服务器地址，如果选择使用私有服务器，ip_protocol_version_ == 1(使用ipv6)则必填
    std::string default_link_address_ipv6_;
    /// string 默认nos 上传服务器地址，如果选择使用私有服务器，则必填
    std::string default_nos_upload_address_;
    /// string 默认nos 上传服务器主机地址，仅 kNIMUseHttps设置为true 时有效，用作 https 上传时的域名校验及 http header host 字段填充
    std::string default_nos_upload_host_;
    /// string  RSA public key，如果选择使用私有服务器，则必填 【6.9.0版本后已废弃】
    std::string rsa_public_key_module_;
    /// int RSA version，如果选择使用私有服务器，则必填 【6.9.0版本后已废弃】
    int rsa_version_;

    /// string  "交换密钥"协议加密算法密钥 part A 自定义时则必填 BigNumHex string 不含0x RSA:module,SM2:X
    std::string nego_key_neca_key_parta_;
    /// string  非对称加密算法key2 RSA:EXP,SM2: SM2Y 自定义时则必填
    std::string nego_key_neca_key_partb_;
    /// int  非对称加密算法的 key version 自定义时则必填
    int nego_key_neca_key_version_;

    /// string nos 下载地址拼接模板，用于拼接最终得到的下载地址
    std::string nos_download_address_;
    /// string 需要被加速主机名【8.1.0版本以及后不建议使用，推荐nos_accelerate_host_list_】
    std::string nos_accelerate_host_;
    /// string array，需要被加速主机名列表
    std::vector<std::string> nos_accelerate_host_list_;
    /// string nos 加速地址拼接模板，用于获得加速后的下载地址
    std::string nos_accelerate_address_;

    /***********IP地址族相关设置 begin************/
    /// string 探测ipv4地址类型使用的url,ip_protocol_version_ == 2(auto) 时生效
    std::string probe_ipv4_url_;
    /// string 探测ipv6地址类型使用的url,ip_protocol_version_ == 2(auto) 时生效
    std::string probe_ipv6_url_;
    /***********地址族相关设置 end************/

    /// map 数据同步类型 key(28:置顶会话) value(0:不同步,1:自动同步)
    std::map<int /*key */, int /*value */> sync_data_type_list_;
    /// string list httpdns服务请求地址，如果没有特定地址可以不填
    std::list<std::string> http_dns_server_interface_;
    /// bool 是否优先使用cdn域名
    bool priority_use_cdn_host_;
    /// string 是否禁用 macOS 下的 App Nap 功能，默认为 true
    bool disable_app_nap_;
    /// bool 删除会话时是否在数据库缓存会话原数据，默认为 false
    bool cache_session_data_when_delete_;
    /// 客户端sdk类型
    NIMSDKType sdk_type;
    /// sdk可读版本号
    std::string sdk_human_version;

    /***********融合存储相关************/
    std::string mock_refer_;
    std::string mock_ua_;
    /// 融合云存储认证方式 1=refer鉴权,2=基于时间的token鉴权，3=基于url的token鉴权，4=custom鉴权
    int fcs_auth_type_;
    /// 是否开启融合云存储
    bool custom_enable_fcs_;

    /** 构造函数 */
    SDKConfig();

public:
    void SetCustomClientType(int type);
    int GetCustomClientType() const;

private:
    friend class Client;
    /// (可选)int, 自定义客户端类型字段,启用该配置时必须0,否则初始化会报错
    std::pair<bool, int> custom_client_type_;
};

/** @brief 多端登陆客户端信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API OtherClientPres {
    /// 第三方账号
    std::string app_account_;
    /// 客户端类型, 见NIMClientType
    NIMClientType client_type_;
    /// 登录系统类型,比如ios 6.0.1
    std::string client_os_;
    /// 登录设备的mac地址
    std::string mac_address_;
    /// 设备id，uuid
    std::string device_id_;
    /// 本次登陆时间, 精度到ms
    int64_t login_time_;
    /// 自定义字段
    std::string custom_data_;
    /// int, 自定义客户端类型字段,大于0
    int custom_client_type_;
    /** 构造函数 */
    OtherClientPres()
        : login_time_(0)
        , custom_client_type_(0) {}
};

/** @brief 登录结果回调信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API LoginRes {
    /// 返回的错误码NIMResCode
    NIMResCode res_code_;
    /// 是否为重连过程
    bool relogin_;
    /// 登录步骤NIMLoginStep
    NIMLoginStep login_step_;
    /// 其他端的在线状态列表，登录成功才会返回这部分内容
    std::list<OtherClientPres> other_clients_;
    /// SDK是否在重试，如果为false，开发者需要检查登录步骤和错误码，明确问题后调用手动重连接口进行登录操作
    bool retrying_;
    /** 构造函数 */
    LoginRes()
        : relogin_(false)
        , retrying_(true) {}
};

/** @brief 被踢结果回调信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API KickoutRes {
    /// int, 客户端类型NIMClientType
    NIMClientType client_type_;
    /// 返回的被踢原因NIMKickReason
    NIMKickReason kick_reason_;
    /// string 返回的被踢描述
    std::string kickout_description_;
    /// 自定义客户端类型，若没有，服务器会填0
    int32_t custom_client_type_;
};

/** @brief 多端登录回调信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API MultiSpotLoginRes {
    /// NIMMultiSpotNotifyType 多点登录通知类型
    NIMMultiSpotNotifyType notify_type_;
    /// 其他端的在线状态列表
    std::list<OtherClientPres> other_clients_;
};

/** @brief 踢人结果回调信息 */
struct NIM_SDK_CPPWRAPPER_DLL_API KickOtherRes {
    /// 返回的错误码NIMResCode
    NIMResCode res_code_;
    /// 设备id，uuid
    std::list<std::string> device_ids_;
};

/** @fn bool ParseOtherClientsPres(const nim_cpp_wrapper_util::Json::Value array_objs, std::list<OtherClientPres> &outs)
 * 解析多端登录客户端信息
 * @param[in] array_objs 多端登录客户端信息(Json Value数据)
 * @param[out] outs 多端登录客户端信息
 * @return bool 解析成功 或失败
 */
bool NIM_SDK_CPPWRAPPER_DLL_API ParseOtherClientsPres(const nim_cpp_wrapper_util::Json::Value array_objs, std::list<OtherClientPres>& outs);

/// @struct LoginParams
struct NIM_SDK_CPPWRAPPER_DLL_API LoginParams {
    /// 自定义登录数据，会同步给其他端
    std::string custom_data_;
    /// 鉴权方式，0表示默认校验方式，1表示基于appSecret计算的token方式，2表示基于第三方回调的token方式，默认0
    NIMAuthType auth_type_;
    /// 第三方回调方式鉴权要传递给服务器的拓展数据
    std::string login_ex_;
    LoginParams()
        : auth_type_(kNIMAuthTypeDefault) {}
};

}  // namespace nim

#endif  //_NIM_SDK_CPP_CLIENT_HELPER_H_
