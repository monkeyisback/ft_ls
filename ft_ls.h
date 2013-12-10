#ifndef _FT_LS_H_
# define _FT_LS_H_
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

typedef struct	s_arglist
{
  char arg_l;
  char arg_R;
  char arg_a;
  char arg_r;
  char arg_t;
}		t_arglist;

#endif /* arguments de arglist : -l -R -a -r -t */
