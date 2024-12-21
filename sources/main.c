#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void  print_nb_lst(void *content)
{
  ft_putnbr_fd(*(int *)content, STDOUT_FILENO);
  ft_putchar_fd('\n', STDOUT_FILENO);
}

int main(int argc, char **argv)
{
  t_stacks  stacks;

  if (argc == 1)
    return (EXIT_SUCCESS);

  stacks.a = init_stack(argv + 1);
  if (stacks.a == NULL)
  {
    ft_putstr_fd("Error\n", STDERR_FILENO);
    return (EXIT_FAILURE);
  }
  ft_lstiter(stacks.a, print_nb_lst);
  ft_lstclear(&stacks.a, free_content);
	return (EXIT_SUCCESS);
}
