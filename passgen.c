/**
 * Password Generator
 * @author Baptiste Gavalda
 * @version 0.1
 * @version_note first edit
**/

#include "passgen.h"

char passgen(char *name, char *pass, int length, int ct_length)
{
  char    *char_table[4];
  char    *c_t;
  char    c;
  int     p = 0;

  if ((c_t = malloc(ct_length * sizeof(char))) == NULL ||
      (char_table[0] = malloc(26 * sizeof(char))) == NULL ||
      (char_table[1] = malloc(26 * sizeof(char))) == NULL ||
      (char_table[2] = malloc(10 * sizeof(char))) == NULL ||
      (char_table[3] = malloc(32 * sizeof(char))) == NULL)
    return (0);
  char_table[0] = "abcdefghijklmnopqrstuvwxyz";
  char_table[1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char_table[2] = "0123456789";
  char_table[3] = "!\"#$%&'()*+'-./:;<=>?@\[]^_`{|}~";
  switch (ct_length)
    {
    case 10:
      strcat(c_t, char_table[2]);
      break;
    case 26:
      strcat(c_t, char_table[0]);
      break;
    case 32:
      strcat(c_t, char_table[3]);
      break;
    case 36:
      strcat(c_t, char_table[0]);
      strcat(c_t, char_table[2]);
      break;
    case 42:
      strcat(c_t, char_table[2]);
      strcat(c_t, char_table[3]);
      break;
    case 52:
      strcat(c_t, char_table[0]);
      strcat(c_t, char_table[1]);
      break;
    case 58:
      strcat(c_t, char_table[0]);
      strcat(c_t, char_table[3]);
      break;
    case 62:
      strcat(c_t, char_table[0]);
      strcat(c_t, char_table[1]);
      strcat(c_t, char_table[2]);
      break;
    case 84:
      strcat(c_t, char_table[0]);
      strcat(c_t, char_table[1]);
      strcat(c_t, char_table[3]);
      break;
    case 94:
      strcat(c_t, char_table[0]);
      strcat(c_t, char_table[1]);
      strcat(c_t, char_table[2]);
      strcat(c_t, char_table[3]);
      break;
    }
  for (int i = 0; i < length; i++)
    {
      c = c_t[(name[i % strlen(name)] * pass[p]) % strlen(c_t)];
      write(1, &c, 1);
      p = ((p < strlen(pass)) ? (p + 1) : (0));
    }
  write(1, "\n", 1);
  /* free(char_table[0]); */
  /* free(char_table[1]); */
  /* free(char_table[2]); */
  /* free(char_table[3]); */
  free(c_t);
  return (1);
}

  int char_table_length(char **av)
{
  int    ct_length = 94;
  char   min = 0;
  char   max = 0;
  char   spe = 0;
  char   dig = 0;

  for (int i = 1; av[i]; i++)
    {
      if (!strcmp("--no-special-character", av[i]) && !spe)
	{
	  ct_length -= 32;
	  spe = 1;
	}
      if (!strcmp("--no-digit", av[i]) && !dig)
	{
	  ct_length -= 10;
	  dig = 1;
	}
      if (!strcmp("--no-letter", av[i]) && !max)
	{
	  ct_length -= 52;
	  max = 1;
	}
      if (!strcmp("--no-uppercase", av[i]) && (!max && !min))
	{
	  ct_length -= 26;
	  min = 1;
	}
    }
  return (ct_length);
}

int main(int ac, char **av)
{
  for (int i = 0; i < ac; i++)
    {
      if (!strcmp("--help", av[i]))
	{
	  write(1, "./passgen name pass_phrase [length] [OPTION]\n", 45);
	  write(1, "--no-digit\n", 11);
	  write(1, "--no-letter\n", 12);
	  write(1, "--noupercase\n", 13);
	  write(1, "--no-sepcials-characters\n", 25);
	  return (1);
	}
    }
  if (!test_args(ac, av))
    return (0);
  passgen(av[1], av[2], 12, char_table_length(av));
}

