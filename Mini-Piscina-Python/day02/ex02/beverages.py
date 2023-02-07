#!/usr/bin/env python3
class HotBeverage:
    def __init__(self,name = "hot beverage", price = 0.30, description = "Just some hot water in a cup."):
        self.name = name
        self.price = price
        self.description = description

    def __str__(self):
        returned_str = ""
        returned_str += "name : " + self.name + "\n"
        returned_str += "price : " + str("{:.2f}".format(self.price)) + "\n"
        returned_str += "description : " + self.description
        return returned_str

class Coffe(HotBeverage):
    def __init__(self, name="coffe", price = 0.50, description = "A coffe, to stay awake."):
        super().__init__(name = name, price = price, description=description)

class Tea(HotBeverage):
    def __init__(self, name="tea"):
        super().__init__(name = name)

if __name__ == "__main__":
    drink = HotBeverage()
    print(drink, "\n")
    coffe = Coffe()
    print(coffe, "\n")
    tea = Tea()
    print(tea, "\n")