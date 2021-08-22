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
typedef char *			t_str;
typedef unsigned int	t_uint;

typedef struct s_file {
	t_str		content;
	t_uint 		length;
}	t_file;

typedef struct s_dict {
	t_str	number;
	t_str	text;
}	t_dict;

typedef struct s_rush {
	t_file	file;
	t_dict	*dict;
	t_uint	lines;
	t_str	dictname;
	t_str	number;
}	t_rush;

// FileFT
t_bool	ft_file_exists(t_str path);
t_uint	ft_filelen(t_str path);
t_file	ft_fileread(t_str path);

// CharFT
t_bool	ft_isnbr(char c);
t_bool	ft_ischar(char c, char comp);
t_bool	ft_charinset(char c, t_str charset);

// StringFT
t_uint	ft_strlen(t_str str);
t_uint	ft_strlenuntil(t_str str, t_str stop);
t_bool	ft_strhas(t_str str, t_str charset);
t_bool	ft_stronlyhas(t_str str, t_str charset);
t_uint	ft_strcount(t_str str, char c);
t_bool	ft_strcmp(t_str s1, t_str s2);
t_str	ft_strucat(t_str dest, t_str src, t_str stop);
t_str	ft_strscat(t_str dest, t_str src);

// ParseFT
t_rush	ft_dictparse(t_str	dictpath);

// WatiFT
t_str	ft_watisuite(t_str str);
t_str	ft_watireste(t_str str);
t_str	ft_watiunit(t_str str);
t_str	ft_watidec(t_str str);
t_uint	ft_watisum(t_rush rush, t_str s);
void	ft_waticat(t_rush rush, t_str dest, t_str s);

// DictFT
t_str	ft_getdict(t_rush rush, t_str key);

// PutFT
void	ft_putstr(t_str str);

#endif