/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:30:14 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 17:04:39 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include "./minilibx-linux/mlx.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_character
{
	int		p_row;
	int		p_col;
	int		coins;
	int		total_coins;
	int		on_exit;
	char	pov;
}				t_character;

typedef struct s_param
{
	void		*session;
	void		*window;
	t_data		*img;
	t_character	pc;
	char		**map;
	int			map_rows;
	int			moves;
	int			clock;
}				t_param;

void	ft_set_position(void *params);
void	ft_set_character(void *params);
void	ft_set_coins(void *params);

int		ft_clean_board(void *params);
int		ft_clean_board2(void *params);
void	ft_clean_map(char **map, int map_rows);

int		ft_floodfill(void *params);
void	ft_floodfill_exe(t_param *dummy, int r, int c);
int		ft_floodcheck(t_param *dummy);

void	ft_set_img(void *params);
void	ft_set_img_2(t_param *dummy);

int		ft_get_map_rows(int fd);
char	**ft_get_map(int fd, int dim);
void	ft_draw_map(void *params);
void	ft_pick_objects(char point, void *params, int i, int j);
void	ft_pick_pov(t_param *dummy, int j, int i);

int		ft_move_manager(int key, void *params);
void	ft_move_up(t_param *dummy, void *params);
void	ft_move_down(t_param *dummy, void *params);
void	ft_move_left(t_param *dummy, void *params);
void	ft_move_right(t_param *dummy, void *params);

void	ft_check_map(void *params);
int		ft_check_objects(void *params);
int		ft_check_format(char *path);
int		ft_validate_objects(char c);
int		ft_check_map_form(void *params);

int		ft_strlen_2(char *s);
int		ft_putnbr(int n, int fd, int len);
void	ft_put_move(void *params, int toggle);
int		ft_inspect_map(void *params);

void	ft_setup(char *line, t_param *params);
int		ft_manager(int key, void *params);