#include "checker.h"

void	free_content(void *content)
{
	free(content);
}

int		*get_and_check_number(char *nb_str, t_list *stack)
{
	int		*nb;

	nb = NULL;
	if (ft_isint(nb_str) == TRUE)
	{
		nb = (int *)malloc(sizeof(int));
		if (nb != NULL)
		{
			*nb = ft_atoi(nb_str);
			while (stack != NULL)
			{
				if (*((int *)(stack->content)) == *nb)
				{
					free(nb);
					return (NULL);
				}
				stack = stack->next;
			}
		}
	}
	return (nb);
}

t_list	*implement_stack_a(char **numbers, size_t stack_size)
{
	t_list	*stack;
	int		*cur_nb;
	t_list	*cur_link;
	size_t	i;

	stack = NULL;
	i = 0;
	while (i < stack_size)
	{
		cur_nb = get_and_check_number(numbers[i], stack);
		if (cur_nb == NULL)
		{
			ft_lstclear(&stack, free_content);
			return (NULL);
		}
		cur_link = ft_lstnew(cur_nb);
		if (cur_link == NULL)
		{
			free(cur_nb);
			ft_lstclear(&stack, free_content);
			return (NULL);
		}
		ft_lstadd_back(&stack, cur_link);
		i++;
	}
	return (stack);
}

int		check_instruction(char *instruction)
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
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	**push_instruction(char **instructions, char *input, int gnl_ret)
{
	char	**new_instructions;

	new_instructions = NULL;
	if (check_instruction(input) == TRUE)
	{
		new_instructions = push_str_to_array(instructions, input);
		if (new_instructions == NULL)
		{
			free(instructions);
			free(input);
		}
	}
	else if (gnl_ret == 0 && input[0] == '\0')
		new_instructions = instructions;
	else
	{
		free(instructions);
		free(input);
	}
	return (new_instructions);
}

char	**get_instructions(void)
{
	char	**instructions;
	char	*line;
	int		ret;

	instructions = NULL;
	ret = 1;
	line = NULL;
	while (ret == 1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == ERROR)
		{
			free(instructions);
			return (NULL);
		}
		instructions = push_instruction(instructions, line, ret);
		if (instructions == NULL)
			break ;
	}
	return (instructions);
}

void	print_int(void *content)
{
	printf("%d\n", *(int *)content);
}

void	inst_sa(t_list **stack_a, t_list **stack_b);
int		main(int argc, char **argv)
{
	t_list	*stack_a;
	//char	**instructions;

	if (argc > 1)
	{
		stack_a = implement_stack_a(argv + 1, (size_t)(argc - 1));
		if (stack_a == NULL)
		{
			write(STDOUT_FILENO, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		//instructions = get_instructions();
		//if (instructions == NULL)
		//{
			//write(STDOUT_FILENO, "Error\n", 6);
			//return (EXIT_FAILURE);
		//}
		print_lst(stack_a);
		//ft_lstiter(stack_a, print_int);
		//printf("number of instructions = %zu\n", ft_arraylen(instructions));
		//ft_printarray_fd(instructions, STDOUT_FILENO);
		//execute_instructions(stack_a, instructions);
	t_list	*link0;
	t_list	*link2;

	link0 = stack_a;
	link2 = stack_a->next->next;
	stack_a = stack_a->next;
	stack_a->next = link0;
	stack_a->next->next = link2;
	//print_lst(swap);
		printf("\nRESULT\n");
		print_lst(stack_a);
		ft_lstclear(&stack_a, free_content);
		//free(instructions);
	}
	return (EXIT_SUCCESS);
}
