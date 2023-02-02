import sys

def periodic_table():
    periodic_text = open('./periodic_table.txt', 'r')
    # content = periodic_text.readlines()
    # content = [i.rstrip('\n') for i in content]
    # print(content[0].split(','))
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
                # print(substance[0])
        # print(only_line)
        # print(splited_line)
        
    # periodic_dict = {}
    # for i in range(len(content)):
    #     periodic_dict[content[i][0]] = content[i][1]
    # print(periodic_dict)
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
    index_arq.write(html_template)
    index_arq.write(input_table(substance[0]))
    index_arq.write(html_end)
    index_arq.close()
    
# def input_tabel(substance, nr, small, mol, electron):
def input_table(substance):
    str_table = """<table>
    <tr>
        <td style="border: 1px solid black; padding:10px">
        <h4>""" + substance + """</h4>
        <ul>
            <li>No""" """</li>
            <li>H</li>
            <li>1.00794</li>
            <li>1 electron</li>
        <ul>
        </td>
    </tr>
</table>
"""
    print(str_table)
    return str_table
if __name__ =="__main__":
    periodic_table()
