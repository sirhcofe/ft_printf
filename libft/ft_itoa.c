/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:44:54 by chenlee           #+#    #+#             */
/*   Updated: 2022/05/03 18:44:54 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_length(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (count = 1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_putnbr(char *ptr, long n, size_t len)
{
	if (n == 0)
		ptr[0] = '0';
	ptr[len] = '\0';
	while (n > 0)
	{
		ptr[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(long m)
{
	long	n;
	char	*ptr;
	size_t	len;

	if (m < 0)
		n = -m;
	else
		n = m;
	len = get_length(n);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	ptr = ft_putnbr(ptr, n, len);
	return (ptr);
}
