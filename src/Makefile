#!smake
#
# make clobber �Τ��Ȥ䡢co spec_ovl �Τ��Ȥ˰ʲ��� make ��¹Ԥ��Ƥ�������
# make genfiles
#
# $Id: Makefile,v 1.2 2003/02/25 01:12:39 wheeler Exp $
#
# ����������ѥᥤ���ե�����
#
# �̾� nload�С������Υᥤ����make rom_d
# �ңϣ;Ƥ��С������Υᥤ����make rom_x
# �ǽ��ңϣͥС������Υᥤ����make rom_f
# ���祦�С������Υᥤ����make rom_s
# 
#
# make "VMAKEOPT=" ; ����ѥ���/makerom���ץ�����ɲ�
# make "VMAKEROMOPT=" ; makerom���ץ�����ɲ�
# make "VMAKEOPTION=" ; make���ץ�����ɲ�
#
#
#
# make -n ; make����ȼ¹Ԥ���륳�ޥ�ɤ�ɽ������
#
#
# RAM8M�С������make "RAM8M="
# malloc�ѥҡ��ץ������ѹ���make "VMAKEOPT=-DSYS_HEAP_SIZE=0x240000"
# fifo�������ѹ���make "VMAKEOPT=-DSYS_FIFO_SIZE=0x2000"
#
# make clean ; rm -rf *.[ou] a.out core lex.yy.[co] y.tab.[cho] _force ar.tmp.*
# make clobber ; �嵭�˲ä��� $(TARGETS) MakeDepend ���ä�
# make rmtargets ; $(TARGETS) ������ä�
#
# �ѡ��ȥʡ��Σ���Ω���夲��
# setenv PTSRC ../:/home/hayakawa/prj/PR/libc64/:/home/hayakawa/prj/PR/libu64/:/home/hayakawa/prj/PR/libbg/:/usr/src/PR/libultra/gu/
# ptnet -host partner2 -fn rk24 -jfn k24 -fg white -bg black -width 80 -height 40 /usr/local/partner-net/n64/nptn64 -EUC
#
# z_actor_h.h �򿨤�Ȥɤ�����Υե����뤬�ƶ�������뤫��Ĵ�٤�ˤ�
# grep z_actor_h.h rom_d/Makedepend | cut -d: -f1
#


#ifndef PARALLEL
.NOTPARALLEL:				# ����ư���ػ�
#endif
.PATH: ..				# rom_?�ǥ��쥯�ȥ꤫�饽�����򸫤뤿��
.SUFFIXES :				# �ᥤ�����ϤޤǤβ�����û��
#.SUFFIXES : .c .h .s .o .i		# ɬ�פʥ��ե��å��� #HIRATSU Daisuke deleted this line.
.SUFFIXES : .h .s .o .i		# ɬ�פʥ��ե��å��� #HIRATSU Daisuke edited this line.

## ɸ��ؿ��饤�֥��
N64KITDIR    = /usr/local/n64kit
NUSTDINCDIR  = $(N64KITDIR)/nustd/include
NUSTDLIBDIR  = $(N64KITDIR)/nustd/lib


## �ǥХå���٥�(ͽ��)
## 0: ���������� �ץ����Բ�
## 1: ������     osSyncPrintf�Τ�
## 2: ���祦��   osSyncPrintf�Τ�
## 3: ������     PRINTF��
## 4: �ޥꥪ����ֽ���ǥХå���
## 5: �̾ﳫȯ�� ���פʥ�å������Τ�ɽ��
## 6: �̾ﳫȯ�� ����Ū�ʥ�å�������ɽ��
## 7: �ƥ��ȳ�ȯ��  ��å�����������äȤ��뤵��
## 8: �ǥХå�Ĵ����  �����ब���óݤ���ۤɥ�å����������뤵��
## 9: �����ƥ�ǥХå���  �����ब�ߤޤ�ۤɥ�å����������뤵��
## DEBUG_LEVEL = 6

## cc / makerom �Υ��ץ����

## DD�ѤˤĤ��ä��ǡ���������Ǥ��Ȥ߹���
## make -k "VMAKEOPTION=USE_NEW_DUNGEON=" rom_d

#ifdef USE_NEW_DUNGEON
LMAKEOPT += -DUSE_NEW_DUNGEON
#endif

## z_player.[ch] �λĳ��ä�����ä�
LMAKEOPT += -DHAYAKAWA_TESTks2

## �����ϰ�
LMAKEOPT += -DFOR_JAPAN -DFOR_USA


##LMAKEOPT += -DGRAPH_OLD_VERSION
##LMAKEOPT += -D_graph=__graph

LMAKEOPT += -DNOUSE_LINE_UCODE		# LineUcode�ϻȤ�ʤ�
###LMAKEOPT += -DZURUMODE=2		# �������ޤ��äƤ����餺��⡼��
LMAKEOPT += -DPLAY_ADJUST		# GAME_PLAY�ɲåƥ�����
LMAKEOPT += -DOPTIMIZE_NEXT_DISP	# NEXT_DISP�ι�®��
LMAKEOPT += -DUSE_DEBUG_MODE
#ifdef USE_N64DD
LMAKEOPT += -DJPN_CASSETTE_BOOT -DOVERLAY_PRG -DMULTICOUNTRY # 64DD�б�
###LMAKEOPT += -DDD_SYNCHRO # Ʊ������
LMAKEOPT += -DUSE_DD_WRITE  # ���
#endif
#LMAKEOPT+= -DHAYAKAWA_TEST=1 -DRAM4M -DSYS_FIFO_SIZE=0x8000

## make �Υ��ץ����

#ifdef ROM_D
LMAKEOPT += -DROM_D
LMAKEOPT += -DZURUMODE=2
LMAKEOPT += "-DU_${USER}_U"
#endif
#ifdef ROM_X
LMAKEOPT += -DROM_X
LMAKEOPT += -DZURUMODE=2
#endif
#ifdef ROM_F
LMAKEOPT += -DROM_F
LMAKEOPT += -DZURUMODE=0
#endif
#ifdef ROM_S
LMAKEOPT += -DROM_S
LMAKEOPT += -DZURUMODE=2
#endif
#ifdef FINAL_ROM
LMAKEOPT += -DFINAL_ROM
#endif

#ifdef ROM_ROM
LMAKEOPT +=	-DROM_ROM=1			# �ңϣ;Ƥ��ѤΥ����ɤ��Ǥ�
#endif
#ifdef EMU_ROM
LMAKEOPT +=	-DEMU_ROM=1			# �ܡ����ѤΥ����ɤ��Ǥ�
#endif
#ifdef PARTNER
LMAKEOPT +=	-DPARTNER=1			# �ѡ��ȥʡ��ѤΥ����ɤ��Ǥ�
#endif
#ifdef ISVIEWER
LMAKEOPT +=	-DISVIEWER=1			# ISVIEWER�ѤΥ����ɤ��Ǥ�
#endif

## z_play�����С��쥤��
#ifdef RAM8M
LMAKEOPT += -DRAM8M
#endif

## HIRATSU Daisuke modified under lines.
LMAKEOPT += -DUSE_CIC6105_NOCHECK=


#ifdef USE_N64DD
LMAKEOPT += -DUSE_N64DD
#endif
#ifdef USE_LEOEMU
LMAKEOPT += -DUSE_LEOEMU
#endif
#ifdef USE_COUNT
LMAKEOPT += -DUSE_COUNT
#endif

