/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:27:45 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:04:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	inspect_line(t_input *input, int *elements, int *indxs)
{
	if (is_dir_line(input, elements, indxs, "NO") == 1 || \
		is_dir_line(input, elements, indxs, "SO") == 1 || \
		is_dir_line(input, elements, indxs, "WE") == 1 || \
		is_dir_line(input, elements, indxs, "EA") == 1 || \
		is_skyfloor_line(input, elements, indxs, "F") == 1 || \
		is_skyfloor_line(input, elements, indxs, "C") == 1)
		return (1);
	else
		return (0);
}

int	inspect_file(t_input *input)
{
	int	indxs[3];
	int	elements[6];

	indxs[0] = -1;
	indxs[2] = -1;
	set_elements(elements, 0);
	while (++indxs[0] < input->file_rows)
	{
		// printf("R: %s\n", input->file[indxs[0]]); --Commentata prima delle vacanze--
		indxs[1] = 0;
		while (input->file[indxs[0]][indxs[1]] == ' ' && !(set_elements(elements, 1) == 0))
			indxs[1]++;
		if (input->file[indxs[0]][indxs[1]] == '\0' || ft_strlen(input->file[indxs[0]]) == 0)
			continue;
		else if (inspect_line(input, elements, indxs) == 1)
			if (set_elements(elements, 1) == 0)
				break;		
	}
	if (set_elements(elements, 1) == 1)
		return (1);
	if (indxs[0] == input->file_rows -1)
		return (1);
	indxs[0]++;
	while (input->file[indxs[0]][0] == '\0' && indxs[0] < input->file_rows - 1)
		indxs[0]++;
	indxs[2] = indxs[0];
	if (indxs[0] == input->file_rows -1)
		return (1);
	// printf("inizio mappa riga: %d\n", indxs[2]);
	ft_get_map(input, indxs);
	return (0);
}

int	inspect_map(t_input *input)
{
	int	checks[2];
	int	indxs[2];

	checks[0] = 0; //controlla se ci sono doppioni di direzioni
	indxs[0] = -1;
	while (input->map[++indxs[0]] != NULL)
	{
		if (find_char(input->map[indxs[0]], "NSWE01 ", 1) == 0 && input->map[indxs[0]][0] != '\0')//se la linea non e' vuota e trovo un carattere non valido
			return (1);
		if (find_char(input->map[indxs[0]], "NSWE", 0) == 1)//se trovo una direzione
		{
			if (checks[0] == 0)
				checks[0] = 1;
			else
				return (1);
		}
	}
	if (checks[0] == 0 || is_closed(input) == 0)
		return (1);
	return (0);
}

int	inspect_textures(t_input *input)
{
	int	fd[4];
	int	toggle;
	
	toggle = 0;
	fd[0] = open(input->t[0].texture_path, O_RDONLY);
	fd[1] = open(input->t[1].texture_path, O_RDONLY);
	fd[2] = open(input->t[2].texture_path, O_RDONLY);
	fd[3] = open(input->t[3].texture_path, O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1 || fd[3] == -1)
		toggle = 1;
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	close(fd[3]);
	return (toggle);
}

int	inspect_bgcolors(t_input *input)
{
	int		i;
	int		j;
	char	**rgbsky;
	char	**rgbfloor;

	rgbsky = ft_split2(input->sky.line, ',');
	rgbfloor = ft_split2(input->floor.line, ',');
	i = -1;
	while (rgbsky[++i] != NULL)
	{
		j = -1;
		while (rgbsky[i][++j] != '\0')
			if (ft_isdigit(rgbsky[i][j]) == 0)
				return (1);
		if (ft_atoi(rgbsky[i]) < 0 || ft_atoi(rgbsky[i]) > 255)
			return (1);
	}
	if (i != 3)
		return (1);
	input->sky.rgb_r = (int)ft_atoi(rgbsky[0]);
	input->sky.rgb_g = (int)ft_atoi(rgbsky[1]);
	input->sky.rgb_b = (int)ft_atoi(rgbsky[2]);
	//printf("\n\nCOLORE CIELO\nR: %d, G: %d, B: %d", input->sky.rgb_r, input->sky.rgb_g, input->sky.rgb_b); --Commentata prima delle vacanze--
	i = -1;
	while (rgbfloor[++i] != NULL)
	{
		j = -1;
		while (rgbfloor[i][++j] != '\0')
			if (ft_isdigit(rgbfloor[i][j]) == 0)
				return (1);
		if (ft_atoi(rgbfloor[i]) < 0 || ft_atoi(rgbfloor[i]) > 255)
			return (1);
	}
	if (i != 3)
		return (1);
	input->floor.rgb_r = (int)ft_atoi(rgbfloor[0]);
	input->floor.rgb_g = (int)ft_atoi(rgbfloor[1]);
	input->floor.rgb_b = (int)ft_atoi(rgbfloor[2]);
	//printf("\n\nCOLORE TERRA\nR: %d, G: %d, B: %d", input->floor.rgb_r, input->floor.rgb_g, input->floor.rgb_b); --Commentata prima delle vacanze--
	return (0);
}
