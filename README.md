# Prueba Práctica - Árbol Binario de Búsqueda en C++

**Estudiante:** Shirley Amaguaña

**Semestre:** Tercer Semestre  

**Universidad:** Universidad Técnica de Ambato (UTA)  

**Carrera:** Ingeniería de Software  

**Asignatura:** Estructura de Datos  

---

# Descripción del Proyecto

Este proyecto consiste en el desarrollo de un sistema académico utilizando un **Árbol Binario de Búsqueda (BST)** en C++.

El sistema permite registrar y gestionar estudiantes mediante su número de cédula, aplicando estructuras dinámicas, recursividad, punteros y recorridos de árboles binarios.

Cada estudiante contiene la siguiente información:

- Cédula
- Apellidos
- Nombres
- Nota final
- Carrera
- Nivel

La cédula funciona como clave principal para organizar automáticamente el árbol.

---

# Funcionalidades Implementadas

El sistema cumple con todas las funciones solicitadas en la práctica:

insertarEstudiante()

buscarEstudiante()

eliminarEstudiante()

recorridoInorden()

recorridoPreorden()

recorridoPostorden()

recorridoPorNiveles()

contarNodos()

calcularAltura()

buscarNotaMayor()

buscarNotaMenor()

mostrarAprobados()

mostrarReprobados()

---

# Recorridos Implementados

## Preorden
```txt
Raíz → Izquierda → Derecha
```

---

## Inorden
```txt
Izquierda → Raíz → Derecha
```

Este recorrido muestra los estudiantes ordenados por cédula.

---

## Postorden
```txt
Izquierda → Derecha → Raíz
```

---

## BFS - Por niveles
Recorre el árbol nivel por nivel utilizando una cola FIFO.

```txt
Nivel 0 → Raíz
Nivel 1 → Hijos
Nivel 2 → Nietos
```

---

# Menú del Sistema

```txt
1. Insertar estudiante
2. Buscar estudiante por cédula
3. Eliminar estudiante
4. Recorrido Inorden
5. Recorrido Preorden
6. Recorrido Postorden
7. Recorrido por niveles BFS
8. Contar estudiantes
9. Calcular altura del árbol
10. Mostrar estudiante con mayor nota
11. Mostrar estudiante con menor nota
12. Mostrar estudiantes aprobados
13. Mostrar estudiantes reprobados
14. Salir
```

---

# Tecnologías Utilizadas

- Lenguaje: C++
- Compilador: g++
- GitHub para control de versiones

---

# Instrucciones de Compilación y Ejecución

## Compilar el programa

```bash
g++ main.cpp -o sistema
```

## Ejecutar el programa
```bash
.\sistema.exe
```
---

# Estructura del Proyecto

```txt
prueba-practica-arboles-cpp-java/
│
├── main.cpp
├── README.md
│
├── assets/
│   ├── menu.png
│   ├── recorridos.png
│   └── operaciones.png
```

---

# Evidencias de Ejecución

## 1. Menú principal del sistema

En esta captura se muestra el menú principal del programa con las opciones disponibles para gestionar estudiantes.

![Menu Principal](assets/menu.png)

---

## 2. Recorrido Inorden

El recorrido Inorden muestra los estudiantes ordenados automáticamente por número de cédula.

![Inorden](assets/inorden.png)

---

## 3. Recorrido Preorden

El recorrido Preorden visita primero la raíz y luego sus hijos.

![Preorden](assets/preorden.png)

---

## 4. Recorrido Postorden

El recorrido Postorden visita primero los hijos y finalmente la raíz.

![Postorden](assets/postorden.png)

---

## 5. Recorrido BFS por niveles

El recorrido BFS utiliza una cola FIFO para recorrer el árbol nivel por nivel.

![BFS](assets/bfs.png)

---

## 6. Buscar estudiante

Ejemplo de búsqueda de un estudiante mediante su número de cédula.

![Buscar Estudiante](assets/buscarestudiante.png)

---

## 7. Eliminar estudiante

Demostración de eliminación de un nodo dentro del árbol binario.

![Eliminar Estudiante](assets/eliminarestudiante.png)

---

## 8. Contar estudiantes

El sistema calcula automáticamente la cantidad total de nodos registrados en el árbol.

![Contar Estudiantes](assets/Contarestudiante.png)

---

## 9. Calcular altura del árbol

Se muestra el cálculo de la altura máxima alcanzada por el árbol binario.

![Altura Arbol](assets/alturaarbol.png)

---

## 10. Estudiante con nota más alta

El sistema identifica automáticamente al estudiante con la nota mayor.

![Nota Alta](assets/notaAlta.png)

---

## 11. Estudiante con nota más baja

El sistema identifica automáticamente al estudiante con la nota menor.

![Nota Baja](assets/notabaja.png)

---

## 12. Mostrar estudiantes aprobados

Listado de estudiantes con nota mayor o igual a 7.

![Aprobados](assets/aprobados.png)

---

## 13. Mostrar estudiantes reprobados

Listado de estudiantes con nota menor a 7.

![Reprobados](assets/reprobados.png)

---

# Conceptos Aplicados

Durante el desarrollo se aplicaron los siguientes temas vistos en clase:

- Árboles binarios de búsqueda
- Recursividad
- Punteros
- Estructuras dinámicas
- Colas FIFO
- Recorridos DFS y BFS
- Manejo modular del código

---

# Explicación Técnica

## Recursividad

La recursividad fue utilizada para:

- insertar nodos
- buscar estudiantes
- eliminar nodos
- recorrer el árbol
- calcular altura
- contar nodos

---

## BFS usando cola

Para el recorrido por niveles se utilizó:

```cpp
queue<Nodo*> cola;
```

La cola permite recorrer el árbol de izquierda a derecha y nivel por nivel.

---

# Uso de GitHub 

## GitHub

El proyecto fue subido y versionado mediante GitHub utilizando varios commits durante el desarrollo.

---

# Conclusiones

Esta práctica permitió comprender mejor:

- El funcionamiento de los árboles binarios de búsqueda
- La aplicación de recursividad
- El uso de punteros en C++
- Los recorridos DFS y BFS
- El manejo de estructuras dinámicas

Además, se logró aplicar estos conceptos a un caso académico real.

---
