#include "ft_ls.h"

void		ft_putchar(char c)
{
  write(1, &c, 1);
}

void		ft_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      ft_putchar(str[i]);
      i++;
    }
}

void		ft_showargs(int argc, char **argv, t_arglist *arglist)
{
  ft_putstr("\nNom Du Programme : [");
  ft_putstr(argv[0]);
  ft_putstr("]\n\nNombre D'arguments : [");
  ft_putchar((char)(argc + '0'));
  ft_putstr("]\n\nListe des arguments :\n");
  int i = 1;
  while (i < argc)
    {
      ft_putstr(" - [");
      ft_putstr(argv[i]);
      ft_putstr("]\n");
      i++;
    }
  ft_putstr("\n\n");
  ft_putstr("Parsing des arguments :\n");
  ft_putstr("arg_l : ");
  ft_putchar((*arglist).arg_l + '0');
  ft_putchar('\n');
  ft_putstr("arg_R : ");
  ft_putchar((*arglist).arg_R + '0');
  ft_putchar('\n');
  ft_putstr("arg_a : ");
  ft_putchar((*arglist).arg_a + '0');
  ft_putchar('\n');
  ft_putstr("arg_r : ");
  ft_putchar((*arglist).arg_r + '0');
  ft_putchar('\n');
  ft_putstr("arg_t : ");
  ft_putchar((*arglist).arg_t + '0');
  ft_putchar('\n');
}

int	ft_srtlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	parse_cmd(int argc, char **argv, t_arglist *arglist)
{
  int		i;
  int		j;

  i = 1;
  j = 0;
  while (i < argc)
    {
      if (j > 0 && argv[i][0] == '-')
	{
	  if (argv[i][j] == 'l')
	    (*arglist).arg_l = 1;
	  if (argv[i][j] == 'R')
	    (*arglist).arg_R = 1;
	  if (argv[i][j] == 'a')
	    (*arglist).arg_a = 1;
	  if (argv[i][j] == 'r')
	    (*arglist).arg_r = 1;
	  if (argv[i][j] == 't')
	    (*arglist).arg_t = 1;
	}
      if (argv[i][j] == '\0')
	{
	  j = 0;
	  i++;
	}
      else
	j++;
    }
  ft_showargs(argc, argv, arglist);
}


/* fonction à virer plus tard, initialiser les variables
dans la déclaration de structure de ft_ls.h */
void	initialize_arglist(t_arglist *arglist)
{
  (*arglist).arg_l = 0;
  (*arglist).arg_R = 0;
  (*arglist).arg_a = 0;
  (*arglist).arg_r = 0;
  (*arglist).arg_t = 0;
}

int		main(int argc, char **argv)
{
  t_arglist arglist;

  initialize_arglist(&arglist);
  parse_cmd(argc, argv, &arglist);
  /*  ft_opendir(arglist); */
  return (0);
}
