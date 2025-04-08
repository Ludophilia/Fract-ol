# Fractol

## Sequences

### Mandelbrot

z is complex number in the form of `x + yi`.

A point `x, y` of the complex plane is in the mandelbrot set if and only if
the sequence:

`z0 = 0`
`zn+1 = zn² + c`, with c a complex number such as `c = x + iy`

remains in the circle C of radius 2.

### Julia

z is complex number in the form of `x + yi`.

A point `x, y` of the complex plane is in the julia set if and only if
the sequence:

`z0 = x + iy`
`zn+1 = zn² + c`, with `c` a complex number such as `c = a + ib`,
`a` and `b` being arbitrary chosen real numbers.

remains in the circle C of radius 2.

### Burning ship

z is complex number in the form of `x + yi`.

A point `x, y` of the complex plane is in the julia set if and only if
the sequence:

`z0 = 0`
`zn+1 = (|Re(zn)| + i * |Im(zn)|)² + c`, with c a complex number such as 
`c = x + iy` remains in the circle C of radius 2.

The resulting fractal will be reversed compared to the images of the set
available online. Use `zn+1 = (|Re(zn)| - i * |Im(zn)|)² + c` instead.

## Remarquable fractals

### Julia

- `z² -0.80`, 3 big circles with mandelbrot like decorations

- `z² - 1`, three holes on real axis
- `z² - 1.75`, 5 small holes on real axis
- `z² - 1.49`, 5 small segments and more on real axis

- `z² - 0.4 + 0.6 * I`, 2 big tornados and multiple small ones (***)
- `z² -0.25 + 0.646 * I`, still 2 big tornardos (***) but
deeper

- `z² - 0.2 + 0.7 * I`, 2 big tornardos but the wings
are larger, multiple small ones (*)
- `z² - 0.835 - 0.2321 * I`, still 2 big tornardos but with less large wings

- `z² - 0.608 + 0.510 * I`, galaxy of dotted tornados (***)

- `z² + I`, fissure
- `z² -0.15 0.95`, fissure

- `z² + 0.285`, big curly cloud? A snail? (***)
- `z² + 0.285 + 0.01i` (***)
- `z² + 0.4 + 0.1 * I`, 4 clouds

- `z² + 0.34 + 0.31 * I`, big hole with angles

- `z² + 0`, circle

- `z² -0.78 - 0.15 * I`, curly cloud with curly holes
- `z² -0.78 - 0.14 * I`, curly cloud with curly holes

- `z² -0.10 + 0.75 * I`, 2 fans
- `z² +0.13 + 0.6 * I`, 2 fans turns into a whirlpool
- `z² +0.132 + 0.62 * I`, 2 fans turns into leaves

- `z² +0.285 + 0.02 * I`, hole with a lot of waves

## Palettes

### About interpolation

`interpolated_color = color1 + (int)((color2 - color1) * coeff)`

### How to count colors

C1 X X X X C2
C2 X X X X C3
C3 X X X X C4
C4 X X X X C5

C1 X X X C2		// 5 colors = (1 * 5 + (2 - 2) * (5 - 1))
C2 X X X C3 	// 9 = (1 * 5 + (3 - 2) * (5 - 1))
C3 X X X C4 	// 13 = (1 * 5 + (4 - 2) * (5 - 1))
C4 X X X C5 	// 17 = (1 * 5 + (5 - 2) * (5 - 1))

C1 X X C2		// 4 colors = (1 * 4 + (2 - 2) * (4 - 1))
C2 X X C3		// 7 = (1 * 4 + (3 - 2) * (4 - 1))

colors = (1 * colors_per_gr + (basecolors - 2) * (colors_per_gr - 1))
colors += 1 	// for the black

### Basic gradient!

0x120272 -> 0x44bcfc (dark to light blue)
0x44bcfc -> 0xffffff (light blue to white)
0xffffff -> 0xfaa502 (white to light orange)
0xfaa502 -> 0xcb2600 (light orange to red)

int	palette[6] = {
	0x120272,
	0x44bcfc,
	0xffffff,
	0xfaa502,
	0xcb2600,
	0x000000
};

### 4 colors per gradient!

int	palette[14] = {
	0x120272, 0x0047aa, 0x0081d7,
	0x44BCFC, 0x95d2fd, 0xcde8fe,
	0xFFFFFF, 0xffe0b5, 0xffc26c,
	0xFAA502, 0xed7f00, 0xde5700,
	0xCB2600, 
	0x000000
};

