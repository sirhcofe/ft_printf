/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:26 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/05 21:33:34 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// append chars into pregenerated string
// first nested-if considers any specifiers except 

void	fill_chars(char *output, char *src, t_flags *flag)
{
	if (flag->chars != 's'
		|| (flag->chars == 's' && (flag->width > ft_strlen(src) && flag->width
					> flag->prcn && flag->prcn == 0)))
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, (ft_strlen(src) + 1));
		else
			ft_strlcpy(output + ft_strlen(output) - ft_strlen(src), src,
				ft_strlen(src) + 1);
	}
	else
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src,
				((ft_strlen(src) >= flag->prcn) * (flag->prcn)
					+ (flag->prcn > ft_strlen(src))
					* (ft_strlen(src))));
		else
			ft_strlcpy(output + ft_strlen(output) - ((flag->prcn
						>= ft_strlen(src)) * ft_strlen(src) + (ft_strlen(src)
						> flag->prcn) * flag->prcn), src,
				((flag->prcn >= ft_strlen(src)) * ft_strlen(src)
					+ (ft_strlen(src) > flag->prcn) * flag->prcn));
	}
}

// to fill the spaces with 0 when zero flag or number_after_prcn is used
void	fill_width_zeros(char *output, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->prcn != 0)
	{
		if (flag->minus != 0)
		{
			while (i < (flag->prcn + 1))
				output[i++] = '0';
		}
		else
		{
			i = 1;
			while (i < (flag->prcn + 1))
				output[ft_strlen(output) - i++] = '0';
		}
	}
	else if (flag->zero != 0)
	{
		while (i < ft_strlen(output))
			output[i++] = '0';
	}
}

// first if runs when: 1. there's no width and prcn (eg: %s, "abc")
//                     2. prcn > width (eg: %2.4d, 69)
// second if (else) runs when: width > prcn (eg: %10.6d, 69)
//                             if first index is '0', strjoin '+' or ' '
//                             otherwise, go to index before output[i] = '0'
//                                        and change it to '+' or ' '
char	*fill_plus_blank(char *output, t_flags *flag, long n)
{
	char	*temp;
	int		i;

	temp = ft_calloc(sizeof(char), 2);
	temp[0] = ((flag->plus != 0) * '+') + ((flag->blank != 0) * ' ')
		+ ((n < 0) * '-');
	if ((flag->width == 0 && flag->prcn == 0)
		|| (flag->prcn) >= (flag->width))
		output = ft_strjoin(temp, output);
	else
	{
		i = 0;
		while (output[i] == ' ')
			i++;
		if (i == 0 && output[0] == '0')
			output[i] = temp[0];
		else
			output[i - 1] = temp[0];
		free(temp);
	}
	return (output);
}

// first 2 ifs initiate temp with "0x" or "0X" depending on flag->chars
// third if runs when: 1. there's no width and prcn (eg: %#x, 12345)
//                     2. prcn > width (eg: %#2.8x, 12345)
// last if (else) runs when: width > prcn (eg: %#10.8x, 12345)
char	*fill_hash_0x(char *output, t_flags *flag)
{
	char	*temp;
	int		i;

	if (flag->chars == 'x')
		temp = ft_strdup("0x");
	else if (flag->chars == 'X')
		temp = ft_strdup("0X");
	if (output[0] != ' ' && output[1] != ' ')
		output = ft_strjoin(temp, output);
	else if (output[0] == ' ' && output[1] != ' ')
	{
		output[0] = (flag->chars == 'x') * 'x' + (flag->chars == 'X') * 'X';
		output = ft_strjoin(ft_strdup("0"), output);
		free(temp);
	}
	else
	{
		i = 0;
		while (output[i] == ' ')
			i++;
		ft_strlcpy((output + i - 2), temp, 3);
		free(temp);
	}
	return (output);
}

char	*fill_minus(char *output, t_flags *flag)
{
	char	*temp;
	int		i;

	temp = ft_strdup("-");
	if (output[0] != ' ' && flag->minus == 0)
		output = ft_strjoin(temp, output);
	else if (output[0] == ' ')
	{
		i = 0;
		while (output[i] == ' ')
			i++;
		output[i - 1] = '-';
		free(temp);
	}
	return (output);
}
