/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:59:28 by ahua              #+#    #+#             */
/*   Updated: 2014/11/08 12:23:05 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	a;

	if (!s1 || !s2)
		return (NULL);
	if (s2[0] == '\0')
		return (char*)s1;
	i = -1;
	while (s1[++i] != '\0')
	{
		j = 0;
		a = 0;
		while (s2[j] != '\0' && a == 0)
		{
			if (s2[j] != s1[i + j])
				a = 1;
			if (s1[i + j] == '\0')
				return (NULL);
			j++;
		}
		if (!a)
			return (char*)(&(s1[i]));
	}
	return (NULL);
}