#ifdef USE_LOCALE
LMAKEOPT += -DUSE_LOCALE
#endif
#ifdef USE_DEBUG_MALLOC
LMAKEOPT += -DUSE_DEBUG_MALLOC
#endif
#ifdef SCENE_TOOL
LMAKEOPT += -DSCENE_TOOL
#endif
#ifdef SCENE_TOOL2
#endif
#ifdef DEBUG_CAMERA
LMAKEOPT += -DDEBUG_CAMERA
#endif
#ifdef PAL_VERSION
LMAKEOPT += "-DPAL_VERSION"
#endif
#ifdef GATEWAY_VERSION
LMAKEOPT += -DGATEWAY_VERSION
LMAKEOPT += -DSYS_GATEWAY_N64
#endif

#ifdef VIDEO_AUTO
LMAKEOPT += "-DVIDEO_AUTO"
#else
#ifdef PAL_VERSION
LMAKEOPT += "-DVIDEO_PAL"
#else
LMAKEOPT += "-DVIDEO_NTSC_OR_MPAL"
#endif
#endif


include $(ROOT)/usr/include/make/PRdefs
#ifdef HAYAKAWA_LIB
include /home/hayakawa/prj/PR/COMMON/SRDdefs.mk
#else
include $(ZELDA_ROOT)/srd/PR/SRDdefs.mk
#endif
include $(COMMONRULES)
#ifdef __GCC__
include $(ROOT)/usr/include/make/gccdefs
#endif

#
# �ǥ��쥯�ȥ������
#
ZELDA_LIB =	$(ZELDA_ROOT)/lib
ZELDA_TOOL =	$(ZELDA_ROOT)/tool/bin
ZELDA_DATA =	$(ZELDA_ROOT)/data
ZELDA_AUDIO =   $(ZELDA_LIB)/audio

SHELL 		= $(ROOT)/bin/sh
LD 		= $(ROOT)/usr/lib/PR/nld
MAKEMASK 	= $(ROOT)/usr/sbin/makemask
#HIRATSU Daisuke modified this line.
#MAKEMASK 	= true
#if defined(USE_CIC6105) && defined(ROM_D)
VERSUM 		= $(ZELDA_LIB)/CIC6105/981001/versum
#endif
NRDC 		= $(ZELDA_LIB)/NRDC/nrdc/nrdc

TARGETS = romPP_d

#if defined(HAYAKAWA_LIB_TEST)
HAYAKAWA_LIB =
#endif

ZELDA_INFO =    zelda_makerom.stdout

#ifdef __GCC__
MKDEPOPT=
LLDOPTS  = 
#else
LLDOPTS  = $(MKDEPOPT)
#endif
#ifdef HAYAKAWA_LIB
PATCH_DIR = /home/hayakawa/prj/PR/COMMON/patch/PR
PATCH_INCDIR = $(PATCH_DIR)
PATCH_LIBDIR = $(PATCH_DIR)
#endif
LCINCS = \
-I$(PATCH_INCDIR) \
-I$(PATCH_INCDIR)/.. \
-I$(ZELDA_LIB)
LLDOPTS += \
-L$(PATCH_LIBDIR)
#ifdef HAYAKAWA_LIB
LCINCS += \
-I/home/hayakawa/prj/PR/libu64 \
-I/home/hayakawa/prj/PR/libc64
LLDOPTS += \
-L/home/hayakawa/prj/PR/libu64 \
-L/home/hayakawa/prj/PR/libc64
#endif
LCINCS += \
-I$(COMMON_INCDIR) \
-I$(ROOT)/usr/include/PR \
-I$(NUSTDINCDIR)
LLDOPTS +=  \
-L$(ZELDA_LIB)/audio \
-L$(COMMON_LIBDIR) \
-L$(ROOT)/usr/lib/PR \
-L$(NUSTDLIBDIR)


### ����ȥ�饤�֥�������
#if defined(ROM_ROM) || defined(ISVIEWER)
ULTRALIB_BASE = ultra_rom
#elif defined(EMU_ROM) || defined(PARTNER)
ULTRALIB_BASE = ultra
#endif
ULTRALIB = -l$(ULTRALIB_BASE)
## ULTRALIB_FULLPATH = $(PATCH_LIBDIR)/lib$(ULTRALIB_BASE).a
ULTRALIB_FULLPATH = $(ROOT)/usr/lib/lib$(ULTRALIB_BASE).a
ULTRALIB2 = libultra2.a

LEOEMULIBDIR = $(ZELDA_LIB)/ISV/tool/lib
LEOLIBDIR = $(ROOT)/usr/lib

#if defined(ROM_ROM)
U64LIB_BASE = u64_rom
C64LIB_BASE = c64_rom
NUSLIB_BASE = nustd
#else /* EMU_ROM */
U64LIB_BASE = u64_d
C64LIB_BASE = c64_d
NUSLIB_BASE = nustd_d
#endif
LEOLIB_BASE = leo
LEOEMULIB_BASE = leoemu

U64LIB    = -l$(U64LIB_BASE)
C64LIB    = -l$(C64LIB_BASE)
NUSLIB    = -l$(NUSLIB_BASE)
LEOEMULIB = -l$(LEOEMULIB_BASE)
LEOLIB    = -l$(LEOLIB_BASE)

#ifdef HAYAKAWA_LIB
U64LIB_FULLPATH = /home/hayakawa/prj/PR/libu64/lib$(U64LIB_BASE).a
C64LIB_FULLPATH = /home/hayakawa/prj/PR/libc64/lib$(C64LIB_BASE).a
#else
U64LIB_FULLPATH = $(COMMON_LIBDIR)/lib$(U64LIB_BASE).a
C64LIB_FULLPATH = $(COMMON_LIBDIR)/lib$(C64LIB_BASE).a
#endif
NUSLIB_FULLPATH = $(NUSTDLIBDIR)/lib$(NUSLIB_BASE).a
LEOLIB_FULLPATH = $(LEOLIBDIR)/lib$(LEOLIB_BASE).a
LEOEMULIB_FULLPATH = $(LEOEMULIBDIR)/lib$(LEOEMULIB_BASE).a

U64LIB2    = libu642.a
C64LIB2    = libc642.a
NUSLIB2    = libnustd2.a
LEOLIB2    = libleo2.a
LEOEMULIB2 = libleoemu2.a

#
# �ե����������
#
include Makefile.CFILES			# CFILES �����
include Makefile.DISK			# DISK �Ǥ����

C++FILES =	
COBJECTS        = 	$(CFILES:.c=.o)
COBJECTS_EN     = 	$(CFILES_EN:.c=.o)
COBJECTS_EFF    = 	$(CFILES_EFF:.c=.o)
COBJECTS_Z      = 	$(CFILES_Z:.c=.o)
COBJECTS_SYS    = 	$(CFILES_SYS:.c=.o)
COBJECTS_BOOT   = 	$(CFILES_BOOT:.c=.o)
#ifdef USE_N64DD
COBJECTS_N64DD   = 	$(CFILES_N64DD:.c=.o)
#endif /* USE_N64DD */
C++OBJECTS      = 	$(C++FILES:.c++=.o)
C++OBJECTS_EN   = 	$(C++FILES_EN:.c++=.o)
C++OBJECTS_EFF  = 	$(C++FILES_EFF:.c++=.o)
C++OBJECTS_Z    = 	$(C++FILES_Z:.c++=.o)
C++OBJECTS_SYS  = 	$(C++FILES_SYS:.c++=.o)
C++OBJECTS_BOOT = 	$(C++FILES_BOOT:.c++=.o)
#ifdef USE_N64DD
C++OBJECTS_N64DD = 	$(C++FILES_N64DD:.c++=.o)
#endif /* USE_N64DD */

COBJECT_EN  = cobject_en.o
COBJECT_EFF = cobject_eff.o
COBJECT_Z   = cobject_z.o
COBJECT_SYS = cobject_sys.o
COBJECTS    = $(COBJECTS_EN) $(COBJECTS_EFF) $(COBJECTS_Z) $(COBJECTS_SYS)

