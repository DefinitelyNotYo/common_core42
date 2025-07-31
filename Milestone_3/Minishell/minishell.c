/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:12:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 14:17:07 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_var_signal = 0;

int	ft_faya(char *str, char *faya)
{
	int	i;
	int	j;
	int	faya_lenght;

	i = -1;
	j = 0;
	faya_lenght = ft_strlen(faya);
	if (faya == NULL)
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] == faya[j])
		{
			if (j == faya_lenght - 1)
				return (1);
			j++;
		}
		else
			j = 0;
	}
	return (0);
}

int	ft_home(char *path)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (path[++i] != '\0')
	{
		if (path[i] == '/')
		{
			count++;
			if (count == 3)
				return (i);
		}
	}
	return (0);
}

int	ft_check_check(char *tmp)
{
	int	i;

	i = -1;
	while (tmp[++i] != '\0')
	{
		if (tmp[i] != ' ')
			return (1);
	}
	return (0);
}

void	ft_printf_matrix( char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i] != NULL)
	{
		ft_putstr_fd(matrix[i], 2);
		ft_putstr_fd("\n", 2);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_parameters	p;

	ft_main_setup(&p, argc, argv, env);
	while (ft_strncmp(p.str, "exit", 5) != 0)
	{
		main_exe_1(&p);
		if (p.tmp == NULL)
			return (main_exe_2(&p), ft_putstr_fd("exit\n", 2), exit(0), 0);
		if (ft_strlen(p.tmp) != 0 && ft_check_check(p.tmp) != 0)
		{
			main_exe_3(&p);
			if (check_n_q(p.tmp, &p) == 0)
			{
				if (prompt_err_manager(p.tmp) == 0)
				{
					ft_putstr_fd("bash: syntax error\n", 2);
					p.dollar = 2;
					continue ;
				}				
			}		
			else
				continue ;
			main_exe_4(&p);
		}
	}
}
