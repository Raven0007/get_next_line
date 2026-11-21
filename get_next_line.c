/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:16:01 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/21 18:09:00 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_full_line(int fd, t_strct *track, char	*line, long line_len)
{
	char	*tmp_buffer;
	long		bytes;

	while (!check_newline(line, line_len))
	{
		bytes = read(fd, track->new_chunk, BUFFER_SIZE);
		if (bytes == -1)
			return(NULL);
		if (bytes == 0)
			break;
		tmp_buffer = line;
		line = str_join(line, track, &line_len);
		free(tmp_buffer);
		if (!line)
			return(NULL);
	}
	track->res_chunk = track->new_chunk;
	return (line);
	
}

char	*get_next_chunk(int fd, t_strct *track)
{
	char	*line;
	long		line_len;
	long		bytes;

	line_len = 0;
	bytes = read(fd, track->new_chunk, BUFFER_SIZE);
	if (bytes == -1 || bytes == 0)
		return(NULL);
	line = get_join(track, &line_len);
	if (!line)
		return(NULL);
	return(get_full_line(fd, track, line, line_len));
}

char	*get_next_line(int fd)
{
	static	t_strct	track;
	char	*str;

	if (!track.res_chunk)
		track.res_chunk = malloc(sizeof(char) * BUFFER_SIZE);
	track.new_chunk = malloc(sizeof(char) * BUFFER_SIZE);
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = get_next_chunk(fd, &track);
	return (str);
}
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)))
	{

		printf("%s", str);
		free(str);
		
	}
	return (0);
}