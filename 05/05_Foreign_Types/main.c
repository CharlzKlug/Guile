/* eval gcc (pkg-config --cflags guile-3.0) -o ft main.c \
   (pkg-config --libs guile-3.0) */
#include <libguile.h>
#include <string.h> // For `memset`.
#include <unistd.h> // For `close`.

struct image {
  int width, height;
  char *pixels;

  /* The name of this image */
  SCM name;

  /* A function to call when this image is
     modified, e.g., to update the screen,
     or SCM_BOOL_F if no action necessary */
  SCM update_func;
};

static SCM image_type;

void init_image_type (void) {
  SCM name, slots;
  scm_t_struct_finalize finalizer;

  name = scm_from_utf8_symbol ("image");
  slots = scm_list_1 (scm_from_utf8_symbol ("data"));
  finalizer = NULL;

  image_type =
    scm_make_foreign_object_type (name, slots, finalizer);
}

SCM make_image (SCM name, SCM s_width, SCM s_height) {
  struct image *image;
  int width = scm_to_int (s_width);
  int height = scm_to_int (s_height);

  /* Allocate the `struct image'. Because we
     use scm_gc_malloc, this memory block will
     be automatically reclaimed when it becomes
     inaccessible, and its member will be traced
     by the garbage collector. */
  image = (struct image *)
    scm_gc_malloc (sizeof (struct image), "image");
  image->width = width;
  image->height = height;

  /* Allocating the pixels with
     scm_gc_malloc_pointerless means that the
     pixels data is collectable by GC, but
     that GC shouldn't spend time tracing its
     contents for nested pointers because there
     aren't any. */
  image->pixels =
    scm_gc_malloc_pointerless (width * height, "image pixels");

  image->name = name;
  image->update_func = SCM_BOOL_F;

  /* Now wrap the struct image* in a new foreign
     object, and return that object. */
  return scm_make_foreign_object_1 (image_type, image);
}

SCM clear_image (SCM image_obj) {
  int area;
  struct image *image;

  scm_assert_foreign_object_type (image_type, image_obj);

  image = scm_foreign_object_ref (image_obj, 0);
  area = image->width * image->height;
  memset (image->pixels, 0, area);

  /* Invoke the image's update function. */
  if (scm_is_true (image->update_func))
    scm_call_0 (image->update_func);

  return SCM_UNSPECIFIED;
}

static SCM file_type;

static void finalize_file (SCM file) {
  int fd = scm_foreign_object_signed_ref (file, 0);
  if (fd >= 0) {
    scm_foreign_object_signed_set_x (file, 0, -1);
    close (fd);
  }
}

static void init_file_type (void) {
  SCM name, slots;
  scm_t_struct_finalize finalizer;

  name = scm_from_utf8_symbol ("file");
  slots = scm_list_1 (scm_from_utf8_symbol ("fd"));
  finalizer = finalize_file;

  image_type = scm_make_foreign_object_type (name, slots, finalizer);
}

static SCM make_file (int fd) {
  return scm_make_foreign_object_1 (file_type, (void *) fd);
}

int main() {
  scm_init_guile();
  init_image_type();
  SCM my_image = make_image(scm_from_utf8_symbol("flower"),
                            scm_from_int(128),
                            scm_from_int(128));
  clear_image(my_image);
}
