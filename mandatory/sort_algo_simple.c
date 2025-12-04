/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:58:08 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 20:38:36 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_mini_position(t_stack *stack)
{
	t_node	*current;
	t_node	*mini_node;
	int		position;
	int		count;

	position = 0;
	count = 0;
	current = stack->top;
	mini_node = current;
	while (current)
	{
		if (current->value < mini_node->value)
		{
			mini_node = current;
			position = count;
		}
		current = current->next;
		count++;
	}
	return (position);
}

static void	push_small_number(t_stack *a, t_stack *b)
{
	int	position;
	int	size;
	int	i;

	i = 0;
	position = find_mini_position(a);
	size = a->size;
	if (position <= size / 2)
	{
		while (i < position)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = position;
		while (i < size)
		{
			rra(a);
			i++;
		}
	}
	pb(a, b);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;
	int	max;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	max = first;
	if (second > max)
		max = second;
	if (third > max)
		max = third;
	if (first == max)
		ra(a);
	else if (second == max)
		rra(a);
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_all_small_number(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
	{
		push_small_number(a, b);
		sort_three(a);
		pa(b, a);
	}
	else if (size == 5)
	{
		push_small_number(a, b);
		push_small_number(a, b);
		sort_three(a);
		pa(b, a);
		pa(b, a);
	}
}
