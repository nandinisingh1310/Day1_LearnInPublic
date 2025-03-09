 //stack using an array
//  #include<iostream>
//  using namespace std;
//  class stack{
//     public:
//     //properties
//     int *arr;
//     int size;
//     int top;
    
//     //behaviour
//     stack(int size){
//         this -> size = size;
//         arr = new int[size];
//         top = -1;
//     }
//         void push(int element){
//             if (size - top > 1){
//                 top++;
//                 arr[top] = element;
//             }else{ 
//                 cout << "STACK OVERFLOW" << endl;
//             }
//         }
//         void pop(){
//             if(top >= 0){
//                 top--;
//             }else{
//                 cout << "STACK UNDERFLOW" << endl;
//             }

//         }
//         int top_element(){
//         if(top >= 0){
//             return arr[top];
//             }else{
//             cout << "STACK is empty" << endl;
//             return -1;
//         }
//     }
//         bool is_empty(){
//             if(top == -1){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//     }
//  };
//  int main(){
//     stack st(3);
//     st.push(56);
//     st.push(45);
//     st.push(34);
//     st.push(69);
//     cout << st.top_element() << endl;

//     // st.pop();

//     // cout << st.top_element() << endl;
//     // st.top_element();
//     // cout << st.top_element() << endl;
//     // st.pop();
//     // cout << st.top_element() << endl;
//     // st.pop();
//     // cout << st.top_element() << endl;
//     if(st.is_empty()){
//         cout << "stack is empty" << endl;
//     }else{
//         cout<< "stack is not empty" << endl;
//     }
    

//  }

//Stack using a vector
#include<iostream>
#include<vector>
using namespace std;
class stack {
vector<int> v;
public:
        void push(int val){ 
            v.push_back(val);
        }
        void pop(){
            v.pop_back();
        }
        int top(){
            return v[v.size() - 1];
        }
        bool empty(){
            return v.size() == 0;
        }
    };
int main(){
 stack s;
 s.push(10);
 s.push(20);
 s.push(30);
 while(!s.empty()){
    cout << s.top() << " ";
    s.pop();
 }
 s.empty();
 cout << endl;
}
