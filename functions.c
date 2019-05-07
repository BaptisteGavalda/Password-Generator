/**
 * Password Generator
 * @author Baptiste Gavalda
 * @version 0.1
 * @version_note first edit
**/

#include "functions.h"

char isnum(char *str)
{
  for (int i = 0; str[i]; i++)
    {
      if (!ISNUM(str[i]))
	return (0);
    }
  return (1);
}

char test_args(int ac, char **av)
{
  if (ac < 3)
    {
      write(2, "./passgen name pass_phrase [length] [OPTION]\n", 45);
      return (0);
    }
  if (ac > 3)
    {
      for (int i = 0; av[3][i]; i++)
	{
	  if (!ISNUM(av[3][i]))
	    {
	      write(2, "./passgen [application | website] pass_phrase length\n", 46);
	      return (0);
	    }
	}
    }
  return (1);
}
