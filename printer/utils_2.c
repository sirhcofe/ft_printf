/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:26 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/24 23:04:54 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_chars(char *output, char *src, t_flags *flag)
{
	if (ft_strchr("s", flag->chars) == 0 || (ft_strchr("s", flag->chars) != 0
			&& flag->precision > ft_strlen(src)))
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, (ft_strlen(src) + 1));
		else
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(src)), src,
				(ft_strlen(src) + 1));
	}
	else if (ft_strchr("s", flag->chars) != 0
		&& flag->precision < ft_strlen(src))
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, flag->precision + 1);
		else
			ft_strlcpy((output + ft_strlen(output) - flag->precision), src,
				(flag->precision + 1));
	}
}

// to fill the spaces with 0 when zero flag or number_after_precision is used
void	fill_width_zeros(char *output, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->precision != 0)
	{
		if (flag->minus != 0)
		{
			while (i < (flag->precision + 1))
				output[i++] = '0';
		}
		else
		{
			i = 1;
			while (i < (flag->precision + 1))
				output[ft_strlen(output) - i++] = '0';
		}
	}
	else if (flag->zero != 0)
	{
		while (i < ft_strlen(output))
			output[i++] = '0';
	}
}

// first if runs when: 1. there's no width and precision (eg: %s, "abc")
//                     2. precision > width (eg: %2.4d, 69)
// second if (else) runs when: width > precision (eg: %10.6d, 69)
//                             if first index is '0', strjoin '+' or ' '
//                             otherwise, go to index before output[i] = '0'
//                                        and change it to '+' or ' '
void	fill_plus_blank(char *output, t_flags *flag, long n)
{
	char	*temp;
	int		i;

	temp = ft_calloc(sizeof(char), 2);
	temp[0] = ((flag->plus != 0) * '+') + ((flag->blank != 0) * ' ')
		+ ((n < 0) * '-');
	if ((flag->width == 0 && flag->precision == 0)
		|| (flag->precision) >= (flag->width))
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
}

// first 2 ifs initiate temp with "0x" or "0X" depending on flag->chars
// third if runs when: 1. there's no width and precision (eg: %#x, 12345)
//                     2. precision > width (eg: %#2.8x, 12345)
// last if (else) runs when: width > precision (eg: %#10.8x, 12345)
char	*fill_hash_0x(char *output, t_flags *flag)
{
	char	*temp;
	int		i;

	if (flag->chars == 'x')
		temp = ft_strdup("0x");
	else if (flag->chars == 'X')
		temp = ft_strdup("0X");
	if ((flag->width == 0 && flag->precision == 0)
		|| (flag->precision) >= (flag->width))
		output = ft_strjoin(temp, output);
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
