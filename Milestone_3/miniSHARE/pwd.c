/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:50:10 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/13 17:14:41 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_parameters *p)
{
	char	curr_dir[PATH_MAX];

	getcwd(curr_dir, sizeof(curr_dir));
	ft_putstr_fd(curr_dir, 1);
	ft_putstr_fd("\n", 1);
	p->dollar = 0;
}
