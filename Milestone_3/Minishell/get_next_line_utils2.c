/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:08:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 17:53:44 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_here_doc_exe(t_parameters *p, char *lim, int fd, int std)
{
	p->pluto = ft_strdup(lim);
	p->pluto = prompt_clear(p->pluto);
	while (1)
	{
		ft_putstr_fd("> ", 2);
		p->pippo = readline(NULL);
		if (g_var_signal == 130)
		{
			ft_doc_sig(p, std);
			break ;
		}
		if (p->pippo == NULL)
		{
			ft_putstr_fd("bash: warning\n", 2);
			break ;
		}
		if (ft_strncmp(p->pippo, p->pluto, ft_strlen(p->pluto)) == 0 && \
		ft_strlen(p->pluto) == ft_strlen(p->pippo))
		{
			free(p->pippo);
			break ;
		}
		ft_here_doc_exe2(p, lim, p->pippo, fd);
	}
	free(p->pluto);
}

void	ft_here_doc_exe2(t_parameters *p, char *lim, char *temp, int fd)
{
	char	*temp1;
	char	**exp;

	temp1 = ft_strjoin(temp, "\n");
	free(temp);
	temp = ft_strdup(temp1);
	free(temp1);
	exp = ft_split(temp, '\n');
	if (ft_find_quote(lim) == 0)
		ft_handle_dollar_doc(exp, p);
	ft_putstr_fd(exp[0], fd);
	ft_putstr_fd("\n", fd);
	free (temp);
	ft_free_matrix(exp, 0);
}

void	ft_doc_sig(t_parameters *p, int std)
{
	p->flag_heredoc = 1;
	p->dollar = 130;
	dup2(std, 0);
}

void	ft_here_doc_exe3(char *lim, char *temp1)
{
	temp1 = ft_strdup(lim);
	temp1 = prompt_clear(temp1);
}

void	ft_here_doc_exe4(char *temp)
{
	ft_putstr_fd("> ", 2);
	temp = readline(NULL);
}
