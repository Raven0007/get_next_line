/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:32:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/26 19:30:17 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>  // remove it 

typedef struct s_list
{
	char	*content;
	struct s_list	*next;
}			t_list;

t_list	*find_last_node(t_list *list);
int		add_node(t_list **list , char *str);
char 	*get_next_line(int fd);
void	lst_clear(t_list **list);
void	ft_strlcat(char	*dst, char *src);
size_t	lst_len(t_list *list);
#endif