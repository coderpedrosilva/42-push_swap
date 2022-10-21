/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varied_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:01 by progerio          #+#    #+#             */
/*   Updated: 2022/10/21 03:04:16 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_reverse_rotate_both(t_stack **a, t_stack **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		execute_rrr(a, b);
	}
}

static void	execute_rotate_both(t_stack **a,
								t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		execute_rr(a, b);
	}
}

static void	execute_rotate_a(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			execute_ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			execute_rra(a);
			(*cost)++;
		}
	}
}

static void	execute_rotate_b(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			execute_rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			execute_rrb(b);
			(*cost)++;
		}
	}
}

void	execute_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		execute_reverse_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		execute_rotate_both(a, b, &cost_a, &cost_b);
	execute_rotate_a(a, &cost_a);
	execute_rotate_b(b, &cost_b);
	execute_pa(a, b);
}
