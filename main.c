/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:01 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/11 04:06:10 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(char **list)
{
	int	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
}

char	*aff_path(char *av, char **env)
{
	int		i;
	int		j;
	char	*full_path;
	char	*paths;
	char	**my_paths;
	char	*program;

	i = 0;
	if (access(av, F_OK) == 0)
		return (av);
	while (env[i])
	{
		j = 0;
		paths = (ft_strnstr(env[i++], "PATH=", 5));
		if (paths)
		{
			my_paths = ft_split(paths + 5, ':');
			while (my_paths[j])
			{
				program = m_strjoin("/", av);
				full_path = m_strjoin(my_paths[j++], program);
				free(program);
				if (access(full_path, F_OK) == 0)
					break ;
				free(full_path);
				full_path = NULL;
			}
			free_list(my_paths);
		}
	}
	return (full_path);
}

void	command_one(int fd[], char **env, char **av)
{
	int		input;
	char	**list;
	char	*program_path;

	close(fd[0]);
	input = open(av[1], O_RDONLY);
	list = ft_split(av[2], ' ');
	program_path = aff_path(list[0], env);
	if (input == -1)
	{
		ft_printf("no such file or directory: %s \n", av[1]);
		exit(1);
	}
	if (program_path == NULL)
	{
		perror("Error: no such file or directory");
		exit(EXIT_FAILURE);
	}
	if (dup2(input, 0) < 0 || (dup2(fd[1], 1) < 0))
	{
		perror("dup error !");
		exit(2);
	}
	execve(program_path, list, env);
}

void	command_two(int fd[], char **env, char **av)
{
	char	**list1;
	int		output;
	char	*program_path;

	list1 = ft_split(av[3], ' ');
	output = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	program_path = aff_path(list1[0], env);
	if (program_path == NULL)
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
	execve(program_path, list1, env);
}

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	fd[2];

	if (ac == 5)
	{
		if (fd < 0)
		{
			perror("open");
			return (1);
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
