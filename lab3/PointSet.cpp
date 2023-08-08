/*
5eeew * PointSet.cpp
 *
 */

#include "PointSet.h"
#include <iostream>
using namespace std;


PointSet::PointSet()
{
   // This function is already completed.

   cout << "Initialized by PointSet's default constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked
   numPoints = 0;
   points = NULL;
}

PointSet::PointSet(const Point3D points_in[], int num_in)
{
   cout << "Initialized by PointSet's other constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
      Point3D *pointsarray=new Point3D[num_in];
      for(int i=0;i<num_in;i++){
    	  pointsarray[i]=Point3D(points_in[i]);
      }
      points=pointsarray;
      numPoints=num_in;

}

PointSet::PointSet(const PointSet & s)
{
   cout << "Initialized by PointSet's copy constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
      numPoints=s.numPoints;
      //Point3D newarray[s.numPoints];
      Point3D* pointsarray=new Point3D[s.numPoints];
       for(int i=0;i<s.numPoints;i++){
     	  pointsarray[i]=s.points[i];
       }
       //this->points=pointsarray;
      points=pointsarray;

}

PointSet::~PointSet()
{
    cout<<"PointSet's destructor!" <<endl;
    // This cout statement is for learning purpose only, which shows when the desstructor will be invoked

     // TODO: add your code here
    delete[] points;
    points=NULL;
}


void PointSet::addPoint(const Point3D& p)
{
   // TODO: add your code here

    //Point3D const *newpoint=new Point3D;
   // newpoint=&p;
    //points[numPoints]=*newpoint;
	//Point3D newarray[numPoints+1];
	Point3D* pointsarray=new Point3D[numPoints+1];
	for(int i=0;i<numPoints;i++){
		pointsarray[i]=points[i];
	}
	pointsarray[numPoints]=p;
	delete[] points;
	points=pointsarray;
	numPoints++;

}

bool PointSet::contains(const Point3D& p) const
{
   // TODO: add your code here
	for(int i=0;i<numPoints;i++){
		if(points[i].equal(p))
			return true;
	}
	return false;

}

void PointSet::removeFirstPoint()
{
   // TODO: add your code here
	if(numPoints==0){
		cout<<"No points."<<endl;
		return;
	}
	else{
		Point3D* pointsarray=new Point3D[numPoints-1];
		for(int i=1;i<numPoints;i++){
			pointsarray[i-1]=points[i];
		}
		delete[] points;
		points=pointsarray;
	    numPoints--;
	}

}
void PointSet::removeAll()
{
   // TODO: add your code here
   if(numPoints==0)
	   return;
   delete [] points;
   points=NULL;
   numPoints=0;
}

void PointSet::print() const
{
  // This function is already completed.

   if (numPoints == 0) {
      cout << "The PointSet is empty!" << endl;
      return;
   }
   cout << "Number of points: " << numPoints << endl;;
   cout << "points: " << endl;
   for (int i = 0; i < numPoints; i++)
   {
      points[i].print();
      cout << endl;
   }
}
