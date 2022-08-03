#include <iostream>
#include <math.h>
using namespace std;
class Minheap
{
public:
int *harr;
int capacity;
int heap_size;
 Minheap(int cap)
 {
    heap_size=0;
    capacity=cap;
    harr=new int[cap]; 
 }
 void linearsearch(int val)
 {
     for(int i=0; i<val; i++){
         if(harr[i]==val)
         {
      cout<<"Value found"<<endl;
      return ;
         }
     }
     cout<<"Value not found"<<endl;
 }
 void print(){
     for(int i=0; i<heap_size; i++)
     {
        cout<<harr[i]<<endl;
     }
 }
 int height()
 {
     return ceil(log2(heap_size+1))-1;
 }
};
int main()
{
 int n;
 cout<<"Enter the size of the heap : ";
 cin>>n;
 Minheap obj(n);
 int option ,value;
 do
 {
     cout<<"What operation do you want to perform  : "<<endl;
     cout<<"1. Inset the key: "<<endl;
     cout<<"2. Search Key/Node: "<<endl;
     cout<<"3. Delete Key/Node."<<endl;
     cout<<"4. Get Min: "<<endl;
     cout<<"5. Extract Min"<<endl;
     cout<<"6. Height of Heap"<<endl;
     cout<<"7. Print/Traversal Heap values."<<endl;
     cout<<"8. Clear Screen."<<endl;
     cout<<"0. Exit Program."<<endl;
     cin>>option;
     switch(option)
     {
         case 0: break;
         case 1: 
         cout<<"Insert Operation- ";
         cout<<"Enter value in Insert Heap: ";
         cin>>value;
         //obj.Insert(value);
         break;
         case 2: 
         cout<<"Search Operation- ";
         cout<<"Enter value search in heap: ";
         cin>>value;
         obj.linearsearch(value);
         break;
         case 3: 
         cout<<"Delete Operation- ";
         cout<<"Enter index of heap array to be deleted: ";
         cin>>value;
         //obj.deletekey(valiue);
         break;
         case 4: 
         cout<<"Get Min value- ";
         //cout<<obj.getmin();<<endl;
         break;
         case 5: 
         cout<<"Extract min value- ";
         //cout<<obj.Extractmin();<<endl;
         break;
         case 6: 
         cout<<"Heap height tree: "<<obj.height()<<endl;
         break;
         case 7: 
         cout<<"Print Heap array : "<<endl;
         obj.print();
         break;
         case 8: 
         system("cls");
         break;
         default: break;
     }
 } while (option!=0);
 return 0;
}