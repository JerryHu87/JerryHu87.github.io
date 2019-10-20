#CCC 2015 problem 1
list = []
average = 0
numbers = input("")
for listnumber in range(numbers):
  stats = input("")
  if stats > 0:
    list.append(stats)
  elif stats == 0:
    list.pop()
for i in range(len(list)):
  average = average + list[i]
print average
