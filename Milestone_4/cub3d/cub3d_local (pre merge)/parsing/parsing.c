/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:41:02 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:05:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_input(int argc, char **argv)
{
	int lenght;

	lenght = ft_strlen(argv[1]);
	if (argc != 2)
		return (message_error(1), 1);
	if (argv[1][lenght - 4] != '.')
		return (message_error(2), 2);
	if (argv[1][lenght - 3] != 'c')
		return (message_error(2), 2);
	if (argv[1][lenght - 2] != 'u')
		return (message_error(2), 2);
	if (argv[1][lenght - 1] != 'b')
		return (message_error(2), 2);
	return (0);
}

int	set_elements(int *elements, int toggle)
{
	if (toggle == 0)
	{
		elements[0] = 0;
		elements[1] = 0;
		elements[2] = 0;
		elements[3] = 0;
		elements[4] = 0;
		elements[5] = 0;
	}
	else
	{
		if (elements[0] == 0 || elements[0] == -1)
			return (1);
		if (elements[1] == 0 || elements[1] == -1)
			return (1);
		if (elements[2] == 0 || elements[2] == -1)
			return (1);
		if (elements[3] == 0 || elements[3] == -1)
			return (1);
		if (elements[4] == 0 || elements[4] == -1)
			return (1);
		if (elements[5] == 0 || elements[5] == -1)
			return (1);
	}
	return (0);
}

void	print_data(t_input *input)
{
	printf("\n\nDIR: %s\nTEXTURE: %s\n\n", input->t[0].direction, input->t[0].texture_path);
	printf("DIR: %s\nTEXTURE: %s\n\n", input->t[1].direction, input->t[1].texture_path);
	printf("DIR: %s\nTEXTURE: %s\n\n", input->t[2].direction, input->t[2].texture_path);
	printf("DIR: %s\nTEXTURE: %s\n\n", input->t[3].direction, input->t[3].texture_path);
	printf("FLOOR: %s\n\n", input->floor.line);
	printf("SKY: %s\n\n", input->sky.line);
}

int parse_cub3d(int argc, char **argv, t_input *input)
{
    int fd;

    if (check_input(argc, argv) != 0)
        return (0);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
	{
		return (message_error(3), 0);		
	}
	input->file_rows = ft_get_file_rows(fd);
	close(fd);
    fd = open(argv[1], O_RDONLY);
	if (input->file_rows == 0)
		return (message_error(4), 0);
	input->file = ft_get_file(fd, input->file_rows);
	close(fd);
	remove_newlines(input);
	if (inspect_file(input) == 1)
		return (message_error(5), 0);
	if (inspect_map(input) == 1)
		return (message_error(6), 0);
	if (inspect_textures(input) == 1)
		return (message_error(7), 0);
	if (inspect_bgcolors(input) == 1)
		return (message_error(8), 0);
	// print_data(input);		--Commentata prima delle vacanze--
	return (0);
}
