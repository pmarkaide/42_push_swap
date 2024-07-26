/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:07:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/26 15:58:24 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_node **a, int *nbrs, int len)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < len)
	{
		tmp = create_node(nbrs[i]);
		if(tmp == NULL)
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
	int len;
	t_node	*a;
	t_node	*b;

	input = NULL;
	nbrs = NULL;
	a = NULL;
	b = NULL;
	if (argc < 2)
		exit_on_error(&a, &b, input, nbrs);
	input = parse_input(argc, argv);
	if(input == NULL)
		exit_on_error(&a, &b, input, nbrs);
	len = ft_char_array_len(input);
	nbrs = nbrs_are_valid(input, len);
	if(nbrs == NULL)
		exit_on_error(&a, &b, input, nbrs);
	init_stack(&a, nbrs, len);
	if(a == NULL)
		exit_on_error(&a, &b, input, nbrs);
	push_swap(&a, &b);
	free_all(&a, &b, input, nbrs);
	return (0);
}
