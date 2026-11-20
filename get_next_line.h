/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:32:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/19 16:49:26 by ablaila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define BUFFER_SIZE 8
typedef struct s_strct
{
	int	indx;
	int	offset;
}			t_strct;

void		ft_strcpy(char *dst, char *src, int size);
char		*ft_strjoin(char *src, char *dst, t_strct *track, int nul);
int			check_newline(char *str);
#endif