> (define (count-zeros lst)
  (cond
    ((null? lst) 0)
    ((= (car lst) 0) (+ 1 (count-zeros (cdr lst))))
    (else (count-zeros (cdr lst)))))
