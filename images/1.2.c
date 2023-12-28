/* =========================
 Basic Types Definition.
 File name: btype.h
========================= */

#ifndef BTYPE_H
#define BTYPE_H 1

/* ====================
   判斷 !BTYPE_H 是為了防止因為重複 #include 造成的 error.
==================== */

#if TURBOC20
#define BYTE char
#define WORD int
#define DWORD long
#endif

#if MSC51
#define BYTE char
#define WORD int
#define DWORD long
#endif

#if WATCOMC95
#define BYTE char
#define WORD short int
#define DWORD int
#endif

#if SYMANTECC70
#define BYTE char
#define WORD short int
#define DWORD int
#endif

#endif
