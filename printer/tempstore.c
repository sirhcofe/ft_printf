char	*ft_htoa(unsigned long n, char *s_hex, t_flags *flag)
{
	char	*s;

	s = ft_calloc(sizeof(char), 2);
	if (n >= 16)
		ft_htoa((n / 16), s_hex, flag);
	else
	{
		if (n >= 10 && n <= 15)
		{
			if (flag->chars == 'x')
				*s = (n - 10 + 'a');
			else if (flag->chars == 'X')
				*s = (n - 10 + 'A');
			s_hex = ft_strjoin(s_hex, s);
		}
		else
		{
			*s = n + '0';
			s_hex = ft_strjoin(s_hex, s);
		}
	}
	free(s);
	return (s_hex);
}