/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/25 15:48:24 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort_a(t_node **a)
{
	t_node	*tmp;
	t_node	*min;
	int		i;

	i = 0;
	tmp = *a;
	min = find_smallest(a);
	while (tmp->nbr != min->nbr)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = *a;
	if (i < stack_len(a) / 2)
	{
		while ((*a)->nbr != find_smallest(a)->nbr)
			execute_moves(a, NULL, RA, 1);
	}
	else
	{
		while ((*a)->nbr != find_smallest(a)->nbr)
			execute_moves(a, NULL, RRA, 1);
	}
}

void	turksort(t_node **a, t_node **b)
{
	int		len;
	int		*cheapest;
	t_node	*best_a;

	len = stack_len(a) - 2;
	cheapest = (int *)malloc(sizeof(int) * 2);
	if (!cheapest)
		exit_on_error();
	execute_moves(a, b, PB, 2);
	while (len-- > 3 && a != NULL)
	{
		cheapest = cheapest_moves(a, b, *a);
		execute_cheapest_moves(a, b, cheapest);
		execute_moves(a, b, PB, 1);
	}
	sort_three(a);
	while (*b != NULL)
	{
		best_a = best_node_in_a(a, (*b)->nbr);
		cheapest[0] = distance_to_top(a, best_a);
		cheapest[1] = 0;
		execute_cheapest_moves(a, b, cheapest);
		execute_moves(a, b, PA, 1);
	}
	final_sort_a(a);
}

void	sort_three(t_node **head)
{
	t_node	*tmp;
	t_node	*highest;

	tmp = *head;
	highest = find_highest(head);
	if (tmp->nbr == highest->nbr)
		execute_moves(head, NULL, RA, 1);
	else if (tmp->next->nbr == highest->nbr)
		execute_moves(head, NULL, RRA, 1);
	if ((*head)->nbr > (*head)->next->nbr)
		execute_moves(head, NULL, SA, 1);
}

void	push_swap(t_node **a, t_node **b)
{
	if (is_sorted(a) || stack_len(a) == 1)
		exit(1);
	if (stack_len(a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			execute_moves(a, NULL, SA, 1);
		exit(1);
	}
	if (stack_len(a) == 3)
	{
		sort_three(a);
		exit(1);
	}
	turksort(a, b);
}
