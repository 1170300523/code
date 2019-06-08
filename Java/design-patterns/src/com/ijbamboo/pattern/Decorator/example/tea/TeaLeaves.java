package com.ijbamboo.pattern.Decorator.example.tea;

/**
 * @author ����
 * @Description 
 * @version 1.0
 * 2018��2��3�� ����8:57:54
 */
public class TeaLeaves  extends Tea {  
	   public TeaLeaves() {
	       teaIsSteeped = false;
	   }
	   
	   public void steepTea() {
	       teaIsSteeped = true;
	       System.out.println("tea leaves are steeping");
	   }
	}