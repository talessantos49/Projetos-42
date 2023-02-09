#!/usr/bin/python3
from local_lib.path import Path


if __name__ =="__main__":
    try:
        Path.mkdir("Path_test")
        archive = open("./Path_test/file", 'w')
        archive.write("FINISH HIM!!!")
        archive.close()
    except:
        archive = open("./Path_test/file", 'w')
        archive.write("FINISH HIM!!!")
        archive.close()
    readed_archive = open("./Path_test/file", 'r').readlines()
    print(readed_archive)