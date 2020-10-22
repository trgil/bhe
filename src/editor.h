/************************************************************************
 * Copyright (c) 2020, Gil Treibush
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * A copy of the full GNU General Public License is included in this
 * distribution in a file called "COPYING" or "LICENSE".
 ***********************************************************************/

#ifndef _EDITOR_H__
#define _EDITOR_H__

#include <stdint.h>
#include <sys/types.h>

int bhe_run_editor(int fd, uint8_t *file_buf, off_t file_buf_size);

#endif /* _EDITOR_H__ */
