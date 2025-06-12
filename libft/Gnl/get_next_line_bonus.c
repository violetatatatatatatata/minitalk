/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epascual <epascual@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:52:45 by epascual          #+#    #+#             */
/*   Updated: 2024/12/16 19:03:19 by epascual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_strjoin(char *save, char *tmp)
{
	char	*new;

	new = ft_strjoin(save, tmp);
	free(save);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*linea;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	stash[fd] = lector(fd, stash[fd]);
	if (stash[fd] == NULL || !stash[fd])
		return (NULL);
	linea = crealinea(stash[fd]);
	stash[fd] = guardaresto(stash[fd]);
	return (linea);
}

char	*lector(int fd, char *stash)
{
	int		n;
	char	*buffer;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE +1, 1);
	n = 1;
	while (n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
			return (free(buffer), NULL);
		buffer[n] = '\0';
		stash = ft_free_strjoin(stash, buffer);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (free(buffer), stash);
}

char	*crealinea(char *s)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	ret = ft_calloc(i +2, 1);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		ret[i++] = '\n';
	return (ret);
}

char	*guardaresto(char *s)
{
	int		i;
	int		n;
	char	*resto;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
		return (free(s), NULL);
	resto = ft_calloc(ft_strlen(s) - i + 1, 1);
	i++;
	n = 0;
	while (s[i])
		resto[n++] = s[i++];
	return (free(s), resto);
}
