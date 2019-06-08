package com.ijbamboo.pattern.singleton.example.soup;

import com.ijbamboo.pattern.soup.Soup;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:38:39
 */
public class SingleSpoon {
	 private Soup soupLastUsedWith;
	   
	   private static SingleSpoon theSpoon;
	   private static boolean theSpoonIsAvailable = true;
	   
	   private SingleSpoon() {}
	     
	   public static SingleSpoon getTheSpoon() {
	       if (theSpoonIsAvailable) {
	           if (theSpoon == null) {
	               theSpoon = new SingleSpoon();
	           }
	           theSpoonIsAvailable = false;
	           return theSpoon;
	       } else {
	           return null;
	           //spoon not available, 
	           //  could throw error or return null (as shown)
	       }
	   }
	    
	   public String toString() {
	       return "Behold the glorious single spoon!";
	   }
	    
	   public static void returnTheSpoon() {
	       theSpoon.cleanSpoon();
	       theSpoonIsAvailable = true;
	   }     
	   
	   public Soup getSoupLastUsedWith() {
	       return this.soupLastUsedWith;
	   }
	   public void setSoupLastUsedWith(Soup soup) {
	       this.soupLastUsedWith = soup;
	   }


	   public void cleanSpoon() {
	       this.setSoupLastUsedWith(null);
	   } 
}
