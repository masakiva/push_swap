#include "push_swap.h"

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
