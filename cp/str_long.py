def StringChallenge(sen):
    words = sen.split()
    longest_word = max(words, key=lambda x: (len([c for c in x if c.isalnum()]), len(x)), default="")
    return longest_word


input_string = input()
result = StringChallenge(input_string)
print(result)
