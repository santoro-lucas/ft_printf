/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusantor <lusantor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:53:12 by lusantor          #+#    #+#             */
/*   Updated: 2022/09/13 00:42:22 by lusantor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_parse_nbr(long int n, char formatter);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(unsigned long int n, unsigned int base, char *set);
int		ft_printf(const char *string, ...);

#endif