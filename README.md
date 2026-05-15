# Estructuras de Datos - Prueba Práctica (Árboles BST)

**Estudiante:** Shirley Amaguaña 
**Semestre:** Tercer Semestre   
**Institución:** Universidad Técnica de Ambato 
**Asignatura:** Estructura de Datos  

---

## Descripción del Proyecto
Este proyecto consiste en el diseño e implementación de un **Sistema Académico** basado en **Árboles Binarios de Búsqueda (BST)**. Permite gestionar de manera eficiente los registros de estudiantes (cédula, nombres, notas, carrera, etc.) utilizando la cédula de identidad como clave primaria única de ordenamiento.

El sistema está desarrollado bajo dos tecnologías distintas solicitadas en la rúbrica:
1. **C++**: Haciendo uso de punteros nativos, estructuras dinámicas (`struct`) y recursividad explícita.
---

## Funcionalidades Principales

El menú de operaciones contiene:
- **Gestión Estudiantil:** Inserción ordenada, búsquedas en tiempo logarítmico $O(\log n)$ y eliminación completa considerando los 3 casos típicos (hojas, un hijo, dos hijos mediante sucesor inorden).
- **Recorridos del Árbol:** Profundidad (Inorden, Preorden, Postorden) y Amplitud (BFS por niveles utilizando colas estructuradas).
- **Métricas:** Conteo de nodos totales y cálculo de la altura del árbol.
- **Análisis de Rendimiento:** Filtrado en tiempo real de estudiantes aprobados/reprobados, así como búsqueda global de calificaciones extremas (mayor y menor nota).

---

## Instrucciones de Compilación y Ejecución

###  Compilación en C++
Asegúrate de contar con un compilador de GCC configurado (MinGW para Windows). Ejecuta en tu terminal:

```bash
# Compilar el archivo
g++ main.cpp -o main.exe

# Ejecutar el programa
./main.exe