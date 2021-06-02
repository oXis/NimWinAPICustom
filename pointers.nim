## :Author: Kaushal Modi
## :License: MIT
##
## Introduction
## ============
## This module implements basic Pointer Arithmetic functions.
##
## Source
## ======
## `Repo link <https://github.com/kaushalmodi/ptr_math>`_
##
## The code in this module is mostly from `this code snippet <https://forum.nim-lang.org/t/1188#7366>`_ on Nim Forum.

template ptrMath*(body: untyped) =
  ## Enclosure to contain the pointer arithmetic expressions.
  runnableExamples:
    var
      a: array[0 .. 3, int]
      p = addr(a[0])        # p is pointing to a[0]

    for i, _ in a:
      a[i] += i

    ptrMath:
      p += 1                  # p is now pointing to a[1]
      p[] = 100               # p[] is accessing the contents of a[1]
      doAssert a[1] == 100

      p[0] = 200              # .. so does p[0]
      doAssert a[1] == 200

      p[1] -= 2               # p[1] is accessing the contents of a[2]
      doAssert a[2] == 0

      p[2] += 50              # p[2] is accessing the contents of a[3]
      doAssert a[3] == 53

      p += 2                  # p is now pointing to a[3]
      p[-1] += 77             # p[-1] is accessing the contents of a[2]
      doAssert a[2] == 77
    doAssert a == [0, 200, 77, 53]
  ##
  template `+`[T](p: ptr T, offset: int): ptr T =
    ## Increments pointer `p` by `offset` that jumps memory in increments of
    ## the size of `T`.
    ## This can be used only within the `ptrMath:` template.
    runnableExamples:
      type
        MyObject = object
          i: int
          f: float
          b: bool
      var
        a = [MyObject(i: 100, f: 2.3, b: true),
             MyObject(i: 300, f: 4.5, b: false),
             MyObject(i: 500, f: 6.7, b: true)]
        p = addr(a[0])

      ptrMath:
        var
          p2 = p + 2
        doAssert p2[0].i == 500
        doAssert p2[-1].f == 4.5
    ##
    cast[ptr T](cast[ByteAddress](p) +% (offset * sizeof(T)))
    #                               `+%` treats x and y inputs as unsigned
    # and adds them: https://nim-lang.github.io/Nim/system.html#%2B%25%2Cint%2Cint

  template `-`[T](p: ptr T, offset: int): ptr T =
    ## Decrements pointer `p` by `offset` that jumps memory in increments of
    ## the size of `T`.
    ## This can be used only within the `ptrMath:` template.
    runnableExamples:
      type
        MyObject = object
          i: int
          f: float
          b: bool
      var
        a = [MyObject(i: 100, f: 2.3, b: true),
             MyObject(i: 300, f: 4.5, b: false),
             MyObject(i: 500, f: 6.7, b: true)]
        p = addr(a[2])

      ptrMath:
        var
          p1 = p - 1
        doAssert p1[0].i == 300
        doAssert p1[-1].b == true
        doAssert p1[1].f == 6.7
    ##
    cast[ptr T](cast[ByteAddress](p) -% (offset * sizeof(T)))

  template `[]`[T](p: ptr T, offset: int): T =
    ## Retrieves the value from `p[offset]`.
    ## This can be used only within the `ptrMath:` template.
    runnableExamples:
      var
        a = [1, 3, 5, 7]
        p = addr(a[0])

      ptrMath:
        doAssert p[] == a[0]
        doAssert p[0] == a[0]
        doAssert p[2] == a[2]
    ##
    (p + offset)[]

  template `[]=`[T](p: ptr T, offset: int, val: T) =
    ## Assigns the value at memory location pointed by `p[offset]`.
    ## This can be used only within the `ptrMath:` template.
    runnableExamples:
      var
        a = [1.3, -9.5, 100.0]
        p = addr(a[1])

      ptrMath:
        p[0] = 123.456
        doAssert a[1] == 123.456
    ##
    (p + offset)[] = val

  template `+=`[T](p: ptr T, offset: int) =
    ## Increments pointer `p` *in place* by `offset` that jumps memory
    ## in increments of the size of `T`.
    ## This can be used only within the `ptrMath:` template.
    runnableExamples:
      type
        MyObject = object
          i: int
          f: float
          b: bool
      var
        a = [MyObject(i: 100, f: 2.3, b: true),
             MyObject(i: 300, f: 4.5, b: false),
             MyObject(i: 500, f: 6.7, b: true)]
        p = addr(a[0])

      ptrMath:
        p += 1
        doAssert p[].i == 300
    ##
    p = p + offset

  template `-=`[T](p: ptr T, offset: int) =
    ## Decrements pointer `p` *in place* by `offset` that jumps memory
    ## in increments of the size of `T`.
    ## This can be used only within the `ptrMath:` template.
    runnableExamples:
      type
        MyObject = object
          i: int
          f: float
          b: bool
      var
        a = [MyObject(i: 100, f: 2.3, b: true),
             MyObject(i: 300, f: 4.5, b: false),
             MyObject(i: 500, f: 6.7, b: true)]
        p = addr(a[2])

      ptrMath:
        p -= 2
        doAssert p[].f == 2.3
    ##
    p = p - offset

  body
