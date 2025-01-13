/*
SDLPoP, a port/conversion of the DOS game Prince of Persia.
Copyright (C) 2013-2023  Dávid Nagy

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

The authors of this program may be contacted at https://forum.princed.org
*/

#ifndef COMMON_H
#define COMMON_H

#ifdef DREAMCAST
#include <kos/fs.h>

// Define `DC_FILE` as an alias for `file_t`
typedef file_t DC_FILE;

#define dc_fopen(path, mode)      fs_open(path, O_RDONLY)
#define dc_fclose(file)           fs_close(file)
#define dc_fseek(file, offset, whence) fs_seek(file, offset, whence)
#define dc_ftell(file)            fs_tell(file)

#else
// Use standard library for other platforms
#define DC_FILE FILE
#define dc_fopen(path, mode)      fopen(path, mode)
#define dc_fclose(file)           fclose(file)
#define dc_fseek(file, offset, whence) fseek(file, offset, whence)
#define dc_ftell(file)            ftell(file)
#endif

//setup vmu display image
#include <kos.h>
#include <kos/string.h>
#include <dc/maple.h>
#include <dc/maple/controller.h>
#include <dc/maple/vmu.h>
#include <adx/adx.h> /* ADX Decoder Library */
#include <adx/snddrv.h> /* Direct Access to Sound Driver */
#include <oggvorbis/sndoggvorbis.h>
#include <dc/sound/sound.h>
#include <dc/sound/sfxmgr.h>
#include <wav/sndwav.h>
//#include "util.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __STDC_ALLOC_LIB__
#define __STDC_WANT_LIB_EXT2__ 1
#else
#define _POSIX_C_SOURCE 200809L
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef _MSC_VER // unistd.h does not exist in the Windows SDK.
#include <unistd.h>
#else
#ifndef _UNISTD_H
#define _UNISTD_H    1
#define F_OK    0       /* Test for existence.  */
#define access _access
#endif
#endif

// S_ISREG and S_ISDIR may not be defined under MSVC
#ifndef S_ISREG
#define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif
#ifndef S_ISDIR
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#include "config.h"
#include "types.h"
#include "proto.h"
#include "data.h"

#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif
#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif
#ifndef ABS
#define ABS(x) ((x)<0?-(x):(x))
#endif

#ifdef DISABLE_SNPRINTF_CHECKS
#define snprintf_check(dst, size, ...) snprintf(dst, size, __VA_ARGS__)
#else
#define snprintf_check(dst, size, ...)	do {			\
		int __len;					\
		__len = snprintf(dst, size, __VA_ARGS__);	\
		if (__len < 0 || __len >= (int)size) {		\
			fprintf(stderr, "%s: buffer truncation detected!\n", __func__);\
			quit(2);				\
		}						\
	} while (0)
#endif


#ifdef __cplusplus
}
#endif

#endif
