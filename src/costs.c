/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:14:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/26 15:00:44 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the node in A stack that is closest to the given number.
 *
 * @param a Pointer to the head of stack A.
 * @param nbr The number to compare against.
 * @return t_node* Pointer to the best node in stack A.
 * 		   The node B must be pushed below this node
 */
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

/**
 * @brief Finds the node in B stack that is closest to the given number.
 *
 * @param a Pointer to the head of stack B.
 * @param nbr The number to compare against.
 * @return  t_node* Pointer to the best node in stack A.
 * 			The node A must be pushed above this node.
 */
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

/**
 * @brief Calculates rotation costs for a given node.
 * 		  The cost of A : rotate the node to the top.
 * 		  The cost of B : rotate best node in B to the top.
 *
 * @param a Pointer to the head of stack A.
 * @param b Pointer to the head of stack B.
 * @param node The node to calculate costs for.
 * @return int* Array containing the costs for rotating stacks A and B.
 * 		   Positive cost for rotations, negative for reverse rotating.
 */
void	calculate_costs(t_node **a, t_node **b, t_node *node, int *costs)
{
	t_node	*best_node;

	best_node = best_node_in_b(b, node->nbr);
	costs[0] = distance_to_top(a, node);
	costs[1] = distance_to_top(b, best_node);
}

/**
 * @brief Calculate the optimized total cost for a given node.
 * 		  If both costs have same sign, means we can use rr or rrr.
 * 		  Else, we can not save moves.
 *
 * @param costs Array containing the costs for stacks A and B.
 * @return int The optimized total cost.
 */
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

/**
 * @brief Scans stack A and calculates the cheapest node to move to B.
 * 		  The cheapest node is the one that ending in the correct position
 * 		  in B, require the lowest ammount of moves.
 *
 * @param a Pointer to the head of stack A.
 * @param b Pointer to the head of stack B.
 * @param node The node to calculate the moves for.
 * @return int* Array containing the cheapest moves for stacks A and B.
 */
 void cheapest_moves(t_node **a, t_node **b, t_node *node, int *cheapest)
{
	int		costs[2];
	long	total;

	total = LONG_MAX;
	while (node != NULL)
	{
		calculate_costs(a, b, node, costs);
		if (total > optimized_total(costs))
		{
			total = optimized_total(costs);
			cheapest[0] = costs[0];
			cheapest[1] = costs[1];
		}
		node = node->next;
	}
}
