# NetEase IM CrossPlatform(PC) C SDK 9.5.2 封装层接入指引

## 网易云信服务概要

云信以提供客户端 SDK（覆盖 Android、iOS、Web、PC）和服务端 OPEN API 的形式提供即时通讯云服务。开发者只需想好 APP 的创意及 UI 展现方案，根据 APP 业务需求选择云信的相应功能接入即可。

> 注：SDK 兼容的系统有 Windows XP（SP2 及以上, IM 版本 < 8.9.0）、Windows 7、Windows 8/8.1、Windows 10、macOS 10.13 or higher，SDK 从 V3.2.5 版本开始全面支持 32 位和 64 位程序接入。

## 运行环境

在 Windows 下 SDK 使用 VS2017 及其工具链（v141_xp、/MD）进行编译，在您的应用部署前需要将 VS2017 运行时库安装到目标系统中或将依赖文件存放到执行程序可以搜索到的路径下。最新的 Visual Studio 2017 运行时库可以从微软官方网站进行下载：[https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0](https://support.microsoft.com/en-us/topic/the-latest-supported-visual-c-downloads-2647da03-1eea-4433-9aff-95f26a218cc0)

在 macOS 下 SDK 使用 Xcode 及其工具链进行编译，无特殊支持要求，最低支持系统到 macOS 10.13。

## 开发准备

### SDK 目录结构及主要文件介绍

在 Windows 系统下，SDK 发布目录为以下格式

```
├─bin ------------------------ Windows SDK 二进制文件如 *.dll 动态库文件，含聊天室
├─include -------------------- Windows SDK C 接口依赖的头文件目录
├─lib ------------------------ Windows SDK C 接口导出的符号链接文件 *.lib
└─wrapper -------------------- Windows SDK 对 C 接口封装的 C++ 接口源代码，使用 CMake 生成
```

在 macOS 系统下，SDK 发布目录为一下格式：

```
├─include -------------------- macOS SDK C 接口依赖的头文件目录
├─lib ------------------------ macOS SDK 本体以及依赖的一些动态库文件 *.dylib，您需要打包到您应用的 bundle 中，含聊天室
└─wrapper -------------------- macOS SDk 对 C 接口封装的 C++ 接口源代码，使用 CMake 生成
```

C 接口 SDK 不提供 Debug 版本的动态链接库供开发者调试，如果遇到问题请联系技术支持或在线客服。

### 对接 C 接口层

**Windows 环境** 将 `include` 目录添加为头文件搜索路径、将 `lib` 目录添加为库文件搜索路径，并根据需要链接 `lib` 下的指定符号链接文件即可。生成的二进制文件需要与 `bin` 目录下的动态库在同一个文件夹。

**macOS 环境** 将 `include` 目录添加为头文件搜索路径、将 `lib` 目录添加为库文件搜索路径，并根据需要链接 `lib` 下的指定符号链接文件即可。

### 对接 C++ 接口层

为了方便桌面应用开发者更快速的接入云信 SDK，我们还提供了官方的 C++ 封装层代码（SDK wrapper 目录），接入和使用方法请参考 [SDK C++ 封装层接入指引](https://doc.yunxin.163.com/docs/interface/%E5%8D%B3%E6%97%B6%E9%80%9A%E8%AE%AFWindows%E7%AB%AF/NIMSDKAPI_CPP/html/index.html)。另外基于 C++ SDK 我们提供了丰富的 [VC++ Demo 演示程序代码](https://github.com/netease-im/NIM_PC_Demo)，您可以通过 Demo 演示程序代码参考如何调用 SDK 相关能力。

### 对接 C# 接口层

云信 SDK 还提供了 C# 程序集，方便 .Net 开发人员接入，PC SDK 下载包中包括官方的 [C# 封装层 项目文件及源码](https://github.com/netease-im/NIM_PC_SDK-CSharp "target=_blank")，接入和使用方法请看 [Windows(PC) SDK 开发手册(C# 封装层)](http://dev.netease.im/docs/product/%E9%80%9A%E7%94%A8/Demo%E6%BA%90%E7%A0%81%E5%AF%BC%E8%AF%BB/PC%E9%80%9A%E7%94%A8/CSharp%E5%B0%81%E8%A3%85%E5%B1%82 "target=_blank")，目前 IM Demo(C#) 源码就是通过接入和调用该 SDK 完成 IM 功能的。

**如果开发者在调用 C 接口过程中或者解析接口返回结果过程中出现疑问，可以参考和借鉴 C++ 封装层代码。**
