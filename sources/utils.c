#include "push_swap.h"
#include <stdlib.h>

t_bool  append_nb_to_list(t_list **alst, int nb)
{
  int     *nb_ptr;
  t_list  *link;

  nb_ptr = (int *)malloc(sizeof(int));
  if (nb_ptr == NULL)
    return (FAILURE);
  *nb_ptr = nb;
  link = ft_lstnew(nb_ptr);
  if (link == NULL)
    return (FAILURE);
  ft_lstadd_back(alst, link);
  return (SUCCESS);
}

t_bool  is_in_list(t_list *lst, int nb)
{
  int  cur_int;

  while (lst != NULL)
  {
    cur_int = *(int *)lst->content;
    if (cur_int == nb)
      return (TRUE);
    lst = lst->next;
  }
  return (FALSE);
}

void  free_content(void *content)
{
  free(content);
}
