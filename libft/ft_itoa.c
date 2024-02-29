/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:24:12 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/21 03:09:25 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numsize(int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		len += 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	d;

	d = n;
	len = ft_numsize(d);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (d < 0)
	{
		str[0] = '-';
		d *= -1;
	}
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (d != '\0')
	{
		str[--len] = (d % 10) + '0';
		d /= 10;
	}
	return (str);
}
