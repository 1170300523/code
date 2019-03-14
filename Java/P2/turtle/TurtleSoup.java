/* Copyright (c) 2007-2016 MIT 6.005 course staff, all rights reserved.
 * Redistribution of original or derived work requires permission of course staff.
 */
package turtle;

import java.util.List;
import java.util.Set;

import javax.security.auth.kerberos.KerberosKey;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;

public class TurtleSoup {

    /**
     * Draw a square.
     * 
     * @param turtle the turtle context
     * @param sideLength length of each side
     */
    public static void drawSquare(Turtle turtle, int sideLength) {
        //throw new RuntimeException("implement me!");
        for(int i =0;i<4;i++)
    	{
        	turtle.forward(sideLength);
        	turtle.turn(90);
    	}
        
        
    }

    /**
     * Determine inside angles of a regular polygon.
     * 
     * There is a simple formula for calculating the inside angles of a polygon;
     * you should derive it and use it here.
     * 
     * @param sides number of sides, where sides must be > 2
     * @return angle in degrees, where 0 <= angle < 360
     */
    public static double calculateRegularPolygonAngle(int sides) {
        //throw new RuntimeException("implement me!");
    	return  (sides - 2)* 180.0 /sides;
    }

    /**
     * Determine number of sides given the size of interior angles of a regular polygon.
     * 
     * There is a simple formula for this; you should derive it and use it here.
     * Make sure you *properly round* the answer before you return it (see java.lang.Math).
     * HINT: it is easier if you think about the exterior angles.
     * 
     * @param angle size of interior angles in degrees, where 0 < angle < 180
     * @return the integer number of sides
     */
    public static int calculatePolygonSidesFromAngle(double angle) {
        //throw new RuntimeException("implement me!");
    	int k = (int)  Math.round( 360.0 /(180 - angle) ) ;
    	return k;
    }

    /**
     * Given the number of sides, draw a regular polygon.
     * 
     * (0,0) is the lower-left corner of the polygon; use only right-hand turns to draw.
     * 
     * @param turtle the turtle context
     * @param sides number of sides of the polygon to draw
     * @param sideLength length of each side
     */
    public static void drawRegularPolygon(Turtle turtle, int sides, int sideLength) {
        //throw new RuntimeException("implement me!");
    	double degree = 180 - calculateRegularPolygonAngle(sides);
    	  for(int i =0;i<sides;i++)
      	{
          	turtle.forward(sideLength);
          	turtle.turn(degree);
      	}
     
    }

    /**
     * Given the current direction, current location, and a target location, calculate the Bearing
     * towards the target point.
     * 
     * The return value is the angle input to turn() that would point the turtle in the direction of
     * the target point (targetX,targetY), given that the turtle is already at the point
     * (currentX,currentY) and is facing at angle currentBearing. The angle must be expressed in
     * degrees, where 0 <= angle < 360. 
     *
     * HINT: look at http://en.wikipedia.org/wiki/Atan2 and Java's math libraries
     * 
     * @param currentBearing current direction as clockwise from north
     * @param currentX current location x-coordinate
     * @param currentY current location y-coordinate
     * @param targetX target point x-coordinate
     * @param targetY target point y-coordinate
     * @return adjustment to Bearing (right turn amount) to get to target point,
     *         must be 0 <= angle < 360
     */
    public static double calculateBearingToPoint(double currentBearing, int currentX, int currentY,
                                                 int targetX, int targetY) {
        //throw new RuntimeException("implement me!");
    	Double deg;
    	if(currentX == targetX)
    		deg = currentY > targetY ?180 - currentBearing:360 - currentBearing;
    	else if (currentY == targetY) 
    		deg = currentX < targetX ?90 - currentBearing +360 :270 -currentBearing;
    	else 
    	 deg = 450 -  Math.atan((double)(targetY-currentY)/(targetX - currentX )) /Math.PI *180 -currentBearing;
    	//deg =  deg > currentBearing?(deg - currentBearing):(360 - currentBearing + deg);
    	if(targetX<currentX &&targetY<currentX)deg +=180;
    	return deg%360;
    }

