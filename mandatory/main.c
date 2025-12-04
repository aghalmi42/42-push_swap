/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 02:09:05 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 17:59:19 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_argument(ac, av);
	if (!a)
		return (0);
	b = create_stack();
	if (!b)
		is_error();
	if (is_sort(a))
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (a->size <= 5)
		sort_all_small_number(a, b);
	else
		turkish_algo(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
