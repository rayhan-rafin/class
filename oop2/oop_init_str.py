class stat:
    def __init__(self,name,age,cgpa):
        self.name = name
        self.age = age
        self.cgpa = cgpa
        
    def __str__(self):
        return f'{self.name} is {self.age} years old and has a cgpa of {self.cgpa}'

r1= stat ("rayhan rafin", 21 ,3.74)
print (r1)
