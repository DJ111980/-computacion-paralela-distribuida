# Ejercicio 3 - Información de la GPU

## Objetivo
Consultar las propiedades de la GPU instalada usando CUDA Runtime API.

## Conceptos utilizados
- `cudaGetDeviceProperties`
- `cudaDeviceProp`
- Compute Capability
- Multiprocessors y memoria

## Compilación
```bash
nvcc ejercicio3_device_info.cu -o ejercicio3