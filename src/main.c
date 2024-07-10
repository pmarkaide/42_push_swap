/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:07:06 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/10 16:28:20 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	char	**res;
	if (argc < 2)
		error();
	res = parse_input(argc, argv);
	ft_print_array(res);
	// is_valid_input(argc, argv);
	// push_swap(argc, argv);
	// free_all();
	return (0);
}
