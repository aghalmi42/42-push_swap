/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_algo_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:47:53 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/03 22:53:44 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*get_node_position(t_stack *stack, int position)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = 0;
	while (i < position)
	{
		current = current->next;
		i++;
	}
	return (current);
}

static void	exec_rotations(t_stack *a, t_stack *b, int *cost)
{
	while (cost[0] > 0 && cost[1] > 0)
	{
		rr(a, b);
		cost[0]--;
		cost[1]--;
	}
	while (cost[0] < 0 && cost[1] < 0)
	{
		rrr(a, b);
		cost[0]++;
		cost[1]++;
	}
	while (cost[0] > 0 && cost[0]--)
		ra(a);
	while (cost[0] < 0 && cost[0]++)
		rra(a);
	while (cost[1] > 0 && cost[1]--)
		rb(b);
	while (cost[1] < 0 && cost[1]++)
		rrb(b);
}

void	exec_the_ratus_move(t_stack *a, t_stack *b, int best_pos)
{
	t_node	*node;
	int		target_pos;
	int		cost[2];

	node = get_node_position(b, best_pos);
	target_pos = find_target_position(a, node->index);
	cost[0] = calcul_cost_a(a, target_pos);
	cost[1] = calcul_cost_b(b, best_pos);
	exec_rotations(a, b, cost);
	pa(b, a);
}