CODEOBJECTS = \
	$(COBJECTS) \
	$(C++OBJECTS) \
	$(ZELDA_LIB)/z_fault.o \
	$(ZELDA_LIB)/faultprint.o \
	$(KANJIDATA1)

#ifdef USE_VOLCULL
CODEOBJECTS += $(ZELDA_LIB)/volcull.o
#endif
#ifdef USE_COUNT
CODEOBJECTS += $(ZELDA_LIB)/count.o
#endif

#ifdef PAL_VERSION

#if defined(ROM_D) || defined(ROM_X)
CODEOBJECTS +=	$(ZELDA_LIB)/audio/debug_audio_pal.o 
#else
CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio_pal.o 
#endif

#else /* PAL_VERSION */

#if defined(ROM_D) || defined(ROM_X)
CODEOBJECTS +=	$(ZELDA_LIB)/audio/debug_audio.o 
#else
CODEOBJECTS +=	$(ZELDA_LIB)/audio/audio.o 
#endif

#endif /* PAL_VERSION */

AUDIOOBJECTS =	\
	$(ZELDA_AUDIO)/aspMain.o \
	$(ZELDA_AUDIO)/audio.o \
	$(ZELDA_AUDIO)/audio_hb.o \
	$(ZELDA_AUDIO)/audio_hm.o \
	$(ZELDA_AUDIO)/audio_hs.o \
	$(ZELDA_AUDIO)/audio_hw.o \
	$(ZELDA_AUDIO)/audiotable.o \
	$(ZELDA_AUDIO)/audioheap.o

BOOTOBJECTS = \
	$(COBJECTS_BOOT) \
	$(C++OBJECTS_BOOT)

#ifdef USE_N64DD
N64DDOBJECTS = \
	$(COBJECTS_N64DD) \
	$(C++OBJECTS_N64DD)
#endif /* USE_N64DD */

# KSEG0���֤Υǡ���
DATAFILES = \
	last.c \
	sys_cfb.c \
	sys_dram_stack.c \
	sys_dynamic.c \
	sys_fifo_buffer.c \
	sys_heap.c \
	sys_yield_buffer.c \
	sys_zb.c \
	z_std_dma_data.c

DATAFILES += nullsegment.c

# Segment���֤Υǡ���
DATAFILES += \
	rcp_cfb.c \
	rcp_zb.c \
	z_hilite.c
DATAOBJECTS =	$(DATAFILES:.c=.o)

AUDIOSEGMENT =	audiosegment.o
BOOTSEGMENT =	bootsegment.o
CODESEGMENT =	codesegment.o
#ifdef USE_N64DD
N64DDSEGMENT =	n64ddsegment.o
#endif /* USE_N64DD */
KANJIDATA1 = 	kanread.o
KANJIDATA2 =	kan.o

OBJECTS =	$(BOOTSEGMENT) $(CODESEGMENT)
#ifdef USE_N64DD
OBJECTS +=	$(N64DDSEGMENT)
#endif /* USE_N64DD */
# if defined(PAL_VERSION)
OBJECTS +=	$(DATAOBJECTS)
# else
OBJECTS +=	$(DATAOBJECTS) $(KANJIDATA2)
# endif

##LMAKEOPT = -UUSE_PRERENDER
LMAKEOPT +=	-DF3DEX_GBI 			# ��ȯ�����Υޥ����������ɤ���Ѥ���
LMAKEOPT +=	-DF3DEX_GBI_2 			# ��ȯ�����Υޥ����������ɤ���Ѥ���
LMAKEOPT +=	-DUSE_VISCVG			# ���Х�å��βĻ�ɽ��
#if defined(ROM_S)
LMAKEOPT +=     -DROM_S
LMAKEOPT +=	-DSHOW_VERSION			# ���祦�С�������ѤΥ����ɤ��Ǥ�
LMAKEOPT +=	-DDEBUG_MODE_NOINPUT		# �ǥХå��쥸������Ф��ʤ�
LMAKEOPT +=	-DDISABLE_FAULT_DISPLAY		# HungUp��Ф��ʤ�
#endif
#if defined(ROM_F)
LMAKEOPT +=     -DROM_F
LMAKEOPT +=     -DFINAL_ROM
####�ޥꥪ����֥ǥХå�����HungUp��Ф��褦�ˤ���
####LMAKEOPT +=	-DDISABLE_FAULT_DISPLAY		# HungUp��Ф��ʤ�
LMAKEOPT +=	-DDEBUG_MODE_NOINPUT		# �ǥХå��쥸������Ф��ʤ�
LMAKEOPT +=	-DNOUSE_DEBUG_PAD		# �ǥХå��ѥ���ȥ�����ѥåɤ���Ѥ��ʤ�
#endif

#if defined(ROM_F) || defined(ROM_S)
OPTIMIZER = 	-O2 -g3				# ®����������
LMAKEOPT +=	-DROM_VERSION=1			# �µ��ѣңϣͤκ���
LMAKEOPT +=	-DNOUSE_PRINTF -DPRINTF_with_Warning_609 # PRINTF��Ȥ�ʤ�
LMAKEOPT +=	-DDEBUG=0			# put8x8��
LMAKEOPT +=	-DNDEBUG 			# assert�򻦤�
LMAKEOPT +=	-DUSE_TIMER=0 			# �������֤��¬���ʤ�
LMAKEOPT +=	-D_ODEBUG 			# �ǥХå��⡼��.�Ȥ�� z_camera.c �����顼�ˤʤ�ΤǼ�ꤢ��������Ƥ���ʾ�����
#else
#ifdef ROM_X
OPTIMIZER = 	-O2 -g3				# ®����������
LMAKEOPT +=	-DROM_VERSION=1			# �µ��ѣңϣͤκ���
LMAKEOPT +=	-DNOUSE_PRINTF -DPRINTF_with_Warning_609 # PRINTF��Ȥ�ʤ�
#else
OPTIMIZER = 	-O2 -g3				# ���̤˥��ץƥ��ޥ������ǥХå��Ȥ�
LMAKEOPT +=	-DROM_VERSION=0			# ���ߥ�졼���ܡ�����
LMAKEOPT +=	-UNOUSE_PRINTF			# PRINTF��Ȥ�
#endif
LMAKEOPT +=	-DDEBUG=1			# lib*_d.a����Ѥ���
LMAKEOPT +=	-DUSE_DEBUG_MOJI		# puts8x8��
LMAKEOPT +=	-DUSE_TIMER=1 			# �������֤��¬����
LMAKEOPT +=	-D_ODEBUG 			# �ǥХå��⡼��.�Ȥ�� z_camera.c �����顼�ˤʤ�
#endif
LMAKEOPT +=	-DUSE_FAULT=1 			# ���̤˥ե���ȥ�å��������Ф�
LMAKEOPT +=	-UUSE_RMON			# rmon����åɤ�ư���ʤ�

#if defined(RAM8M) && defined(ROM_D)
LMAKEOPT +=	-DUSE_SEGMENT_NAME_TABLE
#endif
#if defined(RAM8M) && !defined(ROM_F)
LMAKEOPT +=	-DUSE_ACTOR_NAME_TABLE
#endif


LLDLIBS_CODE += $(U64LIB2) $(C64LIB2)
#if 0
LLDLIBS_CODE += $(ZELDA_LIB)/ucode/us2dexNew.o
#endif
LLDLIBS_CODE += $(ZELDA_LIB)/ucode/libjpg.a
####LLDLIBS_CODE += $(ZELDA_LIB)/audio/libgsmp.a
LLDLIBS_CODE += $(ULTRALIB2) $(NUSLIB2)

