/* This program determines whether two given files are similar */

#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  //declare the file streams for the two files
  ifstream file1;
  ifstream file2;

  //declare two strings to store the two file names
  string filename1;
  string filename2;

  //open filename1
  cout << "Please enter the name of the first file: ";
  cin >> filename1;
  file1.open(filename1.c_str());
  if(!file1){
	cout << "\"" << filename1 << "\" is not a valid file!" << endl;
	return 1;
  }
  
  //open filename2
  cout << "Please enter the name of the second file: ";
  cin >> filename2;
  file2.open(filename2.c_str());
  if(!file2){
	cout << "\"" << filename2 << "\" is not a valid file! Ending program." << endl;
	return 1;
  }

  //create two maps<string, int> and for each new word, 
  //store the word into the map and increment count
  map<string, int> Data1;
  map<string, int> Data2;

  //vector of links for the webcrawl
  vector<string> links;
  
  //store words of file into the maps
  int htmlIgnore = 0;//ignores letters inside of html tags
  int link = 0;
  string nonlinkword;
  while( !file1.eof() ){//while not the end of the file
    //add the word as a string, and the parse through that
    string word;
    file1 >> word;
    //if the previous word signalled a link, then new word is the link
    //and take the rest of the link as the new word	
    if(link && word.size()){
	//generally some of the link is good code, namely 
	for(int j=0; j<word.size(); j++){
		if(word[j] == '>'){
			//add the rest of the word to nonlinkword
			nonlinkword.assign(word.end()-j, word.end());
			word.erase(j,word.size()-j);
		}
	}
	//word.erase(word.size()-1,2);
	links.push_back(word);
	//set word equal to the rest of the nonlinkword
	word = nonlinkword;
    }
	
    int erased = 0;
    int i = 0;
    while( i<word.size()){
	if(word[i] == '<'){//this means to ignore the text until a '>' tag
	    if(word[i+1]=='a'){//this is a link to be computed
		link = 1;
		break;
	    } else {
		htmlIgnore = 1;
	    }
	}
	else if(word[i] == '>'){//check if we should stop ignoring the letters
		htmlIgnore = 0;
		link = 0;
	}
	if(!isalnum(word[i]) || htmlIgnore || link){ //removes non-alphanumeric, or if htmlIgnore is on
		word.erase(i,1);
		//when it removes a letter, don't increment the count
		erased = 1;
	} else {
		word[i] = tolower(word[i]);
		erased = 0;
	}
	//only increment count if a letter wasn't erased (to avoid skipping double punctuation)
	if(!erased) i++;
    }
    //if the string is not empty and html ignore is not on, add it to the map 
    if(word.size() && !htmlIgnore && !link) Data1[word]++;

  }

  //Now parse through the second file
  htmlIgnore = 0;//ignores letters inside of html tags
  link = 0;
  nonlinkword;
  while( !file2.eof() ){//while not the end of the file
    //add the word as a string, and the parse through that
    string word;
    file2 >> word;
    //if the previous word signalled a link, then new word is the link
    //take the rest of the link as the new word	
    if(link && word.size()){
	//generally some of the link is good code, namely 
	for(int j=0; j<word.size(); j++){
		if(word[j] == '>'){
			//add the rest of the word to nonlinkword
			nonlinkword.assign(word.end()-j, word.end());
			word.erase(j,word.size()-j);
		}
	}
	links.push_back(word);
	//set word equal to the rest of the nonlinkword
	word = nonlinkword;
    }
	
    int erased = 0;
    int i = 0;
    while( i<word.size()){
	if(word[i] == '<'){//this means to ignore the text until a '>' tag
	    if(word[i+1]=='a'){//this is a link to be computed
		link = 1;
		break;
	    } else {
		htmlIgnore = 1;
	    }
	}
	else if(word[i] == '>'){//check if we should stop ignoring the letters
		htmlIgnore = 0;
		link = 0;
	}
	if(!isalnum(word[i]) || htmlIgnore || link){ //removes non-alphanumeric, or if htmlIgnore is on
		word.erase(i,1);
		//when it removes a letter, don't increment the count
		erased = 1;
	} else {
		word[i] = tolower(word[i]);
		erased = 0;
	}
	//only increment count if a letter wasn't erased (to avoid skipping double punctuation)
	if(!erased) i++;
    }
    //if the string is not empty and html ignore is not on, add it to the map 
    if(word.size() && !htmlIgnore && !link) Data2[word]++;

  }

  //print out all the keys of the first file using the mapiter
  map<string, int>::iterator mapiter;
  map<string, int>::iterator mapiter2;
  set<string> D1, D2;

  //Store all of the first file into the file words.txt
  ofstream wordStore;
  wordStore.open("words.txt");
  //store the unique words in words.txt 
  wordStore << "The first file, " << filename1 << " has " << Data1.size() << " unique words." << endl;
  for (mapiter = Data1.begin(); mapiter != Data1.end(); mapiter++) {
    wordStore << "The word "<< mapiter->first << " occurs " << mapiter->second << " times."<< endl;
  }
  //create two new set<string> to compute the Jacard intersection and union
  for (mapiter = Data1.begin(); mapiter != Data1.end(); mapiter++) {
    D1.insert(mapiter->first);
  }
  for (mapiter = Data2.begin(); mapiter != Data2.end(); mapiter++) {
    D2.insert(mapiter->first);
  }

  //compute Jaccard similarity of the two files
  set<string> jacUnion;
  set<string> jacIntersection;

  set_intersection(D1.begin(), D1.end(), D2.begin(), D2.end(), inserter(jacIntersection, jacIntersection.end()));
  set_union(D1.begin(), D1.end(), D2.begin(), D2.end(), inserter(jacUnion, jacUnion.begin()));

  cout << "Intersection size: "<<jacIntersection.size() << " Union size: " << jacUnion.size() << endl;
  double similarity = (double)jacIntersection.size() / jacUnion.size();
  cout << "The Jaccard similarity of the two files is: " << similarity << endl;

  //store links into webcrawl.txt
  ofstream webcrawl;
  webcrawl.open("webcrawl.txt");
  for(int i=0; i<links.size(); i++)
	webcrawl << links[i] << endl;

  return 0;
}
