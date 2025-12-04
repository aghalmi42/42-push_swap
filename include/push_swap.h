/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aghalmi <aghalmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:30:18 by aghalmi           #+#    #+#             */
/*   Updated: 2025/12/04 20:19:26 by aghalmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct t_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;

t_node				*create_node(int value);
t_stack				*create_stack(void);
void				free_stack(t_stack *stack);

void				swap(t_stack *stack);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				push(t_stack *src, t_stack *dest);
void				pa(t_stack *b, t_stack *a);
void				pb(t_stack *a, t_stack *b);

void				rotate(t_stack *stack);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				reverse_rotate(t_stack *stack);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

t_stack				*parsing_argument(int ac, char **av);

void				is_error(void);
int					is_number(char *str);
long				ft_atol(char *str);
int					check_atoi(char *str);
int					is_duplicate(t_stack *stack);

void				bottom_lifo(t_stack *stack, t_node *node);
int					is_sort(t_stack *stack);

void				sort_three(t_stack *a);
void				sort_all_small_number(t_stack *a, t_stack *b);

void				index_for_all_value(t_stack *stack);

void				push_chunk_to_b(t_stack *a, t_stack *b);

int					find_target_position(t_stack *a, int b_index);
int					calcul_cost_a(t_stack *a, int target_pos);
int					calcul_cost_b(t_stack *b, int b_pos);

void				exec_the_ratus_move(t_stack *a, t_stack *b, int best_pos);

void				push_back_a(t_stack *a, t_stack *b);

void				turkish_algo(t_stack *a, t_stack *b);

int					get_direction_a(t_stack *a, int target_pos);
int					get_direction_b(t_stack *b, int b_pos);
t_node				*get_node_at_pos(t_stack *b, int b_pos);
int					calcul_cost_total(t_stack *a, t_stack *b, int b_pos);

// BONUS //

void				sa_bonus(t_stack *a);
void				sb_bonus(t_stack *b);
void				ss_bonus(t_stack *a, t_stack *b);
void				pa_bonus(t_stack *b, t_stack *a);
void				pb_bonus(t_stack *a, t_stack *b);
void				ra_bonus(t_stack *a);
void				rb_bonus(t_stack *b);
void				rr_bonus(t_stack *a, t_stack *b);
void				rra_bonus(t_stack *a);
void				rrb_bonus(t_stack *b);
void				rrr_bonus(t_stack *a, t_stack *b);
int					ft_strcmp(char *s1, char *s2);
#endif