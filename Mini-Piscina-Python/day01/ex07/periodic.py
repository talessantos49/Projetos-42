import sys

def periodic_table():
    periodic_text = open('./periodic_table.txt', 'r')
    index_arq = open('periodic_table.html', 'w')
    linhas = periodic_text.read().split('\n')
    parse_function(linhas)

def parse_function(text_read):
    splited = text_read[0].split("=")
    for index in text_read:
        pass
    print(splited)
if __name__ =="__main__":
    periodic_table()
