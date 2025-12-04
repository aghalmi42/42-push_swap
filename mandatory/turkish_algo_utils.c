/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:17:33 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/03 22:57:38 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	divide_in_chunk(int size)
{
	if (size <= 16)
		return (1);
	if (size <= 100)
		return (4);
	if (size <= 500)
		return (10);
	return (15);
}

static int	find_push_i_to_position(t_stack *a, int max_index)
{
	t_node	*current;
	int		position;

	current = a->top;
	position = 0;
	while (current)
	{
		if (current->index <= max_index)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}

static void	rotate_to_position(t_stack *a, int position)
{
	int	size;
	int	i;

	size = a->size;
	if (position <= size / 2)
	{
		i = 0;
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
}

static void	push_one_to_b(t_stack *a, t_stack *b, int position, int *values)
{
	rotate_to_position(a, position);
	pb(a, b);
	if (b->size > 1 && b->top->index < values[3] / 2)
		rb(b);
}

void	push_chunk_to_b(t_stack *a, t_stack *b)
{
	int	values[4];
	int	push_i;
	int	position;

	values[0] = a->size;
	values[1] = divide_in_chunk(values[0]);
	values[2] = values[0] / values[1];
	values[3] = values[2];
	push_i = 0;
	while (push_i < values[0] - 3)
	{
		position = find_push_i_to_position(a, values[3]);
		if (position != -1)
		{
			push_one_to_b(a, b, position, values);
			push_i++;
		}
		else
			values[3] += values[2];
	}
}
