#include<stdio.h>
#include<stdarg.h>
#include <string.h>
#include "main.h"
/**
  * _printf - function that produces output acording to format
  * @format: const char
  * Return: cont -1
  *
  */

int _printf(const char *format, ...)
{
	int h = 0;
	long int j = 0;
	int i = 0;
	int n = 1;
	int *cont = &n; 
	char t;
	char *p;
	va_list data_type;
	
	if (format == NULL)
		return (-1);

	va_start(data_type, format);

	for (; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{	
			if (format[i + 1] == '\0')
			{
				return(-1);
			}
			i++;
			switch(format[i])
			{	
					case 'd': 
						j = va_arg(data_type, int);
						function(j, cont);
						
						break;
					case 'i':
						j = va_arg(data_type, int);
						function(j, cont);
						break;
					case 's':
						p = va_arg(data_type, char *);
						if (p == NULL)
							p = "(null)"; 
						for (h = 0; p[h] != '\0'; h++)
						{
							putchar(p[h]);
							*cont = *cont + 1;
						}
						break;
					case 'c': 
						t = va_arg(data_type, int);
						putchar(t);
						*cont = *cont + 1;
						break;
					case '%':
						putchar('%');
						*cont = *cont + 1;
						break;
					default:
						putchar(format[i- 1]);
						*cont = *cont + 1;
						putchar(format[i]);
						*cont = *cont + 1;
						break;
				}
		}
		else
		{
			putchar(format[i]);
			*cont = *cont + 1;
		}
	}
	va_end(data_type);
	return (*cont - 1);
}
