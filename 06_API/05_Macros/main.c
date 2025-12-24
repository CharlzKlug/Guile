/* Compile in Fish: */
/*eval gcc -o simple-guile main.c (pkg-config --cflags --libs guile-3.0) */

/* Использование guile-snarf: */
/* eval guile-snarf -o image-type.x main.c (pkg-config --cflags guile-3.0) */
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
#include "image-type.x"
  scm_shell(argc, argv);
}

int main(int argc, char **argv) {
  scm_boot_guile(argc, argv, inner_main, 0);
  return 0; /* never reached */
}
