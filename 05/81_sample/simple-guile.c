/* simple-guile.c --- Start Guile from C. */
/* nix-shell -p pkg-config guile_3_0 */
/* How to compile : gcc simple-guile.c `pkg-config guile-3.0 --cflags --libs` */
#include <libguile.h>

static void inner_main(void *closure, int argc, char **argv) {
  /* preparation */
  scm_shell(argc, argv);
  /* after exit */
}

int main(int argc, char** argv) {
  scm_boot_guile(argc, argv, inner_main, 0);
  return 0;
}
