/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookmgr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:10:23 by jgermany          #+#    #+#             */
/*   Updated: 2023/06/23 14:14:29 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H

# define HOOKS_H

# define ESC_KEY 65307 
# define FORE_COLOR 0xffffff

# include "mlx_common.h"
# include "scenemgr.h"

int		test_mouse_hook(int button, int x, int y, void *params);
int		test_key_hook(int keycode, void *params);
int		test_loop_hook(t_mlx *mlx_data);
int		test_destroy_hook(void *params);
// int		test_hook(void);
// int		test_hook(int data);
int		test_motion_hook(int x, int y, t_mlx *mlx_data);
int		test_expose_hook(void);

#endif