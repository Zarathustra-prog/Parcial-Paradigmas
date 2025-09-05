# README

# Ejercicio 1: Student Grades Sorting

## Especificación del Problema

Se tiene una lista de nombres de estudiantes con sus calificaciones finales. El objetivo es ordenar la lista en **orden descendente por calificación** y, en caso de empate, **alfabéticamente por nombre**.

Este ejercicio pertenece al repositorio **Parcial Paradigmas** y se implementa utilizando **dos paradigmas de programación**:

- Imperativo (Python)
- Declarativo / Funcional (Haskell)

---

## Enfoque Imperativo en Python

- Implementa un **bubble sort manual**.
- Ordena **descendentemente por calificación** y resuelve empates **alfabéticamente**.
- Usa **listas mutables**, modificando la lista en el lugar.

**Código Clave:**
```python
if students[j][1] < students[j+1][1] or \
   (students[j][1] == students[j+1][1] and students[j][0] > students[j+1][0]):
    students[j], students[j+1] = students[j+1], students[j]
```

---

## Enfoque Declarativo en Haskell

- Implementa una **función recursiva de ordenamiento**.
- Ordena **descendentemente por calificación** y resuelve empates **alfabéticamente**.
- Usa **listas inmutables**; cada llamada recursiva genera una nueva lista ordenada.

**Código Clave:**
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
| Claridad y legibilidad         | Intuitivo con bucles explícitos              | Conciso y expresivo; requiere comprensión de recursión    |
| Expresividad & abstracción     | Se centra en **cómo** se realiza el ordenamiento | Se centra en **qué resultado** se desea                   |
| Estructuras de datos           | Lista mutable                                | Lista inmutable                                           |
| Manejo de estado               | Estado mutable explícito                     | Sin estado mutable, más seguro                            |
| Mantenimiento & Extensibilidad | Fácil de modificar en scripts pequeños      | Muy mantenible y flexible                                 |
| Eficiencia                     | Bubble sort O(n²); puede optimizarse con funciones nativas | Recursivo O(n²) (naive); optimizable con mergesort       |

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

