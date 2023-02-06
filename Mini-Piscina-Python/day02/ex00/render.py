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
    html_header = """<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
    """

    if "tittle" in mydict:
        html_header += f"""\t<title>{mydict["tittle"]}</title>"""

    html_mid ="""
    </head>
    <body>"""
    if "name" in mydict:
        html_mid += f"""\n\t\t<p>Name : {mydict["name"]}</p>"""
    if "surname" in mydict:
        html_mid += f"""\n\t\t<p>Surname : {mydict["surname"]}</p>"""
    if "age" in mydict:
        html_mid += f"""\n\t\t<p>Age : {mydict["age"]}</p>"""
    if "profession" in mydict:
        html_mid += f"""\n\t\t<p>Profession :{mydict["profession"]}</p>"""
    html_end = """\n\t</body>
</html> """
    html_complete = html_header + html_mid + html_end
    new_archive.write(html_complete)
    return (html_complete)

if __name__ =="__main__":
    html_template()
