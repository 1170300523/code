package com.ijbamboo.pattern.interpreter.example.dvd;

import java.util.ArrayList;
import java.util.ListIterator;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:22:49
 */
public class DvdActorTitleExpression extends DvdAbstractExpression {
	   String title;
	   
	   public DvdActorTitleExpression(String title) {
	       this.title = title;
	   }
	    
	   public String interpret(DvdInterpreterContext dvdInterpreterContext) {
	       ArrayList actorsAndTitles = 
	           dvdInterpreterContext.getActorsForTitle(title);
	       ListIterator actorsAndTitlesIterator = 
	           actorsAndTitles.listIterator();
	       StringBuffer actorBuffer = new StringBuffer("");
	       boolean first = true;
	       while (actorsAndTitlesIterator.hasNext()) {
	           if (!first) {
	               actorBuffer.append(", "); 
	           } else {
	               first = false;
	           }
	           actorBuffer.append((String)actorsAndTitlesIterator.next());
	       }
	       return actorBuffer.toString();
	   }
	}