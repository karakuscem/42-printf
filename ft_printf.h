/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42istanbul.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:33:43 by ckarakus          #+#    #+#             */
/*   Updated: 2022/12/28 14:24:19 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t			ft_strlen(const char *str);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnumber(int num);
int				ft_printf(const char *str, ...);
int				ft_putconvert(size_t num, char *base);
void			ft_check(va_list args, char str, int *len);

#endif
