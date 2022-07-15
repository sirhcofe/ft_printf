/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:54:05 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/13 14:55:47 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// - now that we've pregenerated strings with spaces, it's time to fill in chars
// - we continue to fill char except for one condition:
//      ft_printf("10.s", "abc") or ft_printf(".s", "abc")
static void	continue_str(char *output, char *source, t_flags *flag, t_len *len)
{
	if (!(flag->dot != 0 && flag->prcn == 0))
		fill_strings(output, source, flag);
	ft_putstr_fd(output, 1);
	len->n += ft_strlen(output);
	free(output);
}

static void	print_string_w_dot(char *output, char *s, t_flags *flag, t_len *len)
{
	if (flag->width > ft_strlen(s) || (flag->width != 0 && flag->prcn == 0)
		|| (flag->width > flag->prcn && ft_strlen(s) > flag->prcn))
	{
		output = pregenerate_flag(flag, 1);
		continue_str(output, s, flag, len);
	}
	else if (flag->width == 0 && flag->prcn == 0)
		return ;
	else if (ft_strlen(s) >= flag->width && ft_strlen(s) > flag->prcn)
	{
		output = pregenerate_flag(flag, 2);
		continue_str(output, s, flag, len);
	}
	else if (ft_strlen(s) >= flag->width && flag->prcn >= ft_strlen(s))
	{
		ft_putstr_fd(s, 1);
		len->n += ft_strlen(s);
	}
}

// - kinda dependant on compiler, but if s does not exist, some compiler will
//   print "(null)" and some will print "(nil)"
// - for printf_string, we consider 2 situation:
//   SITUATION 1: flag->dot does not exist
//      example: ft_printf("=%10s=", "haha")
//   if situation 1 is true, we then need to consider 2 more condition:
//      1.1 width is bigger than strlen(s) example: 
//              ft_printf("=%10s=", "abc")
//          pregenerate flag with length of width
//      1.2 otherwise, just put string
//
//   SITUATION 2: flag->dot exist
//      example: ft_printf("=%10.5s=", "haha")
//   if situation 2 is true, we consider 4 more condition:
//      2.1 pregenrate string with width when:
//          - width is bigger than strlen(s)    ft_printf("%20s", "abcde")
//          - width exist but precision doesnt  ft_printf("%8.s", "abcde")
//          - width > prcn && strlen >> prcn    ft_printf("=%8.3s=", "abcde")
//      2.2 do nothing and return when:
//          - width and prcn does not exist     ft_printf("=.s=", "abcde")
//      2.3 pregenerate string with precision when:
//          - precision > width && strlen > width && strlen > precision
//                                              ft_printf("=%2.4s=", "abcde")
//      2.4 if all above is false, just putstr
void	print_string(char *s, t_flags *flag, t_len *len)
{
	char	*output;

	if (!s)
		print_string("(null)", flag, len);
	else if (flag->dot == 0)
	{
		if (flag->width != 0 && flag->width > ft_strlen(s))
		{
			output = pregenerate_flag(flag, 1);
			continue_str(output, s, flag, len);
		}
		else
		{
			ft_putstr_fd(s, 1);
			len->n += ft_strlen(s);
		}
	}
	else
	{
		output = NULL;
		print_string_w_dot(output, s, flag, len);
	}
}
