/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayermeko <ayermeko@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:59:44 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/24 16:07:59 by ayermeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_puthex_l(const unsigned int hex)
{
	if (hex / 16)
		return (ft_puthex_l(hex / 16) + ft_puthex_l(hex % 16));
	else if (!(hex / 10))
		ft_putchar(hex + '0');
	else
		ft_putchar((char) hex - 10 + 'a');
	return (1);
}

size_t	ft_puthex_u(const unsigned int hex)
{
	if (hex / 16)
		return (ft_puthex_u(hex / 16) + ft_puthex_u(hex % 16));
	else if (!(hex / 10))
		ft_putchar(hex + '0');
	else
		ft_putchar((char) hex - 10 + 'A');
	return (1);
}
