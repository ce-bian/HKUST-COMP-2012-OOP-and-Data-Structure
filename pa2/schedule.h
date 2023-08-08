
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> duration_type;

template <typename T>
class Schedule {
public:
	typedef map<duration_type, T> schedule_type;
	typedef typename schedule_type::iterator schedule_it;
    typedef typename schedule_type::const_iterator schedule_const_it;

    Schedule(int start = 0, int end = 24);
    ~Schedule();

	vector<T> operator()(int start, int end);

    int size() const;

    bool isFree(int start, int end);

	void mergeSameContinuous();
    void insert(int start, int end, T item);
    bool remove(int start, int end);
    void remove(string name);

    T summarize(string name, int &total_time) const;

	void debug_print(int indent = 0) const;

private:
    int min_time;
    int max_time;
    schedule_type values;
};

template <typename T>
Schedule<T>::Schedule(int start, int end) {
	min_time = start;
	max_time = end;
}

template <typename T>
Schedule<T>::~Schedule() {
	values.clear();
}

template <typename T>
int Schedule<T>::size() const {
	/*
	 * get the size of values
	 * optional: size() will return size_t, to resolve the warning of implicit conversion, you may use static_cast to convert it to int
	 *
	 * Add your code here!
	 */
    int num=values.size();
    return num;


}

template <typename T>
vector<T> Schedule<T>::operator()(int start, int end) {
    /*
	 * return a vector of T objects whose durations are inside [start, end]
	 * you need to keep the order of the objects!
	 * if [start, end] is invalid, i.e. start >= end, return an empty vector: vector<T>() 
     * if there is no object inside [start, end], return an empty vector: vector<T>() 
	 *  
     * Add your code here!
     * */
	if(start>=end||isFree(start,end))
		return vector<T>();

    vector<T> a;

	for(schedule_const_it it=values.begin();it!=values.end();it++){
       if(it->first.first>=start&&it->first.second<=end){
             a.push_back(it->second);
       }
	}
	return a;


}

template <typename T>
bool Schedule<T>::isFree(int start, int end) {
	/*
	 * if start time is not smaller than end time, return false
	 * if start time is smaller than min_time, return false
	 * if end time is larger than max_time, return false
	 * if [start, end] has collision with any activity in schedule, return false
	 *     [1, 3] and [3, 4] have no collision
	 * otherwise (i.e. [start, end] doesn't have collision with any activity), return true
	 *
	 * Add your code here!
	 * */
	if(start>=end||start<min_time||end>max_time)
	   return false;
	for(schedule_const_it it=values.begin();it!=values.end();it++){
		if((it->first.first<=start&&it->first.second>start)||
				(it->first.first<end&&it->first.second>=end)||
				(it->first.first>=start&&it->first.second<=end)||
				(it->first.first<=start&&it->first.second>=end))
			return false;
	}
	return true;

}

template <typename T>
void Schedule<T>::mergeSameContinuous() {
	/*
	 * merge items with same name AND continuous durations
	 * more detailed instructions can be found on the website
	 *
	 * Add your code here!
	 */


 schedule_it it3=values.begin();
    	 for(schedule_it it=values.begin();it!=values.end();it++){

    	 schedule_it it1=it;
    	 schedule_it it2 =++it;
    	 it--;
    	if(it2!=values.end()){
            if(it1->second.getName()==it2->second.getName()){
        	if(it1->first.second==it2->first.first){
        		it2->second=it1->second+it2->second;
        		T item(it2->second);
        		int start=it1->first.first;
        		int end=it2->first.second;
        		values.erase(it2);
        		values.erase(it1);
        		values[make_pair(start,end)]=item;
        		it3=values.find(make_pair(start,end));
        		break;
        	}
        }
     }
     }


    	 for(schedule_it it=++it3;it!=values.end();it++){
    		 it3--;

    		 if(it->second.getName()==it3->second.getName()){
    		         	if(it3->first.second==it->first.first){
    		         		it3->second=it3->second+it->second;
    		         		T item(it3->second);
    		         		int start=it3->first.first;
    		         		int end=it->first.second;
    		         		values.erase(it3);
    		         		values.erase(it);
    		         		values[make_pair(start,end)]=item;

    	 }
    		 }
    	 }


}

template <typename T>
void Schedule<T>::insert(int start, int end, T item) {
	/*
	 * first add item to values if [start, end] is free, then merge adjacent items with same name (std::map is sorted by default)
	 *
	 * Add your code here!
	 * */
	if(isFree(start,end)){
		values[make_pair(start,end)]=item;
		mergeSameContinuous();
	}


}

template <typename T>
bool Schedule<T>::remove(int start, int end) {
    /*
     * Remove items which are inside [start, end]
	 * return false if the input start >= end, otherwise return true
	 * 
     * Add your code here!
     * */

	if(start>=end||isFree(start,end))
		return false;
	for(schedule_const_it it=values.begin();it!=values.end();){
		if(it->first.first>=start&&it->first.second<=end)
			values.erase(it++);
		else
			it++;
	}

	return true;
}

template <typename T>
void Schedule<T>::remove(string name) {
	/*
	 * Remove items whose names are the same as the input name
	 *
	 * Add your code here!
	 * */
	for(schedule_const_it it=values.begin();it!=values.end();){
		if(name==it->second.getName()){
			values.erase(it++);
		}
		else
			++it;
	}
}

template <typename T>
T Schedule<T>::summarize(string name, int &total_time) const {
	/*
     * If items A, B, D, F in schedule have the same name
     *   1. Calculate the total time of A, B, D, F by summing their durations 
	 *       (duration_of_an_item = end_time - start_time). And assign the result to total_time
     *   2. Return a new item which is calculated by A + B + D + F.
     * If there is no item with name, return an initialized object (its variables do not matter) and keep total_time as 0.
	 *
	 * You might init a new T object and use operator += to sum selected objects
	 *
	 * Add your code here!
	 * */
	T* pt=new T;

	total_time=0;
	for(schedule_const_it it=values.begin();it!=values.end();it++)
	{
		if(name==it->second.getName()){
			total_time+=it->first.second-it->first.first;
         if(total_time==0)
		     *pt=it->second;
         else
        	 *pt=*pt+it->second;

		}
	}
	return *pt;

}

template<typename T>
void Schedule<T>::debug_print(int indent) const {
    string indent1 = string(indent, '\t');

    for (schedule_const_it cit = values.begin(); cit != values.end(); ++cit) {
		cout << indent1 << "duration [" << cit->first.first << ", " << cit->first.second << "]:" << endl;
		cit->second.debug_print(indent + 1);
	}
}

#endif //SCHEDULE_H
