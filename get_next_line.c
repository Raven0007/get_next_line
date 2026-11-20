/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:16:01 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/20 23:13:11 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.c"

void	get_full_line(char	*str)
{
	if (check_newline(str))
}

char	*get_next_chunk(int fd, t_strct *track)
{
	char	*line;

	*(track->offset) = read(int fd, track->new_chunk, BUFFER_SIZE);
	if (offset == -1)
		return(NULL);
	line = get_join(track->res_chnk, track->new_chunk);
	if (!line)
		return(NULL);
	if (check_newline(line))
		return (line);
	
}

char	*get_next_line(int fd)
{
	static	t_strct	track;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);	
}