#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_bool  append_input_nb_to_list(char *input, t_list **alst)
{
  int     *cur_int;
  t_list  *cur_link;

  while (*input != '\0')
  {
    if (!ft_isint(input))
      return (FAILURE);
    cur_int = (int *)malloc(sizeof(int));
    if (cur_int == NULL)
      return (FAILURE);
    *cur_int = ft_atoi(input);
    cur_link = ft_lstnew(cur_int);
    if (cur_link == NULL)
      return (FAILURE);
    ft_lstadd_back(alst, cur_link);
    input = skip_int(input);
  }
  return (SUCCESS);
}

t_list  *init_stack(char **input_arr)
{
  t_list  *stack_a;

  while (*input_arr != NULL)
  {
    if (append_input_nb_to_list(*input_arr, &stack_a) == FAILURE)
      return (NULL);
    input_arr++;
  }
  return (stack_a);
}

void  print_nb_lst(void *content)
{
  ft_putnbr_fd(*(int *)content, STDOUT_FILENO);
  ft_putchar_fd('\n', STDOUT_FILENO);
}

void  free_content(void *content)
{
  free(content);
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
