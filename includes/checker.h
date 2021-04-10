#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# include "libft.h"

# define	NB_INSTRUCTIONS	11

int		print_lst(t_list *first);

typedef void	(*t_instruction)(t_list **stack_a, t_list **stack_b);

void	execute_instructions(t_list *stack_a, char **instructions);

#endif
