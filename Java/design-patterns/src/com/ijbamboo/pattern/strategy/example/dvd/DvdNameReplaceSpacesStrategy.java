package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:40:31
 */
public class DvdNameReplaceSpacesStrategy extends DvdNameStrategy {
	   public String formatDvdName(String dvdName, char charIn) {
	       return dvdName.replace(' ', charIn);
	   }
	}
