#include <iostream>

using namespace std; 
class Test {
public :
    Test(int a, int b) {
        cout << "TEST(int, int).." << endl;
        ma = a;
        mb = b;
    }

    void printT() {
        cout << "prinnt ma = " << ma << " ,mb = "<< mb << endl;
        
    }
    ~Test() {
        cout << "~Test() ........." << endl;

    }
private:
    int ma;
    int mb;
};
int main() {
    #if 0
    test1();
    cout << "--------------------" << endl;
    test2();
    #endif
    cout << "============" << endl;
    Test *p = (Test *)malloc(sizeof(Test));
    p->printT();
    if (p != NULL) {
        free(p);
        p = NULL;
    }
    cout << "--------------------" << endl;
    Test *p1 = new Test(10, 20);
    p1->printT();
    if (p1 != NULL) {
        delete p1;
        p1 = NULL;
    }
     

    return 0;
}
  

//   c
void  test1() {
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    if (p != NULL) {
        // delete p;
        free(p);
        p = NULL;
    }
    //数组
    int *array_p = (int *)malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++) {
        array_p[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", array_p[i]);
    }
    printf("\n");
    if (array_p != NULL) {
        free(array_p);
        array_p = NULL;
    }
}

// c++
void test2() {
    int *p = new int;
    char *ch = new char;
    *p = 10;
    if (p != NULL) {
        delete p;
        p = NULL;
    }
     //数组
    int *array_p = new int[10];
    for (int i = 0; i < 10; i++) {
        array_p[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        cout << array_p[i] << " ";
    }
    cout << endl;
    if (array_p != NULL) {
        delete[] array_p;
        array_p = NULL;
    }

}

