/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:40 by aijadid           #+#    #+#             */
/*   Updated: 2024/11/25 22:09:50 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# ifndef BUFFERSIZE
# define BUFFERSIZE 3
#endif

#include "get_next_line.h"

size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start,size_t len);
char *gnlre(char *str);

int  newline(char *str)
{
        int i;

        i = 0;
	if (!str)
		return (-1);
        while (str[i])
        {
                if (str[i] == '\n')
                        return (i);
                i++;
        }
        return (-1);
}
char *gnlre(char *str)
{
	int t;
	char *re;

	t = newline(str);
	if (t >= 0)	
		re = ft_substr(str, 0, t + 1);
	return re;
	
}
char *get_next_line(int fd)
{
	char	*buf;
	static char	*tmp;
	char	*store;
	int	i;
	int	r;
	int	t;

	t = 1;
	i = 0;
	store = NULL;
	if (tmp)
	{
		store = ft_strdup(tmp);
	}
	while(t)
	{
		i = newline(store);
                if (i >= 0)
                {

                        tmp = ft_substr(store, i + 1, ft_strlen(store) - i);
                                                store = gnlre(store);
                        break ;
                }
		buf = malloc(sizeof(char) * BUFFERSIZE);
       		if(!buf)
       		         return (0);	
		r = read(fd, buf, BUFFERSIZE);
		if(r < 1)
		{
			return NULL;
		}
		buf[r] = '\0';
		store = ft_strjoin(store, buf);
		free(buf);
	}
	return (store);
}

int main()
{
	int fd;
	char *b;
	int i = 0;

	fd = open ("readthis.txt", O_CREAT | O_RDWR, 777);
	while(i < 20)
	{
		b = get_next_line(fd);
		if (b)
			printf("\nnew line ladies and gents -->  ''%s''   \n", b);
		free(b);
		i++;
	}
}
