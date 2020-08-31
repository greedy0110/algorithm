class Person:
    def __init__(self, name, age):
        self._name = name
        self._age = age

    def __str__(self):
        return self._name + "이다. " + str(self._age)


person = Person("신승민", 26)
print(person)
