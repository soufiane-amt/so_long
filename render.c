/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:32:39 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:43:49 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_collect(t_data *data, int i, int j)
{
	static int	changer = 0;

	if (changer < 50)
	{
		mlx_put_image_to_window (data ->mlx, data -> mlx_win,
			data ->mlx_img.collect->blue, j * 75, i * 75);
		changer++;
	}
	else
	{
		mlx_put_image_to_window (data ->mlx, data -> mlx_win,
			data ->mlx_img.collect->yellow, j * 75, i * 75);
		changer++;
		if (changer >= 100)
			changer = 0;
	}
}

void	put_pieces(t_data *game, int i, int j)
{
	if (game -> map[i][j] == '1')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> mlx_img.wall, j * game -> img_size, i * game -> img_size);
	if (game -> map[i][j] == 'P')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> mlx_img.player, j * game -> img_size, i * game -> img_size);
	if (game -> map[i][j] == '0')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> mlx_img.space, j * game -> img_size, i * game -> img_size);
	if (game -> map[i][j] == 'C')
		put_collect(game, i, j);
	if (game -> map[i][j] == '3')
		mlx_put_image_to_window(game -> mlx, game -> mlx_win,
			game -> mlx_img.enemy, j * game -> img_size, i * game -> img_size);
	if (game -> map[i][j] == 'E')
	{
		if (game -> components.collectibles)
			mlx_put_image_to_window(game -> mlx, game -> mlx_win,
				game -> mlx_img.exit.closed,
				j * game -> img_size, i * game -> img_size);
		else
			mlx_put_image_to_window(game -> mlx, game -> mlx_win,
				game -> mlx_img.exit.opened, j * game -> img_size,
				i * game -> img_size);
	}
}

int	display(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(game -> mlx, game -> mlx_win);
	game -> components.collectibles = collect(game);
	while (i < game -> column_size)
	{
		j = 0;
		while (j < game -> row_size)
		{
			put_pieces(game, i, j);
			j++;
		}
		i++;
	}
	display_score(game);
	return (0);
}
