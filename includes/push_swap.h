#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stacks
{
	t_list*	a;
	t_list*	b;
}				t_stacks;

// parsing
t_bool  push_nbs_to_stack(char *input, t_list **alst);
t_list  *init_stack(char **input_arr);

// utils
t_bool  append_nb_to_list(t_list **alst, int nb);
t_bool  is_in_list(t_list *lst, int nb);
void    free_content(void *content);

// check_duplicates
t_bool  has_duplicates(t_list *stack);

#endif // PUSH_SWAP_H
