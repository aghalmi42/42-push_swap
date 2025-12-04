/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:33:09 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/03 22:58:59 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min_index_pos(t_stack *a)
{
	t_node	*current;
	int		min_index;
	int		min_pos;
	int		pos;

	current = a->top;
	min_index = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

int	find_target_position(t_stack *a, int b_index)
{
	t_node	*current;
	int		target_pos;
	int		target_index;
	int		pos;

	target_pos = -1;
	target_index = 2147483647;
	current = a->top;
	pos = 0;
	while (current)
	{
		if (current->index > b_index && current->index < target_index)
		{
			target_index = current->index;
			target_pos = pos;
		}
		pos++;
		current = current->next;
	}
	if (target_pos == -1)
		target_pos = find_min_index_pos(a);
	return (target_pos);
}

int	calcul_cost_a(t_stack *a, int target_pos)
{
	int	size;

	size = a->size;
	if (target_pos <= size / 2)
		return (target_pos);
	return (-(size - target_pos));
}

int	calcul_cost_b(t_stack *b, int b_pos)
{
	int	size;

	size = b->size;
	if (b_pos <= size / 2)
		return (b_pos);
	return (-(size - b_pos));
}
