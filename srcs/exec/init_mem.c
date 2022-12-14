/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:31:19 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/28 18:55:17 by thomathi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_exec_loop(t_exec_loop *exec_loop)
{
	exec_loop->redirect_file_path = NULL;
	exec_loop->right_path = NULL;
}

t_mem	*initialize_mem(void)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	mem->exec_loop = (t_exec_loop *)malloc(sizeof(t_exec_loop));
	init_exec_loop(mem->exec_loop);
	mem->my_env = NULL;
	mem->path_tab = NULL;
	mem->tmpfile = "buzz";
	mem->exit_statue = 0;
	mem->lces = 0;
	return (mem);
}

void	free_exec_loop(t_exec_loop *exec_loop)
{
	if (exec_loop->redirect_file_path)
		free(exec_loop->redirect_file_path);
	if (exec_loop->right_path)
		free(exec_loop->right_path);
	free(exec_loop);
}

int	free_mem(t_mem *mem, int exit_status)
{
	if (mem->my_env)
		free_tab_2d(mem->my_env);
	if (mem->path_tab)
		free_tab_2d(mem->path_tab);
	if (mem->exec_loop)
		free_exec_loop(mem->exec_loop);
	if (mem)
		free(mem);
	return (exit_status);
}

void	free_path(t_mem *mem)
{
	if (mem->exec_path)
		free(mem->exec_path);
	if (mem->path_env)
		free(mem->path_env);
}
