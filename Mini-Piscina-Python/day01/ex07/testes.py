import sys

def add_td(text, rest, position, last_position):
    if position < 2 : color = "background: green;" 
    elif position < 12 : color = "background: red;" 
    else : color = "background: yellow;" 
    for x in range(int(last_position), position - 1):
        text += """ <td style="border: 0px; padding:10px; min-width:100px; min-height:100px"> </td>"""
    text += """
    <td style="border: 1px solid black; padding:10px ;min-width:100px; min-height:100px; """ + color + """ ">
        <h4 style="text-align:center">""" + str(rest[0]).split("=")[0].strip(" ") + """</h4>
        <ul>
        <li>No """+ rest[1].split(":")[1] +"""</li>
        <li>"""+ rest[2].split(":")[1] +"""</li>
        <li>"""+ rest[3].split(":")[1] +"""</li>
        <li>"""+ rest[4].split(":")[1] +""" electron</li>
        </ul>
        </td>"""
    return text

def main():
    periodic = open("./periodic_table.txt", "r")
    html = open("./index.html", "w")
    str2 = periodic.read().split("\n")
    text = """<!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Periodic Table</title>
        <link rel="preconnect" href="https://fonts.googleapis.com">
        <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
        <link href="https://fonts.googleapis.com/css2?family=Roboto:wght@300;400;500;700&display=swap" rel="stylesheet">
        <style>
        *{
            box-sizing: border-box;
        }
        
        body {
            font-family: 'Roboto', sans-serif;
            width: 100%;
            --webkit-font-smoothing: antialiased;
        }
        h2 {
            font-size: 20px;
        }
        ul {  
            list-style-type: none;  
            font-weight: bold;  
            font-size: 15px;  
        }  
        </style>
    </head>
    <body>
    <h1 style="text-align:center"> Peiodic Table</h1>
    <table>
    """
    lst_position = 0
    for i in str2:
        if (i == ""):
            break
        splitted = str(i).split(",")
        split_position = splitted[0].split(":")
        position = int(split_position[1])
        if (position == 0):
            text += "<tr>"
        text = add_td(text, splitted, position, lst_position)
        lst_position = position
        if (int(lst_position) + 1 == 18):
            lst_position = 0
            text += "</tr>"
    text += """ 
    
    </table>  
    </body>
    </html>
    """
    html.write(text)
    html.close()



if __name__ == '__main__':
    main()