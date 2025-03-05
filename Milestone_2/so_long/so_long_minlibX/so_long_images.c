/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:58:18 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 17:13:10 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_img(void *params)
{
	t_param	*dummy;
	int		dim;

	dummy = (t_param *)params;
	dim = 21;
	dummy->img[0].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/BG.xpm", &dim, &dim);
	dummy->img[1].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/Tree.xpm", &dim, &dim);
	dummy->img[2].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/Apple.xpm", &dim, &dim);
	dummy->img[3].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/Stairs.xpm", &dim, &dim);
	dummy->img[4].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/P_front.xpm", &dim, &dim);
	ft_set_img_2(params);
}

void	ft_set_img_2(t_param *dummy)
{
	int		dim;

	dim = 21;
	dummy->img[5].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/P_back.xpm", &dim, &dim);
	dummy->img[6].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/P_right.xpm", &dim, &dim);
	dummy->img[7].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/P_left.xpm", &dim, &dim);
	dummy->img[8].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/Stairs_P_front.xpm", &dim, &dim);
	dummy->img[9].img = mlx_xpm_file_to_image(\
		dummy->session, "./textures/Stairs_P_back.xpm", &dim, &dim);
	dummy->img[10].img = mlx_xpm_file_to_image(\
			dummy->session, "./textures/Stairs_P_right.xpm", &dim, &dim);
	dummy->img[11].img = mlx_xpm_file_to_image(\
			dummy->session, "./textures/Stairs_P_left.xpm", &dim, &dim);
}
