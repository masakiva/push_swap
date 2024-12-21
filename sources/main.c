#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_bool  push_nbs_to_stack(char *input, t_list **alst)
{
  while (*input != '\0')
  {
    if (!ft_isint(input))
      return (FAILURE);
    if (append_nb_to_list(alst, ft_atoi(input)) == FAILURE)
      return (FAILURE);
    input = skip_int(input);
  }
  return (SUCCESS);
}

t_list  *init_stack(char **input_arr)
{
  t_list  *stack;
  t_bool   err;

  stack = NULL;
  err = FALSE;
  while (*input_arr != NULL)
  {
    if (push_nbs_to_stack(*input_arr, &stack) == FAILURE)
    {
      err = TRUE;
      break ;
    }
    input_arr++;
  }
  if (err == TRUE || has_duplicates(stack) == TRUE)
  {
    ft_lstclear(&stack, free_content);
    return (NULL);
  }
  return (stack);
}

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
