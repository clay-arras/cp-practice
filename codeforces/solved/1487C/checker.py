for _ in ' ' * int(input()):
  n = int(input()) - 1
  for i in range(n):
    oc = min(n - i, n // 2)
    print('1 ' * oc + '0 ' * (n % 2 and i <= n // 2) + '-1 ' * (n - n % 2 - oc - i), end='')
  print()
