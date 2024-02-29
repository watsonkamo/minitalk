/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:55:37 by eshintan          #+#    #+#             */
/*   Updated: 2024/02/27 15:39:38 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

const char	*determine_sign(const char *str, int *sign)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	long long	k;
	int			sign;

	k = 0;
	sign = 1;
	str = determine_sign(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		if (k > LONG_MAX / 10 || (k == LONG_MAX / 10 && *str
				- '0' > LONG_MAX % 10))
		{
			if (sign == 1)
			{
				return ((int)LONG_MAX);
			}
			return ((int)LONG_MIN);
		}
		k = k * 10 + (*str - '0');
		str++;
	}
	return ((int)sign * k);
}
