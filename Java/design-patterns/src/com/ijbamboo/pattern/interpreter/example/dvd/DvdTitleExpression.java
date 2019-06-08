package com.ijbamboo.pattern.interpreter.example.dvd;

import java.util.ArrayList;
import java.util.ListIterator;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:23:10
 */
public class DvdTitleExpression extends DvdAbstractExpression {  
	   public String interpret(DvdInterpreterContext 
               dvdInterpreterContext) {
ArrayList titles = dvdInterpreterContext.getAllTitles();
ListIterator titlesIterator = titles.listIterator();
StringBuffer titleBuffer = new StringBuffer("");
boolean first = true;
while (titlesIterator.hasNext()) {
if (!first) {
   titleBuffer.append(", ");
} else {
   first = false;
}    
titleBuffer.append((String)titlesIterator.next());
}
return titleBuffer.toString();
}
}