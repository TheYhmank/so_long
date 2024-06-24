/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:42 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/24 16:09:38 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		count;

	if (n == 0)
		return (0);
	count = 0;
	while (count < n)
	{
		if (s1[count] && s1[count] == s2[count])
		{
			while (s1[count] && s1[count] == s2[count] && count < n)
				count++;
		}
		else
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
	}
	return (0);
}
