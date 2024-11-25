/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aijadid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:58:43 by aijadid           #+#    #+#             */
/*   Updated: 2024/11/25 21:56:24 by aijadid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t  ft_strlen(const char *str);
char    *ft_strdup(const char *s);
char    *ft_substr(char const *s, unsigned int start,size_t len);
char *gnlre(char *str);
char    *ft_strjoin(char *s1, char *s2);
int  newline(char *str);
char *get_next_line(int fd);

#endif
