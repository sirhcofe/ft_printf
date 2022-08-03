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

### Disclaimer
I, for one, am still on a journey on a vast sea of computer programming, and I can't gurantee the information you read below is completely true. Read at your own risk :)


## Literature

### Conversions

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

These conversions can be built up to 6 parts shown below, and must be used in the order as follow:
|     %    |   Flags  | Minimum field width |  Period  | Precision/maximum field width | Argument type |
| :---:    | :---:    | :---:               | :---:    | :---:                         | :---:         |
| Required | Optional |       Optional      | Optional |            Optional           |    Required   |

---

### Flags

The flags must follow the % sign as it marks the beginning of the syntax, and wherever that make sense, more than one flag can be used. The table below shows the conversions that can be altered using the following flags and the function of applying them:

|   Flags   |  %c   |  %s   |   %p  |   %d  |   %i  |   %u  |   %x  |   %X  |  %%   | Description |
| :---:     | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :--- |
| -         |   ✓   |   ✓  |  ✓    |  ✓    | ✓    | ✓     |  ✓   |  ✓    |       | Left justify |
| 0         |       |       |  ✓    |   ✓  |  ✓    | ✓     |  ✓   |   ✓   |       | Field is padded with 0's instead of blanks |
| .         |       |   ✓   |  ✓    |  ✓   |  ✓    | ✓    |   ✓   | ✓    |       | Period, used suffixed with precisions |
| #         |       |       |       |       |       |       |    ✓  |  ✓    |       | 0x prefix added to non-zero values |
|  (space)  |       |       |       |   ✓   |  ✓    |      |       |       |       | positive values begin with a blank |
| +         |       |       |       |   ✓   |  ✓    |       |       |       |       | positive values and 0 begin with + |

---

### Minimum field width

While by default, the width of a field printed will be based on the length of the argument intended for printing. However, useful for lining up columns when printing data in tabular format, the field width can be increased using the following syntax:

```
int     main()
{
    printf("-%10d-\n", 123);
    printf("-%10s-\n", "Hello");
}

/**********************************
*  Expected outcome:
*
*  -       123-
*  -     Hello-
**********************************/
```

---

### Period

Period must be used suffixed with precision

---

### Precision

The precision takes different meanings for different conversions:

#### 1. Number/hex precision

```
printf("-%10.8d-", 123);       //outcome: -  00000123-
printf("-%10.8x-", 123);       //outcome: -  0000007b-
```

The example above allocates 10 characters total field, in which within 8 characters will be 0 appended along with the number/hex appended from right

#### 2. String precision

```
printf("-%10.2s-", "Hello");   //outcome: -        He-
```

The example above allocates 10 characters total field, and since the string is greater than 2 characters specified with the precision flag, it will be cropped down to size.

```
printf("-%2.8d-", 123);        //outcome: -00000123-
printf("-%1.4s-", "Hello");    //outcome: -Hell-
printf("-%1.8s-", "Hello");    //outcome: -Hello-
```

From the example above, should there be a scenario whereby the minimum field width specified is not sufficient to hold the string, it will be ignored and instead follows the precision (maximum field width)

## Commands
You can compile the program with your own main.c with your own test cases by running `make test` in the repository.


## Process

