import pyperclip


input_str = input("Enter problem name : ")
ext = input("Enter extenstion : ")
output_str = "LC" + input_str.replace(" ", "-").replace(".", "")
output_str += ('.'+ext)
pyperclip.copy(output_str)
print(output_str)
