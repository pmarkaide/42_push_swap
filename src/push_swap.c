/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/23 21:55:14 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rr(t_node **a, t_node **b, int *costs)
{
	int	common;
	int	extra;

	if (costs[0] < costs[1])
		common = costs[0];
	else
		common = costs[1];
	rr(a, b, common);
	extra = costs[0] - costs[1];
	if (extra > 0)
		ra(a, extra);
	extra = costs[1] - costs[0];
	if (extra > 0)
		rb(b, extra);
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
	rrr(a, b, common);
	extra = costs[0] - costs[1];
	if (extra > 0)
		rra(a, extra);
	extra = costs[1] - costs[0];
	if (extra > 0)
		rrb(b, extra);
}

void	execute_moves(t_node **a, t_node **b, int *costs)
{
	if ((costs[0] > 0 && costs[1] > 0))
		execute_rr(a, b, costs);
	else if ((costs[0] < 0 && costs[1] < 0))
		execute_rrr(a, b, costs);
	else if (costs[0] >= 0 && costs[1] <= 0)
	{
		ra(a, costs[0]);
		rrb(b, -costs[1]);
	}
	else if (costs[0] <= 0 && costs[1] >= 0)
	{
		rra(a, -costs[0]);
		rb(b, costs[1]);
	}
}

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
		if (ft_abs(costs[0]) > ft_abs(costs[1]))
			return (ft_abs(costs[0]));
		else
			return (ft_abs(costs[1]));
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
			ra(a, 1);
	}
	else
	{
		while ((*a)->nbr != find_smallest(a)->nbr)
			rra(a, 1);
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
	pb(a, b, 2);
	while (len > 3 && a != NULL)
	{
		cheapest = cheapest_moves(a, b, *a);
		execute_moves(a, b, cheapest);
		pb(a, b, 1);
		len--;
	}
	sort_three(a);
	while (*b != NULL)
	{
		best_a = best_node_in_a(a, (*b)->nbr);
		cheapest[0] = distance_to_top(a, best_a);
		cheapest[1] = 0;
		execute_moves(a, b, cheapest);
		pa(b, a, 1);
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
		ra(head, 1);
	else if (tmp->next->nbr == highest->nbr)
		rra(head, 1);
	if ((*head)->nbr > (*head)->next->nbr)
		sa(head);
}

void	push_swap(t_node **a, t_node **b)
{
	if (is_sorted(a) || stack_len(a) == 1)
		exit(1);
	if (stack_len(a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		exit(1);
	}
	if (stack_len(a) == 3)
	{
		sort_three(a);
		exit(1);
	}
	turksort(a, b);
}
