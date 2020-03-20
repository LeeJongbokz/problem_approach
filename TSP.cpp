#include <iostream>
#include <vector>
#include <cstring> 

using namespace std;

const int INF = 999999999;

int N;
int W[20][20];
bool visited[20];
int minSum = INF; 

void recursive(vector<int> &city, int& tempSum, int start){
    
    if(minSum < tempSum){
        return; 
    }
    
    if(city.size() == N){
        
        int len = city.size(); 
        int num = city.back();
        
        if(W[num][city[0]] != 0){
            tempSum += W[num][city[0]];
        }else{
            return; 
        }
            
        if(minSum > tempSum){
            minSum = tempSum;
        }
        
        tempSum -= W[num][city[0]]; 
        
        return;
        
    }
    
    
    
    for(int i=1; i<=N; i++){
        if( (visited[i] == false) && (W[start][i] != 0) ){
            visited[i] = true;
            city.push_back(i);
            tempSum += W[start][i]; 
                
            recursive(city, tempSum, i);
            
            city.pop_back();
            tempSum -= W[start][i]; 
            visited[i] = false; 
        }
    }
    
    
    
    
    
}





int main(){
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> W[i][j];
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    
	vector<int>city;

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(visited));
		city.clear();
		city.push_back(i);
		visited[i] = true;
		int sum = 0;
		recursive(city, sum, i);

	}

    
    cout << minSum; 
    
      
    
}
