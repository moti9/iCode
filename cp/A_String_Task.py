
def petyas_program(input_string):
    vowels = "AEIOUYaeiouy"
    result = ""

    for char in input_string:
        if char not in vowels:
            result += "." + char.lower()

    print(result)

if __name__ == "__main__":
    s = input()
    petyas_program(s)
    
