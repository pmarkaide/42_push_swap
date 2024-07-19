/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:43:50 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/18 09:46:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	no_duplicated_ints(int **nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i][0] == nbrs[j][0])
				exit_on_error();
			j++;
		}
		i++;
	}
}

int	**is_valid_input(char **input)
{
	int	**res;

	res = input_nbrs_to_valid_ints(input);
	no_duplicated_ints(res);
	return (res);
}

void	is_valid_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '-' || str[i] == '+')
			i++;
		else if (ft_isspace(str[i]))
			i++;
		else
			exit_on_error();
	}
}

void	clean_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		is_valid_char(argv[i]);
		remove_extra_spaces(argv[i]);
		white_spaces_into_spaces(argv[i]);
		i++;
	}
}

char	**parse_input(int argc, char **argv)
{
	char	**res;
	int		i;

	i = 0;
	clean_input(argc, argv);
	if (argc == 2)
		res = ft_split(argv[1], ' ');
	else
	{
		res = malloc(sizeof(char *) * argc);
		if (!res)
			exit_on_error();
		while (i < argc - 1)
		{
			res[i] = ft_strdup(argv[i + 1]);
			if (res[i] == NULL)
				exit_on_error();
			i++;
		}
		res[i] = NULL;
	}
	return (res);
}
