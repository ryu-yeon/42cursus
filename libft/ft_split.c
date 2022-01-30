/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yryu <yryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:24:06 by yryu              #+#    #+#             */
/*   Updated: 2022/01/30 13:53:35 by yryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_error(char **result)
{
	unsigned int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		++i;
	}
	free(result);
	return (0);
}

static size_t	ft_get_word_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			++cnt;
		++s;
	}
	return (cnt + 1);
}

static size_t	ft_get_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		++s;
		++i;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (ft_get_word_cnt(s, c) + 1));
	if (!result)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = ft_get_word_len(s, c);
			result[i] = (char *)malloc(word_len + 1);
			if (!result[i])
				return (ft_malloc_error(result));
			ft_strlcpy(result[i++], s, word_len + 1);
			s += word_len - 1;
		}
		++s;
	}
	result[i] = 0;
	return (result);
}
