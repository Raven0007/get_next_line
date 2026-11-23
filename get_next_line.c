/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:16:01 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/23 14:53:49 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static void	free_alloc(t_strct *track)
{
	if (track->chunk)
		free(track->chunk);
	if (track->res_chunk)
		free(track->res_chunk);
}

static char	*get_line(int fd, t_strct *track)
{
	char	*tmp_buffer;
	char	*line;
	long	line_len;
	
	tmp_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!tmp_buffer)
		return(NULL);
	line_len = track->bytes;
	ft_memcpy(tmp_buffer, track->chunk, track->bytes);
	while (!check_newline(track->chunk, track->bytes))
	{
		track->bytes = read(fd, track->chunk, BUFFER_SIZE);
		if (track->bytes == -1)
		{
			free(tmp_buffer);
			return (NULL);
		}
		line = str_join(tmp_buffer, track, &line_len);
		if (!line)
		{
			free(tmp_buffer);
			return(NULL);
		}
		free(tmp_buffer);
		tmp_buffer = line;
	}
	line[line_len] = '\0';
	ft_memcpy(track->res_chunk, track->chunk, track->bytes);
	track->res_len = 0;
	return(line);
}
static char	*get_helper(t_strct *track, int fd)
{
	char	*buff;
	long	buff_len;
	long	i;

	i = -1;
	if (check_newline(track->chunk, track->bytes))
	{
		buff = malloc((track->bytes + 1) * sizeof(char));
		if (!buff)
			return(NULL);
		buff_len = get_indx(track->chunk, track) + 1;
		while (++i  < buff_len)
			buff[i] = (track->chunk)[i];
		buff[i] = '\0';
			track->res_len = 0;
	}
	else
		buff = get_line(fd, track);
	ft_memcpy(track->res_chunk, track->chunk, track->bytes);
	return(buff);
}
char	*get_next_line(int fd)
{
	char	*str;
	t_strct	track;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	track.chunk = malloc(sizeof(char) * BUFFER_SIZE);
	if (!track.chunk)
		return(NULL);
	if (track.res_len)
	{
		track.res_chunk = malloc(sizeof(char) * BUFFER_SIZE);
		if (!track.res_chunk)
		{
			free_alloc(&track);
			return (NULL);
		}
	}
	track.bytes = read(fd, track.chunk, BUFFER_SIZE);
	if (track.bytes == -1)
	{
		free_alloc(&track);
		return(NULL);
	}
	str = get_helper(&track, fd);
	if (!str)
		free_alloc(&track);
	return (str);
}
