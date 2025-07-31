/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:59:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:02:23 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	message_error(int err)
{
	if (err == 0)
		return ;
	else if (err == 1)
    	printf("Error\nInvalid number of arguments\n");
	else if (err == 2)
		printf("Error\nInvalid map extension\n");
	else if (err == 3)
		printf("Error\nInvalid input file\n");
	else if (err == 4)
		printf("Error\nMap is empty\n");
	else if (err == 5)
		printf("Error\nInvalid fields\n");
	else if (err == 6)
		printf("Error\nInvalid Map\n");
	else if (err == 7)
		printf("Error\nInvalid Textures\n");
	else if (err == 8)
		printf("Error\nInvalid BG colors\n");
}

void	print_matrix(t_input *input, int toggle)
{
	int	i;
	
	i = -1;
	if (toggle == 0)
	{
		while (++i < input->file_rows)
			printf("%s", input->file[i]);
	}
	if (toggle == 1)
	{
		while (input->map[++i] != NULL)
			printf("%s\n", input->map[i]);
	}
}
