/* $Id: camera.h,v 1.1.1.1 2003/01/17 21:07:13 tong Exp $ */
/*
 * ����饯�饹
 */

#ifndef __CAMERA_H_
#define __CAMERA_H_

#include "u64basic.h"

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

typedef struct camera_s {
    xyz_t		eye;		/* ���� */
    xyz_t		center;		/* �濴 */
    xyz_t		up;		/* ������ */
} camera_t;
typedef camera_t Camera;

void camera_init(Camera *);
void camera_set_camera(Camera *);

#ifdef _LANGUAGE_C_PLUS_PLUS
} /* extern "C" */
#endif

#endif /* __CAMERA_H_ */