    /**
     * Given a sequence of points, calculate the Bearing adjustments needed to get from each point
     * to the next.
     * 
     * Assumes that the turtle starts at the first point given, facing up (i.e. 0 degrees).
     * For each subsequent point, assumes that the turtle is still facing in the direction it was
     * facing when it moved to the previous point.
     * You should use calculateBearingToPoint() to implement this function.
     * 
     * @param xCoords list of x-coordinates (must be same length as yCoords)
     * @param yCoords list of y-coordinates (must be same length as xCoords)
     * @return list of Bearing adjustments between points, of size 0 if (# of points) == 0,
     *         otherwise of size (# of points) - 1
     */
    public static List<Double> calculateBearings(List<Integer> xCoords, List<Integer> yCoords) {
        //throw new RuntimeException("implement me!");
    	List<Double> re = new ArrayList<Double>();
    	int len = xCoords.size();
    	Double deg = 0.0;
    	for(int i=0;i<len -1;i++)
    	{
    	Double k = calculateBearingToPoint(deg, xCoords.get(i), yCoords.get(i),
    				xCoords.get(i+1) , yCoords.get(i+1));
    	re.add(k);
    	deg  = k + deg;
    	
    	deg %= 360;
    	
    		
    	}
  
    	return re;
    }
    
    /**
     * Given a set of points, compute the convex hull, the smallest convex set that contains all the points 
     * in a set of input points. The gift-wrapping algorithm is one simple approach to this problem, and 
     * there are other algorithms too.
     * 
     * @param points a set of points with xCoords and yCoords. It might be empty, contain only 1 point, two points or more.
     * @return minimal subset of the input points that form the vertices of the perimeter of the convex hull
     */
    public static Set<Point> convexHull(Set<Point> points) {
        
    	if(points.size()<=3)return points;
    	Set<Point> s = new HashSet<Point>();
    	double turn = 180,deg = 0;
    	//Iterator<Point> k = points.iterator();
    	Point lpoint = points.iterator().next();
    	//Point npoint = k.next();
    	
    	
    	
    	for(Point i:points)
    		if((i.x() <= lpoint.x()) && (i.y()<lpoint.y()))
    			lpoint = i;
    			
    	
    	s.add(lpoint);
    	Point npoint = lpoint;
    	Point hpoint = null;

    	int k = 0;
    	do
	    {	turn = 360; //³õÊ¼»¯×ª½Ç
    		for(Point i:points)
	    	{	//if(s.contains(i))continue;
    			if(i.equals(npoint))continue;
	    		double k1 = calculateBearingToPoint(deg,(int)npoint.x(),(int)npoint.y(),(int)i.x(),(int)i.y());
	    		System.out.println(deg+" "+(int)npoint.x()+","+(int)npoint.y()+" "+(int)i.x()+","+(int)i.y()+"-->deg "+k1);
	    		if(k1 < turn)
	    			{
	    			turn = k1;
	    		    hpoint = i;
	    			}		
	    	}
    		npoint = hpoint;
    		deg = (deg + turn)%360;
	    	s.add(npoint);
	    	k++;
    	}while(!lpoint.equals(npoint) && k<=points.size());	
    	
    		for(Point i:s)
    		{
    			System.out.println(i.x()+","+i.y());
    		}
    	System.out.println(s.size());
    	return s;
    }
    
    /**
     * Draw your personal, custom art.
     * 
     * Many interesting images can be drawn using the simple implementation of a turtle.  For this
     * function, draw something interesting; the complexity can be as little or as much as you want.
     * 
     * @param turtle the turtle context
     */
    public static void drawPersonalArt(Turtle turtle) {
        //throw new RuntimeException("implement me!");
    	
    	for(int i =200;i>38;i--)
    	{
    		turtle.forward(200 - i);
    		turtle.turn(i);
    	}
    }

    /**
     * Main method.
     * 
     * This is the method that runs when you run "java TurtleSoup".
     * 
     * @param args unused
     */
    public static void main(String args[]) {
        DrawableTurtle turtle = new DrawableTurtle();

        //drawSquare(turtle, 40);
        //drawRegularPolygon(turtle, 7, 50);
        drawPersonalArt(turtle);

         //draw the window
        turtle.draw();
        System.out.println(calculateBearingToPoint(0.0, 0, 0, 0, 1));
        List<Integer> xcoords = new ArrayList<>();
        List<Integer> ycoords = new ArrayList<>();
         int[] x = {0,0,1,1};
         int[] y = {1,0,0,1};
         for(int i:x)
        	 xcoords.add(i);
         for(int j:y)
        	 ycoords.add(j);
         System.out.println(calculateBearings(xcoords,ycoords));
        	 
        
        
        
        
        
    }

}
