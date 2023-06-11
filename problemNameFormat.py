import subprocess

input_str = input("Enter problem name: ")
ext = input("Enter extension: ")
output_str = input_str.replace(" ", "-").replace(".", "")
output_str += ('.' + ext)

# Copy the output string to the clipboard using xclip
subprocess.run(["xclip", "-selection", "clipboard"], input=output_str.encode("utf-8"))

print(output_str)

