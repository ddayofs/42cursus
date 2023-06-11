/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:44:08 by donglee2          #+#    #+#             */
/*   Updated: 2023/05/30 16:26:17 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int c);
int	ft_putstr_fd_ret_cnt(char *s, int fd);
int	ft_putnbr_base_addr(void *address, char *base);
int	ft_putnbr_base_ll(long long n, char *base);
int	ft_printf(const char *str, ...);

#endif