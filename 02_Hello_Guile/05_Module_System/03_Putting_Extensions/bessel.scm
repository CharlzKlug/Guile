;; Файл bessel.scm следует положить в /usr/share/guile/site/3.0/math/bessel.scm,
;; а файл libguile-bessel.so в /usr/local/lib/libguile-bessel.so
(define-module (math bessel)
  #:export (j0))

(load-extension "libguile-bessel" "init_bessel")
