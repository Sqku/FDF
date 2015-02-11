/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:28:43 by ahua              #+#    #+#             */
/*   Updated: 2014/11/10 18:44:19 by ahua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		start;
	size_t				len1;
	char				*ret;

	if (s == NULL)
		return (NULL);
	if ((ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	len1 = ft_strlen(s) - 1;
	while (s[len1] == ' ' || s[len1] == '\n' || s[len1] == '\t')
		len1--;
	if (start == ft_strlen(s))
	{
		ret[0] = '\0';
		return (ret);
	}
	ret = ft_strsub(s, start, len1 - start + 1);
	return (ret);
}
