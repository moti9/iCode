import subprocess
import platform
import sys

def copy_to_clipboard(text):
    """Copy text to clipboard across different operating systems."""
    system = platform.system()
    
    try:
        if system == "Darwin":  # macOS
            subprocess.run(["pbcopy"], input=text.encode("utf-8"), check=True)
        elif system == "Linux":
            subprocess.run(["xclip", "-selection", "clipboard"], input=text.encode("utf-8"), check=True)
        elif system == "Windows":
            subprocess.run(["clip"], input=text.encode("utf-8"), shell=True, check=True)
        else:
            print(f"Clipboard copying not supported on {system}")
            return False
        
        print("✓ Copied to clipboard")
        return True
        
    except subprocess.CalledProcessError:
        print(f"Error: Clipboard tool not available on {system}")
        return False
    except FileNotFoundError:
        print(f"Error: Required clipboard tool not found on {system}")
        if system == "Linux":
            print("Install xclip: sudo apt-get install xclip")
        return False

def main():
    input_str = input("Enter problem name: ")
    ext = input("Enter extension: ")
    
    # Generate formatted filename
    output_str = "LC" + input_str.replace(" ", "").replace(".", "")
    output_str += ('.' + ext)
    
    print(f"Generated filename: {output_str}")
    
    # Try to copy to clipboard
    copy_to_clipboard(output_str)

if __name__ == "__main__":
    main()

