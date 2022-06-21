/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:57:13 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/21 20:23:26 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointer(unsigned long ptr, t_flags *flag, t_len *len)
{
	char	*str;
	char	*zero_x;
	int		x;

	zero_x = ft_strdup("0x");
	str = ft_strjoin(zero_x, ft_itoa(*(long *)ptr));
	x = ft_atoi(str);
	flag->chars = 'x';
	flag->hash = 1;
	print_hex((long)x, flag, len);
}
