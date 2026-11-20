/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:59:00 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/19 20:01:26 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_helper()
{
	char *chunk
}

char    *get_next_line(int fd)
{
    char *chunk;
    char *buffer;
    char *tmp_buff;
	t_strct track;
    
    tmp_buff = NULL;
    chunk = malloc(BUFFER_SIZE * sizeof(char));
	if (!chunk)
		return(NULL);
    read(fd, chunk, BUFFER_SIZE);
	track.offset = BUFFER_SIZE;
	track.indx = 0;
    while (check_newline(chunk))
    {
    	buffer = ft_strjoin(chunk, tmp_buff, &track, 0);
    	free(tmp_buff);
    	free(chunk);
		if (!buffer)
			return (NULL);
    	tmp_buff = buffer;
		chunk = malloc(BUFFER_SIZE * sizeof(char));
		if (!chunk)
			return (NULL);
    	read(fd, chunk, BUFFER_SIZE);
		track.offset += BUFFER_SIZE;
    }
	while (chunk[track.indx] != '\n')
		track.indx += 1;
	buffer = ft_strjoin(chunk, tmp_buff, &track , 1);
    	free(tmp_buff);
    	free(chunk);
	if (!buffer)
		return (NULL);
	buffer[(track.offset - BUFFER_SIZE) + track.indx + 1] = '\0';
    return (buffer);
}

int main()
{
    char *str;
    int fd;

    fd = open("test.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("%s", str);
    free(str);
}
