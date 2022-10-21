/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:27:40 by progerio          #+#    #+#             */
/*   Updated: 2022/10/21 03:03:08 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* functions to check input */

int			check_if_is_correct_input(char **av);
int			check_if_is_digit(char c);
int			check_sign(char c);
int			digit_str_cmp(const char *s1, const char *s2);

/* stack development functions */

t_stack		*get_stack_bottom(t_stack *stack);
t_stack		*get_stack_before_bottom(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

/* stack initialization */

t_stack		*fill_stack_values(int ac, char **av);
void		assign_index(t_stack *stack_a, int ac);

/* sorting algorithms */

int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

/* position functions */

int			get_lowest_index_position(t_stack **stack);
void		assign_target_position(t_stack **stack_a, t_stack **stack_b);

/* functions considering costs */

void		calculate_cost(t_stack **stack_a, t_stack **stack_b);
void		execute_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* calculate move */

void		execute_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* operations */

void		execute_sa(t_stack **stack_a);
void		execute_sb(t_stack **stack_b);
void		execute_ss(t_stack **stack_a, t_stack **stack_b);
void		execute_pa(t_stack **stack_a, t_stack **stack_b);
void		execute_pb(t_stack **stack_a, t_stack **stack_b);
void		execute_ra(t_stack **stack_a);
void		execute_rb(t_stack **stack_b);
void		execute_rr(t_stack **stack_a, t_stack **stack_b);
void		execute_rra(t_stack **stack_a);
void		execute_rrb(t_stack **stack_b);
void		execute_rrr(t_stack **stack_a, t_stack **stack_b);

/* functions utils */

void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nbr_absolute(int nbr);

/* error function */

void		error(t_stack **stack_a, t_stack **stack_b);

#endif