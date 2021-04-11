#include "checker.h"

int		print_lst(t_list *first)
{
	t_list	*lst;
	int		*ptr;
	int		i;

	lst = first;
	i = 0;
	printf("\033[0;32m");
	printf("\n");
	printf("||||||||||||||||||||||||\n");
	printf("|||||| PRINT_LIST ||||||\n");
	printf("|||||| size = %3zu ||||||\n", ft_lstsize(lst));
	printf("||||||||||||||||||||||||\n");
	printf("|                      |\n");
	while (lst != NULL)
	{
		ptr = lst->content;
		printf("|  |================|  |\n");
		printf("|  |%16p|  |\n", lst);
		printf("|  |            #%3d|  |\n", i);
		printf("|  |================|  |\n");
		printf("|  |   data = %3d   |  |\n", *ptr);
		printf("|  |    next        |  |\n");
		printf("|  |_____||_________|  |\n");
		printf("|        ||            |\n");
		printf("|        \\/            |\n");
		i++;
		lst = lst->next;
	}
	if (lst == NULL)
	{
		printf("|  |================|  |\n");
		printf("|  |    NULL        |  |\n");
		printf("|  |================|  |\n");
	}
	printf("|                      |\n");
	printf("|______________________|\n");
	printf("\n");
	printf("\033[0m\n");
	return (0);
}

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

void	inst_sa(t_list **stack_a, t_list **stack_b)
{
	t_list	*link0;
	t_list	*link2;

	(void)stack_b;
	link0 = *stack_a;
	link2 = (*stack_a)->next->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->next = link0;
	(*stack_a)->next->next = link2;
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
		inst[get_inst_index(*instructions)](&stack_a, &stack_b);
		instructions++;
	}
}
