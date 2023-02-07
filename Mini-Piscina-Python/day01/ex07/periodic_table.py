import sys

def read_and_convert(periodic_text):
    only_line = periodic_text.readline().rstrip('\n')
    if only_line != '':
        splited_line = only_line.split(',')
        number = splited_line[1].split(':')
        number = number[1]
        small = splited_line[2].split(':')
        small = small[1]
        molar = splited_line[3].split(':')
        molar = molar[1]
        electron = splited_line[4].split(':')
        electron = electron[1]
        position = splited_line[0].split(':')
        position = int(position[1])
        substance = splited_line[0].split()
        substance = substance[0]
        returned_list = [substance, position, number, small, molar, electron]
        return (returned_list)
    else: return

def input_table(line_listed):
    str_table = """\t
        <td style="border: 1px solid black; padding:10px">
        \t<h4>""" + line_listed[0] + """</h4>
        \t<ul>
            \t\t<li>No """+ str(line_listed[1]) +""" </li>
            \t\t<li> """ + line_listed[2] + """ </li>
            \t\t<li>""" + line_listed[3] + """ </li>
            \t\t<li> """ + line_listed[4] + """ </li>
            \t\t<li> """ + line_listed[5] + """ electron</li>
        \t</ul>
        \t</td>
    """
    return(str_table)

def periodic_table():
    periodic_text = open('./periodic_table.txt', 'r')
    index_arq = open('periodic_table.html', 'w')
    list_received = (read_and_convert(periodic_text))
    
    table_html = "\t<table>"
    collum = 0
    for index in range(7):
        table_html += "\n\t<tr>"
        if collum == 18:
            collum = 0
        for collum in range(18):
            if collum == int(list_received[1]):
                table_html += input_table(list_received)
                list_received = (read_and_convert(periodic_text))
            else:
                table_html += "\n\t\t<td></td>"
        table_html += "</tr>"

    html_template = """<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Periodic Table</title>
    </head>
    <body>
"""
    html_end="""    
    </body>
</html>
""" 
    table_html += """</table>"""

    string_concatenade = html_template + table_html + html_end
    index_arq.write(string_concatenade)
    index_arq.close()
    periodic_text.close()

if __name__ =="__main__":
    periodic_table()
