/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:10 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/25 18:53:24 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//   QUANDO SI USA FORK, L'ID DEL PROCESSO DEL PADRE VIENE SOVRASCRITTO E L'ID DEL NUOVO
//   PROCESSO VIENE SETTATO A 0

int main()
{
    int id = fork();
    printf("id del processo %d\n", id);
}