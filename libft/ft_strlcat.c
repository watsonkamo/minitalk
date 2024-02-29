/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:51:22 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/19 02:33:17 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	src_len;

	if (dst == NULL && dstsize == 0)
	{
		return (ft_strlen(src));
	}
	src_len = 0;
	dest_len = 0;
	while (dst[dest_len] != '\0' && dest_len < dstsize)
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len == dstsize)
		return (dest_len + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < dstsize - 1)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
