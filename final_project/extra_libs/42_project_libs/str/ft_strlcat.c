/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:06 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/24 16:09:09 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len > size)
		return (size + s_len);
	while (src[i] && (d_len + i + 1) < size)
	{
		dst[d_len + i] = src [i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}
