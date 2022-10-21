/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:29:37 by progerio          #+#    #+#             */
/*   Updated: 2022/10/21 03:03:33 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_except_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			execute_pb(stack_a, stack_b);
			pushed++;
		}
		else
			execute_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		execute_pb(stack_a, stack_b);
		pushed++;
	}
}

static void	change_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			execute_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			execute_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_except_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (*stack_b)
	{
		assign_target_position(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		change_stack(stack_a);
}
