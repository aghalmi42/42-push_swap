/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:16:25 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 20:36:46 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra_bonus(t_stack *a)
{
	rotate(a);
}

void	rb_bonus(t_stack *b)
{
	rotate(b);
}

void	rr_bonus(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	rra_bonus(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb_bonus(t_stack *b)
{
	reverse_rotate(b);
}
