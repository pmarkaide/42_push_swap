/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:58:28 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 16:42:47 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static t_move	operation_to_move(char *operation)
{
	if (ft_strcmp(operation, "sa\n") == 0)
		return (SA);
	else if (ft_strcmp(operation, "sb\n") == 0)
		return (SB);
	else if (ft_strcmp(operation, "ss\n") == 0)
		return (SS);
	else if (ft_strcmp(operation, "pa\n") == 0)
		return (PA);
	else if (ft_strcmp(operation, "pb\n") == 0)
		return (PB);
	else if (ft_strcmp(operation, "ra\n") == 0)
		return (RA);
	else if (ft_strcmp(operation, "rb\n") == 0)
		return (RB);
	else if (ft_strcmp(operation, "rr\n") == 0)
		return (RR);
	else if (ft_strcmp(operation, "rra\n") == 0)
		return (RRA);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		return (RRB);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		return (RRR);
	else
		return (ERR);
}

int	checker(t_node **a, t_node **b)
{
	char	*operation;
	t_move	move;

	operation = get_next_line(STDIN_FILENO);
	while (operation)
	{
		move = operation_to_move(operation);
		if (move == ERR)
		{
			free(operation);
			return (-1);
		}
		execute_moves(a, b, move, 1);
		free(operation);
		operation = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
