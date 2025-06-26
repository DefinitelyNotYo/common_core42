/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:18:45 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/17 15:41:40 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_exit(char	*str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit_error(char *str, t_parameters **p)
{
	char	*temp;
	char	*temp1;

	temp1 = ft_strjoin("exit\nbash: exit: ", str);
	temp = ft_strjoin(temp1, ": numeric argument required\n");
	ft_putstr_fd(temp, 2);
	if (temp1 != NULL)
		free(temp1);
	if (temp != NULL)
		free(temp);
	(*p)->dollar = 2;
	free ((*p)->prompt);
	free ((*p)->str);
	free ((*p)->user);
	free ((*p)->place);
	ft_free_matrix((*p)->env_copy, 0);
	ft_free_3d_matrix((*p)->p_writes, 0);
	ft_free_3d_matrix((*p)->p_reads, 0);
	ft_free_arg((*p), (*p)->p_args);
	close((*p)->fd[0]);
	close((*p)->fd[1]);
	close((*p)->read_0);
	close((*p)->write_1);
	exit((*p)->dollar);
}

void	ft_exit_exe(t_parameters **p, long long unsigned value)
{
	if (value > 9223372036854775807)
	{
		ft_putstr_fd("bash: exit: numeric argument required\n", 2);
		(*p)->dollar = 2;
		return ;
	}
	ft_putstr_fd("exit\n", 2);
	(*p)->dollar = value;
	free ((*p)->prompt);
	free ((*p)->str);
	free ((*p)->user);
	free ((*p)->place);
	ft_free_matrix((*p)->env_copy, 0);
	ft_free_3d_matrix((*p)->p_writes, 0);
	ft_free_3d_matrix((*p)->p_reads, 0);
	ft_free_arg((*p), (*p)->p_args);
	close((*p)->fd[0]);
	close((*p)->fd[1]);
	close((*p)->read_0);
	close((*p)->write_1);
	exit((*p)->dollar);
}

void	ft_exit(char **matrix, t_parameters *p)
{
	if (ft_strlen_matrix(matrix) == 1)
		ft_exit_exe(&p, 0);
	else
	{
		if (ft_check_exit(matrix[1]) == 1)
			ft_exit_error(matrix[1], &p);
		else
		{
			if (ft_strlen_matrix(matrix) > 2)
			{
				ft_putstr_fd("exit\nbash: exit: too many arguments\n", 2);
				p->dollar = 1;
			}
			else if (ft_strlen_matrix(matrix) == 2)
			{
				if (ft_strlen(matrix[1]) < 20)
					ft_exit_exe(&p, ft_atoi(matrix[1]));
				else
				{
					ft_putstr_fd("bash: exit: numeric argument required\n", 2);
					p->dollar = 2;
				}
			}
		}
	}
}
