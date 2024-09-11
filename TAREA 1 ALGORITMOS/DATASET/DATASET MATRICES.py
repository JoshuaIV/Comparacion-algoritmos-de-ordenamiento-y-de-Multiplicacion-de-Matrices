import numpy as np 

def guardar_matrices_en_archivo(matriz1, matriz2, archivo):
    with open(archivo, 'w') as f:
        # Guardar la primera matriz

        for fila in matriz1:
            f.write(" ".join(map(str, fila)) + "\n")

        f.write("\n")
        # Guardar la segunda matriz

        for fila in matriz2:
            f.write(" ".join(map(str, fila)) + "\n")

"DataSet Creacion Matrices CUADRADAS"
matriz1 = np.random.randint(0, 3,(64,64), dtype=int)  
matriz2 = np.random.randint(0, 3,(64,64), dtype=int)
guardar_matrices_en_archivo(matriz1,matriz2,"M6.txt")
matriz1 = np.random.randint(0, 3,(128,128), dtype=int)  
matriz2 = np.random.randint(0, 3,(128,128), dtype=int)
guardar_matrices_en_archivo(matriz1,matriz2,"M7.txt")
matriz1 = np.random.randint(0, 3,(256,256), dtype=int)  
matriz2 = np.random.randint(0, 3,(256,256), dtype=int)
guardar_matrices_en_archivo(matriz1,matriz2,"M8.txt")
matriz1 = np.random.randint(0, 3,(512,512), dtype=int)  
matriz2 = np.random.randint(0, 3,(512,512), dtype=int)
guardar_matrices_en_archivo(matriz1,matriz2,"M9.txt")
matriz1 = np.random.randint(0, 3,(1024,1024), dtype=int)  
matriz2 = np.random.randint(0, 3,(1024,1024), dtype=int)
guardar_matrices_en_archivo(matriz1,matriz2,"M10.txt")
matriz1 = np.random.randint(0, 3,(2048,2048), dtype=int)  
matriz2 = np.random.randint(0, 3,(2048,2048), dtype=int)
guardar_matrices_en_archivo(matriz1,matriz2,"M11.txt")


