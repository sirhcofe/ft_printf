/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:57:13 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/20 17:29:55 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(void *ptr, t_flags *flag, t_len *len)
{
	ft_putstr_fd("0x", 1);
	len->n += 2;
	flag->chars = 'x';
	print_hex((long)ptr, flag, len);
}
