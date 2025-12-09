/* eval gcc (pkg-config --cflags guile-3.0) -o dt main.c \
   (pkg-config --libs guile-3.0) */
#include <libguile.h>
#include <stdio.h>

static void do_some_work() {
  printf("Doing some work...\n");
}

SCM my_incrementing_function (SCM a, SCM flag) {
  SCM result;

  if (scm_is_true (flag))
    result = scm_sum (a, scm_from_int (1));
  else
    result = a;

  return result;
}

int main() {
  scm_init_guile();
  while(1) {
    scm_async_tick();
    do_some_work();
  }
}
