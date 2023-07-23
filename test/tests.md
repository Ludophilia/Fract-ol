# Fractol, test suite


## Happy path series

#### Mandelbrot 

`./fractol 0`
`./fractol +0`
`./fractol -0`

#### Julia 

`./fractol 1 0.285 0.01`
`./fractol +1 +0.285 +0.01`
`./fractol 1 -0.78 - 0.15`

## Error series

On those case, error message should be printed

### ./fractol level

#### No arguments or Empty arguments

`./fractol`
`./fractol ""`
`./fractol "" "" "" ""`
`./fractol 1 0 ""`

#### Invalid arguments

`./fractol a b c`
`./fractol x`
`./fractol +`
`./fractol -`
`./fractol . . .`
`./fractol -1 0 0`

#### Mandelbrot 

`./fractol 0 ""`
`./fractol 0+`
`./fractol 0x`
`./fractol 0.`
`./fractol 0 0.1 1.7`
`./fractol 0 . .`

#### Julia 

`./fractol 1`
`./fractol 1.0`
`./fractol 1.`
`./fractol 1 0 1.`
`./fractol 1. 0 1.`
`./fractol 1 0 1..`
`./fractol 1 o l o`
`./fractol 1 +. 1.0`
`./fractol 1 . .`
`./fractol 1 3 .`
`./fractol 1 .0 .0`