/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate_reset_flag.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:26:57 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/21 18:44:10 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initiate_flags(t_flags *flag)
{
	flag->flag_str = NULL;
	flag->width = 0;
	flag-> precision = 0;
	flag->count = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->blank = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->hash = 0;
	flag->chars = 0;
}

void	reset_flags(t_flags *flag)
{
	if (flag->flag_str)
		free(flag->flag_str);
	initiate_flags(flag);
}
