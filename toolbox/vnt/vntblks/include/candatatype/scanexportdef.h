/**
 * @file:       scanexportdef.h
 * Purpose:     Define the import/export macros properly.
 * $Copyright: 2012-2021 The MathWorks, Inc.$
 *              
 */

// Always start over.
#undef SCAN_EXPORT_FCN

#ifdef _MSC_VER
  #define DLL_EXPORT_SYM __declspec(dllexport)
  #define DLL_IMPORT_SYM __declspec(dllimport)
#elif __GNUC__ >= 4
  #define DLL_EXPORT_SYM __attribute__ ((visibility("default")))
  #define DLL_IMPORT_SYM __attribute__ ((visibility("default")))
#else
  #define DLL_EXPORT_SYM
  #define DLL_IMPORT_SYM
#endif

// IMPORT_SCANUTIL is defined if used from an S-Function. 
#if defined(IMPORT_SCANUTIL)
#define SCAN_EXPORT_FCN   DLL_IMPORT_SYM
#else
#define SCAN_EXPORT_FCN   DLL_EXPORT_SYM
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif
#endif
