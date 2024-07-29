/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:00:45 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 22:42:53 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

static t_node	**init_stack(t_node **a, int *nbrs, int len)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = create_node(nbrs[i]);
		if (tmp == NULL)
		{
			free_stack(a);
			*a = NULL;
			return (NULL);
		}
		append_node(a, tmp);
		i++;
	}
	return (a);
}

static t_node	*prepare_input(int argc, char **argv, t_node **a, t_node **b)
{
	int		len;
	char	**input;
	int		*nbrs;

	input = NULL;
	nbrs = NULL;
	input = parse_input(argc, argv);
	if (!input)
		err_exit(a, b, input, nbrs);
	len = ft_char_array_len(input);
	nbrs = nbrs_are_valid(input, len);
	if (!nbrs)
		err_exit(a, b, input, nbrs);
	a = init_stack(a, nbrs, len);
	if (!a)
		err_exit(a, b, input, nbrs);
	free_char_array(&input);
	free_int_array(&nbrs);
	if (is_sorted(a) || stack_len(a) == 1)
	{
		free_all(a, b, input, nbrs);
		exit(0);
	}
	return (*a);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		error;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	a = prepare_input(argc, argv, &a, &b);
	error = checker(&a, &b);
	if (error == -1)
		err_exit(&a, &b, NULL, NULL);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
