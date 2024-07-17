/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:05 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/17 15:45:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**input_nbrs_to_valid_ints(char **input)
{
	int	len;
	int	**res;
	int	error;
	int	i;

	i = 0;
	error = 0;
	len = ft_char_array_len(input);
	res = malloc(sizeof(int *) * len);
	if (!res)
		exit_on_error();
	while (i < len)
	{
		res[i] = malloc(sizeof(int));
		if (!res[i])
			exit_on_error();
		res[i][0] = nbr_to_int(input[i], &error);
		if (error == 1)
			exit_on_error();
		i++;
	}
	res[i] = NULL;
	return (res);
}

int	check_overflow(long nb, char next_char, int neg)
{
	if (neg > 0)
	{
		if (nb > LONG_MAX / 10)
			return (1);
		if (nb == LONG_MAX / 10 && next_char - '0' > LONG_MAX % 10)
			return (1);
	}
	else
	{
		if (nb > -(long)(LONG_MIN / 10))
			return (1);
		if (nb == -(long)(LONG_MIN / 10) && next_char - '0' > -(LONG_MIN % 10))
			return (1);
	}
	return (0);
}

int	nbr_to_int(char *str, int *error)
{
	int		i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] && (ft_isspace(str[i])))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		if (check_overflow(nb, str[i], neg))
			*error = 1;
		nb = 10 * nb + str[i++] - '0';
	}
	nb *= neg;
	if (nb < INT_MIN || nb > INT_MAX)
		*error = 1;
	return ((int)nb);
}
