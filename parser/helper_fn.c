/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:05:29 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/16 22:12:09 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// extension of ft_itoa in which additionally considers
// plus and blank flag when printing numbers
char	*nmbr_to_str(long n, t_flags *flag)
{
	char	*str;

	str = ft_itoa(n);
	if (n >= 0 && flag->plus != 0)
		ft_strjoin("+", str);
	else if (n >= 0 && flag->blank != 0)
		ft_strjoin(" ", str);
	return (str);
}

#include <stdio.h>
// initial allocation of spaces based on number_before_precision
char	*ft_spalloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = malloc(size * count);
	if (!ptr)
		return (0);
	i = 0;
	while (i < (size * count))
	{
		ptr[i] = ' ';
		i++;
	}
	ptr[i] = '\0';
	printf("Spalloc did run\n");
	return (ptr);
}

// to fill the spaces with 0 when zero flag or number_after_precision is used
void	fill_width(char *output, t_flags *flag, int n)
{
	int	i;
	int	j;

	i = 0;
	if (flag->minus != 0)
	{
		while (i++ <= n)
			output[i] = '0';
	}
	else
	{
		while (i++ <= n)
		{
			j = ft_strlen(output);
			output[j--] = '0';
		}
	}
}

// ----- pregeneration of string -----
// line 80-88: if statement tries to allocate spaces if there's nmbr_bfore_prcn;
// 			   however if we are printing numbers, we need to consider if
//			   (nmbr_after_prcn > nmbr_bfore_prcn) in which if true, we will
//			   instead allocate spaces based on nmbr_after_prcn
// line 89-95: if there is a zero flag, fill_width spaces with 0
//			   if (nmbr_after_prcn != NULL), fill_width nmbr_after_prcn of 0
char	*pregenerate_flag(t_flags *flag)
{
	char	*output;

	output = NULL;
	if (flag->nmbr_bfore_prcn)
	{
		if ((ft_strchr("csp%", flag->chars) == 0)
			&& ft_atoi(flag->nmbr_bfore_prcn) < ft_atoi(flag->nmbr_after_prcn))
			output = ft_spalloc((ft_atoi(flag->nmbr_after_prcn) + 1),
					sizeof(char));
		else
			output = ft_spalloc((ft_atoi(flag->nmbr_bfore_prcn) + 1),
					sizeof(char));
	}
	if (ft_strchr("csp%", flag->chars) == 0)
	{
		if (flag->nmbr_after_prcn)
			fill_width(output, flag, ft_atoi(flag->nmbr_after_prcn));
		else if (flag->zero != 0)
			fill_width(output, flag, ft_atoi(flag->nmbr_bfore_prcn));
	}
	return (output);
}
