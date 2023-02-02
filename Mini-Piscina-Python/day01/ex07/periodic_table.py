import sys

def periodic_table():
    periodic_text = open('./periodic_table.txt', 'r')
    only_line = periodic_text.readline().rstrip('\n')
    # print(only_line)
    splited_line = only_line.split(',')
    # print(splited_line)
    if splited_line != '':
        substance = splited_line[0].split()
        # print(substance[0])
    while only_line != '':
        only_line = periodic_text.readline().rstrip('\n')
        splited_line = only_line.split(',')
        if splited_line != '':
            substance = splited_line[0].split()
            if substance :
                pass
                # print(substance[0])
        # print(only_line)
        # print(splited_line)
    index_arq = open('periodic_table.html', 'w')
    html_template = """<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Periodic Table</title>
        <style>
            table, th, td
            {
                border-width: 1px;
                border-style: solid;
                border-collapse:collapse;
            }
        </style>
    </head>
    <body>
"""
    html_end="""    </body>
</html>
""" 
    # string_substance = substance[0]
    string_concatenade = html_template + html_end
    index_arq.write(string_concatenade)
    index_arq.close()
    
# def input_tabel(substance, nr, small, mol, electron):
# def input_table (substance):
#     str_table = substance[0]
#     print(str_table)
#     return str_table

if __name__ =="__main__":
    periodic_table()
