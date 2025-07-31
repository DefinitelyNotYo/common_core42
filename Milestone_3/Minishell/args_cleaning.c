/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_cleaning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 14:03:12 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 17:56:50 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_args_cleaning(t_parameters *p, int len, char **args)
{
	int	i[2];

	p->p_writes = ft_calloc(len + 1, sizeof(char **));
	p->p_reads = ft_calloc(len + 1, sizeof(char **));
	ft_set_n_cut_redir(p, len, args, i);
	i[0] = -1;
	while (++i[0] < len)
		ft_handle_dollar(p->p_writes[i[0]], p);
	i[0] = -1;
	while (++i[0] < len)
		ft_handle_dollar(args, p);
	i[0] = -1;
	while (++i[0] < len)
	{
		p->p_args[i[0]].arg = ft_split_args(args[i[0]], ' ');
		p->p_args[i[0]].flag_in = 1;
		p->p_args[i[0]].flag_out = 1;
	}
	i[0] = -1;
	while (++i[0] < len)
		ft_handle_empties(&p->p_args[i[0]].arg);
}

void	ft_set_n_cut_redir(t_parameters *p, int len, char **args, int *i)
{
	i[0] = -1;
	while (++i[0] < len)
		p->p_writes[i[0]] = ft_set_writes(args[i[0]]);
	i[0] = -1;
	while (++i[0] < len)
		args[i[0]] = ft_cut_writes(args[i[0]]);
	i[0] = -1;
	while (++i[0] < len)
		p->p_reads[i[0]] = ft_set_reads(args[i[0]]);
	i[0] = -1;
	while (++i[0] < len)
		args[i[0]] = ft_cut_reads(args[i[0]]);
}
