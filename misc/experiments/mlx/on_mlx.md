# MLX

## Documented functions

Here can be found the mlx documented functions, with a [x] if they 
ever had been useful for this project:

- [x] void	*mlx_init();

- [x] void	*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
	char *title);
- [ ] int	mlx_clear_window(void *mlx_ptr, void *win_ptr);
- [x] int	mlx_destroy_window(void *mlx_ptr, void *win_ptr);

- [ ] int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
	int color);
- [ ] int	mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
	int color, char *string);

- [x] void	*mlx_new_image(void *mlx_ptr,int width,int height);
- [ ] void	*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
			  int *width, int *height);
- [ ] void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
			       int *width, int *height);
- [o] char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
			   int *size_line, int *endian);
- [ ] int	mlx_get_color_value(void *mlx_ptr, int color);
- [o] int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
		void *img_ptr, int x, int y);
- [o] int	mlx_destroy_image(void *mlx_ptr, void *img_ptr);

- [x] int	mlx_loop (void *mlx_ptr);
- [ ] int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
- [ ] int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
- [x] int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
- [ ] int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);

## About hook function's pointers

- [ ] int   expose_hook(void *param);
- [ ] int   key_hook(int keycode, void *param);
- [ ] int   mouse_hook(int button, int x,int y, void *param);
- [ ] int   loop_hook(void *param);
- [ ] int   generic_hook(void *param);

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