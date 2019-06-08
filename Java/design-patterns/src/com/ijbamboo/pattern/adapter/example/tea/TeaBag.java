package com.ijbamboo.pattern.adapter.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:42:59
 */
public class TeaBag {
	boolean teaBagIsSteeped; 
    
	   public TeaBag() {
	       teaBagIsSteeped = false;
	   }
	   
	   public void steepTeaInCup() {
	       teaBagIsSteeped = true;
	       System.out.println("tea bag is steeping in cup");
	   }
}
