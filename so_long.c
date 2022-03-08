/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:51:09 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:38:44 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key_code, t_data *game)
{
	char	*moves;

	moves = ft_itoa(game->player_moves);
	ft_putstr_fd("number of movements : ", 1);
	ft_putstr_fd(moves, 1);
	ft_putstr_fd ("\n", 1);
	if (key_code == 2)
		move_right(game);
	if (key_code == 0)
		move_left(game);
	if (key_code == 13)
		move_up(game);
	if (key_code == 1)
		move_down(game);
	if (key_code == 53)
		end_game(game);
	free (moves);
	return (0);
}

static void	fill(t_data *game)
{
	int	info[2];

	game -> img_size = 75;
	game -> components.collectibles = 0;
	game -> player_moves = 0;
	game -> mlx = mlx_init();
	game -> mlx_win = mlx_new_window(game -> mlx,
			game -> row_size * game -> img_size,
			(game->column_size + 1) * game->img_size, "Bounce");
	game->mlx_img.wall = mlx_xpm_file_to_image(game->mlx,
			"./images/Wall.xpm", &info[0], &info[1]);
	game->mlx_img.player = mlx_xpm_file_to_image(game->mlx,
			"./images/Ball.xpm", &info[0], &info[1]);
	game->mlx_img.space = mlx_xpm_file_to_image(game->mlx,
			"./images/space.xpm", &info[0], &info[1]);
	game->mlx_img.enemy = mlx_xpm_file_to_image(game->mlx,
			"./images/enemy.xpm", &info[0], &info[1]);
	game->mlx_img.collect->yellow = mlx_xpm_file_to_image(game->mlx,
			"./images/ring.xpm", &info[0], &info[1]);
	game->mlx_img.collect->blue = mlx_xpm_file_to_image(game->mlx,
			"./images/bring.xpm", &info[0], &info[1]);
	game->mlx_img.exit.closed = mlx_xpm_file_to_image(game->mlx,
			"./images/exitClosed.xpm", &info[0], &info[1]);
	game->mlx_img.exit.opened = mlx_xpm_file_to_image(game->mlx,
			"./images/exitOpened.xpm", &info[0], &info[1]);
}

void	so_long(char *path)
{
	t_data	data;

	data.map_path = path;
	data.fd = open(data.map_path, O_RDONLY);
	if (data.fd == -1 || !map_dimentions_are_valid (data.map_path))
	{
		write(1, "Error\n", 6);
		return ;
	}
	if (!fill_2d_array(&data))
	{
		write(1, "Error\n", 6);
		return ;
	}
	fill(&data);
	mlx_loop_hook (data.mlx, display, &data);
	mlx_hook (data.mlx_win, 2, (0L), key_hook, &data);
	mlx_hook (data.mlx_win, 17, (0L), end_game, &data);
	mlx_loop(data.mlx);
}
