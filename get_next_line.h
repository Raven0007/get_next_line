/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:32:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/23 14:58:11 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_strct
{
	char	*res_chunk;
	char	*chunk;
	long	res_len;
	long	bytes;
}			t_strct;

void	*ft_memcpy(char *dest, char *src, long n);
char	*str_join(char *line, t_strct *track, long *line_len);
long	get_indx(char *str, t_strct *track);
int		check_newline(char *str, long size);
char	*get_next_line(int fd);
#endif