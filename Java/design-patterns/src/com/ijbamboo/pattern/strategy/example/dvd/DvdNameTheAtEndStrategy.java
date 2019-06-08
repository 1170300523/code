package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:40:07
 */
public class DvdNameTheAtEndStrategy extends DvdNameStrategy {
	   public String formatDvdName(String dvdName, char charIn) {
	       if (dvdName.startsWith("The ")) {
	           return new String(dvdName.substring(4, 
	             (dvdName.length())) + ", The");
	       }
	       if (dvdName.startsWith("THE ")) {
	           return new String(dvdName.substring(4, 
	             (dvdName.length())) + ", THE");
	       }       
	       if (dvdName.startsWith("the ")) {
	           return new String(dvdName.substring(4, 
	             (dvdName.length())) + ", the");
	       }         
	       return dvdName;
	   }
	}