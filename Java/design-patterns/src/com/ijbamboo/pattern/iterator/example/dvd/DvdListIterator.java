package com.ijbamboo.pattern.iterator.example.dvd;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:25:56
 */
public interface DvdListIterator {
	   public void first();
	   public void next();  
	   public boolean isDone();
	   public String currentItem();
	}