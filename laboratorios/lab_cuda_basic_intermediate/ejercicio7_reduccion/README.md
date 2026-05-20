# Ejercicio 7 - Reducción Paralela

## Objetivo
Implementar reducción paralela usando shared memory para sumar un arreglo.

## Conceptos utilizados
- Shared Memory
- `__syncthreads()`
- Reducción paralela
- Suma por bloques

## Compilación
```bash
nvcc ejercicio7_reduccion.cu -o ejercicio7