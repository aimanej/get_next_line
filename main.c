/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:03:40 by aijadid           #+#    #+#             */
/*   Updated: 2024/11/21 22:43:12 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	int	t;

	t = 0;
	while (str[t])
		t++;
	return (t);
}

int	newline(char *str, int c)
{
	int i;

	i = 0;
	while (str[i++])
	{
		if (str[i++] == (char)c)
			return (i);
		i++;
	}
	return (0);
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

char	*ft_strcat(char *s1, char *s2)
{
	char *str;
	int	t;
	int	i;

	t = 0;
	i = 0;

	str = malloc(ft_strlen(s1) + ft_strlen(s2));
	while (s1[t])
	{
		str[i] = s1[t];
		i++;
		t++;
	}
	t = 0;
	while (s2[t])
	{
		str[i] = s2[t];
		t++;
		i++;
	}
	str[i] = '\0';
	return str;
}
char *get_next_line(int fd)
{
	char	*buf;
	char	*tmp;
	int	i;
	int	r;
	int	t;

	t = 0;
	i = 0;

	buf = malloc(sizeof(char) * 5);
	if(!buf)
		return (0);
	r = 5;
	printf("here");
	while (r && !newline(buf, 10));
	{
		printf("here");
		r = read(fd, buf, 5);
		printf("%s\n", buf);
		buf[r] = '\0';
		tmp = ft_strcat(tmp, buf);
	}
	return (tmp);
}

int main()
{
	int fd;
	char *b;
	int i = 0;

	fd = open ("readthis.txt", O_CREAT | O_RDWR, 777);
/*	while(i < 155)
	{
		b = get_next_line(fd);
		printf("%s", b);
		free(b);
		i++;
	}*/
	b = get_next_line(fd);
        printf("%s", b);
}
