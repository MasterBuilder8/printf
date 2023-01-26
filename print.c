#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: is the character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;

	va_start(ap, format);
	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					putchar(va_arg(ap, int));
					count++;
					break;
					case 's':
					fputs(va_arg(ap, char *), stdout);
					count += strlen(va_arg(ap, char *));
					break;
					case '%':
					putchar('%');
					count++;
					break;
					default:
					putchar(format[i]);
					count++;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(ap);
	return (count);

}
