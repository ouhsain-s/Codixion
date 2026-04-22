/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souhsain <souhsain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 09:00:22 by souhsain          #+#    #+#             */
/*   Updated: 2026/04/22 16:21:08 by souhsain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int check_digits(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		i++;
	}
	return 1;
}
int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	check_overflow(long num, int tmp, int sign)
{
	if (num == 2147483648 && sign < 0)
		return (0);
	if ((int)num / 10 != tmp)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		count;
	int		sign;
	int		tmp;
	long	num;

	num = 0;
	sign = 1;
	count = 0;
	if (!check_digits(str))
		return -1;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == '-')
		sign = -1;
	if (str[count] == '+' || str[count] == '-')
		count++;
	while (str[count] != '\0' && ft_isdigit(str[count]))
	{
		tmp = num;
		num = (num * 10) + (str[count] - '0');
		if (check_overflow(num, tmp, sign))
			return (-1);
		count++;
	}
	return (num * sign);
}