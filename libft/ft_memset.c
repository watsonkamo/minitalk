/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:29:14 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/21 00:07:16 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t i)
{
	unsigned char	*p;
	size_t			n;

	p = ptr;
	n = 0;
	while (n < i)
	{
		p[n] = (unsigned char)c;
		n++;
	}
	return (ptr);
}
