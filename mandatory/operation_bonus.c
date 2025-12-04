/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:12:44 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 20:36:43 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa_bonus(t_stack *a)
{
	swap(a);
}

void	sb_bonus(t_stack *b)
{
	swap(b);
}

void	ss_bonus(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	pa_bonus(t_stack *b, t_stack *a)
{
	push(b, a);
}

void	pb_bonus(t_stack *a, t_stack *b)
{
	push(a, b);
}
