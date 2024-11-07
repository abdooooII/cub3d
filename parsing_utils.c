/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 09:02:44 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/04 13:26:56 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *str)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (str[i] == '.' && str[++i] == 'c' && str[++i] == 'u' && str[++i] == 'b')
		return (1);
	else
	{
		ft_putstr_fd("ERROR: extension\n", 2);
		return(0);
	}
}