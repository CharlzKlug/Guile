/* Compile in Fish: */
/*eval gcc -o simple-tower main.c (pkg-config --cflags --libs guile-3.0) */

#include <libguile.h>
#include <stdlib.h>
#include <stdio.h>

const char* question(SCM input_bool, const char* input_a, const char* input_b) {
  if (scm_is_true(input_bool)) {
    return input_a;
  }
  return input_b;
}

static void inner_main(void *data, int argc, char **argv) {
  scm_init_guile();
  printf("SCM_BOOL_T is integer: %s\n",
         question(scm_integer_p(SCM_BOOL_T), "Yes", "No"));
  printf("SCM(11) is integer: %s\n",
         question(scm_integer_p(scm_from_int(11)), "Yes", "No"));
  printf("SCM_BOOL_T is integer: %d\n", scm_is_integer(SCM_BOOL_T));
  printf("SCM(11) is integer: %d\n", scm_is_integer(scm_from_int(11)));
  printf("Exact integer 37: %s\n",
         question(scm_exact_integer_p(scm_from_int(37)), "Yes", "No"));
  printf("Is 37.1 exact integer? %s\n",
         question(scm_integer_p(scm_from_double(37.1)), "Yes", "No"));
  scm_t_uint8 k2;
  scm_t_int16 k3;
  scm_t_uint16 k4;
  scm_t_int32 k5;
  scm_t_uint32 k6;
  scm_t_int64 k7;
  scm_t_uint64 k8;
  scm_t_intmax k9;
  scm_t_uintmax k10;
  exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
  scm_boot_guile(argc, argv, inner_main, 0);

  return 0; /* never reached */
}
