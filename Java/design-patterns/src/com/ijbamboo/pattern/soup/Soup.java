package com.ijbamboo.pattern.soup;

import java.util.ArrayList;
import java.util.ListIterator;

/**
 * ��
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����1:39:52
 */
public abstract  class Soup {
	ArrayList soupIngredients = new ArrayList(); //������   
	   String soupName;//������
	   
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
