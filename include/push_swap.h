/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:08:08 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/10 16:29:17 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h" /* libft library */
# include <fcntl.h>              /* for open */
# include <stdlib.h>             /* for malloc, free, exit */
# include <unistd.h>             /* for read, write */


void remove_extra_spaces(char *str);
void white_spaces_into_spaces(char *str);
void is_valid_char(char *str);
void	clean_input(int argc, char **argv);
char	**parse_input(int argc, char **argv);
void	error(void);


#endif /* PUSH_SWAP_H */