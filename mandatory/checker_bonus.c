/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 20:17:29 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 20:35:37 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	exec_instruction(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_bonus(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb_bonus(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_bonus(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa_bonus(b, a);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb_bonus(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_bonus(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb_bonus(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_bonus(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_bonus(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb_bonus(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_bonus(a, b);
	else
		is_error();
}

static void	checker(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_instruction(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

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
	checker(a, b);
	if (is_sort(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
