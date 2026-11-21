/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:54:58 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/21 17:09:22 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

long	check_newline(char *str, int size)
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

static long	get_indx(t_strct *track)
{
	long		i;
	char	*str;
	
	str = track->new_chunk;
	i = 0;
	track->indx = 0;
	while(str[i] != '\n')
	{
		track->indx += 1;
		i++;
	}
	track->indx += 1;
	return (i + 1);
}

char	*str_join(char *line, t_strct *track, long *line_len)
{
		char	*join;
		char	*new_chunk;
		long		indx;
		long		i;

		i = -1;
		new_chunk = track->new_chunk;
		if (check_newline(new_chunk, BUFFER_SIZE))
			indx = get_indx(track);
		join = malloc((*line_len + BUFFER_SIZE + 1) * sizeof(char));
		if (!join)
			return (NULL);
		while (++i < *line_len)
			join[i] = line[i];
		i = -1;
		while (++i < BUFFER_SIZE)
			join[*line_len + i] = new_chunk[i];
		join[*line_len + BUFFER_SIZE] = '\0';
		*line_len += BUFFER_SIZE;
		return(join);
}

char	*get_join(t_strct *track, long *line_len)
{
	char	*buffer;
	long		res_chunk_len;
	long		indx;
	long		i;

	indx = 0;
	if (track->res_chunk)
		res_chunk_len = 0;
	else
		res_chunk_len = BUFFER_SIZE - get_indx(track);
	if (check_newline(track->new_chunk, BUFFER_SIZE))
		indx = get_indx(track);
	buffer = malloc((res_chunk_len + BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(NULL);
	i = -1;
	while (++i < res_chunk_len)
		buffer[i] = (track->res_chunk)[i];
	i = -1;
	while (++i < BUFFER_SIZE)
		buffer[i + res_chunk_len] = (track->new_chunk)[i];
	buffer[res_chunk_len + BUFFER_SIZE] = '\0';
	*line_len = res_chunk_len + BUFFER_SIZE;
	return (buffer);	
}
