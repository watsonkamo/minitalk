/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:17:33 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/21 02:57:36 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_check(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

size_t	count_words(char *str, char charset)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (is_check(*str, charset))
		{
			if (flag)
				flag = 0;
		}
		else if (!flag)
		{
			flag = 1;
			count++;
		}
		str++;
	}
	return (count);
}

size_t	sple(const char *str, char charset)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != charset)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char *str, char charset)
{
	char	**result;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		if (!is_check(*str, charset))
		{
			j = 0;
			result[i] = (char *)malloc(sizeof(char) * (sple(str, charset) + 1));
			while (!is_check(*str, charset) && *str != '\0')
				result[i][j++] = *str++;
			result[i++][j] = '\0';
		}
		if (*str != '\0')
			str++;
	}
	result[i] = NULL;
	return (result);
}
