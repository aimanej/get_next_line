/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:40 by aijadid           #+#    #+#             */
/*   Updated: 2024/12/01 22:48:52 by aijadid          ###   ########.fr       */
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

char *extract_line_tmp_update(char **store, char **tmp)
{
	int newindex;
	char *line;

	newindex = newline(*store);
	if(newindex >= 0)
	{
		*tmp = ft_substr(*store, newindex + 1, ft_strlen(*store) - newindex);
        line = ft_substr(*store, 0, newindex + 1);
    	free(*store);
		*store = NULL;
        return line;
	}
	return NULL;
}

int read_and_store(int fd, char **buf, char **store)
{
	int iread;
	char *newstore;

	*buf = malloc(BUFFER_SIZE + 1);
	if(!*buf)
		return -1;
	iread = read(fd, *buf, BUFFER_SIZE);
	if(iread > 0)
	{
		(*buf)[iread] = '\0';
		newstore = ft_strjoin(*store, *buf);
		free(*store);
		*store = newstore;
	}
	free(*buf);
	return (iread);

}

char *get_next_line(int fd)
{
	char	*buf;
	static char	*tmp;
	char	*store;
	char *line;
	char *newstore;
	int	r;

	store = NULL;
	if (tmp)
	{
		store = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
	}
	while(1)
	{
		line = extract_line_tmp_update(&store, &tmp);
		if(line)
			return line;
		r = read_and_store(fd, &buf, &store);
		if (r < 1)
		{
			free(store);
			return NULL;
		}
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
