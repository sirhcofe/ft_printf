/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:57:26 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/15 14:46:42 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// - sometimes we have a string as follow: =0001234   =
//   the zeros are appended by precision, and there are extra spaces behind
//   then whenever we have flags like '+' or ' ', etc
//   we need to put these flag in front of the string -> = 0001234  =
// - to do this, we first go through the string to look for spaces
//   this will determine the part we will substr for output
// - if space = TRUE:
//   strjoin the flags into the string first then substr one less byte from rear
// - if space = FALSE
//   strjoin the flags into the string as well, but substr everything
char	*move_and_extract(char *string, char *temp)
{
	char	*output;
	int		i;
	int		count;
	int		temp_len;

	temp_len = ft_strlen(temp);
	i = 0;
	count = 0;
	while (string[i++] != '\0')
	{
		if (string[i] == ' ')
			count++;
	}
	string = ft_strjoin(temp, string);
	output = ft_substr(string, 0, ft_strlen(string) - ((count >= temp_len
					* temp_len) + (temp_len > count) * count));
	free(string);
	return (output);
}

// - to fill symbols '+', '-', ' ', etc... we need to consider 2 conditions:
//   1. there is no spaces available
//          example: printf("=%3d=", 12345)   -> =12345=
//                   printf("=%010d=", 12345) -> =0000012345=
//   2. there are still spaces available in the string
//          example: printf("=%10d=", 12345)   -> =     12345=
//                   printf("=%10.8d=", 12345) -> =  00012345=
// - if condition 1 is true:
//      1.1 if the 0th index of output string is from precision '0' or from the
//          va_args number itself, we strjoin the symbols with output string
//              example: printf("=.10d=", -12345) -> =-0000012345=
//                       printf("=5d=", -12345)   -> =-12345=
//      1.2 else if the 0th index of output string is from zero flag, we replace
//          the 0th index with the symbols
//              example: printf("=010d=")
// - 
char	*continue_fill(char *output, char *temp, int str_len, t_flags *flag)
{
	int	i;

	if (ft_strchr(output, ' ') == 0)
	{
		if (flag->prcn >= str_len || (output[0] >= 49 && output[0] <= 57))
			return (ft_strjoin(temp, output));
		else
			ft_strlcpy(output, temp, ft_strlen(temp));
		free(temp);
	}
	else
	{
		i = 0;
		if (flag->minus == 0)
		{
			while (output[i] == ' ')
				i++;
			ft_strlcpy(output + i - ft_strlen(temp), temp, ft_strlen(temp));
			free(temp);
		}
		else if (flag->minus != 0)
			output = move_and_extract(output, temp);
	}
	return (output);
}

// - fills '+' flag or ' ' flag (only for positive number)
// - calls continue_fill except for one condition:
//   since n = 0 is considered to be positive, so when we encounter conditions:
//      printf("%+d", 0) or printf("% d", 0)
//   we need to append '+' and ' ' too
//   to not confuse '0' from va_args and '0' printed from precision/zero flags
//      printf("%.10d", 0) -> 0000000000    (what? which 0 is which?)
//   we create an additional if statement
char	*fill_plus_blank(char *output, t_flags *flag, int str_len)
{
	char	*temp;

	temp = ft_calloc(sizeof(char), 2);
	temp[0] = (((flag->plus != 0) * '+') + ((flag->blank != 0) * ' '));
	if (flag->prcn < str_len && output[0] == '0')
		output = ft_strjoin(temp, output);
	else
		output = continue_fill(output, temp, str_len, flag);
	return (output);
}

// - fills '-' flag (only for negative number)
// - calls continue_fill
char	*fill_minus(char *output, t_flags *flag, int str_len)
{
	char	*temp;

	temp = ft_strdup("-");
	output = continue_fill(output, temp, str_len, flag);
	return (output);
}
