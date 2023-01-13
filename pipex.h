/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:37:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/13 22:33:36 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 434
# endif
# define TEMP_FILE_NAME ".temp_file"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_unsg(unsigned int n);
int		ft_printf(const char *format, ...);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*m_strjoin(char *s1, char *s2);
void	free_list(char **list);
void	exit_msg(char *msg, int i);
void	error_handling(char **av);
void	piping(int fd[2], int pid2, char **env, char **av);
void	command_two(int fd[], char **env, char **av);
#endif