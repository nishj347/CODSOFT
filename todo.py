import tkinter as tk
from tkinter import messagebox
import random

quotes = [
    "The best way to get started is to quit talking and begin doing.",
    "Don't let yesterday take up too much of today.",
    "It's not whether you get knocked down, it's whether you get up.",
    "We may encounter many defeats but we must not be defeated.",
    "Whether you think you can or think you can't, you're right.",
]
tasks = []

def updatetask():
    task_listbox.delete(0, tk.END)  
    for task in tasks:
        task_listbox.insert(tk.END, task)  
def add_task():
    task = task_entry.get()
    if task != "":
        tasks.append(task)
        updatetask()
        task_entry.delete(0, tk.END)  
    else:
        messagebox.showwarning("DUDE","Add a task :)")
def remove_task():
    try:
        task_index = task_listbox.curselection()[0]
        del tasks[task_index]
        updatetask()
    except:
        messagebox.showwarning("ERROR","add a task to remove ^-^")
def save_tasks():
    with open("tasks.txt", "w") as file:
        for task in tasks:
            file.write(f"{task}\n")
    messagebox.showinfo("SAVED","Tasks saved to file")
def showquote():
    selected_quote = random.choice(quotes)
    quote_label.config(text=selected_quote)

# main window
root = tk.Tk()
root.title("Personal To-Do List")

quote_frame = tk.Frame(root)
quote_frame.pack(pady=5)

# Label to display the quote at the top
quote_label = tk.Label(quote_frame, text="", font=("Arial",8), wraplength=400, justify="center")
quote_label.pack(pady=5)


showquote()

task_entry = tk.Entry(root, width=40) #width=40 is the number of characters it can display at once
task_entry.pack(pady=10)  #pady=10 is the spacing in which first and second task will be shown

add_button = tk.Button(root, text="Add Task", width=40, command=add_task)
add_button.pack(pady=5)

task_listbox = tk.Listbox(root, width=40, height=10)
task_listbox.pack(pady=10)

remove_button = tk.Button(root, text="Remove Selected Task", width=40, command=remove_task)
remove_button.pack(pady=5)

save_button = tk.Button(root, text="Save Tasks", width=40, command=save_tasks)
save_button.pack(pady=5)

root.mainloop()


