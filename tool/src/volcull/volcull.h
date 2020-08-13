/*
 * $Id: volcull.h,v 1.1.1.1 2003/01/17 21:11:05 tong Exp $
 *
 * 自動ボリュームカリング
 *
 * gSPDisplayList の先のディスプレイリストに含まれる頂点から、
 * カリング用の頂点を抽出し、カリングディスプレイリストを作成、連結する
 *
 *
 * $Log: volcull.h,v $
 * Revision 1.1.1.1  2003/01/17 21:11:05  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 1.1  1996/10/11  02:08:27  hayakawa
 * Initial revision
 *
 *
 */
#ifndef __VOLCULL_H_
#define __VOLCULL_H_

#include "ultra64.h"

#if __cplusplus
extern "C" {
#endif

    Gfx *create_volume_culling(Gfx *gfxp);

#if __cplusplus
}
#endif

#endif /* __VOLCULL_H_ */
