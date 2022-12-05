# Count number of vowels in a given string
count = 0
sen = str(input("Enter a string:"))

for i in range(len(sen)):
    if sen[i] == 'a' or sen[i] == 'e' or sen[i] == 'i' or sen[i] == 'o' or sen[i] == 'u':
        count = count + 1

    if sen[i] == 'A' or sen[i] == 'E' or sen[i] == 'I' or sen[i] == 'O' or sen[i] == 'U':
        count = count + 1
print(count)