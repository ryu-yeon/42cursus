/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yryu <yryu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:34:29 by yryu              #+#    #+#             */
/*   Updated: 2022/04/05 23:47:15 by yryu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buf, char *backup)
{
	int		read_size;
	char	*tmp;

	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (0);
		else if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		if (!backup)
			backup = ft_strdup("");
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		if (!backup)
			return (NULL);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (backup);
}

char	*extract(char *line)
{
	int		i;
	char	*ret;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	ret = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!ret)
		return (NULL);
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	line = read_line(fd, buf, backup);
	free(buf);
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
