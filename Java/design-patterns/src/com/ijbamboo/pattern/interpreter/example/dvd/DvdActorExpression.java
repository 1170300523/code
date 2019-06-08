package com.ijbamboo.pattern.interpreter.example.dvd;

import java.util.ArrayList;
import java.util.ListIterator;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:22:25
 */
public class DvdActorExpression extends DvdAbstractExpression {  
	   public String interpret(DvdInterpreterContext dvdInterpreterContext) {
	       ArrayList actors = dvdInterpreterContext.getAllActors();
	       ListIterator actorsIterator = actors.listIterator();
	       StringBuffer titleBuffer = new StringBuffer("");
	       boolean first = true;
	       while (actorsIterator.hasNext()) {
	           if (!first) {
	               titleBuffer.append(", ");
	           } else {
	               first = false;
	           }
	           titleBuffer.append((String)actorsIterator.next());
	       }
	       return titleBuffer.toString();
	   }
	}
