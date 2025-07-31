/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:43:34 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/25 15:02:50 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	*safe_malloc(size_t size)
{
	size_t	*p;

	p = malloc(size);
	if (!p)
	{
		printf("malloc allocation failed\n");
		return ((void *)-1);
	}
	else
		return (p);
}
