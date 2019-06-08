package com.ijbamboo.pattern.iterator.example.dvd;

/**
 * @author 竹子
 * @Description 
 * @version 1.0
 * 2018年2月3日 下午9:25:56
 */
public interface DvdListIterator {
	   public void first();
	   public void next();  
	   public boolean isDone();
	   public String currentItem();
	}