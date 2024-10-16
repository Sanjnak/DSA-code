#include<iostream>
using namespace std;

int main(){
    
    int m,n;
    cout << "Enter row size for array: ";
    cin >> m;
    cout << "Enter column size for array: ";
    cin >> n;
    int arr[m][n] = {0};

    cout << "Enter "<< m*n <<" elements: "<<endl;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    cout << "Matrix is : "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int nonNull = 0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != 0){
                nonNull++;
            }
        }
    }

    if(nonNull <= (m*n)/4){

        int sparseArray[nonNull+1][3];
        sparseArray[0][0] = nonNull+1;
        sparseArray[0][1] = 3;
        sparseArray[0][2] = nonNull;

        int k = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j] != 0){
                   sparseArray[k][0] = i;
                   sparseArray[k][1] = j;
                   sparseArray[k][2] = arr[i][j];
                   k++;
                }
            }
        }

        cout << "Sparse Array(Matrix) is:"<<endl;

        for(int i=0; i<=nonNull; i++){
            for(int j=0; j<3; j++){
                cout << sparseArray[i][j] <<" ";
            }
            cout<<endl;
        }
    }else{
        cout << "Sparse array cannot be created!";
    }


    return 0;
}