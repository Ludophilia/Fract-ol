/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:04:50 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/20 19:33:17 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// The MLX is partially undocumented. Here are the functions which 
// documentation is missing:

// 	- int	mlx_destroy_display(void *mlx_ptr);
// 	- int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

// 	- void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);

// 	- int 	mlx_loop_end (void *mlx_ptr);
//	- int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
//			void *param);
//	- int	mlx_do_sync(void *mlx_ptr);
//	- int	mlx_do_key_autorepeatoff(void *mlx_ptr);
//	- int	mlx_do_key_autorepeaton(void *mlx_ptr);

//	- int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
//	- int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
//	- int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
//	- int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, "Half Life");
	if (!win_ptr)
		return (1);

	// How can I see the events?
	mlx_key_hook(win_ptr, mah_key_hook, (int []){19, 62, 36, 0});
	mlx_mouse_hook(win_ptr, mah_mouse_hook, NULL);
	// mlx_loop_hook(win_ptr, test, NULL);

	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, win_ptr);
	// free(win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}