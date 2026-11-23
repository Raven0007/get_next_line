/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:54:58 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/23 14:45:47 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str, long size)
{
	long i;
	
	i = 0;
	while (i < size)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

long	get_indx(char *str, t_strct *track)
{
	long		i;
	
	i = 0;
	while(i < track->bytes)
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	return (i);
}

char	*str_join(char *line, t_strct *track, long *line_len)
{
		char	*join;
		long	pos;
		long	chunk_len;
		long	i;

		chunk_len = track->bytes;
		if (check_newline(track->chunk, track->bytes))
			chunk_len = get_indx(track->chunk, track) + 2;
		join = malloc(sizeof(char) * chunk_len + *line_len);
		if (!join)
			return(NULL);
		i = -1;
		while (++i < *line_len)
			join[i] = line[i];
		i = -1;
		while (++i < chunk_len)
			join[i + *line_len] = (track->chunk)[i];
		*line_len += chunk_len;
		return(join);
}

void	*ft_memcpy(char *dest, char *src, long n)
{
	long	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}