/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:45:29 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/11 04:11:00 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*m_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*j;

	if (!s1)
		s1 = ft_calloc(1, 1);
	if (!s2 || s2[0] == 0)
		return (s1);
	i = 0;
	j = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!j)
		return (NULL);
	while (s1[i])
	{
		j[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		j[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	j[ft_strlen(s1) + i] = '\0';
	return (j);
}

int	ft_words_count(const char *s, char c)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len);
}

int	get_world_len(char const *sm, char c)
{
	int	len;

	len = 0;
	while (sm[len] && sm[len] != c)
		len++;
	return (len);
}

char	**free_stuff(char **k)
{
	int	i;

	i = 0;
	while (k[i])
	{
		free(k[i]);
		i++;
	}
	free(k);
	k = NULL;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**k;

	if (!s)
		return (NULL);
	k = (char **)malloc((ft_words_count(s, c) + 1) * (sizeof(char *)));
	if (!k)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			k[i] = ft_substr(s, 0, get_world_len(s, c));
			if (!k[i])
				return (free_stuff(k));
			s += get_world_len(s, c);
			i++;
		}
	}
	k[i] = 0;
	return (k);
}
