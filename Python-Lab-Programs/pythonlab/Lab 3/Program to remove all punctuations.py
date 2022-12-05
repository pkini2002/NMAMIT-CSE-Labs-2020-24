punctuation = '''''!()-[]{};:'"\,<>./?@#$%^&*_~'''

str = input("Enter a string: ")


def remove_punct(str):
    no_punct = ""
    for char in str:
        if char not in punctuation:
            no_punct = no_punct + char
    return no_punct


no_punct=print("The string after removing punctuations is: ",remove_punct(str))




