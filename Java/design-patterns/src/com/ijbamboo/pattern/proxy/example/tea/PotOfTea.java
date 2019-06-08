package com.ijbamboo.pattern.proxy.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����9:09:15
 */
public class PotOfTea implements PotOfTeaInterface {  
	   public PotOfTea() {
	       System.out.println("Making a pot of tea");
	   }
	   
	   public void pourTea() {
	       System.out.println("Pouring tea");
	   }   
	}