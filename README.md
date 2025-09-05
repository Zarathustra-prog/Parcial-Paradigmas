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

# Ejercicio 2:Sistema de Gestión de Estudiantes en C

## Descripción del Proyecto

Este proyecto implementa un sistema de gestión de estudiantes que permite la creación, eliminación y visualización de los registros de estudiantes. Cada registro de estudiante incluye:

* Nombre
* Apellido
* Edad
* Número de identificación
* Calificaciones de diversos cursos

El sistema utiliza asignación dinámica de memoria para asegurar un uso eficiente, adaptándose a la longitud variable de los nombres y al número de cursos por estudiante.

## Funcionalidades

* **Asignación Dinámica de Memoria**: Utiliza `malloc` y `free` para asignar y liberar memoria según sea necesario.
* **Estructuras de Datos Optimizadas**: Implementa campos de bits (bitfields) para almacenar de manera compacta la edad y el número de identificación.
* **Manejo Flexible de Datos**: Soporta cadenas de longitud variable para los nombres y arreglos dinámicos para las calificaciones.
* **Gestión de Memoria**: Incluye funciones para crear y eliminar registros de estudiantes, asegurando una limpieza adecuada de la memoria.

## Como ejecutar

1. Compila el programa en C:

   ```bash
   gcc -o gestor_estudiantes main.c
   ```

2. Ejecuta el programa:

   ```bash
   ./gestor_estudiantes
   ```

## Uso

Al ejecutar el programa, puedes:

* **Crear un Estudiante**: Ingresar el nombre, apellido, edad, número de identificación y calificaciones.
* **Mostrar Información del Estudiante**: Ver los detalles de todos los estudiantes almacenados.
* **Eliminar un Estudiante**: Remover el registro de un estudiante del sistema.

Ejemplo:

```bash
./gestor_estudiantes
Ingrese el nombre del estudiante: Alice
Ingrese el apellido del estudiante: Johnson
Ingrese la edad del estudiante: 20
Ingrese el ID del estudiante: 1001
Ingrese el número de calificaciones: 3
Ingrese la calificación 1: 90.5
Ingrese la calificación 2: 85.0
Ingrese la calificación 3: 88.0
Registro de estudiante creado exitosamente.

Mostrando todos los estudiantes:
ID: 1001 | Nombre: Alice Johnson | Edad: 20
Calificaciones: 90.5 85.0 88.0
```

## Estructura del Código

* `main.c`: Contiene la función `main` y la lógica de interacción con el usuario.
* `student.c`: Implementa funciones para crear, eliminar y mostrar registros de estudiantes.
* `student.h`: Archivo de cabecera que define la estructura `Student` y los prototipos de funciones.

