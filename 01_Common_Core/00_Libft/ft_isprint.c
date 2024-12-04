int	ft_isprint(char str)
{
	if (str >= 32 && str <= 126)
		return (1);
	return (0);
}
