def rev(str):
    return str[::-1]


def reverse_str(str):
    if len(str) == 0:
        return str
    else:
        return reverse_str(str[1:])+str[0]


print(rev("moti"))
print(reverse_str("moti"))

str="moti"

print(str[1:])