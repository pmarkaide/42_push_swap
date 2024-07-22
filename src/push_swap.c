/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/22 21:12:25 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves(t_node **a, t_node **b, int *costs)
{
	int	i;

	i = 0;
	if (costs[0] > 0)
	{
		while (i < costs[0])
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i > costs[0])
		{
			rra(a);
			i--;
		}
	}
	i = 0;
	if (costs[1] > 0)
	{
		while (i < costs[1])
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i > costs[1])
		{
			rrb(b);
			i--;
		}
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
		if (total > abs(costs[0]) + abs(costs[1]))
		{
			total = abs(costs[0]) + abs(costs[1]);
			cheapest[0] = costs[0];
			cheapest[1] = costs[1];
		}
		free(costs);
		node = node->next;
	}
	return (cheapest);
}

void final_sort_a(t_node **a)
{
	t_node	*tmp;
	t_node	*min;
	int i;

	i = 0;
	tmp = *a;
	min = find_smallest(a);
	while (tmp->nbr != min->nbr)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = *a;
	if(i < stack_len(a) / 2)
	{
		while((*a)->nbr != find_smallest(a)->nbr)
			ra(a);
	}
	else
	{
		while((*a)->nbr != find_smallest(a)->nbr)
			rra(a);
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
	pb(a, b);
	pb(a, b);
	while (len > 3 && a != NULL)
	{
		cheapest = cheapest_moves(a, b, *a);
		execute_moves(a, b, cheapest);
		pb(a, b);
		len--;
	}
	sort_three(a);
	while (*b != NULL)
	{
		best_a = best_node_in_a(a, (*b)->nbr);
		cheapest[0] = distance_to_top(a, best_a);
		cheapest[1] = 0;
		execute_moves(a, b, cheapest);
		pa(b, a);
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
		ra(head);
	else if (tmp->next->nbr == highest->nbr)
		rra(head);
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
