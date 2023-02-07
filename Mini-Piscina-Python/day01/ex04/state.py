import sys

def state():
    states = {
    "Oregon" : "OR",
    "Alabama" : "AL",
    "New Jersey": "NJ",
    "Colorado" : "CO"
    }
    capital_cities = {
    "OR": "Salem",
    "AL": "Montgomery",
    "NJ": "Trenton",
    "CO": "Denver"
    }
    lista_chave = []
    for chave, valores in states.items():
        lista_chave.append(chave)
    lista_value = []
    for chave, valores in capital_cities.items():
        lista_value.append(valores)

    new_dict = dict(zip(lista_value, lista_chave))

    if len(sys.argv) == 2:
        if sys.argv[1] in new_dict:
            print(new_dict[sys.argv[1]])
        else:
            print("Unknown capital city")

if __name__ =="__main__":
    state()
    