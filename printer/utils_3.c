/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:44:19 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/07 02:44:19 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*move_and_extract(char *string, char *temp)
{
	char	*output;
	int		i;
	int		count;

	string = ft_strjoin(temp, string);
	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			count++;
		i++;
	}
	output = ft_substr(string, 0, ft_strlen(string) - ((count >= ft_strlen(temp)
					* ft_strlen(temp)) + (ft_strlen(temp) > count) * count));
	free(string);
	return (output);
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

// continuation of fill_minus, because norme 25 lines limit xd
char	*continue_fill_minus(char *output, char *temp, t_flags *flag)
{
	int	i;

	i = 0;
	if (flag->minus == 0)
	{
		while (output[i] == ' ')
			i++;
		output[i - 1] = '-';
		free(temp);
	}
	else if (flag->minus != 0)
		output = move_and_extract(output, temp);
	return (output);
}

// to fill '-' in case number is negative (less than zero)
// there will be 2 condition:
//		1st: there is no space in output string, ie "0000123"
//		2nd: there are space(s) in output string, ie "   00123"
// if 1st condition is true, we will have 2 outputs:
//		
char	*fill_minus(char *output, t_flags *flag, int s_len)
{
	char	*temp;

	temp = ft_strdup("-");
	if (ft_strchr(output, ' ') == 0)
	{
		if (flag->prcn >= s_len || (output[0] >= 49 && output[0] <= 57))
			output = ft_strjoin(temp, output);
		else
		{
			output[0] = '-';
			free(temp);
		}
	}
	else
		output = continue_fill_minus(output, temp, flag);
	return (output);
}
