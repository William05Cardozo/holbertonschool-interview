#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your texteditor can execute only
two operations in this file: Copy All and Paste.
Given a number n, write a method
that calculates the fewest number of operations needed to result in exactly n H
characters in the file.

Prototype: def minOperations(n)
Returns an integer
If n is impossible to achieve, return 0
"""


def minOperations(n):
    """
    Program
    """

    if n <= 1:
        return 0
    num, div, numOfOperations = n, 2, 0

    while num > 1:
        if num % div == 0:
            num = num / div
            numOfOperations = numOfOperations + div
        else:
            div += 1
    return numOfOperations
