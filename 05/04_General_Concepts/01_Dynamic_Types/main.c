/* eval gcc (pkg-config --cflags guile-3.0) -o dt main.c \
   (pkg-config --libs guile-3.0) */
#include <libguile.h>
#include <stdio.h>

SCM my_incrementing_function (SCM a, SCM flag) {
  SCM result;

  if (scm_is_true (flag))
    result = scm_sum (a, scm_from_int (1));
  else
    result = a;

  return result;
}

int main() {
  SCM a = scm_from_int(2);
  SCM b = scm_from_bool(1);
  SCM c = my_incrementing_function(a, b);
  int d = scm_to_int(c);
  printf("%d\n", d);
}