LLDLIBS_BOOT += $(ZELDA_LIB)/driverominit.o	## �ʤ�Ƥ��ä�����
LLDLIBS_BOOT += $(ZELDA_LIB)/slidV10.o
LLDLIBS_BOOT += -L$(ROOT)/usr/lib $(U64LIB) $(C64LIB) 
#ifdef USE_N64DD
#ifdef USE_LEOEMU
LLDLIBS_BOOT += $(LEOEMULIB2)
LLDLIBS_BOOT += $(LEOLIB2)
#endif
#endif
#ifdef __GCC__
LLDLIBS_BOOT += -lgultra_d $(NUSLIB) $(GCCDIR)/mipse/lib/libkmc.a
#else
LLDLIBS_BOOT += $(ULTRALIB) $(NUSLIB)
#endif

###LLDLIBS_N64DD = $(ZELDA_LIB)/driveexist/driveexist.o.leo
#ifdef USE_N64DD
#ifndef USE_LEOEMU
LLDLIBS_N64DD += $(LEOLIB2)
#endif
#endif


##cfe: Warning 813:: struct/union/enum '' is used, but not defined
##cfe: Warning 828:: '' may be indistinguishable from '' due to internal name truncation
##cfe: Warning 852:: '' can be const qualified, since it is not set within its lifetime.
##cfe: Warning 814:: static '' unused
##cfe: Warning 819:: function parameter '' is not used in function ''
##cfe: Warning 820:: '' is not used in function ''
##cfe: Warning 821:: '' set but unused in function ''
##cfe: Warning 827:: implicit conversion from '' to ''
##cfe: Warning 828: /usr/include/PR/libaudio.h, line 467: 'AL_MIDI_SongPositionPointer' may be indistinguishable from 'AL_MIDI_SysEx' due to internal name truncation
#WOFF=-woff 1685,515,608,658,799,803,852,1048,1233,1499$(LWOFF)
#ifdef WARNLEVEL1
LWOFF = 	828,852,813
#elifdef WARNLEVEL2
LWOFF = 	813,828,852,814,819,820,821,827
#elifdef WARNLEVEL3
LWOFF = 	1685,515,608,658,799,803,852,1048,1233,1499,813,828,852,814,819,820,821,827
#else
###LWOFF = 	813,828,852,827
LWOFF = 	813,828,852,827,609
#endif
#ifndef __GCC__
WOFF = -woff $(LWOFF)$(VWOFF)
#endif


MAKEOPT = $(GMAKEOPT) $(LMAKEOPT) $(VMAKEOPT)

#LCINCS =
LASINCS =	$(LCINCS)
LCDEFS += $(MAKEOPT)
#ifdef __GCC__
LCOPTS = -Wall -W -G 0
LASOPTS = 	-G 0
#else
LCOPTS = -non_shared -G 0 -mips2 -fullwarn -float -xansi -Xcpluscomm -wlint,-fhp
LASOPTS =	-non_shared -G 0
#endif

LC++DEFS =	$(LCDEFS)
LC++INCS =	$(LCINCS)
LC++OPTS =	-non_shared -G 0 -mips2 -fullwarn -float -xansi +pp -woff 3259,3262,3672,3106
#: warning(3106): nested comment is not allowed
#: warning(3259): expression has no effect
#: warning(3262): variable "p1" was declared but never referenced
#: warning(3672): Mangling of signed character does not match cfront name mangling

: error(3114): identifier "" is undefined
: error(3130): the #endif for this directive is missing
: error(3232): a value of type "" cannot be used to initialize an entity of type ""
: error(3252): argument of type "" is incompatible with parameter of type ""
: error(3611): a value of type "" cannot be assigned to an entity of type ""
: error(3867): expected a member name

## ��������ʤ�auto�ѿ��� 0xffffa5a5�ˤ��Ƥ��ޤ�
## ���С������ǳ����褦�ˤ��ޤ�������Ǥ�ԡ�����ͺ���
##
###if !defined(ROM_F) && !defined(__GCC__)
##LCOPTS   += -trapuv
##LC++OPTS += -trapuv
###endif

## make clean �Ǿä�����
LDIRT  += rom_d rom_x rom_f rom_s spec_inc_ovl.inc spec_seg_ovl.inc *.rel *.map $(ULTRALIB2) $(U64LIB2) $(C64LIB2) $(NUSLIB2) zelda.gdis eptvr.dat ptn64.dat *.szp *.szs
LDIRT1 = *.d


##LLDOPTS = $(MKDEPOPT) -L$(PATCH_LIBDIR) -L$(COMMON_LIBDIR) -L$(ROOT)/usr/lib/PR
GLDOPTS =				# �ǥե���Ȥ����Ƥ�������

#ifdef __GCC__
LDFLAGS_WIDHOUT_LDLIBS = $(LDOPTS) $(ENDIAN)
#else
LDFLAGS_WIDHOUT_LDLIBS	= $(LDOPTS) $(ENDIAN)
#endif

TOOLBIN = ${ZELDA_ROOT}/tool/bin
###CAMDATINSTALLROOT = /home/umemiya/ZELDA/SAM_TOOL
CAMDATINSTALLROOT = /project/ZELDA1/link/tools/umemiya/SAM_TOOL
CAMPARAMH = camera_param_data.h
CAMERAZDB = camera.zdb
CAMDATABASE = ${ZELDA_ROOT}/data/$(CAMERAZDB)



#
# ����ȥ���Ͽ
#
all default:	genfiles $(TARGETS)

help::
	@echo '�ǿ��С������ǡ������˺ƹ��ۤ��ޤ�(rom_d/rom_x/rom_f/rom_s)'
	@echo 'make fullcourse'

# ���������ǡ�������
coall::
	coall
	$(MAKE) data

# �ե륳����2��
# make_midnight ��
# clobber ����ݤ˰����� *.szs �ե��������¸���Ƥ��ޤ�
fullcourse2::
	@echo ���Υ⡼�ɤ� make clobber ����Ѥ��ޤ�
	coall
	-rm -rf szs_x; mkdir szs_x && (cd rom_x && mv [A-Za-n]*.szs ../szs_x/. && mv [o-z]*.szs ../szs_x/.)
	-rm -rf szs_d; mkdir szs_d && (cd rom_d && mv [A-Za-n]*.szs ../szs_d/. && mv [o-z]*.szs ../szs_d/.)
	-rm -rf szs_f; mkdir szs_f && (cd rom_f && mv [A-Za-n]*.szs ../szs_f/. && mv [o-z]*.szs ../szs_f/.)
##	-rm -rf szs_s; mkdir szs_s && (cd rom_s && mv [A-Za-n]*.szs ../szs_s/. && mv [o-z]*.szs ../szs_s/.)
	$(MAKE) clobber
	-mkdir rom_d; (cd szs_d && mv [A-Za-n]*.szs ../rom_d/. && mv [o-z]*.szs ../rom_d/.) && rmdir szs_d
	-mkdir rom_x; (cd szs_x && mv [A-Za-n]*.szs ../rom_x/. && mv [o-z]*.szs ../rom_x/.) && rmdir szs_x
	-mkdir rom_f; (cd szs_f && mv [A-Za-n]*.szs ../rom_f/. && mv [o-z]*.szs ../rom_f/.) && rmdir szs_f
##	-mkdir rom_s; (cd szs_s && mv [A-Za-n]*.szs ../rom_s/. && mv [o-z]*.szs ../rom_s/.) && rmdir szs_s
	$(MAKE) camera_params
	$(MAKE) data
	$(MAKE) genfiles
##	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) rom_d rom_x rom_f

rebuild_d:
	-rm -rf szs_d; mkdir szs_d ; (cd rom_d && mv [A-Za-n]*.szs ../szs_d/. && mv [o-z]*.szs ../szs_d/.)
	-rm -rf rom_d; mkdir rom_d ; (cd szs_d && mv [A-Za-n]*.szs ../rom_d/. && mv [o-z]*.szs ../rom_d/.) && rmdir szs_d
	-$(MAKE) rom_d PARALLEL=
