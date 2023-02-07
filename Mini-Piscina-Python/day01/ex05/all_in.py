import sys

def all_in():
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
    new_state = dict(zip(lista_chave, lista_value))
    if len(sys.argv) == 2:
        if sys.argv[1].count(',') >= 1:
            arg_entr = sys.argv[1].split(',')
            arguments = sys.argv[1].title()
            arguments = arguments.split(',')
            for x in arguments:
                temp = x
                if temp == '':
                    pass
            for i in arguments:
                temp = i.strip()
                if temp != '':
                    if temp in new_dict.values():
                        print(new_state[temp],"is the capital of", temp)
                    elif temp in new_state.values():
                        print(temp,"is the capital of",new_dict[temp])
                    else:
                        print(arg_entr[arguments.index(i)].strip(),"is neither a capital city nor a state")
        else:
            one_arg = sys.argv[1].title()
            returned_arg = sys.argv[1].strip()
            if returned_arg == '':
                return
            if one_arg in new_dict.values():
                print(new_state[one_arg],"is the capital of", one_arg)
            elif one_arg in new_state.values():
                print(one_arg,"is the capital of",new_dict[one_arg])
            else:
                print(returned_arg, "is neither a capital city nor a state")

if __name__ =="__main__":
    all_in()
