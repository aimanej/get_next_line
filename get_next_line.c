/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:40 by aijadid           #+#    #+#             */
/*   Updated: 2024/11/28 06:30:59 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
/*
char *gnlre(char *str)
{
	int t;
	char *re;

	t = newline(str);
	if (t >= 0)	
		re = ft_substr(str, 0, t + 1);
	return re;
	
}*/
char *get_next_line(int fd)
{
	char	*buf;
	static char	*tmp;
	char	*store;
	char *line;
	char *newstore;
	int	i;
	int	r;

	i = 0;
	store = NULL;
	if (tmp)
	{
		store = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
	while(1)
	{
		i = newline(store);
    	    	if (i >= 0)
        	{
            		tmp = ft_substr(store, i + 1, ft_strlen(store) - i);
           		line = ft_substr(store, 0, i + 1);
    	    		free(store);
            		return line;
		}
		buf = malloc(sizeof(char) * BUFFERSIZE + 1);
       		if(!buf)
			return (NULL);
		r = read(fd, buf, BUFFERSIZE);
		if(r < 1)
		{
			free(buf);
			free(store);
			return NULL;
		}
		buf[r] = '\0';
		newstore = ft_strjoin(store, buf);
		free(store);
		store = newstore;
		free(buf);
	}
}

int main()
{
	int fd;
	char *b;
	int i = 0;

	fd = open ("readthis.txt", O_CREAT | O_RDWR, 777);
	while(b = get_next_line(fd))
        {
                printf("\nnew line ladies and gents -->  ''%s''   \n", b);
                free(b);
        }
}
