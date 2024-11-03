/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 07:57:05 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/03 08:02:57 by abouafso         ###   ########.fr       */
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


int		ft_strlen(char *str);
char	*ft_strrchr(char *str, int c);
void	*ft_calloc(size_t num_elements, size_t element_size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join_and_free(char *buffer, char *buf);
char	*read_file(int fd, char *result);
char	*copy_line(char *buffer);
char	*remove_first_line(char *buffer);
char	*get_next_line(int fd);


#endif