### 8 colors per gradient!

int	palette[30] = {
	0x120272, 0x00248b, 0x003fa2, 0x0058b8, 0x0071cb, 0x008add, 0x1ca3ed,
	0x44bcfc, 0x6dc5fd, 0x8ccffd, 0xa6d8fe, 0xbee2fe, 0xd5ebff, 0xeaf5ff,
	0xffffff, 0xfff2df, 0xffe5c0, 0xffd7a0, 0xffcb81, 0xffbe61, 0xffb13e,
	0xfaa502, 0xf59500, 0xef8500, 0xe97400, 0xe26300, 0xdb5100, 0xd33e00,
	0xcb2600, 0x000000
};

### 14 colors per gradient!

int	palette[54] = {
	0x120272, 0x071780, 0x00278d, 0x00359a, 0x0042a6, 0x0050b1, 0x005dbc,
	0x006bc7, 0x0078d1, 0x0086da, 0x0093e3, 0x17a1ec, 0x30aef4, 0x44bcfc,
	0x5cc1fc, 0x70c6fd, 0x81cbfd, 0x90d0fd, 0x9ed5fe, 0xacdafe, 0xb9e0fe,
	0xc5e5fe, 0xd1eaff, 0xddefff, 0xe9f4ff, 0xf4faff, 0xffffff,
	0xfff8ee, 0xfff1dd, 0xffeacc, 0xffe2bb, 0xffdbaa, 0xffd599, 0xffce88,
	0xffc777, 0xffc066, 0xffb954, 0xffb241, 0xfdac2a, 0xfaa502,
	0xf79c00, 0xf49400, 0xf18b00, 0xee8200, 0xeb7900, 0xe87000, 0xe46700,
	0xe05e00, 0xdc5400, 0xd84a00, 0xd43f00, 0xd03400, 0xcb2600, 0x000000
};

### 28 colors per gradient!

int	palette[110] = {
	0x120272, 0x0e0d79, 0x08167f, 0x011e86, 0x00258c, 0x002c92, 0x003398,
	0x003a9e, 0x0040a4, 0x0047aa, 0x004daf, 0x0054b5, 0x005aba, 0x0061bf,
	0x0067c4, 0x006ec9, 0x0074ce, 0x007bd2, 0x0081d7, 0x0088db, 0x008ee0,
	0x0095e4, 0x079be8, 0x1aa2ec, 0x26a8f0, 0x31aff4, 0x3bb5f8,
	0x44bcfc, 0x51befc, 0x5cc1fc, 0x66c3fd, 0x6fc6fd, 0x77c8fd, 0x7fcbfd,
	0x87cdfd, 0x8ecffd, 0x95d2fd, 0x9cd4fe, 0xa2d7fe, 0xa9d9fe, 0xafdcfe,
	0xb5defe, 0xbce1fe, 0xc2e3fe, 0xc7e6fe, 0xcde8fe, 0xd3ebff, 0xd9edff,
	0xdef0ff, 0xe4f2ff, 0xe9f5ff, 0xeff7ff, 0xf4faff, 0xfafcff,
	0xffffff, 0xfffcf7, 0xfff8ee, 0xfff5e6, 0xfff1de, 0xffeed6, 0xffeace,
	0xffe7c5, 0xffe4bd, 0xffe0b5, 0xffddad, 0xffd9a5, 0xffd69d, 0xffd395,
	0xffcf8d, 0xffcc84, 0xffc97c, 0xffc574, 0xffc26c, 0xffbf63, 0xffbc5b,
	0xffb852, 0xffb549, 0xffb23f, 0xfeaf35, 0xfdab29, 0xfba81b,
	0xfaa502, 0xf9a100, 0xf79d00, 0xf69800, 0xf59400, 0xf39000, 0xf28c00,
	0xf08800, 0xef8300, 0xed7f00, 0xec7b00, 0xea7700, 0xe87200, 0xe76e00,
	0xe56900, 0xe36500, 0xe16000, 0xe05c00, 0xde5700, 0xdc5300, 0xda4e00,
	0xd84900, 0xd64400, 0xd43e00, 0xd23900, 0xcf3300, 0xcd2d00,
	0xcb2600, 0x000000
};
