/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:51:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/25 15:42:48 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(t_move move)
{
		if (move == SA)
			ft_putstr_fd("sa\n", 1);
		else if (move == PA)
			ft_putstr_fd("pa\n", 1);
		else if (move == PB)
			ft_putstr_fd("pb\n", 1);
		else if (move == RA)
			ft_putstr_fd("ra\n", 1);
		else if (move == RB)
			ft_putstr_fd("rb\n", 1);
		else if (move == RR)
			ft_putstr_fd("rr\n", 1);
		else if (move == RRA)
			ft_putstr_fd("rra\n", 1);
		else if (move == RRB)
			ft_putstr_fd("rrb\n", 1);
		else if (move == RRR)
			ft_putstr_fd("rrr\n", 1);
}

void	execute_moves(t_node **a, t_node **b, t_move move, int n)
{
	while (n-- > 0)
	{
		if (move == SA)
			swap(a);
		else if (move == PA)
			push(b, a);
		else if (move == PB)
			push(a, b);
		else if (move == RA)
			rotate(a);
		else if (move == RB)
			rotate(b);
		else if (move == RRA)
			rev_rotate(a);
		else if (move == RRB)
			rev_rotate(b);
		print_moves(move);
	}
}

void	execute_rr(t_node **a, t_node **b, int *costs)
{
	int	common;
	int	extra;

	if (costs[0] < costs[1])
		common = costs[0];
	else
		common = costs[1];
	while(common-- > 0)
	{
		rotate(a);
		rotate(b);
		ft_putstr_fd("rr\n", 1);
	}
	extra = costs[0] - costs[1];
	if (extra > 0)
		execute_moves(a, NULL, RA, extra);
	extra = costs[1] - costs[0];
	if (extra > 0)
		execute_moves(b, NULL, RB, extra);
}

void	execute_rrr(t_node **a, t_node **b, int *costs)
{
	int	common;
	int	extra;

	costs[0] = -costs[0];
	costs[1] = -costs[1];
	if (costs[0] < costs[1])
		common = costs[0];
	else
		common = costs[1];
	while(common-- > 0)
	{
		rev_rotate(a);
		rev_rotate(b);
		ft_putstr_fd("rrr\n", 1);
	}
	extra = costs[0] - costs[1];
	if (extra > 0)
		execute_moves(a, NULL, RRA, extra);
	extra = costs[1] - costs[0];
	if (extra > 0)
		execute_moves(b, NULL, RRB, extra);
}

void	execute_cheapest_moves(t_node **a, t_node **b, int *costs)
{
	if ((costs[0] > 0 && costs[1] > 0))
		execute_rr(a, b, costs);
	else if ((costs[0] < 0 && costs[1] < 0))
		execute_rrr(a, b, costs);
	else if (costs[0] >= 0 && costs[1] <= 0)
	{
		execute_moves(a, NULL, RA, costs[0]);
		execute_moves(b, NULL, RRB, -costs[1]);
	}
	else if (costs[0] <= 0 && costs[1] >= 0)
	{
		execute_moves(a, NULL, RRA, -costs[0]);
		execute_moves(b, NULL, RB, costs[1]);
	}
}
