package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:39:44
 */
public class DvdNameAllCapStrategy extends DvdNameStrategy {
	   public String formatDvdName(String dvdName, char charIn) {
	       return dvdName.toUpperCase();
	   }
	}
