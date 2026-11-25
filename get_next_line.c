/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:32:13 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/24 17:13:55 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_line(t_list *list, long len)
{
	char	*line;
	int		i;

	i = -1;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		{
			lst_clear(&list);
			return(NULL);
		}
	while (++i <= len)
		line[i] = '\0';
	while (list)
	{
		ft_strlcat(line, list->content);	
		list = list->next;
	}
	line[len] = '\0';
	lst_clear(&list);
	return (line);
}

static int		check_new(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char		*ft_strdup(char *str)
{
	size_t	pos;
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
    pos = 0;
    len = 0;
    while (str[pos] != '\n')
        pos++;
    while (str[pos + len])
        len++;
    dup = malloc(len);
    while (i < len)
	{
      dup[i] = str[pos + i + 1];
	  i++;
	}
    return(dup);
}

char		*get_nodes(t_list *list, int fd)
{
	char 	*chunk;
	static char	*rest;
	long	bytes[2];
	t_list	last_node;

	bytes[1] = 0;
	while (1)
	{
		chunk = malloc((BUFFER_SIZE + 1) * sizeof(char));
		*bytes = read(fd, chunk, BUFFER_SIZE);
		if (*bytes == -1)
			return (NULL);
		chunk[*bytes] = '\0';
		bytes[1] += *bytes;
		if (!add_node(&list, chunk))
			return(NULL);
		if (check_new(chunk) || *bytes == 0)
			break;
	}
	if (rest)
		if (!add_front(&list, rest, bytes + 1))
			return(NULL);
	if (*bytes == 0)
		return(NULL);
	rest = ft_strdup(find_last_node(list)->content);
	return (get_line(list, bytes[1]));
}

char		*get_next_line(int fd)
{
	static	t_list	*list;
	char	*line;
	if (BUFFER_SIZE <= 0 || fd < 0)
	return (NULL);
	line = get_nodes(list, fd);
	lst_clear(&list);
	return(line);
}
