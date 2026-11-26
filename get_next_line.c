/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:32:13 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/26 17:56:20 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*get_line(t_list *list, size_t len)
{
	char	*line;
	int		i;

	i = -1;
	line = malloc(len + 1);
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
	if (!str)
		return(0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_strdup(char *str)
{
	size_t	pos;
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
    pos = 0;
    len = 0;
	if (!str)
		return(NULL);
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


static void	creat_nodes(t_list **list, int fd)
{
	char 	*chunk;
	size_t	bytes;

	while (!check_new((*list)->content))
	{
		chunk = malloc((size_t)BUFFER_SIZE + 1);
		if (!chunk)
			return;
		bytes = read(fd, chunk, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(chunk);
			return;
		}
		chunk[bytes] = '\0';
		if (!add_node(list, chunk))
			return;
	}
}

char		*get_next_line(int fd)
{
	static	t_list	*list;
	size_t	len;
	char	*line;
	t_list	*elem;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	creat_nodes(&list, fd);
	len = lst_len(list);
	line = get_line(list, len);
	elem = malloc(sizeof(size_t));
	if (!elem)
		return(NULL);
	elem->content = ft_strdup(find_last_node(list)->content);
	elem->next = list;
	list = elem;
	lst_clear(&list);
	return(line);
}
