/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 09:16:51 by chenlee           #+#    #+#             */
/*   Updated: 2022/06/16 21:00:28 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

# define ALL "cspdiuxX%-0# +123456789."
# define CHARACTER "cspdiufxX%"
# define NUMBER "123456789"

typedef struct s_len
{
	int	n;
}		t_len;

typedef struct s_flags
{
	int		count;
	int		minus;
	int		plus;
	int		blank;
	int		zero;
	int		precisn;
	int		hash;
	char	chars;
	char	*flag_str;
	char	*nmbr_bfore_prcn;
	char	*nmbr_after_prcn;
}			t_flags;

int		ft_printf(const char *format, ...);

void	print_flag_specifier(va_list args, t_flags *flag, t_len *len);
void	print_char(int c, t_flags *flag, t_len *len);
void	print_number(int n, t_flags *flag, t_len *len);
void	print_string(char *s, t_flags *flag, t_len *len);
void	print_unsigned(unsigned int n, t_flags *flag, t_len *len);
void	print_hex(unsigned long n, t_flags *flag, t_len *len);
void	print_pointer(void *ptr, t_flags *flag, t_len *len);

char	*pregenerate_flag(t_flags *flag);
char	*nmbr_to_str(long n, t_flags *flag);

#endif
