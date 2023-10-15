#! /usr/bin/env -S guile -l fact.scm -e (fac) -s
!#
(define-module (fac)
  #:export (main))

(define (choose n m)
  (/ (fact m) (* (fact (- m n)) (fact n))))

(define (main args)
  (let ((n (string->number (cadr args)))
	(m (string->number (caddr args))))
    (display (choose n m))
    (newline)))
