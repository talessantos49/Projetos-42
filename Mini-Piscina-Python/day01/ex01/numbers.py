
def numbers():
    file = open("numbers.txt", "r")
    file_string = file.read()
    print(file_string.replace("," , "\n").rstrip('\n'))
    file.close()

if __name__ =="__main__":
    numbers()
