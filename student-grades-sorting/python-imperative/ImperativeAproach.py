#Lista sin sortear
students = [
    ("Juanito", 3),
    ("Bob", 5),
    ("Pepe", 1),
    ("Jose", 4.6),
    ("Maria", 5)
]

n = len(students)

#Bubble sort imperativo
for i in range(n):
    for j in range(0, n-i-1):
        if students[j][1] < students[j+1][1] or (students[j][1] == students[j+1][1] and students[j][0] > students[j+1][0]): 
        	students[j], students[j+1] = students[j+1], students[j]
for name, grade in students:
    print(f"{name}: {grade}")
