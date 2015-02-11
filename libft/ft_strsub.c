/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:02:36 by ahua              #+#    #+#             */
/*   Updated: 2014/11/11 17:21:22 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ret;
	size_t			slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen || len > slen)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	s = s + start;
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[len] = '\0';
	return (ret);
}
