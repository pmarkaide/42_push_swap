/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs_are_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:44:05 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 11:37:19 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_overflow(long nb, char next_char, int neg)
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

static int	nbr_to_int(char *str, int *error)
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

int	*input_nbrs_to_valid_ints(char **input, int len)
{
	int	*res;
	int	error;
	int	i;

	i = 0;
	error = 0;
	res = malloc(sizeof(int) * (len));
	if (!res)
		return (NULL);
	while (input[i])
	{
		res[i] = nbr_to_int(input[i], &error);
		if (error == 1)
		{
			free_int_array(&res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

static int	no_duplicated_ints(int *nbrs, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nbrs[i] == nbrs[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*nbrs_are_valid(char **input, int len)
{
	int	*nbrs;
	int	error;

	nbrs = input_nbrs_to_valid_ints(input, len);
	error = no_duplicated_ints(nbrs, len);
	if (error == -1)
	{
		free(nbrs);
		nbrs = NULL;
	}
	return (nbrs);
}
