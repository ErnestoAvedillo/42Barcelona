/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:30:04 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/30 17:29:51 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../Nextline/get_next_line.h"
# include "colors.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/types.h>
# include <limits.h>
# include <term.h>
# include <curses.h>
//list of all accepted commands.
# define COMMANDS	"echo cd pwd export unset env exit"
# define ECHO_CMD	0
# define CD_CMD		1
# define PWD_CMD	2
# define EXPORT_CMD	3
# define UNSET_CMD	4
# define ENV_CMD	5
# define EXIT_CMD	6

# define OPERANDS	"> < >> << | ="

# define SNTX_258_ERR ">>> >>< <<> <<< <<| >>| <| >|"
# define SNTX_127_ERR "\"\""

# define NON_REDIR_CMD "cd export unset alias source"
# define NON_REDIR_CMD_L "ls echo printf find"

# define CUR_PATH "./:"

# define F_E_F "FirstError"

typedef struct s_fd_struc
{
	int		fd;
	int		fd_type;
	char	*fd_name;
	bool	expand;
	void	*next;
}	t_fd_struc;

typedef struct s_data
{
	char			*command;
	char			**env;
	char			**cmd_list;
	char			**oper_list;
	void			**functions_ptr;
	int				my_stdin;
	int				my_stdout;
	int				my_stderr;
	int				out_status;
	int				contador;
	bool			exit;
	bool			execute;
	pid_t			pid;
	struct termios	term;
}	t_data;

typedef struct s_instruct
{
	char		*pre_oper;
	char		*post_oper;
	char		**arg;
	t_data		*header;
	void		*next;
	void		*prev;
	int			signal;
	int			pipefd[2];
	t_fd_struc	*in;
	t_fd_struc	*out;
	t_fd_struc	*err;
}	t_instruct;

// init_vars
t_data		*init_vars(char **env);
t_instruct	*init_instructions(t_data *data);
void		save_signals_status(t_data *header);
// freevars
void		free_vars(t_data *data);
void		free_arrchar(char **arrchr);
void		free_inst(t_instruct *frst_inst);

int			cmd_echo(t_instruct *instruct);
int			cmd_cd(t_instruct *instruct);
int			cmd_env(t_instruct *instruct);
int			cmd_exit(t_instruct *instruct);
int			cmd_export(t_instruct *instruct);
void		print_env_sorted(char **env);
int			cmd_pwd(t_instruct *instruct);
int			cmd_unset(t_instruct *instruct);
int			cmd_setenv(t_instruct *instruct);
//cmd_exec
void		cmd_exec(t_instruct *instruct);
int			check_file_exists(t_instruct *instruct);
// Work_command
void		work_command(t_instruct *instr);
void		work_1_command(t_instruct *instr);
void		back_2_screen(t_instruct *instr);
// check_cmd_line
int			check_cmd_line(t_data *data);
//check_syntax
int			check_syntax(t_data *data);
int			check_redir(t_data *data);
//check_pipes
int			check_pipes(t_data *data);
//check_redir
int			check_redir(t_data *data);
// check_delimiter
void		check_delimiter(t_instruct *instr);
// check_delimiter1
char		*get_start_delimit(char *str);
char		*get_end_delimit(char *str);
void		fill_heredoc(t_instruct *instr, char **delimit);
char		*insert_in_line(char *cmd, char *str, char *ptr);
// check_delimiter1
void		actualize_fdname(t_instruct *instr, char *str);
// check_quotes
bool		quotes_ok(char *str);
// token_utils
char		*fill_instruct2(t_instruct *inst, char *str);
// token_utils2
void		replace_char_btw_quotes(char *str, unsigned int c1,
				unsigned int c2);
char		*check_ext_files(t_instruct *instr, char *str);
// token_utils3
char		*expand_variables(char *str);
void		prepare_for_split(char *str);
void		split_args(t_instruct *inst, char *str);
void		check_quotes(char *str, int pos, bool *quot);
char		*process_quotes(char *str);
// tokenize
t_instruct	*tokenize(t_data *data);
//admin_fd0
t_fd_struc	*get_fd_in_address(t_instruct *instr);
t_fd_struc	*get_fd_out_address(t_instruct *instr);
t_fd_struc	*get_fd_err_address(t_instruct *instr);
//admin_fd1
char		*ext_out_file(t_instruct *instr, int start, char *str);
char		*ext_err_file(t_instruct *instr, int start, char *str);
char		*ext_in_file(t_instruct *instr, int start, char *str);
// utils
char		*get_env_value(char *name_env, char **env);
char		*get_env_name(char *str);
bool		is_char_in_str(char *str, char c);
bool		is_oper(char *str);
char		*concat_env(char *name_var);
// utils2
void		ft_strrmchr(char *str, int n);
char		replace_char(char c, char c1, char c2);
// print_var
void		print_inst(t_instruct *instruct);
void		print_arr(char **arr);
void		listOpenFileDescriptors(void);
//get_var_name
char		*get_var_name(char *str, int pos);
// replace_env_var
char		*replace_env_var(char *str, int pos, int status);
char		*repl_home_dir(char *str, int pos);
char		*repl_old_dir(char *str);
// actualize_env
char		**actualize_env(char **env, char *str, int k);
// adm_signals
void		adm_signals_readline(void);
void		reset_signals(void);
void		han_c_fork(int signal);
// concat_cmd
char		*concat_cmd(char *str1, char *str2);
// get_cmd
void		get_cmd(t_data *data);
// ft_leninst
int			leninstr(t_instruct *list_instr);
// adm_redirections
void		adm_redirections(t_instruct *frst_inst);
// adm_redirections1
void		redirect(t_instruct *cur_inst);
// ft_str_arr_add
char		**ft_str_arr_add(char **arr, char *str);
// ft_str_arr_rem
char		**ft_str_arr_rem(char **arr, int pos);
// ft_strrmallchr
void		ft_strrmallchr(char *str, char c);
// adm_fileredir
bool		adm_file_redir(t_instruct *intr);
bool		output_file_redir(t_fd_struc *out);
bool		output_error_file_redir(t_fd_struc *err);
bool		input_file_redir(t_fd_struc *in);
// void		close_file_redir(t_data *header);
// ft_split_instr
char		**ft_split_instr(char const *s, char c);
// ft_strrmstr
char		*ft_strrmstr(char *str, int start, int end);
//print_err
int			print_err(char *str, ...);
//cmd_read
char		*cmd_read(char *str);
//parse_utils1.c
bool		is_redir(char c);
bool		is_quote(char c);
bool		final_redir(const char *text);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp_mod(const char *s1, const char *s2, unsigned int n);

//  parse_input1.c
char		*free_spaces(char *data);
char		*proc_quotes(char *f_spaces, char *p_quot, int i);
char		*free_quotes(char *data);

//parse_input2.c
bool		first_pipe(char *text);
bool		check_two_pipes(char *text);
int			new_line(void);

//parse_input3.c
int			error_found(char *texto, int *i, int j, int *consecutive_errors);
bool		check_blocks(char *texto, int *i, int *consecutive_errors);
bool		many_blocks(char *text);

//parse_input4.c
char		*return_error_found(char *texto, int *i, int *j, \
				int *consecutive_errors);
char		*return_check(char *texto, int *i, int *consecutive_errors);
char		*process_many_blocks(char *text);
int			unex_token(char *text);
bool		check_text(t_data *data);

#endif
