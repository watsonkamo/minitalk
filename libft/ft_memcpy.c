/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:28:04 by eshintan          #+#    #+#             */
/*   Updated: 2024/02/27 15:33:35 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_ptr;
	char	*src_ptr;	

	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest_ptr = (char *)dest;
		src_ptr = (char *)src;
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
