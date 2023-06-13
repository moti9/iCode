import subprocess

input_str = input("Enter problem name: ")
ext = input("Enter extension: ")
output_str = input_str.replace(" ", "-").replace(".", "")
choice = input("Enter choice - DP(1,2,3,4)")
if choice == "1":
    output_str += "-RecursiveApproach"
elif choice == "2":
    output_str += "-Memoization"
elif choice == "3":
    output_str += "-IterativeDP"
elif choice == "4":
    output_str += "-SpaceOptimized"
else:
    pass
output_str += ('.' + ext)

# Copy the output string to the clipboard using xclip
subprocess.run(["xclip", "-selection", "clipboard"], input=output_str.encode("utf-8"))

print(output_str)

