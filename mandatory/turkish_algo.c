/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:08:03 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/03 04:54:50 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_three_by_index(t_stack *a)
{
	int	first;
	int	second;
	int	third;
	int	max;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	max = first;
	if (second > max)
		max = second;
	if (third > max)
		max = third;
	if (first == max)
		ra(a);
	else if (second == max)
		rra(a);
	if (a->top->index > a->top->next->index)
		sa(a);
}

static int	find_min_index_position(t_stack *a)
{
	t_node	*current;
	int		position;
	int		i;

	current = a->top;
	position = 0;
	i = 0;
	while (current)
	{
		if (current->index == 0)
		{
			position = i;
			break ;
		}
		current = current->next;
		i++;
	}
	return (position);
}

static void	final_rotate(t_stack *a)
{
	int	min_pos;
	int	size;
	int	i;

	min_pos = find_min_index_position(a);
	size = a->size;
	if (min_pos <= size / 2)
	{
		i = 0;
		while (i < min_pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = min_pos;
		while (i < size)
		{
			rra(a);
			i++;
		}
	}
}

void	turkish_algo(t_stack *a, t_stack *b)
{
	index_for_all_value(a);
	push_chunk_to_b(a, b);
	sort_three_by_index(a);
	push_back_a(a, b);
	final_rotate(a);
}
