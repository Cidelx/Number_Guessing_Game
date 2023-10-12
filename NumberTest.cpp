#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>

using namespace std;

vector<int> attemptsTaken; 

int main() {
  srand(time(0));
  
  int level;
  cout << "Choose difficulty level (1-3): ";
  cin >> level;
  
  int maxNum;
  switch(level) {
    case 1: maxNum = 10; break;
    case 2: maxNum = 100; break;
    case 3: maxNum = 1000; break;
  }
  
  int secretNum = rand() % maxNum + 1;
  
  int guess;
  int tries = 0;
  
  do {
    cout << "Enter your guess (" << 1 << "-" << maxNum << "): ";
    cin >> guess;
    tries++;
    
    attemptsTaken.push_back(tries);
    
    if(guess > secretNum) {
      cout << "Too high!" << endl;
    } else if(guess < secretNum) {
      cout << "Too low!" << endl;
    } else {
      cout << "You got it in " << tries << " tries! Your attempts: ";
      for(int i=0; i<attemptsTaken.size(); i++) {
        cout << attemptsTaken[i] << " "; 
      }
      cout << endl;
    }
  } while(guess != secretNum);
  
  return 0;
}