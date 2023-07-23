/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clichecker.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:46:40 by jgermany          #+#    #+#             */
/*   Updated: 2023/07/20 18:12:34 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLICHECKER_H

# define CLICHECKER_H

# include "imgmgr.h"
# include "scenemgr.h"
# include "fractol_common.h"

int	cli_args_get(int argc, char **argv, t_fra *fra_data);

#endif