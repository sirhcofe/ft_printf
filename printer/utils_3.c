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

char	*continue_fill_hash(char *output, char *temp, int count, t_flags *flag)
{
	if (count == 0)
		output = ft_strjoin(temp, output);
	else if (count >= 2 && output[0] == ' ' && output[1] == ' ')
	{
		ft_strlcpy(output + count - ft_strlen(temp), temp, ft_strlen(temp));
		free(temp);
	}
	else if (count == 1 && output[0] == ' ')
	{
		output[0] = ((flag->chars == 'x') * 'x') + ((flag->chars == 'X') * 'X');
		output = ft_strjoin(ft_strdup("0"), output);
		free(temp);
	}
	else
	{
		output = ft_strjoin(temp, output);
		output[ft_strlen(output) - ((count == 1) * 1) - ((count > 1) * 2)]
			= '\0';
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
	int		count;

	i = 0;
	count = 0;
	if (flag->chars == 'x')
		temp = ft_strdup("0x");
	else if (flag->chars == 'X')
		temp = ft_strdup("0X");
	while (output[i] != '\0')
	{
		if (output[i] == ' ')
			count++;
		i++;
	}
	output = continue_fill_hash(output, temp, count, flag);
	return (output);
}
