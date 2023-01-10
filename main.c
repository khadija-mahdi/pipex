/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:01 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/09 22:27:18 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *aff_path(char *av, char **env)
{
	int i;
	int j;
	char *full_path;
	char *paths;
	char **my_paths;

	i = 0;
	if (access(av, F_OK) == 0)
		return (av);
	while (env[i])
	{
		j = 0;
		my_paths = ft_split(paths + 5, ':');
		if ((paths = (ft_strnstr(env[i++], "PATH=", 5))))
		{
			while (my_paths[j++])
			{
				full_path = m_strjoin(my_paths[j], m_strjoin("/", av));
				if (access(full_path, F_OK) == 0)
					break;
				full_path = NULL;
			}
		}
	}
	return (full_path);
}

void command_one(int fd[], char **env, char **av)
{

	int input = open(av[1], O_RDONLY);
	char **list = ft_split(av[2], ' ');
	close(fd[0]);
	if (input == -1)
	{
		ft_printf("no such file or directory: %s \n", av[1]);
		exit(1);
	}

	if (aff_path(list[0], env) == NULL)
	{
		perror("Error: no such file or directory");
		exit(EXIT_FAILURE);
	}
	if (dup2(input, 0) < 0 || (dup2(fd[1], 1) < 0))
	{
		perror("dup error !");
		exit(2);
	}
	execve(aff_path(list[0], env), list, env);
}

void command_two(int fd[], char **env, char **av)
{
	char **list1;
	int output;
	int temp_file;

	list1 = ft_split(av[3], ' ');
	output = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	printf("affPATH result <%s>", aff_path(list1[0], env));
	if (aff_path(list1[0], env) == NULL)
	{
		perror("Error: no such file or directory");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	if (dup2(output, 1) < 0 || dup2(fd[0], 0) < 0)
	{
		perror("err :");
		exit(2);
	}
	execve(aff_path(list1[0], env), list1, env);
}

int main(int ac, char **av, char **env)
{
	int pid;
	if (ac == 5)
	{
		int fd[2];
		if (fd < 0)
		{
			perror("open");
			return 1;
		}
		if (pipe(fd) == -1)
		{
			ft_printf("ERROR : \n opening the pipe failed !! \n");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == 0)
			command_one(fd, env, av);
		else
			command_two(fd, env, av);
		waitpid(pid, NULL, 0);
	}
	return (0);
}