/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:43:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/26 15:38:07 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	no_duplicated_ints(int *nbrs, int len)
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

int	is_valid_string(char *str, char valid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
			i++;
		else if (valid != '\0' && str[i] == valid)
			i++;
		else
			return (-1);
	}
	return (0);
}

int	clean_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		remove_extra_spaces(argv[i]);
		white_spaces_into_spaces(argv[i]);
		i++;
	}
	return (0);
}

int	arguments_format_is_correct(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_str_empty(argv[i]) == 1)
			return (-1);
		if (argc == 2)
		{
			if (is_valid_string(argv[1], ' ') != 0)
				return (-1);
		}
		else
		{
			if (is_valid_string(argv[i], '\0') != 0)
				return (-1);
		}
		i++;
	}
	return (0);
}

char	**parse_input(int argc, char **argv)
{
	char	**res;
	int		i;

	i = 0;
	if (arguments_format_is_correct(argc, argv) == -1)
		return (NULL);
	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
	{
		res = malloc(sizeof(char *) * argc);
		if (!res)
			return (NULL);
		while (i < argc - 1)
		{
			res[i] = ft_strdup(argv[i + 1]);
			if (res[i] == NULL)
				return (NULL);
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}
