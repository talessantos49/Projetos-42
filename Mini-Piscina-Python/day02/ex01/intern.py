class Intern:
    def __init__(self, name ="My name? I’m nobody, an intern, I have no name."):
        self.name = name 
    def __str__(self):
        return self.name
    def work(self):
        raise Exception("I'm just an intern, I can't do that...")
    def make_coffee(self):
        return (self.Coffee())
    class Coffee:
        def __str__(self):
            self ="This is the worst coffee you ever tasted."
            return self

if __name__ =="__main__":
    Estag = Intern()
    print(Estag)
    Estag_mark = Intern("Mark")
    print(Estag_mark)
    print(Estag_mark.make_coffee())
    try:
        print(Estag_mark.work())
    except Exception as out:
        print(out)