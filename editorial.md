# Ladue CS Challenge


Thanks for participating in the Ladue CS Challenge! Most of the problems were created by Anthony, while a few were inspired by ideas from Darren.


## A

An easy but tedious way is to list all the numbers from 1 to 64 out in binary by hand and count the numbers with more ones than zeros.

You can also write a program, although I think it's faster to just list them out by hand.

This was an ACSL problem from a few years ago.


## B

Write a program like the sample code in `test.py`. You don't want to do this one by hand!

This problem was actually inspired by a famous problem called the [Collatz conjecture](https://en.wikipedia.org/wiki/Collatz_conjecture). It has been called "an extraordinarily difficult problem, completely out of reach of present day mathematics." 


## C

Do it by hand, and make sure you check your work!

This is another old ACSL problem.


## D

You can write a program to extract the characters at prime indices. Then, you can consult either the internet or the RNG presentation to get the answer.

If you're interested in how I made this problem or how to solve it, check out `encoder.cpp`. This problem was suggested by Darren.


## E

You can use a diff checker like [diffchecker.com](https://www.diffchecker.com/) or the `diff` command in your terminal. Compare `E.py` and the code on [Repl.it](https://repl.it/@Ta180m/2048#main.py).

This problem was inspired by something suggested by Darren.


## F

Right click, and view source. Ctrl-F for "answer" and you'll see it!

If you're interested in how I made this problem, look at `generator.cpp`. I used GitHub Pages to host the website.


## G

If you open it with a text editor, you'll get a bunch of ASCII ones and zeros. If you zoom out far enough or make the font size very small, you'll see the answer!

I first made an image using GIMP, then used an [Image to Ascii Art Converter](https://cloudapps.herokuapp.com/imagetoascii/) to convert it to text, then blew it up with `blow-up.cpp`.


## H

You need a bit of math for this one. Consult [GeeksforGeeks](https://www.geeksforgeeks.org/find-the-k-th-permutation-sequence-of-first-n-natural-numbers/) or my code `gen.cpp` for this one!

This was inspired by a problem from USACO Camp.


## I

The hardest problem. It's from [LeetCode](https://leetcode.com/problems/poor-pigs/), although I wrote my own grader for it.

You can see the original grader in `test.cpp` and the obfuscated version is `ob.cpp`. I used [this](https://picheta.me/obfuscator) to obfuscate the code, although it couldn't handle C++ strings very well, so I had to manually do some parts.


## J

Use [this](http://www.nmichaels.org/rsa.py) to decrypt the RSA ciphertext. Then, brute-force the number of digits to open the password-protected zip.

This problem was the easiest once you had all the hints from the previous problems.

