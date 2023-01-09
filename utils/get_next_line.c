/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:55:23 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/06 16:12:44 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	j = malloc((len + 1) * sizeof(char));
	if (!j)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		j[i] = s[start + i];
		i++;
	}
	j[i] = '\0';
	return (j);
}

char	*read_file(int fd, char *dest)
{
	char	*buffer;
	int		bitesreaded;

	bitesreaded = 1;
	if (!dest)
		dest = ft_calloc(1, 1);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	while (!ft_strchr(dest, '\n') && bitesreaded != 0)
	{
		bitesreaded = read(fd, buffer, BUFFER_SIZE);
		if (bitesreaded == -1)
		{	
			free (buffer);
			free (dest);
			return (NULL);
		}
		buffer[bitesreaded] = '\0';
		dest = ft_strjoin(dest, buffer);
	}
	free (buffer);
	return (dest);
}

char	*cpy_first_line(char *saver)
{
	char	*line;
	int		i;

	i = 0;
	if (!saver[i])
		return (NULL);
	while (saver[i] && saver[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (0);
	i = 0;
	while (saver[i] && saver[i] != '\n')
	{
		line[i] = saver[i];
		i++;
	}
	if (saver[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*rm_first_line(char *saver)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!saver)
		return (NULL);
	while (saver[i] && saver[i] != '\n')
		i++;
	if (!saver[i])
	{
		free (saver);
		return (NULL);
	}
	line = malloc(ft_strlen(saver) - i + 1);
	if (!line)
		return (NULL);
	i++;
	while (saver[i])
		line[j++] = saver[i++];
	line[j] = 0;
	free (saver);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	line = cpy_first_line(str);
	str = rm_first_line(str);
	return (line);
}
