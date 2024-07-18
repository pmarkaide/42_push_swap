/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:07:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/18 15:48:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	exit_on_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	char	**input;
	int		**nbrs;
	t_node *a;
	t_node *b;

	a = NULL;
	b = NULL;

	if (argc < 2)
		exit_on_error();
	input = parse_input(argc, argv);
	// ft_print_char_array(input);
	nbrs = is_valid_input(input);
	// ft_print_int_array(nbrs);
	// push_swap(argc, argv);
	// free_all();
	return (0);
}
