Parcial Paradigmas/ ├── Ejercicio1-StudentGradesSorting/ │   ├── python-imperative/ │   │   └── ImperativeApproach.py │   ├── haskell-declarative/ │   │   └── DeclarativeApproach.hs │   └── README.md

---

# python-imperative/ImperativeApproach.py

# Lista de estudiantes sin ordenar

students = [ ("Juanito", 3), ("Bob", 5), ("Pepe", 1), ("Jose", 4.6), ("Maria", 5) ]

n = len(students)

# Bubble sort imperativo: orden descendente por calificación y alfabético en caso de empate

for i in range(n): for j in range(0, n - i - 1): if students[j][1] < students[j+1][1] or (students[j][1] == students[j+1][1] and students[j][0] > students[j+1][0]): students[j], students[j+1] = students[j+1], students[j]

# Imprimir lista ordenada

for name, grade in students: print(f"{name}: {grade}")

---

# haskell-declarative/DeclarativeApproach.hs

\-- Lista de estudiantes students :: [(String, Int)] students = [ ("Alice", 88) , ("Bob", 95) , ("Charlie", 88) , ("Diana", 92) , ("Eve", 95) ]

\-- Función recursiva de ordenamiento: descendente por calificación, alfabético en caso de empate sortStudents :: [(String, Int)] -> [(String, Int)] sortStudents [] = [] sortStudents (x\:xs) = let bigger = [y | y <- xs, (snd y, fst y) > (snd x, fst x)] smallerOrEqual = [y | y <- xs, (snd y, fst y) <= (snd x, fst x)] in sortStudents bigger ++ [x] ++ sortStudents smallerOrEqual

\-- Imprimir lista ordenada main :: IO () main = mapM\_ ((name, grade) -> putStrLn \$ name ++ ": " ++ show grade) (sortStudents students)

---

# README.md

# Ejercicio 1: Student Grades Sorting

## Especificación del Problema

Se tiene una lista de nombres de estudiantes junto con sus respectivas calificaciones en un examen final. El objetivo es ordenar la lista en **orden descendente por calificación** y, en caso de empate, **alfabéticamente por nombre**.

Este ejercicio es parte del repositorio **Parcial Paradigmas** y se resuelve usando **dos paradigmas de programación**:

- Imperativo (Python)
- Declarativo / Funcional (Haskell)

---

## Enfoque Imperativo en Python

- Implementa un **bubble sort manual**.
- Ordena **descendentemente por calificación** y resuelve empates **alfabéticamente**.
- Usa **listas mutables** y cambios en el lugar.

**Sección Clave del Código:**

```python
if students[j][1] < students[j+1][1] or (students[j][1] == students[j+1][1] and students[j][0] > students[j+1][0]):
    students[j], students[j+1] = students[j+1], students[j]
```

---

## Enfoque Declarativo en Haskell

- Implementa una **función recursiva** de ordenamiento.
- Ordena **descendentemente por calificación** y resuelve empates **alfabéticamente**.
- **Listas inmutables**; cada llamada recursiva produce una nueva lista.

**Sección Clave del Código:**

```haskell
sortStudents (x:xs) =
  let bigger = [y | y <- xs, (snd y, fst y) > (snd x, fst x)]
      smallerOrEqual = [y | y <- xs, (snd y, fst y) <= (snd x, fst x)]
  in sortStudents bigger ++ [x] ++ sortStudents smallerOrEqual
```

---

## Análisis Comparativo

| Aspecto                        | Python (Imperativo)                          | Haskell (Declarativo)                                     |
| ------------------------------ | -------------------------------------------- | --------------------------------------------------------- |
| Claridad y legibilidad         | Fácil de seguir con bucles explícitos        | Conciso y expresivo; requiere comprensión de recursión    |
| Expresividad & abstracción     | Se centra en **cómo** se ordena              | Se centra en **qué resultado** se desea                   |
| Estructuras de datos           | Lista mutable                                | Lista inmutable                                           |
| Manejo de estado               | Estado mutable explícito                     | Sin estado mutable, más seguro                            |
| Mantenimiento & Extensibilidad | Adecuado para scripts pequeños               | Muy mantenible y flexible                                 |
| Eficiencia                     | Bubble sort O(n²); optimizable usando sort() | Recursivo O(n²) (naive); se puede optimizar con mergesort |

---

## Cómo Ejecutar

### Python

```bash
python python-imperative/ImperativeApproach.py
```

### Haskell

```bash
ghc haskell-declarative/DeclarativeApproach.hs -o main
./main
```

