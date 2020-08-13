/*
 * $Id: system.h,v 1.1.1.1 2003/01/17 21:07:17 tong Exp $
 *
 * �Σ��������ƥ����
 *
 * $Log: system.h,v $
 * Revision 1.1.1.1  2003/01/17 21:07:17  tong
 * ZELDA-OCARINA OF TIME (20L) build from Nintendo
 *
 * Revision 2.1  1998/10/22  11:41:56  zelda
 * �ңϣͽФ��С������(NTSC)
 *
 * Revision 1.1  1998/03/23 10:30:40  hayakawa
 * Initial revision
 *
 *
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include "os.h"			/* OSPiHandle */

#define SetupDmaIOMsgBuf(mb, priority, dAddr, vAddr, nbytes, mq) do {\
		(mb)->hdr.pri = priority;\
		(mb)->hdr.retQueue = mq;\
		(mb)->devAddr = dAddr;\
		(mb)->dramAddr = vAddr;\
		(mb)->size = nbytes;\
	} while (0)

extern OSPiHandle *carthandle;

#endif /* __SYSTEM_H_ */
