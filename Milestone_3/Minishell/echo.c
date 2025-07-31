/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:55:32 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/13 17:15:39 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_flags(char **matrix, int *toggle)
{
	int	i;
	int	j;

	i = 1;
	while (matrix[i] != NULL)
	{
		if (matrix[i][0] != '-')
			return (i);
		else
		{
			j = 1;
			while (matrix[i][j] != '\0')
			{
				if (matrix[i][j] != 'n')
					return (i);
				j++;
			}
		}
		*toggle = 1;
		i++;
	}
	return (i);
}

//matrix1 ->matrix[i]; matrix2->matrix[i + 1]
void	ft_echo_exe(char **s, char *matrix1, char **matrix2, int toggle)
{
	if (*s != NULL)
		free(*s);
	if (*matrix2 != NULL)
	{
		*s = ft_superjoin(matrix1, " ");
		ft_putstr_fd(*s, 1);
	}
	else
	{
		if (toggle == 0)
		{
			*s = ft_superjoin(matrix1, "\n");
			ft_putstr_fd(*s, 1);
			if (*s != NULL)
				free(*s);
		}
		else if (toggle == 1)
			ft_putstr_fd(matrix1, 1);
	}
}

int	ft_echo(char **matrix, t_parameters *p)
{
	int		i;
	char	*s;
	int		toggle;

	s = NULL;
	toggle = 0;
	i = ft_handle_flags(matrix, &toggle);
	if (matrix[i] == NULL && toggle == 0)
	{
		ft_putstr_fd("\n", 1);
		return (0);
	}
	if (matrix[i] == NULL && toggle == 1)
		return (0);
	while (matrix[i] != NULL)
	{
		ft_echo_exe(&s, matrix[i], &matrix[i + 1], toggle);
		p->dollar = 0;
		i++;
	}
	return (0);
}
