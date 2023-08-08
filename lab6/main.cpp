#include <set>
#include <algorithm>
#include <string>
#include <iostream>
#include <list>
#include <map>
using namespace std;

void printSetUsingIterator(const set<string>& s) {
   // TODO: Print a set of string using iterator
	set<string>:: const_iterator it;
	cout<<"{";
	for(it=s.begin();it!=s.end();it++){
		cout<<*it<<", ";
       }
	cout<<"}"<<endl;

}

void printListUsingIterator(const list<string>& s) {
   // TODO: Print a list of string using iterator
	list<string>::const_iterator it;
	cout<<"{";
	for(it=s.begin();it!=s.end();it++){
			cout<<*it<<", ";
	}
	cout<<"}"<<endl;

}

void printMapUsingIterator(const map<string,int>& s) {
   // TODO: Print a map using iterator
	map<string,int>::const_iterator it;
		for(it=s.begin();it!=s.end();it++){
				cout<<"Key: "<<it->first<<"   Value: "<<it->second<<endl;
		}
}


//TODO: You may need to define a comparator function yourself here (for the sorting task)
void compare(const set<string>s1,const set<string>s2,set<string>&set3){
	set<string>::const_iterator it1;
	set<string>::const_iterator it2;

	for(it1=s1.begin();it1!=s1.end();it1++){
		for(it2=s2.begin();it2!=s2.end();it2++){
			if(*it1==*it2){
			   set3.insert(*it1);
			}
		}
	}

}



int main() {

	cout << endl;
	cout << "************************** Part1: set **************************";
	cout << endl;

	set<string> Fictions, Movies;
	Fictions.insert("The Time Machine");
	Fictions.insert("Harry Potter");
	Fictions.insert("The Lord of the Rings");

	Movies.insert("The Shawshank Redemption");
	Movies.insert("City of God");
	Movies.insert("The Lord of the Rings");
	Movies.insert("Harry Potter");

	cout << "Set Fictions Content =" ;
	printSetUsingIterator(Fictions);
	cout << "Set Movies Content =" ;
	printSetUsingIterator(Movies);

    // Part 1 TODO: Complete the set operations: intersection
	set<string> interSet;
   // ADD YOUR CODE HERE
	compare(Fictions,Movies,interSet);



   cout << "Fictions intersect Movies Content = ";
   printSetUsingIterator(interSet);

   cout << endl;
	cout << "************************** Part2: list **************************";
   cout << endl;

	// Merge Fictions and Movies to listR
	list<string> listR ;

   // Part 2 TODO: Merge Fictions and Movies to listR
   // ADD YOUR CODE HERE
	set<string>::const_iterator it;
	set<string>::const_iterator it1;
	   for(it=Fictions.begin();it!=Fictions.end();it++){
		   listR.push_back(*it);
	   }
	   for(it1=Movies.begin();it1!=Movies.end();it1++){
		   listR.push_back(*it1);
	   }
	   listR.sort();



	cout << "List R Content = ";
	printListUsingIterator(listR);

	// Part 2 TODO:
    //Add a new string "Saw" at the end of the list
    //Add a new string "Avenger" at the head of the list
    // ADD YOUR CODE HERE

	listR.push_front("Avenger");
	listR.push_back("Saw");



	cout << "New R Content = ";
	printListUsingIterator(listR);

	 // Sort listR by movie name length ascendingly
    // ADD YOUR CODE HERE
	list<string>:: const_iterator it3 ;
	list<string> sortR;
	for(it3=listR.begin();it3!=listR.end();it3++){
		sortR.push_back(*it3);
	}
	listR.clear();
	list<string>:: const_iterator it4;
	//list<string>:: const_iterator it5;

	//listR.push_back(*sortR.begin());
	while(sortR.size()!=0){
		string temp=*(sortR.begin());
		list<string>::const_iterator it6=sortR.begin();
	for(it4=sortR.begin();it4!=sortR.end();it4++){
	   if(it4->length()<temp.length()){
		   it6=it4;
		   temp=*it4;
	       }
	   }
	  sortR.erase(it6);
	  listR.push_back(temp);

	}


	cout << "Sorted R Content = ";
	printListUsingIterator(listR);


   cout << endl;
	cout << "************************** Part3: map **************************";
   cout << endl;

    //map
	map<string,int> mapMovie;
	mapMovie.insert(make_pair("The Shawshank Redemption",1994));
	mapMovie.insert(make_pair("City of God",2002));
	mapMovie.insert(make_pair("The Lord of the Rings", 2002));
	mapMovie.insert(make_pair("Star Wars", 1977));
	mapMovie.insert(make_pair("Forest Gump", 1994));
	cout << "mapMovie Content: "<<endl;
	printMapUsingIterator(mapMovie);

   //Part3 TODO : Complete element search and deletion in mapMovie here
    // search "Star Wars" in map
    // ADD YOUR CODE HERE

     map<string,int>::const_iterator it7;
     for(it7=mapMovie.begin();it7!=mapMovie.end();it7++){
    	 if(it7->first=="Star Wars"){
    		 cout<<"Key found, the value is "<<it7->second<<endl;
    		 break;
    	 }
     }

    // delete "City of God" in map
    // ADD YOUR CODE HERE

     map<string, int>:: const_iterator it8;
     for(it8=mapMovie.begin();it8!=mapMovie.end();it8++){
    	 if(it8->first=="City of God"){
    		 mapMovie.erase(it8);
    		 break;
    	 }
     }

	cout << "mapMovie Content after deletion: "<<endl;
	printMapUsingIterator(mapMovie);



	return 0;
}
