#!/usr/bin/env python3
"""
LeetCode filename generator with cross-platform clipboard support using pyperclip.
Install: pip install pyperclip
"""

try:
    import pyperclip
except ImportError:
    print("Error: pyperclip not installed.")
    print("Install with: pip install pyperclip")
    exit(1)

def main():
    input_str = input("Enter problem name: ")
    ext = input("Enter extension: ")
    
    # Generate formatted filename
    output_str = "LC" + input_str.replace(" ", "-").replace(".", "")
    output_str += ('.' + ext)
    
    print(f"Generated filename: {output_str}")
    
    try:
        pyperclip.copy(output_str)
        print("✓ Copied to clipboard")
    except Exception as e:
        print(f"Error copying to clipboard: {e}")

if __name__ == "__main__":
    main()
