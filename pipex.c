/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:14:34 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/13 22:34:34 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_msg(char *msg, int i)
{
	ft_printf("%s", msg);
	exit(i);
}

void	error_handling(char **av)
{
	if (av[2][0] == '\0' && av[3][0] == '\0' )
	{	
		ft_printf("command not found\n");
		exit_msg("command not found", 1);
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
		exit_msg("command not found", 1);
}

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

void	piping(int fd[2], int pid2, char **env, char **av)
{
	close(fd[1]);
	pid2 = fork();
	if (pid2 == 0)
		command_two(fd, env, av);
}
