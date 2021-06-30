/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: catperei <catperei@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:07:34 by catperei          #+#    #+#             */
/*   Updated: 2021/06/30 15:32:41 by catperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)

/*
** Allocates with malloc() and returns a substring from the string ’s’.
** The substring begins at index ’start’ and is of maximum size ’len’.
*/

{
	char	*new;
	int		i;
	int		j;
	int		s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (0);
	new = (char *)malloc(len + 1);
	if (!new)
		return (0);
	i = start;
	j = 0;
	while (i < s_len && j < ((int)len))
		new[j++] = s[i++];
	new[j] = '\0';
	return (new);
	free (new);
}

char	*ft_strdup(const char *s1)

/*  Allocates sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it.
** The pointer may subsequently be used as an argument to the function free().
** If insufficient memory is available, NULL is returned.
*/

{
	char	*new;
	int		i;

	new = ((char *)malloc(ft_strlen(s1) + 1));
	i = 0;
	if (!new)
		return (0);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)

/*
** Locates the first occurrence of c (converted to a char) in the string
** pointed to by s.
** The terminating null character is considered to be part of the string;
** therefore if c is '\0', the function locates the terminating '\0'.
*/

{
	while (*s && (char)c != *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)

/*
** Allocates with malloc() and returns a new string,
** which is the result of the concatenation of ’s1’ and ’s2’.
*/

{
	char			*new;
	unsigned int	i;

	new = ((char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !new)
		return (0);
	i = 0;
	while (*s1)
		new[i++] = *s1++;
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	return (new);
}
