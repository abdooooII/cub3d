/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 08:10:53 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/08 02:31:35 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

int	check_walls(char **map, t_libx mlx)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(map[i]) - 2;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
			ft_error("ERROR: invalid map sides!\n", &mlx);
		i++;
	}
	i = countliness(map) - 1;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != '\n')
			ft_putstr_fd("ERROR; walls\n", 2);
		j++;
	}
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			ft_putstr_fd("ERROR; walls", 2);
		j++;
	}
	return (0);
}

void	space_to_1(char **map)
{
	int i;
	int j;
		
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == ' ' || map[i][j] == '\t')
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	parse_new_map(t_libx *mlx)
{
	int		i;

    i = 0;
	mlx->updated_map = map_copie(mlx);
	if (!mlx->updated_map)
		return (1);
    space_to_1(mlx->updated_map);
    check_walls(mlx->updated_map, *mlx);
    int j = 0;
    printf("new map \n");
    while(mlx->map[i])
    {
        printf("new line %d --> %s", j, mlx->updated_map[i]);
        i++;
    }
    printf("\n");
	return (0);
}

void	split_map(t_libx *mlx)
{
	int i;

	i = 0;
	mlx->infos = malloc(sizeof(char ***) * countliness(mlx->map) + 1);
	while(mlx->map[i] && mlx->map[i][0] != '1' && mlx->map[i][0] != ' '&& mlx->map[i][0] != '\n')
	{
		mlx->infos[i] = ft_split(mlx->map[i], ' ');
		if(!mlx->infos)
			return;
		i++;
	}
	mlx->infos[i] = NULL;
}
void	init_infos(t_libx *mlx)
{
	int i = 0;
	while(mlx->infos[i])
	{
		printf("----> %s -----> %s\n", mlx->infos[i][0], mlx->infos[i][1]);
		i++;
	}
}

void	map_info(t_libx *mlx)
{
	split_map(mlx);
	puts("hello");
	init_infos(mlx);
}

int	parsing(char **av, t_libx *mlx)
{
    
    mlx->fd = open(av[1], O_RDONLY);
    if (mlx->fd == -1)
		ft_putstr_fd("file descriptor fail\n", 2);
	check_file(av[1]);
	mlx->map = read_map(mlx->fd, av[1]);
	// int i = 0;
	// while(mlx->map[i])
	// {
	// 	printf("line %d --> %s", i, mlx->map[i]);
	// 	i++;
	// }
	map_info(mlx);
	printf("\n");
	parse_new_map(mlx);
	return(0);
}


int main(int ac, char **av)
{
	t_libx	mlx;

	if(ac != 2)
		return(ft_putstr_fd("INVALID NUMBER OF ARGUMENTS\n", 2),1);
	if(!parsing(av, &mlx))
		return(1);
	return(0);
}