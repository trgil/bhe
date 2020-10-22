########################################################################
# Copyright (c) 2020, Gil Treibush
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License, version 2, as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# A copy of the full GNU General Public License is included in this
# distribution in a file called "COPYING" or "LICENSE".
########################################################################

OUT_FILE = bhe
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

.PHONY: all clean
.DEFAULT: all

all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT_FILE)

$(OBJS) : $(SRCS)

clean:
	rm -fr $(OBJS) $(OUT_FILE)
