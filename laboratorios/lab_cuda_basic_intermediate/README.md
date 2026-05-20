# LAB-CUDA-BASIC-INTERMEDIATE | Danilo Jose Castillejo Ponton & Rusbell Oveymar Endes

> **Asignatura:** Fundamentos de Programación Concurrente y Distribuida
> **Docente:** Prf. Alejandro Jaimes
> **Fecha:** 20/05/2026
> **Repositorio:** [https://github.com/DJ111980/-computacion-paralela-distribuida](https://github.com/DJ111980/-computacion-paralela-distribuida)

---

## Equipo

|    | Colaborador                   | GitHub      |
| -- | ----------------------------- | ----------- |
| 👤 | Danilo Jose Castillejo Ponton | DJ111980    |
| 👤 | Rusbell Oveymar Endes         | rusbellec11 |

---

## Descripción

Este directorio contiene los ejercicios del taller de CUDA enfocados en programación paralela utilizando GPU.

Los ejercicios desarrollados abarcan:

* Transferencia de memoria CPU ↔ GPU
* Uso de kernels CUDA
* Manejo de hilos y bloques
* Shared Memory
* Reducción paralela
* Medición de rendimiento
* Comparación CPU vs GPU

---

## Configuración del repositorio

### Clonar repositorio

```bash
git clone https://github.com/DJ111980/-computacion-paralela-distribuida.git
cd -computacion-paralela-distribuida
```

---

## Compilación general

Todos los ejercicios se compilan utilizando `nvcc`.

Ejemplo:

```bash
nvcc ejercicio1_hola_gpu.cu -o ejercicio1
```

---

## Estructura del laboratorio

```text
lab_cuda_basic_intermediate/
├── ejercicio1_hola_gpu/
├── ejercicio2_matriz/
├── ejercicio3_device_info/
├── ejercicio4_suma_vectores/
├── ejercicio5_cuadrado/
├── ejercicio6_kernel2d/
├── ejercicio7_reduccion/
├── ejercicio8_tiempo/
├── ejercicio9_producto_punto/
├── img/
└── reporte/
```
