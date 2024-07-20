/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/20 11:15:21 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node **head)
{
    t_node *tmp;
    t_node *highest;

    tmp = *head;
    highest = find_highest(head);
    if(tmp->nbr == highest->nbr)
        ra(head);
    else if(tmp->next->nbr == highest->nbr)
        rra(head);
    if((*head)->nbr > (*head)->next->nbr)
        sa(head);
}

void push_swap(t_node **a)
{
    if(is_sorted(a) || stack_len(a) == 1)
        exit(1);
    if(stack_len(a) == 2)
    {
        if((*a)->nbr > (*a)->next->nbr)
            sa(a);
        print_list(a);
        exit(1);
    }
    if(stack_len(a) == 3)
    {
        sort_three(a);
        print_list(a);
        exit(1);
    }
    
    ft_printf("so much to sort...\n");
}