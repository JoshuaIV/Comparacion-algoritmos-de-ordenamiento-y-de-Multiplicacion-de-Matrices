
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <vector>

using namespace std;


// ---------------ALGORITMOS QUICKSORT--------------- //

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) {
        return;}
    else{
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
}


// ---------------ALGORITMOS MERGESORT--------------- //

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


// ---------------ALGORITMO SELECTIONSORT--------------- //

void selectionSort(int arr[], int size){
        for(int i = 0; i < size - 1; ++i){
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }};

// ---------------ALGORITMO PRINTARRAY--------------- //

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



// ---------------ALGORITMO LEERMATRICES--------------- //

void LeerMatrices(string nombre_archivo, vector<vector<int>>& matriz1, vector<vector<int>>& matriz2, int dimension) {
    ifstream archivo(nombre_archivo);

    if (!archivo) {
        cerr << "Error al abrir el archivo matrices" << endl;
        return;
    }

    matriz1.resize(dimension, vector<int>(dimension));
    matriz2.resize(dimension, vector<int>(dimension));

    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            archivo >> matriz1[i][j];
        }
    }

    archivo.ignore(numeric_limits<streamsize>::max(), '\n');
  
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            archivo >> matriz2[i][j];
        }
    }
    archivo.close();
    
}

// ----------MULTIPLICACION DE MATRICES TRADICIONAL---------- //

vector<vector<int>> Tradicional(vector<vector<int>> A, vector<vector<int>> B,int dimension){
    vector<vector<int>> C(dimension, vector<int>(dimension, 0));
    for(int i=0; i < dimension;i++){
        for(int j=0; j < dimension;j++){
            for(int k=0; k < dimension;k++){
                C[i][j] += A[i][k] * B[k][j];

            }
        }         
    }
    return C;
}

// ----------MULTIPLICACION DE MATRICES OPTIMIZADO---------- //

vector<vector<int>> transponer(const vector<vector<int>>& mat) {
    int dimension = mat.size();
    vector<vector<int>> transpuesta(dimension, vector<int>(dimension));
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            transpuesta[j][i] = mat[i][j];
        }
    }
    return transpuesta;
}

vector<vector<int>> Optimizado(const vector<vector<int>>& A, const vector<vector<int>>& B, int dimension) {
    vector<vector<int>> B_T = transponer(B);
    vector<vector<int>> C(dimension, vector<int>(dimension, 0));
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            for (int k = 0; k < dimension; ++k) {
                C[i][j] += A[i][k] * B_T[j][k];
            }
        }
    }

    return C;
}

// ----------MULTIPLICACION DE MATRICES STRASSEN---------- //

vector<vector<int>> add_matrix(vector<vector<int> > matrix_A,vector<vector<int> > matrix_B, int split_index,int multiplier = 1){
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_A[i][j]
                = matrix_A[i][j]
                  + (multiplier * matrix_B[i][j]);
    return matrix_A;
}
 
vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A,vector<vector<int>> matrix_B){
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    vector<int> result_matrix_row(col_2, 0);
    vector<vector<int>> result_matrix(row_1,result_matrix_row);
                           
    if (col_1 == 1){
        result_matrix[0][0]= matrix_A[0][0] * matrix_B[0][0];
        }
    else {
        int split_index = col_1 / 2;
        vector<int> row_vector(split_index, 0);
        vector<vector<int>> a00(split_index, row_vector);
        vector<vector<int>> a01(split_index, row_vector);
        vector<vector<int>> a10(split_index, row_vector);
        vector<vector<int>> a11(split_index, row_vector);
        vector<vector<int>> b00(split_index, row_vector);
        vector<vector<int>> b01(split_index, row_vector);
        vector<vector<int>> b10(split_index, row_vector);
        vector<vector<int>> b11(split_index, row_vector);
 
        for (auto i = 0; i < split_index; i++){
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index][j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index][j + split_index];
            }                   
        }
        vector<vector<int>> p(multiply_matrix(a00, add_matrix(b01, b11, split_index, -1)));   
        vector<vector<int>> q(multiply_matrix(add_matrix(a00, a01, split_index), b11));    
        vector<vector<int>> r(multiply_matrix(add_matrix(a10, a11, split_index), b00));  
        vector<vector<int>> s(multiply_matrix(a11, add_matrix(b10, b00, split_index, -1)));    
        vector<vector<int>> t(multiply_matrix(add_matrix(a00, a11, split_index),add_matrix(b00, b11, split_index)));    
        vector<vector<int>> u(multiply_matrix(add_matrix(a01, a11, split_index, -1),add_matrix(b10, b11, split_index)));
        vector<vector<int>> v(multiply_matrix(add_matrix(a00, a10, split_index, -1),add_matrix(b00, b01, split_index)));

        vector<vector<int>> result_matrix_00(add_matrix(add_matrix(add_matrix(t, s, split_index), u,split_index),q, split_index, -1));
        vector<vector<int>> result_matrix_01(add_matrix(p, q, split_index));
        vector<vector<int>> result_matrix_10(add_matrix(r, s, split_index));
        vector<vector<int>> result_matrix_11(add_matrix( add_matrix(add_matrix(t, p, split_index), r,split_index, -1), v, split_index, -1));
                       
        for (auto i = 0; i < split_index; i++){
            for (auto j = 0; j < split_index; j++) {
                result_matrix[i][j]= result_matrix_00[i][j];                   
                result_matrix[i][j + split_index] = result_matrix_01[i][j];                   
                result_matrix[split_index + i][j]= result_matrix_10[i][j];
                result_matrix[i + split_index] [j + split_index]= result_matrix_11[i][j];                    
            }}
        
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
        p.clear();
        q.clear();
        r.clear();
        s.clear();
        t.clear();
        u.clear();
        v.clear();
        result_matrix_00.clear();
        result_matrix_01.clear();
        result_matrix_10.clear();
        result_matrix_11.clear();
    }
    return result_matrix;
}

