import speech_recognition as sr
import subprocess
import os

def get_audio_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening for a command...")
        try:
            audio = recognizer.listen(source)
            command = recognizer.recognize_google(audio).lower()
            print(f"Command received: {command}")
            return command
        except sr.UnknownValueError:
            print("Sorry, I could not understand the audio.")
        except sr.RequestError as e:
            print(f"Could not request results; {e}")
    return None

def is_valid_command(cmd):
    allowed_starts = ["create file", "delete file", "create function", "delete function", "create for loop"]
    return any(cmd.startswith(start) for start in allowed_starts)

def execute_parser():
    parser_path = r"c:\Ronak\CD\project\parser.exe"
    if os.path.exists(parser_path):
        print(f"Executing parser: {parser_path}")
        result = subprocess.run([parser_path], capture_output=True, text=True)
        print("Parser output:\n", result.stdout)
        if result.stderr:
            print("Parser errors:\n", result.stderr)
    else:
        print(f"Error: parser.exe not found at {parser_path}")

def process_for_loop_command(command, current_filename):
    # Example: "add for loop i up to 10 with increment 2"
    parts = command.split()

    try:
        i_index = parts.index("loop") + 1
        up_index = parts.index("up")
        with_index = parts.index("with")
        in_index = parts.index("increment")

        var = parts[i_index]
        limit = int(parts[up_index + 2])
        step = int(parts[in_index + 1])

        if current_filename:
            return f"create for loop {var} up to {limit} with increment {step} in {current_filename}"
        else:
            print("Please set a file first using 'set file to <filename>'.")
            return None
    except (ValueError, IndexError):
        print("Invalid format for 'add for loop' command.")
        return None

def main():
    current_filename = None

    while True:
        command = get_audio_command()
        if command is None:
            continue

        # Handle setting or changing the current file
        if command.startswith("set file to"):
            parts = command.split()
            if len(parts) >= 4:
                current_filename = parts[3]
                print(f"Filename set to: {current_filename}")
            else:
                print("Invalid set file command. Please say 'set file to <filename>'.")
            continue
        elif command == "change file":
            current_filename = None
            print("Filename cleared. Please set a new one.")
            continue
        elif command == "exit":
            print("Exiting the program.")
            break

        # Handle 'add for loop' command separately
        if command.startswith("create for loop"):
            full_command = process_for_loop_command(command, current_filename)
            if full_command:
                with open("command.txt", "w") as f:
                    f.write(full_command)
                    print(f"Command written to command.txt: {full_command}")
                execute_parser()
            continue

        # Auto-append 'in filename' if not present
        if is_valid_command(command):
            if current_filename:
                command = command.split("with")[0].strip()  # Clean trailing noise
                if f"in {current_filename}" not in command and " in " not in command:
                    command += f" in {current_filename}"
            else:
                print("Please set a file first using 'set file to <filename>'.")
                continue

            with open("command.txt", "w") as f:
                f.write(command)
            print(f"Command written to command.txt: {command}")
            execute_parser()
        else:
            print("Invalid or unsupported command. Try again.")

if __name__ == "__main__":
    main()
