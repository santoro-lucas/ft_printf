size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	return (write(1, s, ft_strlen(s)));
}

static void	putdigit(int d, char formatter)
{
	char	set[17] = "0123456789";
	char	lowerhex[17] = "abcdef";
	char	upperhex[17] = "ABCDEF";
	
	if (formatter == 'p' || formatter == 'x')
		ft_strlcat(set, lowerhex, 17);
	else if (formatter == 'X')
		ft_strlcat(set, upperhex, 17);
	ft_putchar_fd(*(set + d), fd);
}

static void	parse_nbr(int *base, char formatter)
{
	if (formatter == 'd' || formatter == 'i' || formatter == 'u')
		*base = 10;
	else if (formatter == 'p'|| formatter == 'x' || formatter == 'X')
		*base = 16;
}

void	ft_putnbr(int n, char formatter)
{
	long int	n2;
	int			base;
	
	n2 = n;
	parse_nbr(&base, formatter);
	if (n2 < 0)
	{
		ft_putchar('-');
		n2 = n2 * -1;
	}
	if (n2 >= base)
		ft_putnbr(n2 / base, formatter);
	putdigit(n2 % base, formatter);
}
