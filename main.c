/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:58:01 by kmahdi            #+#    #+#             */
/*   Updated: 2023/01/13 22:37:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "main.h"

void	path(char *paths, char **full_path, char *av)
{
	char	**my_paths;
	char	*program;
	int		j;

	j = 0;
	if (paths)
	{
		my_paths = ft_split(paths + 5, ':');
		while (my_paths[j])
		{
			program = m_strjoin("/", av);
			*full_path = m_strjoin(my_paths[j++], program);
			free(program);
			if (access(*full_path, F_OK) == 0)
				break ;
			free(*full_path);
			*full_path = NULL;
		}
		free_list(my_paths);
	}
}

char	*aff_path(char *av, char **env)
{
	int		i;
	char	*full_path;
	char	*paths;

	i = 0;
	full_path = NULL;
	if (access(av, F_OK) == 0)
		return (av);
	while (env[i])
	{
		paths = (ft_strnstr(env[i++], "PATH=", 5));
		path(paths, &full_path, av);
	}
	return (full_path);
}

void	command_one(int fd[], char **env, char **av)
{
	int		input;
	char	**list;
	char	*program_path;

	input = open(av[1], O_RDONLY);
	list = ft_split(av[2], ' ');
	program_path = aff_path(list[0], env);
	if (input == -1)
		exit_msg("input fd error ! \n", 1);
	if (program_path == NULL)
		exit_msg("No such file or directory \n", 1);
	if (dup2(input, 0) < 0 || (dup2(fd[1], 1) < 0))
		exit_msg("Dup error cmd1! \n", 1);
	execve(program_path, list, env);
}

void	command_two(int fd[], char **env, char **av)
{
	char	**list1;
	int		output;
	char	*program_path;

	list1 = ft_split(av[3], ' ');
	output = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (output == -1)
		exit_msg("input fd error ! \n", 1);
	program_path = aff_path(list1[0], env);
	if (program_path == NULL)
		exit_msg("No such file or directory \n", 1);
	if (dup2(output, 1) < 0 || dup2(fd[0], 0) < 0)
		exit_msg("Dup error cmd2! \n", 1);
	execve(program_path, list1, env);
}

int	main(int ac, char **av, char **env)
{
	int	pid;
	int	pid2;
	int	fd[2];

	pid = 0;
	pid2 = 0;
	if (ac == 5)
	{
		error_handling(av);
		if (pipe(fd) == -1)
			exit_msg("pipe error ! \n", 1);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			command_one(fd, env, av);
		}
		else
			piping(fd, pid2, env, av);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		exit_msg("wrong args! \n", 1);
}
