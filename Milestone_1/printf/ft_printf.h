/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:53:16 by yoherfan          #+#    #+#             */
/*   Updated: 2025/05/14 17:06:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>

int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd, int toggle);
int	ft_putnbr(int n, int fd);
int	ft_putaddress(void *address);

int	ft_printf(const char *r_key, ...);
int	check_base(char *base);
int	ft_putnbr_exe(unsigned long nbr, char *base, int len);
int	ft_putnbr_base(unsigned long x, char *base, int len);
#endif