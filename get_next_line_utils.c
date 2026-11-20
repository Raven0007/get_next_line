/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:54:58 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/20 23:12:20 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_newline(char *str)
{
	int i;
	
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return(0);
}

int	get_indx(char	*str)
{
	int		i;

	i = 0;
	*(track->indx) = 0;
	while(str[i] != '\n')
	{
		*(track->indx) += 1;
		i++;
	}
	*(track->indx) += 1;
	return (i);
}

char	*get_join(t_strct *track)
{
	char	*buffer;
	int		res_chunk_len;
	int		indx;
	int		i;

	if (!track->res_chnk)
		res_chunk_len = 0;
	else
		res_chunk_len = BUFFER_SIZE - get_indx(track->res_chnk);
	if (check_newline(track->new_chunk))
		indx = get_indx(track->new_chunk);
	buffer = malloc((res_chunk_len + BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(NULL);
	while (++i < res_chunk_len)
		buffer[i] = st_chunk[i];
	i = -1;
	while (++i < BUFFER_SIZE)
		buffer[i + statc_len] = chunk[i];
	buff[res_chunk_len + BUFFER_SIZE - indx] = '\0';
	return (buffer);	
}
