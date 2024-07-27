/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:00:12 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/27 14:26:59 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		else if (move == RA || move == RR)
			rotate(a);
		else if (move == RB || move == RR)
			rotate(b);
		else if (move == RRA || move == RRR)
			rev_rotate(a);
		else if (move == RRB || move == RRR)
			rev_rotate(b);
	}
}
