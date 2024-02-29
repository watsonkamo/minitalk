/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 02:32:53 by eshintan          #+#    #+#             */
/*   Updated: 2024/01/20 23:53:27 by eshintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*str, int c)
{
	const char	*p = str + ft_strlen(str);

	while (p >= str)
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p--;
	}
	return (NULL);
}
