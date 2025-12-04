/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo_utils_5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:55:31 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/03 22:46:26 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_direction_a(t_stack *a, int target_pos)
{
	if (target_pos <= a->size / 2)
		return (1);
	return (-1);
}

int	get_direction_b(t_stack *b, int b_pos)
{
	if (b_pos <= b->size / 2)
		return (1);
	return (-1);
}

t_node	*get_node_at_pos(t_stack *b, int b_pos)
{
	t_node	*current;
	int		i;

	current = b->top;
	i = 0;
	while (i < b_pos)
	{
		current = current->next;
		i++;
	}
	return (current);
}

static int	get_combined_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = cost_a;
	abs_b = cost_b;
	if (abs_a < 0)
		abs_a = -abs_a;
	if (abs_b < 0)
		abs_b = -abs_b;
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

int	calcul_cost_total(t_stack *a, t_stack *b, int b_pos)
{
	t_node	*current;
	int		i;
	int		target_pos;
	int		cost_a;
	int		cost_b;

	current = b->top;
	i = 0;
	while (i < b_pos)
	{
		current = current->next;
		i++;
	}
	target_pos = find_target_position(a, current->index);
	cost_a = calcul_cost_a(a, target_pos);
	cost_b = calcul_cost_b(b, b_pos);
	return (get_combined_cost(cost_a, cost_b));
}
