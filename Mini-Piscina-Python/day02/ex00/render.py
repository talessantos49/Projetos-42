#!/usr/bin/python3
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
    settings_archive.close()
    return (mydict)

def replace_keys():
    archive_name = sys.argv[1].split('.')
    archive_name = archive_name[0] + ".html"
    mydict = read_archive()
    new_file = open(archive_name, "w" )
    template_file = open(sys.argv[1], 'r').read()
    for key, value in mydict.items():
        template_file = template_file.replace("{" + key + "}", value)
    new_file.write(template_file)
    new_file.close()

if __name__ =="__main__":
    replace_keys()
