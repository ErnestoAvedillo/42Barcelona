/*
** mlx_mouse_hook.c for MiniLibX in 
** 
** Made by Charlie Root
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie Root
** Last update Fri Feb 23 17:11:05 2001 Charlie Root
*/


#include	"mlx_int.h"




int		mlx_mouse_hook(t_win_list *win,int (*funct)(),void *param)
{
  win->hooks[ButtonPress].hook = funct;
  win->hooks[ButtonPress].param = param;
  win->hooks[ButtonPress].mask = ButtonPressMask;
}

int	mlx_mouse_hook_pre(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[ButtonPress].hook = funct;
	win->hooks[ButtonPress].param = param;
	win->hooks[ButtonPress].mask = ButtonPressMask;
}

// Simula esta función (pseudocódigo)// Botón presionado
int	mlx_mouse_hook_rel(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[ButtonRelease].hook = funct;
	win->hooks[ButtonRelease].param = param;
	win->hooks[ButtonRelease].mask = ButtonReleaseMask;
}

// Simula esta función (pseudocódigo)// Botón presionado
int	mlx_mouse_hook_mov(t_win_list *win, int (*funct)(), void *param)
{
	win->hooks[MotionNotify].hook = funct;
	win->hooks[MotionNotify].param = param;
	win->hooks[MotionNotify].mask = PointerMotionMask;
}