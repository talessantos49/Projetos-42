import sys

def periodic_table():
    periodic_text = open('./periodic_table.txt', 'r')
    only_line = periodic_text.readline().rstrip('\n')
    print(only_line)
    splited_line = only_line.split(',')
    print(splited_line)
    # dict_element[key] = value
    table_html = "\t<table>"
    text_test = "\t<table>"
    # while only_line != '':
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
    collum = 0
    line = 0
    for index in range(7):
        text_test += "<tr>"
        line += 1
        if collum == 18:
            collum = 0
        for collum in range(18):
            if collum == position:
                text_test += f"""\n\t\t<td style="border: 1px solid black; padding: 10px; border-collapse: collapse"> <h4>{substance}</h4></td>"""
                # print(k, text_test)
            else:
                text_test += f"\n\t\t<td>{collum}</td>"
        text_test += "</tr>"
        # print(text_test)
        # if splited_line != '':
        #     substance = splited_line[0].split()
        #     if substance != '':
        #         str_substance = substance[0]
        #         str_substance = substance[0]
    table_html += """
    <tr>
        <td style="border: 1px solid black; padding:10px">
            <h4>"""
    table_html += substance
    table_html += """</h4>
    <ul>
        <li>No """
    table_html += number
    table_html += """ </li>
        <li>"""
    table_html += small
    table_html += """ </li>
        <li>"""
    table_html += molar
    table_html += """ </li>
        <li>"""
    table_html += electron
    table_html += """ electron</li>
    <ul>
    </td>
    </tr>
            """
    only_line = periodic_text.readline().rstrip('\n')


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
    html_end="""    
    </body>
</html>
""" 
    table_html += """</table>"""
    # string_concatenade = html_template + table_html + html_end + text_test
    string_concatenade = text_test + table_html
    index_arq = open('periodic_table.html', 'w')
    index_arq.write(string_concatenade)
    index_arq.close()

if __name__ =="__main__":
    periodic_table()
