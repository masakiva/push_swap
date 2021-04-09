#include "checker.h"

size_t	get_inst_index(char *instruction)
{
	const char	*inst_list[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"};
	size_t		i;

	i = 0;
	while (i < NB_INSTRUCTIONS)
	{
		if (ft_strcmp(instruction, inst_list[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

void	inst_sa(t_list *stack_a, t_list *stack_b)
{
	t_list	*swap;

	(void)stack_b;
	swap = stack_a->next->next;
	stack_a->next->next = stack_a;
	stack_a->next = swap;
}

void	execute_instructions(t_list *stack_a, char **instructions)
{
	t_list	*stack_b;
	static t_instruction	inst[1/*NB_INSTRUCTIONS*/] = {inst_sa/*, inst_sb, inst_ss,
		inst_pa, inst_pa, inst_pb, inst_ra, inst_rb, inst_rr, inst_rra,
		inst_rrb, inst_rrr*/};

	stack_b = NULL;
	while (*instructions != NULL)
	{
		inst[get_inst_index(*instructions)](stack_a, stack_b);
	}
}
