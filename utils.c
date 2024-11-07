/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:13:41 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/06 18:22:21 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_putstr_fd(char *str, int fd)
{
    write(fd, str, strlen(str));
}
void    ft_error(char *str, t_libx *mlx)
{
    ft_putstr_fd(str, 2);
    close(mlx->fd);
    sleep(10);
    exit(1);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}