int main(){

    // ---------------SE LEEN LOS ARREGLOS--------------- // 

    ifstream archivo("C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\Arreglos5000.txt");  
    string linea1,linea2,linea3,linea4;
    getline(archivo,linea1);
    getline(archivo,linea2);
    getline(archivo,linea3);
    getline(archivo,linea4);
    int listaOrdenada[5000];
    int listaSemi[5000];
    int listaParcial[5000];
    int listaRandom[5000];
    istringstream iss1(linea1);
    istringstream iss2(linea2); 
    istringstream iss3(linea3); 
    istringstream iss4(linea4);  
    int numero1,numero2,numero3,numero4;
    int i = 0;
    while(iss1 >> numero1){
        iss2 >>numero2;
        iss3 >>numero3;
        iss4 >>numero4;
        listaOrdenada[i] = numero1;
        listaSemi[i] = numero2;
        listaParcial[i] = numero3;
        listaRandom[i] = numero4;
        i++;
        }
    archivo.close();

    // ---------------ALGORITMO DE ORDENAMIENTO--------------- //

    auto inicioO = chrono::high_resolution_clock::now();
    sort(listaOrdenada, listaOrdenada + 5000);
    auto finalO = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempoO = finalO - inicioO;
    cout << "La funcion de Ordenamiento para Ordenada(5000) tardo: " << tiempoO.count() << " ms." << endl;


    auto inicioS = chrono::high_resolution_clock::now();
    sort(listaSemi, listaSemi + 5000);
    auto finalS = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempoS = finalS- inicioS;
    cout << "La funcion de Ordenamiento para Semi(5000) tardo: " << tiempoS.count() << " ms." << endl;
     
    
    auto inicioP = chrono::high_resolution_clock::now();
    sort(listaParcial, listaParcial + 5000);
    auto finalP = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempoP = finalP - inicioP;
    cout << "La funcion de Ordenamiento para Parcial(5000) tardo: " << tiempoP.count() << " ms." << endl;

    
    auto inicioR = chrono::high_resolution_clock::now();
    sort(listaRandom, listaRandom + 5000);
    auto finalR = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempoR = finalR - inicioR;
    cout << "La funcion de Ordenamiento para Random(5000) tardo: " << tiempoR.count() << " ms." << endl;



    // ---------------SE LEEN LAS MATRICES--------------- //

    string ruta ="C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\M6.txt";
    vector<vector<int>> MA6;
    vector<vector<int>> MB6;
    LeerMatrices(ruta,MA6,MB6,64);

    ruta ="C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\M7.txt";
    vector<vector<int>> MA7;
    vector<vector<int>> MB7;
    LeerMatrices(ruta,MA7,MB7,128);

    ruta ="C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\M8.txt";
    vector<vector<int>> MA8;
    vector<vector<int>> MB8;
    LeerMatrices(ruta,MA8,MB8,256);

    ruta ="C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\M9.txt";
    vector<vector<int>> MA9;
    vector<vector<int>> MB9;
    LeerMatrices(ruta,MA9,MB9,512);

    ruta="C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\M10.txt";
    vector<vector<int>> MA10;
    vector<vector<int>> MB10;
    LeerMatrices(ruta,MA10,MB10,1024);

    ruta="C:\\Users\\Shame\\Desktop\\PC\\VISUAL\\DATASET\\M11.txt";
    vector<vector<int>> MA11;
    vector<vector<int>> MB11;
    LeerMatrices(ruta,MA11,MB11,2048);

    // ---------------MULTIPLICACION DE MATRICES--------------- //
/*
    vector<vector<int>> r6,r7,r8,r9,r10,r11;
    
    auto inicio6 = chrono::high_resolution_clock::now();
    r6 = multiply_matrix(MA6,MB6);
    auto final6 = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempo6 = final6 - inicio6;
    cout << "La funcion de Multiplicacion(6) tardo: " << tiempo6.count() << " ms." << endl;


    auto inicio7 = chrono::high_resolution_clock::now();
    r7 = multiply_matrix(MA7,MB7);
    auto final7 = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempo7 = final7 - inicio7;
    cout << "La funcion de Multiplicacion(7) tardo: " << tiempo7.count() << " ms." << endl;
     
    
    auto inicio8 = chrono::high_resolution_clock::now();
    r8 = multiply_matrix(MA8,MB8);
    auto final8 = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempo8 = final8 - inicio8;
    cout << "La funcion de Multiplicacion(8) tardo: " << tiempo8.count() << " ms." << endl;

    
    auto inicio9 = chrono::high_resolution_clock::now();
    r9 = multiply_matrix(MA9,MB9);
    auto final9 = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempo9 = final9 - inicio9;
    cout << "La funcion de Multiplicacion(9) tardo: " << tiempo9.count() << " ms." << endl;

    
    auto inicio10 = chrono::high_resolution_clock::now();
    r10 = multiply_matrix(MA10,MB10);
    auto final10 = chrono::high_resolution_clock::now();
    chrono::duration<float,milli> tiempo10 = final10 - inicio10;
    cout << "La funcion de Multiplicacion(10) tardo: " << tiempo10.count() << " ms." << endl;*/

   

    
    return 0;
}