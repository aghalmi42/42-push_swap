/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 21:24:11 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 23:29:00 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	parsing_argument_2(t_stack *stack, char *av)
{
	int		value;
	t_node	*node;

	if (!is_number(av))
		is_error();
	value = check_atoi(av);
	node = create_node(value);
	if (!node)
		is_error();
	bottom_lifo(stack, node);
}

t_stack	*parsing_argument(int ac, char **av)
{
	t_stack	*stack;
	int		i;

	i = 1;
	if (ac < 2)
		return (0);
	stack = create_stack();
	if (!stack)
		is_error();
	while (i < ac)
	{
		parsing_argument_2(stack, av[i]);
		i++;
	}
	if (is_duplicate(stack))
	{
		free_stack(stack);
		is_error();
	}
	return (stack);
}
