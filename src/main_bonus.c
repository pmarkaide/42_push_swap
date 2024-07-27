/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:00:45 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 14:26:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	init_stack(t_node **a, int *nbrs, int len)
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
			return ;
		}
		append_node(a, tmp);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**input;
	int		*nbrs;
	int		len;
	t_node	*a;
	t_node	*b;

	input = NULL;
	nbrs = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	input = parse_input(argc, argv);
	if (input == NULL)
		err_exit(&a, &b, input, nbrs);
	len = ft_char_array_len(input);
	nbrs = nbrs_are_valid(input, len);
	if (nbrs == NULL)
		err_exit(&a, &b, input, nbrs);
	init_stack(&a, nbrs, len);
	if (a == NULL)
		err_exit(&a, &b, input, nbrs);
	checker(&a, &b);
	free_all(&a, &b, input, nbrs);
	return (0);
}