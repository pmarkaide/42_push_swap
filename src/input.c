/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:43:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 11:51:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_string(char *str, char valid)
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

static int	arguments_format_is_correct(int argc, char **argv)
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

static int	clean_input(int argc, char **argv)
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

char	**parse_input(int argc, char **argv)
{
	char	**res;
	int		i;

	i = 0;
	if (arguments_format_is_correct(argc, argv) == -1)
		return (NULL);
	clean_input(argc, argv);
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
