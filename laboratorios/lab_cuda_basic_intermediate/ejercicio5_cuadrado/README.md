# Ejercicio 5 - Operación In-Place

## Objetivo
Modificar datos directamente en GPU elevando cada elemento al cuadrado y verificando el resultado.

## Conceptos utilizados
- Kernels CUDA
- Modificación in-place
- Validación de resultados
- Transferencia GPU ↔ CPU

## Compilación
```bash
nvcc ejercicio5_cuadrado.cu -o ejercicio5