/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_movements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:05:47 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:38:23 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moving_allowed(t_data *data, int distination_x, int distination_y)
{
	if (data -> map[distination_x][distination_y] == '1' ||
	(collect(data) && data -> map[distination_x][distination_y] == 'E'))
		return (0);
	else if (data -> map[distination_x][distination_y] == 'E' ||
	data -> map[distination_x][distination_y] == '3')
		end_game(data);
	return (1);
}

int	move_right(t_data *data)
{
	player_pos(data);
	if (moving_allowed(data, data->player_pos.x, data->player_pos.y + 1))
	{
		data -> map[data -> player_pos.x][data -> player_pos.y] = '0';
		data -> player_pos.y += 1;
		data -> map[data -> player_pos.x][data -> player_pos.y] = 'P';
		data ->player_moves++;
	}
	return (0);
}

int	move_left(t_data *data)
{
	player_pos(data);
	if (moving_allowed(data, data -> player_pos.x, data -> player_pos.y - 1))
	{
		data -> map[data -> player_pos.x][data -> player_pos.y] = '0';
		data -> player_pos.y -= 1;
		data -> map[data -> player_pos.x][data -> player_pos.y] = 'P';
		data ->player_moves++;
	}
	return (0);
}

int	move_up(t_data *data)
{
	player_pos(data);
	if (moving_allowed(data, data -> player_pos.x - 1, data -> player_pos.y))
	{
		data -> map[data -> player_pos.x][data -> player_pos.y] = '0';
		data -> player_pos.x -= 1;
		data -> map[data -> player_pos.x][data -> player_pos.y] = 'P';
		data ->player_moves++;
	}
	return (0);
}

int	move_down(t_data *data)
{
	player_pos(data);
	if (moving_allowed(data, data -> player_pos.x + 1, data -> player_pos.y))
	{
		data -> map[data -> player_pos.x][data -> player_pos.y] = '0';
		data -> player_pos.x += 1;
		data -> map[data -> player_pos.x][data -> player_pos.y] = 'P';
		data ->player_moves++;
	}
	return (0);
}
