/* vi: set sw=4 ts=4: */
/*
 * Utility routines.
 *
 * Copyright (C) tons of folks.  Tracking down who wrote what
 * isn't something I'm going to worry about...  If you wrote something
 * here, please feel free to acknowledge your work.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * Based in part on code from sash, Copyright (c) 1999 by David I. Bell 
 * Permission has been granted to redistribute this code under the GPL.
 *
 */

#include <stdio.h>
#include <string.h>
#include "../pwd_grp/pwd.h"
#include "../pwd_grp/grp.h"
#include "libbb.h"



/* gets a gid given a user name */
long my_getpwnamegid(const char *name)
{
	struct group *mygroup;
	struct passwd *myuser;

	myuser=getpwnam(name);
	if (myuser==NULL)
		error_msg_and_die("unknown user name: %s", name);

	mygroup  = getgrgid(myuser->pw_gid);
	if (mygroup==NULL)
		error_msg_and_die("unknown gid %ld", (long)myuser->pw_gid);

	return mygroup->gr_gid;
}


/* END CODE */
/*
Local Variables:
c-file-style: "linux"
c-basic-offset: 4
tab-width: 4
End:
*/
