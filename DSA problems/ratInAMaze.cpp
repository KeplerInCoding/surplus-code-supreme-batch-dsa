//rat in a maze 
#include <iostream>
using namespace std;
#include  <vector>



void map(vector <vector <int>>& maze, int i, int j, vector <char>& route){
  // cout<<"current i and j : "<<i<<" "<<j<<endl;
  // cout<<"route : "<<endl;
  // for(auto i:route) cout<<i<<"";
  // cout<<endl;

  //base condition-> reached destination
  if(i==(maze.size()-1) && j==(maze.size()-1)) {
    for(auto k: route) cout<<k<<" ";
    cout<<endl;
    return;
  }


  //set current to zero
  maze[i][j]=0; 

  //solve one case

  //move down if poss 
  if(i<(maze.size()-1) && maze[i+1][j]){
    route.push_back('D');
    map(maze, i+1, j, route);
    route.pop_back();
  }
  //move right if poss
  if(j<(maze.size()-1) && maze[i][j+1]){
    route.push_back('R');
    map(maze, i, j+1, route);
    route.pop_back();
  }
  
 
  //move left if poss
  if(j>0 && maze[i][j-1]){
    route.push_back('L');
    map(maze, i, j-1, route);
    route.pop_back();
  }
  

  //move up if poss
  if(i>0 && maze[i-1][j]){
    route.push_back('U');
    map(maze, i-1, j, route);
    route.pop_back();
  }

  // Reset current cell for backtracking
  maze[i][j] = 1;


  return;

}

int main() {
  vector <vector <int>> maze{{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  vector <char> route;
  int i = 0; 
  int j = 0;
  cout<<"the route is : "<<endl;
  map(maze, i, j, route);

  return 0;
}