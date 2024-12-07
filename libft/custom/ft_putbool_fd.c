#include "libft.h"

t_bool	ft_putbool_fd(t_bool val, int fd)
{
  if (val == TRUE)
    return (ft_putstr_fd("TRUE", fd));
  return (ft_putstr_fd("FALSE", fd));
}