rebuild_x:
	-rm -rf szs_x; mkdir szs_x ; (cd rom_x && mv [A-Za-n]*.szs ../szs_x/. && mv [o-z]*.szs ../szs_x/.)
	-rm -rf rom_x; mkdir rom_x ; (cd szs_x && mv [A-Za-n]*.szs ../rom_x/. && mv [o-z]*.szs ../rom_x/.) && rmdir szs_x
	-$(MAKE) rom_x PARALLEL=
rebuild_f:
	-rm -rf szs_f; mkdir szs_f ; (cd rom_f && mv [A-Za-n]*.szs ../szs_f/. && mv [o-z]*.szs ../szs_f/.)
	-rm -rf rom_f; mkdir rom_f ; (cd szs_f && mv [A-Za-n]*.szs ../rom_f/. && mv [o-z]*.szs ../rom_f/.) && rmdir szs_f
	-$(MAKE) rom_f PARALLEL=
rebuild_s:
	-rm -rf szs_s; mkdir szs_s ; (cd rom_s && mv [A-Za-n]*.szs ../szs_s/. && mv [o-z]*.szs ../szs_s/.)
	-rm -rf rom_s; mkdir rom_s ; (cd szs_s && mv [A-Za-n]*.szs ../rom_s/. && mv [o-z]*.szs ../rom_s/.) && rmdir szs_s
	-$(MAKE) rom_s PARALLEL=
rebuild_c:
	-rm -rf szs_c; mkdir szs_c ; (cd rom_c && mv [A-Za-n]*.szs ../szs_c/. && mv [o-z]*.szs ../szs_c/.)
	-rm -rf rom_c; mkdir rom_c ; (cd szs_c && mv [A-Za-n]*.szs ../rom_c/. && mv [o-z]*.szs ../rom_c/.) && rmdir szs_c
	-$(MAKE) rom_c PARALLEL=
rebuild_all:
	-coall
	-$(MAKE) camera_params
	-$(MAKE) data
	-$(MAKE) genfiles
	-$(MAKE) rebuild_d rebuild_x rebuild_f rebuild_s
	-$(MAKE) romPP_d romPP_x romPP_f PARALLEL=
	-$(MAKE) romPP_d romPP_x romPP_f PARALLEL=
	-$(MAKE) rebuild_s rebuild_c
	-$(MAKE) romPP_s PARALLEL=
	-$(MAKE) romPP_s PARALLEL=

fullcourse3::
	-$(MAKE) cleanboot
##	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) rom_d rom_x rom_f rom_s
	-$(MAKE) romPP_d || $(MAKE) romPP_d
	-$(MAKE) romPP_x || $(MAKE) romPP_x
	-$(MAKE) romPP_f || $(MAKE) romPP_f
##	-$(MAKE) romPP_s || $(MAKE) romPP_s

# �ե륳������
fullcourse::
	coall
	$(MAKE) camera
	$(MAKE) data
	$(MAKE) genfiles
	-$(MAKE) romPP_d || $(MAKE) romPP_d

SPECFILE  = spec
SPEC_INCLUDE  = spec.segment spec.audio
LMAKEROMOPT = -I$(ZELDA_ROOT)

MAKEROMOPT = $(GMAKEROMOPT) $(LMAKEROMOPT) $(VMAKEROMOPT)

