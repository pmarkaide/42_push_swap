/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:26:55 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/22 18:02:04 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_extra_spaces(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]) || (i > 0 && !ft_isspace(str[i - 1])))
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void	white_spaces_into_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			str[i] = ' ';
		i++;
	}
}

void	exit_on_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
