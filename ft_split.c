/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:16:34 by abouafso          #+#    #+#             */
/*   Updated: 2024/11/07 23:16:41 by abouafso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	countword(const char *s, char c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*result;

	result = (char *)malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static void	ft_free(char **ptr, int i)
{
	while (i >= 0)
	{
		free(ptr[i]);
		i--;
	}
	free(ptr);
}

static char	**ft_help(const char *end, char c, int len, char **final)
{
	int		i;
	char	*start;

	len = countword(end, c);
	final = (char **)malloc((len + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	i = 0;
	while (i < len)
	{
		while (*end == c)
			end++;
		start = (char *)end;
		while (*end && *end != c)
			end++;
		final[i] = ft_strndup(start, end - start);
		if (!final[i])
		{
			ft_free(final, i);
			return (NULL);
		}
		i++;
	}
	final[i] = NULL;
	return (final);
}

char	**ft_split(const char *s, char c)
{
	int		len;
	char	**final;

	final = NULL;
	len = 0;
	return (ft_help(s, c, len, final));
}