/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:51:44 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/01 21:30:41 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	t_node	*node;

	if (!src || !src->top)
		return ;
	node = src->top;
	src->top = node->next;
	src->size--;
	if (src->top)
		src->top->prev = NULL;
	node->next = dest->top;
	if (dest->top)
		dest->top->prev = node;
	dest->top = node;
	if (dest->size == 0)
		dest->bottom = node;
	dest->size++;
	node->prev = NULL;
}

void	pa(t_stack *b, t_stack *a)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