MAKEROMOBJECTS = $(OBJECTS) $(ZELDA_DATA)/*.o $(OVLOBJECTS) \
	$(ZELDA_AUDIO)/ZeldaAudio_banks.o \
	$(ZELDA_AUDIO)/ZeldaAudio_music.o \
	$(ZELDA_AUDIO)/ZeldaAudio_table.o
MAKEROMFILES = $(SPECFILE) $(SPEC_INCLUDE)  $(OVLRELFILES)


# �ޥåץե�����κ���
zelda.map: $(MAKEROMOBJECTS) $(MAKEROMFILES)
	(LANG=C ZELDA_DATA=${ZELDA_DATA} time $(MAKEROM) -m $(MAKEROMOPT) $(MAKEOPT) -r rom ../$(SPECFILE) > zelda.map)


##
## LMAKEOPTION�����
##
LMAKEOPTION =
####for GC EMU
###LMAKEOPTION += USE_N64DD=
LMAKEOPTION += USE_LOCALE=

####for GC EMU
###LMAKEOPTION += USE_CIC6105=

#ifdef PARALLEL
LMAKEOPTION += "PARALLEL=$(PARALLEL)"
#endif
#ifdef HAYAKAWA_LIB
LMAKEOPTION += "HAYAKAWA_LIB=$(HAYAKAWA_LIB)"
#endif
#ifdef FORCE_CPP
LMAKEOPTION += "FORCE_CPP=$(FORCE_CPP)"
#endif
#ifdef VMAKEOPT
LMAKEOPTION += "VMAKEOPT=$(VMAKEOPT)"
#endif
#ifdef VMAKEROMOPT
LMAKEOPTION += "VMAKEROMOPT=$(VMAKEROMOPT)"
#endif
#ifdef SCENE_TOOL
LMAKEOPTION += "SCENE_TOOL=$(SCENE_TOOL)"
#endif
#ifdef SCENE_TOOL2
LMAKEOPTION += "SCENE_TOOL2=$(SCENE_TOOL2)"
#endif
MAKEOPTION_D = $(LMAKEOPTION) $(VMAKEOPTION) ROM_D= USE_COUNT= DEBUG_CAMERA= USE_DEBUG_MALLOC= ISVIEWER= RAM8M= VIDEO_AUTO=
MAKEOPTION_X = $(LMAKEOPTION) $(VMAKEOPTION) ROM_X= USE_COUNT= DEBUG_CAMERA= USE_DEBUG_MALLOC= ISVIEWER= RAM8M= VIDEO_AUTO=
MAKEOPTION_F = $(LMAKEOPTION) $(VMAKEOPTION) ROM_F= ROM_ROM= FINAL_ROM=
MAKEOPTION_S = $(LMAKEOPTION) $(VMAKEOPTION) ROM_S= ROM_ROM= SHOW_VERSION=
MAKEOPTION_C = $(MAKEOPTION_D) ROM_C= FORCE_CPP=

LMAKEFLAGS = -f ../$(MAKEFILE)
MAKEFLAGS = $(GMAKEFLAGS) $(LMAKEFLAGS) $(VMAKEFLAGS)

zelda_d.map:
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_D)
	@echo ": Leaving directory \`./rom_d/'"

zelda_x.map:
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_X)
	@echo ": Leaving directory \`./rom_x/'"

zelda_f.map:
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) zelda.map $(MAKEOPTION_F)
	@echo ": Leaving directory \`./rom_f/'"

zelda_s.map:
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(VMAKEFLAGS)  zelda.map $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

spec.i:../$(SPECFILE) ../spec.segment ../spec_seg_ovl.inc ../boot.h ../sys_segment.h
	(LANG=C ZELDA_DATA=${ZELDA_DATA} $(CC) -E $(MAKEOPT) ../$(SPECFILE) > spec.i.tmp)
	mv spec.i.tmp spec.i

# ����إå�����ʲ���
MASKROM_VERSION = f		# ��ȯ�С���������ѡʲ���
MASKROM_PGW_INICODE = nzll	# PAL(GATEWAY)
MASKROM_GTW_INICODE = czlg	# GATEWAY
MASKROM_PAL_INICODE = nzlp	# PAL
MASKROM_JPN_INICODE = czlj	# JAPAN
MASKROM_NES_INICODE = czle	# NES
MASKROM_GAME_TITLE = "THE LEGEND OF ZELDA"
#if defined(PAL_VERSION) && defined(GATEWAY_VERSION)
MASKROM_INICODE = $(MASKROM_PGW_INICODE)
#elif !defined(PAL_VERSION) && defined(GATEWAY_VERSION)
MASKROM_INICODE = $(MASKROM_GTW_INICODE)
#elif defined(PAL_VERSION)
MASKROM_INICODE = $(MASKROM_PAL_INICODE)
#else
MASKROM_INICODE = $(MASKROM_NES_INICODE)	# HIRATSU Daisuke modified this line.
#endif

rom: $(MAKEROMOBJECTS) $(MAKEROMFILES)
	../make_version.sh $(MAKEOPTION) > version_data.h
	$(CC) $(CFLAGS) -c ../version.c
	(LANG=C ZELDA_DATA=${ZELDA_DATA} time $(MAKEROM) -d $(MAKEROMOPT) $(MAKEOPT) -r rom.tmp ../$(SPECFILE) > $(ZELDA_INFO))
	$(NRDC) -b -i$(MASKROM_INICODE) -t$(MASKROM_GAME_TITLE) -v$(MASKROM_VERSION) rom.tmp
#if defined(USE_CIC6105) && defined(ROM_D) && !defined(GATEWAY_VERSION)
	$(VERSUM) rom.tmp
#endif
	mv -f rom.tmp rom
#	-(nm zelda | sort | tee zelda.nm1 | egrep "^8" > zelda.nm)&
	-(/usr/bin/nm -B zelda | sort | tee zelda.nm2 | egrep "^8" > zelda.nm)&
#if defined(PARTNER)
	n64deb zelda		# �ѡ��ȥʡ����Ѵ�
#endif
# #if defined(PARTNER) || defined(ISVIEWER) || defined(ROM_ROM)
#	@echo "makemask�ϥ����åפ���ޤ���"
#	@echo "makemask�ϼ�Ǥ�äƤ�������"
#	@echo "���makemask rom_d/rom"
	$(MAKEMASK) rom		# ROM�Ƥ����Ѵ�
# #endif
	@-if [ \( ${USER} = "###yoshida" -o ${USER} = "###hayakawa" \) -a -f /home/iwawaki/AIFC_FILES/capture.mv ]; then \
	    audiopanel -nodisplay -nofork -outlevels 2; \
	    movieplayer -l 0 -N -z 0.5 -b q -v /home/iwawaki/AIFC_FILES/capture.mv > /dev/null; \
	else \
	    if [ -x ../bell.sh ]; then \
		    ../bell.sh; \
	    else \
	        if [ -x ./bell.sh ]; then \
		        ./bell.sh; \
	        fi; \
	    fi; \
	fi
	date
#	then playaifc /home/iwawaki/AIFC_FILES/bakabon.aifc > /dev/null; \

## �֡��ȥ������ȤǻȤ�ʤ��ä����֥������Ȥǥ饤�֥���ƹ��ۤ���
$(ULTRALIB2): $(ULTRALIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibultra.a
	cp $(ULTRALIB_FULLPATH) tmplibultra.a
	chmod 644 tmplibultra.a
	sed -n -e "s/.*libultra.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > ultra.stdout
	$(AR) d tmplibultra.a `sed -n -e "s/.*libultra.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibultra.a sprintf.o
#if defined(ISVIEWER) || defined(ROM_ROM)
	$(AR) d tmplibultra.a syncprintf.o
#endif
####if !defined(USE_LEOEMU)
###	$(AR) d tmplibultra.a driverominit.o
####endif
	chmod 444 tmplibultra.a
	mv tmplibultra.a $(ULTRALIB2)

## �֡��ȥ������ȤǻȤ�ʤ��ä����֥������Ȥǥ饤�֥���ƹ��ۤ���
$(U64LIB2): $(U64LIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibu64.a
	cp $(U64LIB_FULLPATH) tmplibu64.a
	chmod 644 tmplibu64.a
	sed -n -e "s/.*libu64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > u64.stdout
	$(AR) d tmplibu64.a `sed -n -e "s/.*libu64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	chmod 444 tmplibu64.a
	mv tmplibu64.a $(U64LIB2)

# �֡��ȥ������ȤǻȤ�ʤ��ä����֥������Ȥǥ饤�֥���ƹ��ۤ���
$(C64LIB2): $(C64LIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibc64.a
	cp $(C64LIB_FULLPATH) tmplibc64.a
	chmod 644 tmplibc64.a
	sed -n -e "s/.*libc64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > c64.stdout
	$(AR) d tmplibc64.a `sed -n -e "s/.*libc64.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	-$(AR) d tmplibc64.a assert64.o	# zelda ��assert����Ѥ��뤿��
	chmod 444 tmplibc64.a
	mv tmplibc64.a $(C64LIB2)

# �֡��ȥ������ȤǻȤ�ʤ��ä����֥������Ȥǥ饤�֥���ƹ��ۤ���
$(NUSLIB2): $(NUSLIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibnus.a
	cp $(NUSLIB_FULLPATH) tmplibnus.a
	chmod 644 tmplibnus.a
	sed -n -e "s/.*lib$(NUSLIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > nus.stdout
	$(AR) d tmplibnus.a `sed -n -e "s/.*'lib$(NUSLIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibnus.a memcpy.o strchr.o strlen.o
	chmod 444 tmplibnus.a
	mv tmplibnus.a $(NUSLIB2)

# �֡��ȥ������ȤǻȤ�ʤ��ä����֥������Ȥǥ饤�֥���ƹ��ۤ���
$(LEOLIB2): $(LEOLIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibleo.a
	cp $(LEOLIB_FULLPATH) tmplibleo.a
	chmod 644 tmplibleo.a
	sed -n -e "s/.*lib$(LEOLIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > leo.stdout
#	$(AR) d tmplibleo.a `sed -n -e "s/.*'lib$(LEOLIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	$(AR) d tmplibleo.a driverominit.o
	chmod 444 tmplibleo.a
	mv tmplibleo.a $(LEOLIB2)

# �֡��ȥ������ȤǻȤ�ʤ��ä����֥������Ȥǥ饤�֥���ƹ��ۤ���
$(LEOEMULIB2): $(LEOEMULIB_FULLPATH) $(BOOTSEGMENT)
	rm -f tmplibleoemu.a
	cp $(LEOEMULIB_FULLPATH) tmplibleoemu.a
	chmod 644 tmplibleoemu.a
	sed -n -e "s/.*lib$(LEOEMULIB_BASE).*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) > leoemu.stdout
	$(AR) d tmplibleoemu.a `sed -n -e "s/.*'lib$(LEOEMULIB_BASE)'.*(\(.*\.o\)).*/\1/p" $(BOOTSEGMENT:.o=.map) | sort | uniq`
	chmod 444 tmplibleoemu.a
	mv tmplibleoemu.a $(LEOEMULIB2)

#ifdef __GCC__
LDMAPOPT =
#else
LDMAPOPT = -m
#endif

$(AUDIOSEGMENT:.o=.map): $(AUDIOSEGMENT)
$(AUDIOSEGMENT): $(AUDIOOBJECTS)
	$(LD)  -o $(AUDIOSEGMENT) -r $(AUDIOOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_AUDIO) $(LDMAPOPT) > $(AUDIOSEGMENT:.o=.map)

$(BOOTSEGMENT:.o=.map): $(BOOTSEGMENT)
$(BOOTSEGMENT): $(BOOTOBJECTS)
	$(LD)  -o $(BOOTSEGMENT) -r $(BOOTOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_BOOT) $(LDMAPOPT) > $(BOOTSEGMENT:.o=.map)
	echo "$(BOOTSEGMENT:.o=.map) �Ǥ���"

$(N64DDSEGMENT:.o=.map): $(N64DDSEGMENT)
$(N64DDSEGMENT): $(N64DDOBJECTS) $(LEOLIB2)
	$(LD)  -o $(N64DDSEGMENT) -r $(N64DDOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_N64DD) $(LDMAPOPT) > $(N64DDSEGMENT:.o=.map)

