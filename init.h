/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:46:40 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/17 21:17:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H

# define INIT_H

# include "fractol_common.h"
# include "imgmgr.h"
# include "scenemgr.h"

int	get_cli_args(int argc, char **argv, t_mlx *mlx_data);

#endif