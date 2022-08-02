# ft_printf
A not so complete replica of the printf function in C, from one of the projects during my time studying in 42KL

<p align="center">
<img 
    width="150" 
    alt="Screenshot 2022-07-18 at 14 31 28" 
    src="https://user-images.githubusercontent.com/99158692/179455859-7203c776-952d-4c33-ae66-28a5d43d50e5.png"
  >
</p>

<p align="center">
<img 
    width="1252"
    alt="Screenshot 2022-07-18 at 14 32 20"
    src="https://user-images.githubusercontent.com/99158692/179455963-19084249-2480-4a79-85d5-495c78d1b221.png"
  >
</p>


### Acknowledgement
As with any piece of research that results in the production of this project, there should not be only the name of
the author for this project, but also the names of all those unsung heroes who provided assistance, encouragement
and guidance, in which without I would not have succeded.


I would like to thank [Jaclyn Tan](https://github.com/Jachokoreto) and [Jason](https://github.com/jasonkwm) for their
help and support throughout the process.

---

## Literature
This ft_printf program acounts for `cspdiuxX%` conversions, `-0.# +` flag and field minimum width, where:

• %c Prints a single character.

• %s Prints a string (as defined by the common C convention).

• %p The void * pointer argument has to be printed in hexadecimal format.

• %d Prints a decimal (base 10) number.

• %i Prints an integer in base 10.

• %u Prints an unsigned decimal (base 10) number.

• %x Prints a number in hexadecimal (base 16) lowercase format.

• %X Prints a number in hexadecimal (base 16) uppercase format.

• %% Prints a percent sign.

|   Flags   |  %c   |  %s   |   %p  |   %d  |   %i  |   %u  |   %x  |   %X  |  %%   |
| :---:     | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| -         |   ✓   |   ✓  |  ✓    |  ✓    | ✓    | ✓     |  ✓   |  ✓    | ✓     |
| 0         |       |       |  ✓    |   ✓  |  ✓    | ✓     |  ✓   |   ✓   |       |
| .         |       |       |       |       |       |       |       |       |       |
| #         |       |       |       |       |       |       |       |       |       |
|  (space)  |       |       |       |       |       |       |       |       |       |
| +         |       |       |       |       |       |       |       |       |       |

---

## Commands
You can compile the program with your own main.c with your own test cases by running `make test` in the repository.

---

## Process

