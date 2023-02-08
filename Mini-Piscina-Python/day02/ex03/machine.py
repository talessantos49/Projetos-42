from beverages import *
import random

class CoffeeMachine(HotBeverage):
    counter = 0
    def __init__(self):
        self.name = "coffee machine"
        self.repaired = True

    def repair(self):
        CoffeeMachine.counter = 0
        self.repaired = True
        return print("The CoffeeMachine can work again!\n")

    def serve(self, drink):
        if (self.counter == 10):
            self.repaired = False
            raise CoffeeMachine.BrokenMachineException()
        CoffeeMachine.counter += 1
        isDrink = random.randint(0, 1)
        if isDrink :
            return drink()
        return CoffeeMachine.EmptyCup()

    class EmptyCup(HotBeverage):
        def __init__(self, name="empty cup", price=0.9):
            super().__init__(name=name, price=price)

        def description(self):
            return "An empty cup?! Gimme my money back!"

    class BrokenMachineException(Exception):
        def __init__(self):
            super().__init__("This coffee machine has to be repaired.")

if __name__ == "__main__":
    menu = [Tea, Coffe, Chocolate, Cappuccino, HotBeverage]
    random_list = random.choices(menu, k = 15)
    try:
        for i in range(15):
            print(CoffeeMachine().serve(random_list[i]), i, "\n")
    except Exception as e:
        print(e, "\n")

    print("-----------------------------------------------")

    CoffeeMachine().repair()

    try:
        for i in range(15):
            print(CoffeeMachine().serve(random_list[i]), i, "\n")
    except Exception as e:
        print(e, "\n")
