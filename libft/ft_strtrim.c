/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:32:58 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/21 00:09:58 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t i = 0;
	size_t j = 0;
	size_t s1_len = 0;
	size_t set_len = 0;
	size_t trimmed_len = 0;

	if (s1 == NULL || set == NULL)
	{
		return (NULL);
	}
    s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	while (s1[i] != '\0')
	{
		while (set[j] != '\0')
		{
			if(s1[i] == set[j])
				break;
			j++;
		}
		i++;
	}
		//return (break);
	// 取り除かれた部分の長さを計算
	size_t trimmed_len = s1_len - set_len;

    // 結果の文字列noメモリを確保
	char *trimmed_str = (char *)malloc(sizeof(char) * (trimmed_len + 1));

	if (trimmed_str == NULL)
	{
		return (NULL);
	}
    // 取り除かれた部分をコピー
	ft_strlcpy(trimmed_str, s1, trimmed_len);
    // ヌル文字追加
    trimmed_str[trimmed_len] = '\0';
	return (trimmed_str);
}*/

static int	is_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed = malloc(end - start + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, end - start + 1);
	return (trimmed);
}
