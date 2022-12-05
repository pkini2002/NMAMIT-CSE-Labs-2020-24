test=str(input("Enter the name of the file which you want to manipulate: "))

file = open(test, "r")

number_of_lines = 0
number_of_words = 0
number_of_characters = 0

for line in file:
  line = line.strip("\n")
  words = line.split()
  number_of_lines += 1
  number_of_words += len(words)
  number_of_characters += len(line)

file.close()

print("lines:", number_of_lines, "words:", number_of_words, "characters:", number_of_characters)