$(CODESEGMENT:.o=.map): $(CODESEGMENT)
$(CODESEGMENT): $(CODEOBJECTS) $(ULTRALIB2) $(NUSLIB2) $(U64LIB2) $(C64LIB2)
	$(LD)  -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS_WIDHOUT_LDLIBS) $(LLDLIBS_CODE) $(LDMAPOPT) > $(CODESEGMENT:.o=.map)

$(COBJECT_EN) $(COBJECT_EN:.o=.map): $(COBJECTS_EN)
	$(LD)  -o $(COBJECT_EN) -r $(COBJECTS_EN) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_EN:.o=.map)

$(COBJECT_EFF) $(COBJECT_EFF:.o=.map): $(COBJECTS_EFF)
	$(LD)  -o $(COBJECT_EFF) -r $(COBJECTS_EFF) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_EFF:.o=.map)

$(COBJECT_Z) $(COBJECT_Z:.o=.map): $(COBJECTS_Z)
	$(LD)  -o $(COBJECT_Z) -r $(COBJECTS_Z) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_Z:.o=.map)

$(COBJECT_SYS) $(COBJECT_SYS:.o=.map): $(COBJECTS_SYS)
	$(LD)  -o $(COBJECT_SYS) -r $(COBJECTS_SYS) $(LDFLAGS) $(LDMAPOPT) > $(COBJECT_SYS:.o=.map)

## �裱���ե���� �ǡ���
CC_FLAGS  = -Wab,-r4300_mul -mips2 -O -xansi -signed -fullwarn -prototypes -Xcpluscomm -I/usr/include/PR -non_shared -G 0 -c -Dyj
##LASFLAGS = -Wab,-r4300_mul -mips2 -O2 -xansi -signed -prototypes -Xcpluscomm -I/usr/include/PR -non_shared -G 0 -c -Dyj
kanread.o	: kanread.s	;cc $(CC_FLAGS) -o $(.TARGET) $(.IMPSRC)
kan.o	: kan.s	;cc $(CC_FLAGS) -o $(.TARGET) $(.IMPSRC)

name : zelda
	/usr/bin/nm -x zelda | grep -v ref | sort +2 > $@
name2 : name
	/home/hayakawa/prj/test/namesize name > $@

cfb.o:cfb.c
	$(CC) $(LCOPTS) $(LCINCS) $(MKDEPOPT) $(WOFF) $(LCDEFS) -c cfb.c

##
###


camera: $(CAMDATABASE) $(TOOLBIN)/makecamera
	$(TOOLBIN)/makecamera -l -d$(CAMDATINSTALLROOT) $(CAMDATABASE)

camera_params:  $(CAMPARAMH)

$(CAMPARAMH):  $(CAMDATABASE) $(TOOLBIN)/makecamera
	$(TOOLBIN)/makecamera -td -q $(CAMDATABASE)

../$(CAMPARAMH):  ../../data/$(CAMERAZDB)
	$(TOOLBIN)/makecamera -td -q ../../data/$(CAMERAZDB)
	mv $(CAMPARAMH) ..

../../data/$(CAMERAZDB):
	@if [ ! -l ../../data/camera ]; \
	then \
	    if [ `echo ${HOST} | awk '{print substr($$0, 1, 3)}'` = "srd" ]; \
	    then  ln -s /project/ZELDA/data/camera ../../data; \
	    else  echo "please contact to SRD ..."; \
	    fi; \
	fi
	@if [ ! -r ../../data/$(CAMERAZDB) ]; \
	then \
	    cp ../../data/camera/$(CAMERAZDB) ../../data; \
	fi

$(CAMDATABASE):  ${ZELDA_ROOT}/data/camera/${@F}
	if [ -r $@ ] && [ ! -w $@ ]; \
	then  chmod +w $@; \
	fi
	cp ${ZELDA_ROOT}/data/camera/${@F} $@

###
##

zelda.gdis::				# �ե�����֥�ꥹ�Ȥκ���
	gdis -S \
$(GDISOPT) \
-I.. \
-I/usr/local/srd/PR/src/libu64 \
-I/usr/local/srd/PR/src/libc64 \
-I/usr/src/PR/libultra/gu zelda > zelda.gdis

# �ե�����֥�ꥹ�Ȥκ���
zelda_d.gdis::
	cd rom_d; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_x.gdis::
	cd rom_x; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_f.gdis::
	cd rom_f; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"
zelda_s.gdis::
	cd rom_s; $(MAKE) $(MAKEFLAGS) zelda.gdis "GDISOPT=$(GDISOPT)"

cleanall:
	rm -f rom*/*.o rom*/Makedepend rom*/*.map rom*/*. rom*/*.oo rom*/*.gdis rom*/*.a
cleanboot:				# ptstart()/isPrintfInit()��Ƥ�Ǥ���
	rm -f */boot.o
	rm -f */padmgr.o */main.o
#if defined(CLEAN_ALL) || defined(USE_LEOEMU)
	rm -f */idle.o */is_debug.o	# USE_LEOEMU
	rm -f */cpuprint.o */idle.o */ssSRAMrdwt.o */z_sram.o */z_std_dma.o # sys_leoemu.h
#endif
#if defined(CLEAN_ALL) || defined(RAM8M)
	rm -f */db_camera.o */z_camera.o # 8M/4M
#endif
#if defined(CLEAN_ALL) || defined(HAYAKAWA_TEST)
	rm -f */game.o */graph.o */sys_ucode.o */z_room.o */z_kaleido_manager.o */z_play.o */z_scene_table.o */z_std_dma.o
#endif

#if defined(CLEAN_ALL) || defined(USE_COUNT) || defined(USE_TIMER)
	rm -f */graph.o
#endif
#if defined(CLEAN_ALL) || defined(USE_CIC6105)
	rm -f */boot.o */z_bg_zg.o */z_en_zl2.o */z_fishing.o */sys_ucode.o */audioMgr.o */z_title.o */CIC6105.o */main.o
#endif
#if defined(CLEAN_ALL) || defined(USE_N64DD)
	rm -f */sys_cfb.o */main.o */z_select.o
#endif
#if defined(CLEAN_ALL) || defined(USE_RMON)
	rm -f */main.o */idle.o
#endif
#if defined(CLEAN_ALL) || defined(USE_ACTOR_NAME_TABLE)
	rm -f */z_actor_dlftbls.o */z_std_dma.o
#endif
#if defined(CLEAN_ALL) || defined(USE_VISCVG)
	rm -f */game.o
#endif
#if defined(CLEAN_ALL) || defined(SHOW_VERSION)
	rm -f */main.o 				# DISABLE_FAULT_DISPLAY	
	rm -f */padmgr.o			# SHOW_VERSION
#endif
#if defined(CLEAN_ALL) || defined(DEBUG_MODE_NOINPUT)
	rm -f */game.o */graph.o */z_debug.o */z_demo.o */z_file_choose.o */z_kaleido.o */z_kaleido_scope.o */z_kankyo.o */z_message.o */z_play.o */z_player.o	# DEBUG_MODE_NOINPUT
#endif
#if defined(CLEAN_ALL) || defined(GATEWAY_VERSION)
	rm -f */graph.o */ssSRAMrdwt.o */z_locale.o 
#endif

cleancode:				# ��󥯤�������ľ��
	rm -f */$(CODESEGMENT)
cleanbootseg:				# ��󥯤�������ľ��
	rm -f */$(BOOTSEGMENT)
cleanrom:				# makerom��������ľ��
	rm -f */rom
cleandepend:				# Makedepend������ä�
	rm -f */Makedepend
data:
	cd $(ZELDA_DATA); coall; shape_all

