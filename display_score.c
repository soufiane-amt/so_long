/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_score.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:49:35 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:40:49 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_moves(t_data *data)
{
	char	*moves;

	moves = ft_itoa(data->player_moves);
	mlx_string_put(data->mlx, data->mlx_win,
		10, ((data->column_size) * 75) + 10, GREEN, "Moves:");
	mlx_string_put(data->mlx, data->mlx_win,
		150, ((data->column_size) * 75) + 10, RED, moves);
	free(moves);
}

static void	display_collect(t_data *data)
{
	char	*coll;

	coll = ft_itoa(collect(data));
	mlx_string_put(data->mlx, data->mlx_win,
		10, ((data->column_size) * 75) + 40, GREEN, "Collects:");
	mlx_string_put(data->mlx, data->mlx_win,
		150, ((data->column_size) * 75) + 40, RED, coll);
	free(coll);
}

void	display_score(t_data *data)
{
	display_moves(data);
	display_collect(data);
}
