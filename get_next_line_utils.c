/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:54:58 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/19 21:05:05 by ablaila          ###   ########.fr       */
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
			return (0);
		i++;
	}
	return(1);
}

int	get_indx(char *str)
{
	int		indx;

	indx = 0;
	while(*str == '\n')
		indx++;
	return (indx);
}

char	*get_join(char *st_chunk, char *chunk, int offset)
{
	char	*buffer;
	int		statc_len;
	int		i;

	i = 0;
	statc_len = BUFFER_SIZE - get_indx(chunk);
	buffer = malloc(statc_len + offset);
	if (!buffer)
		return(NULL);
	while (++i < statc_len)
		buffer[i] = st_chunk[i];
	i = -1;
	while (++i < offset)
		buffer[i + statc_len] = chunk[i];
	return (buffer);
	
}

char	*ft_strjoin(char *str1, char *str2, t_strct *track)
{
	int	s1_len;
	int	s2_len;
	char	*join;
	int	i;
	
	if (!str2)
		s2_len = 0;
	else
		s2_len = track->offset - BUFFER_SIZE;
	s1_len = BUFFER_SIZE - track->offset;
	join = malloc((s1_len + s2_len + nul) * sizeof(char));
	if (!join)
		return(NULL);
	i = -1;
	while (++i < s2_len)
		join[i] = str2[i];
	i = -1;
	while (++i < s1_len)
		join[i + s2_len] = str1[i];
	return (join);
}