scene:
	cd $(ZELDA_DATA); $(TOOLBIN)/scene_make

keep:
	cd $(ZELDA_DATA); keep

dma_make::
	cd $(ZELDA_DATA); dma_make

# ROM�ѥС������κ���
rom_x::
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_X)
	@echo ": Leaving directory \`./rom_x/'"

# �ǥХå��С������
rom_d::
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_D)
	@echo ": Leaving directory \`./rom_d/'"

# �áܡܥС������
rom_c::
	@echo ": Entering directory \`./rom_c/'"
	mkdirhier rom_c
	cd rom_c; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_C)
	@echo ": Leaving directory \`./rom_c/'"

# �áܡܥС������
cpptest:
	@echo ": Entering directory \`./rom_c/'"
	mkdirhier rom_c
	cd rom_c; $(MAKE) $(MAKEFLAGS) $(TARGET) $(MAKEOPTION_C)
	@echo ": Leaving directory \`./rom_c/'"

# �ǽ��ңϣͥС������
rom_f::
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_F)
	@echo ": Leaving directory \`./rom_f/'"

# ���祦�С������
rom_s::
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(MAKEFLAGS) rom $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

romPP_d::
	@echo ": Entering directory \`./rom_d/'"
	mkdirhier rom_d
	cd rom_d; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_D)
	-(cd rom_d; $(MAKEMASK) romPP)
	@echo ": Leaving directory \`./rom_d/'"

romPP_x::
	@echo ": Entering directory \`./rom_x/'"
	mkdirhier rom_x
	cd rom_x; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_X)
	-(cd rom_x; $(MAKEMASK) romPP)
	@echo ": Leaving directory \`./rom_x/'"

romPP_f::
	@echo ": Entering directory \`./rom_f/'"
	mkdirhier rom_f
	cd rom_f; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_F)
	-(cd rom_f; $(MAKEMASK) romPP)
	@echo ": Leaving directory \`./rom_f/'"

romPP_s::
	@echo ": Entering directory \`./rom_s/'"
	mkdirhier rom_s
	cd rom_s; $(MAKE) $(MAKEFLAGS) romPP $(MAKEOPTION_S)
	@echo ": Leaving directory \`./rom_s/'"

romPP:rom
#	../zelda_press -p1
	../zelda_press -p2
	@-if [ \( ${USER} = "###yoshida" -o ${USER} = "###hayakawa" \) -a -f /home/iwawaki/AIFC_FILES/capture.mv ]; then \
	    movieplayer -l 0 -N -z 0.5 -b q -v /home/iwawaki/AIFC_FILES/capture.mv > /dev/null; \
	else \
	    if [ -x ../bell.sh ]; then \
		    ../bell.sh; \
	    else \
	        if [ -x ./bell.sh ]; then \
		        ./bell.sh; \
	        fi; \
	    fi; \
	fi

rom_d/rom::rom_d
rom_x/rom::rom_x
rom_f/rom::rom_f
rom_s/rom::rom_s
rom_d/romPP::romPP_d
rom_x/romPP::romPP_x
rom_f/romPP::romPP_f
rom_s/romPP::romPP_s

install::
	-rm /project/ZELDA/ROM/rom
	cp rom_d/rom /project/ZELDA/ROM/rom_d
	cp rom_x/rom /project/ZELDA/ROM/rom_x
	cp rom_f/rom /project/ZELDA/ROM/rom_f
	cp rom_s/rom /project/ZELDA/ROM/rom_s
	ln /project/ZELDA/ROM/rom_d /project/ZELDA/ROM/rom_d_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_x /project/ZELDA/ROM/rom_x_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_f /project/ZELDA/ROM/rom_f_`date '+%y-%m-%d_%H:%M:%S'`
	ln /project/ZELDA/ROM/rom_s /project/ZELDA/ROM/rom_s_`date '+%y-%m-%d_%H:%M:%S'`

main.o:sys_heap.h
z_actor_dlftbls.o:z_actor_dlftbls.decl
z_actor_profile.o:z_actor_dlftbls.decl
z_scene.o:z_actor_dlftbls.decl

genfiles:spec_seg_ovl.inc spec_inc_ovl.inc camera_params
z_segment.decl:spec.i
	grep include spec.i | \
grep -v "\." | \
grep -v '"nullsegment"' | \
grep -v '"hilite"' | \
grep -v '"fifobuffer"' | \
grep -v '"yieldbuffer"' | \
grep -v '"SystemDynamic"' | \
grep -v '"dramstackbuffer"' | \
grep -v '"yieldbuffer"' | \
grep -v '"zbuffer"' | \
grep -v '"rcp_cfb"' | \
grep -v '"rcp_zb"' | \
grep -v '"Audioheap"' | \
grep -v '"SystemHeap"' | \
grep -v '"object_go2"' | \
grep -v '"object_stk"' | \
grep -v '"object_gate"' | \
sed -e 's/[ 	]*include[ 	]*"\(.*\)"[ 	]*/_DECL_(\1)/' > z_segment.decl.tmp
	mv z_segment.decl.tmp z_segment.decl

../rom_d/z_segment.decl:z_segment.decl
../rom_x/z_segment.decl:z_segment.decl
../rom_f/z_segment.decl:z_segment.decl
../rom_s/z_segment.decl:z_segment.decl
../rom_c/z_segment.decl:z_segment.decl
spec_seg_ovl.inc:spec_ovl.dat make_spec_seg_ovl.sh
	make_spec_seg_ovl.sh < spec_ovl.dat > spec_seg_ovl.inc~$$$$~ && mv spec_seg_ovl.inc~$$$$~ spec_seg_ovl.inc
spec_inc_ovl.inc:spec_ovl.dat make_spec_inc_ovl.sh
	make_spec_inc_ovl.sh < spec_ovl.dat > spec_inc_ovl.inc~$$$$~ && mv spec_inc_ovl.inc~$$$$~ spec_inc_ovl.inc

z_std_dma.o:z_segment.decl
z_std_dma_data.o:z_segment.decl

# ��¸�ե�����(depend)��Ĥ���
DEPEND_FILES = $(COBJECTS:.o=.dep)
.SUFFIXES : .dep
.c.dep :
	$(CC) $(CFLAGS) -M $(.IMPSRC) > $(.PREFIX).dep
.cxx.dep .C.dep .c++.dep :
	$(CXX) $(CXXFLAGS) -M $(.IMPSRC) > $(.PREFIX).dep
depend : $(DEPEND_FILES)
test:test.o
	cc -non_shared -o test test.o
touch_z_actor_dlftbls.decl:
	@echo "z_actor_dlftbls.decl�ν��֤�����פǤ�����"
	touch 01010001 z_actor_dlftbls.decl
	touch 01010000 rom_[dfxs]/z_actor.o rom_[dfxs]/z_actor_dlftbls.o
#ifmake fluff
GCDEFS = $(HW_FLAGS) -F
#endif

## ��¼����˥�����Ϥ�
z_en_oA2.o:z_en_oA2_inWater.c

ikuiku_d:
	cp rom_d/rom /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/rom_d
ikuiku_f:
	cp rom_f/romPP /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/romPP_f
ikuiku_x:
	cp rom_x/romPP /auto/srd-server/home/mnt01/srd00/srd/GC-ZELDA/kimura/upload/romPP_x


#HIRATSU Daiuske added below lines.
z_message.o : z_message.c
	$(CC) $(CFLAGS) -c ../z_message.c

z_common_data.o : z_common_data.c
	$(CC) $(CFLAGS) -c ../z_common_data.c

z_locale.o : z_locale.c
	$(CC) $(CFLAGS) -c ../z_locale.c

z_std_dma_slid.o : ../z_std_dma_slid.c
	$(CC) $(CFLAGS) -c ../z_std_dma_slid.c