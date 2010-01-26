/*  Copyright 1997,1998,2001-2003,2006,2009 Alain Knaff.
 *  Copyright 2010 Volker Lanz (vl@fidra.de)
 *  This file is part of mtools.
 *
 *  Mtools is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Mtools is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Mtools.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MTOOLS_PARTITION_H
#define MTOOLS_PARTITION_H

struct hsc
{
	unsigned char byte0;
	unsigned char head;		/* starting head */
	unsigned char sector;		/* starting sector */
	unsigned char cyl;		/* starting cylinder */
};

#define head(x) ((unsigned int)((x).head))
#define sector(x) ((unsigned int)((x).sector & 0x3f))
#define cyl(x) ((unsigned int)((x).cyl | (((x).sector & 0xc0)<<2)))

#define BEGIN(p) _DWORD((p).start_sect)
#define END(p) (_DWORD((p).start_sect)+(_DWORD((p).nr_sects)))

#define boot_ind start.byte0
#define sys_ind end.byte0

struct partition
{
	struct hsc start;
	struct hsc end;
	unsigned char start_sect[4];	/* starting sector counting from 0 */
	unsigned char nr_sects[4];     	/* nr of sectors in partition */
};


#endif