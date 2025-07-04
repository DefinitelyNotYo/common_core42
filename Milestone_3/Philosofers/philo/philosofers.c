/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 14:13:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_rules	rules;

	if (parse_inputs(argc, argv) == -1)
		return (0);
	setup_table(&table, &rules, argc, argv);
	clean_memory(&table);
}
