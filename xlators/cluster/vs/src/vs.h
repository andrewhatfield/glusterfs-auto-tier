/*
   Copyright (c) 2013 Andrew Hatfield <andrew.hatfield@cynosureservices.com>
   This file is part of GlusterFS.

   This file is licensed to you under your choice of the GNU Lesser
   General Public License, version 3 or any later version (LGPLv3 or
   later), or the GNU General Public License, version 2 (GPLv2), in all
   cases as published by the Free Software Foundation.
*/
#ifndef __VS_H__
#define __VS_H__

#ifndef _CONFIG_H
#define _CONFIG_H
#include "config.h"
#endif

typedef struct {
	gf_boolean_t encrypt_write;
	gf_boolean_t decrypt_read;
} vs_private_t;

#endif /* __VS_H__ */
