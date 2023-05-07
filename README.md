# ft_printf
ft_printf is reproduced C's printf function. Just like real printf, it allows the following functionality:

```
%[flags][width][length]type 
```

Result is a formated string. Each of these parts is explained below.
To produce ft_printf() function, only UNIX write, malloc, free, exit, stdarg functions have been used. Rest of the functionality is custom built.

## Project folder structure
```
ft_printf
├── [header file for project]
└── [source files of the project]
Makefile [compiles the project]
```

## Getting Started

Run **make**, which results in library called libftprintf.a. In your source file, use ft_printf() function just as you would use printf(). Furthermore, compile your source code with libftprintf.a to use ft_printf() function. So libftprint.a includes the ft_printf() function.

```
cc main.c libftprintf.a
```
## Functionality
### [flags]

Following flags are supported
```
'#'(hash) - For o, x, X types, the text 0, 0x, 0X, respectively, is prepended to non-zero numbers.

'+'(plus) - Prepends a plus for positive signed-numeric types.

' '(space) - Prepends a space for positive signed-numeric types.This flag is ignored if the + flag exists.
```

### [width]
Width specifies a minimum number of characters to output.
For example, ft_printf("%5d", 5); would result in '    5';

### [length]
Length specifiers tell what argument is expected. It will cause ft_printf() to typecast the input
to meet necessary requirement.

### type
Following conversion characters are allowed:

```
%c (character)
%s (string)
%p (address)
%d (digit)
%i (integer)
%o (digit in octal)
%u (unsigned integer)
%x (hexadecimal in lowercase)
%X (hexadecimal in upper case)
%f (float)
```
Furthermore, ft_printf supports multibyte characters. For multibyte character argument must have L in front of it indicating that it consists of wide characters. If multibyte character or string are printed, their respective conversion character has to be in capital. For example, to print '→' character, %c becomes %C. If you wish, you can also print emojis.
```
ft_printf("%C", L'→'); Outputs '→'.
ft_printf("%C", L'😊'); Outputs '😊'

```
## Return value
Function returns bytes written to standard output. Thus, if multibyte character is printed, ft_printf() would return the amount of bytes it consists of not how many characters were printed.
```
