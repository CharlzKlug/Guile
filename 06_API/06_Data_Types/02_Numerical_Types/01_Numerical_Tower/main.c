/* Compile in Fish: */
/*eval gcc -o simple-tower main.c (pkg-config --cflags --libs guile-3.0) */

#include <libguile.h>
#include <stdlib.h>
#include <stdio.h>

static void inner_main(void *data, int argc, char **argv) {
  scm_init_guile();
  SCM pred = scm_number_p(SCM_BOOL_T);
  SCM func = scm_c_eval_string("(define (foo x) (display x)"
                               "(display \"\n\")) foo");
  scm_call_1(func, pred);

  printf("Is scm_from_int(1) a number?:%d\n", scm_is_number(scm_from_int(1)));
  printf("Is SCM_BOOL_T a number?:%d\n", scm_is_number(SCM_BOOL_T));
}

int main(int argc, char **argv) {
  scm_boot_guile(argc, argv, inner_main, 0);
  return 0; /* never reached */
}
