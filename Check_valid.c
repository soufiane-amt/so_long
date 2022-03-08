/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:13:52 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 14:47:13 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_compenents(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data -> column_size)
	{
		j = -1;
		while (++j < data->row_size)
		{
			if (data->map[i][j] == 'C')
				data -> components.collectibles++;
			else if (data->map[i][j] == 'E')
				data -> components.exits++;
			else if (data->map[i][j] == 'P')
				data -> components.players++;
			if (data ->map[i][j] != 'C' && data ->map[i][j] != 'P'
				&& data ->map[i][j] != 'E' && data ->map[i][j] != '0'
				&& data ->map[i][j] != '1' && data ->map[i][j] != '3')
				return (0);
		}
	}
	if (data -> components.collectibles >= 1
		&& data -> components.exits == 1 && data -> components.players == 1)
		return (1);
	return (0);
}

int	map_wall_is_valid(char **map, int c, int r)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (map[i][0] != '1' || map[i][r - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < r)
	{
		if (map[0][i] != '1' || map[c - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_dimentions_are_valid(char *path)
{
	int		fd;
	int		r;
	int		c;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line (fd);
	r = ft_strlen_line(line);
	c++;
	while (line)
	{
		free (line);
		line = get_next_line (fd);
		c++;
	}
	c--;
	free (line);
	if (c == r)
		return (0);
	return (1);
}
