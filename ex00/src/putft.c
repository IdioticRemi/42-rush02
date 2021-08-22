#include <rush02.h>

void	ft_putstr(t_str str)
{
	write(1, str, ft_strlen(str));
}
