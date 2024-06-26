/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:48 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/24 16:09:43 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include <string.h>

char	*ft_strnstr(const char *string, const char *find, size_t n)
{
	size_t	counter;
	size_t	match;

	counter = 0;
	match = 0;
	if (find[0] == '\0')
		return ((char *)string);
	while (string[counter] != '\0' && counter < n)
	{
		while (string[counter + match] == find[match] && counter + match < n)
		{
			if (find[match + 1] == '\0')
				return ((char *)(string + counter));
			match++;
		}
		match = 0;
		counter++;
	}
	return (NULL);
}
