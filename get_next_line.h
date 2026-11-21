/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:32:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/21 18:31:19 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
# endif
typedef struct s_strct
{
	char	*res_chunk;
	char	*new_chunk;
	long		indx;
	long	offset;
}			t_strct;

char	*get_next_line(int fd);
long	check_newline(char *str, int size);
char	*str_join(char *line, t_strct *track, long *line_len);
char	*get_join(t_strct *track, long *line_len);

#endif