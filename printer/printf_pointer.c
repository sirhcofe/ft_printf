/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:57:13 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/05 14:07:45 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_pointer(void *ptr, t_flags *flag, t_len *len)
{
	flag->chars = 'x';
	flag->hash = 1;
	print_hex((unsigned long)ptr, flag, len);
}
