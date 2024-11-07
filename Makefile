# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 08:08:20 by abouafso          #+#    #+#              #
#    Updated: 2024/11/06 18:17:47 by abouafso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

CC = CC

# CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = get_next_line_utils.c get_next_line.c cub3d.c utils.c parsing_utils.c read_map.c

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

obj/%.o : %.c cub3d.h
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean all
