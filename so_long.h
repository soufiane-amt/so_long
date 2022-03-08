/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:16:51 by samajat           #+#    #+#             */
/*   Updated: 2022/02/23 20:39:10 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Headers
# include	"get_next_line/get_next_line.h"
# include	<fcntl.h>
# include	<mlx.h>
# include	<stdio.h>
# include	<stdlib.h>
# include	<unistd.h>

# define RED 0x00FF0000
# define GREEN 0x0000FF00

//Structor
typedef struct s_color
{
	void	*blue;
	void	*yellow;
}		t_color;

typedef struct s_components
{
	int	collectibles;
	int	players;
	int	exits;
}		t_components;

typedef struct s_couple
{
	int	x;
	int	y;
}	t_couple;

typedef struct s_exit
{
	void	*closed;
	void	*opened;
}			t_exit;

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*space;
	void	*enemy;
	t_color	*collect;
	t_exit	exit;
}			t_img;

typedef struct s_data
{
	void			*mlx;
	void			*mlx_win;
	t_img			mlx_img;
	t_couple		coordinate_img;
	t_couple		size_img;
	t_couple		size_win;
	t_couple		player_pos;
	char			**map;
	char			*map_path;
	int				column_size;
	int				row_size;
	int				fd;
	int				img_size;
	int				player_moves;
	t_components	components;
}				t_data;

//functions
int		main(int argc, char **argv);
int		map_dimentions_are_valid(char *path);
int		get_dimentions(t_data *data);
int		fill_2d_array(t_data *data);
int		check_map_compenents(t_data *data);
void	so_long(char *path);
int		move_right(t_data *data);
int		end_game(t_data *game);
void	free_map(t_data *game);
int		move_right(t_data *data);
int		move_left(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		key_hook(int key_code, t_data *game);
int		collect(t_data *data);
void	player_pos(t_data	*data);
void	t_free(char **str_tab, int i);
int		change_ring_color(t_data *data);
int		display(t_data *game);
void	put_pieces(t_data *game, int i, int j);
char	*ft_itoa(int n);
void	display_score(t_data *data);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);

#endif
