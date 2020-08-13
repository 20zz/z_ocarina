/*
 * $Id: THA_GA.h,v 1.1.1.1 2003/01/17 21:07:13 tong Exp $
 *
 * ディスプレイリスト用 THA
 *
 * $Log: THA_GA.h,v $
 * Revision 1.1.1.1  2003/01/17 21:07:13  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * ＲＯＭ出しバージョン(NTSC)
 *
 * Revision 1.5  1998/07/17 12:23:00  hayakawa
 * ゼルダ高速化残念措置
 * NEXT_DISP
 * NOW_DISP
 * SET_NOW_DISP
 * その他いろいろ
 *
 * Revision 1.4  1998-04-02 18:04:42+09  hayakawa
 * Ｃ＋＋のときにインライン関数バージョンになるようにした
 * Ｃのときも OPTIMIZE_NEXT_DISP が設定されているときは速くなるようにした
 *
 * Revision 1.3  1998/04/01  02:47:30  hayakawa
 * 汎用性を考え __cplusplus を _LANGUAGE_C_PLUS_PLUS に変更
 *
 * Revision 1.2  1996/10/09  05:29:38  hayakawa
 * 先頭ポインタの設定ができるように THA_GA_setHeadPtr 関数を追加した
 *
 */

#ifndef __THA_GA_H_
#define __THA_GA_H_

#include "TwoHeadArena.h"	/* 基底クラスTHAのヘッダ */
#include "u64types.h"		/* size_t */

typedef struct TwoHeadArenaGfx_s {
    size_t size;		/* バッファサイズ */
    Gfx  *buf_p;		/* バッファ先頭ポインタ */
    Gfx  *head_p;		/* 順アロケーションポインタ */
    Gfx  *tail_p;		/* 逆アロケーションポインタ */
} TwoHeadArenaGfx_t;
typedef TwoHeadArenaGfx_t TwoHeadArenaGfx;
typedef union THA_GA_s {
    TwoHeadArena tha;
    TwoHeadArenaGfx thaGfx;
} THA_GA_t;
typedef THA_GA_t THA_GA;

#if defined(_LANGUAGE_C_PLUS_PLUS) && !defined(__THA_GA_C_)

inline void THA_GA_ct(THA_GA *this, Gfx *p, size_t n)
{ THA_ct(&this->tha, (char *)p, n); }
inline void THA_GA_dt(THA_GA *this)
{ THA_dt(&this->tha); }
inline int THA_GA_isCrash(THA_GA *this)
{ return THA_isCrash(&this->tha); }
inline void THA_GA_init(THA_GA *this)
{ THA_init(&this->tha); }
inline int THA_GA_getFreeBytes(THA_GA *this)
{ return THA_getFreeBytes(&this->tha); }
inline void *THA_GA_getHeadPtr(THA_GA *this)
{ return THA_getHeadPtr(&this->tha); }
inline void THA_GA_setHeadPtr(THA_GA *this, void *p)
{ THA_setHeadPtr(&this->tha, p); }
inline void *THA_GA_getTailPtr(THA_GA *this)
{ return THA_getTailPtr(&this->tha); }
inline void *THA_GA_nextPtrN(THA_GA *this, size_t n)
{ return THA_nextPtrN(&this->tha, (int)sizeof(Gfx) * n); }
inline void *THA_GA_nextPtr1(THA_GA *this)
{ return THA_GA_nextPtrN(this, 1); }
inline Gfx *THA_GA_NEXT_DISP(THA_GA *this)
{ return (Gfx *)THA_GA_nextPtr1(this); }
inline Mtx *THA_GA_alloc(THA_GA *this, size_t n)
{ return (Mtx *)THA_alloc(&this->tha, n); }
inline Mtx *THA_GA_allocMtxN(THA_GA *this, size_t n)
{ return THA_GA_alloc(this, sizeof(Mtx) * n); }
inline Mtx *THA_GA_allocMtx1(THA_GA *this)
{ return THA_GA_alloc(this, sizeof(Mtx)); }
inline Vtx *THA_GA_allocVtxN(THA_GA *this, size_t n)
{ return (Vtx *)THA_GA_alloc(this, sizeof(Vtx) * n); }
inline Vtx *THA_GA_allocVtx1(THA_GA *this)
{ return (Vtx *)THA_GA_alloc(this, sizeof(Vtx)); }

#else  /* defined(_LANGUAGE_C_PLUS_PLUS) && !defined(__THA_GA_C_)*/
    
#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

extern void THA_GA_ct(THA_GA *this, Gfx *p, size_t n);
extern void THA_GA_dt(THA_GA *this);
extern int THA_GA_isCrash(THA_GA *this);
extern void THA_GA_init(THA_GA *this);
extern int THA_GA_getFreeBytes(THA_GA *this);
extern void *THA_GA_getTailPtr(THA_GA *this);
extern void *THA_GA_nextPtrN(THA_GA *this, size_t n);
extern void *THA_GA_nextPtr1(THA_GA *this);
#if defined(OPTIMIZE_NEXT_DISP) && !defined(__THA_GA_C_)
#define THA_GA_NEXT_DISP(thaga) ((thaga)->thaGfx.head_p++)
#define THA_GA_getHeadPtr(thaga) ((thaga)->tha.head_p)
#define THA_GA_setHeadPtr(thaga, ptr) (void)((thaga)->tha.head_p = (char *)(ptr))
#else
extern Gfx *THA_GA_NEXT_DISP(THA_GA *this);
extern void *THA_GA_getHeadPtr(THA_GA *this);
extern void THA_GA_setHeadPtr(THA_GA *this, void *p);
#endif
extern Mtx *THA_GA_alloc(THA_GA *this, size_t n);
extern Mtx *THA_GA_allocMtxN(THA_GA *this, size_t n);
extern Mtx *THA_GA_allocMtx1(THA_GA *this);
extern Vtx *THA_GA_allocVtxN(THA_GA *this, size_t n);
extern Vtx *THA_GA_allocVtx1(THA_GA *this);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* defined(_LANGUAGE_C_PLUS_PLUS) && !defined(__THA_GA_C_)*/

#endif /* __THA_GA_H_ */
