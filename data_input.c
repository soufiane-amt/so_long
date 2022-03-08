/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:23:06 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:28:35 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collect(t_data *data)
{
	int	i;
	int	j;
	int	c_total;

	i = 0;
	c_total = 0;
	while (i < data -> column_size)
	{
		j = 0;
		while (j < data -> row_size)
		{
			if (data -> map[i][j] == 'C')
				c_total++;
			j++;
		}
		i++;
	}
	return (c_total);
}

void	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data -> column_size)
	{
		j = 0;
		while (j < data -> row_size)
		{
			if (data -> map[i][j] == 'P')
			{
				data->player_pos.x = i;
				data->player_pos.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	get_dimentions(t_data *data)
{
	int		fd;
	char	*line;

	data->column_size = 0;
	data->row_size = 0;
	fd = open(data->map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	data->row_size = ft_strlen(line) - 1;
	data->column_size++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		data->column_size++;
	}
	free (line);
	if (data->row_size != data->column_size
		&& map_dimentions_are_valid(data -> map_path))
		return (1);
	return (0);
}

int	allocate_arr(t_data *data)
{
	int		i;

	i = -1;
	data->map = (char **) malloc (sizeof(char *) * data->column_size);
	if (!data -> map)
		return (0);
	while (++i < data->column_size)
	{
		data->map[i] = (char *) malloc (sizeof(char) * data->row_size);
		if (!data->map[i])
		{
			t_free(data->map, i);
			return (0);
		}
	}
	return (1);
}

int	fill_2d_array(t_data *data)
{
	int		i;
	char	*line;

	i = -1;
	if (!get_dimentions(data) || !allocate_arr(data))
		return (0);
	while (++i < data->column_size)
	{
		line = get_next_line(data->fd);
		ft_memmove(data->map[i], line, ft_strlen(line));
		free(line);
	}
	if (!map_wall_is_valid(data -> map, data -> column_size, data -> row_size)
		|| !check_map_compenents(data))
		return (0);
	return (1);
}
