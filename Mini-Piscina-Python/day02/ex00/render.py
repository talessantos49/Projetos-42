import sys, os, re

def arguments_validator():
    if len(sys.argv) == 2:
        extension = sys.argv[1].split('.')
        template = "template"
        if extension[-1] != template:
            print("Error: invalid archive extensions !")
            return (1)
        else:
            return (0)
    elif len(sys.argv) < 2:
        print("Error: Too few, arguments!")
        return(1)
    else:
        print("Error: Too many, arguments!")
        return(1)

def read_archive():
    if arguments_validator() == 1 :
        exit(0)
    settings_archive = open("./settings.py", 'r')
    settings_text = settings_archive.readlines()
    mydict= {}
    for key in settings_text :
        mydict[key.split("=")[0].strip()] = key.split("=")[1].strip().strip("\"")
    return (mydict)

def html_template():
    mydict = read_archive()
    new_archive = open("file.html", 'w')

    html_init = f"""<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
"""
    html_mid = f"""
        <title>{mydict["pageTittle"]}</title>
    </head>
    <body>
        <p>Name : {mydict["name"]}</p>
        <p>Surname : {mydict["surname"]}</p>
        <p>Age : {mydict["age"]}</p>
        <p>Profession :{mydict["profession"]}</p>
    </body>
</html> """
    html_complete = html_init + html_mid
    new_archive.write(html_complete)
    return (html_complete)

html_template()