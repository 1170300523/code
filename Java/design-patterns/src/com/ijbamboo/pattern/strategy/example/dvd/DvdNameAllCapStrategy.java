package com.ijbamboo.pattern.strategy.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:39:44
 */
public class DvdNameAllCapStrategy extends DvdNameStrategy {
	   public String formatDvdName(String dvdName, char charIn) {
	       return dvdName.toUpperCase();
	   }
	}
