int	ft_isalnum(char str)
{
	return ((str >= 'a' && str <= 'z')
		|| (str >= 'A' && str <= 'Z')
		|| (str >= '0' && str <= '9'));
}
