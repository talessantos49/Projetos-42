#!/usr/bin/python3


class Text(str):
    """
    A Text class to represent a text you could use with your HTML elements.

    Because directly using str class was too mainstream.
    """
    def __str__(self):
        """
        Do you really need a comment to understand this method?..
        """
        return super().__str__().replace('<', '&lt;').replace('>', '&gt;').replace('"', '&quot;').replace('\&quot;', '\"').replace('\n', "\n<br />\n")


class Elem:
    """
    Elem will permit us to represent our HTML elements.
    """
    identation_counter = 0
    def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
        self.tag = tag
        self.tag_type = tag_type
        self.attr = attr
        if not self.check_type(content) and content != None :
            raise Elem.ValidationError()
        if isinstance(content, list):
            self.content = content
        elif isinstance(content, Elem) or isinstance(content, Text):
            self.content = [content]
        else:
            self.content = []


    def __str__(self):
        """
        The __str__() method will permit us to make a plain HTML representation
        of our elements.
        Make sure it renders everything (tag, attributes, embedded
        elements...).
        """
        result = ''
        returned_attr = self.__make_attr()
        if self.tag_type == 'double':
            result += "<" + self.tag + self.__make_attr() + ">" + self.__make_content() + "</" + self.tag + ">"
        elif self.tag_type == 'simple':
            result += "<" + self.tag + self.__make_attr() + "/>"
        return result

    def __make_attr(self):
        """
        Here is a function to render our elements attributes.
        """
        result = ''
        for pair in sorted(self.attr.items()):
            result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
        return result

    def __make_content(self):
        """
        Here is a method to render the content, including embedded elements.
        """
        if len(self.content) == 0:
            return ''
        result = ''
        Elem.identation_counter += 1
        for elem in self.content:
            if str(elem) != '':
                result += "\n" + Elem.identation_counter * '  ' + str(elem)
        if len(str(elem)) != 0:
            result += "\n" + (Elem.identation_counter -1) * '  '
        Elem.identation_counter -= 1
        return result


    def add_content(self, content):
        if not Elem.check_type(content):
            raise Elem.ValidationError
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    class ValidationError(Exception):
        def __init__(self):
            super().__init__("Incorrect behaviour.")

    @staticmethod
    def check_type(content):
        """
        Is this object a HTML-compatible Text instance or a Elem, or even a
        list of both?
        """
        return (isinstance(content, Elem) or type(content) == Text or
                (type(content) == list and all([type(elem) == Text or
                                                isinstance(elem, Elem)
                                                for elem in content])))


if __name__ == '__main__':
    # print(Elem(tag = "img",attr = {"src":"http://i.imgur.com/pfp3T.jpg"},content= Text("Hello ground!")))
    # print(Elem(tag = "html", attr = {"src":"http://i.imgur.com/pfp3T.jpg"}, content= [Elem(tag="h1")]))
    print(Elem(tag="html",content= [Elem(tag="head", content = [Elem(tag="title", content= Text('\\"Hello ground!\\"'))]), Elem(tag="body", content = [Elem(tag = "h1", content = Text('\\"Oh no, not again!\\"')), Elem(tag = "img", attr = {"src":"http://i.imgur.com/pfp3T.jpg"}, tag_type = "simple" )])]))
    # print(str(Elem(tag ='body', attr={}, content = Elem(), tag_type='double')))
    # print(str(Elem(content=[Text('foo'), Text(''), Elem()])))
    # print(str(Elem(tag='body', attr={}, content=Elem(),tag_type='double')))
    # print(str(Elem(content=[Text('foo'), Text('bar'), Elem()])))
    # print(str(Elem(content = Text(''))))