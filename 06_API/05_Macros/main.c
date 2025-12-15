/* Compile in Fish: */
/* eval gcc -o simple-guile simple-guile.c (pkg-config --cflags --libs
 * guile-3.0) */

/* Использование guile-snarf: */
/* eval guile-snarf (pkg-config --cflags guile-3.0) -o image-type.x main.c */
#include <libguile.h>
#include <stdlib.h>

SCM_DEFINE(my_add, "my-add", 2, 0, 0,
           (SCM a, SCM b),
           "Return the sum of A and B."
           )
{
  return scm_sum(a, b);
}

static void inner_main(void *data, int argc, char **argv) {
  /* scm_c_define_gsubr("my-hostname", 0, 0, 0, my_hostname); */
  /* #include "image-type.x" */
  scm_shell(argc, argv);
}

int main(int argc, char **argv) {
  scm_boot_guile(argc, argv, inner_main, 0);
  return 0; /* never reached */
}
