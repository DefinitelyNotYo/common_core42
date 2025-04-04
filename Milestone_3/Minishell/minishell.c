/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:12:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/04 17:30:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_faya(char *str, char *faya)
{
	int	i;
	int	j;
	int	faya_lenght;
	
	i = -1;
	j = 0;
	faya_lenght = ft_strlen(faya);
	while(str[++i] != NULL)
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

int	ft_find_home(char *path)
{
	int i;
	int	count;
	
	i = -1;
	count = 0;
	while (path[++i] != NULL)
	{
		if (path[i] == '/')
		{
			count++;
			if (count == 4)
				return (i);
		}
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
    char    *str = "test";
	
    while (ft_strncmp(str, "exit", 5) != 0)
    {
        str = readline(ft_prompt(env));
        add_history(str);
    }
}
