/* Compile in Fish: */
/*eval gcc -o simple-guile main.c (pkg-config --cflags --libs guile-3.0) */

#include <libguile.h>
#include <stdlib.h>
#include <stdio.h>

static void inner_main(void *data, int argc, char **argv) {
  scm_init_guile();

  if (scm_is_true(SCM_BOOL_T)) {printf("True\n");} else {printf("False\n");}
  if (scm_is_true(SCM_BOOL_F)) {printf("True\n");} else {printf("False\n");}
  if (scm_is_bool(SCM_BOOL_F)) {printf("It is a Bool\n");}
  else {printf("It is not a Bool");}

  if (scm_is_bool(scm_from_int(42))) {printf("It is a Bool\n");}
  else {printf("It is not a Bool\n");}

  SCM func = scm_c_eval_string("(define (foo x) (if x 11 13)) foo");
  printf("Result: %d\n", scm_to_int(scm_call_1(func, scm_from_bool(0))));
  printf("Result: %d\n", scm_to_int(scm_call_1(func, scm_from_bool(1))));

  printf("SCM_BOOL_T to int: %d\n", scm_to_bool(SCM_BOOL_T));
  printf("SCM_BOOL_F to int: %d\n", scm_to_bool(SCM_BOOL_F));

  scm_not(SCM_BOOL_T);
  scm_boolean_p(SCM_BOOL_T);
}

int main(int argc, char **argv) {
  scm_boot_guile(argc, argv, inner_main, 0);
  return 0; /* never reached */
}
