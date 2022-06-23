/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:26 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/23 21:50:44 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_chars(char *output, char *src, t_flags *flag)
{
	if (ft_strchr("s", flag->chars) == 0 || (ft_strchr("s", flag->chars) != 0
			&& ft_strlen(src) > flag->precision))
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, (ft_strlen(src) + 1));
		else
			ft_strlcpy((output + ft_strlen(output) - ft_strlen(src)), src,
				(ft_strlen(src) + 1));
	}
	else if (ft_strchr("s", flag->chars) != 0
		&& flag->precision > ft_strlen(src))
	{
		if (flag->minus != 0)
			ft_strlcpy(output, src, flag->precision + 1);
		else
			ft_strlcpy((output + ft_strlen(output) - flag->precision), src,
				(flag->precision + 1));
	}
}

// to fill the spaces with 0 when zero flag or number_after_precision is used
void	fill_width_zeros(char *output, t_flags *flag, int n)
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

char	*fill_plus_blank(char *output, t_flags *flag, long n)
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
	return (output);
}

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
