#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - A custom implementation of printf
 * @format: The format string containing the characters and format specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *ptr;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
        {
            ptr++;

            if (*ptr == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*ptr == 's')
            {
                char *s = va_arg(args, char *);

                if (s == NULL)
                {
                    s = "(null)";
                }

                while (*s != '\0')
                {
                    write(1, s, 1);
                    s++;
                    count++;
                }
            }
            else if (*ptr == '%')
            {
                write(1, "%", 1);
                count++;
            }
            else
            {
                write(1, ptr - 1, 2);
                count += 2;
            }
        }
        else
        {
            write(1, ptr, 1);
            count++;
        }
    }

    va_end(args);

    return (count);
}

