/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:08 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/29 13:35:00 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h" /* libft library */
# include <fcntl.h>              /* for open */
# include <limits.h>             /* for LONG_MAX, LONG_MIN */
# include <stdlib.h>             /* for malloc, free, exit */
# include <unistd.h>             /* for read, write */

typedef struct s_node
{
	int				nbr;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef enum e_move
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_move;

/* input */
char				**parse_input(int argc, char **argv);

/* utils */
void				remove_extra_spaces(char *str);
void				white_spaces_into_spaces(char *str);
void				err_exit(t_node **a, t_node **b, char **input, int *nbrs);
int					ft_abs(int n);

/* nbrs_are_valid */
int					*nbrs_are_valid(char **input, int len);

/* moves */
void				push(t_node **from, t_node **to);
void				swap(t_node **head);
void				rotate(t_node **head);
void				rev_rotate(t_node **head);

/* list utils*/
t_node				*create_node(int nbr);
void				append_node(t_node **head, t_node *node);
int					stack_len(t_node **head);
int					is_sorted(t_node **head);

/* push_swap */
void				push_swap(t_node **a, t_node **b);
void				sort_three(t_node **head);

/* stack_utils.c */
t_node				*find_highest(t_node **head);
t_node				*find_smallest(t_node **head);
int					distance_to_top(t_node **head, t_node *node);

/* costs */
t_node				*best_node_in_a(t_node **a, int nbr);
void				cheapest_moves(t_node **a, t_node **b, t_node *node,
						int *costs);

/* execute_moves */
void				execute_moves(t_node **a, t_node **b, t_move move, int n);
void				execute_cheapest_moves(t_node **a, t_node **b, int *costs);

/* free */
void				free_int_array(int **array);
void				free_all(t_node **a, t_node **b, char **input, int *nbrs);
void				free_stack(t_node **stack);
void				free_char_array(char ***array);

#endif /* PUSH_SWAP_H */