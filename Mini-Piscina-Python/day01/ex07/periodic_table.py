import sys

def periodic_table():
    periodic_text = open('./periodic_table.txt', 'r')
    only_line = periodic_text.readline().rstrip('\n')
    print(only_line)
    splited_line = only_line.split(',')
    print(splited_line)

    table_html = "<table>"
    while only_line != '':
        splited_line = only_line.split(',')
        number = splited_line[1].split(':')
        number = number[1]
        small = splited_line[2].split(':')
        small = small[1]
        molar = splited_line[3].split(':')
        molar = molar[1]
        electron = splited_line[4].split(':')
        electron = electron[1]
        if splited_line != '':
            substance = splited_line[0].split()
            if substance != '':
                str_substance = substance[0]
                str_substance = substance[0]
                table_html += """
                <tr>
                <td style="border: 1px solid black; padding:10px">
                <h4>"""
                table_html += str_substance
                table_html += """</h4>
                <ul>
                <li>No """
                table_html += number
                table_html += """</li>
                <li>"""
                table_html += small
                table_html += """</li>
                <li>"""
                table_html += molar
                table_html += """</li>
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
    html_end="""    </body>
</html>
""" 
    table_html += """</table>"""
    string_concatenade = html_template + table_html + html_end
    index_arq = open('periodic_table.html', 'w')
    index_arq.write(string_concatenade)
    index_arq.close()
    
if __name__ =="__main__":
    periodic_table()
