/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:07:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/22 18:03:09 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_node **a, int **nbrs)
{
	int		len;
	int		i;
	t_node	*tmp;

	len = 0;
	i = 0;
	len = ft_int_array_len(nbrs);
	while (i < len)
	{
		tmp = create_node(nbrs[i][0]);
		append_node(a, tmp);
		i++;
	}
}

// TODO: free all mallocs
int	main(int argc, char **argv)
{
	char	**input;
	int		**nbrs;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit_on_error();
	input = parse_input(argc, argv);
	nbrs = is_valid_input(input);
	init_stack(&a, nbrs);
	push_swap(&a, &b);
	return (0);
}
