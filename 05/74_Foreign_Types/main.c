#include <libguile.h>

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

void init_image_type(void) {
  SCM name, slots;
  scm_t_struct_finalize finalizer;

  name = scm_from_utf8_symbol ("image");
  slots = smc_list_1 (scm_from_utf8_symbol ("data"));
  finalizer = NULL;

  image_type = scm_make_foreign_object_type (name, slots, finalizer);
}

SCM make_image(SCM name, SCM s_width, SCM s_height) {
  struct image *image;
  int width = scm_to_int(s_width);
  int height = scm_to_int(s_height);

  /* Allocate the 'struct image'. Because we
     use scm_gc_malloc, this memory block will
     be automatically reclaimed when it becomes
     inaccessible, and its members will be traced
     by the garbage collector. */
  image = (struct image *) scm_gc_malloc(sizeof(struct image), "image");
  image->width = width;
  image->height = height;

  /* Allocating the pixels with
     scm_gc_malloc_pointerless means that the
     pixels data is collectable by GC, but
     that GC shouldn't spend time tracing its
     contents for nested pointers because there
     aren't any. */
  image->pixels = scm_gc_malloc_pointerless(widht * height, "image pixels");

  image->name = name;
  image->update_func = SCM_BOOL_F;

  /* Now wrap the struct image* in a new foreign
     object, and return that object. */
  return scm_make_foreign_object_1(image_type, image);
}
