#ifndef LKLOG_TOOLS_H
#define LKLOG_TOOLS_H

#if defined(_WIN32) || defined(_WIN64)  // Windows ??
#ifdef EXPORTING_DLL
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else  // ?? Windows ?? (Linux, macOS ??)
#ifdef EXPORTING_DLL
#define DLL_API __attribute__ ((visibility ("default")))
#else
#define DLL_API
#endif
#endif

#endif // LKLOG_TOOLS_H
