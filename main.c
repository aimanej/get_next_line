/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:40 by aijadid           #+#    #+#             */
/*   Updated: 2024/11/25 17:50:11 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
# ifndef BUFFERSIZE
# define BUFFERSIZE 3
#endif

size_t	ft_strlen(const char *str)
{
	size_t	t;

	t = 0;
	while (str[t])
		t++;
	return (t);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		t;
	int		i;

	i = 0;
	t = ft_strlen(s);
	str = malloc(t + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ret;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		ret = malloc(ft_strlen(s) - start + 1);
	else
		ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	while (s[start] && len > 0)
	{
		ret[i] = s[start];
		start++;
		i++;
		len--;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	t;
	size_t	i;

	i = 0;
	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	t = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(t);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	t = 0;
	while (s2[t])
	{
		str[i] = s2[t];
		i++;
		t++;
	}
	str[i] = '\0';
	return (str);
}

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
	while(i < 12)
	{
		b = get_next_line(fd);
		if (b)
			printf("\nnew line ladies and gents -->  ''%s''   \n", b);
		free(b);
		i++;
	}
}
