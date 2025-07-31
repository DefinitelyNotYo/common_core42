/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:09:05 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/31 16:59:41 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minilibx-linux_cub3d/mlx.h"
#include "minilibx-linux_cub3d/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#define WIDTH 500
#define HEIGHT 400
#define FOV_SCALE 0.577

typedef struct s_texture
{
    char    *direction;
    char    *texture_path;
}   t_texture;

typedef struct s_skyfloor
{
    char    id;
    char    *line;
    int		rgb_r;
    int		rgb_g;
    int		rgb_b;
}   t_skyfloor;

typedef struct s_input
{
    char		**map;
    int         map_len;
	char		**file;
	t_texture	t[4];
	t_skyfloor	sky;
	t_skyfloor	floor;
	int			file_rows;
}   t_input;

typedef struct s_pc
{
    float   posX;
    float   posY;
    int     mapX;
    int     mapY;
    float   dirX;
    float   dirY;
    float   planeX;
    float   planeY;
    float   cameraX;
    float   rayDirX;
    float   rayDirY;
    float   deltaDistX;
    float   deltaDistY;
    float   sideDistX;
    float   sideDistY;
    int     hit;
    int     stepX;
    int     stepY;
    float   lineHeight;
}   t_pc;


typedef struct s_win
{
    void    *mlx;
    void    *window;
    void    *img;
    int     *data_pixel;
    int     bpp;
    int     size_line;
    int     endian;
    t_pc    *pc;
    t_input *input;
}   t_win;

//CHECK_DIRECTION.C
void	check_north(t_input *in, int *elements, int *indxs, char *dir);
void	check_south(t_input *in, int *elements, int *indxs, char *dir);
void	check_west(t_input *in, int *elements, int *indxs, char *dir);
void	check_east(t_input *in, int *elements, int *indxs, char *dir);
//INPUT_FILE.C
int		ft_get_file_rows(int fd);
char	**ft_get_file(int fd, int dim);
void	ft_get_map(t_input *input, int *indxs);
//INSPECT.C
int     inspect_file(t_input *input);
int     inspect_line(t_input *input, int *elements, int *indxs);
int     inspect_map(t_input *input);
int     inspect_textures(t_input *input);
int     inspect_bgcolors(t_input *input);
//LINE.C
int     is_dir_line(t_input *input, int *elements, int *indxs, char *dir);
int     is_skyfloor_line(t_input *input, int *elements, int *indxs, char *dir);
//MESSAGES.C
void	message_error(int err);
void	print_matrix(t_input *input, int toggle);
//PARSING_MAP.C
int	    closed_dx(char *line);
int	    closed_sx(char *line);
int     closed_updown(t_input *input);
int     is_closed(t_input *in);
//PARSING_UTILS.C
void    remove_newlines(t_input *input);
int		find_char(char *str, char *chars, int flag);
char	*ft_strdup2(char *s, int len);
char	**ft_split2(char const *s, char c);
//PARSING.C
int		check_input(int argc, char **argv);
int     set_elements(int *elements, int toggle);
void	print_data(t_input *input);
int		parse_cub3d(int argc, char **argv, t_input *input);

//READ_MAP.C
void    ft_read_map(t_input *input, t_pc *pc);
//RAYS.C
void    ft_rays(t_pc *pc, t_input *input, t_win *win);
//DISPLAY.C
void    ft_display(t_pc *pc, t_win *win, int x);
int     ft_check_map(int map_rayX, int map_rayY, t_input *input, t_pc *pc);

