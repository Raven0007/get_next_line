/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:32:44 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/26 19:17:27 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*find_last_node(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	lst_clear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
}

size_t	lst_len(t_list *list)
{
	size_t	len;
	size_t	i;
	
	if (!list->content)
		return (0);
	len = 0;
	i = 0;
	while(list)
	{
		i = 0;
		while(list->content[i])
		{
			len++;
			i++;
		}
		list = list->next;
	}
	return(len);
}

int	add_node(t_list **list , char *str)
{
	t_list	*node;
	t_list *last_node;
	
	last_node = find_last_node(*list);
	node = malloc(sizeof(t_list));
	if (!node)
	{
		lst_clear(list);
		return(0);
	}
	if (!last_node)
		*list = node;
	else
		last_node -> next = node;
	node->content = str;
	node -> next = NULL;
	return(1);
}

void	ft_strlcat(char	*dst, char *src)
{
	size_t	dst_len;
	size_t	i;

	dst_len =  0;
	i = 0;
	while(dst[dst_len])
		dst_len++;
	while(src[i] && src[i] != '\n')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (src[i] == '\n')
		dst[dst_len + i++] = '\n';
	dst[dst_len + i] = '\0';
}

