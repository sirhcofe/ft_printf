/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:15:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/07/15 14:00:50 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_number(const char *format, t_flags *flag, int *i)
{
	int		j;
	char	*temp;

	j = 0;
	while (ft_isdigit(format[*i + j]))
		j++;
	temp = ft_substr(format, *i, j);
	if (flag->dot == 0)
		flag->width = ft_atoi(temp);
	else
		flag->prcn = ft_atoi(temp);
	*i = *i + j - 1;
	free(temp);
}

// - one main problem with identifying these flags is that the program might get
//   confused especially when dealing with zero, flag and precision flag
// - which explains the extra if conditions to differentiate those flags
void	identify_spec(const char *format, t_flags *flag)
{
	int		i;

	i = 0;
	while (i < flag->count)
	{
		if (format[i] == '-')
			flag->minus += 1;
		else if (format[i] == '+')
			flag->plus += 1;
		else if (format[i] == ' ')
			flag->blank += 1;
		else if (format[i] == '0' && ft_strchr(NUMBER, format[i - 1]) == 0
			&& flag->dot == 0)
			flag->zero += 1;
		else if (format[i] == '#')
			flag->hash += 1;
		else if (format[i] == '.')
			flag->dot += 1;
		else if (ft_isdigit(format[i]))
			parse_number(format, flag, &i);
		else if (ft_strchr(CHARACTER, format[i]))
			flag->chars = format[i];
		i++;
	}
	flag->flag_str = ft_substr(format, 0, (flag->count + 1));
}

// - goes through format string:
//      1. if the i-th index of format string is '%', this indicates a possible
//         group of flags/specifier
//      2. otherwise, just write the char of the i-th index
//   the start of a group of flags and specifier
// - if % symbol is found, check if specifier is present after the symbol until:
//      1. the i-th index of format string is not in "cspdiuxX%-0# +123456789."
//      2. one of the specifier in "cspdiuxX%" is found
// - then calls identify_spec to recognize each and every flags
// - if there is a specifier in the group, calls print_flag_specifier
// - then reset flags struct
void	parse_format(const char *format, va_list args, t_len *len)
{
	t_flags	*flag;
	int		i;

	i = -1;
	flag = malloc(sizeof(t_flags));
	initiate_flags(flag);
	while (format[++i])
	{
		if (format[i] == '%' && (format[i + 1]) != '\0')
		{
			while (ft_strchr(ALL, format[++i]))
			{
				flag->count += 1;
				if (ft_strchr(CHARACTER, format[i]))
					break ;
			}
			identify_spec((format + i + 1 - flag->count), flag);
			if (flag->chars != 0)
				print_flag_specifier(args, flag, len);
			reset_flags(flag);
		}
		else
			len->n += write(1, &format[i], 1);
	}
	free(flag);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_len		*len;
	int			print_length;

	len = malloc(sizeof(t_len));
	len->n = 0;
	va_start(args, format);
	parse_format(format, args, len);
	va_end(args);
	print_length = len->n;
	free(len);
	return (print_length);
}
