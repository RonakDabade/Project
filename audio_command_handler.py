import tkinter as tk
from tkinter import ttk
import speech_recognition as sr
import threading
import subprocess
import os
from PIL import Image, ImageTk
import io
import base64

# Define microphone and next icons as base64 strings
MIC_ICON = """
iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAYAAABXAvmHAAAACXBIWXMAAAsTAAALEwEAmpwYAAAE6UlEQVR4nO2ZXYhVVRTHf3fGmS8b08YaP8YsKtQHA4ugD6IwIoMeFKIgkB4qJYiiXir6eKigKIKCIKjAEoqgSKIPegh6CLIgEoqgNIpIM7XUJj/Gj5n/sGCdWce1zz1n33vPPSPcP1zmnL3XXv+z9t5rr7UPXOnlrtHA08BBYDSwBOgDCqndrcAE4BAwFXgLGAQKSm8F0As8CIwzfTQBm1S/ALwDNLvjKgIfAw2q/xrQrDoTgfVANeqzgLeBgnw9AFyT9OaAVcAZOVkPtAKzgC9U9jtwK9AFfKd6J4Bb5ONZ4IjKvwTmAjOBXSr7CRgfx/0jcnIcuE6Oi4Ef1eguoCny5rrMHZGzSfL5hsr2KRCXMEuBs3LSJeKpwJAwdmZaB/Qr8xXgXpX3A5fJ7wd6aB6YBexWw23ADJXfAJzWfTs9kJttgNv17wJ9Vr2IrEtYz9cqKgO9kXbVwFWKwFHgCdP2Y+AdtbtgPLk+56sPl0BQSuHqH83KQJ/K+4Gzxt5kxlUF7AQazJgGgMdVfp1C8ZyJyBKn8O06M8eAbhWMNv28oTsxVkHrMWEOYHF8CnhQZVtM3U/UTzlCvE/R6gI2eDxwDHhSdsm8NjbSlrXA+8rBNfK5QfXsKPYCPwP/qmyi6s5ItF6aLYh5OgP8DUwxTt4C9ug+zPCvZk7eFflR3cfpXlFdtwJuR7aZNu6Bbhd+A24GHgEW6PK7Ql1uyJUy9QFsEKGuVP0BYIuxOQO8DJyU0xagTfc2Gnm2IrSifrdqvMEU+RH4RnDsyM4Dbht1A3foOyIUoUbgcfm+XoFLxcYURigLJkbozOHbKc5MlBYA16o9z/53G3C3F2m7iU8rVK9UJJKWLbUvp+9S6ZeDQJofLYXOmL77RGq5EahNGeS5JPElUSzXQE9FqMnUu1N5pF35oaSfUqqBWLkrx0CzVL9Dif0HYKfyxURvGTgKYZF3oBZgFvCBsfdppkycVg5gPAaqCsHZsnISZWO0EsKhbAamBcBdl2vAmhVtxuZ5OcxrfKsRzDhW6+XGYkYeGNRXTZgLgIeU0F3f5xS+PAa2KXGdU9nyf8FAyURoPvCIbLm+d5b71vGVLdpJnDV1F/kG7wPGOVzWJjnRZRvXWpFLI2PtbFFO+EA2eJhT3Jib5j4cuhLRTAbuM5Fz7DYoE28Nla2Wk3sT5Dc6G5Mw64CfZCvoY5TJxt8m3g6jbBLe0LkhjXi9kvoZtR2WbauJfJEa0/e7KWvgR51s00i3qqNB5YHh8mLjpBW4VeVBGG9J6T8gc2Ia8WrTyUhTdpesXSu7qbLvKw/0qrwQlpXSViCNuJ3Jz4Syd1U2MyXK5RL/2dLmZ3sE9UXSIm7lhNm5exRRd7zcaywSC9TeSnK8KRTpLjP3NjpfyK9Vq5n0sCLuNGWdOvOGTrGvIZXYLSVa5Hvk1y2B2wkrVXLCJu5u2YoK0yA5iZf70A6M0YM/VdPiPmMzKHe7EsYrSkL3/Ur9DfSlKlYLXQO8qbBYRXQfvsUb0wPau+19KHEGaFNkS/5lkLg6Fdigu2Kdzg6FaLPs1KXFaKgYp/zR6kSrPf4bIQtaJQvbXU50gFWCrwvh/13w9X+3K6Yl/RoRvgAAAABJRU5ErkJggg==
"""

