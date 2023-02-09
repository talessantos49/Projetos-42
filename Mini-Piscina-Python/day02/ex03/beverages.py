#!/usr/bin/env python3
class HotBeverage:
    def __init__(self,name = "hot beverage", price = 0.30 ):
        self.name = name
        self.price = price

    def description(self):
        return ("Just some hot water in a cup.")

    def __str__(self):
        returned_str = ""
        returned_str += "name : " + self.name + "\n"
        returned_str += "price : " + str("{:.2f}".format(self.price)) + "\n"
        returned_str += "description : " + self.description()
        return returned_str

class Coffee(HotBeverage):
    def __init__(self, name="coffee", price = 0.40):
        super().__init__(name = name, price = price)
    def description(self):
        return "A coffee, to stay awake."

class Tea(HotBeverage):
    def __init__(self, name="tea"):
        super().__init__(name = name)

class Chocolate(HotBeverage):
    def __init__(self, name="chocolate", price = 0.50):
        super().__init__(name=name, price=price)

    def description(self):
        return "Chocolate, sweet chocolate..."

class Cappuccino(HotBeverage):
    def __init__(self, name="cappuccino", price = 0.45):
        super().__init__(name=name, price=price)

    def description(self):
        return "Un po’ di Italia nella sua tazza!"

if __name__ == "__main__":
    drink = HotBeverage()
    print(drink, "\n")
    coffee = Coffee()
    print(coffee, "\n")
    tea = Tea()
    print(tea, "\n")
    chocolate = Chocolate()
    print(chocolate, "\n")
    capputino = Cappuccino()
    print(capputino, '\n')
