/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:06:28 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/03 23:46:03 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_chepeast_position(t_stack *a, t_stack *b)
{
	int	i;
	int	cheapest_pos;
	int	min_cost;
	int	current_cost;

	i = 0;
	min_cost = 2147483647;
	cheapest_pos = 0;
	while (i < b->size)
	{
		current_cost = calcul_cost_total(a, b, i);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest_pos = i;
		}
		i++;
	}
	return (cheapest_pos);
}

void	push_back_a(t_stack *a, t_stack *b)
{
	int	best_pos;

	while (b->size > 0)
	{
		best_pos = find_chepeast_position(a, b);
		exec_the_ratus_move(a, b, best_pos);
	}
}
