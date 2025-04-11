//inserire funzioni Lab5 qui

int matrice_confronta(int** first, int** second, int row, int col) {
    return confronta_array((int*)first, (int*)second, row * col);
}

int matrice_confronta_double(double** first, double** second, int row, int col, double toll) {
    return confronta_array_double((double*)first, (double*)second, row * col, toll);
}
