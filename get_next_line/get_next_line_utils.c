/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yryu <yryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:34:54 by yryu              #+#    #+#             */
/*   Updated: 2022/04/05 22:36:53 by yryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_cpy;

	i = -1;
	j = 0;
	if (!s)
		return (NULL);
	s_cpy = malloc(len + 1);
	if (!s_cpy)
		return (NULL);
	while (s[++i] != '\0')
		if (i >= start && j < len)
			s_cpy[j++] = s[i];
	s_cpy[j] = '\0';
	return (s_cpy);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*pointer;

	pointer = (char *)str;
	while (*pointer)
	{
		if (*pointer == c)
			return (pointer);
		else
			pointer++;
	}
	if (*pointer == c)
		return (pointer);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		len_s1;
	char	*ret;
	int		i;

	len_s1 = 0;
	i = 0;
	while (s1[i++] != '\0')
		len_s1++;
	ret = malloc(sizeof(char) * (len_s1 + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
