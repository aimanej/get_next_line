/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:58:43 by aijadid           #+#    #+#             */
/*   Updated: 2024/11/26 17:05:49 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

<<<<<<< HEAD
# ifndef BUFFERSIZE
# define BUFFERSIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
=======
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif
>>>>>>> 862c269b6409b1b577449c2b5b48746f124ad00e

size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start,size_t len);
char *gnlre(char *str);
char    *ft_strjoin(char *s1, char *s2);
int  newline(char *str);
char *get_next_line(int fd);

#endif
