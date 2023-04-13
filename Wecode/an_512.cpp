void merge(int *a, int n, int *b, int m, int *c){
    int indexB = -1;
    int indexC = 0;
    for (int indexA = 0; indexA < n; indexA++){
        while (indexB + 1 < m && b[indexB + 1] <= a[indexA]){
            indexB++;
            c[indexC++] = b[indexB];
        }
        c[indexC++] = a[indexA];
    }
    while (indexB + 1 < m){
        c[indexC++] = b[++indexB];
    }
}
