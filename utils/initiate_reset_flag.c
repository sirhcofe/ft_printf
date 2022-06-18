/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_reset_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:26:57 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/18 19:13:43 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initiate_flags(t_flags *flag)
{
	flag->flag_str = NULL;
	flag->nmbr_bfore_prcn = NULL;
	flag->nmbr_after_prcn = NULL;
	flag->count = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->blank = 0;
	flag->zero = 0;
	flag->precisn = 0;
	flag->hash = 0;
	flag->chars = 0;
}

void	reset_flags(t_flags *flag)
{
	if (flag->flag_str)
		free(flag->flag_str);
	if (flag->nmbr_after_prcn)
		free(flag->nmbr_after_prcn);
	if (flag->nmbr_bfore_prcn)
		free(flag->nmbr_bfore_prcn);
	initiate_flags(flag);
}
