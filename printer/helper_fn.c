/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:05:29 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/19 18:43:45 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*fill_plus_blank(char *output, t_flags *flag)
{
	char	*temp;
	int		i;

	temp = ft_calloc(sizeof(char), 2);
	temp[0] = ((flag->plus != 0) * '+') + ((flag->blank != 0) * ' ');
	if ((!flag->nmbr_bfore_prcn && !flag->nmbr_after_prcn)
		|| ft_atoi(flag->nmbr_after_prcn) >= ft_atoi(flag->nmbr_bfore_prcn)
		|| flag->zero != 0)
	{
		output = ft_strjoin(temp, output);
	}
	else
	{
		i = 0;
		while (output[i] == ' ')
			i++;
		if (i == 0 && output[0] == '0')
			output[i] = temp[0];
		else
			output[i - 1] = temp[0];
	}
	free(temp);
	return (output);
}

// initial allocation of spaces based on number_before_precision
char	*ft_spalloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = ft_calloc(count + 1, size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

// to fill the spaces with 0 when zero flag or number_after_precision is used
void	fill_width(char *output, t_flags *flag, int n)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(output) - 1;
	if (flag->minus != 0)
	{
		while (i <= n)
		{
			output[i] = '0';
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			output[j] = '0';
			i++;
			j--;
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
	if ((ft_strchr("csp%", flag->chars) == NULL)
		&& ft_atoi(flag->nmbr_bfore_prcn) <= ft_atoi(flag->nmbr_after_prcn))
	{
		output = ft_spalloc(ft_atoi(flag->nmbr_after_prcn),
				sizeof(char));
	}
	else
	{
		output = ft_spalloc(ft_atoi(flag->nmbr_bfore_prcn),
				sizeof(char));
	}
	if (ft_strchr("csp%", flag->chars) == 0)
	{
		if (ft_atoi(flag->nmbr_after_prcn) > 0)
			fill_width(output, flag, ft_atoi(flag->nmbr_after_prcn));
		else if (flag->zero != 0)
			fill_width(output, flag, ft_atoi(flag->nmbr_bfore_prcn));
	}
	return (output);
}
