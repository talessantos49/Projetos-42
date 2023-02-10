#!/usr/bin/python3
import requests, sys, dewiki

def check_arguments(arguments):
    if len(arguments) == 2 :
        response = get_wiki_info(sys.argv)
        if response.status_code == 200:
            archive_name = arguments[1].strip().replace(' ', '_')
            try:
                DATA = response.json()
                output = dewiki.from_string(DATA['parse']['wikitext']['*'])
                archive = open(archive_name + ".wiki", 'w')
                archive.write(output)
                archive.close()
            except:
                print("Error: Search not found!")
                exit(1)
    
    elif len(arguments) > 2:
        print("Too many arguments!")
        exit(1)
    elif len(arguments) < 2:
        print("Too few arguments!")
        exit(1)
    elif response != 200:
        print("Error: Wikipedia's sites is out of business or Not found")
        exit(1)

def get_wiki_info(argument):
    params = {
        'action': 'parse',
        'page': argument[1],
        'format': 'json',
        'prop':'wikitext',
        'redirects': True
    }
    url = 'https://en.wikipedia.org/w/api.php'
    info = requests.get(url, params=params)
    return info


if __name__== '__main__':
    check_arguments(sys.argv)
