/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 07:57:05 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/08 00:52:19 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#  define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>


typedef struct s_libx
{
	char	**map;
	char	**updated_map;
	char	***infos;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	float	floor;
	float	ceiling;
	int		fd;

}			t_libx;

// get next line
int		ft_strlen(char *str);
char	*ft_strrchr(char *str, int c);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_and_free(char *buffer, char *buf);
char	*read_file(int fd, char *result);
char	*copy_line(char *buffer);
char	*remove_first_line(char *buffer);
char	*get_next_line(int fd);

//  utils
void	ft_putstr_fd(char *str, int fd);
char	*ft_strdup(char *s1);
void    ft_error(char *str, t_libx *mlx);
char	**ft_split(const char *s, char c);
int	ft_strcmp(char *s1, char *s2);

// parsing
int		check_file(char *str);
char	**read_map(int fd, char *av);
int     count_lines(int fd);
int		countliness(char **map);
char	**map_copie(t_libx *mlx);

#endif
