/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:18:07 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:39:25 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_line(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i) != '\n' && *(str + i))
		i++;
	return (i);
}

void	t_free(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free (str_tab[j]);
		j++;
	}
	free(str_tab);
}

void	free_map(t_data *game)
{
	int	i;

	i = 0;
	while (i < game -> column_size)
		free (game -> map[i++]);
	free(game -> map);
	close(game -> fd);
}

static void	free_window(t_data *game)
{
	mlx_destroy_image (game -> mlx, game -> mlx_img.wall);
	mlx_destroy_image (game -> mlx, game -> mlx_img.player);
	mlx_destroy_image (game -> mlx, game -> mlx_img.collect->blue);
	mlx_destroy_image (game -> mlx, game -> mlx_img.collect->yellow);
	mlx_destroy_image (game -> mlx, game -> mlx_img.exit.closed);
	mlx_destroy_image (game -> mlx, game -> mlx_img.exit.opened);
	mlx_destroy_image (game -> mlx, game -> mlx_img.space);
	mlx_destroy_window (game -> mlx, game -> mlx_win);
}

int	end_game(t_data *game)
{
	free_map (game);
	free_window (game);
	exit (0);
	return (1);
}
