/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:07:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/19 16:39:54 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_node **a, int **nbrs)
{
	int len;
	int i;
	t_node *tmp;

	len = 0;
	i = 0;
	len = ft_int_array_len(nbrs);
	while(i < len)
	{
		tmp = create_node(nbrs[i][0]);
		append_node(a,tmp);
		i++;
	}
}

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
	//ft_print_int_array(nbrs);
	init_stack(&a, nbrs);
	//print_list(&a);
	push_swap(&a, &b);
	// free_all();
	return (0);
}
