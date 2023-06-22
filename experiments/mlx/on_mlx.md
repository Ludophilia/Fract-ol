# MLX

## Documentation Problems

The MLX is partially undocumented. Here are the functions which documentation 
is missing, with a [x] if they were useful:

- [x] int	mlx_destroy_display(void *mlx_ptr);
- [ ] int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

- [ ] void	mlx_set_font(void *mlx_ptr, void *win_ptr, char *name);

- [x] int 	mlx_loop_end (void *mlx_ptr);
- [x] int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
		void *param);
- [ ] int	mlx_do_sync(void *mlx_ptr);
- [ ] int	mlx_do_key_autorepeatoff(void *mlx_ptr);
- [ ] int	mlx_do_key_autorepeaton(void *mlx_ptr);

- [ ] int	mlx_mouse_get_pos(void *mlx_ptr, void *win_ptr, int *x, int *y);
- [ ] int	mlx_mouse_move(void *mlx_ptr, void *win_ptr, int x, int y);
- [ ] int	mlx_mouse_hide(void *mlx_ptr, void *win_ptr);
- [ ] int	mlx_mouse_show(void *mlx_ptr, void *win_ptr);