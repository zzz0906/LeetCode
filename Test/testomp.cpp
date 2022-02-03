int main(){
    int a[5000];

    # pragma omp simd
    for (int i = 0; i < 5000; i++){
        a[i] = i;
    }
}