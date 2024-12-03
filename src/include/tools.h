#ifndef LKLOG_TOOLS_H
#define LKLOG_TOOLS_H

#if defined(_WIN32) || defined(_WIN64)  // Windows 平台
#ifdef EXPORTING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else  // 非 Windows 平台 (Linux, macOS 等)
#ifdef EXPORTING_DLL
#define DLL_API __attribute__ ((visibility ("default")))
#else
#define DLL_API
#endif
#endif

#endif // LKLOG_TOOLS_H
