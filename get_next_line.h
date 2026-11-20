/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaila <ablaila@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:32:56 by ablaila           #+#    #+#             */
/*   Updated: 2026/11/20 22:32:33 by ablaila          ###   ########.fr       */
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
	char	res_chunk[BUFFER_SIZE];
	char	new_chunk[BUFFER_SIZE];
	int		offset;
	int		indx;
}			t_strct;

char	*get_next_line(int fd);
#endif