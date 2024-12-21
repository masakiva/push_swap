#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

#define HASH_TABLE_SIZE 4096

void  free_hash_table(t_list *hash_table[HASH_TABLE_SIZE])
{
  size_t  i;

  i = 0;
  while (i < HASH_TABLE_SIZE)
  {
    if (hash_table[i] != NULL)
      ft_lstclear(&hash_table[i], free_content);
    i++;
  }
}

size_t  hash_function(int n)
{
  return ((size_t)ft_abs(n % HASH_TABLE_SIZE));
}

t_bool  has_duplicates(t_list *stack)
{
  int     cur_int;
  size_t  hash_index;
  t_list  *hash_table[HASH_TABLE_SIZE];
  t_bool   res;

  res = FALSE;
  ft_bzero(hash_table, HASH_TABLE_SIZE * sizeof(t_list *));
  while (stack != NULL)
  {
    cur_int = *(int *)stack->content;
    hash_index = hash_function(cur_int);

    if (hash_table[hash_index] != NULL
      && is_in_list(hash_table[hash_index], cur_int))
    {
      res = TRUE;
      break ;
    }
    append_nb_to_list(&hash_table[hash_index], cur_int);
    stack = stack->next;
  }
  free_hash_table(hash_table);
  return (res);
}
