/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: progerio <progerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:26 by progerio          #+#    #+#             */
/*   Updated: 2022/10/21 03:03:16 by progerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (check_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && check_if_is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !check_if_is_digit(av[i]))
		return (0);
	return (1);
}

static int	check_for_duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && digit_str_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_if_arg_is_zero(char *av)
{
	int	i;

	i = 0;
	if (check_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	check_if_is_correct_input(char **av)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 1;
	while (av[i])
	{
		if (!check_if_arg_is_number(av[i]))
			return (0);
		nbr += check_if_arg_is_zero(av[i]);
		i++;
	}
	if (nbr > 1)
		return (0);
	if (check_for_duplicates(av))
		return (0);
	return (1);
}
