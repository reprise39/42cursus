/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 19:49:50 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

// mode
# define INPUT_FORMAT_ERROR 0
# define EXEC_HEREDOC_MODE 10
# define EXEC_PIPE_MODE 20

// struck
typedef struct s_input
{
	int		cmd_num;
	int		pipe_num;
	int		exec_i_num;
	char	***cmd_phrase;
	char	**cmd_fullpath;
}			t_input;

// pipe_mode.c
int			pipe_mode(int argc, char **argv, char *envp[]);

// check_pipemode_input_file.c
int			file1_unexist(char *path);
int			file2_unexist(int argc, char **argv);
int			file1_no_read_auth(char *path);
int			file2_no_write_auth(char *path);

// check_pipemode_input_cmd.c
int			cmd_unexit(int argc, char **argv, char *env_path);

// set_struct.c
t_input		*set_struct(int argc, char **argv, char *envp[]);

// print_struct.c
void		print_struct(t_input *print);

// free_struct
void		free_struct(t_input *input);

// exec_pipe.c
int			exec_pipe(int argc, char **argv, char *envp[], t_input *pipe_input);
void		exec_cmds(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);

// exec_cmds.c
void		close_not_neighbor_pipe(int pipe_fd[][2], t_input *pipe_input);
void		exec_child(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);
void		exec_first_cmd(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);
void		exec_last_cmd(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);
void		exec_mid_cmd(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);

// utils.c
char		*getpath_from_env(char **envp);
char		*ft_strcat_threewords(char *dest, char *one, char *two,
				char *three);
void		free_ft_split(char **dest);
void		free_cmd_phrase(char ***cmd_phrase);

#endif