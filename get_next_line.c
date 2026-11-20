/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:16:01 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/19 21:01:15 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.c"

int	get_next_chunk(st_chunk)
{
	char	*tmp_buff;
	int		res;

	nxt_chunk = malloc(sizeof(char) * BUFFER_SIZE);
	if (!nxt_chunk)
		return (NULL);
	res =  read(fd, nxt_chunk, BUFFER_SIZE);
		if (res == -1)
			return (NULL);
		else
			offset += res;
	get_join(st_chunk, nxt_chunk, offset);
	
}
void	get_helper(int fd)
{
	static	char	*st_chunk;
	static	int		offst = 0;
	int		res;
	
	if (check_newline(st_chunk, &offst))
	{
		buffer = get_next_chunk(st_chunk)
	}
	res = read()
	
}
char	*get_next_line(int fd)
{
	
}