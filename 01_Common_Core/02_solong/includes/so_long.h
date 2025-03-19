/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpico-bu <mpico-bu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:39:13 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/02/24 15:45:00 by mpico-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
}	t_game;

int check_map(char *fd_name);

void	error_exit(char *message);
char **read_map(char *file);
int	parse_map(t_game *game, char *file);
void render_map(t_game *game);

#endif