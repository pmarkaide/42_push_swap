/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:14:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/25 12:15:01 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*best_node_in_a(t_node **a, int nbr)
{
	long	bigger;
	t_node	*tmp;
	t_node	*min;
	t_node	*closest_big;

	tmp = *a;
	bigger = LONG_MAX;
	min = find_smallest(a);
	closest_big = min;
	while (tmp != NULL)
	{
		if (tmp->nbr > nbr && (long)tmp->nbr - (long)nbr < bigger)
		{
			bigger = (long)tmp->nbr - (long)nbr;
			closest_big = tmp;
		}
		tmp = tmp->next;
	}
	return (closest_big);
}

t_node	*best_node_in_b(t_node **b, int nbr)
{
	long	smaller;
	t_node	*tmp;
	t_node	*max;
	t_node	*closest_small;

	tmp = *b;
	smaller = LONG_MAX;
	max = find_highest(b);
	closest_small = max;
	while (tmp != NULL)
	{
		if (tmp->nbr < nbr && (long)nbr - (long)tmp->nbr < smaller)
		{
			smaller = (long)nbr - (long)tmp->nbr;
			closest_small = tmp;
		}
		tmp = tmp->next;
	}
	return (closest_small);
}

int	*calculate_costs(t_node **a, t_node **b, t_node *node)
{
	int		*costs;
	t_node	*best_node;

	costs = (int *)malloc(sizeof(int) * 2);
	if (!costs)
		exit_on_error();
	best_node = best_node_in_b(b, node->nbr);
	costs[0] = distance_to_top(a, node);
	costs[1] = distance_to_top(b, best_node);
	return (costs);
}

int	optimized_total(int *costs)
{
	if ((costs[0] > 0 && costs[1] > 0) || (costs[0] < 0 && costs[1] < 0))
	{
		if (ft_abs(costs[0]) > ft_abs(costs[1]))
			return (ft_abs(costs[0]));
		else
			return (ft_abs(costs[1]));
	}
	else
		return (ft_abs(costs[0]) + ft_abs(costs[1]));
}

int	*cheapest_moves(t_node **a, t_node **b, t_node *node)
{
	int		*costs;
	int		*cheapest;
	long	total;

	cheapest = (int *)malloc(sizeof(int) * 2);
	if (!cheapest)
		exit_on_error();
	total = LONG_MAX;
	while (node != NULL)
	{
		costs = calculate_costs(a, b, node);
		if (total > optimized_total(costs))
		{
			total = optimized_total(costs);
			cheapest[0] = costs[0];
			cheapest[1] = costs[1];
		}
		free(costs);
		node = node->next;
	}
	return (cheapest);
}
