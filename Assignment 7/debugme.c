int main() {
    int d;
    char c;
    short s;
    int *p;
    int arr[2];
    
    p = &d;
    *p = 10;
    c = 1;

    p = arr;
    *(p + 1) = 5;
    p[0] = d;

    *((char *)p + 1) = c;


    return 0;
}