NEXT_ICON = """
iVBORw0KGgoAAAANSUhEUgAAADAAAAAwCAYAAABXAvmHAAAACXBIWXMAAAsTAAALEwEAmpwYAAACMElEQVR4nO2YPWsUURSGn7uJGjUWaiHEQhQUQVFBsBKDjSAWgp+YVlArC22s/A1ioT9BBRsFK7EQKxVFLBQRQY2iYtCoUZNdc2TecJjM7M7s3J27kPvAYXbvnnPe98y9Z84ZyMnJyWkitVqtTa0z1TvLQEEiJoBBoJiB+O+uYWAW6AdeAAVX8WF1fgF0AOPAcaDVNVhK1IBloA8Yzfii7HRjFHgP9Gr8ytW5C/gEtAMTQHsGF1JEn3gA7AVmgC5X8a3ABNCiFzLqGShF3gIFYBI46Cq+SqXTCjzVzKRpFpbRh+o02uIqvgO4p7FaQiVgQD4eA9uBeeBsigkU12Y+CNuAm8BWXcyuFE6gmLY5qLF+hc0zHbsF9CWcQHPapIuVRUjjV4Aza9wvTZvUVR1C4SDwVeNrgS+uK1Aeb4pZiLIOnAK+A5uAJ0CvQ5z1aZPmVTaOKmwua+xHlNIoRZvUlaQJ7AD+aLwC3F5DnPVpk+iFnJFgJzB5XDyMrKHvZN7hg3YqbN5pbK9mKAxr0yZVHULhmMJmUeN9wJco98vSJvXS2akO/K9N2LK0SfNMtcmeRt1TzXVeZVSftqlLm/SvdQeEzTkZ+i5sqrSLSCGjpROSZZVNnVQTOK2dVHvwhw7s9uCSbsH1gF/HtFKnPLmmD/XLczY262I6gYs6y37V2eaKPNXaJnMZ8Uo/Og7pwM5L2PxSGR2ShyKeT04+PnBV/1NevMzJyTH+AUZzv91t54qMAAAAAElFTkSuQmCC
"""

class VoiceCommandApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Voice Command GUI")
        self.root.geometry("800x600")
        
        # Set up the main window
        self.setup_main_window()
        
        # Set up the modal
        self.setup_modal()
        
        # Initialize voice recognition
        self.recognizer = sr.Recognizer()
        self.is_listening = False
        
        # Current filename for commands
        self.current_filename = None
        
        # Show the modal initially
        self.show_modal()
        
    def setup_main_window(self):
        self.main_frame = tk.Frame(self.root, bg="#f0f0f0")
        self.main_frame.pack(fill=tk.BOTH, expand=True)
        
        # Header
        header_frame = tk.Frame(self.main_frame, bg="#4a6ea9", height=80)
        header_frame.pack(fill=tk.X)
        
        header_label = tk.Label(header_frame, text="Code Generator Voice Assistant", 
                               font=("Arial", 18, "bold"), bg="#4a6ea9", fg="white")
        header_label.pack(pady=20)
        
        # Content area
        self.content_frame = tk.Frame(self.main_frame, bg="white")
        self.content_frame.pack(fill=tk.BOTH, expand=True, padx=20, pady=20)
        
        # Command history display
        self.history_frame = tk.Frame(self.content_frame, bg="white")
        self.history_frame.pack(fill=tk.BOTH, expand=True)
        
        history_label = tk.Label(self.history_frame, text="Command History:", 
                                font=("Arial", 12, "bold"), bg="white", anchor="w")
        history_label.pack(fill=tk.X, pady=(0, 10))
        
        # Scrollable text area for command history
        self.history_text = tk.Text(self.history_frame, height=20, width=70, 
                                   bg="#f9f9f9", font=("Consolas", 10))
        self.history_text.pack(fill=tk.BOTH, expand=True, side=tk.LEFT)
        
        # Scrollbar for history text
        scrollbar = ttk.Scrollbar(self.history_frame, command=self.history_text.yview)
        scrollbar.pack(fill=tk.Y, side=tk.RIGHT)
        self.history_text.config(yscrollcommand=scrollbar.set)
        
        # Display initial help info
        self.display_help()
        
    def setup_modal(self):
        # Create modal frame that will slide up from bottom
        self.modal_frame = tk.Frame(self.root, bg="#e0e0e0", height=120)
        
        # Create a frame for the content of the modal
        modal_content = tk.Frame(self.modal_frame, bg="#e0e0e0", padx=20, pady=20)
        modal_content.pack(fill=tk.BOTH, expand=True)
        
        # Input field with label
        input_frame = tk.Frame(modal_content, bg="#e0e0e0")
        input_frame.pack(fill=tk.X, pady=10)
        
        cmd_label = tk.Label(input_frame, text="Command:", font=("Arial", 10), bg="#e0e0e0")
        cmd_label.pack(side=tk.LEFT, padx=(0, 10))
        
        self.command_entry = tk.Entry(input_frame, font=("Arial", 10), width=50)
        self.command_entry.pack(side=tk.LEFT, fill=tk.X, expand=True)
        self.command_entry.bind("<Return>", self.process_command)
        
        # Button frame for voice and process buttons
        button_frame = tk.Frame(modal_content, bg="#e0e0e0")
        button_frame.pack(fill=tk.X, pady=(10, 0))
        
        # Voice button with microphone icon
        self.mic_icon_data = base64.b64decode(MIC_ICON)
        self.mic_image = ImageTk.PhotoImage(data=self.mic_icon_data)
        
        self.voice_button = tk.Button(button_frame, image=self.mic_image, 
                                     command=self.toggle_voice_recognition,
                                     bg="#e0e0e0", relief=tk.RAISED,
                                     width=40, height=40, bd=1)
        self.voice_button.pack(side=tk.LEFT, padx=(0, 10))
        
        # Process button with next icon
        self.next_icon_data = base64.b64decode(NEXT_ICON)
        self.next_image = ImageTk.PhotoImage(data=self.next_icon_data)
        
        self.process_button = tk.Button(button_frame, image=self.next_image,
                                       command=self.process_command,
                                       bg="#e0e0e0", relief=tk.RAISED,
                                       width=40, height=40, bd=1)
        self.process_button.pack(side=tk.LEFT)
        
        # Help button
        self.help_button = tk.Button(button_frame, text="Help", 
                                    command=self.display_help,
                                    bg="#e0e0e0", font=("Arial", 10),
                                    width=8, height=2)
        self.help_button.pack(side=tk.RIGHT, padx=(10, 0))
        
        # File info display
        self.file_info = tk.Label(modal_content, text="Current file: None", 
                                 font=("Arial", 9), bg="#e0e0e0", fg="#555555")
        self.file_info.pack(side=tk.LEFT, pady=(10, 0))
        
    def show_modal(self):
        # Position the modal initially below the screen
        screen_height = self.root.winfo_height()
        self.modal_frame.place(x=0, y=screen_height, width=self.root.winfo_width(), height=120)
        
        # Animate the modal sliding up
        self.animate_modal_up()
        
    def animate_modal_up(self, current_y=None):
        if current_y is None:
            current_y = self.root.winfo_height()
            
        target_y = self.root.winfo_height() - 120
        
        if current_y > target_y:
            # Move the modal up
            new_y = max(current_y - 10, target_y)
            self.modal_frame.place(x=0, y=new_y, width=self.root.winfo_width(), height=120)
            
            # Schedule the next animation step
            self.root.after(10, lambda: self.animate_modal_up(new_y))
    
    def toggle_voice_recognition(self):
        if self.is_listening:
            # Stop listening
            self.is_listening = False
            self.voice_button.config(relief=tk.RAISED)
            self.add_to_history("Voice recognition stopped.")
        else:
            # Start listening in a separate thread
            self.is_listening = True
            self.voice_button.config(relief=tk.SUNKEN)
            self.add_to_history("Listening for voice command...")
            
            # Start listening in a separate thread
            thread = threading.Thread(target=self.listen_for_command)
            thread.daemon = True
            thread.start()
    
    def listen_for_command(self):
        try:
            with sr.Microphone() as source:
                self.recognizer.adjust_for_ambient_noise(source)
                audio = self.recognizer.listen(source, timeout=5, phrase_time_limit=10)
                
                try:
                    command = self.recognizer.recognize_google(audio).lower()
                    self.command_entry.delete(0, tk.END)
                    self.command_entry.insert(0, command)
                    
                    # Reset the voice button state
                    self.root.after(0, lambda: self.voice_button.config(relief=tk.RAISED))
                    self.is_listening = False
                    
                    self.add_to_history(f"Voice command recognized: {command}")
                    
                except sr.UnknownValueError:
                    self.add_to_history("Sorry, I could not understand the audio.")
                except sr.RequestError as e:
                    self.add_to_history(f"Could not request results; {e}")
                
        except Exception as e:
            self.add_to_history(f"Error: {e}")
            
        # Reset button state if we exit due to an exception
        self.root.after(0, lambda: self.voice_button.config(relief=tk.RAISED))
        self.is_listening = False
    
    def process_command(self, event=None):
        command = self.command_entry.get().strip().lower()
        
        if not command:
            return
            
        self.add_to_history(f"> {command}")
        
        # Handle special commands
        if command == "exit":
            self.root.quit()
            return
        elif command == "help":
            self.display_help()
            return
            
        # Handle "set file to" command
        if command.startswith("set file to"):
            parts = command.split()
            if len(parts) >= 4:
                self.current_filename = parts[3] + ".c"
                self.file_info.config(text=f"Current file: {self.current_filename}")
                self.add_to_history(f"Current file set to: {self.current_filename}")
            else:
                self.add_to_history("Invalid set file command. Please use 'set file to <filename>'.")
            return
            
        # Process the command using the existing processing functions
        try:
            # This is where you would integrate with your existing command processing code
            self.add_to_history(f"Processing command: {command}")
            
            # Write the command to command.txt
            with open("command.txt", "w") as f:
                f.write(command)
                
            self.add_to_history(f"Command written to command.txt: {command}")
            
            # Execute the parser
            self.execute_parser()
            
        except Exception as e:
            self.add_to_history(f"Error processing command: {e}")
            
        # Clear the command entry
        self.command_entry.delete(0, tk.END)
    
    def execute_parser(self):
        parser_path = os.path.join(os.getcwd(), "parser.exe")
        if os.path.exists(parser_path):
            self.add_to_history(f"Executing parser: {parser_path}")
            
            try:
                result = subprocess.run([parser_path], capture_output=True, text=True)
                self.add_to_history("Parser output:")
                self.add_to_history(result.stdout)
                
                if result.stderr:
                    self.add_to_history("Parser errors:")
                    self.add_to_history(result.stderr)
            except Exception as e:
                self.add_to_history(f"Error executing parser: {e}")
        else:
            self.add_to_history(f"Error: parser.exe not found at {parser_path}")
            self.add_to_history(f"Current directory: {os.getcwd()}")
            self.add_to_history("Please ensure the parser executable is in the current directory.")
    
    def add_to_history(self, text):
        self.history_text.config(state=tk.NORMAL)
        self.history_text.insert(tk.END, text + "\n")
        self.history_text.see(tk.END)
        self.history_text.config(state=tk.DISABLED)
    
    def display_help(self):
        help_text = """
Available commands:
- set file to <filename>
- create file <filename>
- create file <filename> with <count> functions <func1> <func2> ... <funcN>
- delete file <filename>
- create function <name>
- delete function <name>
- create for loop <var> up to <limit> with increment <step> in <function>
- create if <var> <operator> <value> in <function>
- create if <var> <operator> <value> else in <function>
- create switch <var> conditions with <number> cases in <function>
- create case <value>
- create default
- create break
- close brace
- create array <name> from <start> to <end> in <function>
- create iterate array <name> using index <var> in <function>
- optimize [file]
- help (show this help menu)
- exit

Note: After using 'set file to <filename>', you don't need to specify the filename in commands
"""
        self.history_text.config(state=tk.NORMAL)
        self.history_text.delete(1.0, tk.END)
        self.history_text.insert(tk.END, help_text)
        self.history_text.config(state=tk.DISABLED)

if __name__ == "__main__":
    root = tk.Tk()
    app = VoiceCommandApp(root)
    root.mainloop()

