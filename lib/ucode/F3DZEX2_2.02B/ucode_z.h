/*---------------------------------------------------------------------*
	Copyright (C) 1998, Nintendo.
	
	File		ucode_z.h
	Coded    by	Yoshitaka Yasumoto.	Mar 30, 1998.
	
	$Id: ucode_z.h,v 1.1.1.1 2003/01/17 21:07:12 tong Exp $
 *---------------------------------------------------------------------*/
#ifndef _UCODE_Z_H_
#define	_UCODE_Z_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)
/*========== F3DZEX2/L3DZEX2 ==========*/
/* FIFO version */
extern long long int gspF3DZEX2_fifoTextStart[],
                     gspF3DZEX2_fifoTextEnd[];
extern long long int gspF3DZEX2_fifoDataStart[],
                     gspF3DZEX2_fifoDataEnd[];
extern long long int gspF3DZEX2_NoN_fifoTextStart[],
                     gspF3DZEX2_NoN_fifoTextEnd[];
extern long long int gspF3DZEX2_NoN_fifoDataStart[],
                     gspF3DZEX2_NoN_fifoDataEnd[];
extern long long int gspL3DZEX2_fifoTextStart[],
                     gspL3DZEX2_fifoTextEnd[];
extern long long int gspL3DZEX2_fifoDataStart[],
                     gspL3DZEX2_fifoDataEnd[];
/* XBUS version */
extern long long int gspF3DZEX2_xbusTextStart[],
                     gspF3DZEX2_xbusTextEnd[];
extern long long int gspF3DZEX2_xbusDataStart[],
                     gspF3DZEX2_xbusDataEnd[];
extern long long int gspF3DZEX2_NoN_xbusTextStart[],
                     gspF3DZEX2_NoN_xbusTextEnd[];
extern long long int gspF3DZEX2_NoN_xbusDataStart[],
                     gspF3DZEX2_NoN_xbusDataEnd[];
extern long long int gspL3DZEX2_xbusTextStart[],
                     gspL3DZEX2_xbusTextEnd[];
extern long long int gspL3DZEX2_xbusDataStart[],
                     gspL3DZEX2_xbusDataEnd[];
#endif /* _LANGUAGE_C */
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#endif /* !_UCODE_Z_H */

/*======== End of ucode_z.h ========*/
