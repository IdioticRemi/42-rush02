#ifndef RUSH02_H
# define RUSH02_H

# define TRUE	1
# define FALSE	0

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef int				t_bool;
typedef char*			t_str;
typedef unsigned int	t_uint;

typedef struct s_dict {
	t_str	number;
	t_str	text;
}	t_dict;

typedef struct s_rush {
	t_dict	*dict;
	t_str	dictname;
	t_str	number;
}	t_rush;

#endif
