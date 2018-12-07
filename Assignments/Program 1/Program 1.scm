;Corbin Matamoros
;Program will simply create the list ((a 1) (b 2) (c 3))
(define (pairs list1 list2)
  (if (or (null? list1) (null? list2))	;condition to be met
      ()								;if condition met, do this
    (append								;if not condition, then do all this
      (list
        (append
          (list (car list1))
          (list (car list2))
        )
      )
      (pairs (cdr list1) (cdr list2))	;non-tail recursion function call
    )
  )
)

(pairs '(a b c) '(1 2 3))				;function call with two lists as arguments
