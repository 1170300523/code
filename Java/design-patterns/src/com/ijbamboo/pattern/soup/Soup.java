package com.ijbamboo.pattern.soup;

import java.util.ArrayList;
import java.util.ListIterator;

/**
 * 汤
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午1:39:52
 */
public abstract  class Soup {
	ArrayList soupIngredients = new ArrayList(); //汤配料   
	   String soupName;//汤名字
	   
	   public String getSoupName()
	   {
	       return soupName;
	   }
	   
	   public String toString()
	   {
	        StringBuffer stringOfIngredients = new StringBuffer(soupName);
	        stringOfIngredients.append(" Ingredients: ");
	        ListIterator soupIterator = soupIngredients.listIterator();
	        while (soupIterator.hasNext())
	        {
	            stringOfIngredients.append((String)soupIterator.next());
	        }
	        return stringOfIngredients.toString();
	   }
}
