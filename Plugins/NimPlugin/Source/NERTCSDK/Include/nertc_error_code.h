/** @file nertc_error_code.h
  * @brief The definition of error codes of NERtc SDK.
  * @copyright (c) 2021, NetEase Inc. All rights reserved.
  */

#ifndef NERTC_ERROR_CODE_H
#define NERTC_ERROR_CODE_H

 /**
 * @namespace nertc
 * @brief namespace nertc
 */
namespace nertc
{
/** 
 * @if English
 * Error codes.
 * <br>Error codes are returned when a problem that cannot be recovered without app intervention has occurred. 
 * @endif
 * @if Chinese
 * 错误代码。
 * <br>错误代码意味着 SDK 遇到不可恢复的错误，需要应用程序干预。
* @endif
*/
typedef enum
{
	/**
	 * @if English
	 * No errors.
	 * @endif
	 * @if Chinese
	 * 没有错误
	 * @endif
	 */
	kNERtcNoError = 0,		
	//Error codes are returned when resources are wrongly assigned. Such kind of error code is not returned when the SDK sends the normal permissions.
	/** 
	 * @if English
	 * No permissions. Possible reasons: 
	 * - Audio and Video Call is not enabled, whose trial period is overdue or fees are not renewed.
	 * - Token is not specified in safe mode when joining a channel.
	 * - Other permission-related problems.
	 * @endif
	 * @if Chinese
	 * - 权限不足。原因包括：
	 * - 未开通音视频通话 2.0 服务，或试用期已过、未及时续费等。
	 * - 安全模式下加入房间时未设置 Token。
	 * - 其他权限问题。
	 * @endif
	 */
	kNERtcErrChannelReservePermissionDenied = 403,	
	/**
	 * @if English
	 * Request timeouts.
	 * @endif
	 * @if Chinese
	 * 请求超时
	 * @endif
	 */
	kNERtcErrChannelReserveTimeOut = 408,			
	/**
	 * @if English
	 * Error codes are returned when parameters are requested in the server.
	 * @endif
	 * @if Chinese
	 * 服务器请求参数错误
	 * @endif
	 */
	kNERtcErrChannelReserveErrorParam = 414,		
	/**
	 * @if English
	 * Unknown errors are returned when channels are assigned in the server.
	 * @endif
	 * @if Chinese
	 * 分配房间服务器未知错误
	 * @endif
	 */
	kNERtcErrChannelReserveServerFail = 500,		
	/**
	 * @if English
	 * Only two users are supported in the same channel. If the third user wants to share the same channel name, assign another channel.
	 * @endif
	 * @if Chinese
	 * 只支持两个用户, 有第三个人试图使用相同的房间名分配房间
	 * @endif
	 */
	kNERtcErrChannelReserveMoreThanTwoUser = 600,	
	//livestream task
	/**
	 * @if English
	 * Invalid permission that is replaced by following operations.
	 * @endif
	 * @if Chinese
	 * task请求无效，被后续操作覆盖
	 * @endif
	 */
    kNERtcErrLsTaskRequestInvalid = 1301,	        
	/**
	 * @if English
	 * Parameter format error.
	 * @endif
	 * @if Chinese
	 * task参数格式错误
	 * @endif
	 */
    kNERtcErrLsTaskIsInvaild = 1400,	            
	/**
	 * @if English
	 * Exited the channel.
	 * @endif
	 * @if Chinese
	 * 房间已经退出
	 * @endif
	 */
    kNERtcErrLsTaskRoomExited = 1401,	            
	/**
	 * @if English
	 * Streaming tasks are over the limit.
	 * @endif
	 * @if Chinese
	 * 推流任务超出上限
	 * @endif
	 */
    kNERtcErrLsTaskNumLimit = 1402,	                
	/**
	 * @if English
	 * Duplicates ID of streaming tasks.
	 * @endif
	 * @if Chinese
	 * 推流ID重复
	 * @endif
	 */
    kNERtcErrLsTaskDuplicateId = 1403,	            
	/**
	 * @if English
	 * No ID task or no channels.
	 * @endif
	 * @if Chinese
	 * taskId任务不存在，或房间不存在
	 * @endif
	 */
    kNERtcErrLsTaskNotFound = 1404,	                
	/**
	 * @if English
	 * Permission failures.
	 * @endif
	 * @if Chinese
	 * 请求失败
	 * @endif
	 */
    kNERtcErrLsTaskRequestErr = 1417,	            
	/**
	 * @if English
	 * Internal errors in the server.
	 * @endif
	 * @if Chinese
	 * 服务器内部错误
	 * @endif
	 */
    kNERtcErrLsTaskInternalServerErr = 1500,	    
	/**
	 * @if English
	 * Layout parameter errors.
	 * @endif
	 * @if Chinese
	 * 布局参数错误
	 * @endif
	 */
    kNERtcErrLsTaskInvalidLayout = 1501,	        
	/**
	 * @if English
	 * Image errors of users.
	 * @endif
	 * @if Chinese
	 * 用户图片错误
	 * @endif
	 */
    kNERtcErrLsTaskUserPicErr = 1512,	            
	//Other errors.
	/**
	 * @if English
	 * Fails to initiate a channel.
	 * @endif
	 * @if Chinese
	 * 通道发起失败
	 * @endif
	 */
	kNERtcErrChannelStartFail = 11000,				
	/**
	 * @if English
	 * Disconnects the channel.
	 * @endif
	 * @if Chinese
	 * 断开连接
	 * @endif
	 */
	kNERtcErrChannelDisconnected = 11001,			
	/**
	 * @if English
	 * The local SDK version is too low to achieve compatibility.
	 * @endif
	 * @if Chinese
	 * 本人SDK版本太低不兼容
	 * @endif
	 */
	kNERtcErrVersionSelfLow = 11002,				
	/**
	 * @if English
	 * The remote SDK version is too low to achieve compatibility.
	 * @endif
	 * @if Chinese
	 * 对方SDK版本太低不兼容
	 * @endif
	 */
	kNERtcErrVersionRemoteLow = 11003,				
	/**
	 * @if English
	 * The channel is disabled.
	 * @endif
	 * @if Chinese
	 * 通道被关闭
	 * @endif
	 */
	kNERtcErrChannelClosed = 11004,					
	/**
	 * @if English
	 * The ID is removed from the channel.
	 * @endif
	 * @if Chinese
	 * 账号被踢
	 * @endif
	 */
	kNERtcErrChannelKicked = 11005,					
	/**
	 * @if English
	 * Data error.
	 * @endif
	 * @if Chinese
	 * 数据错误
	 * @endif
	 */
	kNERtcErrDataError = 11400,						
	/**
	 * @if English
	 * Invalid operation.
	 * @endif
	 * @if Chinese
	 * 无效的操作
	 * @endif
	 */
	kNERtcErrInvalid = 11403,						
	// Server connection error.
	/**
	 * @if English
	 * Request timeouts.
	 * @endif
	 * @if Chinese
	 * 请求超时
	 * @endif
	 */
	kNERtcErrChannelJoinTimeOut = 20101,			
	/**
	 * @if English
	 * Meeting mode error.
	 * @endif
	 * @if Chinese
	 * 会议模式错误
	 * @endif
	 */
	kNERtcErrChannelJoinMeetingModeError = 20102,	
	/**
	 * @if English
	 * rtmp users join the channel that applies the non-rtmp protocol.
	 * @endif
	 * @if Chinese
	 * rtmp用户加入非rtmp房间
	 * @endif
	 */
	kNERtcErrChannelJoinRtmpModeError = 20103,		
	/**
	 * @if English
	 * Users capacity is exceeded in the room that applies to the rtmp protocol.
	 * @endif
	 * @if Chinese
	 * 超过房间最多rtmp人数限制
	 * @endif
	 */
	kNERtcErrChannelJoinRtmpNodesError = 20104,		
	/**
	 * @if English
	 * The role of host is specified.
	 * @endif
	 * @if Chinese
	 * 已经存在一个主播
	 * @endif
	 */
	kNERtcErrChannelJoinRtmpHostError = 20105,		
	/**
	 * @if English
	 * Relayed live streaming is required where the host does not create the room.
	 * @endif
	 * @if Chinese
	 * 需要旁路直播, 但房间创建者非主播
	 * @endif
	 */
	kNERtcErrChannelJoinRtmpCreateError = 20106,	
	/**
	 * @if English
	 * Errors occur when the host customized the channel layout.
	 * @endif
	 * @if Chinese
	 * 主播自定义布局错误
	 * @endif
	 */
	kNERtcErrChannelJoinLayoutError = 20208,		
	/**
	 * @if English
	 * Error parameters.
	 * @endif
	 * @if Chinese
	 * 错误参数
	 * @endif
	 */
	kNERtcErrChannelJoinInvalidParam = 20400,		
	/**
	 * @if English
	 * Password encryption error.
	 * @endif
	 * @if Chinese
	 * 密码加密错误
	 * @endif
	 */
	kNERtcErrChannelJoinDesKey = 20401,				
	/**
	 * @if English
	 * Error request.
	 * @endif
	 * @if Chinese
	 * 错误请求
	 * @endif
	 */
	kNERtcErrChannelJoinInvalidRequst = 20417,		
	/**
	 * @if English
	 * Internal errors in the server.
	 * @endif
	 * @if Chinese
	 * 服务器内部错误
	 * @endif
	 */
	kNERtcErrChannelServerUnknown = 20500,			
	//Engine error code
	/**
	 * @if English
	 * Common errors.
	 * @endif
	 * @if Chinese
	 * 通用错误
	 * @endif
	 */
	kNERtcErrFatal = 30001,                         
	/**
	 * @if English
	 * Out of memory.
	 * @endif
	 * @if Chinese
	 * 内存耗尽
	 * @endif
	 */
	kNERtcErrOutOfMemory = 30002,                   
	/**
	 * @if English
	 * Invalid parameters.
	 * @endif
	 * @if Chinese
	 * 错误的参数
	 * @endif
	 */
	kNERtcErrInvalidParam = 30003,                  
	/**
	 * @if English
	 * Unsupported operation.
	 * @endif
	 * @if Chinese
	 * 不支持的操作
	 * @endif
	 */
	kNERtcErrNotSupported = 30004,                  
	/**
	 * @if English
	 * Unsupported operations in the current state.
	 * @endif
	 * @if Chinese
	 * 当前状态不支持的操作
	 * @endif
	 */
	kNERtcErrInvalidState = 30005,                  
	/**
	 * @if English
	 * Depleted resources.
	 * @endif
	 * @if Chinese
	 * 资源耗尽
	 * @endif
	 */
	kNERtcErrLackOfResource = 30006,                
	/**
	 * @if English
	 * Invalid index.
	 * @endif
	 * @if Chinese
	 * 非法 index
	 * @endif
	 */
	kNERtcErrInvalidIndex = 30007,                  
	/**
	 * @if English
	 * Device is not found.
	 * @endif
	 * @if Chinese
	 * 设备未找到
	 * @endif
	 */
	kNERtcErrDeviceNotFound = 30008,                
	/**
	 * @if English
	 * Invalid device ID.
	 * @endif
	 * @if Chinese
	 * 非法设备 ID 
	 * @endif
	 */
	kNERtcErrInvalidDeviceSourceID = 30009,         
	/**
	 * @if English
	 * Invalid profile type of video.
	 * @endif
	 * @if Chinese
	 * 非法的视频 profile type
	 * @endif
	 */
	kNERtcErrInvalidVideoProfile = 30010,           
	/**
	 * @if English
	 * Device creation errors.
	 * @endif
	 * @if Chinese
	 * 设备创建错误
	 * @endif
	 */
	kNERtcErrCreateDeviceSourceFail = 30011,        
	/**
	 * @if English
	 * Invalid rendering device.
	 * @endif
	 * @if Chinese
	 * 非法的渲染容器
	 * @endif
	 */
	kNERtcErrInvalidRender = 30012,                 
	/**
	 * @if English
	 * Device is already enabled.
	 * @endif
	 * @if Chinese
	 * 设备已经打开
	 * @endif
	 */
	kNERtcErrDevicePreviewAlreadyStarted = 30013,   
	/**
	 * @if English
	 * Transmission error.
	 * @endif
	 * @if Chinese
	 * 传输错误
	 * @endif
	 */
	kNERtcErrTransmitPendding = 30014,              
	/**
	 * @if English
	 * Server connection error.
	 * @endif
	 * @if Chinese
	 * 连接服务器错误
	 * @endif
	 */
	kNERtcErrConnectFail = 30015,                   
	/**
	 * @if English
	 * Fails to create Audio dump file.
	 * @endif
	 * @if Chinese
	 * 创建Audio dump文件失败
	 * @endif
	 */
    kNERtcErrCreateDumpFileFail = 30016,            
	/**
	 * @if English
	 * Fails to enable Audio dump file.
	 * @endif
	 * @if Chinese
	 * 开启Audio dump失败
	 * @endif
	 */
    kNERtcErrStartDumpFail = 30017,                 
	/**
	 * @if English
	 * Fails to enable desktop screen recording if camera is started at the same time.
	 * @endif
	 * @if Chinese
	 * 启动桌面录屏失败，不能与camera同时启动
	 * @endif
	 */
    kNERtcErrDesktopCaptureInvalidState = 30020,    
	/**
	 * @if English
	 * Parameters are invalid when the desktop screen recording is implemented.
	 * @endif
	 * @if Chinese
	 * 桌面录屏传入参数无效
	 * @endif
	 */
    kNERtcErrDesktopCaptureInvalidParam = 30021,    
	/**
	 * @if English
	 * Desktop screen recording is not ready.
	 * @endif
	 * @if Chinese
	 * 桌面录屏未就绪
	 * @endif
	 */
    kNERtcErrDesktopCaptureNotReady     = 30022,  
  /**
  * @if English
  * Selected device is occupied.
  * @endif
  * @if Chinese
  * 所选设备已被占用
  * @endif
  */
    kNERtcErrDeviceOccupied             = 30027,
	/**
	 * @if English
	 * Repeatedly joins the channel.
	 * @endif
	 * @if Chinese
	 * 重复加入房间
	 * @endif
	 */
	kNERtcErrChannelAlreadyJoined = 30100,    
	/**
	 * @if English
	 * Does not join the channel.
	 * @endif
	 * @if Chinese
	 * 尚未加入房间
	 * @endif
	 */
	kNERtcErrChannelNotJoined = 30101,        
	/**
	 * @if English
	 * Repeatedly leaves the channel.
	 * @endif
	 * @if Chinese
	 * 重复离开房间
	 * @endif
	 */
	kNERtcErrChannelRepleatedlyLeave = 30102, 
	/**
	 * @if English
	 * Fails to join the channel.
	 * @endif
	 * @if Chinese
	 * 加入房间操作失败
	 * @endif
	 */
	kNERtcErrRequestJoinChannelFail = 30103,  
	/**
	 * @if English
	 * Session is not found.
	 * @endif
	 * @if Chinese
	 * 会话未找到
	 * @endif
	 */
	kNERtcErrSessionNotFound = 30104,         
	/**
	 * @if English
	 * The user is not found.
	 * @endif
	 * @if Chinese
	 * 用户未找到
	 * @endif
	 */
	kNERtcErrUserNotFound = 30105,            
	/**
	 * @if English
	 * Invalid user ID.
	 * @endif
	 * @if Chinese
	 * 非法的用户 ID 
	 * @endif
	 */
	kNERtcErrInvalidUserID = 30106,           
	/**
	 * @if English
	 * Users do not connect the multi-media data.
	 * @endif
	 * @if Chinese
	 * 用户多媒体数据未连接
	 * @endif
	 */
	kNERtcErrMediaNotStarted = 30107,         
	/**
	 * @if English
	 * Source is not found.
	 * @endif
	 * @if Chinese
	 * source 未找到
	 * @endif
	 */
	kNERtcErrSourceNotFound = 30108,          
	/**
	 * @if English
	 * Invalid state of switching channels.
	 * @endif
	 * @if Chinese
	 * 切换房间状态无效
	 * @endif
	 */
    kNERtcErrSwitchChannelInvalidState = 30109,        
	/**
	 * @if English
	 * Invalid state of relaying media streams.
	 * @endif
	 * @if Chinese
	 * 重复调用 startChannelMediaRelay。
	 * @endif
	 */
    kNERtcErrChannelMediaRelayInvalidState = 30110,    
	/**
	 * @if English
	 * Invalid permissions of relaying streams. Check whether the mode is set as audience mode or 1v1 mode.
	 * @endif
	 * @if Chinese
	 * 媒体流转发权限不足。例如调用 startChannelMediaRelay 的房间成员为主播角色、或房间为双人通话房间，不支持转发媒体流。
	 * @endif
	 */
    kNERtcErrChannelMediaRelayPermissionDenied = 30111,
	/**
	 * @if English
	 * If you fail to stop relaying media streams, check whether the media stream forwarding is enabled.
	 * @endif
	 * @if Chinese
	 * 调用 stopChannelMediaRelay 前，未调用 startChannelMediaRelay。
	 * @endif
	 */
    kNERtcErrChannelMediaRelayStopFailed = 30112,      
	/**
	 * @if English
	 * If you set the different encryption password of media streams from other members in the room, you fail to join the room.  Sets new encryption password thorough enableEncryption.
	 * @endif
	 * @if Chinese
	 * 设置的媒体流加密密钥与房间中其他成员不一致，加入房间失败。请通过 enableEncryption 重新设置加密密钥。
	 * @endif
	 */
    kNERtcErrEncryptNotSuitable = 30113,               
	/**
	 * @if English
	 * Connection is not found.
	 * @endif
	 * @if Chinese
	 * 连接未找到
	 * @endif
	 */
    kNERtcErrConnectionNotFound = 30200,          
	/**
	 * @if English
	 * Media streams are not found.
	 * @endif
	 * @if Chinese
	 * 媒体流未找到
	 * @endif
	 */
	kNERtcErrStreamNotFound = 30201,              
	/**
	 * @if English
	 * Fails to join the track.
	 * @endif
	 * @if Chinese
	 * 加入 track 失败
	 * @endif
	 */
	kNERtcErrAddTrackFail = 30202,                
	/**
	 * @if English
	 * Track is not found.
	 * @endif
	 * @if Chinese
	 * track 未找到
	 * @endif
	 */
	kNERtcErrTrackNotFound = 30203,               
	/**
	 * @if English
	 * Media disconnection.
	 * @endif
	 * @if Chinese
	 * 媒体连接断开
	 * @endif
	 */
	kNERtcErrMediaConnectionDisconnected = 30204, 
	/**
	 * @if English
	 * Signalling disconnection.
	 * @endif
	 * @if Chinese
	 * 信令连接断开
	 * @endif
	 */
	kNERtcErrSignalDisconnected = 30205,          
	/**
	 * @if English
	 * The user is removed from the room.
	 * @endif
	 * @if Chinese
	 * 被踢出房间
	 * @endif
	 */
	kNERtcErrServerKicked = 30206,                
	/**
	 * @if English
	 * Removed for the channel is already disabled.
	 * @endif
	 * @if Chinese
	 * 因房间已关闭而被踢出
	 * @endif
	 */
    kNERtcErrKickedForRoomClosed = 30207,         
	/**
	 * @if English
	 * A room is closed when a user switches to another room.
	 * @endif
	 * @if Chinese
	 * 因为切换房间的操作房间被关闭
	 * @endif
	 */
    kNERtcErrChannelLeaveBySwitchAction = 30208,  
        
    /**
	 * @if English
     * A room is closed due to duplicates user IDs
	 * @endif
	 * @if Chinese
     * 因为有重复 uid 登录导致房间被关闭
	 * @endif
     */
    kNERtcErrChannelLeaveByDuplicateUidLogin = 30209,

    /**
	 * @if English
	 * Media is banned by the server.
	 * @endif
	 * @if Chinese
	 * 被服务器禁言
	 * @endif
     */
    kNERtcErrMediaOpenBannedByServer = 30403,

	/**
	 * @if English
	 * No permission of audio devices.
	 * @endif
	 * @if Chinese
	 * 没有音频设备权限
	 * @endif
	 */
    kNERtcRuntimeErrADMNoAuthorize = 40000,              
	/**
	 * @if English
	 * No permission of video devices.
	 * @endif
	 * @if Chinese
	 * 没有视频设备权限
	 * @endif
	 */
    kNERtcRuntimeErrVDMNoAuthorize = 50000,              
	/**
	 * @if English
	 * No permission of video recording.
	 * @endif
	 * @if Chinese
	 * 没有录制视频权限
	 * @endif
	 */
    kNERtcRuntimeErrScreenCaptureNoAuthorize = 60000,    
} NERtcErrorCode;

/** 
 * @if English
 * @enum NERtcRoomServerErrorCode The related error codes of room server. TODO:NERtcErrorCode.
 * 
 * @endif
 * @if Chinese
 * @enum NERtcRoomServerErrorCode room server相关错误码。TODO：NERtcErrorCode
 * @endif
 */
typedef enum
{
	/**
	 * @if English
	 * Successful operation.
	 * @endif
	 * @if Chinese
	 * 操作成功
	 * @endif
	 */
	kNERtcRoomServerErrOK               = 200,				
	/**
	 * @if English
	 * Authentication error.
	 * @endif
	 * @if Chinese
	 * 认证错误
	 * @endif
	 */
	kNERtcRoomServerErrAuthError        = 401,			    
	/**
	 * @if English
	 * Channel is not found.
	 * @endif
	 * @if Chinese
	 * 房间不存在
	 * @endif
	 */
	kNERtcRoomServerErrChannelNotExist  = 404,	            
	/**
	 * @if English
	 * The uid of the channel is not found.
	 * @endif
	 * @if Chinese
	 * 房间下的uid不存在
	 * @endif
	 */
	kNERtcRoomServerErrUidNotExist      = 405,		        
	/**
	 * @if English
	 * Request data error.
	 * @endif
	 * @if Chinese
	 * 请求数据不对
	 * @endif
	 */
	kNERtcRoomServerErrDataError        = 417,			    
	/**
	 * @if English
	 * Internal error that request error occurs in the TurnServer.
	 * @endif
	 * @if Chinese
	 * 内部错误（TurnServer请求异常）
	 * @endif
	 */
	kNERtcRoomServerErrUnknown          = 500,			    
	/**
	 * @if English
	 * Internal errors in the server.
	 * @endif
	 * @if Chinese
	 * 服务器内部错误
	 * @endif
	 */
	kNERtcRoomServerErrServerError      = 600,		        
	/**
	 * @if English
	 * Invalid operation.
	 * @endif
	 * @if Chinese
	 * 无效的操作
	 * @endif
	 */
	kNERtcRoomServerErrInvilid          = 11403,			
} NERtcRoomServerErrorCode;

/** 
 * @if English
 * @enum NERtcAudioMixingErrorCode indicates error codes of audio mixing music files.
 * @endif
 * @if Chinese
 * @enum NERtcAudioMixingErrorCode 混音音乐文件错误码。
* @endif
*/
typedef enum 
{
	/**
	 * @if English
	 * No error.
	 * @endif
	 * @if Chinese
	 * 没有错误。
	 * @endif
	 */
    kNERtcAudioMixingErrorOK            = 0,      			
	/**
	 * @if English
	 * Common error.
	 * @endif
	 * @if Chinese
	 * 通用错误。
	 * @endif
	 */
    kNERtcAudioMixingErrorFatal         = 1,      			
	/**
	 * @if English
	 * Audio mixing is not enabled normally. 
	 * @endif
	 * @if Chinese
	 * 伴音不能正常打开
	 * @endif
	 */
	kNERtcAudioMixingErrorCanNotOpen,						
	/**
	 * @if English
	 * Audio decoding error.
	 * @endif
	 * @if Chinese
	 * 音频解码错误
	 * @endif
	 */
	kNERtcAudioMixingErrorDecode,							
	/**
	 * @if English
	 * Interruption codes in the operation.
	 * @endif
	 * @if Chinese
	 * 操作中断码
	 * @endif
	 */
	kNERtcAudioMixingErrorInterrupt,						
	/**
	 * @if English
	 * 404 file not found，only for http / https.
	 * @endif
	 * @if Chinese
	 * 404 file not found，only for http /
	 * @endif
	 */
	kNERtcAudioMixingErrorHttpNotFound,						
	/**
	 * @if English
	 * Fails to enable streams/files.
	 * @endif
	 * @if Chinese
	 * 打开流 / 文件失败
	 * @endif
	 */
	kNERtcAudioMixingErrorOpen,								
	/**
	 * @if English
	 * Decoding information failures or timeouts.
	 * @endif
	 * @if Chinese
	 * 获取解码信息失败 / 超时
	 * @endif
	 */
	kNERtcAudioMixingErrorNInfo,							
	/**
	 * @if English
	 * No audio streams.
	 * @endif
	 * @if Chinese
	 * 无音频流
	 * @endif
	 */
	kNERtcAudioMixingErrorNStream,							
	/**
	 * @if English
	 * No decoder.
	 * @endif
	 * @if Chinese
	 * 无解码器
	 * @endif
	 */
	kNERtcAudioMixingErrorNCodec,							
	/**
	 * @if English
	 * No memory.
	 * @endif
	 * @if Chinese
	 * 无内存
	 * @endif
	 */
	kNERtcAudioMixingErrorNMem,								
	/**
	 * @if English
	 * Failures or timeouts of enabling decoders.
	 * @endif
	 * @if Chinese
	 * 解码器打开失败 / 超时
	 * @endif
	 */
	kNERtcAudioMixingErrorCodecOpen,						
	/**
	 * @if English
	 * Invalid audio parameters such as channels and sample rate.
	 * @endif
	 * @if Chinese
	 * 无效音频参数（声道、采样率）
	 * @endif
	 */
	kNERtcAudioMixingErrorInvalidInfo,						
	/**
	 * @if English
	 * Streams/files enabling timeouts.
	 * @endif
	 * @if Chinese
	 * 打开流 / 文件超时
	 * @endif
	 */
	kNERtcAudioMixingErrorOpenTimeout,						
	/**
	 * @if English
	 * Network io timeouts.
	 * @endif
	 * @if Chinese
	 * 网络io超时
	 * @endif
	 */
	kNERtcAudioMixingErrorIoTimeout,						
	/**
	 * @if English
	 * Network io errors.
	 * @endif
	 * @if Chinese
	 * 网络io错误
	 * @endif
	 */
	kNERtcAudioMixingErrorIo,								
	/**
	 * @if English
	 * Music files frequently enabled. 
	 * @endif
	 * @if Chinese
	 * 音乐文件打开太频繁。
	 * @endif
	 */
    //kNERtcAudioMixingErrorTooFrequentCall = 101,      	
	/**
	 * @if English
	 * Music files playbacks interrupted.
	 * @endif
	 * @if Chinese
	 * 音乐文件播放中断。
	 * @endif
	 */
    //kNERtcAudioMixingErrorInterruptedEOF= 102,      		
} NERtcAudioMixingErrorCode;

/** 
 * @if English
 * Error codes.
 * Error codes are returned when a problem that cannot be recovered without app intervention has occurred.
 * @endif
 * @if Chinese
 * 错误代码。
 * 错误代码意味着 SDK 遇到不可恢复的错误，需要应用程序干预。
* @endif
*/
typedef enum
{
    //ADM
	/**
	 * @if English
	 * Audio device module: Errors occur when initializing recording devices. Please check whether the recording device can work properly or have limited permissions, or try reconnecting to rejoin the room.
	 * @endif
	 * @if Chinese
	 * 音频设备模块：初始化录音设备时出现错误。请检查录音设备是否正常或者权限限制，或者尝试重新进入房间。
	 * @endif
	 */
    kNERtcRuntimeErrADMInitRecording        = 40001,     
	/**
	 * @if English
	 * Audio device module: Errors occur when enabling recording devices. Please check whether the recording device can work properly, or try reconnecting to rejoin the room.
	 * @endif
	 * @if Chinese
	 * 音频设备模块：启动录音设备出现错误。请检查录音设备是否正常，或者尝试重新进入房间。
	 * @endif
	 */
    kNERtcRuntimeErrADMStartRecording       = 40002,     
	/**
	 * @if English
	 * Audio device module: Errors occur when running recording devices. Please check whether the recording device can work properly, or try reconnecting to rejoin the room.
	 * @endif
	 * @if Chinese
	 * 音频设备模块：运行时录音错误。请检查录音设备是否正常，或者尝试重新进入房间。
	 * @endif
	 */
    kNERtcRuntimeErrADMStopRecording        = 40003,     
	/**
	 * @if English
	 * Audio device module: Errors occur when initializing playback devices. Please check whether the playback device can work properly or have limited permissions, or try reconnecting to rejoin the room.
	 * @endif
	 * @if Chinese
	 * 音频设备模块：初始化播放设备出现错误。请检查播放设备是否异常或者权限限制，或者尝试重新进入房间。
	 * @endif
	 */
    kNERtcRuntimeErrADMInitPlayout          = 40004,     
	/**
	 * @if English
	 * Audio device module: Errors occur when enabling playback devices. Please check whether the playback device can work properly, or try reconnecting to rejoin the room.
	 * @endif
	 * @if Chinese
	 * 音频设备模块：启动播放设备出现错误。请检查播放设备是否正常，或者尝试重新进入房间。
	 * @endif
	 */
    kNERtcRuntimeErrADMStartPlayout         = 40005,     
	/**
	 * @if English
	 * Audio device module: Errors occur when running playback devices. Please check whether the playback device can work properly, or try reconnecting to rejoin the room.
	 * @endif
	 * @if Chinese
	 * 音频设备模块：运行时播放出现错误。请检查播放设备是否正常，或者尝试重新进入房间。
	 * @endif
	 */
    kNERtcRuntimeErrADMStopPlayout          = 40006,     
	//VDM
	/**
	 * @if English
	 * Video device module: The Camera has no data frame. Please check the camera or switch the camera.
	 * @endif
	 * @if Chinese
	 * 视频设备模块：摄像头无数据帧。请检查摄像头或者切换摄像头。
	 * @endif
	 */
    kNERtcErrVDMCameraNoFrame               = 1502,    
	/**
	 * @if English
	 * Video device module:Fails to enable camera. Please check whether the camera has exited or occupied.
	 * @endif
	 * @if Chinese
	 * 视频设备模块：摄像头启动失败。请检查摄像头是否存在或被占用
	 * @endif
	 */
    kNERtcErrVDMCameraCreateFail            = 1503,     

} NERtcDMErrorCode;

} // namespace nertc

#endif
