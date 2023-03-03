#include "city.cpp"

float routeDis(float xCord1, float yCord1, float xCord2, float yCord2){
  return sqrt(pow(xCord2 - xCord1,2) + pow(yCord2 - yCord1, 2) * 1.0);
}

void checkAdj(vector<vector<string>> adj, string city){
  for (int i = 0; i < adj.size(); i++){
    for (int j = 0; j < adj.at(i).size(); j++){
      cout << adj[i][j] << " ";
      /*if (city == adj.at(i).at(j)){
          cout << adj[i][j] << " ";
      }*/
      cout << endl;
    }
  }
}

int main(){
  vector <city> cityVec, visted;
  vector<vector<string>> adjVec;
  vector<string> tempAdj, rowCord, rowAdj;
  city tempCities;
  string inRecCord, inRecAdj, tempStrCord, tempStrAdj;
  ifstream inCordFile, inAdjFile;
  inCordFile.open("Coordinates.txt");
  inAdjFile.open("Adjacencies.txt");
  if (inCordFile.is_open() && inAdjFile.is_open()){
    cout << "They both opened correctly!\n";
  }
  inCordFile >> inRecCord;
  inAdjFile >> inRecAdj;
  while (inCordFile.good()){
    rowCord.clear();
    stringstream inSSCord(inRecCord);
    while (getline(inSSCord, tempStrCord, ',')){
      rowCord.push_back(tempStrCord);
    }
    tempCities.cityName = rowCord[0];
    tempCities.xCord = stof(rowCord[1]);
    tempCities.yCord = stof(rowCord[2]);
    cityVec.push_back(tempCities);
    inCordFile >> inRecCord;
  }
  while (inAdjFile.good()){
    rowAdj.clear();
    stringstream inSSAdj(inRecAdj);
    while(getline(inSSAdj, tempStrAdj, ',')){
      rowAdj.push_back(tempStrAdj);
    }
    adjVec.push_back(rowAdj);
    inAdjFile >> inRecAdj;
  }
  for (int i = 0; i < cityVec.size(); i++){
    cout << cityVec.at(i).cityName << ": " << cityVec.at(i).xCord << "," << cityVec.at(i).yCord << endl;
  }
  checkAdj(adjVec, "Attica");
}