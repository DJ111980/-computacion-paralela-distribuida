# Ejercicio 1 - Transferencia CPU ↔ GPU

## Objetivo
Aprender a reservar memoria en la GPU y transferir datos entre CPU y GPU usando CUDA.

## Conceptos utilizados
- `cudaMalloc`
- `cudaMemcpy`
- Memoria host y device
- Verificación de datos

## Compilación
```bash
nvcc ejercicio1_hola_gpu.cu -o ejercicio1
