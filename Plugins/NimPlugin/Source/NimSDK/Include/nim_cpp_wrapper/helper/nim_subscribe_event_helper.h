/** @file nim_subscribe_event_helper.h
 * @brief 事件订阅辅助方法和数据结构定义
 * @copyright (c) 2017, NetEase Inc. All rights reserved
 * @date 2017/03/23
 */

#ifndef _NIM_SDK_CPP_SUBSCRIBE_EVENT_HELPER_H_
#define _NIM_SDK_CPP_SUBSCRIBE_EVENT_HELPER_H_

#include <functional>
#include <list>
#include <set>
#include <string>
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"
#include "nim_define_include.h"
#include "nim_wrapper_util/nim_json_util.h"
/**
 * @namespace nim
 * @brief namespace nim
 */
namespace nim {

/** @brief 事件数据 */
struct NIM_SDK_CPPWRAPPER_DLL_API EventData {
    /// 事件类型，服务器保留1～99999的事件类型，客户端自定义事件类型需大于99999
    int event_type_;
    /// 事件状态，在线状态事件服务器保留1～9999的事件值，客户端自定义事件值需大于9999
    int event_value_;
    /// 客户端生成的消息id
    std::string client_msg_id_;
    /// 用户自定义事件扩展属性，最长4K
    std::string config_;
    /// 事件有效期，单位：秒，时间范围：60s到7天
    int64_t ttl_;
    /// 事件广播类型
    NIMEventBroadcastType broadcast_type_;
    /// 事件同步类型
    NIMEventSyncType sync_self_;

public:
    /// TtlType枚举值
    int readonly_ttl_type;
    /// 是否需要持久化(可选字段)，默认为需要持久化,0:不需要持久化，1：需要持久化
    int readonly_durable_;
    /// 事件发布的时间戳，服务器补充
    int64_t readonly_event_time_;
    /// 服务端生成的消息id
    std::string readonly_server_msg_id_;
    /// 发送客户端类型
    int readonly_client_type_;
    /// 预定义事件的扩展字段（在线状态事件：在线的客户端类型Json）
    std::string readonly_nim_config_;
    /// 多端配置信息字段，JSON格式{"clent_type":"clent_config","1":"xxx","2":"xxx"}
    std::string readonly_multi_config_;

public:
    /// 事件发布者的accid
    std::string readonly_publisher_accid_;
    /// 发送设备id
    std::string readonly_consid_;

    /** 构造函数 */
    EventData()
        : event_type_(0)
        , event_value_(0)
        , ttl_(0)
        , broadcast_type_(kNIMEventBroadcastTypeOnline)
        , sync_self_(kNIMEventSyncTypeNoSelf)
        , readonly_ttl_type(0)
        , readonly_durable_(0)
        , readonly_event_time_(0)
        , readonly_client_type_(0) {}

    /** @fn std::string ToJsonString() const
     * @brief 组装Json Value字符串
     * @return string Json Value字符串
     */
    std::string ToJsonString() const {
        nim_cpp_wrapper_util::Json::Value values;
        values[kNIMEventEventType] = event_type_;
        values[kNIMEventEventValue] = event_value_;
        values[kNIMEventMsgIdClient] = client_msg_id_;
        values[kNIMEventConfig] = config_;
        values[kNIMEventTTL] = ttl_;
        values[kNIMEventBroadcastType] = broadcast_type_;
        values[kNIMEventSyncSelf] = sync_self_;

        return GetJsonStringWithNoStyled(values);
    }
};

/** @brief 在线客户端类型，此结构体只用于在线状态事件的kNIMEventNimConfig字段 */
struct NIM_SDK_CPPWRAPPER_DLL_API EventOnlineClientType {
    /// 在线客户端类型集合
    std::set<NIMClientType> online_client_type_;

    /** @fn bool ParseConfig(const std::string& multi_config_json)
     * @brief 针对在线状态事件，从kNIMEventNimConfig的Json Value解析出在线客户端类型
     * @param[in] nim_config_json 在线客户端类型Json
     * @return bool 解析成功 或失败
     */
    bool ParseConfig(const std::string& multi_config_json) {
        nim_cpp_wrapper_util::Json::Value values;
        if (nim::ParseJsonValue(multi_config_json, values) && values.isObject()) {
            if (values.isMember(kNIMEventNimConfigOnlineClient)) {
                nim_cpp_wrapper_util::Json::Value online_values = values[kNIMEventNimConfigOnlineClient];
                if (online_values.isArray()) {
                    for (int i = 0; i < (int)online_values.size(); ++i) {
                        NIMClientType client_type = (NIMClientType)online_values[i].asUInt();
                        online_client_type_.insert(client_type);
                    }

                    return true;
                }
            }
        }

        return false;
    }
};

/** @brief 事件订阅数据 */
struct NIM_SDK_CPPWRAPPER_DLL_API EventSubscribeData {
    /// 事件类型
    int event_type_;
    /// 订阅有效期，单位：秒，范围：60s到30天
    int64_t ttl_;
    /// 订阅的事件的同步类型
    NIMEventSubscribeSyncEventType sync_event_;

    /// 被订阅人（事件发布人）的accid
    std::string publisher_accid_;
    /// 订阅人的accid
    std::string subscribe_accid_;
    /// 订阅时间戳
    int64_t subscribe_time_;
    /** 构造函数 */
    EventSubscribeData()
        : event_type_(0)
        , ttl_(0)
        , sync_event_(kNIMEventSubscribeSyncTypeUnSync)
        , subscribe_time_(0) {}
};

/** @fn bool ParseEventData(const std::string& event_json, EventData& event_data)
 * @brief 解析事件数据
 * @param[in] event_json    事件数据(Json Value数据字符串)
 * @param[out] event_data    事件数据
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseEventData(const std::string& event_json, EventData& event_data);

/** @fn bool ParseEventData(const nim_cpp_wrapper_util::Json::Value& values, EventData& event_data)
 * @brief 解析事件数据
 * @param[in] values        事件数据(Json Value数据字符串)
 * @param[out] event_data    事件数据
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseEventData(const nim_cpp_wrapper_util::Json::Value& values, EventData& event_data);

/** @fn bool ParseEventDataList(const std::string& event_list_json, std::list<EventData>& event_data_list)
 * @brief 解析批量事件数据
 * @param[in] event_list_json    事件数据(Json Value数据字符串)
 * @param[out] event_data_list    事件数据
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseEventDataList(const std::string& event_list_json, std::list<EventData>& event_data_list);

/** @fn bool ParseEventSubscribeData(const nim_cpp_wrapper_util::Json::Value& values, EventSubscribeData& event_subscribe)
 * @brief 解析事件订阅数据
 * @param[in] values            事件订阅数据(Json Value数据)
 * @param[out] event_subscribe    事件订阅数据
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseEventSubscribeData(const nim_cpp_wrapper_util::Json::Value& values, EventSubscribeData& event_subscribe);

/** @fn bool ParseEventSubscribeDataList(const std::string& subscribe_list_json, std::list<EventSubscribeData>& event_subscribe_list)
 * @brief 解析事件订阅数据列表
 * @param[in] subscribe_list_json        事件订阅数据(Json Value数据字符串)
 * @param[out] event_subscribe_list    事件订阅数据列表
 * @return bool 解析成功 或失败
 */
NIM_SDK_CPPWRAPPER_DLL_API bool ParseEventSubscribeDataList(const std::string& subscribe_list_json,
    std::list<EventSubscribeData>& event_subscribe_list);

}  // namespace nim

#endif  //_NIM_SDK_CPP_SUBSCRIBE_EVENT_HELPER_H_
