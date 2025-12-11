/* eval gcc (pkg-config --cflags guile-3.0) -o fo main.c \
   (pkg-config --libs guile-3.0) */

#include <libguile.h>

struct foo_data {
  int val;
};

static SCM foo_data_type;

void init_foo_data_type (void) {
  SCM name, slots;
  scm_t_struct_finalize finalizer;

  name = scm_from_utf8_symbol ("foo");
  slots = scm_list_1 (scm_from_utf8_symbol("val"));
  finalizer = NULL;

  foo_data_type = scm_make_foreign_object_type (name, slots, finalizer);
}

SCM make_foo_data (SCM input_name, SCM input_val) {
  struct foo_data *my_data;
  my_data = (struct foo_data *)
    scm_gc_malloc (sizeof (struct foo_data), "foo");
  my_data->val = scm_to_int(input_val);
  return scm_make_foreign_object_1(foo_data_type, my_data);
}

SCM get_val_from_foo_data(SCM x) {
  scm_assert_foreign_object_type (foo_data_type, x);

  struct foo_data *my_data;
  my_data = scm_foreign_object_ref (x, 0);
  return scm_from_int(my_data->val);
}

void init_get_val_from_foo_data () {
  scm_c_define_gsubr ("get-val-from-foo-data", 1, 0, 0, get_val_from_foo_data);
}

int main() {
  scm_init_guile();
  init_foo_data_type();
  init_get_val_from_foo_data();
  SCM some_data = make_foo_data(scm_from_utf8_symbol("bar"), scm_from_int(34));
  SCM bim = scm_from_int(42);
  /* scm_eval_string (scm_from_utf8_string ("(display bim)")); */
  /* scm_call_1(scm_variable_ref("display"), bim); */

  SCM func_symbol = scm_c_lookup("display");
  SCM func = scm_variable_ref(func_symbol);
  scm_call_1(func, bim);
}
