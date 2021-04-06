#include <iostream>
using namespace std;
#define MAX 100
#define maxSize 5
void setSize(int &n);
void setArrayValues(int a[], int n);
void displayArrayValues(int a[], int n);
void Delete(int a[], int &n, int local);
void Local(int n, int &local);
void deleteElementByIndex(int a[], int &n, int local);
void deleteElementByValue(int a[], int &n, int &value);
void updateElementByIndex(int a[], int n, int local2, int value2);
void updateElementByValue(int a[], int n, int value2, int value3); 
void Mang(int b[], int &m);
void concat(int a[], int elements[], int n, int size, int c[], int &p);


class Array
{
    private:
      int *elements;
      int size;
    public:
      Array();
      void printArray();
      void push(int elements);
      void pop();
      void shift();
};
int main()
{
    Array array1;
    int n, m, p, local, value, local2, value2, value3;
    int a[MAX], b[MAX], c[MAX];
    array1.push(4);
    array1.printArray();
    array1.push(5);
    array1.printArray();
    array1.push(6);
    array1.printArray();
    array1.push(7);
    array1.printArray();
    array1.pop();
    array1.printArray();
    array1.pop();
    array1.printArray();
    array1.pop();
    array1.printArray();
    array1.shift();
    array1.printArray();
    array1.shift();
    array1.printArray();
    array1.shift();
    array1.printArray();
    
    setSize(n);
    setArrayValues(a, n);
    displayArrayValues(a, n);
    deleteElementByIndex(a, n, local);
    deleteElementByValue(a, n, value);
    updateElementByIndex(a, n, local2, value2);
    updateElementByValue(a, n, value2, value3);
    Mang(b, m);
    concat(a, b, n, m, c, p);
    displayArrayValues(c, p);
}
void setSize(int &n)
{
    cout << "\nEnter number element in array 2: ";
    cin >> n;
}
void setArrayValues(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "Enter element " << i+1 << ":\n" ;
        cin >> a[i];
    }
}
void displayArrayValues(int a[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout << "\na["<<i<<"]: " << a[i];
    }
}
void Delete(int a[], int &n, int local)
{
    for(int i=local; i<n; i++)
        a[i] = a[i+1];
    n--;
    displayArrayValues(a, n);
}
void Local(int n, int &local)
{
    do{
        cout << "\nEnter a delete local (If you don't want to delete, press -100 to skip this step): \n";
        cin >> local;
        if(local < 0 && local > -100 || local >= n)
            cout << "Position does not exist please re-enter!!!\n";
    }while(local < 0 && local > -100 || local >= n);
}
void deleteElementByIndex(int a[], int &n, int local)
{
   for(int i=0; i<n; i++){
    Local(n, local);
    if(local == -100)
      break;
    Delete(a, n, local);
   }
}
void deleteElementByValue(int a[], int &n, int &value)
{
   int dem=0;
   do{
        cout << "Enter a value u want to delete\n";
        cin >> value;
        for(int i=0; i<n; i++){
            if(a[i]==value){
               for(int j=i; j<n-1; j++){
                    a[j]=a[j+1];
                }
            dem++;
            n--;
            i--;
            }
        }
    if(dem==0)
       cout<<"Does not value need search!\n";
    }while(dem==0);
    displayArrayValues(a, n);
}
void updateElementByIndex(int a[], int n, int local2, int value2)
{
    do{
        cout<<"\nEnter the location u want to update: ";
        cin >> local2;
        if(local2 >= n)
           cout<<"\nPosition does not exist please re-enter!!!";
    }while(local2 >= n);
    cout<<"\nEnter a value u want to update: ";
    cin >> value2;
    for(int i=0; i<n; i++)
    {
        if(i == local2)
            a[i] = value2;
    }
    displayArrayValues(a, n);
}
void updateElementByValue(int a[], int n, int value2, int value3)
{
    int dem=0;
    cout << "\nEnter the new value: ";
    cin >> value3;
    do{
        cout << "\nEnter the old value you want to change to the new value: ";
        cin >> value2;
        for(int i=0; i<n; i++){
            if(a[i]==value2){
                    a[i]=value3;
                    dem++;
                }
            }
    if(dem==0)
       cout<<"Does not value need change!\n";
    }while(dem==0);
    displayArrayValues(a, n);
}
Array::Array(){
    std::cout << "\nEnter number element in array 1: ";
    std::cin >> size;
    elements = new int[size];
    for(int i=0; i<size; i++)
    {
        std::cout << "\nEnter element "<<i+1<<": ";
        std::cin >> *(elements+i);
    }
}
void Array::printArray(){
    std::cout<<std::endl<<"Elements: ";
    if(size == 0){
        std::cout<<"no elements"<<std::endl;
    } else {
        for(int i=0; i< size; i++){
        std::cout<<*(elements + i)<<"  ";
        }
    }
}
void Array::push(int element){
    if(size == 0){
        elements = new int;
        elements[0] = element;
    }
    else if(size >= maxSize){
        std::cout << "\nArray full can't add elements!";
        size--;
    }
    else{
        elements[size] = element;
    }
    size++;
    /* Cach 2: Mang Dong
    if(size == 0){// hoac elements = NULL
        elements = new int;
        elements[0] = element;
    }
    else{
        int* temp;
        temp = new int[size];
        // copy tu elements sang temp
        for(int i =0;i<size;i++){
           *(temp+i) = *(elements + i); 
        }
        // reset gia tri cua elements
        delete[] elements;
        elements = new int[size+1];
        // copy tu temp sang elements
        for(int i=0;i<size;i++){
            elements[i] = temp[i];
        }
        // them  1 phan tu
        elements[size] = element;
    }
    size++;*/
}
void Array::pop()
{
    if(size==0){
        std::cout<<"No element for delete!";
    }
    else
        size--;
/* Cách 2: Mảng Động
    if(size==0){
        std::cout<<"khong the xoa vi khong co phan tu trong mang!";
    }
    else
    {
        int *temp;
        temp= new int[size];
        for( int i=0;i<size;i++){
            *(temp+i)=*(elements+i);
        }
        delete[] elements;
        elements = new int[size-1];
        for(int i=0;i<size-1;i++){
            *(elements+i) = *(temp+i);
        }
        size--;
        delete[] temp; */
}
void Array::shift()
{
    if(size != 0){
        for(int i=0; i<size; i++)
            elements[i] = elements[i+1];
        size--;
    }
}
void Mang(int b[], int &m)
{
    cout << "\nEnter number element in array 3: ";
    cin >> m;
    for(int i=0; i<m; i++)
    {
        cout <<"\nEnter element " << i+1 << ": ";
        cin >> b[i];
    }
}
void concat(int a[], int b[], int n, int m, int c[], int &p)
{
    p = n + m;
    for(int i=0; i<p; i++)
    {
        if(i<n)
           c[i]=a[i];
        else c[i] = b[i-n];
    }
}
