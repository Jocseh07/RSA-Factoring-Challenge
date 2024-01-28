#!/usr/bin/python3
import sys
"""Get factors of a number."""

    
def factors(num):
  """Get factors."""
  for a in range(2, int(num / 2) + 1):
    if (num % a == 0):
      print("{}={}*{}".format(int(num), int(num / a), int(a)))
  return

def main():
  """Get the function."""
  if len(sys.argv) != 2:
    return
  f = open(sys.argv[1], "r")
  f = f.readlines()
  for num in f:
    num = int(num)
    factors(num)


if __name__ == "__main__":
    main()

