package com.ijbamboo.pattern.adapter.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:44:04
 */
public class LooseLeafTea {
	boolean teaIsSteeped; 
    
	   public LooseLeafTea() {
	       teaIsSteeped = false;
	   }
	   
	   public void steepTea() {
	       teaIsSteeped = true;
	       System.out.println("tea is steeping");
	   }
	}
