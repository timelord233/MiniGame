/** @file nim_cpp_api.h
 * @brief NIM集合头文件
 * @copyright (c) 2015-2017, NetEase Inc. All rights reserved
 * @date 2015/10/20
 */

#ifndef WRAPPER_NIM_CPP_WRAPPER_NIM_CPP_API_H_
#define WRAPPER_NIM_CPP_WRAPPER_NIM_CPP_API_H_

// 以dll方式使用时的导出定义
#include "nim_cpp_wrapper/nim_sdk_cpp_wrapper.h"

// 客户端登录，注销以及相关回调接口注册API
#include "nim_cpp_wrapper/api/nim_cpp_client.h"
#include "nim_cpp_wrapper/helper/nim_client_helper.h"
// 代理设置等工具类API
#include "nim_cpp_wrapper/api/nim_cpp_global.h"
// 数据同步通知API
#include "nim_cpp_wrapper/api/nim_cpp_data_sync.h"
// 好友关系相关API
#include "nim_cpp_wrapper/api/nim_cpp_friend.h"
#include "nim_cpp_wrapper/helper/nim_friend_helper.h"
// 用户信息相关API
#include "nim_cpp_wrapper/api/nim_cpp_user.h"
#include "nim_cpp_wrapper/helper/nim_user_helper.h"
// 消息历史相关API
#include "nim_cpp_wrapper/api/nim_cpp_msglog.h"
#include "nim_cpp_wrapper/helper/nim_msglog_helper.h"
// 会话相关API
#include "nim_cpp_wrapper/api/nim_cpp_talk.h"
#include "nim_cpp_wrapper/helper/nim_talk_helper.h"
// 系统通知相关API
#include "nim_cpp_wrapper/api/nim_cpp_sysmsg.h"
#include "nim_cpp_wrapper/helper/nim_sysmsg_helper.h"
// 群组相关API
#include "nim_cpp_wrapper/api/nim_cpp_team.h"
#include "nim_cpp_wrapper/helper/nim_team_helper.h"
// NOS云存储服务相关API
#include "nim_cpp_wrapper/api/nim_cpp_nos.h"
#include "nim_cpp_wrapper/helper/nim_nos_helper.h"
// 会话列表相关API
#include "nim_cpp_wrapper/api/nim_cpp_session.h"
#include "nim_cpp_wrapper/helper/nim_session_helper.h"
// 插件类相关API(聊天室)
#include "nim_cpp_wrapper/api/nim_cpp_plugin_in.h"
// 工具辅助类API
#include "nim_cpp_wrapper/api/nim_cpp_tool.h"
// 超大群
#include "nim_cpp_wrapper/api/nim_cpp_super_team.h"
#include "nim_cpp_wrapper/helper/nim_super_team_helper.h"
// 文档共享相关API
#include "nim_cpp_wrapper/api/nim_cpp_doc_trans.h"
#include "nim_cpp_wrapper/helper/nim_doc_trans_helper.h"
// 事件订阅
#include "nim_cpp_wrapper/api/nim_cpp_subscribe_event.h"
#include "nim_cpp_wrapper/helper/nim_subscribe_event_helper.h"
// 独立信令
#include "nim_cpp_wrapper/api/nim_cpp_signaling.h"
#include "nim_cpp_wrapper/helper/nim_signaling_helper.h"
// 会话服务
#include "nim_cpp_wrapper/api/nim_cpp_session_online_service.h"
#include "nim_cpp_wrapper/helper/nim_session_online_service_helper.h"
// 透传服务
#include "nim_cpp_wrapper/api/nim_cpp_pass_through_proxy.h"
#include "nim_cpp_wrapper/api/nim_cpp_talkex.h"
#include "nim_cpp_wrapper/helper/nim_pass_through_proxy_helper.h"
#include "nim_cpp_wrapper/helper/nim_talkex_helper_collect.h"
/* 仅在 Windows 平台下使用的头 */
#if defined(WIN32)
// 数据通道相关API(白板等)
#include "nim_cpp_wrapper/api/nim_cpp_rts.h"
// 音视频,音视频设备相关API
#include "nim_cpp_wrapper/api/nim_cpp_vchat.h"
// 机器人
#include "nim_cpp_wrapper/api/nim_cpp_robot.h"
#include "nim_cpp_wrapper/helper/nim_robot_helper.h"
#endif
#include "nim_cpp_wrapper/helper/nim_msg_helper.h"
#include "nim_cpp_wrapper/helper/nim_sdk_loader_helper.h"
#include "nim_cpp_wrapper/helper/nim_tool_helper.h"

#endif  // WRAPPER_NIM_CPP_WRAPPER_NIM_CPP_API_H_
