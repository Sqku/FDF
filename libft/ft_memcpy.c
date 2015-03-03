/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:43:28 by ahua              #+#    #+#             */
/*   Updated: 2015/02/26 19:36:13 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*strdst;
	const unsigned char	*strsrc;

	strdst = (unsigned char*)dst;
	strsrc = (const unsigned char*)src;
	while (n--)
		*strdst++ = *strsrc++;
	return (dst);
}
