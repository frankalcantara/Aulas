def mergesort(var a as array):
    if (n == 1) return a
    var l1 as array = a[0] ... a[n/2]
    var l2 as array = a[n/2+1] ... a[n]

    l1 = mergesort(l1)
    l2 = mergesort(l2)

    return merge(l1, l2)


def merge(vara as array, varb as array):
    var c as array

    while (a and b have elements)
       if (a[0] > b[0])
         add b[0] to the end of c
          remove b[0] from b
        else
         add a[0] to the end of c
          remove a[0] from a
    while (a has elements)
     add a[0] to the end of c
      remove a[0] from a
    while (b has elements)
     add b[0] to the end of c
      remove b[0] from b
    return c


end func