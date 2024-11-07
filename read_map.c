/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:53:14 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/05 15:28:33 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**read_map(int fd, char *av)
{
	int		i;
	char	**all_lines;

	i = count_lines(fd);
	close(fd);
	fd = open(av, O_RDONLY);
	all_lines = (char **)malloc(sizeof(char *) * i + 1);
	if (!all_lines)
		return (NULL);
	i = 0;
	while (1)
	{
		all_lines[i] = get_next_line(fd);
		if (!all_lines[i])
			break ;
		i++;
	}
	return (all_lines);
}

int	countliness(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		count++;
	}
	return (count);
}
int	countlines(t_libx *mlx)
{
	int	count;

	count = 0;
	while (mlx->map[count])
		count++;
	return (count);
}
char	**map_copie(t_libx *mlx)
{
	int		i;
	int		ii;
	char	**map_copie;

	ii = countlines(mlx);
	map_copie = (char **) malloc (sizeof(char *) * ii + 1);
	if (!map_copie)
		return (NULL);
	i = 0;
	while (i < ii)
	{
		map_copie[i] = ft_strdup(mlx->map[i]);
		if (!map_copie[i])
			ft_putstr_fd("Error\nfor strdup to copie map\n",2);
		i++;
	}
	map_copie[i] = NULL;
	return (map_copie);
}