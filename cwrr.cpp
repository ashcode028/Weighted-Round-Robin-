//
// Created by ashita on 30/04/21.
//
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <queue>

void send(char &front);

using namespace std;
int main(){
    int n;
    cout<<"Enter no of queues"<<endl;
    cin>>n;
    int w[n];
    std::deque<char> q[n];
   cout<<"Enter weight of each queue"<<endl;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cout<<"Enter values in each queue in each line separated with ';'"<<endl;
    std::string str[n];
    cin>>ws;
    for(int i=0;i<n;i++){
        getline(cin,str[i]);
    }
    int check=0;
    for(int i=0;i<n;i++){
        std::string del=";";
        size_t pos = 0;
        char* token;
        std::string temp;
        while ((pos = str[i].find(del)) != std::string::npos) {
            temp = str[i].substr(0, pos);
            token=const_cast<char*>(temp.c_str());
            //std::cout << token[0] << std::endl;
            q[i].push_back(token[0]);
            check++;
            str[i].erase(0, pos + del.length());
        }
    }
    int c;
    cout<<"Output:Processes per cycle:"<<endl;
    while(check-->0){
        for(int i=0;i<n;i++){
            c=0;
            while((!q[i].empty()) &&(c<w[i])){
                send(q[i].front());
                q[i].pop_front();
                check--;
                c+=1;
            }
        }
        cout<<endl;
    }
    return 0;
}

void send(char &front) {
    std::cout<<front<<" ";
}
/*Input
3
5 2 3
A;B;C;D;E;F;G;
U;V;W;
X;Y;
 */